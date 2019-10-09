#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_

#include <iostream>
#include <string>
#include <vector>
#include "instructions/instruction_set/base.h"
#include "instructions/opcodes.h"
#include "utils/string.h"

namespace Instructions {
namespace Branch {
class RefCompareEqual : public Instruction {
 public:
  RefCompareEqual() : Instruction(Opcodes::kIF_ACMPEQ) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class RefCompareNotEqual : public Instruction {
 public:
  RefCompareNotEqual() : Instruction(Opcodes::kIF_ACMPNE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareEqual : public Instruction {
 public:
  IntegerCompareEqual() : Instruction(Opcodes::kIF_ICMPEQ) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareGreaterEqual : public Instruction {
 public:
  IntegerCompareGreaterEqual() : Instruction(Opcodes::kIF_ICMPGE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareGreaterThan : public Instruction {
 public:
  IntegerCompareGreaterThan() : Instruction(Opcodes::kIF_ICMPGT) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareLessEqual : public Instruction {
 public:
  IntegerCompareLessEqual() : Instruction(Opcodes::kIF_ICMPLE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareLessThan : public Instruction {
 public:
  IntegerCompareLessThan() : Instruction(Opcodes::kIF_ICMPLT) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class IntegerCompareNotEqual : public Instruction {
 public:
  IntegerCompareNotEqual() : Instruction(Opcodes::kIF_ICMPNE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class EqualZero : public Instruction {
 public:
  EqualZero() : Instruction(Opcodes::kIFEQ) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class GreaterEqualZero : public Instruction {
 public:
  GreaterEqualZero() : Instruction(Opcodes::kIFGE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class GreaterThanZero : public Instruction {
 public:
  GreaterThanZero() : Instruction(Opcodes::kIFGT) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class LessEqualZero : public Instruction {
 public:
  LessEqualZero() : Instruction(Opcodes::kIFLE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class LessThanZero : public Instruction {
 public:
  LessThanZero() : Instruction(Opcodes::kIFLT) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class NotEqualZero : public Instruction {
 public:
  NotEqualZero() : Instruction(Opcodes::kIFNE) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class NonNull : public Instruction {
 public:
  NonNull() : Instruction(Opcodes::kIFNONNULL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};

class RefNull : public Instruction {
 public:
  RefNull() : Instruction(Opcodes::kIFNULL) {}

  inline std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      const bool &wide) override {
    auto offset = (*++*code_it << 8) | *++*code_it;
    std::cout << Opcodes::getMnemonic(this->opcode) << " ";
    *delta_code = 2;
    return {offset};
  }

  inline std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_it, int *delta_code,
      int *ret, const bool &wide) {
    auto offset = (*++*code_it << 8) | *++*code_it;
    *delta_code = 2;
    return {Utils::String::to_string(static_cast<int>(char(offset)))};
  }
};
}  // namespace Branch
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTIONS_SET_BRANCH_H_
