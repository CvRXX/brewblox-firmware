// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Pid_test.proto

#ifndef PROTOBUF_INCLUDED_Pid_5ftest_2eproto
#define PROTOBUF_INCLUDED_Pid_5ftest_2eproto

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
#include "SetpointSensorPair_test.pb.h"
// @@protoc_insertion_point(includes)
#define PROTOBUF_INTERNAL_EXPORT_protobuf_Pid_5ftest_2eproto 

namespace protobuf_Pid_5ftest_2eproto {
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
}  // namespace protobuf_Pid_5ftest_2eproto
namespace blox {
class Pid;
class PidDefaultTypeInternal;
extern PidDefaultTypeInternal _Pid_default_instance_;
}  // namespace blox
namespace google {
namespace protobuf {
template<> ::blox::Pid* Arena::CreateMaybeMessage<::blox::Pid>(Arena*);
}  // namespace protobuf
}  // namespace google
namespace blox {

// ===================================================================

class Pid : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:blox.Pid) */ {
 public:
  Pid();
  virtual ~Pid();

  Pid(const Pid& from);

  inline Pid& operator=(const Pid& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Pid(Pid&& from) noexcept
    : Pid() {
    *this = ::std::move(from);
  }

  inline Pid& operator=(Pid&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor();
  static const Pid& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Pid* internal_default_instance() {
    return reinterpret_cast<const Pid*>(
               &_Pid_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Pid* other);
  friend void swap(Pid& a, Pid& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Pid* New() const final {
    return CreateMaybeMessage<Pid>(NULL);
  }

  Pid* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Pid>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Pid& from);
  void MergeFrom(const Pid& from);
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
  void InternalSwap(Pid* other);
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

  // repeated uint32 strippedFields = 99 [(.nanopb_test) = {
  int strippedfields_size() const;
  void clear_strippedfields();
  static const int kStrippedFieldsFieldNumber = 99;
  ::google::protobuf::uint32 strippedfields(int index) const;
  void set_strippedfields(int index, ::google::protobuf::uint32 value);
  void add_strippedfields(::google::protobuf::uint32 value);
  const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      strippedfields() const;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_strippedfields();

  // uint32 inputId = 1 [(.nanopb_test) = {
  void clear_inputid();
  static const int kInputIdFieldNumber = 1;
  ::google::protobuf::uint32 inputid() const;
  void set_inputid(::google::protobuf::uint32 value);

  // uint32 outputId = 2 [(.nanopb_test) = {
  void clear_outputid();
  static const int kOutputIdFieldNumber = 2;
  ::google::protobuf::uint32 outputid() const;
  void set_outputid(::google::protobuf::uint32 value);

  // sint32 inputValue = 5 [(.nanopb_test) = {
  void clear_inputvalue();
  static const int kInputValueFieldNumber = 5;
  ::google::protobuf::int32 inputvalue() const;
  void set_inputvalue(::google::protobuf::int32 value);

  // sint32 inputSetting = 6 [(.nanopb_test) = {
  void clear_inputsetting();
  static const int kInputSettingFieldNumber = 6;
  ::google::protobuf::int32 inputsetting() const;
  void set_inputsetting(::google::protobuf::int32 value);

  // sint32 outputValue = 7 [(.nanopb_test) = {
  void clear_outputvalue();
  static const int kOutputValueFieldNumber = 7;
  ::google::protobuf::int32 outputvalue() const;
  void set_outputvalue(::google::protobuf::int32 value);

  // sint32 outputSetting = 8 [(.nanopb_test) = {
  void clear_outputsetting();
  static const int kOutputSettingFieldNumber = 8;
  ::google::protobuf::int32 outputsetting() const;
  void set_outputsetting(::google::protobuf::int32 value);

  // sint32 kp = 13 [(.nanopb_test) = {
  void clear_kp();
  static const int kKpFieldNumber = 13;
  ::google::protobuf::int32 kp() const;
  void set_kp(::google::protobuf::int32 value);

  // uint32 ti = 14 [(.nanopb_test) = {
  void clear_ti();
  static const int kTiFieldNumber = 14;
  ::google::protobuf::uint32 ti() const;
  void set_ti(::google::protobuf::uint32 value);

  // uint32 td = 15 [(.nanopb_test) = {
  void clear_td();
  static const int kTdFieldNumber = 15;
  ::google::protobuf::uint32 td() const;
  void set_td(::google::protobuf::uint32 value);

  // sint32 p = 16 [(.nanopb_test) = {
  void clear_p();
  static const int kPFieldNumber = 16;
  ::google::protobuf::int32 p() const;
  void set_p(::google::protobuf::int32 value);

  // bool enabled = 11 [(.brewblox_test) = {
  void clear_enabled();
  static const int kEnabledFieldNumber = 11;
  bool enabled() const;
  void set_enabled(bool value);

  // bool active = 12 [(.brewblox_test) = {
  void clear_active();
  static const int kActiveFieldNumber = 12;
  bool active() const;
  void set_active(bool value);

  // bool boilModeActive = 26 [(.brewblox_test) = {
  void clear_boilmodeactive();
  static const int kBoilModeActiveFieldNumber = 26;
  bool boilmodeactive() const;
  void set_boilmodeactive(bool value);

  // sint32 i = 17 [(.nanopb_test) = {
  void clear_i();
  static const int kIFieldNumber = 17;
  ::google::protobuf::int32 i() const;
  void set_i(::google::protobuf::int32 value);

  // sint32 d = 18 [(.nanopb_test) = {
  void clear_d();
  static const int kDFieldNumber = 18;
  ::google::protobuf::int32 d() const;
  void set_d(::google::protobuf::int32 value);

  // sint32 error = 19 [(.nanopb_test) = {
  void clear_error();
  static const int kErrorFieldNumber = 19;
  ::google::protobuf::int32 error() const;
  void set_error(::google::protobuf::int32 value);

  // sint32 integral = 20 [(.nanopb_test) = {
  void clear_integral();
  static const int kIntegralFieldNumber = 20;
  ::google::protobuf::int32 integral() const;
  void set_integral(::google::protobuf::int32 value);

  // sint32 derivative = 21 [(.nanopb_test) = {
  void clear_derivative();
  static const int kDerivativeFieldNumber = 21;
  ::google::protobuf::int32 derivative() const;
  void set_derivative(::google::protobuf::int32 value);

  // uint32 drivenOutputId = 22 [(.nanopb_test) = {
  void clear_drivenoutputid();
  static const int kDrivenOutputIdFieldNumber = 22;
  ::google::protobuf::uint32 drivenoutputid() const;
  void set_drivenoutputid(::google::protobuf::uint32 value);

  // sint32 integralReset = 23 [(.nanopb_test) = {
  void clear_integralreset();
  static const int kIntegralResetFieldNumber = 23;
  ::google::protobuf::int32 integralreset() const;
  void set_integralreset(::google::protobuf::int32 value);

  // sint32 boilPointAdjust = 24 [(.nanopb_test) = {
  void clear_boilpointadjust();
  static const int kBoilPointAdjustFieldNumber = 24;
  ::google::protobuf::int32 boilpointadjust() const;
  void set_boilpointadjust(::google::protobuf::int32 value);

  // sint32 boilMinOutput = 25 [(.nanopb_test) = {
  void clear_boilminoutput();
  static const int kBoilMinOutputFieldNumber = 25;
  ::google::protobuf::int32 boilminoutput() const;
  void set_boilminoutput(::google::protobuf::int32 value);

  // .blox.FilterChoice derivativeFilter = 27 [(.brewblox_test) = {
  void clear_derivativefilter();
  static const int kDerivativeFilterFieldNumber = 27;
  ::blox::FilterChoice derivativefilter() const;
  void set_derivativefilter(::blox::FilterChoice value);

  // @@protoc_insertion_point(class_scope:blox.Pid)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > strippedfields_;
  mutable int _strippedfields_cached_byte_size_;
  ::google::protobuf::uint32 inputid_;
  ::google::protobuf::uint32 outputid_;
  ::google::protobuf::int32 inputvalue_;
  ::google::protobuf::int32 inputsetting_;
  ::google::protobuf::int32 outputvalue_;
  ::google::protobuf::int32 outputsetting_;
  ::google::protobuf::int32 kp_;
  ::google::protobuf::uint32 ti_;
  ::google::protobuf::uint32 td_;
  ::google::protobuf::int32 p_;
  bool enabled_;
  bool active_;
  bool boilmodeactive_;
  ::google::protobuf::int32 i_;
  ::google::protobuf::int32 d_;
  ::google::protobuf::int32 error_;
  ::google::protobuf::int32 integral_;
  ::google::protobuf::int32 derivative_;
  ::google::protobuf::uint32 drivenoutputid_;
  ::google::protobuf::int32 integralreset_;
  ::google::protobuf::int32 boilpointadjust_;
  ::google::protobuf::int32 boilminoutput_;
  int derivativefilter_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::protobuf_Pid_5ftest_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Pid

// uint32 inputId = 1 [(.nanopb_test) = {
inline void Pid::clear_inputid() {
  inputid_ = 0u;
}
inline ::google::protobuf::uint32 Pid::inputid() const {
  // @@protoc_insertion_point(field_get:blox.Pid.inputId)
  return inputid_;
}
inline void Pid::set_inputid(::google::protobuf::uint32 value) {
  
  inputid_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.inputId)
}

// uint32 outputId = 2 [(.nanopb_test) = {
inline void Pid::clear_outputid() {
  outputid_ = 0u;
}
inline ::google::protobuf::uint32 Pid::outputid() const {
  // @@protoc_insertion_point(field_get:blox.Pid.outputId)
  return outputid_;
}
inline void Pid::set_outputid(::google::protobuf::uint32 value) {
  
  outputid_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.outputId)
}

// sint32 inputValue = 5 [(.nanopb_test) = {
inline void Pid::clear_inputvalue() {
  inputvalue_ = 0;
}
inline ::google::protobuf::int32 Pid::inputvalue() const {
  // @@protoc_insertion_point(field_get:blox.Pid.inputValue)
  return inputvalue_;
}
inline void Pid::set_inputvalue(::google::protobuf::int32 value) {
  
  inputvalue_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.inputValue)
}

// sint32 inputSetting = 6 [(.nanopb_test) = {
inline void Pid::clear_inputsetting() {
  inputsetting_ = 0;
}
inline ::google::protobuf::int32 Pid::inputsetting() const {
  // @@protoc_insertion_point(field_get:blox.Pid.inputSetting)
  return inputsetting_;
}
inline void Pid::set_inputsetting(::google::protobuf::int32 value) {
  
  inputsetting_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.inputSetting)
}

// sint32 outputValue = 7 [(.nanopb_test) = {
inline void Pid::clear_outputvalue() {
  outputvalue_ = 0;
}
inline ::google::protobuf::int32 Pid::outputvalue() const {
  // @@protoc_insertion_point(field_get:blox.Pid.outputValue)
  return outputvalue_;
}
inline void Pid::set_outputvalue(::google::protobuf::int32 value) {
  
  outputvalue_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.outputValue)
}

// sint32 outputSetting = 8 [(.nanopb_test) = {
inline void Pid::clear_outputsetting() {
  outputsetting_ = 0;
}
inline ::google::protobuf::int32 Pid::outputsetting() const {
  // @@protoc_insertion_point(field_get:blox.Pid.outputSetting)
  return outputsetting_;
}
inline void Pid::set_outputsetting(::google::protobuf::int32 value) {
  
  outputsetting_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.outputSetting)
}

// bool enabled = 11 [(.brewblox_test) = {
inline void Pid::clear_enabled() {
  enabled_ = false;
}
inline bool Pid::enabled() const {
  // @@protoc_insertion_point(field_get:blox.Pid.enabled)
  return enabled_;
}
inline void Pid::set_enabled(bool value) {
  
  enabled_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.enabled)
}

// bool active = 12 [(.brewblox_test) = {
inline void Pid::clear_active() {
  active_ = false;
}
inline bool Pid::active() const {
  // @@protoc_insertion_point(field_get:blox.Pid.active)
  return active_;
}
inline void Pid::set_active(bool value) {
  
  active_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.active)
}

// sint32 kp = 13 [(.nanopb_test) = {
inline void Pid::clear_kp() {
  kp_ = 0;
}
inline ::google::protobuf::int32 Pid::kp() const {
  // @@protoc_insertion_point(field_get:blox.Pid.kp)
  return kp_;
}
inline void Pid::set_kp(::google::protobuf::int32 value) {
  
  kp_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.kp)
}

// uint32 ti = 14 [(.nanopb_test) = {
inline void Pid::clear_ti() {
  ti_ = 0u;
}
inline ::google::protobuf::uint32 Pid::ti() const {
  // @@protoc_insertion_point(field_get:blox.Pid.ti)
  return ti_;
}
inline void Pid::set_ti(::google::protobuf::uint32 value) {
  
  ti_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.ti)
}

// uint32 td = 15 [(.nanopb_test) = {
inline void Pid::clear_td() {
  td_ = 0u;
}
inline ::google::protobuf::uint32 Pid::td() const {
  // @@protoc_insertion_point(field_get:blox.Pid.td)
  return td_;
}
inline void Pid::set_td(::google::protobuf::uint32 value) {
  
  td_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.td)
}

// sint32 p = 16 [(.nanopb_test) = {
inline void Pid::clear_p() {
  p_ = 0;
}
inline ::google::protobuf::int32 Pid::p() const {
  // @@protoc_insertion_point(field_get:blox.Pid.p)
  return p_;
}
inline void Pid::set_p(::google::protobuf::int32 value) {
  
  p_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.p)
}

// sint32 i = 17 [(.nanopb_test) = {
inline void Pid::clear_i() {
  i_ = 0;
}
inline ::google::protobuf::int32 Pid::i() const {
  // @@protoc_insertion_point(field_get:blox.Pid.i)
  return i_;
}
inline void Pid::set_i(::google::protobuf::int32 value) {
  
  i_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.i)
}

// sint32 d = 18 [(.nanopb_test) = {
inline void Pid::clear_d() {
  d_ = 0;
}
inline ::google::protobuf::int32 Pid::d() const {
  // @@protoc_insertion_point(field_get:blox.Pid.d)
  return d_;
}
inline void Pid::set_d(::google::protobuf::int32 value) {
  
  d_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.d)
}

// sint32 error = 19 [(.nanopb_test) = {
inline void Pid::clear_error() {
  error_ = 0;
}
inline ::google::protobuf::int32 Pid::error() const {
  // @@protoc_insertion_point(field_get:blox.Pid.error)
  return error_;
}
inline void Pid::set_error(::google::protobuf::int32 value) {
  
  error_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.error)
}

// sint32 integral = 20 [(.nanopb_test) = {
inline void Pid::clear_integral() {
  integral_ = 0;
}
inline ::google::protobuf::int32 Pid::integral() const {
  // @@protoc_insertion_point(field_get:blox.Pid.integral)
  return integral_;
}
inline void Pid::set_integral(::google::protobuf::int32 value) {
  
  integral_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.integral)
}

// sint32 derivative = 21 [(.nanopb_test) = {
inline void Pid::clear_derivative() {
  derivative_ = 0;
}
inline ::google::protobuf::int32 Pid::derivative() const {
  // @@protoc_insertion_point(field_get:blox.Pid.derivative)
  return derivative_;
}
inline void Pid::set_derivative(::google::protobuf::int32 value) {
  
  derivative_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.derivative)
}

// uint32 drivenOutputId = 22 [(.nanopb_test) = {
inline void Pid::clear_drivenoutputid() {
  drivenoutputid_ = 0u;
}
inline ::google::protobuf::uint32 Pid::drivenoutputid() const {
  // @@protoc_insertion_point(field_get:blox.Pid.drivenOutputId)
  return drivenoutputid_;
}
inline void Pid::set_drivenoutputid(::google::protobuf::uint32 value) {
  
  drivenoutputid_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.drivenOutputId)
}

// sint32 integralReset = 23 [(.nanopb_test) = {
inline void Pid::clear_integralreset() {
  integralreset_ = 0;
}
inline ::google::protobuf::int32 Pid::integralreset() const {
  // @@protoc_insertion_point(field_get:blox.Pid.integralReset)
  return integralreset_;
}
inline void Pid::set_integralreset(::google::protobuf::int32 value) {
  
  integralreset_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.integralReset)
}

// sint32 boilPointAdjust = 24 [(.nanopb_test) = {
inline void Pid::clear_boilpointadjust() {
  boilpointadjust_ = 0;
}
inline ::google::protobuf::int32 Pid::boilpointadjust() const {
  // @@protoc_insertion_point(field_get:blox.Pid.boilPointAdjust)
  return boilpointadjust_;
}
inline void Pid::set_boilpointadjust(::google::protobuf::int32 value) {
  
  boilpointadjust_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.boilPointAdjust)
}

// sint32 boilMinOutput = 25 [(.nanopb_test) = {
inline void Pid::clear_boilminoutput() {
  boilminoutput_ = 0;
}
inline ::google::protobuf::int32 Pid::boilminoutput() const {
  // @@protoc_insertion_point(field_get:blox.Pid.boilMinOutput)
  return boilminoutput_;
}
inline void Pid::set_boilminoutput(::google::protobuf::int32 value) {
  
  boilminoutput_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.boilMinOutput)
}

// bool boilModeActive = 26 [(.brewblox_test) = {
inline void Pid::clear_boilmodeactive() {
  boilmodeactive_ = false;
}
inline bool Pid::boilmodeactive() const {
  // @@protoc_insertion_point(field_get:blox.Pid.boilModeActive)
  return boilmodeactive_;
}
inline void Pid::set_boilmodeactive(bool value) {
  
  boilmodeactive_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.boilModeActive)
}

// .blox.FilterChoice derivativeFilter = 27 [(.brewblox_test) = {
inline void Pid::clear_derivativefilter() {
  derivativefilter_ = 0;
}
inline ::blox::FilterChoice Pid::derivativefilter() const {
  // @@protoc_insertion_point(field_get:blox.Pid.derivativeFilter)
  return static_cast< ::blox::FilterChoice >(derivativefilter_);
}
inline void Pid::set_derivativefilter(::blox::FilterChoice value) {
  
  derivativefilter_ = value;
  // @@protoc_insertion_point(field_set:blox.Pid.derivativeFilter)
}

// repeated uint32 strippedFields = 99 [(.nanopb_test) = {
inline int Pid::strippedfields_size() const {
  return strippedfields_.size();
}
inline void Pid::clear_strippedfields() {
  strippedfields_.Clear();
}
inline ::google::protobuf::uint32 Pid::strippedfields(int index) const {
  // @@protoc_insertion_point(field_get:blox.Pid.strippedFields)
  return strippedfields_.Get(index);
}
inline void Pid::set_strippedfields(int index, ::google::protobuf::uint32 value) {
  strippedfields_.Set(index, value);
  // @@protoc_insertion_point(field_set:blox.Pid.strippedFields)
}
inline void Pid::add_strippedfields(::google::protobuf::uint32 value) {
  strippedfields_.Add(value);
  // @@protoc_insertion_point(field_add:blox.Pid.strippedFields)
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
Pid::strippedfields() const {
  // @@protoc_insertion_point(field_list:blox.Pid.strippedFields)
  return strippedfields_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
Pid::mutable_strippedfields() {
  // @@protoc_insertion_point(field_mutable_list:blox.Pid.strippedFields)
  return &strippedfields_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_INCLUDED_Pid_5ftest_2eproto
