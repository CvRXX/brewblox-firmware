// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SetpointSensorPair_test.proto

#include "SetpointSensorPair_test.pb.h"

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
namespace SetpointSensorPair {
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace SetpointSensorPair
}  // namespace blox
namespace protobuf_SetpointSensorPair_5ftest_2eproto {
static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox::SetpointSensorPair::_Block_default_instance_;
    new (ptr) ::blox::SetpointSensorPair::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox::SetpointSensorPair::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsBlock}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, sensorid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, setting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, value_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, settingenabled_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, storedsetting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, filter_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, filterthreshold_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, valueunfiltered_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, resetfilter_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::SetpointSensorPair::Block, strippedfields_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::SetpointSensorPair::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox::SetpointSensorPair::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "SetpointSensorPair_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\035SetpointSensorPair_test.proto\022\027blox.Se"
      "tpointSensorPair\032\023brewblox_test.proto\032\021n"
      "anopb_test.proto\"\300\003\n\005Block\022\035\n\010sensorId\030\002"
      " \001(\rB\013\212\265\030\002\030\002\222\?\0028\020\022/\n\007setting\030\005 \001(\021B\036\212\265\030\002"
      "0\001\212\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 \212\265\030\002(\001\022-\n\005value\030\006 \001("
      "\021B\036\212\265\030\0020\001\212\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 \212\265\030\002(\001\022\026\n\016set"
      "tingEnabled\030\007 \001(\010\022/\n\rstoredSetting\030\010 \001(\021"
      "B\030\212\265\030\0020\000\212\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 \0225\n\006filter\030\t \001"
      "(\0162%.blox.SetpointSensorPair.FilterChoic"
      "e\022+\n\017filterThreshold\030\n \001(\021B\022\212\265\030\002\010\006\212\265\030\003\020\200"
      " \222\?\0028 \0227\n\017valueUnfiltered\030\013 \001(\021B\036\212\265\030\0020\001\212"
      "\265\030\002\010\001\212\265\030\003\020\200 \222\?\0028 \212\265\030\002(\001\022\023\n\013resetFilter\030\014"
      " \001(\010\022(\n\016strippedFields\030c \003(\rB\020\212\265\030\002(\001\222\?\0028"
      "\020\222\?\002\020\003:\023\212\265\030\003\030\257\002\212\265\030\002H\001\212\265\030\002H\004*~\n\014FilterCho"
      "ice\022\017\n\013FILTER_NONE\020\000\022\016\n\nFILTER_15s\020\001\022\016\n\n"
      "FILTER_45s\020\002\022\016\n\nFILTER_90s\020\003\022\r\n\tFILTER_3"
      "m\020\004\022\016\n\nFILTER_10m\020\005\022\016\n\nFILTER_30m\020\006b\006pro"
      "to3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 683);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "SetpointSensorPair_test.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_SetpointSensorPair_5ftest_2eproto
namespace blox {
namespace SetpointSensorPair {
const ::google::protobuf::EnumDescriptor* FilterChoice_descriptor() {
  protobuf_SetpointSensorPair_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_SetpointSensorPair_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool FilterChoice_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void Block::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kSensorIdFieldNumber;
const int Block::kSettingFieldNumber;
const int Block::kValueFieldNumber;
const int Block::kSettingEnabledFieldNumber;
const int Block::kStoredSettingFieldNumber;
const int Block::kFilterFieldNumber;
const int Block::kFilterThresholdFieldNumber;
const int Block::kValueUnfilteredFieldNumber;
const int Block::kResetFilterFieldNumber;
const int Block::kStrippedFieldsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_SetpointSensorPair_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox.SetpointSensorPair.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      strippedfields_(from.strippedfields_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&sensorid_, &from.sensorid_,
    static_cast<size_t>(reinterpret_cast<char*>(&valueunfiltered_) -
    reinterpret_cast<char*>(&sensorid_)) + sizeof(valueunfiltered_));
  // @@protoc_insertion_point(copy_constructor:blox.SetpointSensorPair.Block)
}

void Block::SharedCtor() {
  ::memset(&sensorid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&valueunfiltered_) -
      reinterpret_cast<char*>(&sensorid_)) + sizeof(valueunfiltered_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox.SetpointSensorPair.Block)
  SharedDtor();
}

void Block::SharedDtor() {
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_SetpointSensorPair_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_SetpointSensorPair_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_SetpointSensorPair_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.SetpointSensorPair.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  strippedfields_.Clear();
  ::memset(&sensorid_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&valueunfiltered_) -
      reinterpret_cast<char*>(&sensorid_)) + sizeof(valueunfiltered_));
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox.SetpointSensorPair.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(16383u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 sensorId = 2 [(.nanopb_test) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &sensorid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 setting = 5 [(.nanopb_test) = {
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &setting_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 value = 6 [(.nanopb_test) = {
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &value_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool settingEnabled = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &settingenabled_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 storedSetting = 8 [(.nanopb_test) = {
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &storedsetting_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.SetpointSensorPair.FilterChoice filter = 9;
      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(72u /* 72 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_filter(static_cast< ::blox::SetpointSensorPair::FilterChoice >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 filterThreshold = 10 [(.nanopb_test) = {
      case 10: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(80u /* 80 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &filterthreshold_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 valueUnfiltered = 11 [(.nanopb_test) = {
      case 11: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(88u /* 88 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &valueunfiltered_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool resetFilter = 12;
      case 12: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(96u /* 96 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &resetfilter_)));
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
  // @@protoc_insertion_point(parse_success:blox.SetpointSensorPair.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox.SetpointSensorPair.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox.SetpointSensorPair.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 sensorId = 2 [(.nanopb_test) = {
  if (this->sensorid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->sensorid(), output);
  }

  // sint32 setting = 5 [(.nanopb_test) = {
  if (this->setting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(5, this->setting(), output);
  }

  // sint32 value = 6 [(.nanopb_test) = {
  if (this->value() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(6, this->value(), output);
  }

  // bool settingEnabled = 7;
  if (this->settingenabled() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(7, this->settingenabled(), output);
  }

  // sint32 storedSetting = 8 [(.nanopb_test) = {
  if (this->storedsetting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(8, this->storedsetting(), output);
  }

  // .blox.SetpointSensorPair.FilterChoice filter = 9;
  if (this->filter() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      9, this->filter(), output);
  }

  // sint32 filterThreshold = 10 [(.nanopb_test) = {
  if (this->filterthreshold() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(10, this->filterthreshold(), output);
  }

  // sint32 valueUnfiltered = 11 [(.nanopb_test) = {
  if (this->valueunfiltered() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(11, this->valueunfiltered(), output);
  }

  // bool resetFilter = 12;
  if (this->resetfilter() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(12, this->resetfilter(), output);
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
  // @@protoc_insertion_point(serialize_end:blox.SetpointSensorPair.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox.SetpointSensorPair.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 sensorId = 2 [(.nanopb_test) = {
  if (this->sensorid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->sensorid(), target);
  }

  // sint32 setting = 5 [(.nanopb_test) = {
  if (this->setting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(5, this->setting(), target);
  }

  // sint32 value = 6 [(.nanopb_test) = {
  if (this->value() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(6, this->value(), target);
  }

  // bool settingEnabled = 7;
  if (this->settingenabled() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(7, this->settingenabled(), target);
  }

  // sint32 storedSetting = 8 [(.nanopb_test) = {
  if (this->storedsetting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(8, this->storedsetting(), target);
  }

  // .blox.SetpointSensorPair.FilterChoice filter = 9;
  if (this->filter() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      9, this->filter(), target);
  }

  // sint32 filterThreshold = 10 [(.nanopb_test) = {
  if (this->filterthreshold() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(10, this->filterthreshold(), target);
  }

  // sint32 valueUnfiltered = 11 [(.nanopb_test) = {
  if (this->valueunfiltered() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(11, this->valueunfiltered(), target);
  }

  // bool resetFilter = 12;
  if (this->resetfilter() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(12, this->resetfilter(), target);
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
  // @@protoc_insertion_point(serialize_to_array_end:blox.SetpointSensorPair.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.SetpointSensorPair.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
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

  // uint32 sensorId = 2 [(.nanopb_test) = {
  if (this->sensorid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->sensorid());
  }

  // sint32 setting = 5 [(.nanopb_test) = {
  if (this->setting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->setting());
  }

  // sint32 value = 6 [(.nanopb_test) = {
  if (this->value() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->value());
  }

  // sint32 storedSetting = 8 [(.nanopb_test) = {
  if (this->storedsetting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->storedsetting());
  }

  // .blox.SetpointSensorPair.FilterChoice filter = 9;
  if (this->filter() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->filter());
  }

  // bool settingEnabled = 7;
  if (this->settingenabled() != 0) {
    total_size += 1 + 1;
  }

  // bool resetFilter = 12;
  if (this->resetfilter() != 0) {
    total_size += 1 + 1;
  }

  // sint32 filterThreshold = 10 [(.nanopb_test) = {
  if (this->filterthreshold() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->filterthreshold());
  }

  // sint32 valueUnfiltered = 11 [(.nanopb_test) = {
  if (this->valueunfiltered() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->valueunfiltered());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox.SetpointSensorPair.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox.SetpointSensorPair.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox.SetpointSensorPair.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.SetpointSensorPair.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  strippedfields_.MergeFrom(from.strippedfields_);
  if (from.sensorid() != 0) {
    set_sensorid(from.sensorid());
  }
  if (from.setting() != 0) {
    set_setting(from.setting());
  }
  if (from.value() != 0) {
    set_value(from.value());
  }
  if (from.storedsetting() != 0) {
    set_storedsetting(from.storedsetting());
  }
  if (from.filter() != 0) {
    set_filter(from.filter());
  }
  if (from.settingenabled() != 0) {
    set_settingenabled(from.settingenabled());
  }
  if (from.resetfilter() != 0) {
    set_resetfilter(from.resetfilter());
  }
  if (from.filterthreshold() != 0) {
    set_filterthreshold(from.filterthreshold());
  }
  if (from.valueunfiltered() != 0) {
    set_valueunfiltered(from.valueunfiltered());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox.SetpointSensorPair.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.SetpointSensorPair.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Block::IsInitialized() const {
  return true;
}

void Block::Swap(Block* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Block::InternalSwap(Block* other) {
  using std::swap;
  strippedfields_.InternalSwap(&other->strippedfields_);
  swap(sensorid_, other->sensorid_);
  swap(setting_, other->setting_);
  swap(value_, other->value_);
  swap(storedsetting_, other->storedsetting_);
  swap(filter_, other->filter_);
  swap(settingenabled_, other->settingenabled_);
  swap(resetfilter_, other->resetfilter_);
  swap(filterthreshold_, other->filterthreshold_);
  swap(valueunfiltered_, other->valueunfiltered_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_SetpointSensorPair_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_SetpointSensorPair_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace SetpointSensorPair
}  // namespace blox
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox::SetpointSensorPair::Block* Arena::CreateMaybeMessage< ::blox::SetpointSensorPair::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox::SetpointSensorPair::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
