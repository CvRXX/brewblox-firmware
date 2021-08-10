/* Automatically generated nanopb header */

#ifndef PB_BLOX_TOUCHSETTINGS_PB_H_INCLUDED
#define PB_BLOX_TOUCHSETTINGS_PB_H_INCLUDED
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
typedef enum _blox_TouchSettings_Calibrated {
    blox_TouchSettings_Calibrated_CALIBRATED_NO = 0,
    blox_TouchSettings_Calibrated_CALIBRATED_YES = 1,
    blox_TouchSettings_Calibrated_CALIBRATED_NEW = 2
} blox_TouchSettings_Calibrated;
#define _blox_TouchSettings_Calibrated_MIN blox_TouchSettings_Calibrated_CALIBRATED_NO
#define _blox_TouchSettings_Calibrated_MAX blox_TouchSettings_Calibrated_CALIBRATED_NEW
#define _blox_TouchSettings_Calibrated_ARRAYSIZE ((blox_TouchSettings_Calibrated)(blox_TouchSettings_Calibrated_CALIBRATED_NEW+1))

/* Struct definitions */
typedef struct _blox_TouchSettings {
    blox_TouchSettings_Calibrated calibrated;
    int16_t xOffset;
    int16_t yOffset;
    uint16_t xBitsPerPixelX16;
    uint16_t yBitsPerPixelX16;
/* @@protoc_insertion_point(struct:blox_TouchSettings) */
} blox_TouchSettings;

/* Default values for struct fields */

/* Initializer values for message structs */
#define blox_TouchSettings_init_default          {_blox_TouchSettings_Calibrated_MIN, 0, 0, 0, 0}
#define blox_TouchSettings_init_zero             {_blox_TouchSettings_Calibrated_MIN, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define blox_TouchSettings_calibrated_tag        1
#define blox_TouchSettings_xOffset_tag           2
#define blox_TouchSettings_yOffset_tag           3
#define blox_TouchSettings_xBitsPerPixelX16_tag  4
#define blox_TouchSettings_yBitsPerPixelX16_tag  5

/* Struct field encoding specification for nanopb */
extern const pb_field_t blox_TouchSettings_fields[6];

/* Maximum encoded size of messages (where known) */
#define blox_TouchSettings_size                  36

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define TOUCHSETTINGS_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
