#ifndef INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BASE_H_
#define INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BASE_H_

#include <sstream>
#include <string>
#include <vector>

#include "utils/types.h"

// forward declaration
namespace MemoryAreas {
class Thread;
}

namespace Instructions {
class Instruction {
 public:
  explicit Instruction(const Utils::Types::u1 &op) : opcode{op} {}

  virtual ~Instruction() = default;

  virtual std::vector<int> execute(
      std::vector<Utils::Types::u1>::iterator *code_iterator,
      MemoryAreas::Thread *th, int *delta_code, const bool &wide,
      int *pc = nullptr) = 0;

  virtual std::vector<int> toBytecode(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      std::stringstream *ss, const bool &wide, int *pc = nullptr,
      const int &delta_tab = 0) = 0;

  virtual std::vector<std::string> toBytecode_json(
      std::vector<Utils::Types::u1>::iterator *code_iterator, int *delta_code,
      int *ret_val, const bool &wide, int *pc = nullptr) = 0;

  const Utils::Types::u1 opcode;
};
}  // namespace Instructions

#endif  // INCLUDE_INSTRUCTIONS_INSTRUCTION_SET_BASE_H_
