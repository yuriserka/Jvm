#ifndef INCLUDE_UTILS_SERIALIZERS_CONSTPOOLSERIALIZER_H_
#define INCLUDE_UTILS_SERIALIZERS_CONSTPOOLSERIALIZER_H_

#include "classfile.h"
#include "utils/external/nlohmann_json.hpp"

using nlohmann::json;

namespace Utils {
namespace ConstantPool {
class ConstantPoolSerializer {
 public:
  explicit ConstantPoolSerializer(const ClassFile *cf) { this->cf = cf; }

  bool to_json(json *j, const int &kpoolindex);

 private:
  template <typename T>
  void writeReferences(json *j, const T *kinfo);

  const ClassFile *cf;
};
}  // namespace ConstantPool
}  // namespace Utils

#endif  // INCLUDE_UTILS_SERIALIZERS_CONSTPOOLSERIALIZER_H_
