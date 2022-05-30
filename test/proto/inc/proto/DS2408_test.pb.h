// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DS2408_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_DS2408_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_DS2408_5ftest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3020000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3020001 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
#include "IoArray_test.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_DS2408_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_DS2408_5ftest_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_DS2408_5ftest_2eproto;
namespace blox_test {
namespace DS2408 {
class Block;
struct BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
}  // namespace DS2408
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> ::blox_test::DS2408::Block* Arena::CreateMaybeMessage<::blox_test::DS2408::Block>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox_test {
namespace DS2408 {

enum ChannelId : int {
  DS2408_CHAN_NONE = 0,
  DS2408_CHAN_A = 1,
  DS2408_CHAN_B = 2,
  DS2408_CHAN_C = 3,
  DS2408_CHAN_D = 4,
  DS2408_CHAN_E = 5,
  DS2408_CHAN_F = 6,
  DS2408_CHAN_G = 7,
  DS2408_CHAN_H = 8,
  DS2408_VALVE_NONE = 0,
  DS2408_VALVE_A = 5,
  DS2408_VALVE_B = 1,
  ChannelId_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  ChannelId_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool ChannelId_IsValid(int value);
constexpr ChannelId ChannelId_MIN = DS2408_CHAN_NONE;
constexpr ChannelId ChannelId_MAX = DS2408_CHAN_H;
constexpr int ChannelId_ARRAYSIZE = ChannelId_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* ChannelId_descriptor();
template<typename T>
inline const std::string& ChannelId_Name(T enum_t_value) {
  static_assert(::std::is_same<T, ChannelId>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function ChannelId_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    ChannelId_descriptor(), enum_t_value);
}
inline bool ChannelId_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, ChannelId* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<ChannelId>(
    ChannelId_descriptor(), name, value);
}
enum PinConnectMode : int {
  CONNECT_VALVE = 0,
  CONNECT_ACTUATOR = 1,
  PinConnectMode_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PinConnectMode_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PinConnectMode_IsValid(int value);
constexpr PinConnectMode PinConnectMode_MIN = CONNECT_VALVE;
constexpr PinConnectMode PinConnectMode_MAX = CONNECT_ACTUATOR;
constexpr int PinConnectMode_ARRAYSIZE = PinConnectMode_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PinConnectMode_descriptor();
template<typename T>
inline const std::string& PinConnectMode_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PinConnectMode>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PinConnectMode_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PinConnectMode_descriptor(), enum_t_value);
}
inline bool PinConnectMode_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PinConnectMode* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PinConnectMode>(
    PinConnectMode_descriptor(), name, value);
}
// ===================================================================

class Block final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox_test.DS2408.Block) */ {
 public:
  inline Block() : Block(nullptr) {}
  ~Block() override;
  explicit PROTOBUF_CONSTEXPR Block(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Block(const Block& from);
  Block(Block&& from) noexcept
    : Block() {
    *this = ::std::move(from);
  }

  inline Block& operator=(const Block& from) {
    CopyFrom(from);
    return *this;
  }
  inline Block& operator=(Block&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Block& default_instance() {
    return *internal_default_instance();
  }
  static inline const Block* internal_default_instance() {
    return reinterpret_cast<const Block*>(
               &_Block_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Block& a, Block& b) {
    a.Swap(&b);
  }
  inline void Swap(Block* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Block* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Block* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Block>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Block& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Block& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Block* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox_test.DS2408.Block";
  }
  protected:
  explicit Block(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kChannelsFieldNumber = 11,
    kAddressFieldNumber = 1,
    kConnectModeFieldNumber = 9,
    kOneWireBusIdFieldNumber = 10,
    kConnectedFieldNumber = 6,
    kPinsFieldNumber = 90,
  };
  // repeated .blox_test.IoArray.IoChannel channels = 11 [(.nanopb) = {
  int channels_size() const;
  private:
  int _internal_channels_size() const;
  public:
  void clear_channels();
  ::blox_test::IoArray::IoChannel* mutable_channels(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::IoArray::IoChannel >*
      mutable_channels();
  private:
  const ::blox_test::IoArray::IoChannel& _internal_channels(int index) const;
  ::blox_test::IoArray::IoChannel* _internal_add_channels();
  public:
  const ::blox_test::IoArray::IoChannel& channels(int index) const;
  ::blox_test::IoArray::IoChannel* add_channels();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::IoArray::IoChannel >&
      channels() const;

  // fixed64 address = 1 [(.brewblox.field) = {
  void clear_address();
  uint64_t address() const;
  void set_address(uint64_t value);
  private:
  uint64_t _internal_address() const;
  void _internal_set_address(uint64_t value);
  public:

  // .blox_test.DS2408.PinConnectMode connectMode = 9;
  void clear_connectmode();
  ::blox_test::DS2408::PinConnectMode connectmode() const;
  void set_connectmode(::blox_test::DS2408::PinConnectMode value);
  private:
  ::blox_test::DS2408::PinConnectMode _internal_connectmode() const;
  void _internal_set_connectmode(::blox_test::DS2408::PinConnectMode value);
  public:

  // uint32 oneWireBusId = 10 [(.nanopb) = {
  void clear_onewirebusid();
  uint32_t onewirebusid() const;
  void set_onewirebusid(uint32_t value);
  private:
  uint32_t _internal_onewirebusid() const;
  void _internal_set_onewirebusid(uint32_t value);
  public:

  // bool connected = 6 [(.brewblox.field) = {
  void clear_connected();
  bool connected() const;
  void set_connected(bool value);
  private:
  bool _internal_connected() const;
  void _internal_set_connected(bool value);
  public:

  // bool pins = 90 [(.nanopb) = {
  void clear_pins();
  bool pins() const;
  void set_pins(bool value);
  private:
  bool _internal_pins() const;
  void _internal_set_pins(bool value);
  public:

  // @@protoc_insertion_point(class_scope:blox_test.DS2408.Block)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::IoArray::IoChannel > channels_;
  uint64_t address_;
  int connectmode_;
  uint32_t onewirebusid_;
  bool connected_;
  bool pins_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_DS2408_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Block

// fixed64 address = 1 [(.brewblox.field) = {
inline void Block::clear_address() {
  address_ = uint64_t{0u};
}
inline uint64_t Block::_internal_address() const {
  return address_;
}
inline uint64_t Block::address() const {
  // @@protoc_insertion_point(field_get:blox_test.DS2408.Block.address)
  return _internal_address();
}
inline void Block::_internal_set_address(uint64_t value) {
  
  address_ = value;
}
inline void Block::set_address(uint64_t value) {
  _internal_set_address(value);
  // @@protoc_insertion_point(field_set:blox_test.DS2408.Block.address)
}

// bool connected = 6 [(.brewblox.field) = {
inline void Block::clear_connected() {
  connected_ = false;
}
inline bool Block::_internal_connected() const {
  return connected_;
}
inline bool Block::connected() const {
  // @@protoc_insertion_point(field_get:blox_test.DS2408.Block.connected)
  return _internal_connected();
}
inline void Block::_internal_set_connected(bool value) {
  
  connected_ = value;
}
inline void Block::set_connected(bool value) {
  _internal_set_connected(value);
  // @@protoc_insertion_point(field_set:blox_test.DS2408.Block.connected)
}

// .blox_test.DS2408.PinConnectMode connectMode = 9;
inline void Block::clear_connectmode() {
  connectmode_ = 0;
}
inline ::blox_test::DS2408::PinConnectMode Block::_internal_connectmode() const {
  return static_cast< ::blox_test::DS2408::PinConnectMode >(connectmode_);
}
inline ::blox_test::DS2408::PinConnectMode Block::connectmode() const {
  // @@protoc_insertion_point(field_get:blox_test.DS2408.Block.connectMode)
  return _internal_connectmode();
}
inline void Block::_internal_set_connectmode(::blox_test::DS2408::PinConnectMode value) {
  
  connectmode_ = value;
}
inline void Block::set_connectmode(::blox_test::DS2408::PinConnectMode value) {
  _internal_set_connectmode(value);
  // @@protoc_insertion_point(field_set:blox_test.DS2408.Block.connectMode)
}

// uint32 oneWireBusId = 10 [(.nanopb) = {
inline void Block::clear_onewirebusid() {
  onewirebusid_ = 0u;
}
inline uint32_t Block::_internal_onewirebusid() const {
  return onewirebusid_;
}
inline uint32_t Block::onewirebusid() const {
  // @@protoc_insertion_point(field_get:blox_test.DS2408.Block.oneWireBusId)
  return _internal_onewirebusid();
}
inline void Block::_internal_set_onewirebusid(uint32_t value) {
  
  onewirebusid_ = value;
}
inline void Block::set_onewirebusid(uint32_t value) {
  _internal_set_onewirebusid(value);
  // @@protoc_insertion_point(field_set:blox_test.DS2408.Block.oneWireBusId)
}

// repeated .blox_test.IoArray.IoChannel channels = 11 [(.nanopb) = {
inline int Block::_internal_channels_size() const {
  return channels_.size();
}
inline int Block::channels_size() const {
  return _internal_channels_size();
}
inline ::blox_test::IoArray::IoChannel* Block::mutable_channels(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.DS2408.Block.channels)
  return channels_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::IoArray::IoChannel >*
Block::mutable_channels() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.DS2408.Block.channels)
  return &channels_;
}
inline const ::blox_test::IoArray::IoChannel& Block::_internal_channels(int index) const {
  return channels_.Get(index);
}
inline const ::blox_test::IoArray::IoChannel& Block::channels(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.DS2408.Block.channels)
  return _internal_channels(index);
}
inline ::blox_test::IoArray::IoChannel* Block::_internal_add_channels() {
  return channels_.Add();
}
inline ::blox_test::IoArray::IoChannel* Block::add_channels() {
  ::blox_test::IoArray::IoChannel* _add = _internal_add_channels();
  // @@protoc_insertion_point(field_add:blox_test.DS2408.Block.channels)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::IoArray::IoChannel >&
Block::channels() const {
  // @@protoc_insertion_point(field_list:blox_test.DS2408.Block.channels)
  return channels_;
}

// bool pins = 90 [(.nanopb) = {
inline void Block::clear_pins() {
  pins_ = false;
}
inline bool Block::_internal_pins() const {
  return pins_;
}
inline bool Block::pins() const {
  // @@protoc_insertion_point(field_get:blox_test.DS2408.Block.pins)
  return _internal_pins();
}
inline void Block::_internal_set_pins(bool value) {
  
  pins_ = value;
}
inline void Block::set_pins(bool value) {
  _internal_set_pins(value);
  // @@protoc_insertion_point(field_set:blox_test.DS2408.Block.pins)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace DS2408
}  // namespace blox_test

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::blox_test::DS2408::ChannelId> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::DS2408::ChannelId>() {
  return ::blox_test::DS2408::ChannelId_descriptor();
}
template <> struct is_proto_enum< ::blox_test::DS2408::PinConnectMode> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::DS2408::PinConnectMode>() {
  return ::blox_test::DS2408::PinConnectMode_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_DS2408_5ftest_2eproto
