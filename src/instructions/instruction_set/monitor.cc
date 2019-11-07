#include "instructions/instruction_set/monitor.h"
#include "utils/memory_areas/thread.h"

namespace Instructions {
namespace Monitor {
std::vector<int> Enter::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide,
    int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
std::vector<int> Exit::execute(
    std::vector<Utils::Types::u1>::iterator *code_iterator,
    MemoryAreas::Thread *th, int *delta_code, const bool &wide,
    int *pc) {
  std::cout << "Executando " << Opcodes::getMnemonic(this->opcode) << "\n";
  return {};
}
// ----------------------------------------------------------------------------
}  // namespace Monitor
}  // namespace Instructions
