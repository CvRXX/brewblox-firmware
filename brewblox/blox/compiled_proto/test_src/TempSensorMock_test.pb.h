// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: TempSensorMock_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_TempSensorMock_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_TempSensorMock_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_TempSensorMock_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_TempSensorMock_5ftest_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_TempSensorMock_5ftest_2eproto;
namespace blox {
class Fluctuation;
struct FluctuationDefaultTypeInternal;
extern FluctuationDefaultTypeInternal _Fluctuation_default_instance_;
class TempSensorMock;
struct TempSensorMockDefaultTypeInternal;
extern TempSensorMockDefaultTypeInternal _TempSensorMock_default_instance_;
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> ::blox::Fluctuation* Arena::CreateMaybeMessage<::blox::Fluctuation>(Arena*);
template<> ::blox::TempSensorMock* Arena::CreateMaybeMessage<::blox::TempSensorMock>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox {

// ===================================================================

class Fluctuation final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox.Fluctuation) */ {
 public:
  inline Fluctuation() : Fluctuation(nullptr) {}
  ~Fluctuation() override;
  explicit constexpr Fluctuation(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Fluctuation(const Fluctuation& from);
  Fluctuation(Fluctuation&& from) noexcept
    : Fluctuation() {
    *this = ::std::move(from);
  }

  inline Fluctuation& operator=(const Fluctuation& from) {
    CopyFrom(from);
    return *this;
  }
  inline Fluctuation& operator=(Fluctuation&& from) noexcept {
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
  static const Fluctuation& default_instance() {
    return *internal_default_instance();
  }
  static inline const Fluctuation* internal_default_instance() {
    return reinterpret_cast<const Fluctuation*>(
               &_Fluctuation_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Fluctuation& a, Fluctuation& b) {
    a.Swap(&b);
  }
  inline void Swap(Fluctuation* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Fluctuation* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Fluctuation* New() const final {
    return new Fluctuation();
  }

  Fluctuation* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Fluctuation>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Fluctuation& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Fluctuation& from);
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
  void InternalSwap(Fluctuation* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox.Fluctuation";
  }
  protected:
  explicit Fluctuation(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kAmplitudeFieldNumber = 1,
    kPeriodFieldNumber = 2,
  };
  // sint32 amplitude = 1 [(.nanopb_test) = {
  void clear_amplitude();
  ::PROTOBUF_NAMESPACE_ID::int32 amplitude() const;
  void set_amplitude(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_amplitude() const;
  void _internal_set_amplitude(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // uint32 period = 2 [(.nanopb_test) = {
  void clear_period();
  ::PROTOBUF_NAMESPACE_ID::uint32 period() const;
  void set_period(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_period() const;
  void _internal_set_period(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:blox.Fluctuation)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::int32 amplitude_;
  ::PROTOBUF_NAMESPACE_ID::uint32 period_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_TempSensorMock_5ftest_2eproto;
};
// -------------------------------------------------------------------

class TempSensorMock final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox.TempSensorMock) */ {
 public:
  inline TempSensorMock() : TempSensorMock(nullptr) {}
  ~TempSensorMock() override;
  explicit constexpr TempSensorMock(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TempSensorMock(const TempSensorMock& from);
  TempSensorMock(TempSensorMock&& from) noexcept
    : TempSensorMock() {
    *this = ::std::move(from);
  }

  inline TempSensorMock& operator=(const TempSensorMock& from) {
    CopyFrom(from);
    return *this;
  }
  inline TempSensorMock& operator=(TempSensorMock&& from) noexcept {
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
  static const TempSensorMock& default_instance() {
    return *internal_default_instance();
  }
  static inline const TempSensorMock* internal_default_instance() {
    return reinterpret_cast<const TempSensorMock*>(
               &_TempSensorMock_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(TempSensorMock& a, TempSensorMock& b) {
    a.Swap(&b);
  }
  inline void Swap(TempSensorMock* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TempSensorMock* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline TempSensorMock* New() const final {
    return new TempSensorMock();
  }

  TempSensorMock* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<TempSensorMock>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TempSensorMock& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const TempSensorMock& from);
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
  void InternalSwap(TempSensorMock* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox.TempSensorMock";
  }
  protected:
  explicit TempSensorMock(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kFluctuationsFieldNumber = 5,
    kStrippedFieldsFieldNumber = 99,
    kValueFieldNumber = 1,
    kConnectedFieldNumber = 3,
    kSettingFieldNumber = 4,
  };
  // repeated .blox.Fluctuation fluctuations = 5;
  int fluctuations_size() const;
  private:
  int _internal_fluctuations_size() const;
  public:
  void clear_fluctuations();
  ::blox::Fluctuation* mutable_fluctuations(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox::Fluctuation >*
      mutable_fluctuations();
  private:
  const ::blox::Fluctuation& _internal_fluctuations(int index) const;
  ::blox::Fluctuation* _internal_add_fluctuations();
  public:
  const ::blox::Fluctuation& fluctuations(int index) const;
  ::blox::Fluctuation* add_fluctuations();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox::Fluctuation >&
      fluctuations() const;

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

  // bool connected = 3 [(.brewblox_test) = {
  void clear_connected();
  bool connected() const;
  void set_connected(bool value);
  private:
  bool _internal_connected() const;
  void _internal_set_connected(bool value);
  public:

  // sint32 setting = 4 [(.nanopb_test) = {
  void clear_setting();
  ::PROTOBUF_NAMESPACE_ID::int32 setting() const;
  void set_setting(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_setting() const;
  void _internal_set_setting(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:blox.TempSensorMock)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox::Fluctuation > fluctuations_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 > strippedfields_;
  mutable std::atomic<int> _strippedfields_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 value_;
  bool connected_;
  ::PROTOBUF_NAMESPACE_ID::int32 setting_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_TempSensorMock_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Fluctuation

// sint32 amplitude = 1 [(.nanopb_test) = {
inline void Fluctuation::clear_amplitude() {
  amplitude_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Fluctuation::_internal_amplitude() const {
  return amplitude_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Fluctuation::amplitude() const {
  // @@protoc_insertion_point(field_get:blox.Fluctuation.amplitude)
  return _internal_amplitude();
}
inline void Fluctuation::_internal_set_amplitude(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  amplitude_ = value;
}
inline void Fluctuation::set_amplitude(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_amplitude(value);
  // @@protoc_insertion_point(field_set:blox.Fluctuation.amplitude)
}

// uint32 period = 2 [(.nanopb_test) = {
inline void Fluctuation::clear_period() {
  period_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Fluctuation::_internal_period() const {
  return period_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Fluctuation::period() const {
  // @@protoc_insertion_point(field_get:blox.Fluctuation.period)
  return _internal_period();
}
inline void Fluctuation::_internal_set_period(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  period_ = value;
}
inline void Fluctuation::set_period(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_period(value);
  // @@protoc_insertion_point(field_set:blox.Fluctuation.period)
}

// -------------------------------------------------------------------

// TempSensorMock

// sint32 value = 1 [(.nanopb_test) = {
inline void TempSensorMock::clear_value() {
  value_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorMock::_internal_value() const {
  return value_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorMock::value() const {
  // @@protoc_insertion_point(field_get:blox.TempSensorMock.value)
  return _internal_value();
}
inline void TempSensorMock::_internal_set_value(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  value_ = value;
}
inline void TempSensorMock::set_value(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_value(value);
  // @@protoc_insertion_point(field_set:blox.TempSensorMock.value)
}

// bool connected = 3 [(.brewblox_test) = {
inline void TempSensorMock::clear_connected() {
  connected_ = false;
}
inline bool TempSensorMock::_internal_connected() const {
  return connected_;
}
inline bool TempSensorMock::connected() const {
  // @@protoc_insertion_point(field_get:blox.TempSensorMock.connected)
  return _internal_connected();
}
inline void TempSensorMock::_internal_set_connected(bool value) {
  
  connected_ = value;
}
inline void TempSensorMock::set_connected(bool value) {
  _internal_set_connected(value);
  // @@protoc_insertion_point(field_set:blox.TempSensorMock.connected)
}

// sint32 setting = 4 [(.nanopb_test) = {
inline void TempSensorMock::clear_setting() {
  setting_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorMock::_internal_setting() const {
  return setting_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 TempSensorMock::setting() const {
  // @@protoc_insertion_point(field_get:blox.TempSensorMock.setting)
  return _internal_setting();
}
inline void TempSensorMock::_internal_set_setting(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  setting_ = value;
}
inline void TempSensorMock::set_setting(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_setting(value);
  // @@protoc_insertion_point(field_set:blox.TempSensorMock.setting)
}

// repeated .blox.Fluctuation fluctuations = 5;
inline int TempSensorMock::_internal_fluctuations_size() const {
  return fluctuations_.size();
}
inline int TempSensorMock::fluctuations_size() const {
  return _internal_fluctuations_size();
}
inline void TempSensorMock::clear_fluctuations() {
  fluctuations_.Clear();
}
inline ::blox::Fluctuation* TempSensorMock::mutable_fluctuations(int index) {
  // @@protoc_insertion_point(field_mutable:blox.TempSensorMock.fluctuations)
  return fluctuations_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox::Fluctuation >*
TempSensorMock::mutable_fluctuations() {
  // @@protoc_insertion_point(field_mutable_list:blox.TempSensorMock.fluctuations)
  return &fluctuations_;
}
inline const ::blox::Fluctuation& TempSensorMock::_internal_fluctuations(int index) const {
  return fluctuations_.Get(index);
}
inline const ::blox::Fluctuation& TempSensorMock::fluctuations(int index) const {
  // @@protoc_insertion_point(field_get:blox.TempSensorMock.fluctuations)
  return _internal_fluctuations(index);
}
inline ::blox::Fluctuation* TempSensorMock::_internal_add_fluctuations() {
  return fluctuations_.Add();
}
inline ::blox::Fluctuation* TempSensorMock::add_fluctuations() {
  ::blox::Fluctuation* _add = _internal_add_fluctuations();
  // @@protoc_insertion_point(field_add:blox.TempSensorMock.fluctuations)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox::Fluctuation >&
TempSensorMock::fluctuations() const {
  // @@protoc_insertion_point(field_list:blox.TempSensorMock.fluctuations)
  return fluctuations_;
}

// repeated uint32 strippedFields = 99 [(.nanopb_test) = {
inline int TempSensorMock::_internal_strippedfields_size() const {
  return strippedfields_.size();
}
inline int TempSensorMock::strippedfields_size() const {
  return _internal_strippedfields_size();
}
inline void TempSensorMock::clear_strippedfields() {
  strippedfields_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 TempSensorMock::_internal_strippedfields(int index) const {
  return strippedfields_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 TempSensorMock::strippedfields(int index) const {
  // @@protoc_insertion_point(field_get:blox.TempSensorMock.strippedFields)
  return _internal_strippedfields(index);
}
inline void TempSensorMock::set_strippedfields(int index, ::PROTOBUF_NAMESPACE_ID::uint32 value) {
  strippedfields_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.TempSensorMock.strippedFields)
}
inline void TempSensorMock::_internal_add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  strippedfields_.Add(value);
}
inline void TempSensorMock::add_strippedfields(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_add_strippedfields(value);
  // @@protoc_insertion_point(field_add:blox.TempSensorMock.strippedFields)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
TempSensorMock::_internal_strippedfields() const {
  return strippedfields_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >&
TempSensorMock::strippedfields() const {
  // @@protoc_insertion_point(field_list:blox.TempSensorMock.strippedFields)
  return _internal_strippedfields();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
TempSensorMock::_internal_mutable_strippedfields() {
  return &strippedfields_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::uint32 >*
TempSensorMock::mutable_strippedfields() {
  // @@protoc_insertion_point(field_mutable_list:blox.TempSensorMock.strippedFields)
  return _internal_mutable_strippedfields();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_TempSensorMock_5ftest_2eproto
