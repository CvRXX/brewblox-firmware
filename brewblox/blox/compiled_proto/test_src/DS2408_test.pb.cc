// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DS2408_test.proto

#include "DS2408_test.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG
namespace blox {
constexpr DS2408::DS2408(
  ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized)
  : channels_()
  , address_(uint64_t{0u})
  , connected_(false)
  , pins_(false)
  , connectmode_(0)

  , onewirebusid_(0u){}
struct DS2408DefaultTypeInternal {
  constexpr DS2408DefaultTypeInternal()
    : _instance(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized{}) {}
  ~DS2408DefaultTypeInternal() {}
  union {
    DS2408 _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT DS2408DefaultTypeInternal _DS2408_default_instance_;
}  // namespace blox
static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_DS2408_5ftest_2eproto[1];
static const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* file_level_enum_descriptors_DS2408_5ftest_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_DS2408_5ftest_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_DS2408_5ftest_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::blox::DS2408, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::blox::DS2408, address_),
  PROTOBUF_FIELD_OFFSET(::blox::DS2408, connected_),
  PROTOBUF_FIELD_OFFSET(::blox::DS2408, connectmode_),
  PROTOBUF_FIELD_OFFSET(::blox::DS2408, onewirebusid_),
  PROTOBUF_FIELD_OFFSET(::blox::DS2408, channels_),
  PROTOBUF_FIELD_OFFSET(::blox::DS2408, pins_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::blox::DS2408)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::blox::_DS2408_default_instance_),
};

const char descriptor_table_protodef_DS2408_5ftest_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\021DS2408_test.proto\022\004blox\032\023brewblox_test"
  ".proto\032\021nanopb_test.proto\032\022IoArray_test."
  "proto\"\271\002\n\006DS2408\022\027\n\007address\030\001 \001(\006B\006\212\265\030\002 "
  "\001\022\031\n\tconnected\030\006 \001(\010B\006\212\265\030\002(\001\0220\n\013connectM"
  "ode\030\t \001(\0162\033.blox.DS2408.PinConnectMode\022("
  "\n\014oneWireBusId\030\n \001(\rB\022\212\265\030\003\030\202\002\222\?\0028\020\212\265\030\002(\001"
  "\022.\n\010channels\030\013 \003(\0132\017.blox.IoChannelB\013\222\?\002"
  "\020\010\212\265\030\002(\001\022\031\n\004pins\030Z \001(\010B\013\212\265\030\002H\001\222\?\002\030\003\"9\n\016P"
  "inConnectMode\022\021\n\rCONNECT_VALVE\020\000\022\024\n\020CONN"
  "ECT_ACTUATOR\020\001:\031\212\265\030\003\030\275\002\212\265\030\002H\n\212\265\030\002H\013\212\265\030\002H"
  "\t*\203\002\n\020DS2408ChannelIds\022\024\n\020DS2408_CHAN_NO"
  "NE\020\000\022\021\n\rDS2408_CHAN_A\020\001\022\021\n\rDS2408_CHAN_B"
  "\020\002\022\021\n\rDS2408_CHAN_C\020\003\022\021\n\rDS2408_CHAN_D\020\004"
  "\022\021\n\rDS2408_CHAN_E\020\005\022\021\n\rDS2408_CHAN_F\020\006\022\021"
  "\n\rDS2408_CHAN_G\020\007\022\021\n\rDS2408_CHAN_H\020\010\022\025\n\021"
  "DS2408_VALVE_NONE\020\000\022\022\n\016DS2408_VALVE_A\020\005\022"
  "\022\n\016DS2408_VALVE_B\020\001\032\002\020\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_DS2408_5ftest_2eproto_deps[3] = {
  &::descriptor_table_IoArray_5ftest_2eproto,
  &::descriptor_table_brewblox_5ftest_2eproto,
  &::descriptor_table_nanopb_5ftest_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_DS2408_5ftest_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_DS2408_5ftest_2eproto = {
  false, false, 671, descriptor_table_protodef_DS2408_5ftest_2eproto, "DS2408_test.proto", 
  &descriptor_table_DS2408_5ftest_2eproto_once, descriptor_table_DS2408_5ftest_2eproto_deps, 3, 1,
  schemas, file_default_instances, TableStruct_DS2408_5ftest_2eproto::offsets,
  file_level_metadata_DS2408_5ftest_2eproto, file_level_enum_descriptors_DS2408_5ftest_2eproto, file_level_service_descriptors_DS2408_5ftest_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable* descriptor_table_DS2408_5ftest_2eproto_getter() {
  return &descriptor_table_DS2408_5ftest_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY static ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptorsRunner dynamic_init_dummy_DS2408_5ftest_2eproto(&descriptor_table_DS2408_5ftest_2eproto);
namespace blox {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DS2408_PinConnectMode_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_DS2408_5ftest_2eproto);
  return file_level_enum_descriptors_DS2408_5ftest_2eproto[0];
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

#if (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
constexpr DS2408_PinConnectMode DS2408::CONNECT_VALVE;
constexpr DS2408_PinConnectMode DS2408::CONNECT_ACTUATOR;
constexpr DS2408_PinConnectMode DS2408::PinConnectMode_MIN;
constexpr DS2408_PinConnectMode DS2408::PinConnectMode_MAX;
constexpr int DS2408::PinConnectMode_ARRAYSIZE;
#endif  // (__cplusplus < 201703) && (!defined(_MSC_VER) || _MSC_VER >= 1900)
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* DS2408ChannelIds_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_DS2408_5ftest_2eproto);
  return file_level_enum_descriptors_DS2408_5ftest_2eproto[1];
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

class DS2408::_Internal {
 public:
};

void DS2408::clear_channels() {
  channels_.Clear();
}
DS2408::DS2408(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned),
  channels_(arena) {
  SharedCtor();
  if (!is_message_owned) {
    RegisterArenaDtor(arena);
  }
  // @@protoc_insertion_point(arena_constructor:blox.DS2408)
}
DS2408::DS2408(const DS2408& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      channels_(from.channels_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&address_, &from.address_,
    static_cast<size_t>(reinterpret_cast<char*>(&onewirebusid_) -
    reinterpret_cast<char*>(&address_)) + sizeof(onewirebusid_));
  // @@protoc_insertion_point(copy_constructor:blox.DS2408)
}

inline void DS2408::SharedCtor() {
::memset(reinterpret_cast<char*>(this) + static_cast<size_t>(
    reinterpret_cast<char*>(&address_) - reinterpret_cast<char*>(this)),
    0, static_cast<size_t>(reinterpret_cast<char*>(&onewirebusid_) -
    reinterpret_cast<char*>(&address_)) + sizeof(onewirebusid_));
}

DS2408::~DS2408() {
  // @@protoc_insertion_point(destructor:blox.DS2408)
  if (GetArenaForAllocation() != nullptr) return;
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

inline void DS2408::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void DS2408::ArenaDtor(void* object) {
  DS2408* _this = reinterpret_cast< DS2408* >(object);
  (void)_this;
}
void DS2408::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void DS2408::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}

void DS2408::Clear() {
// @@protoc_insertion_point(message_clear_start:blox.DS2408)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  channels_.Clear();
  ::memset(&address_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&onewirebusid_) -
      reinterpret_cast<char*>(&address_)) + sizeof(onewirebusid_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* DS2408::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // fixed64 address = 1 [(.brewblox_test) = {
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 9)) {
          address_ = ::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<::PROTOBUF_NAMESPACE_ID::uint64>(ptr);
          ptr += sizeof(::PROTOBUF_NAMESPACE_ID::uint64);
        } else goto handle_unusual;
        continue;
      // bool connected = 6 [(.brewblox_test) = {
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 48)) {
          connected_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .blox.DS2408.PinConnectMode connectMode = 9;
      case 9:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 72)) {
          ::PROTOBUF_NAMESPACE_ID::uint64 val = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
          _internal_set_connectmode(static_cast<::blox::DS2408_PinConnectMode>(val));
        } else goto handle_unusual;
        continue;
      // uint32 oneWireBusId = 10 [(.nanopb_test) = {
      case 10:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 80)) {
          onewirebusid_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated .blox.IoChannel channels = 11 [(.nanopb_test) = {
      case 11:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 90)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_channels(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<90>(ptr));
        } else goto handle_unusual;
        continue;
      // bool pins = 90 [(.nanopb_test) = {
      case 90:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 208)) {
          pins_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag == 0) || ((tag & 7) == 4)) {
          CHK_(ptr);
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* DS2408::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:blox.DS2408)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // fixed64 address = 1 [(.brewblox_test) = {
  if (this->_internal_address() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteFixed64ToArray(1, this->_internal_address(), target);
  }

  // bool connected = 6 [(.brewblox_test) = {
  if (this->_internal_connected() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(6, this->_internal_connected(), target);
  }

  // .blox.DS2408.PinConnectMode connectMode = 9;
  if (this->_internal_connectmode() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteEnumToArray(
      9, this->_internal_connectmode(), target);
  }

  // uint32 oneWireBusId = 10 [(.nanopb_test) = {
  if (this->_internal_onewirebusid() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteUInt32ToArray(10, this->_internal_onewirebusid(), target);
  }

  // repeated .blox.IoChannel channels = 11 [(.nanopb_test) = {
  for (unsigned int i = 0,
      n = static_cast<unsigned int>(this->_internal_channels_size()); i < n; i++) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(11, this->_internal_channels(i), target, stream);
  }

  // bool pins = 90 [(.nanopb_test) = {
  if (this->_internal_pins() != 0) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(90, this->_internal_pins(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:blox.DS2408)
  return target;
}

size_t DS2408::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:blox.DS2408)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .blox.IoChannel channels = 11 [(.nanopb_test) = {
  total_size += 1UL * this->_internal_channels_size();
  for (const auto& msg : this->channels_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // fixed64 address = 1 [(.brewblox_test) = {
  if (this->_internal_address() != 0) {
    total_size += 1 + 8;
  }

  // bool connected = 6 [(.brewblox_test) = {
  if (this->_internal_connected() != 0) {
    total_size += 1 + 1;
  }

  // bool pins = 90 [(.nanopb_test) = {
  if (this->_internal_pins() != 0) {
    total_size += 2 + 1;
  }

  // .blox.DS2408.PinConnectMode connectMode = 9;
  if (this->_internal_connectmode() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::EnumSize(this->_internal_connectmode());
  }

  // uint32 oneWireBusId = 10 [(.nanopb_test) = {
  if (this->_internal_onewirebusid() != 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::UInt32Size(
        this->_internal_onewirebusid());
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData DS2408::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSizeCheck,
    DS2408::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*DS2408::GetClassData() const { return &_class_data_; }

void DS2408::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to,
                      const ::PROTOBUF_NAMESPACE_ID::Message&from) {
  static_cast<DS2408 *>(to)->MergeFrom(
      static_cast<const DS2408 &>(from));
}


void DS2408::MergeFrom(const DS2408& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:blox.DS2408)
  GOOGLE_DCHECK_NE(&from, this);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  channels_.MergeFrom(from.channels_);
  if (from._internal_address() != 0) {
    _internal_set_address(from._internal_address());
  }
  if (from._internal_connected() != 0) {
    _internal_set_connected(from._internal_connected());
  }
  if (from._internal_pins() != 0) {
    _internal_set_pins(from._internal_pins());
  }
  if (from._internal_connectmode() != 0) {
    _internal_set_connectmode(from._internal_connectmode());
  }
  if (from._internal_onewirebusid() != 0) {
    _internal_set_onewirebusid(from._internal_onewirebusid());
  }
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
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

void DS2408::InternalSwap(DS2408* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  channels_.InternalSwap(&other->channels_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(DS2408, onewirebusid_)
      + sizeof(DS2408::onewirebusid_)
      - PROTOBUF_FIELD_OFFSET(DS2408, address_)>(
          reinterpret_cast<char*>(&address_),
          reinterpret_cast<char*>(&other->address_));
}

::PROTOBUF_NAMESPACE_ID::Metadata DS2408::GetMetadata() const {
  return ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(
      &descriptor_table_DS2408_5ftest_2eproto_getter, &descriptor_table_DS2408_5ftest_2eproto_once,
      file_level_metadata_DS2408_5ftest_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::blox::DS2408* Arena::CreateMaybeMessage< ::blox::DS2408 >(Arena* arena) {
  return Arena::CreateMessageInternal< ::blox::DS2408 >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
