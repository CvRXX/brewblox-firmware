// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DS2408_test.proto

#include "DS2408_test.pb.h"

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

namespace protobuf_IoArray_5ftest_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_IoArray_5ftest_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_IoChannel;
}  // namespace protobuf_IoArray_5ftest_2eproto
namespace blox {
class DS2408DefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<DS2408>
      _instance;
} _DS2408_default_instance_;
}  // namespace blox
namespace protobuf_DS2408_5ftest_2eproto {
static void InitDefaultsDS2408() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::blox::_DS2408_default_instance_;
    new (ptr) ::blox::DS2408();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::blox::DS2408::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_DS2408 =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsDS2408}, {
      &protobuf_IoArray_5ftest_2eproto::scc_info_IoChannel.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_DS2408.base);
}

::google::protobuf::Metadata file_level_metadata[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors[2];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::DS2408, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::DS2408, address_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::DS2408, connected_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::DS2408, connectmode_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::DS2408, onewirebusid_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::blox::DS2408, channels_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::DS2408)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::blox::_DS2408_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "DS2408_test.proto", schemas, file_default_instances, TableStruct::offsets,
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
      "\n\021DS2408_test.proto\022\004blox\032\023brewblox_test"
      ".proto\032\021nanopb_test.proto\032\022IoArray_test."
      "proto\"\236\002\n\006DS2408\022\027\n\007address\030\001 \001(\006B\006\212\265\030\002 "
      "\001\022\031\n\tconnected\030\006 \001(\010B\006\212\265\030\002(\001\0220\n\013connectM"
      "ode\030\t \001(\0162\033.blox.DS2408.PinConnectMode\022("
      "\n\014oneWireBusId\030\n \001(\rB\022\212\265\030\003\030\202\002\222\?\0028\020\212\265\030\002(\001"
      "\022.\n\010channels\030\013 \003(\0132\017.blox.IoChannelB\013\222\?\002"
      "\020\010\212\265\030\002(\001\"9\n\016PinConnectMode\022\021\n\rCONNECT_VA"
      "LVE\020\000\022\024\n\020CONNECT_ACTUATOR\020\001:\031\212\265\030\003\030\275\002\212\265\030\002"
      "H\n\212\265\030\002H\013\212\265\030\002H\t*\203\002\n\020DS2408ChannelIds\022\024\n\020D"
      "S2408_CHAN_NONE\020\000\022\021\n\rDS2408_CHAN_A\020\001\022\021\n\r"
      "DS2408_CHAN_B\020\002\022\021\n\rDS2408_CHAN_C\020\003\022\021\n\rDS"
      "2408_CHAN_D\020\004\022\021\n\rDS2408_CHAN_E\020\005\022\021\n\rDS24"
      "08_CHAN_F\020\006\022\021\n\rDS2408_CHAN_G\020\007\022\021\n\rDS2408"
      "_CHAN_H\020\010\022\025\n\021DS2408_VALVE_NONE\020\000\022\022\n\016DS24"
      "08_VALVE_A\020\001\022\022\n\016DS2408_VALVE_B\020\005\032\002\020\001b\006pr"
      "oto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 644);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "DS2408_test.proto", &protobuf_RegisterTypes);
  ::protobuf_brewblox_5ftest_2eproto::AddDescriptors();
  ::protobuf_nanopb_5ftest_2eproto::AddDescriptors();
  ::protobuf_IoArray_5ftest_2eproto::AddDescriptors();
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
}  // namespace protobuf_DS2408_5ftest_2eproto
namespace blox {
const ::google::protobuf::EnumDescriptor* DS2408_PinConnectMode_descriptor() {
  protobuf_DS2408_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_DS2408_5ftest_2eproto::file_level_enum_descriptors[0];
}
bool DS2408_PinConnectMode_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const DS2408_PinConnectMode DS2408::CONNECT_VALVE;
const DS2408_PinConnectMode DS2408::CONNECT_ACTUATOR;
const DS2408_PinConnectMode DS2408::PinConnectMode_MIN;
const DS2408_PinConnectMode DS2408::PinConnectMode_MAX;
const int DS2408::PinConnectMode_ARRAYSIZE;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900
const ::google::protobuf::EnumDescriptor* DS2408ChannelIds_descriptor() {
  protobuf_DS2408_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return protobuf_DS2408_5ftest_2eproto::file_level_enum_descriptors[1];
}
bool DS2408ChannelIds_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void DS2408::InitAsDefaultInstance() {
}
void DS2408::clear_channels() {
  channels_.Clear();
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int DS2408::kAddressFieldNumber;
const int DS2408::kConnectedFieldNumber;
const int DS2408::kConnectModeFieldNumber;
const int DS2408::kOneWireBusIdFieldNumber;
const int DS2408::kChannelsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

DS2408::DS2408()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_DS2408_5ftest_2eproto::scc_info_DS2408.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:blox.DS2408)
}
DS2408::DS2408(const DS2408& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL),
      channels_(from.channels_) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::memcpy(&address_, &from.address_,
    static_cast<size_t>(reinterpret_cast<char*>(&connectmode_) -
    reinterpret_cast<char*>(&address_)) + sizeof(connectmode_));
  // @@protoc_insertion_point(copy_constructor:blox.DS2408)
}

void DS2408::SharedCtor() {
  ::memset(&address_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&connectmode_) -
      reinterpret_cast<char*>(&address_)) + sizeof(connectmode_));
}

DS2408::~DS2408() {
  // @@protoc_insertion_point(destructor:blox.DS2408)
  SharedDtor();
}

void DS2408::SharedDtor() {
}

void DS2408::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* DS2408::descriptor() {
  ::protobuf_DS2408_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DS2408_5ftest_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const DS2408& DS2408::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_DS2408_5ftest_2eproto::scc_info_DS2408.base);
  return *internal_default_instance();
}


void DS2408::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.DS2408)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  channels_.Clear();
  ::memset(&address_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&connectmode_) -
      reinterpret_cast<char*>(&address_)) + sizeof(connectmode_));
  _internal_metadata_.Clear();
}

bool DS2408::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:blox.DS2408)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // fixed64 address = 1 [(.brewblox_test) = {
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(9u /* 9 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_FIXED64>(
                 input, &address_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool connected = 6 [(.brewblox_test) = {
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &connected_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .blox.DS2408.PinConnectMode connectMode = 9;
      case 9: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(72u /* 72 & 0xFF */)) {
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_connectmode(static_cast< ::blox::DS2408_PinConnectMode >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // uint32 oneWireBusId = 10 [(.nanopb_test) = {
      case 10: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(80u /* 80 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &onewirebusid_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // repeated .blox.IoChannel channels = 11 [(.nanopb_test) = {
      case 11: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(90u /* 90 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
                input, add_channels()));
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
  // @@protoc_insertion_point(parse_success:blox.DS2408)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:blox.DS2408)
  return false;
#undef DO_
}

void DS2408::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:blox.DS2408)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // fixed64 address = 1 [(.brewblox_test) = {
  if (this->address() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteFixed64(1, this->address(), output);
  }

  // bool connected = 6 [(.brewblox_test) = {
  if (this->connected() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(6, this->connected(), output);
  }

  // .blox.DS2408.PinConnectMode connectMode = 9;
  if (this->connectmode() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      9, this->connectmode(), output);
  }

  // uint32 oneWireBusId = 10 [(.nanopb_test) = {
  if (this->onewirebusid() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(10, this->onewirebusid(), output);
  }

  // repeated .blox.IoChannel channels = 11 [(.nanopb_test) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->channels_size()); i < n; i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      11,
      this->channels(static_cast<int>(i)),
      output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:blox.DS2408)
}

::google::protobuf::uint8* DS2408::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:blox.DS2408)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // fixed64 address = 1 [(.brewblox_test) = {
  if (this->address() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteFixed64ToArray(1, this->address(), target);
  }

  // bool connected = 6 [(.brewblox_test) = {
  if (this->connected() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(6, this->connected(), target);
  }

  // .blox.DS2408.PinConnectMode connectMode = 9;
  if (this->connectmode() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      9, this->connectmode(), target);
  }

  // uint32 oneWireBusId = 10 [(.nanopb_test) = {
  if (this->onewirebusid() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(10, this->onewirebusid(), target);
  }

  // repeated .blox.IoChannel channels = 11 [(.nanopb_test) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->channels_size()); i < n; i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        11, this->channels(static_cast<int>(i)), deterministic, target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.DS2408)
  return target;
}

size_t DS2408::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.DS2408)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // repeated .blox.IoChannel channels = 11 [(.nanopb_test) = {
  {
    unsigned int count = static_cast<unsigned int>(this->channels_size());
    total_size += 1UL * count;
    for (unsigned int i = 0; i < count; i++) {
      total_size +=
        ::google::protobuf::internal::WireFormatLite::MessageSize(
          this->channels(static_cast<int>(i)));
    }
  }

  // fixed64 address = 1 [(.brewblox_test) = {
  if (this->address() != 0) {
    total_size += 1 + 8;
  }

  // uint32 oneWireBusId = 10 [(.nanopb_test) = {
  if (this->onewirebusid() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::UInt32Size(
        this->onewirebusid());
  }

  // bool connected = 6 [(.brewblox_test) = {
  if (this->connected() != 0) {
    total_size += 1 + 1;
  }

  // .blox.DS2408.PinConnectMode connectMode = 9;
  if (this->connectmode() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->connectmode());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void DS2408::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:blox.DS2408)
  GOOGLE_DCHECK_NE(&from, this);
  const DS2408* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const DS2408>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:blox.DS2408)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:blox.DS2408)
    MergeFrom(*source);
  }
}

void DS2408::MergeFrom(const DS2408& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.DS2408)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  channels_.MergeFrom(from.channels_);
  if (from.address() != 0) {
    set_address(from.address());
  }
  if (from.onewirebusid() != 0) {
    set_onewirebusid(from.onewirebusid());
  }
  if (from.connected() != 0) {
    set_connected(from.connected());
  }
  if (from.connectmode() != 0) {
    set_connectmode(from.connectmode());
  }
}

void DS2408::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:blox.DS2408)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DS2408::CopyFrom(const DS2408& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:blox.DS2408)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DS2408::IsInitialized() const {
  return true;
}

void DS2408::Swap(DS2408* other) {
  if (other == this) return;
  InternalSwap(other);
}
void DS2408::InternalSwap(DS2408* other) {
  using std::swap;
  CastToBase(&channels_)->InternalSwap(CastToBase(&other->channels_));
  swap(address_, other->address_);
  swap(onewirebusid_, other->onewirebusid_);
  swap(connected_, other->connected_);
  swap(connectmode_, other->connectmode_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata DS2408::GetMetadata() const {
  protobuf_DS2408_5ftest_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_DS2408_5ftest_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::blox::DS2408* Arena::CreateMaybeMessage< ::blox::DS2408 >(Arena* arena) {
  return Arena::CreateInternal< ::blox::DS2408 >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
