/* Automatically generated nanopb constant definitions */

#include "EdgeCase.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_EdgeCase_Settings_fields[3] = {
    PB_FIELD(  1, FIXED64 , SINGULAR, STATIC  , FIRST, blox_EdgeCase_Settings, address, address, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase_Settings, offset, address, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_EdgeCase_State_fields[3] = {
    PB_FIELD(  1, SINT32  , SINGULAR, STATIC  , FIRST, blox_EdgeCase_State, value, value, 0),
    PB_FIELD(  2, BOOL    , SINGULAR, STATIC  , OTHER, blox_EdgeCase_State, connected, value, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_EdgeCase_NestedLink_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_EdgeCase_NestedLink, connection, connection, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_EdgeCase_Block_fields[10] = {
    PB_FIELD(  1, MESSAGE , SINGULAR, STATIC  , FIRST, blox_EdgeCase_Block, settings, settings, &blox_EdgeCase_Settings_fields),
    PB_FIELD(  2, MESSAGE , SINGULAR, STATIC  , OTHER, blox_EdgeCase_Block, state, settings, &blox_EdgeCase_State_fields),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase_Block, link, state, 0),
    PB_FIELD(  4, MESSAGE , REPEATED, CALLBACK, OTHER, blox_EdgeCase_Block, additionalLinks, link, &blox_EdgeCase_NestedLink_fields),
    PB_FIELD(  5, FLOAT   , REPEATED, CALLBACK, OTHER, blox_EdgeCase_Block, listValues, additionalLinks, 0),
    PB_FIELD(  6, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase_Block, deltaV, listValues, 0),
    PB_FIELD(  7, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase_Block, logged, deltaV, 0),
    PB_FIELD(  8, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase_Block, unLogged, logged, 0),
    PB_FIELD( 10, UINT32  , SINGULAR, STATIC  , OTHER, blox_EdgeCase_Block, ip, unLogged, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_EdgeCase_SubCase_fields[2] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_EdgeCase_SubCase, subvalue, subvalue, 0),
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
PB_STATIC_ASSERT((pb_membersize(blox_EdgeCase_Block, settings) < 65536 && pb_membersize(blox_EdgeCase_Block, state) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_blox_EdgeCase_Settings_blox_EdgeCase_State_blox_EdgeCase_NestedLink_blox_EdgeCase_Block_blox_EdgeCase_SubCase)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(blox_EdgeCase_Block, settings) < 256 && pb_membersize(blox_EdgeCase_Block, state) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_blox_EdgeCase_Settings_blox_EdgeCase_State_blox_EdgeCase_NestedLink_blox_EdgeCase_Block_blox_EdgeCase_SubCase)
#endif


/* @@protoc_insertion_point(eof) */
