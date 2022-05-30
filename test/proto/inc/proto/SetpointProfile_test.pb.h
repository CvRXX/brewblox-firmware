// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: SetpointProfile_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_SetpointProfile_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_SetpointProfile_5ftest_2eproto

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
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_SetpointProfile_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_SetpointProfile_5ftest_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_SetpointProfile_5ftest_2eproto;
namespace blox_test {
namespace SetpointProfile {
class Block;
struct BlockDefaultTypeInternal;
extern BlockDefaultTypeInternal _Block_default_instance_;
class Point;
struct PointDefaultTypeInternal;
extern PointDefaultTypeInternal _Point_default_instance_;
}  // namespace SetpointProfile
}  // namespace blox_test
PROTOBUF_NAMESPACE_OPEN
template<> ::blox_test::SetpointProfile::Block* Arena::CreateMaybeMessage<::blox_test::SetpointProfile::Block>(Arena*);
template<> ::blox_test::SetpointProfile::Point* Arena::CreateMaybeMessage<::blox_test::SetpointProfile::Point>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox_test {
namespace SetpointProfile {

// ===================================================================

class Point final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox_test.SetpointProfile.Point) */ {
 public:
  inline Point() : Point(nullptr) {}
  ~Point() override;
  explicit PROTOBUF_CONSTEXPR Point(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Point(const Point& from);
  Point(Point&& from) noexcept
    : Point() {
    *this = ::std::move(from);
  }

  inline Point& operator=(const Point& from) {
    CopyFrom(from);
    return *this;
  }
  inline Point& operator=(Point&& from) noexcept {
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
  static const Point& default_instance() {
    return *internal_default_instance();
  }
  enum TemperatureOneofCase {
    kTemperature = 2,
    TEMPERATURE_ONEOF_NOT_SET = 0,
  };

  static inline const Point* internal_default_instance() {
    return reinterpret_cast<const Point*>(
               &_Point_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Point& a, Point& b) {
    a.Swap(&b);
  }
  inline void Swap(Point* other) {
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
  void UnsafeArenaSwap(Point* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  Point* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<Point>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Point& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Point& from);
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
  void InternalSwap(Point* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox_test.SetpointProfile.Point";
  }
  protected:
  explicit Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kTimeFieldNumber = 1,
    kTemperatureFieldNumber = 2,
  };
  // uint32 time = 1;
  void clear_time();
  uint32_t time() const;
  void set_time(uint32_t value);
  private:
  uint32_t _internal_time() const;
  void _internal_set_time(uint32_t value);
  public:

  // int32 temperature = 2 [(.nanopb) = {
  bool has_temperature() const;
  private:
  bool _internal_has_temperature() const;
  public:
  void clear_temperature();
  int32_t temperature() const;
  void set_temperature(int32_t value);
  private:
  int32_t _internal_temperature() const;
  void _internal_set_temperature(int32_t value);
  public:

  void clear_temperature_oneof();
  TemperatureOneofCase temperature_oneof_case() const;
  // @@protoc_insertion_point(class_scope:blox_test.SetpointProfile.Point)
 private:
  class _Internal;
  void set_has_temperature();

  inline bool has_temperature_oneof() const;
  inline void clear_has_temperature_oneof();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  uint32_t time_;
  union TemperatureOneofUnion {
    constexpr TemperatureOneofUnion() : _constinit_{} {}
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized _constinit_;
    int32_t temperature_;
  } temperature_oneof_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  uint32_t _oneof_case_[1];

  friend struct ::TableStruct_SetpointProfile_5ftest_2eproto;
};
// -------------------------------------------------------------------

class Block final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox_test.SetpointProfile.Block) */ {
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
    1;

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
    return "blox_test.SetpointProfile.Block";
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
    kPointsFieldNumber = 1,
    kEnabledFieldNumber = 3,
    kTargetIdFieldNumber = 4,
    kDrivenTargetIdFieldNumber = 5,
    kStartFieldNumber = 6,
  };
  // repeated .blox_test.SetpointProfile.Point points = 1;
  int points_size() const;
  private:
  int _internal_points_size() const;
  public:
  void clear_points();
  ::blox_test::SetpointProfile::Point* mutable_points(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::SetpointProfile::Point >*
      mutable_points();
  private:
  const ::blox_test::SetpointProfile::Point& _internal_points(int index) const;
  ::blox_test::SetpointProfile::Point* _internal_add_points();
  public:
  const ::blox_test::SetpointProfile::Point& points(int index) const;
  ::blox_test::SetpointProfile::Point* add_points();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::SetpointProfile::Point >&
      points() const;

  // bool enabled = 3;
  void clear_enabled();
  bool enabled() const;
  void set_enabled(bool value);
  private:
  bool _internal_enabled() const;
  void _internal_set_enabled(bool value);
  public:

  // uint32 targetId = 4 [(.nanopb) = {
  void clear_targetid();
  uint32_t targetid() const;
  void set_targetid(uint32_t value);
  private:
  uint32_t _internal_targetid() const;
  void _internal_set_targetid(uint32_t value);
  public:

  // uint32 drivenTargetId = 5 [(.nanopb) = {
  void clear_driventargetid();
  uint32_t driventargetid() const;
  void set_driventargetid(uint32_t value);
  private:
  uint32_t _internal_driventargetid() const;
  void _internal_set_driventargetid(uint32_t value);
  public:

  // uint32 start = 6;
  void clear_start();
  uint32_t start() const;
  void set_start(uint32_t value);
  private:
  uint32_t _internal_start() const;
  void _internal_set_start(uint32_t value);
  public:

  // @@protoc_insertion_point(class_scope:blox_test.SetpointProfile.Block)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::SetpointProfile::Point > points_;
  bool enabled_;
  uint32_t targetid_;
  uint32_t driventargetid_;
  uint32_t start_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_SetpointProfile_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Point

// uint32 time = 1;
inline void Point::clear_time() {
  time_ = 0u;
}
inline uint32_t Point::_internal_time() const {
  return time_;
}
inline uint32_t Point::time() const {
  // @@protoc_insertion_point(field_get:blox_test.SetpointProfile.Point.time)
  return _internal_time();
}
inline void Point::_internal_set_time(uint32_t value) {
  
  time_ = value;
}
inline void Point::set_time(uint32_t value) {
  _internal_set_time(value);
  // @@protoc_insertion_point(field_set:blox_test.SetpointProfile.Point.time)
}

// int32 temperature = 2 [(.nanopb) = {
inline bool Point::_internal_has_temperature() const {
  return temperature_oneof_case() == kTemperature;
}
inline bool Point::has_temperature() const {
  return _internal_has_temperature();
}
inline void Point::set_has_temperature() {
  _oneof_case_[0] = kTemperature;
}
inline void Point::clear_temperature() {
  if (_internal_has_temperature()) {
    temperature_oneof_.temperature_ = 0;
    clear_has_temperature_oneof();
  }
}
inline int32_t Point::_internal_temperature() const {
  if (_internal_has_temperature()) {
    return temperature_oneof_.temperature_;
  }
  return 0;
}
inline void Point::_internal_set_temperature(int32_t value) {
  if (!_internal_has_temperature()) {
    clear_temperature_oneof();
    set_has_temperature();
  }
  temperature_oneof_.temperature_ = value;
}
inline int32_t Point::temperature() const {
  // @@protoc_insertion_point(field_get:blox_test.SetpointProfile.Point.temperature)
  return _internal_temperature();
}
inline void Point::set_temperature(int32_t value) {
  _internal_set_temperature(value);
  // @@protoc_insertion_point(field_set:blox_test.SetpointProfile.Point.temperature)
}

inline bool Point::has_temperature_oneof() const {
  return temperature_oneof_case() != TEMPERATURE_ONEOF_NOT_SET;
}
inline void Point::clear_has_temperature_oneof() {
  _oneof_case_[0] = TEMPERATURE_ONEOF_NOT_SET;
}
inline Point::TemperatureOneofCase Point::temperature_oneof_case() const {
  return Point::TemperatureOneofCase(_oneof_case_[0]);
}
// -------------------------------------------------------------------

// Block

// repeated .blox_test.SetpointProfile.Point points = 1;
inline int Block::_internal_points_size() const {
  return points_.size();
}
inline int Block::points_size() const {
  return _internal_points_size();
}
inline void Block::clear_points() {
  points_.Clear();
}
inline ::blox_test::SetpointProfile::Point* Block::mutable_points(int index) {
  // @@protoc_insertion_point(field_mutable:blox_test.SetpointProfile.Block.points)
  return points_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::SetpointProfile::Point >*
Block::mutable_points() {
  // @@protoc_insertion_point(field_mutable_list:blox_test.SetpointProfile.Block.points)
  return &points_;
}
inline const ::blox_test::SetpointProfile::Point& Block::_internal_points(int index) const {
  return points_.Get(index);
}
inline const ::blox_test::SetpointProfile::Point& Block::points(int index) const {
  // @@protoc_insertion_point(field_get:blox_test.SetpointProfile.Block.points)
  return _internal_points(index);
}
inline ::blox_test::SetpointProfile::Point* Block::_internal_add_points() {
  return points_.Add();
}
inline ::blox_test::SetpointProfile::Point* Block::add_points() {
  ::blox_test::SetpointProfile::Point* _add = _internal_add_points();
  // @@protoc_insertion_point(field_add:blox_test.SetpointProfile.Block.points)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::blox_test::SetpointProfile::Point >&
Block::points() const {
  // @@protoc_insertion_point(field_list:blox_test.SetpointProfile.Block.points)
  return points_;
}

// bool enabled = 3;
inline void Block::clear_enabled() {
  enabled_ = false;
}
inline bool Block::_internal_enabled() const {
  return enabled_;
}
inline bool Block::enabled() const {
  // @@protoc_insertion_point(field_get:blox_test.SetpointProfile.Block.enabled)
  return _internal_enabled();
}
inline void Block::_internal_set_enabled(bool value) {
  
  enabled_ = value;
}
inline void Block::set_enabled(bool value) {
  _internal_set_enabled(value);
  // @@protoc_insertion_point(field_set:blox_test.SetpointProfile.Block.enabled)
}

// uint32 targetId = 4 [(.nanopb) = {
inline void Block::clear_targetid() {
  targetid_ = 0u;
}
inline uint32_t Block::_internal_targetid() const {
  return targetid_;
}
inline uint32_t Block::targetid() const {
  // @@protoc_insertion_point(field_get:blox_test.SetpointProfile.Block.targetId)
  return _internal_targetid();
}
inline void Block::_internal_set_targetid(uint32_t value) {
  
  targetid_ = value;
}
inline void Block::set_targetid(uint32_t value) {
  _internal_set_targetid(value);
  // @@protoc_insertion_point(field_set:blox_test.SetpointProfile.Block.targetId)
}

// uint32 drivenTargetId = 5 [(.nanopb) = {
inline void Block::clear_driventargetid() {
  driventargetid_ = 0u;
}
inline uint32_t Block::_internal_driventargetid() const {
  return driventargetid_;
}
inline uint32_t Block::driventargetid() const {
  // @@protoc_insertion_point(field_get:blox_test.SetpointProfile.Block.drivenTargetId)
  return _internal_driventargetid();
}
inline void Block::_internal_set_driventargetid(uint32_t value) {
  
  driventargetid_ = value;
}
inline void Block::set_driventargetid(uint32_t value) {
  _internal_set_driventargetid(value);
  // @@protoc_insertion_point(field_set:blox_test.SetpointProfile.Block.drivenTargetId)
}

// uint32 start = 6;
inline void Block::clear_start() {
  start_ = 0u;
}
inline uint32_t Block::_internal_start() const {
  return start_;
}
inline uint32_t Block::start() const {
  // @@protoc_insertion_point(field_get:blox_test.SetpointProfile.Block.start)
  return _internal_start();
}
inline void Block::_internal_set_start(uint32_t value) {
  
  start_ = value;
}
inline void Block::set_start(uint32_t value) {
  _internal_set_start(value);
  // @@protoc_insertion_point(field_set:blox_test.SetpointProfile.Block.start)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace SetpointProfile
}  // namespace blox_test

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_SetpointProfile_5ftest_2eproto
