/* Automatically generated nanopb header */

#ifndef PB_BLOX_ACTUATORLOGIC_ACTUATORLOGIC_PB_H_INCLUDED
#define PB_BLOX_ACTUATORLOGIC_ACTUATORLOGIC_PB_H_INCLUDED
#include <pb.h>

#include "brewblox.pb.h"

#include "IoArray.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Enum definitions */
typedef enum _blox_ActuatorLogic_Result {
    blox_ActuatorLogic_Result_RESULT_FALSE = 0,
    blox_ActuatorLogic_Result_RESULT_TRUE = 1,
    blox_ActuatorLogic_Result_RESULT_EMPTY = 2,
    blox_ActuatorLogic_Result_RESULT_EMPTY_SUBSTRING = 3,
    blox_ActuatorLogic_Result_RESULT_BLOCK_NOT_FOUND = 4,
    blox_ActuatorLogic_Result_RESULT_INVALID_DIGITAL_OP = 5,
    blox_ActuatorLogic_Result_RESULT_INVALID_ANALOG_OP = 6,
    blox_ActuatorLogic_Result_RESULT_UNDEFINED_DIGITAL_COMPARE = 8,
    blox_ActuatorLogic_Result_RESULT_UNDEFINED_ANALOG_COMPARE = 7,
    blox_ActuatorLogic_Result_RESULT_UNEXPECTED_OPEN_BRACKET = 11,
    blox_ActuatorLogic_Result_RESULT_UNEXPECTED_CLOSE_BRACKET = 9,
    blox_ActuatorLogic_Result_RESULT_UNEXPECTED_CHARACTER = 12,
    blox_ActuatorLogic_Result_RESULT_UNEXPECTED_COMPARISON = 13,
    blox_ActuatorLogic_Result_RESULT_UNEXPECTED_OPERATOR = 14,
    blox_ActuatorLogic_Result_RESULT_MISSING_CLOSE_BRACKET = 10
} blox_ActuatorLogic_Result;
#define _blox_ActuatorLogic_Result_MIN blox_ActuatorLogic_Result_RESULT_FALSE
#define _blox_ActuatorLogic_Result_MAX blox_ActuatorLogic_Result_RESULT_MISSING_CLOSE_BRACKET
#define _blox_ActuatorLogic_Result_ARRAYSIZE ((blox_ActuatorLogic_Result)(blox_ActuatorLogic_Result_RESULT_MISSING_CLOSE_BRACKET+1))

typedef enum _blox_ActuatorLogic_DigitalOperator {
    blox_ActuatorLogic_DigitalOperator_OP_VALUE_IS = 0,
    blox_ActuatorLogic_DigitalOperator_OP_VALUE_IS_NOT = 1,
    blox_ActuatorLogic_DigitalOperator_OP_DESIRED_IS = 10,
    blox_ActuatorLogic_DigitalOperator_OP_DESIRED_IS_NOT = 11
} blox_ActuatorLogic_DigitalOperator;
#define _blox_ActuatorLogic_DigitalOperator_MIN blox_ActuatorLogic_DigitalOperator_OP_VALUE_IS
#define _blox_ActuatorLogic_DigitalOperator_MAX blox_ActuatorLogic_DigitalOperator_OP_DESIRED_IS_NOT
#define _blox_ActuatorLogic_DigitalOperator_ARRAYSIZE ((blox_ActuatorLogic_DigitalOperator)(blox_ActuatorLogic_DigitalOperator_OP_DESIRED_IS_NOT+1))

typedef enum _blox_ActuatorLogic_AnalogOperator {
    blox_ActuatorLogic_AnalogOperator_OP_VALUE_LE = 0,
    blox_ActuatorLogic_AnalogOperator_OP_VALUE_GE = 1,
    blox_ActuatorLogic_AnalogOperator_OP_SETTING_LE = 10,
    blox_ActuatorLogic_AnalogOperator_OP_SETTING_GE = 11
} blox_ActuatorLogic_AnalogOperator;
#define _blox_ActuatorLogic_AnalogOperator_MIN blox_ActuatorLogic_AnalogOperator_OP_VALUE_LE
#define _blox_ActuatorLogic_AnalogOperator_MAX blox_ActuatorLogic_AnalogOperator_OP_SETTING_GE
#define _blox_ActuatorLogic_AnalogOperator_ARRAYSIZE ((blox_ActuatorLogic_AnalogOperator)(blox_ActuatorLogic_AnalogOperator_OP_SETTING_GE+1))

/* Struct definitions */
typedef struct _blox_ActuatorLogic_AnalogCompare {
    blox_ActuatorLogic_AnalogOperator op;
    blox_ActuatorLogic_Result result;
    uint16_t id;
    int32_t rhs;
/* @@protoc_insertion_point(struct:blox_ActuatorLogic_AnalogCompare) */
} blox_ActuatorLogic_AnalogCompare;

typedef struct _blox_ActuatorLogic_DigitalCompare {
    blox_ActuatorLogic_DigitalOperator op;
    blox_ActuatorLogic_Result result;
    uint16_t id;
    blox_IoArray_DigitalState rhs;
/* @@protoc_insertion_point(struct:blox_ActuatorLogic_DigitalCompare) */
} blox_ActuatorLogic_DigitalCompare;

typedef struct _blox_ActuatorLogic_Block {
    uint16_t targetId;
    uint16_t drivenTargetId;
    bool enabled;
    blox_ActuatorLogic_Result result;
    char expression[65];
    pb_size_t digital_count;
    blox_ActuatorLogic_DigitalCompare digital[16];
    pb_size_t analog_count;
    blox_ActuatorLogic_AnalogCompare analog[16];
    uint8_t errorPos;
/* @@protoc_insertion_point(struct:blox_ActuatorLogic_Block) */
} blox_ActuatorLogic_Block;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_ActuatorLogic_DigitalCompare_init_default {_blox_ActuatorLogic_DigitalOperator_MIN, _blox_ActuatorLogic_Result_MIN, 0, _blox_IoArray_DigitalState_MIN}
#define blox_ActuatorLogic_AnalogCompare_init_default {_blox_ActuatorLogic_AnalogOperator_MIN, _blox_ActuatorLogic_Result_MIN, 0, 0}
#define blox_ActuatorLogic_Block_init_default    {0, 0, 0, _blox_ActuatorLogic_Result_MIN, "", 0, {blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default, blox_ActuatorLogic_DigitalCompare_init_default}, 0, {blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default, blox_ActuatorLogic_AnalogCompare_init_default}, 0}
#define blox_ActuatorLogic_DigitalCompare_init_zero {_blox_ActuatorLogic_DigitalOperator_MIN, _blox_ActuatorLogic_Result_MIN, 0, _blox_IoArray_DigitalState_MIN}
#define blox_ActuatorLogic_AnalogCompare_init_zero {_blox_ActuatorLogic_AnalogOperator_MIN, _blox_ActuatorLogic_Result_MIN, 0, 0}
#define blox_ActuatorLogic_Block_init_zero       {0, 0, 0, _blox_ActuatorLogic_Result_MIN, "", 0, {blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero, blox_ActuatorLogic_DigitalCompare_init_zero}, 0, {blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero, blox_ActuatorLogic_AnalogCompare_init_zero}, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_ActuatorLogic_AnalogCompare_op_tag  1
#define blox_ActuatorLogic_AnalogCompare_result_tag 2
#define blox_ActuatorLogic_AnalogCompare_id_tag  3
#define blox_ActuatorLogic_AnalogCompare_rhs_tag 4
#define blox_ActuatorLogic_DigitalCompare_op_tag 1
#define blox_ActuatorLogic_DigitalCompare_result_tag 2
#define blox_ActuatorLogic_DigitalCompare_id_tag 3
#define blox_ActuatorLogic_DigitalCompare_rhs_tag 4
#define blox_ActuatorLogic_Block_targetId_tag    1
#define blox_ActuatorLogic_Block_drivenTargetId_tag 2
#define blox_ActuatorLogic_Block_enabled_tag     3
#define blox_ActuatorLogic_Block_result_tag      4
#define blox_ActuatorLogic_Block_expression_tag  5
#define blox_ActuatorLogic_Block_digital_tag     6
#define blox_ActuatorLogic_Block_analog_tag      7
#define blox_ActuatorLogic_Block_errorPos_tag    8

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_ActuatorLogic_DigitalCompare_fields[5];
extern const pb_field_t blox_ActuatorLogic_AnalogCompare_fields[5];
extern const pb_field_t blox_ActuatorLogic_Block_fields[9];

/* Maximum encoded size of messages (where known) */
#define blox_ActuatorLogic_DigitalCompare_size   12
#define blox_ActuatorLogic_AnalogCompare_size    16
#define blox_ActuatorLogic_Block_size            601

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ACTUATORLOGIC_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
