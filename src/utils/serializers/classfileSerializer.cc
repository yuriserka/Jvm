#include "utils/serializers/classfileSerializer.h"

#include "utils/access_flags.h"
#include "utils/serializers/attributeSerializer.h"
#include "utils/serializers/constpoolSerializer.h"
#include "utils/serializers/fieldSerializer.h"
#include "utils/serializers/methodSerializer.h"
#include "utils/versions.h"

void ClassFileSerializer::to_json(json *j) {
  this->writeMagic(&(*j)["magic"]);
  this->writeVersion(&(*j)["version"]);
  this->writeConstantPool(&(*j)["constant pool"]);
  this->writeAccessFlags(&(*j)["access flags"]);
  this->writeThisClass(&(*j)["this class"]);
  this->writeSuperClass(&(*j)["super class"]);
  this->writeInterfaces(&(*j)["interfaces"]);
  this->writeFields(&(*j)["fields"]);
  this->writeMethods(&(*j)["methods"]);
  this->writeAttributes(&(*j)["attributes"]);
}

void ClassFileSerializer::writeMagic(json *j) {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(8) << std::hex << std::uppercase
     << this->cf->magic;

  *j = ss.str();
}

void ClassFileSerializer::writeVersion(json *j) {
  // clang-format off
  *j = {
    {"minor", this->cf->minor_version},
    {"major", this->cf->major_version},
    {"name", Utils::Versions::getVersion(this->cf->major_version)}
  };
  // clang-format on
}

void ClassFileSerializer::writeConstantPool(json *j) {
  // clang-format off
  *j = {
    {"count", this->cf->constant_pool_count},
    {"entries", json::array()}
  };
  // clang-format on

  auto kpoolserializer = Utils::ConstantPool::ConstantPoolSerializer(this->cf);
  for (auto i = 0; i < this->cf->constant_pool_count - 1; ++i) {
    auto jmp = kpoolserializer.to_json(&(*j).at("entries")[i], i);
    if (jmp) {
      // clang-format off
      (*j).at("entries")[++i] = {
        {"type", nullptr},
        {"info", "(large numeric continued)"}
      };
      // clang-format on
    }
  }
}

void ClassFileSerializer::writeAccessFlags(json *j) {
  std::stringstream ss;
  ss << "0x" << std::setfill('0') << std::setw(4) << std::hex << std::uppercase
     << this->cf->access_flags;
  // clang-format off
  *j = {
    {"bytes", ss.str()},
    {"values", Utils::Access::getClassAccessType(this->cf->access_flags)}
  };
  // clang-format on
}

void ClassFileSerializer::writeThisClass(json *j) {
  auto kpoolserializer = Utils::ConstantPool::ConstantPoolSerializer(this->cf);
  kpoolserializer.to_json(j, this->cf->this_class - 1);
}

void ClassFileSerializer::writeSuperClass(json *j) {
  auto kpoolserializer = Utils::ConstantPool::ConstantPoolSerializer(this->cf);
  kpoolserializer.to_json(j, this->cf->super_class - 1);
}

void ClassFileSerializer::writeInterfaces(json *j) {
  // clang-format off
  *j = {
    {"count", this->cf->interfaces_count},
    {"entries", this->cf->interfaces}
  };
  // clang-format on

  auto kpoolserializer = Utils::ConstantPool::ConstantPoolSerializer(this->cf);
  for (auto i = 0; i < this->cf->interfaces_count; ++i) {
    kpoolserializer.to_json(&(*j).at("entries")[i],
                            this->cf->interfaces[i] - 1);
  }
}

void ClassFileSerializer::writeFields(json *j) {
  // clang-format off
  *j = {
      {"count", this->cf->fields_count},
      {"entries", json::array()}
  };
  // clang-format on

  auto fserializer = Utils::Infos::FieldSerializer(this->cf);
  for (auto i = 0; i < this->cf->fields_count; ++i) {
    fserializer.to_json(&(*j).at("entries")[i], i);
  }
}

void ClassFileSerializer::writeMethods(json *j) {
  // clang-format off
  *j = {
      {"count", this->cf->methods_count},
      {"entries", json::array()}
  };
  // clang-format on

  auto mserializer = Utils::Infos::MethodSerializer(this->cf);
  for (auto i = 0; i < this->cf->methods_count; ++i) {
    mserializer.to_json(&(*j).at("entries")[i], i);
  }
}

void ClassFileSerializer::writeAttributes(json *j) {
  // clang-format off
  *j = {
      {"count", this->cf->attributes_count},
      {"entries", json::array()}
  };
  // clang-format on

  auto aserializer =
      Utils::Attributes::AttributeSerializer(this->cf, this->cf->attributes);
  for (auto i = 0; i < this->cf->attributes_count; ++i) {
    aserializer.to_json(&(*j).at("entries")[i], i);
  }
}
