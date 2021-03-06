#ifndef INCLUDE_UTILS_MEMORY_H_
#define INCLUDE_UTILS_MEMORY_H_

#include <cstring>
#include <memory>

#include "utils/errors.h"

namespace Utils {
template <typename T, typename U>
inline T castTo(const U *in) {
  T dest;
  if (sizeof(U) > sizeof(T)) {
    throw Errors::Exception(Errors::kMEMCPY,
                            "size of input greater than size of dest");
  }
  std::memcpy(&dest, in, sizeof(U));

  return dest;
}
}  // namespace Utils

#endif  // INCLUDE_UTILS_MEMORY_H_
