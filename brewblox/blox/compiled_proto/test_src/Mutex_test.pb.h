// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Mutex_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Mutex_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Mutex_5ftest_2eproto

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
#define PROTOBUF_INTERNAL_EXPORT_Mutex_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Mutex_5ftest_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Mutex_5ftest_2eproto;
namespace blox {
class Mutex;
struct MutexDefaultTypeInternal;
extern MutexDefaultTypeInternal _Mutex_default_instance_;
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> ::blox::Mutex* Arena::CreateMaybeMessage<::blox::Mutex>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox {

// ===================================================================

class Mutex final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox.Mutex) */ {
 public:
  inline Mutex() : Mutex(nullptr) {}
  ~Mutex() override;
  explicit constexpr Mutex(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Mutex(const Mutex& from);
  Mutex(Mutex&& from) noexcept
    : Mutex() {
    *this = ::std::move(from);
  }

  inline Mutex& operator=(const Mutex& from) {
    CopyFrom(from);
    return *this;
  }
  inline Mutex& operator=(Mutex&& from) noexcept {
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
  static const Mutex& default_instance() {
    return *internal_default_instance();
  }
  static inline const Mutex* internal_default_instance() {
    return reinterpret_cast<const Mutex*>(
               &_Mutex_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Mutex& a, Mutex& b) {
    a.Swap(&b);
  }
  inline void Swap(Mutex* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Mutex* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Mutex* New() const final {
    return new Mutex();
  }

  Mutex* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Mutex>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Mutex& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Mutex& from);
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
  void InternalSwap(Mutex* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox.Mutex";
  }
  protected:
  explicit Mutex(::PROTOBUF_NAMESPACE_ID::Arena* arena,
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
    kDifferentActuatorWaitFieldNumber = 1,
    kWaitRemainingFieldNumber = 2,
  };
  // uint32 differentActuatorWait = 1 [(.brewblox_test) = {
  void clear_differentactuatorwait();
  ::PROTOBUF_NAMESPACE_ID::uint32 differentactuatorwait() const;
  void set_differentactuatorwait(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_differentactuatorwait() const;
  void _internal_set_differentactuatorwait(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 waitRemaining = 2 [(.nanopb_test) = {
  void clear_waitremaining();
  ::PROTOBUF_NAMESPACE_ID::uint32 waitremaining() const;
  void set_waitremaining(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_waitremaining() const;
  void _internal_set_waitremaining(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:blox.Mutex)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::uint32 differentactuatorwait_;
  ::PROTOBUF_NAMESPACE_ID::uint32 waitremaining_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_Mutex_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Mutex

// uint32 differentActuatorWait = 1 [(.brewblox_test) = {
inline void Mutex::clear_differentactuatorwait() {
  differentactuatorwait_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Mutex::_internal_differentactuatorwait() const {
  return differentactuatorwait_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Mutex::differentactuatorwait() const {
  // @@protoc_insertion_point(field_get:blox.Mutex.differentActuatorWait)
  return _internal_differentactuatorwait();
}
inline void Mutex::_internal_set_differentactuatorwait(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  differentactuatorwait_ = value;
}
inline void Mutex::set_differentactuatorwait(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_differentactuatorwait(value);
  // @@protoc_insertion_point(field_set:blox.Mutex.differentActuatorWait)
}

// uint32 waitRemaining = 2 [(.nanopb_test) = {
inline void Mutex::clear_waitremaining() {
  waitremaining_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Mutex::_internal_waitremaining() const {
  return waitremaining_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Mutex::waitremaining() const {
  // @@protoc_insertion_point(field_get:blox.Mutex.waitRemaining)
  return _internal_waitremaining();
}
inline void Mutex::_internal_set_waitremaining(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  waitremaining_ = value;
}
inline void Mutex::set_waitremaining(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_waitremaining(value);
  // @@protoc_insertion_point(field_set:blox.Mutex.waitRemaining)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Mutex_5ftest_2eproto
