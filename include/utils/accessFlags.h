#ifndef INCLUDE_UTILS_ACCESSFLAGS_H_
#define INCLUDE_UTILS_ACCESSFLAGS_H_

#include <string>
#include <vector>
#include "utils/types.h"

namespace Utils {
namespace Access {
namespace ClassAccess {
enum {
  ACC_PUBLIC = 0x0001,
  ACC_FINAL = 0x0010,
  ACC_SUPER = 0x0020,
  ACC_INTERFACE = 0x0200,
  ACC_ABSTRACT = 0x0400,
  ACC_SYNTHETIC = 0x1000,
  ACC_ANNOTATION = 0x2000,
  ACC_ENUM = 0x4000
};
}  // namespace ClassAccess

namespace FieldAccess {
enum {
  ACC_PUBLIC = 0x0001,
  ACC_PRIVATE = 0x0002,
  ACC_PROTECTED = 0x0004,
  ACC_STATIC = 0x0008,
  ACC_FINAL = 0x0010,
  ACC_VOLATILE = 0x0040,
  ACC_TRANSIENT = 0x0080,
  ACC_SYNTHETIC = 0x1000,
  ACC_ENUM = 0x4000
};
}  // namespace FieldAccess

namespace MethodAccess {
enum {
  ACC_PUBLIC = 0x0001,
  ACC_PRIVATE = 0x0002,
  ACC_PROTECTED = 0x0004,
  ACC_STATIC = 0x0008,
  ACC_FINAL = 0x0010,
  ACC_SYNCHRONIZED = 0x0020,
  ACC_BRIDGE = 0x0040,
  ACC_VARARGS = 0x0080,
  ACC_NATIVE = 0x0100,
  ACC_ABSTRACT = 0x0400,
  ACC_STRICT = 0x0800,
  ACC_SYNTHETIC = 0x1000
};
}  // namespace MethodAccess

namespace NestedClassAccess {
enum {
  ACC_PUBLIC = 0x0001,
  ACC_PRIVATE = 0x0002,
  ACC_PROTECTED = 0x0004,
  ACC_STATIC = 0x0008,
  ACC_FINAL = 0x0010,
  ACC_INTERFACE = 0x0200,
  ACC_ABSTRACT = 0x0400,
  ACC_SYNTHETIC = 0x1000,
  ACC_ANNOTATION = 0x2000,
  ACC_ENUM = 0x4000
};
}  // namespace NestedClassAccess

std::vector<std::string> getClassAccessType(const Utils::Types::u2 &accessType);
std::vector<std::string> getFieldAccessType(const Utils::Types::u2 &accessType);
std::vector<std::string> getMethodAccessType(
    const Utils::Types::u2 &accessType);
std::vector<std::string> getNestedClassAccessType(
    const Utils::Types::u2 &accessType);
}  // namespace Access
}  // namespace Utils

#endif  // INCLUDE_UTILS_ACCESSFLAGS_H_
