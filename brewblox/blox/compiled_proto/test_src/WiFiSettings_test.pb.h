// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: WiFiSettings_test.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_WiFiSettings_5ftest_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_WiFiSettings_5ftest_2eproto

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
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "brewblox_test.pb.h"
#include "nanopb_test.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_WiFiSettings_5ftest_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_WiFiSettings_5ftest_2eproto {
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
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_WiFiSettings_5ftest_2eproto;
namespace blox {
class WiFiSettings;
struct WiFiSettingsDefaultTypeInternal;
extern WiFiSettingsDefaultTypeInternal _WiFiSettings_default_instance_;
}  // namespace blox
PROTOBUF_NAMESPACE_OPEN
template<> ::blox::WiFiSettings* Arena::CreateMaybeMessage<::blox::WiFiSettings>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace blox {

enum WiFiSettings_WlanSecurity : int {
  WiFiSettings_WlanSecurity_WLAN_SEC_UNSEC = 0,
  WiFiSettings_WlanSecurity_WLAN_SEC_WEP = 1,
  WiFiSettings_WlanSecurity_WLAN_SEC_WPA = 2,
  WiFiSettings_WlanSecurity_WLAN_SEC_WPA2 = 3,
  WiFiSettings_WlanSecurity_WLAN_SEC_WPA_ENTERPRISE = 4,
  WiFiSettings_WlanSecurity_WLAN_SEC_WPA2_ENTERPRISE = 5,
  WiFiSettings_WlanSecurity_WLAN_SEC_NOT_SET = 255,
  WiFiSettings_WlanSecurity_WiFiSettings_WlanSecurity_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  WiFiSettings_WlanSecurity_WiFiSettings_WlanSecurity_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool WiFiSettings_WlanSecurity_IsValid(int value);
constexpr WiFiSettings_WlanSecurity WiFiSettings_WlanSecurity_WlanSecurity_MIN = WiFiSettings_WlanSecurity_WLAN_SEC_UNSEC;
constexpr WiFiSettings_WlanSecurity WiFiSettings_WlanSecurity_WlanSecurity_MAX = WiFiSettings_WlanSecurity_WLAN_SEC_NOT_SET;
constexpr int WiFiSettings_WlanSecurity_WlanSecurity_ARRAYSIZE = WiFiSettings_WlanSecurity_WlanSecurity_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* WiFiSettings_WlanSecurity_descriptor();
template<typename T>
inline const std::string& WiFiSettings_WlanSecurity_Name(T enum_t_value) {
  static_assert(::std::is_same<T, WiFiSettings_WlanSecurity>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function WiFiSettings_WlanSecurity_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    WiFiSettings_WlanSecurity_descriptor(), enum_t_value);
}
inline bool WiFiSettings_WlanSecurity_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, WiFiSettings_WlanSecurity* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<WiFiSettings_WlanSecurity>(
    WiFiSettings_WlanSecurity_descriptor(), name, value);
}
enum WiFiSettings_WlanCipher : int {
  WiFiSettings_WlanCipher_WLAN_CIPHER_NOT_SET = 0,
  WiFiSettings_WlanCipher_WLAN_CIPHER_AES = 1,
  WiFiSettings_WlanCipher_WLAN_CIPHER_TKIP = 2,
  WiFiSettings_WlanCipher_WLAN_CIPHER_AES_OR_TKIP = 3,
  WiFiSettings_WlanCipher_WiFiSettings_WlanCipher_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::min(),
  WiFiSettings_WlanCipher_WiFiSettings_WlanCipher_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::PROTOBUF_NAMESPACE_ID::int32>::max()
};
bool WiFiSettings_WlanCipher_IsValid(int value);
constexpr WiFiSettings_WlanCipher WiFiSettings_WlanCipher_WlanCipher_MIN = WiFiSettings_WlanCipher_WLAN_CIPHER_NOT_SET;
constexpr WiFiSettings_WlanCipher WiFiSettings_WlanCipher_WlanCipher_MAX = WiFiSettings_WlanCipher_WLAN_CIPHER_AES_OR_TKIP;
constexpr int WiFiSettings_WlanCipher_WlanCipher_ARRAYSIZE = WiFiSettings_WlanCipher_WlanCipher_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* WiFiSettings_WlanCipher_descriptor();
template<typename T>
inline const std::string& WiFiSettings_WlanCipher_Name(T enum_t_value) {
  static_assert(::std::is_same<T, WiFiSettings_WlanCipher>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function WiFiSettings_WlanCipher_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    WiFiSettings_WlanCipher_descriptor(), enum_t_value);
}
inline bool WiFiSettings_WlanCipher_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, WiFiSettings_WlanCipher* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<WiFiSettings_WlanCipher>(
    WiFiSettings_WlanCipher_descriptor(), name, value);
}
// ===================================================================

class WiFiSettings final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:blox.WiFiSettings) */ {
 public:
  inline WiFiSettings() : WiFiSettings(nullptr) {}
  ~WiFiSettings() override;
  explicit constexpr WiFiSettings(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  WiFiSettings(const WiFiSettings& from);
  WiFiSettings(WiFiSettings&& from) noexcept
    : WiFiSettings() {
    *this = ::std::move(from);
  }

  inline WiFiSettings& operator=(const WiFiSettings& from) {
    CopyFrom(from);
    return *this;
  }
  inline WiFiSettings& operator=(WiFiSettings&& from) noexcept {
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
  static const WiFiSettings& default_instance() {
    return *internal_default_instance();
  }
  static inline const WiFiSettings* internal_default_instance() {
    return reinterpret_cast<const WiFiSettings*>(
               &_WiFiSettings_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(WiFiSettings& a, WiFiSettings& b) {
    a.Swap(&b);
  }
  inline void Swap(WiFiSettings* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(WiFiSettings* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline WiFiSettings* New() const final {
    return new WiFiSettings();
  }

  WiFiSettings* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<WiFiSettings>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const WiFiSettings& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const WiFiSettings& from);
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
  void InternalSwap(WiFiSettings* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "blox.WiFiSettings";
  }
  protected:
  explicit WiFiSettings(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef WiFiSettings_WlanSecurity WlanSecurity;
  static constexpr WlanSecurity WLAN_SEC_UNSEC =
    WiFiSettings_WlanSecurity_WLAN_SEC_UNSEC;
  static constexpr WlanSecurity WLAN_SEC_WEP =
    WiFiSettings_WlanSecurity_WLAN_SEC_WEP;
  static constexpr WlanSecurity WLAN_SEC_WPA =
    WiFiSettings_WlanSecurity_WLAN_SEC_WPA;
  static constexpr WlanSecurity WLAN_SEC_WPA2 =
    WiFiSettings_WlanSecurity_WLAN_SEC_WPA2;
  static constexpr WlanSecurity WLAN_SEC_WPA_ENTERPRISE =
    WiFiSettings_WlanSecurity_WLAN_SEC_WPA_ENTERPRISE;
  static constexpr WlanSecurity WLAN_SEC_WPA2_ENTERPRISE =
    WiFiSettings_WlanSecurity_WLAN_SEC_WPA2_ENTERPRISE;
  static constexpr WlanSecurity WLAN_SEC_NOT_SET =
    WiFiSettings_WlanSecurity_WLAN_SEC_NOT_SET;
  static inline bool WlanSecurity_IsValid(int value) {
    return WiFiSettings_WlanSecurity_IsValid(value);
  }
  static constexpr WlanSecurity WlanSecurity_MIN =
    WiFiSettings_WlanSecurity_WlanSecurity_MIN;
  static constexpr WlanSecurity WlanSecurity_MAX =
    WiFiSettings_WlanSecurity_WlanSecurity_MAX;
  static constexpr int WlanSecurity_ARRAYSIZE =
    WiFiSettings_WlanSecurity_WlanSecurity_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  WlanSecurity_descriptor() {
    return WiFiSettings_WlanSecurity_descriptor();
  }
  template<typename T>
  static inline const std::string& WlanSecurity_Name(T enum_t_value) {
    static_assert(::std::is_same<T, WlanSecurity>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function WlanSecurity_Name.");
    return WiFiSettings_WlanSecurity_Name(enum_t_value);
  }
  static inline bool WlanSecurity_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      WlanSecurity* value) {
    return WiFiSettings_WlanSecurity_Parse(name, value);
  }

  typedef WiFiSettings_WlanCipher WlanCipher;
  static constexpr WlanCipher WLAN_CIPHER_NOT_SET =
    WiFiSettings_WlanCipher_WLAN_CIPHER_NOT_SET;
  static constexpr WlanCipher WLAN_CIPHER_AES =
    WiFiSettings_WlanCipher_WLAN_CIPHER_AES;
  static constexpr WlanCipher WLAN_CIPHER_TKIP =
    WiFiSettings_WlanCipher_WLAN_CIPHER_TKIP;
  static constexpr WlanCipher WLAN_CIPHER_AES_OR_TKIP =
    WiFiSettings_WlanCipher_WLAN_CIPHER_AES_OR_TKIP;
  static inline bool WlanCipher_IsValid(int value) {
    return WiFiSettings_WlanCipher_IsValid(value);
  }
  static constexpr WlanCipher WlanCipher_MIN =
    WiFiSettings_WlanCipher_WlanCipher_MIN;
  static constexpr WlanCipher WlanCipher_MAX =
    WiFiSettings_WlanCipher_WlanCipher_MAX;
  static constexpr int WlanCipher_ARRAYSIZE =
    WiFiSettings_WlanCipher_WlanCipher_ARRAYSIZE;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  WlanCipher_descriptor() {
    return WiFiSettings_WlanCipher_descriptor();
  }
  template<typename T>
  static inline const std::string& WlanCipher_Name(T enum_t_value) {
    static_assert(::std::is_same<T, WlanCipher>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function WlanCipher_Name.");
    return WiFiSettings_WlanCipher_Name(enum_t_value);
  }
  static inline bool WlanCipher_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      WlanCipher* value) {
    return WiFiSettings_WlanCipher_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  enum : int {
    kSsidFieldNumber = 1,
    kPasswordFieldNumber = 2,
    kIpFieldNumber = 6,
    kSecurityFieldNumber = 3,
    kCipherFieldNumber = 4,
    kSignalFieldNumber = 5,
  };
  // string ssid = 1 [(.nanopb_test) = {
  void clear_ssid();
  const std::string& ssid() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_ssid(ArgT0&& arg0, ArgT... args);
  std::string* mutable_ssid();
  PROTOBUF_MUST_USE_RESULT std::string* release_ssid();
  void set_allocated_ssid(std::string* ssid);
  private:
  const std::string& _internal_ssid() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_ssid(const std::string& value);
  std::string* _internal_mutable_ssid();
  public:

  // string password = 2 [(.nanopb_test) = {
  void clear_password();
  const std::string& password() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_password(ArgT0&& arg0, ArgT... args);
  std::string* mutable_password();
  PROTOBUF_MUST_USE_RESULT std::string* release_password();
  void set_allocated_password(std::string* password);
  private:
  const std::string& _internal_password() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_password(const std::string& value);
  std::string* _internal_mutable_password();
  public:

  // string ip = 6 [(.nanopb_test) = {
  void clear_ip();
  const std::string& ip() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_ip(ArgT0&& arg0, ArgT... args);
  std::string* mutable_ip();
  PROTOBUF_MUST_USE_RESULT std::string* release_ip();
  void set_allocated_ip(std::string* ip);
  private:
  const std::string& _internal_ip() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_ip(const std::string& value);
  std::string* _internal_mutable_ip();
  public:

  // .blox.WiFiSettings.WlanSecurity security = 3;
  void clear_security();
  ::blox::WiFiSettings_WlanSecurity security() const;
  void set_security(::blox::WiFiSettings_WlanSecurity value);
  private:
  ::blox::WiFiSettings_WlanSecurity _internal_security() const;
  void _internal_set_security(::blox::WiFiSettings_WlanSecurity value);
  public:

  // .blox.WiFiSettings.WlanCipher cipher = 4;
  void clear_cipher();
  ::blox::WiFiSettings_WlanCipher cipher() const;
  void set_cipher(::blox::WiFiSettings_WlanCipher value);
  private:
  ::blox::WiFiSettings_WlanCipher _internal_cipher() const;
  void _internal_set_cipher(::blox::WiFiSettings_WlanCipher value);
  public:

  // int32 signal = 5 [(.nanopb_test) = {
  void clear_signal();
  ::PROTOBUF_NAMESPACE_ID::int32 signal() const;
  void set_signal(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_signal() const;
  void _internal_set_signal(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:blox.WiFiSettings)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr ssid_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr password_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr ip_;
  int security_;
  int cipher_;
  ::PROTOBUF_NAMESPACE_ID::int32 signal_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_WiFiSettings_5ftest_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// WiFiSettings

// string ssid = 1 [(.nanopb_test) = {
inline void WiFiSettings::clear_ssid() {
  ssid_.ClearToEmpty();
}
inline const std::string& WiFiSettings::ssid() const {
  // @@protoc_insertion_point(field_get:blox.WiFiSettings.ssid)
  return _internal_ssid();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void WiFiSettings::set_ssid(ArgT0&& arg0, ArgT... args) {
 
 ssid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:blox.WiFiSettings.ssid)
}
inline std::string* WiFiSettings::mutable_ssid() {
  std::string* _s = _internal_mutable_ssid();
  // @@protoc_insertion_point(field_mutable:blox.WiFiSettings.ssid)
  return _s;
}
inline const std::string& WiFiSettings::_internal_ssid() const {
  return ssid_.Get();
}
inline void WiFiSettings::_internal_set_ssid(const std::string& value) {
  
  ssid_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* WiFiSettings::_internal_mutable_ssid() {
  
  return ssid_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* WiFiSettings::release_ssid() {
  // @@protoc_insertion_point(field_release:blox.WiFiSettings.ssid)
  return ssid_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void WiFiSettings::set_allocated_ssid(std::string* ssid) {
  if (ssid != nullptr) {
    
  } else {
    
  }
  ssid_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ssid,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:blox.WiFiSettings.ssid)
}

// string password = 2 [(.nanopb_test) = {
inline void WiFiSettings::clear_password() {
  password_.ClearToEmpty();
}
inline const std::string& WiFiSettings::password() const {
  // @@protoc_insertion_point(field_get:blox.WiFiSettings.password)
  return _internal_password();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void WiFiSettings::set_password(ArgT0&& arg0, ArgT... args) {
 
 password_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:blox.WiFiSettings.password)
}
inline std::string* WiFiSettings::mutable_password() {
  std::string* _s = _internal_mutable_password();
  // @@protoc_insertion_point(field_mutable:blox.WiFiSettings.password)
  return _s;
}
inline const std::string& WiFiSettings::_internal_password() const {
  return password_.Get();
}
inline void WiFiSettings::_internal_set_password(const std::string& value) {
  
  password_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* WiFiSettings::_internal_mutable_password() {
  
  return password_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* WiFiSettings::release_password() {
  // @@protoc_insertion_point(field_release:blox.WiFiSettings.password)
  return password_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void WiFiSettings::set_allocated_password(std::string* password) {
  if (password != nullptr) {
    
  } else {
    
  }
  password_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), password,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:blox.WiFiSettings.password)
}

// .blox.WiFiSettings.WlanSecurity security = 3;
inline void WiFiSettings::clear_security() {
  security_ = 0;
}
inline ::blox::WiFiSettings_WlanSecurity WiFiSettings::_internal_security() const {
  return static_cast< ::blox::WiFiSettings_WlanSecurity >(security_);
}
inline ::blox::WiFiSettings_WlanSecurity WiFiSettings::security() const {
  // @@protoc_insertion_point(field_get:blox.WiFiSettings.security)
  return _internal_security();
}
inline void WiFiSettings::_internal_set_security(::blox::WiFiSettings_WlanSecurity value) {
  
  security_ = value;
}
inline void WiFiSettings::set_security(::blox::WiFiSettings_WlanSecurity value) {
  _internal_set_security(value);
  // @@protoc_insertion_point(field_set:blox.WiFiSettings.security)
}

// .blox.WiFiSettings.WlanCipher cipher = 4;
inline void WiFiSettings::clear_cipher() {
  cipher_ = 0;
}
inline ::blox::WiFiSettings_WlanCipher WiFiSettings::_internal_cipher() const {
  return static_cast< ::blox::WiFiSettings_WlanCipher >(cipher_);
}
inline ::blox::WiFiSettings_WlanCipher WiFiSettings::cipher() const {
  // @@protoc_insertion_point(field_get:blox.WiFiSettings.cipher)
  return _internal_cipher();
}
inline void WiFiSettings::_internal_set_cipher(::blox::WiFiSettings_WlanCipher value) {
  
  cipher_ = value;
}
inline void WiFiSettings::set_cipher(::blox::WiFiSettings_WlanCipher value) {
  _internal_set_cipher(value);
  // @@protoc_insertion_point(field_set:blox.WiFiSettings.cipher)
}

// int32 signal = 5 [(.nanopb_test) = {
inline void WiFiSettings::clear_signal() {
  signal_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WiFiSettings::_internal_signal() const {
  return signal_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 WiFiSettings::signal() const {
  // @@protoc_insertion_point(field_get:blox.WiFiSettings.signal)
  return _internal_signal();
}
inline void WiFiSettings::_internal_set_signal(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  signal_ = value;
}
inline void WiFiSettings::set_signal(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_signal(value);
  // @@protoc_insertion_point(field_set:blox.WiFiSettings.signal)
}

// string ip = 6 [(.nanopb_test) = {
inline void WiFiSettings::clear_ip() {
  ip_.ClearToEmpty();
}
inline const std::string& WiFiSettings::ip() const {
  // @@protoc_insertion_point(field_get:blox.WiFiSettings.ip)
  return _internal_ip();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void WiFiSettings::set_ip(ArgT0&& arg0, ArgT... args) {
 
 ip_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:blox.WiFiSettings.ip)
}
inline std::string* WiFiSettings::mutable_ip() {
  std::string* _s = _internal_mutable_ip();
  // @@protoc_insertion_point(field_mutable:blox.WiFiSettings.ip)
  return _s;
}
inline const std::string& WiFiSettings::_internal_ip() const {
  return ip_.Get();
}
inline void WiFiSettings::_internal_set_ip(const std::string& value) {
  
  ip_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* WiFiSettings::_internal_mutable_ip() {
  
  return ip_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* WiFiSettings::release_ip() {
  // @@protoc_insertion_point(field_release:blox.WiFiSettings.ip)
  return ip_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
}
inline void WiFiSettings::set_allocated_ip(std::string* ip) {
  if (ip != nullptr) {
    
  } else {
    
  }
  ip_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ip,
      GetArenaForAllocation());
  // @@protoc_insertion_point(field_set_allocated:blox.WiFiSettings.ip)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace blox

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::blox::WiFiSettings_WlanSecurity> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::WiFiSettings_WlanSecurity>() {
  return ::blox::WiFiSettings_WlanSecurity_descriptor();
}
template <> struct is_proto_enum< ::blox::WiFiSettings_WlanCipher> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::blox::WiFiSettings_WlanCipher>() {
  return ::blox::WiFiSettings_WlanCipher_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_WiFiSettings_5ftest_2eproto
