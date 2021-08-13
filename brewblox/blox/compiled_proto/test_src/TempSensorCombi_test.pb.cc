// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TempSensorCombi_test.proto

#include "TempSensorCombi_test.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace blox {
class TempSensorCombiDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<TempSensorCombi>
      _instance;
} _TempSensorCombi_default_instance_;
}  // namespace blox
namespace protobuf_TempSensorCombi_5ftest_2eproto {
static void InitDefaultsTempSensorCombi() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox::_TempSensorCombi_default_instance_;
    new (ptr) ::blox::TempSensorCombi();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox::TempSensorCombi::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_TempSensorCombi =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsTempSensorCombi}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_TempSensorCombi.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::TempSensorCombi, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::TempSensorCombi, value_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::TempSensorCombi, combinefunc_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::TempSensorCombi, sensors_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::TempSensorCombi, strippedfields_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::TempSensorCombi)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox::_TempSensorCombi_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "TempSensorCombi_test.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, file_level_enum_descriptors, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\032TempSensorCombi_test.proto\022\004blox\032\023brew"
      "blox_test.proto\032\021nanopb_test.proto\"\310\001\n\017T"
      "empSensorCombi\022-\n\005value\030\001 \001(\021B\036\212\265\030\0020\001\212\265\030"
      "\002\010\001\212\265\030\003\020\200 \212\265\030\002(\001\222\?\0028 \022*\n\013combineFunc\030\002 \001"
      "(\0162\025.blox.SensorCombiFunc\022!\n\007sensors\030\003 \003"
      "(\rB\020\212\265\030\002\030\002\222\?\0028\020\222\?\002\020\010\022(\n\016strippedFields\030c"
      " \003(\rB\020\212\265\030\002(\001\222\?\0028\020\222\?\002\020\001:\r\212\265\030\003\030\304\002\212\265\030\002H\002*b\n"
      "\017SensorCombiFunc\022\031\n\025SENSOR_COMBI_FUNC_AV"
      "G\020\000\022\031\n\025SENSOR_COMBI_FUNC_MIN\020\001\022\031\n\025SENSOR"
      "_COMBI_FUNC_MAX\020\002b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 385);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "TempSensorCombi_test.proto", &protobuf_RegisterTypes);
  ::protobuf_brewblox_5ftest_2eproto::AddDescriptors();
  ::protobuf_nanopb_5ftest_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_TempSensorCombi_5ftest_2eproto
namespace blox {
const ::google::protobuf::EnumDescriptor* SensorCombiFunc_descriptor() {
  protobuf_TempSensorCombi_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_TempSensorCombi_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool SensorCombiFunc_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void TempSensorCombi::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int TempSensorCombi::kValueFieldNumber;
const int TempSensorCombi::kCombineFuncFieldNumber;
const int TempSensorCombi::kSensorsFieldNumber;
const int TempSensorCombi::kStrippedFieldsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

TempSensorCombi::TempSensorCombi()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_TempSensorCombi_5ftest_2eproto::scc_info_TempSensorCombi.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox.TempSensorCombi)
}
TempSensorCombi::TempSensorCombi(const TempSensorCombi& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      sensors_(from.sensors_),
      strippedfields_(from.strippedfields_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&value_, &from.value_,
    static_cast<size_t>(reinterpret_cast<char*>(&combinefunc_) -
    reinterpret_cast<char*>(&value_)) + sizeof(combinefunc_));
  // @@protoc_insertion_point(copy_constructor:blox.TempSensorCombi)
}

void TempSensorCombi::SharedCtor() {
  ::memset(&value_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&combinefunc_) -
      reinterpret_cast<char*>(&value_)) + sizeof(combinefunc_));
}

TempSensorCombi::~TempSensorCombi() {
  // @@protoc_insertion_point(destructor:blox.TempSensorCombi)
  SharedDtor();
}

void TempSensorCombi::SharedDtor() {
}

void TempSensorCombi::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* TempSensorCombi::descriptor() {
  ::protobuf_TempSensorCombi_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_TempSensorCombi_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const TempSensorCombi& TempSensorCombi::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_TempSensorCombi_5ftest_2eproto::scc_info_TempSensorCombi.base);
  return *internal_default_instance();
}


void TempSensorCombi::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.TempSensorCombi)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  sensors_.Clear();
  strippedfields_.Clear();
  ::memset(&value_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&combinefunc_) -
      reinterpret_cast<char*>(&value_)) + sizeof(combinefunc_));
  _internal_metadata_.Clear();
}

bool TempSensorCombi::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox.TempSensorCombi)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // sint32 value = 1 [(.nanopb_test) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &value_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.SensorCombiFunc combineFunc = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_combinefunc(static_cast< ::blox::SensorCombiFunc >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated uint32 sensors = 3 [(.nanopb_test) = {
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_sensors())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 1, 26u, input, this->mutable_sensors())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
      case 99: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 794 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, this->mutable_strippedfields())));
        } else if (
            static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 792 & 0xFF */)) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitiveNoInline<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 2, 794u, input, this->mutable_strippedfields())));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:blox.TempSensorCombi)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox.TempSensorCombi)
  return false;
#undef DO_
}

void TempSensorCombi::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox.TempSensorCombi)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 value = 1 [(.nanopb_test) = {
  if (this->value() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(1, this->value(), output);
  }

  // .blox.SensorCombiFunc combineFunc = 2;
  if (this->combinefunc() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->combinefunc(), output);
  }

  // repeated uint32 sensors = 3 [(.nanopb_test) = {
  if (this->sensors_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(3, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _sensors_cached_byte_size_));
  }
  for (int i = 0, n = this->sensors_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->sensors(i), output);
  }

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  if (this->strippedfields_size() > 0) {
    ::google::protobuf::internal::WireFormatLite::WriteTag(99, ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED, output);
    output->WriteVarint32(static_cast< ::google::protobuf::uint32>(
        _strippedfields_cached_byte_size_));
  }
  for (int i = 0, n = this->strippedfields_size(); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32NoTag(
      this->strippedfields(i), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox.TempSensorCombi)
}

::google::protobuf::uint8* TempSensorCombi::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox.TempSensorCombi)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // sint32 value = 1 [(.nanopb_test) = {
  if (this->value() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(1, this->value(), target);
  }

  // .blox.SensorCombiFunc combineFunc = 2;
  if (this->combinefunc() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->combinefunc(), target);
  }

  // repeated uint32 sensors = 3 [(.nanopb_test) = {
  if (this->sensors_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      3,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _sensors_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->sensors_, target);
  }

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  if (this->strippedfields_size() > 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteTagToArray(
      99,
      ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED,
      target);
    target = ::google::protobuf::io::CodedOutputStream::WriteVarint32ToArray(
        static_cast< ::google::protobuf::int32>(
            _strippedfields_cached_byte_size_), target);
    target = ::google::protobuf::internal::WireFormatLite::
      WriteUInt32NoTagToArray(this->strippedfields_, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.TempSensorCombi)
  return target;
}

size_t TempSensorCombi::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.TempSensorCombi)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated uint32 sensors = 3 [(.nanopb_test) = {
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      UInt32Size(this->sensors_);
    if (data_size > 0) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _sensors_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  {
    size_t data_size = ::google::protobuf::internal::WireFormatLite::
      UInt32Size(this->strippedfields_);
    if (data_size > 0) {
      total_size += 2 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
            static_cast< ::google::protobuf::int32>(data_size));
    }
    int cached_size = ::google::protobuf::internal::ToCachedSize(data_size);
    GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
    _strippedfields_cached_byte_size_ = cached_size;
    GOOGLE_SAFE_CONCURRENT_WRITES_END();
    total_size += data_size;
  }

  // sint32 value = 1 [(.nanopb_test) = {
  if (this->value() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->value());
  }

  // .blox.SensorCombiFunc combineFunc = 2;
  if (this->combinefunc() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->combinefunc());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void TempSensorCombi::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox.TempSensorCombi)
  GOOGLE_DCHECK_NE(&from, this);
  const TempSensorCombi* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const TempSensorCombi>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox.TempSensorCombi)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox.TempSensorCombi)
    MergeFrom(*source);
  }
}

void TempSensorCombi::MergeFrom(const TempSensorCombi& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.TempSensorCombi)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  sensors_.MergeFrom(from.sensors_);
  strippedfields_.MergeFrom(from.strippedfields_);
  if (from.value() != 0) {
    set_value(from.value());
  }
  if (from.combinefunc() != 0) {
    set_combinefunc(from.combinefunc());
  }
}

void TempSensorCombi::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox.TempSensorCombi)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void TempSensorCombi::CopyFrom(const TempSensorCombi& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.TempSensorCombi)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool TempSensorCombi::IsInitialized() const {
  return true;
}

void TempSensorCombi::Swap(TempSensorCombi* other) {
  if (other == this) return;
  InternalSwap(other);
}
void TempSensorCombi::InternalSwap(TempSensorCombi* other) {
  using std::swap;
  sensors_.InternalSwap(&other->sensors_);
  strippedfields_.InternalSwap(&other->strippedfields_);
  swap(value_, other->value_);
  swap(combinefunc_, other->combinefunc_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata TempSensorCombi::GetMetadata() const {
  protobuf_TempSensorCombi_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_TempSensorCombi_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox::TempSensorCombi* Arena::CreateMaybeMessage< ::blox::TempSensorCombi >(Arena* arena) {
  return Arena::CreateInternal< ::blox::TempSensorCombi >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
