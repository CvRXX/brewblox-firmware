/* Automatically generated nanopb header */

#ifndef PB_BLOX_WIFISETTINGS_WIFISETTINGS_PB_H_INCLUDED
#define PB_BLOX_WIFISETTINGS_WIFISETTINGS_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _blox_WiFiSettings_Security {
    blox_WiFiSettings_Security_WLAN_SEC_UNSEC = 0,
    blox_WiFiSettings_Security_WLAN_SEC_WEP = 1,
    blox_WiFiSettings_Security_WLAN_SEC_WPA = 2,
    blox_WiFiSettings_Security_WLAN_SEC_WPA2 = 3,
    blox_WiFiSettings_Security_WLAN_SEC_WPA_ENTERPRISE = 4,
    blox_WiFiSettings_Security_WLAN_SEC_WPA2_ENTERPRISE = 5,
    blox_WiFiSettings_Security_WLAN_SEC_NOT_SET = 255
} blox_WiFiSettings_Security;
#define _blox_WiFiSettings_Security_MIN blox_WiFiSettings_Security_WLAN_SEC_UNSEC
#define _blox_WiFiSettings_Security_MAX blox_WiFiSettings_Security_WLAN_SEC_NOT_SET
#define _blox_WiFiSettings_Security_ARRAYSIZE ((blox_WiFiSettings_Security)(blox_WiFiSettings_Security_WLAN_SEC_NOT_SET+1))

typedef enum _blox_WiFiSettings_Cipher {
    blox_WiFiSettings_Cipher_WLAN_CIPHER_NOT_SET = 0,
    blox_WiFiSettings_Cipher_WLAN_CIPHER_AES = 1,
    blox_WiFiSettings_Cipher_WLAN_CIPHER_TKIP = 2,
    blox_WiFiSettings_Cipher_WLAN_CIPHER_AES_OR_TKIP = 3
} blox_WiFiSettings_Cipher;
#define _blox_WiFiSettings_Cipher_MIN blox_WiFiSettings_Cipher_WLAN_CIPHER_NOT_SET
#define _blox_WiFiSettings_Cipher_MAX blox_WiFiSettings_Cipher_WLAN_CIPHER_AES_OR_TKIP
#define _blox_WiFiSettings_Cipher_ARRAYSIZE ((blox_WiFiSettings_Cipher)(blox_WiFiSettings_Cipher_WLAN_CIPHER_AES_OR_TKIP+1))

/* Struct definitions */
typedef struct _blox_WiFiSettings_Block {
    char ssid[33];
    char password[64];
    blox_WiFiSettings_Security security;
    blox_WiFiSettings_Cipher cipher;
    int8_t signal;
/* @@protoc_insertion_point(struct:blox_WiFiSettings_Block) */
} blox_WiFiSettings_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_WiFiSettings_Block_init_default     {"", "", _blox_WiFiSettings_Security_MIN, _blox_WiFiSettings_Cipher_MIN, 0}
#define blox_WiFiSettings_Block_init_zero        {"", "", _blox_WiFiSettings_Security_MIN, _blox_WiFiSettings_Cipher_MIN, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_WiFiSettings_Block_ssid_tag         1
#define blox_WiFiSettings_Block_password_tag     2
#define blox_WiFiSettings_Block_security_tag     3
#define blox_WiFiSettings_Block_cipher_tag       4
#define blox_WiFiSettings_Block_signal_tag       5

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_WiFiSettings_Block_fields[6];

/* Maximum encoded size of messages (where known) */
#define blox_WiFiSettings_Block_size             117

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define WIFISETTINGS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
