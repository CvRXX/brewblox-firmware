// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FastPwm_test.proto

#include "FastPwm_test.pb.h"

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

namespace protobuf_Constraints_5ftest_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_Constraints_5ftest_2eproto ::google::protobuf::internal::SCCInfo<1> scc_info_AnalogConstraints;
}  // namespace protobuf_Constraints_5ftest_2eproto
namespace blox_test {
namespace FastPwm {
class BlockDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Block>
      _instance;
} _Block_default_instance_;
}  // namespace FastPwm
}  // namespace blox_test
namespace protobuf_FastPwm_5ftest_2eproto {
static void InitDefaultsBlock() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox_test::FastPwm::_Block_default_instance_;
    new (ptr) ::blox_test::FastPwm::Block();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox_test::FastPwm::Block::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_Block =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsBlock}, {
      &protobuf_Constraints_5ftest_2eproto::scc_info_AnalogConstraints.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_Block.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, hwdevice_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, channel_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, frequency_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, setting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, desiredsetting_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, value_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, constrainedby_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox_test::FastPwm::Block, enabled_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox_test::FastPwm::Block)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox_test::FastPwm::_Block_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "FastPwm_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\022FastPwm_test.proto\022\021blox_test.FastPwm\032"
      "\023brewblox_test.proto\032\021nanopb_test.proto\032"
      "\026Constraints_test.proto\"\345\002\n\005Block\022#\n\010hwD"
      "evice\030\001 \001(\rB\021\212\265\030\002\030\n\212\265\030\002@\001\222\?\0028\020\022\026\n\007channe"
      "l\030\002 \001(\rB\005\222\?\0028\010\0222\n\tfrequency\030\003 \001(\0162\037.blox"
      "_test.FastPwm.PwmFrequency\022)\n\007setting\030\004 "
      "\001(\021B\030\212\265\030\0020\001\212\265\030\002(\001\212\265\030\003\020\200 \222\?\0028 \022*\n\016desired"
      "Setting\030\005 \001(\021B\022\212\265\030\0020\001\212\265\030\003\020\200 \222\?\0028 \022\'\n\005val"
      "ue\030\006 \001(\021B\030\212\265\030\0020\001\212\265\030\002(\001\212\265\030\003\020\200 \222\?\0028 \022\?\n\rco"
      "nstrainedBy\030\007 \001(\0132(.blox_test.Constraint"
      "s.AnalogConstraints\022\017\n\007enabled\030\010 \001(\010:\031\212\265"
      "\030\003\030\311\002\212\265\030\002H\001\212\265\030\002H\005\212\265\030\002H\017*]\n\014PwmFrequency\022"
      "\020\n\014PWM_FREQ_OFF\020\000\022\022\n\016PWM_FREQ_100HZ\020\001\022\022\n"
      "\016PWM_FREQ_200HZ\020\002\022\023\n\017PWM_FREQ_2000HZ\020\003b\006"
      "proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 566);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "FastPwm_test.proto", &protobuf_RegisterTypes);
  ::protobuf_brewblox_5ftest_2eproto::AddDescriptors();
  ::protobuf_nanopb_5ftest_2eproto::AddDescriptors();
  ::protobuf_Constraints_5ftest_2eproto::AddDescriptors();
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
}  // namespace protobuf_FastPwm_5ftest_2eproto
namespace blox_test {
namespace FastPwm {
const ::google::protobuf::EnumDescriptor* PwmFrequency_descriptor() {
  protobuf_FastPwm_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_FastPwm_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool PwmFrequency_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void Block::InitAsDefaultInstance() {
  ::blox_test::FastPwm::_Block_default_instance_._instance.get_mutable()->constrainedby_ = const_cast< ::blox_test::Constraints::AnalogConstraints*>(
      ::blox_test::Constraints::AnalogConstraints::internal_default_instance());
}
void Block::clear_constrainedby() {
  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Block::kHwDeviceFieldNumber;
const int Block::kChannelFieldNumber;
const int Block::kFrequencyFieldNumber;
const int Block::kSettingFieldNumber;
const int Block::kDesiredSettingFieldNumber;
const int Block::kValueFieldNumber;
const int Block::kConstrainedByFieldNumber;
const int Block::kEnabledFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Block::Block()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_FastPwm_5ftest_2eproto::scc_info_Block.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox_test.FastPwm.Block)
}
Block::Block(const Block& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  if (from.has_constrainedby()) {
    constrainedby_ = new ::blox_test::Constraints::AnalogConstraints(*from.constrainedby_);
  } else {
    constrainedby_ = NULL;
  }
  ::memcpy(&hwdevice_, &from.hwdevice_,
    static_cast<size_t>(reinterpret_cast<char*>(&enabled_) -
    reinterpret_cast<char*>(&hwdevice_)) + sizeof(enabled_));
  // @@protoc_insertion_point(copy_constructor:blox_test.FastPwm.Block)
}

void Block::SharedCtor() {
  ::memset(&constrainedby_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&enabled_) -
      reinterpret_cast<char*>(&constrainedby_)) + sizeof(enabled_));
}

Block::~Block() {
  // @@protoc_insertion_point(destructor:blox_test.FastPwm.Block)
  SharedDtor();
}

void Block::SharedDtor() {
  if (this != internal_default_instance()) delete constrainedby_;
}

void Block::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* Block::descriptor() {
  ::protobuf_FastPwm_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_FastPwm_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const Block& Block::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_FastPwm_5ftest_2eproto::scc_info_Block.base);
  return *internal_default_instance();
}


void Block::Clear() {
// @@protoc_insertion_point(message_clear_start:blox_test.FastPwm.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaNoVirtual() == NULL && constrainedby_ != NULL) {
    delete constrainedby_;
  }
  constrainedby_ = NULL;
  ::memset(&hwdevice_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&enabled_) -
      reinterpret_cast<char*>(&hwdevice_)) + sizeof(enabled_));
  _internal_metadata_.Clear();
}

bool Block::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox_test.FastPwm.Block)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // uint32 hwDevice = 1 [(.nanopb) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &hwdevice_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 channel = 2 [(.nanopb) = {
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &channel_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox_test.FastPwm.PwmFrequency frequency = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(24u /* 24 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_frequency(static_cast< ::blox_test::FastPwm::PwmFrequency >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 setting = 4 [(.nanopb) = {
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(32u /* 32 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &setting_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 desiredSetting = 5 [(.nanopb) = {
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(40u /* 40 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_SINT32>(
                 input, &desiredsetting_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // sint32 value = 6 [(.nanopb) = {
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

      // .blox_test.Constraints.AnalogConstraints constrainedBy = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(58u /* 58 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_constrainedby()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool enabled = 8;
      case 8: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(64u /* 64 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &enabled_)));
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
  // @@protoc_insertion_point(parse_success:blox_test.FastPwm.Block)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox_test.FastPwm.Block)
  return false;
#undef DO_
}

void Block::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox_test.FastPwm.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 hwDevice = 1 [(.nanopb) = {
  if (this->hwdevice() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->hwdevice(), output);
  }

  // uint32 channel = 2 [(.nanopb) = {
  if (this->channel() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(2, this->channel(), output);
  }

  // .blox_test.FastPwm.PwmFrequency frequency = 3;
  if (this->frequency() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->frequency(), output);
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(4, this->setting(), output);
  }

  // sint32 desiredSetting = 5 [(.nanopb) = {
  if (this->desiredsetting() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(5, this->desiredsetting(), output);
  }

  // sint32 value = 6 [(.nanopb) = {
  if (this->value() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteSInt32(6, this->value(), output);
  }

  // .blox_test.Constraints.AnalogConstraints constrainedBy = 7;
  if (this->has_constrainedby()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      7, this->_internal_constrainedby(), output);
  }

  // bool enabled = 8;
  if (this->enabled() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(8, this->enabled(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox_test.FastPwm.Block)
}

::google::protobuf::uint8* Block::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox_test.FastPwm.Block)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // uint32 hwDevice = 1 [(.nanopb) = {
  if (this->hwdevice() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->hwdevice(), target);
  }

  // uint32 channel = 2 [(.nanopb) = {
  if (this->channel() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(2, this->channel(), target);
  }

  // .blox_test.FastPwm.PwmFrequency frequency = 3;
  if (this->frequency() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->frequency(), target);
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(4, this->setting(), target);
  }

  // sint32 desiredSetting = 5 [(.nanopb) = {
  if (this->desiredsetting() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(5, this->desiredsetting(), target);
  }

  // sint32 value = 6 [(.nanopb) = {
  if (this->value() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteSInt32ToArray(6, this->value(), target);
  }

  // .blox_test.Constraints.AnalogConstraints constrainedBy = 7;
  if (this->has_constrainedby()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        7, this->_internal_constrainedby(), deterministic, target);
  }

  // bool enabled = 8;
  if (this->enabled() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(8, this->enabled(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox_test.FastPwm.Block)
  return target;
}

size_t Block::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox_test.FastPwm.Block)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .blox_test.Constraints.AnalogConstraints constrainedBy = 7;
  if (this->has_constrainedby()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *constrainedby_);
  }

  // uint32 hwDevice = 1 [(.nanopb) = {
  if (this->hwdevice() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->hwdevice());
  }

  // uint32 channel = 2 [(.nanopb) = {
  if (this->channel() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->channel());
  }

  // .blox_test.FastPwm.PwmFrequency frequency = 3;
  if (this->frequency() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->frequency());
  }

  // sint32 setting = 4 [(.nanopb) = {
  if (this->setting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->setting());
  }

  // sint32 desiredSetting = 5 [(.nanopb) = {
  if (this->desiredsetting() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->desiredsetting());
  }

  // sint32 value = 6 [(.nanopb) = {
  if (this->value() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::SInt32Size(
        this->value());
  }

  // bool enabled = 8;
  if (this->enabled() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Block::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox_test.FastPwm.Block)
  GOOGLE_DCHECK_NE(&from, this);
  const Block* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const Block>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox_test.FastPwm.Block)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox_test.FastPwm.Block)
    MergeFrom(*source);
  }
}

void Block::MergeFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox_test.FastPwm.Block)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.has_constrainedby()) {
    mutable_constrainedby()->::blox_test::Constraints::AnalogConstraints::MergeFrom(from.constrainedby());
  }
  if (from.hwdevice() != 0) {
    set_hwdevice(from.hwdevice());
  }
  if (from.channel() != 0) {
    set_channel(from.channel());
  }
  if (from.frequency() != 0) {
    set_frequency(from.frequency());
  }
  if (from.setting() != 0) {
    set_setting(from.setting());
  }
  if (from.desiredsetting() != 0) {
    set_desiredsetting(from.desiredsetting());
  }
  if (from.value() != 0) {
    set_value(from.value());
  }
  if (from.enabled() != 0) {
    set_enabled(from.enabled());
  }
}

void Block::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox_test.FastPwm.Block)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Block::CopyFrom(const Block& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox_test.FastPwm.Block)
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
  swap(constrainedby_, other->constrainedby_);
  swap(hwdevice_, other->hwdevice_);
  swap(channel_, other->channel_);
  swap(frequency_, other->frequency_);
  swap(setting_, other->setting_);
  swap(desiredsetting_, other->desiredsetting_);
  swap(value_, other->value_);
  swap(enabled_, other->enabled_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata Block::GetMetadata() const {
  protobuf_FastPwm_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_FastPwm_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace FastPwm
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox_test::FastPwm::Block* Arena::CreateMaybeMessage< ::blox_test::FastPwm::Block >(Arena* arena) {
  return Arena::CreateInternal< ::blox_test::FastPwm::Block >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
