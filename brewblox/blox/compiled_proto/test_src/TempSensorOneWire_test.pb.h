// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TempSensorOneWire_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_TempSensorOneWire_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_TempSensorOneWire_5ftest_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_TempSensorOneWire_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_TempSensorOneWire_5ftest_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TempSensorOneWire_5ftest_2eproto;
namespace blox {
class TempSensorOneWire;
struct TempSensorOneWireDefaultTypeInternal;
extern TempSensorOneWireDefaultTypeInternal _TempSensorOneWire_default_instance_;
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> ::blox::TempSensorOneWire* Arena::CreateMaybeMessage<::blox::TempSensorOneWire>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox {

// ===================================================================

class TempSensorOneWire final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox.TempSensorOneWire) */ {
 public:
  inline TempSensorOneWire() : TempSensorOneWire(nullptr) {}
  ~TempSensorOneWire() override;
  explicit constexpr TempSensorOneWire(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TempSensorOneWire(const TempSensorOneWire& from);
  TempSensorOneWire(TempSensorOneWire&& from) noexcept
    : TempSensorOneWire() {
    *this = ::std::move(from);
  }

  inline TempSensorOneWire& operator=(const TempSensorOneWire& from) {
    CopyFrom(from);
    return *this;
  }
  inline TempSensorOneWire& operator=(TempSensorOneWire&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
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
  static const TempSensorOneWire& default_instance() {
    return *internal_default_instance();
  }
  static inline const TempSensorOneWire* internal_default_instance() {
    return reinterpret_cast<const TempSensorOneWire*>(
               &_TempSensorOneWire_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TempSensorOneWire& a, TempSensorOneWire& b) {
    a.Swap(&b);
  }
  inline void Swap(TempSensorOneWire* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TempSensorOneWire* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline TempSensorOneWire* New() const final {
    return new TempSensorOneWire();
  }

  TempSensorOneWire* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<TempSensorOneWire>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TempSensorOneWire& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const TempSensorOneWire& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TempSensorOneWire* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox.TempSensorOneWire";
  }
  protected:
  explicit TempSensorOneWire(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kStrippedFieldsFieldNumber = 99,
    kValueFieldNumber = 1,
    kOffsetFieldNumber = 3,
    kAddressFieldNumber = 4,
    kOneWireBusIdFieldNumber = 5,
  };
  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  int strippedfields_size() const;
  private:
  int _internal_strippedfields_size() const;
  public:
  void clear_strippedfields();
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_strippedfields(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
      _internal_strippedfields() const;
  void _internal_add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
      _internal_mutable_strippedfields();
  public:
  ::PROTOBUF_NAMESPACE_ID::uint32 strippedfields(int index) const;
  void set_strippedfields(int index, ::PROTOBUF_NAMESPACE_ID::uint32 value);
  void add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
      strippedfields() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
      mutable_strippedfields();

  // sint32 value = 1 [(.nanopb_test) = {
  void clear_value();
  ::PROTOBUF_NAMESPACE_ID::int32 value() const;
  void set_value(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_value() const;
  void _internal_set_value(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // sint32 offset = 3 [(.nanopb_test) = {
  void clear_offset();
  ::PROTOBUF_NAMESPACE_ID::int32 offset() const;
  void set_offset(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_offset() const;
  void _internal_set_offset(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // fixed64 address = 4 [(.brewblox_test) = {
  void clear_address();
  ::PROTOBUF_NAMESPACE_ID::uint64 address() const;
  void set_address(::PROTOBUF_NAMESPACE_ID::uint64 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint64 _internal_address() const;
  void _internal_set_address(::PROTOBUF_NAMESPACE_ID::uint64 value);
  public:

  // uint32 oneWireBusId = 5 [(.nanopb_test) = {
  void clear_onewirebusid();
  ::PROTOBUF_NAMESPACE_ID::uint32 onewirebusid() const;
  void set_onewirebusid(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_onewirebusid() const;
  void _internal_set_onewirebusid(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:blox.TempSensorOneWire)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 > strippedfields_;
  mutable std::atomic<int> _strippedfields_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 value_;
  ::PROTOBUF_NAMESPACE_ID::int32 offset_;
  ::PROTOBUF_NAMESPACE_ID::uint64 address_;
  ::PROTOBUF_NAMESPACE_ID::uint32 onewirebusid_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_TempSensorOneWire_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TempSensorOneWire

// sint32 value = 1 [(.nanopb_test) = {
inline void TempSensorOneWire::clear_value() {
  value_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorOneWire::_internal_value() const {
  return value_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorOneWire::value() const {
  // @@protoc_insertion_point(field_get:blox.TempSensorOneWire.value)
  return _internal_value();
}
inline void TempSensorOneWire::_internal_set_value(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  value_ = value;
}
inline void TempSensorOneWire::set_value(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:blox.TempSensorOneWire.value)
}

// sint32 offset = 3 [(.nanopb_test) = {
inline void TempSensorOneWire::clear_offset() {
  offset_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorOneWire::_internal_offset() const {
  return offset_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorOneWire::offset() const {
  // @@protoc_insertion_point(field_get:blox.TempSensorOneWire.offset)
  return _internal_offset();
}
inline void TempSensorOneWire::_internal_set_offset(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  offset_ = value;
}
inline void TempSensorOneWire::set_offset(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_offset(value);
  // @@protoc_insertion_point(field_set:blox.TempSensorOneWire.offset)
}

// fixed64 address = 4 [(.brewblox_test) = {
inline void TempSensorOneWire::clear_address() {
  address_ = uint64_t{0u};
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 TempSensorOneWire::_internal_address() const {
  return address_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint64 TempSensorOneWire::address() const {
  // @@protoc_insertion_point(field_get:blox.TempSensorOneWire.address)
  return _internal_address();
}
inline void TempSensorOneWire::_internal_set_address(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  
  address_ = value;
}
inline void TempSensorOneWire::set_address(::PROTOBUF_NAMESPACE_ID::uint64 value) {
  _internal_set_address(value);
  // @@protoc_insertion_point(field_set:blox.TempSensorOneWire.address)
}

// uint32 oneWireBusId = 5 [(.nanopb_test) = {
inline void TempSensorOneWire::clear_onewirebusid() {
  onewirebusid_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 TempSensorOneWire::_internal_onewirebusid() const {
  return onewirebusid_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 TempSensorOneWire::onewirebusid() const {
  // @@protoc_insertion_point(field_get:blox.TempSensorOneWire.oneWireBusId)
  return _internal_onewirebusid();
}
inline void TempSensorOneWire::_internal_set_onewirebusid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  onewirebusid_ = value;
}
inline void TempSensorOneWire::set_onewirebusid(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_onewirebusid(value);
  // @@protoc_insertion_point(field_set:blox.TempSensorOneWire.oneWireBusId)
}

// repeated uint32 strippedFields = 99 [(.nanopb_test) = {
inline int TempSensorOneWire::_internal_strippedfields_size() const {
  return strippedfields_.size();
}
inline int TempSensorOneWire::strippedfields_size() const {
  return _internal_strippedfields_size();
}
inline void TempSensorOneWire::clear_strippedfields() {
  strippedfields_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 TempSensorOneWire::_internal_strippedfields(int index) const {
  return strippedfields_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 TempSensorOneWire::strippedfields(int index) const {
  // @@protoc_insertion_point(field_get:blox.TempSensorOneWire.strippedFields)
  return _internal_strippedfields(index);
}
inline void TempSensorOneWire::set_strippedfields(int index, ::PROTOBUF_NAMESPACE_ID::uint32 value) {
  strippedfields_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.TempSensorOneWire.strippedFields)
}
inline void TempSensorOneWire::_internal_add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  strippedfields_.Add(value);
}
inline void TempSensorOneWire::add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_add_strippedfields(value);
  // @@protoc_insertion_point(field_add:blox.TempSensorOneWire.strippedFields)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
TempSensorOneWire::_internal_strippedfields() const {
  return strippedfields_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
TempSensorOneWire::strippedfields() const {
  // @@protoc_insertion_point(field_list:blox.TempSensorOneWire.strippedFields)
  return _internal_strippedfields();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
TempSensorOneWire::_internal_mutable_strippedfields() {
  return &strippedfields_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
TempSensorOneWire::mutable_strippedfields() {
  // @@protoc_insertion_point(field_mutable_list:blox.TempSensorOneWire.strippedFields)
  return _internal_mutable_strippedfields();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_TempSensorOneWire_5ftest_2eproto
