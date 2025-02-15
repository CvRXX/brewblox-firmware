// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nanopb_test.proto

#ifndef PROTOBUF_INCLUDED_nanopb_5ftest_2eproto
#define PROTOBUF_INCLUDED_nanopb_5ftest_2eproto

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
#include <google/protobuf/descriptor.pb.h>
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_nanopb_5ftest_2eproto 

namespace protobuf_nanopb_5ftest_2eproto {
// Internal implementation detail -- do not use these members.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[1];
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors();
}  // namespace protobuf_nanopb_5ftest_2eproto
class NanoPBOptions;
class NanoPBOptionsDefaultTypeInternal;
extern NanoPBOptionsDefaultTypeInternal _NanoPBOptions_default_instance_;
namespace google {
namespace protobuf {
template<> ::NanoPBOptions* Arena::CreateMaybeMessage<::NanoPBOptions>(Arena*);
}  // namespace protobuf
}  // namespace google

enum FieldType {
  FT_DEFAULT = 0,
  FT_CALLBACK = 1,
  FT_POINTER = 4,
  FT_STATIC = 2,
  FT_IGNORE = 3,
  FT_INLINE = 5
};
bool FieldType_IsValid(int value);
const FieldType FieldType_MIN = FT_DEFAULT;
const FieldType FieldType_MAX = FT_INLINE;
const int FieldType_ARRAYSIZE = FieldType_MAX + 1;

const ::google::protobuf::EnumDescriptor* FieldType_descriptor();
inline const ::std::string& FieldType_Name(FieldType value) {
  return ::google::protobuf::internal::NameOfEnum(
    FieldType_descriptor(), value);
}
inline bool FieldType_Parse(
    const ::std::string& name, FieldType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<FieldType>(
    FieldType_descriptor(), name, value);
}
enum IntSize {
  IS_DEFAULT = 0,
  IS_8 = 8,
  IS_16 = 16,
  IS_32 = 32,
  IS_64 = 64
};
bool IntSize_IsValid(int value);
const IntSize IntSize_MIN = IS_DEFAULT;
const IntSize IntSize_MAX = IS_64;
const int IntSize_ARRAYSIZE = IntSize_MAX + 1;

const ::google::protobuf::EnumDescriptor* IntSize_descriptor();
inline const ::std::string& IntSize_Name(IntSize value) {
  return ::google::protobuf::internal::NameOfEnum(
    IntSize_descriptor(), value);
}
inline bool IntSize_Parse(
    const ::std::string& name, IntSize* value) {
  return ::google::protobuf::internal::ParseNamedEnum<IntSize>(
    IntSize_descriptor(), name, value);
}
// ===================================================================

class NanoPBOptions : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:NanoPBOptions) */ {
 public:
  NanoPBOptions();
  virtual ~NanoPBOptions();

  NanoPBOptions(const NanoPBOptions& from);

  inline NanoPBOptions& operator=(const NanoPBOptions& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  NanoPBOptions(NanoPBOptions&& from) noexcept
    : NanoPBOptions() {
    *this = ::std::move(from);
  }

  inline NanoPBOptions& operator=(NanoPBOptions&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const NanoPBOptions& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const NanoPBOptions* internal_default_instance() {
    return reinterpret_cast<const NanoPBOptions*>(
               &_NanoPBOptions_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(NanoPBOptions* other);
  friend void swap(NanoPBOptions& a, NanoPBOptions& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline NanoPBOptions* New() const final {
    return CreateMaybeMessage<NanoPBOptions>(NULL);
  }

  NanoPBOptions* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<NanoPBOptions>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const NanoPBOptions& from);
  void MergeFrom(const NanoPBOptions& from);
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
  void InternalSwap(NanoPBOptions* other);
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

  // optional int32 max_size = 1;
  bool has_max_size() const;
  void clear_max_size();
  static const int kMaxSizeFieldNumber = 1;
  ::google::protobuf::int32 max_size() const;
  void set_max_size(::google::protobuf::int32 value);

  // optional int32 max_count = 2;
  bool has_max_count() const;
  void clear_max_count();
  static const int kMaxCountFieldNumber = 2;
  ::google::protobuf::int32 max_count() const;
  void set_max_count(::google::protobuf::int32 value);

  // optional .FieldType type = 3 [default = FT_DEFAULT];
  bool has_type() const;
  void clear_type();
  static const int kTypeFieldNumber = 3;
  ::FieldType type() const;
  void set_type(::FieldType value);

  // optional .IntSize int_size = 7 [default = IS_DEFAULT];
  bool has_int_size() const;
  void clear_int_size();
  static const int kIntSizeFieldNumber = 7;
  ::IntSize int_size() const;
  void set_int_size(::IntSize value);

  // optional bool packed_struct = 5 [default = false];
  bool has_packed_struct() const;
  void clear_packed_struct();
  static const int kPackedStructFieldNumber = 5;
  bool packed_struct() const;
  void set_packed_struct(bool value);

  // optional bool packed_enum = 10 [default = false];
  bool has_packed_enum() const;
  void clear_packed_enum();
  static const int kPackedEnumFieldNumber = 10;
  bool packed_enum() const;
  void set_packed_enum(bool value);

  // optional bool skip_message = 6 [default = false];
  bool has_skip_message() const;
  void clear_skip_message();
  static const int kSkipMessageFieldNumber = 6;
  bool skip_message() const;
  void set_skip_message(bool value);

  // optional bool no_unions = 8 [default = false];
  bool has_no_unions() const;
  void clear_no_unions();
  static const int kNoUnionsFieldNumber = 8;
  bool no_unions() const;
  void set_no_unions(bool value);

  // optional uint32 msgid = 9;
  bool has_msgid() const;
  void clear_msgid();
  static const int kMsgidFieldNumber = 9;
  ::google::protobuf::uint32 msgid() const;
  void set_msgid(::google::protobuf::uint32 value);

  // optional bool anonymous_oneof = 11 [default = false];
  bool has_anonymous_oneof() const;
  void clear_anonymous_oneof();
  static const int kAnonymousOneofFieldNumber = 11;
  bool anonymous_oneof() const;
  void set_anonymous_oneof(bool value);

  // optional bool proto3 = 12 [default = false];
  bool has_proto3() const;
  void clear_proto3();
  static const int kProto3FieldNumber = 12;
  bool proto3() const;
  void set_proto3(bool value);

  // optional bool enum_to_string = 13 [default = false];
  bool has_enum_to_string() const;
  void clear_enum_to_string();
  static const int kEnumToStringFieldNumber = 13;
  bool enum_to_string() const;
  void set_enum_to_string(bool value);

  // optional bool fixed_length = 15 [default = false];
  bool has_fixed_length() const;
  void clear_fixed_length();
  static const int kFixedLengthFieldNumber = 15;
  bool fixed_length() const;
  void set_fixed_length(bool value);

  // optional int32 max_length = 14;
  bool has_max_length() const;
  void clear_max_length();
  static const int kMaxLengthFieldNumber = 14;
  ::google::protobuf::int32 max_length() const;
  void set_max_length(::google::protobuf::int32 value);

  // optional bool long_names = 4 [default = true];
  bool has_long_names() const;
  void clear_long_names();
  static const int kLongNamesFieldNumber = 4;
  bool long_names() const;
  void set_long_names(bool value);

  // @@protoc_insertion_point(class_scope:NanoPBOptions)
 private:
  void set_has_max_size();
  void clear_has_max_size();
  void set_has_max_length();
  void clear_has_max_length();
  void set_has_max_count();
  void clear_has_max_count();
  void set_has_int_size();
  void clear_has_int_size();
  void set_has_type();
  void clear_has_type();
  void set_has_long_names();
  void clear_has_long_names();
  void set_has_packed_struct();
  void clear_has_packed_struct();
  void set_has_packed_enum();
  void clear_has_packed_enum();
  void set_has_skip_message();
  void clear_has_skip_message();
  void set_has_no_unions();
  void clear_has_no_unions();
  void set_has_msgid();
  void clear_has_msgid();
  void set_has_anonymous_oneof();
  void clear_has_anonymous_oneof();
  void set_has_proto3();
  void clear_has_proto3();
  void set_has_enum_to_string();
  void clear_has_enum_to_string();
  void set_has_fixed_length();
  void clear_has_fixed_length();

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::internal::HasBits<1> _has_bits_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  ::google::protobuf::int32 max_size_;
  ::google::protobuf::int32 max_count_;
  int type_;
  int int_size_;
  bool packed_struct_;
  bool packed_enum_;
  bool skip_message_;
  bool no_unions_;
  ::google::protobuf::uint32 msgid_;
  bool anonymous_oneof_;
  bool proto3_;
  bool enum_to_string_;
  bool fixed_length_;
  ::google::protobuf::int32 max_length_;
  bool long_names_;
  friend struct ::protobuf_nanopb_5ftest_2eproto::TableStruct;
};
// ===================================================================

static const int kNanopbFileoptFieldNumber = 1010;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::FileOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::NanoPBOptions >, 11, false >
  nanopb_fileopt;
static const int kNanopbMsgoptFieldNumber = 1010;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::MessageOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::NanoPBOptions >, 11, false >
  nanopb_msgopt;
static const int kNanopbEnumoptFieldNumber = 1010;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::EnumOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::NanoPBOptions >, 11, false >
  nanopb_enumopt;
static const int kNanopbFieldNumber = 1010;
extern ::google::protobuf::internal::ExtensionIdentifier< ::google::protobuf::FieldOptions,
    ::google::protobuf::internal::MessageTypeTraits< ::NanoPBOptions >, 11, false >
  nanopb;

// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// NanoPBOptions

// optional int32 max_size = 1;
inline bool NanoPBOptions::has_max_size() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void NanoPBOptions::set_has_max_size() {
  _has_bits_[0] |= 0x00000001u;
}
inline void NanoPBOptions::clear_has_max_size() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void NanoPBOptions::clear_max_size() {
  max_size_ = 0;
  clear_has_max_size();
}
inline ::google::protobuf::int32 NanoPBOptions::max_size() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.max_size)
  return max_size_;
}
inline void NanoPBOptions::set_max_size(::google::protobuf::int32 value) {
  set_has_max_size();
  max_size_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.max_size)
}

// optional int32 max_length = 14;
inline bool NanoPBOptions::has_max_length() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void NanoPBOptions::set_has_max_length() {
  _has_bits_[0] |= 0x00002000u;
}
inline void NanoPBOptions::clear_has_max_length() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void NanoPBOptions::clear_max_length() {
  max_length_ = 0;
  clear_has_max_length();
}
inline ::google::protobuf::int32 NanoPBOptions::max_length() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.max_length)
  return max_length_;
}
inline void NanoPBOptions::set_max_length(::google::protobuf::int32 value) {
  set_has_max_length();
  max_length_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.max_length)
}

// optional int32 max_count = 2;
inline bool NanoPBOptions::has_max_count() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void NanoPBOptions::set_has_max_count() {
  _has_bits_[0] |= 0x00000002u;
}
inline void NanoPBOptions::clear_has_max_count() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void NanoPBOptions::clear_max_count() {
  max_count_ = 0;
  clear_has_max_count();
}
inline ::google::protobuf::int32 NanoPBOptions::max_count() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.max_count)
  return max_count_;
}
inline void NanoPBOptions::set_max_count(::google::protobuf::int32 value) {
  set_has_max_count();
  max_count_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.max_count)
}

// optional .IntSize int_size = 7 [default = IS_DEFAULT];
inline bool NanoPBOptions::has_int_size() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void NanoPBOptions::set_has_int_size() {
  _has_bits_[0] |= 0x00000008u;
}
inline void NanoPBOptions::clear_has_int_size() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void NanoPBOptions::clear_int_size() {
  int_size_ = 0;
  clear_has_int_size();
}
inline ::IntSize NanoPBOptions::int_size() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.int_size)
  return static_cast< ::IntSize >(int_size_);
}
inline void NanoPBOptions::set_int_size(::IntSize value) {
  assert(::IntSize_IsValid(value));
  set_has_int_size();
  int_size_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.int_size)
}

// optional .FieldType type = 3 [default = FT_DEFAULT];
inline bool NanoPBOptions::has_type() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void NanoPBOptions::set_has_type() {
  _has_bits_[0] |= 0x00000004u;
}
inline void NanoPBOptions::clear_has_type() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void NanoPBOptions::clear_type() {
  type_ = 0;
  clear_has_type();
}
inline ::FieldType NanoPBOptions::type() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.type)
  return static_cast< ::FieldType >(type_);
}
inline void NanoPBOptions::set_type(::FieldType value) {
  assert(::FieldType_IsValid(value));
  set_has_type();
  type_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.type)
}

// optional bool long_names = 4 [default = true];
inline bool NanoPBOptions::has_long_names() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void NanoPBOptions::set_has_long_names() {
  _has_bits_[0] |= 0x00004000u;
}
inline void NanoPBOptions::clear_has_long_names() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void NanoPBOptions::clear_long_names() {
  long_names_ = true;
  clear_has_long_names();
}
inline bool NanoPBOptions::long_names() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.long_names)
  return long_names_;
}
inline void NanoPBOptions::set_long_names(bool value) {
  set_has_long_names();
  long_names_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.long_names)
}

// optional bool packed_struct = 5 [default = false];
inline bool NanoPBOptions::has_packed_struct() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void NanoPBOptions::set_has_packed_struct() {
  _has_bits_[0] |= 0x00000010u;
}
inline void NanoPBOptions::clear_has_packed_struct() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void NanoPBOptions::clear_packed_struct() {
  packed_struct_ = false;
  clear_has_packed_struct();
}
inline bool NanoPBOptions::packed_struct() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.packed_struct)
  return packed_struct_;
}
inline void NanoPBOptions::set_packed_struct(bool value) {
  set_has_packed_struct();
  packed_struct_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.packed_struct)
}

// optional bool packed_enum = 10 [default = false];
inline bool NanoPBOptions::has_packed_enum() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void NanoPBOptions::set_has_packed_enum() {
  _has_bits_[0] |= 0x00000020u;
}
inline void NanoPBOptions::clear_has_packed_enum() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void NanoPBOptions::clear_packed_enum() {
  packed_enum_ = false;
  clear_has_packed_enum();
}
inline bool NanoPBOptions::packed_enum() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.packed_enum)
  return packed_enum_;
}
inline void NanoPBOptions::set_packed_enum(bool value) {
  set_has_packed_enum();
  packed_enum_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.packed_enum)
}

// optional bool skip_message = 6 [default = false];
inline bool NanoPBOptions::has_skip_message() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void NanoPBOptions::set_has_skip_message() {
  _has_bits_[0] |= 0x00000040u;
}
inline void NanoPBOptions::clear_has_skip_message() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void NanoPBOptions::clear_skip_message() {
  skip_message_ = false;
  clear_has_skip_message();
}
inline bool NanoPBOptions::skip_message() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.skip_message)
  return skip_message_;
}
inline void NanoPBOptions::set_skip_message(bool value) {
  set_has_skip_message();
  skip_message_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.skip_message)
}

// optional bool no_unions = 8 [default = false];
inline bool NanoPBOptions::has_no_unions() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void NanoPBOptions::set_has_no_unions() {
  _has_bits_[0] |= 0x00000080u;
}
inline void NanoPBOptions::clear_has_no_unions() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void NanoPBOptions::clear_no_unions() {
  no_unions_ = false;
  clear_has_no_unions();
}
inline bool NanoPBOptions::no_unions() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.no_unions)
  return no_unions_;
}
inline void NanoPBOptions::set_no_unions(bool value) {
  set_has_no_unions();
  no_unions_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.no_unions)
}

// optional uint32 msgid = 9;
inline bool NanoPBOptions::has_msgid() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void NanoPBOptions::set_has_msgid() {
  _has_bits_[0] |= 0x00000100u;
}
inline void NanoPBOptions::clear_has_msgid() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void NanoPBOptions::clear_msgid() {
  msgid_ = 0u;
  clear_has_msgid();
}
inline ::google::protobuf::uint32 NanoPBOptions::msgid() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.msgid)
  return msgid_;
}
inline void NanoPBOptions::set_msgid(::google::protobuf::uint32 value) {
  set_has_msgid();
  msgid_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.msgid)
}

// optional bool anonymous_oneof = 11 [default = false];
inline bool NanoPBOptions::has_anonymous_oneof() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void NanoPBOptions::set_has_anonymous_oneof() {
  _has_bits_[0] |= 0x00000200u;
}
inline void NanoPBOptions::clear_has_anonymous_oneof() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void NanoPBOptions::clear_anonymous_oneof() {
  anonymous_oneof_ = false;
  clear_has_anonymous_oneof();
}
inline bool NanoPBOptions::anonymous_oneof() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.anonymous_oneof)
  return anonymous_oneof_;
}
inline void NanoPBOptions::set_anonymous_oneof(bool value) {
  set_has_anonymous_oneof();
  anonymous_oneof_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.anonymous_oneof)
}

// optional bool proto3 = 12 [default = false];
inline bool NanoPBOptions::has_proto3() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void NanoPBOptions::set_has_proto3() {
  _has_bits_[0] |= 0x00000400u;
}
inline void NanoPBOptions::clear_has_proto3() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void NanoPBOptions::clear_proto3() {
  proto3_ = false;
  clear_has_proto3();
}
inline bool NanoPBOptions::proto3() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.proto3)
  return proto3_;
}
inline void NanoPBOptions::set_proto3(bool value) {
  set_has_proto3();
  proto3_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.proto3)
}

// optional bool enum_to_string = 13 [default = false];
inline bool NanoPBOptions::has_enum_to_string() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void NanoPBOptions::set_has_enum_to_string() {
  _has_bits_[0] |= 0x00000800u;
}
inline void NanoPBOptions::clear_has_enum_to_string() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void NanoPBOptions::clear_enum_to_string() {
  enum_to_string_ = false;
  clear_has_enum_to_string();
}
inline bool NanoPBOptions::enum_to_string() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.enum_to_string)
  return enum_to_string_;
}
inline void NanoPBOptions::set_enum_to_string(bool value) {
  set_has_enum_to_string();
  enum_to_string_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.enum_to_string)
}

// optional bool fixed_length = 15 [default = false];
inline bool NanoPBOptions::has_fixed_length() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void NanoPBOptions::set_has_fixed_length() {
  _has_bits_[0] |= 0x00001000u;
}
inline void NanoPBOptions::clear_has_fixed_length() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void NanoPBOptions::clear_fixed_length() {
  fixed_length_ = false;
  clear_has_fixed_length();
}
inline bool NanoPBOptions::fixed_length() const {
  // @@protoc_insertion_point(field_get:NanoPBOptions.fixed_length)
  return fixed_length_;
}
inline void NanoPBOptions::set_fixed_length(bool value) {
  set_has_fixed_length();
  fixed_length_ = value;
  // @@protoc_insertion_point(field_set:NanoPBOptions.fixed_length)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::FieldType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::FieldType>() {
  return ::FieldType_descriptor();
}
template <> struct is_proto_enum< ::IntSize> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::IntSize>() {
  return ::IntSize_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_nanopb_5ftest_2eproto
