/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.3 at Tue Aug 10 21:42:38 2021. */

#include "WiFiSettings.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_WiFiSettings_fields[7] = {
    PB_FIELD(  1, STRING  , SINGULAR, STATIC  , FIRST, blox_WiFiSettings, ssid, ssid, 0),
    PB_FIELD(  2, STRING  , SINGULAR, STATIC  , OTHER, blox_WiFiSettings, password, ssid, 0),
    PB_FIELD(  3, UENUM   , SINGULAR, STATIC  , OTHER, blox_WiFiSettings, security, password, 0),
    PB_FIELD(  4, UENUM   , SINGULAR, STATIC  , OTHER, blox_WiFiSettings, cipher, security, 0),
    PB_FIELD(  5, INT32   , SINGULAR, STATIC  , OTHER, blox_WiFiSettings, signal, cipher, 0),
    PB_FIELD(  6, STRING  , SINGULAR, STATIC  , OTHER, blox_WiFiSettings, ip, signal, 0),
    PB_LAST_FIELD
};




/* @@protoc_insertion_point(eof) */
