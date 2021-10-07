// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: AnalogConstraints_test.proto

#ifndef PROTOBUF_INCLUDED_AnalogConstraints_5ftest_2eproto
#define PROTOBUF_INCLUDED_AnalogConstraints_5ftest_2eproto

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3006001
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_AnalogConstraints_5ftest_2eproto 

namespace protobuf_AnalogConstraints_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[3];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_AnalogConstraints_5ftest_2eproto
namespace blox {
class AnalogConstraint;
class AnalogConstraintDefaultTypeInternal;
extern AnalogConstraintDefaultTypeInternal _AnalogConstraint_default_instance_;
class AnalogConstraints;
class AnalogConstraintsDefaultTypeInternal;
extern AnalogConstraintsDefaultTypeInternal _AnalogConstraints_default_instance_;
class Balanced;
class BalancedDefaultTypeInternal;
extern BalancedDefaultTypeInternal _Balanced_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::AnalogConstraint* Arena::CreateMaybeMessage<::blox::AnalogConstraint>(Arena*);
template<> ::blox::AnalogConstraints* Arena::CreateMaybeMessage<::blox::AnalogConstraints>(Arena*);
template<> ::blox::Balanced* Arena::CreateMaybeMessage<::blox::Balanced>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

// ===================================================================

class Balanced : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Balanced) */ {
 public:
  Balanced();
  virtual ~Balanced();

  Balanced(const Balanced& from);

  inline Balanced& operator=(const Balanced& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Balanced(Balanced&& from) noexcept
    : Balanced() {
    *this = ::std::move(from);
  }

  inline Balanced& operator=(Balanced&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Balanced& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Balanced* internal_default_instance() {
    return reinterpret_cast<const Balanced*>(
               &_Balanced_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Balanced* other);
  friend void swap(Balanced& a, Balanced& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Balanced* New() const final {
    return CreateMaybeMessage<Balanced>(NULL);
  }

  Balanced* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Balanced>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Balanced& from);
  void MergeFrom(const Balanced& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Balanced* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // uint32 balancerId = 1 [(.nanopb_test) = {
  void clear_balancerid();
  static const int kBalancerIdFieldNumber = 1;
  ::google::protobuf::uint32 balancerid() const;
  void set_balancerid(::google::protobuf::uint32 value);

  // uint32 granted = 2 [(.brewblox_test) = {
  void clear_granted();
  static const int kGrantedFieldNumber = 2;
  ::google::protobuf::uint32 granted() const;
  void set_granted(::google::protobuf::uint32 value);

  // uint32 id = 3 [(.nanopb_test) = {
  void clear_id();
  static const int kIdFieldNumber = 3;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox.Balanced)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::uint32 balancerid_;
  ::google::protobuf::uint32 granted_;
  ::google::protobuf::uint32 id_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_AnalogConstraints_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class AnalogConstraint : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.AnalogConstraint) */ {
 public:
  AnalogConstraint();
  virtual ~AnalogConstraint();

  AnalogConstraint(const AnalogConstraint& from);

  inline AnalogConstraint& operator=(const AnalogConstraint& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AnalogConstraint(AnalogConstraint&& from) noexcept
    : AnalogConstraint() {
    *this = ::std::move(from);
  }

  inline AnalogConstraint& operator=(AnalogConstraint&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AnalogConstraint& default_instance();

  enum ConstraintCase {
    kMin = 1,
    kMax = 2,
    kBalanced = 3,
    CONSTRAINT_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AnalogConstraint* internal_default_instance() {
    return reinterpret_cast<const AnalogConstraint*>(
               &_AnalogConstraint_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(AnalogConstraint* other);
  friend void swap(AnalogConstraint& a, AnalogConstraint& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AnalogConstraint* New() const final {
    return CreateMaybeMessage<AnalogConstraint>(NULL);
  }

  AnalogConstraint* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<AnalogConstraint>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const AnalogConstraint& from);
  void MergeFrom(const AnalogConstraint& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AnalogConstraint* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bool limiting = 100 [(.brewblox_test) = {
  void clear_limiting();
  static const int kLimitingFieldNumber = 100;
  bool limiting() const;
  void set_limiting(bool value);

  // sint32 min = 1 [(.nanopb_test) = {
  private:
  bool has_min() const;
  public:
  void clear_min();
  static const int kMinFieldNumber = 1;
  ::google::protobuf::int32 min() const;
  void set_min(::google::protobuf::int32 value);

  // sint32 max = 2 [(.nanopb_test) = {
  private:
  bool has_max() const;
  public:
  void clear_max();
  static const int kMaxFieldNumber = 2;
  ::google::protobuf::int32 max() const;
  void set_max(::google::protobuf::int32 value);

  // .blox.Balanced balanced = 3;
  bool has_balanced() const;
  void clear_balanced();
  static const int kBalancedFieldNumber = 3;
  private:
  const ::blox::Balanced& _internal_balanced() const;
  public:
  const ::blox::Balanced& balanced() const;
  ::blox::Balanced* release_balanced();
  ::blox::Balanced* mutable_balanced();
  void set_allocated_balanced(::blox::Balanced* balanced);

  void clear_constraint();
  ConstraintCase constraint_case() const;
  // @@protoc_insertion_point(class_scope:blox.AnalogConstraint)
 private:
  void set_has_min();
  void set_has_max();
  void set_has_balanced();

  inline bool has_constraint() const;
  inline void clear_has_constraint();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool limiting_;
  union ConstraintUnion {
    ConstraintUnion() {}
    ::google::protobuf::int32 min_;
    ::google::protobuf::int32 max_;
    ::blox::Balanced* balanced_;
  } constraint_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::uint32 _oneof_case_[1];

  friend struct ::protobuf_AnalogConstraints_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class AnalogConstraints : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.AnalogConstraints) */ {
 public:
  AnalogConstraints();
  virtual ~AnalogConstraints();

  AnalogConstraints(const AnalogConstraints& from);

  inline AnalogConstraints& operator=(const AnalogConstraints& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AnalogConstraints(AnalogConstraints&& from) noexcept
    : AnalogConstraints() {
    *this = ::std::move(from);
  }

  inline AnalogConstraints& operator=(AnalogConstraints&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AnalogConstraints& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AnalogConstraints* internal_default_instance() {
    return reinterpret_cast<const AnalogConstraints*>(
               &_AnalogConstraints_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(AnalogConstraints* other);
  friend void swap(AnalogConstraints& a, AnalogConstraints& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AnalogConstraints* New() const final {
    return CreateMaybeMessage<AnalogConstraints>(NULL);
  }

  AnalogConstraints* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<AnalogConstraints>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const AnalogConstraints& from);
  void MergeFrom(const AnalogConstraints& from);
  void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(AnalogConstraints* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .blox.AnalogConstraint constraints = 1 [(.nanopb_test) = {
  int constraints_size() const;
  void clear_constraints();
  static const int kConstraintsFieldNumber = 1;
  ::blox::AnalogConstraint* mutable_constraints(int index);
  ::google::protobuf::RepeatedPtrField< ::blox::AnalogConstraint >*
      mutable_constraints();
  const ::blox::AnalogConstraint& constraints(int index) const;
  ::blox::AnalogConstraint* add_constraints();
  const ::google::protobuf::RepeatedPtrField< ::blox::AnalogConstraint >&
      constraints() const;

  // @@protoc_insertion_point(class_scope:blox.AnalogConstraints)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox::AnalogConstraint > constraints_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_AnalogConstraints_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Balanced

// uint32 balancerId = 1 [(.nanopb_test) = {
inline void Balanced::clear_balancerid() {
  balancerid_ = 0u;
}
inline ::google::protobuf::uint32 Balanced::balancerid() const {
  // @@protoc_insertion_point(field_get:blox.Balanced.balancerId)
  return balancerid_;
}
inline void Balanced::set_balancerid(::google::protobuf::uint32 value) {
  
  balancerid_ = value;
  // @@protoc_insertion_point(field_set:blox.Balanced.balancerId)
}

// uint32 granted = 2 [(.brewblox_test) = {
inline void Balanced::clear_granted() {
  granted_ = 0u;
}
inline ::google::protobuf::uint32 Balanced::granted() const {
  // @@protoc_insertion_point(field_get:blox.Balanced.granted)
  return granted_;
}
inline void Balanced::set_granted(::google::protobuf::uint32 value) {
  
  granted_ = value;
  // @@protoc_insertion_point(field_set:blox.Balanced.granted)
}

// uint32 id = 3 [(.nanopb_test) = {
inline void Balanced::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 Balanced::id() const {
  // @@protoc_insertion_point(field_get:blox.Balanced.id)
  return id_;
}
inline void Balanced::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox.Balanced.id)
}

// -------------------------------------------------------------------

// AnalogConstraint

// sint32 min = 1 [(.nanopb_test) = {
inline bool AnalogConstraint::has_min() const {
  return constraint_case() == kMin;
}
inline void AnalogConstraint::set_has_min() {
  _oneof_case_[0] = kMin;
}
inline void AnalogConstraint::clear_min() {
  if (has_min()) {
    constraint_.min_ = 0;
    clear_has_constraint();
  }
}
inline ::google::protobuf::int32 AnalogConstraint::min() const {
  // @@protoc_insertion_point(field_get:blox.AnalogConstraint.min)
  if (has_min()) {
    return constraint_.min_;
  }
  return 0;
}
inline void AnalogConstraint::set_min(::google::protobuf::int32 value) {
  if (!has_min()) {
    clear_constraint();
    set_has_min();
  }
  constraint_.min_ = value;
  // @@protoc_insertion_point(field_set:blox.AnalogConstraint.min)
}

// sint32 max = 2 [(.nanopb_test) = {
inline bool AnalogConstraint::has_max() const {
  return constraint_case() == kMax;
}
inline void AnalogConstraint::set_has_max() {
  _oneof_case_[0] = kMax;
}
inline void AnalogConstraint::clear_max() {
  if (has_max()) {
    constraint_.max_ = 0;
    clear_has_constraint();
  }
}
inline ::google::protobuf::int32 AnalogConstraint::max() const {
  // @@protoc_insertion_point(field_get:blox.AnalogConstraint.max)
  if (has_max()) {
    return constraint_.max_;
  }
  return 0;
}
inline void AnalogConstraint::set_max(::google::protobuf::int32 value) {
  if (!has_max()) {
    clear_constraint();
    set_has_max();
  }
  constraint_.max_ = value;
  // @@protoc_insertion_point(field_set:blox.AnalogConstraint.max)
}

// .blox.Balanced balanced = 3;
inline bool AnalogConstraint::has_balanced() const {
  return constraint_case() == kBalanced;
}
inline void AnalogConstraint::set_has_balanced() {
  _oneof_case_[0] = kBalanced;
}
inline void AnalogConstraint::clear_balanced() {
  if (has_balanced()) {
    delete constraint_.balanced_;
    clear_has_constraint();
  }
}
inline const ::blox::Balanced& AnalogConstraint::_internal_balanced() const {
  return *constraint_.balanced_;
}
inline ::blox::Balanced* AnalogConstraint::release_balanced() {
  // @@protoc_insertion_point(field_release:blox.AnalogConstraint.balanced)
  if (has_balanced()) {
    clear_has_constraint();
      ::blox::Balanced* temp = constraint_.balanced_;
    constraint_.balanced_ = NULL;
    return temp;
  } else {
    return NULL;
  }
}
inline const ::blox::Balanced& AnalogConstraint::balanced() const {
  // @@protoc_insertion_point(field_get:blox.AnalogConstraint.balanced)
  return has_balanced()
      ? *constraint_.balanced_
      : *reinterpret_cast< ::blox::Balanced*>(&::blox::_Balanced_default_instance_);
}
inline ::blox::Balanced* AnalogConstraint::mutable_balanced() {
  if (!has_balanced()) {
    clear_constraint();
    set_has_balanced();
    constraint_.balanced_ = CreateMaybeMessage< ::blox::Balanced >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:blox.AnalogConstraint.balanced)
  return constraint_.balanced_;
}

// bool limiting = 100 [(.brewblox_test) = {
inline void AnalogConstraint::clear_limiting() {
  limiting_ = false;
}
inline bool AnalogConstraint::limiting() const {
  // @@protoc_insertion_point(field_get:blox.AnalogConstraint.limiting)
  return limiting_;
}
inline void AnalogConstraint::set_limiting(bool value) {
  
  limiting_ = value;
  // @@protoc_insertion_point(field_set:blox.AnalogConstraint.limiting)
}

inline bool AnalogConstraint::has_constraint() const {
  return constraint_case() != CONSTRAINT_NOT_SET;
}
inline void AnalogConstraint::clear_has_constraint() {
  _oneof_case_[0] = CONSTRAINT_NOT_SET;
}
inline AnalogConstraint::ConstraintCase AnalogConstraint::constraint_case() const {
  return AnalogConstraint::ConstraintCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// AnalogConstraints

// repeated .blox.AnalogConstraint constraints = 1 [(.nanopb_test) = {
inline int AnalogConstraints::constraints_size() const {
  return constraints_.size();
}
inline void AnalogConstraints::clear_constraints() {
  constraints_.Clear();
}
inline ::blox::AnalogConstraint* AnalogConstraints::mutable_constraints(int index) {
  // @@protoc_insertion_point(field_mutable:blox.AnalogConstraints.constraints)
  return constraints_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox::AnalogConstraint >*
AnalogConstraints::mutable_constraints() {
  // @@protoc_insertion_point(field_mutable_list:blox.AnalogConstraints.constraints)
  return &constraints_;
}
inline const ::blox::AnalogConstraint& AnalogConstraints::constraints(int index) const {
  // @@protoc_insertion_point(field_get:blox.AnalogConstraints.constraints)
  return constraints_.Get(index);
}
inline ::blox::AnalogConstraint* AnalogConstraints::add_constraints() {
  // @@protoc_insertion_point(field_add:blox.AnalogConstraints.constraints)
  return constraints_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox::AnalogConstraint >&
AnalogConstraints::constraints() const {
  // @@protoc_insertion_point(field_list:blox.AnalogConstraints.constraints)
  return constraints_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_AnalogConstraints_5ftest_2eproto
