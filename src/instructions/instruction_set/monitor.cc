#include "instructions/instruction_set/monitor.h"

#include "utils/flags.h"
#include "utils/memory_areas/thread.h"
#include "utils/object.h"

namespace Instructions {
namespace Monitor {
std::vector<int> Enter::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->popOperand<Utils::Object *>();
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Exit::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide, int *pc) {
  if (Utils::Flags::options.kDEBUG) {
    std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  }
  th->current_frame->popOperand<Utils::Object *>();
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Monitor
}  // namespace Instructions
