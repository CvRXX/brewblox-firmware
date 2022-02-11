/* Automatically generated nanopb constant definitions */

#include "Balancer.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t blox_Balancer_BalancedActuator_fields[4] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, blox_Balancer_BalancedActuator, id, id, 0),
    PB_FIELD(  2, SINT32  , SINGULAR, STATIC  , OTHER, blox_Balancer_BalancedActuator, requested, id, 0),
    PB_FIELD(  3, SINT32  , SINGULAR, STATIC  , OTHER, blox_Balancer_BalancedActuator, granted, requested, 0),
    PB_LAST_FIELD
};

const pb_field_t blox_Balancer_Block_fields[2] = {
    PB_FIELD(  1, MESSAGE , REPEATED, CALLBACK, FIRST, blox_Balancer_Block, clients, clients, &blox_Balancer_BalancedActuator_fields),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
