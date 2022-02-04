// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ActuatorLogic_test.proto

#ifndef PROTOBUF_INCLUDED_ActuatorLogic_5ftest_2eproto
#define PROTOBUF_INCLUDED_ActuatorLogic_5ftest_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
#include "IoArray_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_ActuatorLogic_5ftest_2eproto 

namespace protobuf_ActuatorLogic_5ftest_2eproto {
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
}  // namespace protobuf_ActuatorLogic_5ftest_2eproto
namespace blox_test {
namespace ActuatorLogic {
class AnalogCompare;
class AnalogCompareDefaultTypeInternal;
extern AnalogCompareDefaultTypeInternal _AnalogCompare_default_instance_;
class Block;
class BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
class DigitalCompare;
class DigitalCompareDefaultTypeInternal;
extern DigitalCompareDefaultTypeInternal _DigitalCompare_default_instance_;
}  // namespace ActuatorLogic
}  // namespace blox_test
namespace google {
namespace protobuf {
template<> ::blox_test::ActuatorLogic::AnalogCompare* Arena::CreateMaybeMessage<::blox_test::ActuatorLogic::AnalogCompare>(Arena*);
template<> ::blox_test::ActuatorLogic::Block* Arena::CreateMaybeMessage<::blox_test::ActuatorLogic::Block>(Arena*);
template<> ::blox_test::ActuatorLogic::DigitalCompare* Arena::CreateMaybeMessage<::blox_test::ActuatorLogic::DigitalCompare>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox_test {
namespace ActuatorLogic {

enum Result {
  RESULT_FALSE = 0,
  RESULT_TRUE = 1,
  RESULT_EMPTY = 2,
  RESULT_EMPTY_SUBSTRING = 3,
  RESULT_BLOCK_NOT_FOUND = 4,
  RESULT_INVALID_DIGITAL_OP = 5,
  RESULT_INVALID_ANALOG_OP = 6,
  RESULT_UNDEFINED_DIGITAL_COMPARE = 8,
  RESULT_UNDEFINED_ANALOG_COMPARE = 7,
  RESULT_UNEXPECTED_OPEN_BRACKET = 11,
  RESULT_UNEXPECTED_CLOSE_BRACKET = 9,
  RESULT_UNEXPECTED_CHARACTER = 12,
  RESULT_UNEXPECTED_COMPARISON = 13,
  RESULT_UNEXPECTED_OPERATOR = 14,
  RESULT_MISSING_CLOSE_BRACKET = 10,
  Result_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  Result_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool Result_IsValid(int value);
const Result Result_MIN = RESULT_FALSE;
const Result Result_MAX = RESULT_UNEXPECTED_OPERATOR;
const int Result_ARRAYSIZE = Result_MAX + 1;

const ::google::protobuf::EnumDescriptor* Result_descriptor();
inline const ::std::string& Result_Name(Result value) {
  return ::google::protobuf::internal::NameOfEnum(
    Result_descriptor(), value);
}
inline bool Result_Parse(
    const ::std::string& name, Result* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Result>(
    Result_descriptor(), name, value);
}
enum DigitalOperator {
  OP_VALUE_IS = 0,
  OP_VALUE_IS_NOT = 1,
  OP_DESIRED_IS = 10,
  OP_DESIRED_IS_NOT = 11,
  DigitalOperator_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  DigitalOperator_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool DigitalOperator_IsValid(int value);
const DigitalOperator DigitalOperator_MIN = OP_VALUE_IS;
const DigitalOperator DigitalOperator_MAX = OP_DESIRED_IS_NOT;
const int DigitalOperator_ARRAYSIZE = DigitalOperator_MAX + 1;

const ::google::protobuf::EnumDescriptor* DigitalOperator_descriptor();
inline const ::std::string& DigitalOperator_Name(DigitalOperator value) {
  return ::google::protobuf::internal::NameOfEnum(
    DigitalOperator_descriptor(), value);
}
inline bool DigitalOperator_Parse(
    const ::std::string& name, DigitalOperator* value) {
  return ::google::protobuf::internal::ParseNamedEnum<DigitalOperator>(
    DigitalOperator_descriptor(), name, value);
}
enum AnalogOperator {
  OP_VALUE_LE = 0,
  OP_VALUE_GE = 1,
  OP_SETTING_LE = 10,
  OP_SETTING_GE = 11,
  AnalogOperator_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  AnalogOperator_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool AnalogOperator_IsValid(int value);
const AnalogOperator AnalogOperator_MIN = OP_VALUE_LE;
const AnalogOperator AnalogOperator_MAX = OP_SETTING_GE;
const int AnalogOperator_ARRAYSIZE = AnalogOperator_MAX + 1;

const ::google::protobuf::EnumDescriptor* AnalogOperator_descriptor();
inline const ::std::string& AnalogOperator_Name(AnalogOperator value) {
  return ::google::protobuf::internal::NameOfEnum(
    AnalogOperator_descriptor(), value);
}
inline bool AnalogOperator_Parse(
    const ::std::string& name, AnalogOperator* value) {
  return ::google::protobuf::internal::ParseNamedEnum<AnalogOperator>(
    AnalogOperator_descriptor(), name, value);
}
// ===================================================================

class DigitalCompare : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.ActuatorLogic.DigitalCompare) */ {
 public:
  DigitalCompare();
  virtual ~DigitalCompare();

  DigitalCompare(const DigitalCompare& from);

  inline DigitalCompare& operator=(const DigitalCompare& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  DigitalCompare(DigitalCompare&& from) noexcept
    : DigitalCompare() {
    *this = ::std::move(from);
  }

  inline DigitalCompare& operator=(DigitalCompare&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const DigitalCompare& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const DigitalCompare* internal_default_instance() {
    return reinterpret_cast<const DigitalCompare*>(
               &_DigitalCompare_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(DigitalCompare* other);
  friend void swap(DigitalCompare& a, DigitalCompare& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline DigitalCompare* New() const final {
    return CreateMaybeMessage<DigitalCompare>(NULL);
  }

  DigitalCompare* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<DigitalCompare>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const DigitalCompare& from);
  void MergeFrom(const DigitalCompare& from);
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
  void InternalSwap(DigitalCompare* other);
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

  // .blox_test.ActuatorLogic.DigitalOperator op = 1;
  void clear_op();
  static const int kOpFieldNumber = 1;
  ::blox_test::ActuatorLogic::DigitalOperator op() const;
  void set_op(::blox_test::ActuatorLogic::DigitalOperator value);

  // .blox_test.ActuatorLogic.Result result = 2 [(.brewblox.field) = {
  void clear_result();
  static const int kResultFieldNumber = 2;
  ::blox_test::ActuatorLogic::Result result() const;
  void set_result(::blox_test::ActuatorLogic::Result value);

  // uint32 id = 3 [(.nanopb) = {
  void clear_id();
  static const int kIdFieldNumber = 3;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // .blox_test.IoArray.DigitalState rhs = 4;
  void clear_rhs();
  static const int kRhsFieldNumber = 4;
  ::blox_test::IoArray::DigitalState rhs() const;
  void set_rhs(::blox_test::IoArray::DigitalState value);

  // @@protoc_insertion_point(class_scope:blox_test.ActuatorLogic.DigitalCompare)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int op_;
  int result_;
  ::google::protobuf::uint32 id_;
  int rhs_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_ActuatorLogic_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class AnalogCompare : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.ActuatorLogic.AnalogCompare) */ {
 public:
  AnalogCompare();
  virtual ~AnalogCompare();

  AnalogCompare(const AnalogCompare& from);

  inline AnalogCompare& operator=(const AnalogCompare& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  AnalogCompare(AnalogCompare&& from) noexcept
    : AnalogCompare() {
    *this = ::std::move(from);
  }

  inline AnalogCompare& operator=(AnalogCompare&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const AnalogCompare& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const AnalogCompare* internal_default_instance() {
    return reinterpret_cast<const AnalogCompare*>(
               &_AnalogCompare_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(AnalogCompare* other);
  friend void swap(AnalogCompare& a, AnalogCompare& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline AnalogCompare* New() const final {
    return CreateMaybeMessage<AnalogCompare>(NULL);
  }

  AnalogCompare* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<AnalogCompare>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const AnalogCompare& from);
  void MergeFrom(const AnalogCompare& from);
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
  void InternalSwap(AnalogCompare* other);
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

  // .blox_test.ActuatorLogic.AnalogOperator op = 1;
  void clear_op();
  static const int kOpFieldNumber = 1;
  ::blox_test::ActuatorLogic::AnalogOperator op() const;
  void set_op(::blox_test::ActuatorLogic::AnalogOperator value);

  // .blox_test.ActuatorLogic.Result result = 2 [(.brewblox.field) = {
  void clear_result();
  static const int kResultFieldNumber = 2;
  ::blox_test::ActuatorLogic::Result result() const;
  void set_result(::blox_test::ActuatorLogic::Result value);

  // uint32 id = 3 [(.nanopb) = {
  void clear_id();
  static const int kIdFieldNumber = 3;
  ::google::protobuf::uint32 id() const;
  void set_id(::google::protobuf::uint32 value);

  // sint32 rhs = 4 [(.nanopb) = {
  void clear_rhs();
  static const int kRhsFieldNumber = 4;
  ::google::protobuf::int32 rhs() const;
  void set_rhs(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:blox_test.ActuatorLogic.AnalogCompare)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  int op_;
  int result_;
  ::google::protobuf::uint32 id_;
  ::google::protobuf::int32 rhs_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_ActuatorLogic_5ftest_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class Block : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox_test.ActuatorLogic.Block) */ {
 public:
  Block();
  virtual ~Block();

  Block(const Block& from);

  inline Block& operator=(const Block& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Block(Block&& from) noexcept
    : Block() {
    *this = ::std::move(from);
  }

  inline Block& operator=(Block&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Block& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Block* internal_default_instance() {
    return reinterpret_cast<const Block*>(
               &_Block_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(Block* other);
  friend void swap(Block& a, Block& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Block* New() const final {
    return CreateMaybeMessage<Block>(NULL);
  }

  Block* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Block>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Block& from);
  void MergeFrom(const Block& from);
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
  void InternalSwap(Block* other);
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

  // repeated .blox_test.ActuatorLogic.DigitalCompare digital = 6 [(.nanopb) = {
  int digital_size() const;
  void clear_digital();
  static const int kDigitalFieldNumber = 6;
  ::blox_test::ActuatorLogic::DigitalCompare* mutable_digital(int index);
  ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::DigitalCompare >*
      mutable_digital();
  const ::blox_test::ActuatorLogic::DigitalCompare& digital(int index) const;
  ::blox_test::ActuatorLogic::DigitalCompare* add_digital();
  const ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::DigitalCompare >&
      digital() const;

  // repeated .blox_test.ActuatorLogic.AnalogCompare analog = 7 [(.nanopb) = {
  int analog_size() const;
  void clear_analog();
  static const int kAnalogFieldNumber = 7;
  ::blox_test::ActuatorLogic::AnalogCompare* mutable_analog(int index);
  ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::AnalogCompare >*
      mutable_analog();
  const ::blox_test::ActuatorLogic::AnalogCompare& analog(int index) const;
  ::blox_test::ActuatorLogic::AnalogCompare* add_analog();
  const ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::AnalogCompare >&
      analog() const;

  // string expression = 5 [(.nanopb) = {
  void clear_expression();
  static const int kExpressionFieldNumber = 5;
  const ::std::string& expression() const;
  void set_expression(const ::std::string& value);
  #if LANG_CXX11
  void set_expression(::std::string&& value);
  #endif
  void set_expression(const char* value);
  void set_expression(const char* value, size_t size);
  ::std::string* mutable_expression();
  ::std::string* release_expression();
  void set_allocated_expression(::std::string* expression);

  // uint32 targetId = 1 [(.nanopb) = {
  void clear_targetid();
  static const int kTargetIdFieldNumber = 1;
  ::google::protobuf::uint32 targetid() const;
  void set_targetid(::google::protobuf::uint32 value);

  // uint32 drivenTargetId = 2 [(.nanopb) = {
  void clear_driventargetid();
  static const int kDrivenTargetIdFieldNumber = 2;
  ::google::protobuf::uint32 driventargetid() const;
  void set_driventargetid(::google::protobuf::uint32 value);

  // bool enabled = 3;
  void clear_enabled();
  static const int kEnabledFieldNumber = 3;
  bool enabled() const;
  void set_enabled(bool value);

  // .blox_test.ActuatorLogic.Result result = 4 [(.brewblox.field) = {
  void clear_result();
  static const int kResultFieldNumber = 4;
  ::blox_test::ActuatorLogic::Result result() const;
  void set_result(::blox_test::ActuatorLogic::Result value);

  // uint32 errorPos = 8 [(.nanopb) = {
  void clear_errorpos();
  static const int kErrorPosFieldNumber = 8;
  ::google::protobuf::uint32 errorpos() const;
  void set_errorpos(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:blox_test.ActuatorLogic.Block)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::DigitalCompare > digital_;
  ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::AnalogCompare > analog_;
  ::google::protobuf::internal::ArenaStringPtr expression_;
  ::google::protobuf::uint32 targetid_;
  ::google::protobuf::uint32 driventargetid_;
  bool enabled_;
  int result_;
  ::google::protobuf::uint32 errorpos_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_ActuatorLogic_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// DigitalCompare

// .blox_test.ActuatorLogic.DigitalOperator op = 1;
inline void DigitalCompare::clear_op() {
  op_ = 0;
}
inline ::blox_test::ActuatorLogic::DigitalOperator DigitalCompare::op() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.DigitalCompare.op)
  return static_cast< ::blox_test::ActuatorLogic::DigitalOperator >(op_);
}
inline void DigitalCompare::set_op(::blox_test::ActuatorLogic::DigitalOperator value) {
  
  op_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.DigitalCompare.op)
}

// .blox_test.ActuatorLogic.Result result = 2 [(.brewblox.field) = {
inline void DigitalCompare::clear_result() {
  result_ = 0;
}
inline ::blox_test::ActuatorLogic::Result DigitalCompare::result() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.DigitalCompare.result)
  return static_cast< ::blox_test::ActuatorLogic::Result >(result_);
}
inline void DigitalCompare::set_result(::blox_test::ActuatorLogic::Result value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.DigitalCompare.result)
}

// uint32 id = 3 [(.nanopb) = {
inline void DigitalCompare::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 DigitalCompare::id() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.DigitalCompare.id)
  return id_;
}
inline void DigitalCompare::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.DigitalCompare.id)
}

// .blox_test.IoArray.DigitalState rhs = 4;
inline void DigitalCompare::clear_rhs() {
  rhs_ = 0;
}
inline ::blox_test::IoArray::DigitalState DigitalCompare::rhs() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.DigitalCompare.rhs)
  return static_cast< ::blox_test::IoArray::DigitalState >(rhs_);
}
inline void DigitalCompare::set_rhs(::blox_test::IoArray::DigitalState value) {
  
  rhs_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.DigitalCompare.rhs)
}

// -------------------------------------------------------------------

// AnalogCompare

// .blox_test.ActuatorLogic.AnalogOperator op = 1;
inline void AnalogCompare::clear_op() {
  op_ = 0;
}
inline ::blox_test::ActuatorLogic::AnalogOperator AnalogCompare::op() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.AnalogCompare.op)
  return static_cast< ::blox_test::ActuatorLogic::AnalogOperator >(op_);
}
inline void AnalogCompare::set_op(::blox_test::ActuatorLogic::AnalogOperator value) {
  
  op_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.AnalogCompare.op)
}

// .blox_test.ActuatorLogic.Result result = 2 [(.brewblox.field) = {
inline void AnalogCompare::clear_result() {
  result_ = 0;
}
inline ::blox_test::ActuatorLogic::Result AnalogCompare::result() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.AnalogCompare.result)
  return static_cast< ::blox_test::ActuatorLogic::Result >(result_);
}
inline void AnalogCompare::set_result(::blox_test::ActuatorLogic::Result value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.AnalogCompare.result)
}

// uint32 id = 3 [(.nanopb) = {
inline void AnalogCompare::clear_id() {
  id_ = 0u;
}
inline ::google::protobuf::uint32 AnalogCompare::id() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.AnalogCompare.id)
  return id_;
}
inline void AnalogCompare::set_id(::google::protobuf::uint32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.AnalogCompare.id)
}

// sint32 rhs = 4 [(.nanopb) = {
inline void AnalogCompare::clear_rhs() {
  rhs_ = 0;
}
inline ::google::protobuf::int32 AnalogCompare::rhs() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.AnalogCompare.rhs)
  return rhs_;
}
inline void AnalogCompare::set_rhs(::google::protobuf::int32 value) {
  
  rhs_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.AnalogCompare.rhs)
}

// -------------------------------------------------------------------

// Block

// uint32 targetId = 1 [(.nanopb) = {
inline void Block::clear_targetid() {
  targetid_ = 0u;
}
inline ::google::protobuf::uint32 Block::targetid() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.targetId)
  return targetid_;
}
inline void Block::set_targetid(::google::protobuf::uint32 value) {
  
  targetid_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.Block.targetId)
}

// uint32 drivenTargetId = 2 [(.nanopb) = {
inline void Block::clear_driventargetid() {
  driventargetid_ = 0u;
}
inline ::google::protobuf::uint32 Block::driventargetid() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.drivenTargetId)
  return driventargetid_;
}
inline void Block::set_driventargetid(::google::protobuf::uint32 value) {
  
  driventargetid_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.Block.drivenTargetId)
}

// bool enabled = 3;
inline void Block::clear_enabled() {
  enabled_ = false;
}
inline bool Block::enabled() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.enabled)
  return enabled_;
}
inline void Block::set_enabled(bool value) {
  
  enabled_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.Block.enabled)
}

// .blox_test.ActuatorLogic.Result result = 4 [(.brewblox.field) = {
inline void Block::clear_result() {
  result_ = 0;
}
inline ::blox_test::ActuatorLogic::Result Block::result() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.result)
  return static_cast< ::blox_test::ActuatorLogic::Result >(result_);
}
inline void Block::set_result(::blox_test::ActuatorLogic::Result value) {
  
  result_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.Block.result)
}

// string expression = 5 [(.nanopb) = {
inline void Block::clear_expression() {
  expression_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& Block::expression() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.expression)
  return expression_.GetNoArena();
}
inline void Block::set_expression(const ::std::string& value) {
  
  expression_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.Block.expression)
}
#if LANG_CXX11
inline void Block::set_expression(::std::string&& value) {
  
  expression_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:blox_test.ActuatorLogic.Block.expression)
}
#endif
inline void Block::set_expression(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  expression_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:blox_test.ActuatorLogic.Block.expression)
}
inline void Block::set_expression(const char* value, size_t size) {
  
  expression_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:blox_test.ActuatorLogic.Block.expression)
}
inline ::std::string* Block::mutable_expression() {
  
  // @@protoc_insertion_point(field_mutable:blox_test.ActuatorLogic.Block.expression)
  return expression_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* Block::release_expression() {
  // @@protoc_insertion_point(field_release:blox_test.ActuatorLogic.Block.expression)
  
  return expression_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void Block::set_allocated_expression(::std::string* expression) {
  if (expression != NULL) {
    
  } else {
    
  }
  expression_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), expression);
  // @@protoc_insertion_point(field_set_allocated:blox_test.ActuatorLogic.Block.expression)
}

// repeated .blox_test.ActuatorLogic.DigitalCompare digital = 6 [(.nanopb) = {
inline int Block::digital_size() const {
  return digital_.size();
}
inline void Block::clear_digital() {
  digital_.Clear();
}
inline ::blox_test::ActuatorLogic::DigitalCompare* Block::mutable_digital(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.ActuatorLogic.Block.digital)
  return digital_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::DigitalCompare >*
Block::mutable_digital() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.ActuatorLogic.Block.digital)
  return &digital_;
}
inline const ::blox_test::ActuatorLogic::DigitalCompare& Block::digital(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.digital)
  return digital_.Get(index);
}
inline ::blox_test::ActuatorLogic::DigitalCompare* Block::add_digital() {
  // @@protoc_insertion_point(field_add:blox_test.ActuatorLogic.Block.digital)
  return digital_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::DigitalCompare >&
Block::digital() const {
  // @@protoc_insertion_point(field_list:blox_test.ActuatorLogic.Block.digital)
  return digital_;
}

// repeated .blox_test.ActuatorLogic.AnalogCompare analog = 7 [(.nanopb) = {
inline int Block::analog_size() const {
  return analog_.size();
}
inline void Block::clear_analog() {
  analog_.Clear();
}
inline ::blox_test::ActuatorLogic::AnalogCompare* Block::mutable_analog(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.ActuatorLogic.Block.analog)
  return analog_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::AnalogCompare >*
Block::mutable_analog() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.ActuatorLogic.Block.analog)
  return &analog_;
}
inline const ::blox_test::ActuatorLogic::AnalogCompare& Block::analog(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.analog)
  return analog_.Get(index);
}
inline ::blox_test::ActuatorLogic::AnalogCompare* Block::add_analog() {
  // @@protoc_insertion_point(field_add:blox_test.ActuatorLogic.Block.analog)
  return analog_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::blox_test::ActuatorLogic::AnalogCompare >&
Block::analog() const {
  // @@protoc_insertion_point(field_list:blox_test.ActuatorLogic.Block.analog)
  return analog_;
}

// uint32 errorPos = 8 [(.nanopb) = {
inline void Block::clear_errorpos() {
  errorpos_ = 0u;
}
inline ::google::protobuf::uint32 Block::errorpos() const {
  // @@protoc_insertion_point(field_get:blox_test.ActuatorLogic.Block.errorPos)
  return errorpos_;
}
inline void Block::set_errorpos(::google::protobuf::uint32 value) {
  
  errorpos_ = value;
  // @@protoc_insertion_point(field_set:blox_test.ActuatorLogic.Block.errorPos)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ActuatorLogic
}  // namespace blox_test

namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::blox_test::ActuatorLogic::Result> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::ActuatorLogic::Result>() {
  return ::blox_test::ActuatorLogic::Result_descriptor();
}
template <> struct is_proto_enum< ::blox_test::ActuatorLogic::DigitalOperator> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::ActuatorLogic::DigitalOperator>() {
  return ::blox_test::ActuatorLogic::DigitalOperator_descriptor();
}
template <> struct is_proto_enum< ::blox_test::ActuatorLogic::AnalogOperator> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox_test::ActuatorLogic::AnalogOperator>() {
  return ::blox_test::ActuatorLogic::AnalogOperator_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_ActuatorLogic_5ftest_2eproto
