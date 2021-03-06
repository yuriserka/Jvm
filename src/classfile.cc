#include "classfile.h"

#include <iomanip>
#include <sstream>

#include "utils/string.h"

void ClassFile::deleteConstantPool() {
  for (int i = 0; i < this->constant_pool_count - 1; ++i) {
    auto cpi = this->constant_pool[i];
    switch (cpi.base->tag) {
      namespace cp = Utils::ConstantPool;
      case cp::kCONSTANT_CLASS:
        cpi.deleteclass<cp::CONSTANT_Class_info>();
        break;
      case cp::kCONSTANT_DOUBLE:
        cpi.deleteclass<cp::CONSTANT_Double_info>();
        ++i;
        break;
      case cp::kCONSTANT_FIELDREF:
        cpi.deleteclass<cp::CONSTANT_FieldRef_info>();
        break;
      case cp::kCONSTANT_FLOAT:
        cpi.deleteclass<cp::CONSTANT_Float_info>();
        break;
      case cp::kCONSTANT_INTEGER:
        cpi.deleteclass<cp::CONSTANT_Integer_info>();
        break;
      case cp::kCONSTANT_INTERFACEMETHODREF:
        cpi.deleteclass<cp::CONSTANT_InterfaceMethodref_info>();
        break;
      case cp::kCONSTANT_LONG:
        cpi.deleteclass<cp::CONSTANT_Long_info>();
        ++i;
        break;
      case cp::kCONSTANT_METHODREF:
        cpi.deleteclass<cp::CONSTANT_Methodref_info>();
        break;
      case cp::kCONSTANT_NAMEANDTYPE:
        cpi.deleteclass<cp::CONSTANT_NameAndType_info>();
        break;
      case cp::kCONSTANT_STRING:
        cpi.deleteclass<cp::CONSTANT_String_info>();
        break;
      case cp::kCONSTANT_UTF8:
        cpi.deleteclass<cp::CONSTANT_Utf8_info>();
        break;
      case cp::kCONSTANT_METHODHANDLE:
        cpi.deleteclass<cp::CONSTANT_MethodHandle_info>();
        break;
      case cp::kCONSTANT_METHODTYPE:
        cpi.deleteclass<cp::CONSTANT_MethodType_info>();
        break;
      case cp::kCONSTANT_INVOKEDYNAMIC:
        cpi.deleteclass<cp::CONSTANT_InvokeDynamic_info>();
        break;
    }
  }
}

void ClassFile::deleteFieldsAttributes() {
  for (auto i = 0; i < this->fields_count; ++i) {
    auto field_attrs = this->fields[i].attributes;
    this->deleteAttributes(&field_attrs);
  }
}

void ClassFile::deleteMethodsAttributes() {
  for (auto i = 0; i < this->methods_count; ++i) {
    auto method_attrs = this->methods[i].attributes;
    this->deleteAttributes(&method_attrs);
  }
}

void ClassFile::deleteAttributes(
    std::vector<Utils::Attributes::attribute_info> *attributes) {
  for (size_t i = 0; i < attributes->size(); ++i) {
    Utils::Attributes::attribute_info attr = attributes->at(i);
    auto utf8nameindex =
        this->constant_pool[attr.base->attribute_name_index - 1];
    auto kutf8 =
        utf8nameindex.getClass<Utils::ConstantPool::CONSTANT_Utf8_info>();
    auto attrName = Utils::String::getUtf8Modified(kutf8);
    auto attrtype = Utils::Attributes::getAttributeType(attrName);

    switch (attrtype) {
      namespace attrs = Utils::Attributes;
      case attrs::kCONSTANTVALUE:
        attr.deleteclass<attrs::ConstantValue_attribute>();
        break;
      case attrs::kCODE: {
        auto code_attr = attr.getClass<attrs::Code_attribute>();
        this->deleteAttributes(&code_attr->attributes);
        attr.deleteclass<attrs::Code_attribute>();
        break;
      }
      case attrs::kEXCEPTIONS:
        attr.deleteclass<attrs::Exceptions_attribute>();
        break;
      case attrs::kINNERCLASSES:
        attr.deleteclass<attrs::InnerClasses_attribute>();
        break;
      case attrs::kENCLOSINGMETHOD:
        attr.deleteclass<attrs::EnclosingMethod_attribute>();
        break;
      case attrs::kSYNTHETIC:
        attr.deleteclass<attrs::Synthetic_attribute>();
        break;
      case attrs::kSIGNATURE:
        attr.deleteclass<attrs::Signature_attribute>();
        break;
      case attrs::kSOURCEFILE:
        attr.deleteclass<attrs::SourceFile_attribute>();
        break;
      case attrs::kLINENUMBERTABLE:
        attr.deleteclass<attrs::LineNumberTable_attribute>();
        break;
      case attrs::kLOCALVARIABLETABLE:
        attr.deleteclass<attrs::LocalVariableTable_attribute>();
        break;
      case attrs::kDEPRECATED:
        attr.deleteclass<attrs::Deprecated_attribute>();
        break;
      case attrs::kBOOTSTRAPMETHODS:
        attr.deleteclass<attrs::BootstrapMethods_attribute>();
        break;
      case attrs::kMETHODPARAMETERS:
        attr.deleteclass<attrs::MethodParameters_attribute>();
        break;
      case attrs::kINVALID:
        attr.deleteclass<attrs::NotImplemented>();
        break;
    }
  }
}
