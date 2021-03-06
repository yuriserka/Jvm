#ifndef INCLUDE_INSTRUCTIONS_PRINTER_H_
#define INCLUDE_INSTRUCTIONS_PRINTER_H_

#include <vector>

#include "utils/infos.h"
#include "utils/types.h"

class Viewer;

namespace Instructions {
std::string getBytecode(std::vector<Utils::Types::u1>::iterator *opcode,
                        Viewer *v, int *pc, const int &delta_tab,
                        const bool &wide = false);
}

#endif  // INCLUDE_INSTRUCTIONS_PRINTER_H_
