/* Automatically generated nanopb constant definitions */

#include "Controlbox.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t Controlbox_Payload_fields[5] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, Controlbox_Payload, blockId, blockId, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, Controlbox_Payload, objtype, blockId, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, Controlbox_Payload, subtype, objtype, 0),
    PB_FIELD(  4, STRING  , SINGULAR, CALLBACK, OTHER, Controlbox_Payload, data, subtype, 0),
    PB_LAST_FIELD
};

const pb_field_t Controlbox_Request_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, Controlbox_Request, msgId, msgId, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, Controlbox_Request, opcode, msgId, 0),
    PB_FIELD(  3, MESSAGE , SINGULAR, STATIC  , OTHER, Controlbox_Request, payload, opcode, &Controlbox_Payload_fields),
    PB_LAST_FIELD
};

const pb_field_t Controlbox_Response_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, Controlbox_Response, msgId, msgId, 0),
    PB_FIELD(  2, UENUM   , SINGULAR, STATIC  , OTHER, Controlbox_Response, error, msgId, 0),
    PB_FIELD(  3, MESSAGE , REPEATED, CALLBACK, OTHER, Controlbox_Response, payload, error, &Controlbox_Payload_fields),
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
PB_STATIC_ASSERT((pb_membersize(Controlbox_Request, payload) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_Controlbox_Payload_Controlbox_Request_Controlbox_Response)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(Controlbox_Request, payload) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_Controlbox_Payload_Controlbox_Request_Controlbox_Response)
#endif


/* @@protoc_insertion_point(eof) */
