#include "utils/memory_areas/thread.h"

#include "instructions/execution_engine.h"
#include "instructions/opcodes.h"
#include "reader.h"
#include "utils/attributes.h"
#include "utils/errors.h"
#include "utils/flags.h"
#include "utils/helper_functions.h"
#include "utils/memory_areas/heap.h"
#include "utils/memory_areas/method_area.h"
#include "utils/string.h"

#define MAX_STACK 40

namespace MemoryAreas {
void Thread::executeMethod(const std::string &method_name) {
  if (this->jvm_stack.size() > MAX_STACK) {
    std::stringstream ss;
    ss << "Stack Overflow. This jvm supports only " << MAX_STACK
       << " methods calls at a time";

    throw Utils::Errors::Exception(Utils::Errors::kSTACK, ss.str());
  }

  auto method = this->method_area->getMethod(method_name);
  this->current_method = method_name;

  Utils::Attributes::Code_attribute *code_attr;

  try {
    code_attr =
        Utils::getAttribute(this->current_class, &method.attributes, "Code")
            .getClass<Utils::Attributes::Code_attribute>();
  } catch (const Utils::Errors::Exception &e) {
    std::cout << e.what() << "\n";
    return;
  }
  auto code_array = code_attr->code;

  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executing method " << method_name << "\n";
  }

  this->current_frame =
      new Utils::Frame(code_attr->max_stack, code_attr->max_locals,
                       this->method_area->runtime_constant_pool);
  this->jvm_stack.push(this->current_frame);

  // On instance method invocation, local variable 0 is always used to
  // pass a reference to the object on which the instance method is being
  // invoked
  this->current_frame->pushLocalVar(this->current_class->this_class);

  for (auto it = code_array.begin(); it != code_array.end(); ++it) {
    if (Utils::Flags::options.kDEBUG) {
      std::cout << this->current_frame->pc << ": ";
    }
    try {
      Instructions::runBytecode(&it, this, &this->current_frame->pc);
    } catch (const Utils::Errors::Exception &e) {
      if (Utils::Flags::options.kDEBUG) {
        std::cout << e.what() << "\n";
      }
      continue;
    }
    // Apenas para teste para ver se a troca de contexto em nível de função
    // funciona, ainda não passa argumentos e nem variaveis locais. invoke
    // todos os invokes
    // if (*it >= 0xb6 && *it <= 0xba) {
    //   std::cout << Utils::getClassName(this->current_class) << "."
    //             << this->current_method << "::" << this->current_frame->pc
    //             << ": " << Instructions::Opcodes::getMnemonic(*it);
    //   uint16_t cp_arg = (((*++it) << 8) | *++it);
    //   std::cout << " -> args: #" << cp_arg << "\n";

    //   std::string ref_class_name, ref_name, ref_descriptor;
    //   Utils::getReference(this->current_class, cp_arg, &ref_class_name,
    //                       &ref_name, &ref_descriptor);
    //   try {
    //     this->changeContext(ref_class_name, ref_name, ref_descriptor);
    //     this->current_frame->pc += 2;
    //   } catch (const Utils::Errors::Exception &e) {
    //     if (Utils::Flags::options.kDEBUG) {
    //       std::cout << e.what() << "\n";
    //     }
    //     continue;
    //   }
    // }
  }

  this->jvm_stack.pop();
}

void Thread::changeContext(const std::string &classname,
                           const std::string &method_name,
                           const std::string &descriptor) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "\tchanging context to " << classname << "." << method_name
              << descriptor << "\n";
  }
  auto const actual_classname = Utils::getClassName(this->current_class);

  auto old_class = this->current_class;
  if (classname.compare(actual_classname)) {
    auto new_class = this->method_area->loadClass(classname);
    this->current_class = new_class;
    this->method_area->update(this->current_class);
  }
  auto old_method = this->current_method;
  auto old_frame = this->current_frame;

  this->executeMethod(method_name);

  this->current_class = old_class;
  this->current_frame = old_frame;
  this->current_method = old_method;

  if (Utils::Flags::options.kDEBUG) {
    std::cout << "\treturning context to " << actual_classname << "."
              << this->current_method << "\n";
  }
  this->method_area->update(this->current_class);
}
}  // namespace MemoryAreas
