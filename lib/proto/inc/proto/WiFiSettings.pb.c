/* Automatically generated nanopb constant definitions */

#include "WiFiSettings.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_WiFiSettings_Block_fields[6] = {
    PB_FIELD(  1, STRING  , SINGULAR, STATIC  , FIRST, blox_WiFiSettings_Block, ssid, ssid, 0),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, blox_WiFiSettings_Block, password, ssid, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, blox_WiFiSettings_Block, security, password, 0),
    PB_FIELD(  4, UENUM   , SINGULAR, STATIC  , OTHER, blox_WiFiSettings_Block, cipher, security, 0),
    PB_FIELD(  5, INT32   , SINGULAR, STATIC  , OTHER, blox_WiFiSettings_Block, signal, cipher, 0),
    PB_LAST_FIELD
};




/* @@protoc_insertion_point(eof) */
