/* Automatically generated nanopb constant definitions */

#include "EdgeCase.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Settings_fields[3] = {
    PB_FIELD(  1, FIXED64 , SINGULAR, STATIC  , FIRST, blox_Settings, address, address, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Settings, offset, address, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_State_fields[3] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, blox_State, value, value, 0),
    PB_FIELD(  2, BOOL    , SINGULAR, STATIC  , OTHER, blox_State, connected, value, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_NestedLink_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_NestedLink, connection, connection, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_EdgeCase_fields[11] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, blox_EdgeCase, settings, settings, &blox_Settings_fields),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, blox_EdgeCase, state, settings, &blox_State_fields),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase, link, state, 0),
    PB_FIELD(  4, MESSAGE , REPEATED, CALLBACK, OTHER, blox_EdgeCase, additionalLinks, link, &blox_NestedLink_fields),
    PB_FIELD(  5, FLOAT   , REPEATED, CALLBACK, OTHER, blox_EdgeCase, listValues, additionalLinks, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase, deltaV, listValues, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase, logged, deltaV, 0),
    PB_FIELD(  8, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase, unLogged, logged, 0),
    PB_FIELD(  9, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase, drivenDevice, unLogged, 0),
    PB_FIELD( 99, UINT32  , REPEATED, STATIC  , OTHER, blox_EdgeCase, strippedFields, drivenDevice, 0),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_EdgeCase, settings) < 65536 && pb_membersize(blox_EdgeCase, state) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_Settings_blox_State_blox_NestedLink_blox_EdgeCase)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_EdgeCase, settings) < 256 && pb_membersize(blox_EdgeCase, state) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_Settings_blox_State_blox_NestedLink_blox_EdgeCase)
#endif


/* @@protoc_insertion_point(eof) */
