// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: IoArray_test.proto

#include "IoArray_test.pb.h"

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
class IoChannelDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<IoChannel>
      _instance;
} _IoChannel_default_instance_;
}  // namespace blox
namespace protobuf_IoArray_5ftest_2eproto {
static void InitDefaultsIoChannel() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox::_IoChannel_default_instance_;
    new (ptr) ::blox::IoChannel();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox::IoChannel::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_IoChannel =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsIoChannel}, {}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_IoChannel.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::IoChannel, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::IoChannel, config_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::IoChannel, state_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::IoChannel)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox::_IoChannel_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "IoArray_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\022IoArray_test.proto\022\004blox\"S\n\tIoChannel\022"
      "#\n\006config\030\001 \001(\0162\023.blox.ChannelConfig\022!\n\005"
      "state\030\002 \001(\0162\022.blox.DigitalState*r\n\014Digit"
      "alState\022\022\n\016STATE_INACTIVE\020\000\022\020\n\014STATE_ACT"
      "IVE\020\001\022\021\n\rSTATE_UNKNOWN\020\002\022\014\n\010Inactive\020\000\022\n"
      "\n\006Active\020\001\022\013\n\007Unknown\020\002\032\002\020\001*\322\002\n\rChannelC"
      "onfig\022\022\n\016CHANNEL_UNUSED\020\000\022\027\n\023CHANNEL_DRI"
      "VING_OFF\020\001\022\026\n\022CHANNEL_DRIVING_ON\020\002\022\033\n\027CH"
      "ANNEL_DRIVING_REVERSE\020\003\022\"\n\036CHANNEL_DRIVI"
      "NG_BRAKE_LOW_SIDE\020\004\022#\n\037CHANNEL_DRIVING_B"
      "RAKE_HIGH_SIDE\020\005\022\027\n\023CHANNEL_DRIVING_PWM\020"
      "\006\022\037\n\033CHANNEL_DRIVING_PWM_REVERSE\020\007\022\021\n\rCH"
      "ANNEL_INPUT\020\n\022\024\n\017CHANNEL_UNKNOWN\020\377\001\022\026\n\022C"
      "HANNEL_ACTIVE_LOW\020\001\022\027\n\023CHANNEL_ACTIVE_HI"
      "GH\020\002\032\002\020\001b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 576);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "IoArray_test.proto", &protobuf_RegisterTypes);
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
}  // namespace protobuf_IoArray_5ftest_2eproto
namespace blox {
const ::google::protobuf::EnumDescriptor* DigitalState_descriptor() {
  protobuf_IoArray_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_IoArray_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool DigitalState_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* ChannelConfig_descriptor() {
  protobuf_IoArray_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_IoArray_5ftest_2eproto::file_level_enum_descriptors[1];
}
bool ChannelConfig_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 255:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void IoChannel::InitAsDefaultInstance() {
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int IoChannel::kConfigFieldNumber;
const int IoChannel::kStateFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

IoChannel::IoChannel()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_IoArray_5ftest_2eproto::scc_info_IoChannel.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox.IoChannel)
}
IoChannel::IoChannel(const IoChannel& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&config_, &from.config_,
    static_cast<size_t>(reinterpret_cast<char*>(&state_) -
    reinterpret_cast<char*>(&config_)) + sizeof(state_));
  // @@protoc_insertion_point(copy_constructor:blox.IoChannel)
}

void IoChannel::SharedCtor() {
  ::memset(&config_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&state_) -
      reinterpret_cast<char*>(&config_)) + sizeof(state_));
}

IoChannel::~IoChannel() {
  // @@protoc_insertion_point(destructor:blox.IoChannel)
  SharedDtor();
}

void IoChannel::SharedDtor() {
}

void IoChannel::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* IoChannel::descriptor() {
  ::protobuf_IoArray_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_IoArray_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const IoChannel& IoChannel::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_IoArray_5ftest_2eproto::scc_info_IoChannel.base);
  return *internal_default_instance();
}


void IoChannel::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.IoChannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&config_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&state_) -
      reinterpret_cast<char*>(&config_)) + sizeof(state_));
  _internal_metadata_.Clear();
}

bool IoChannel::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox.IoChannel)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // .blox.ChannelConfig config = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_config(static_cast< ::blox::ChannelConfig >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.DigitalState state = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_state(static_cast< ::blox::DigitalState >(value));
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
  // @@protoc_insertion_point(parse_success:blox.IoChannel)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox.IoChannel)
  return false;
#undef DO_
}

void IoChannel::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox.IoChannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .blox.ChannelConfig config = 1;
  if (this->config() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      1, this->config(), output);
  }

  // .blox.DigitalState state = 2;
  if (this->state() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->state(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox.IoChannel)
}

::google::protobuf::uint8* IoChannel::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox.IoChannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .blox.ChannelConfig config = 1;
  if (this->config() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      1, this->config(), target);
  }

  // .blox.DigitalState state = 2;
  if (this->state() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->state(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.IoChannel)
  return target;
}

size_t IoChannel::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.IoChannel)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // .blox.ChannelConfig config = 1;
  if (this->config() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->config());
  }

  // .blox.DigitalState state = 2;
  if (this->state() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->state());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void IoChannel::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox.IoChannel)
  GOOGLE_DCHECK_NE(&from, this);
  const IoChannel* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const IoChannel>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox.IoChannel)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox.IoChannel)
    MergeFrom(*source);
  }
}

void IoChannel::MergeFrom(const IoChannel& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.IoChannel)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.config() != 0) {
    set_config(from.config());
  }
  if (from.state() != 0) {
    set_state(from.state());
  }
}

void IoChannel::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox.IoChannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void IoChannel::CopyFrom(const IoChannel& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.IoChannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool IoChannel::IsInitialized() const {
  return true;
}

void IoChannel::Swap(IoChannel* other) {
  if (other == this) return;
  InternalSwap(other);
}
void IoChannel::InternalSwap(IoChannel* other) {
  using std::swap;
  swap(config_, other->config_);
  swap(state_, other->state_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata IoChannel::GetMetadata() const {
  protobuf_IoArray_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_IoArray_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox::IoChannel* Arena::CreateMaybeMessage< ::blox::IoChannel >(Arena* arena) {
  return Arena::CreateInternal< ::blox::IoChannel >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
