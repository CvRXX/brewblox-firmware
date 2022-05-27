#include <cstddef>
#include <cstdint>

static constexpr uint16_t eepromStart = 0;

struct __attribute__((packed)) EepromLayout {
    union {
        uint16_t header;
        struct {
            uint8_t magic;
            uint8_t version;
        } MagicVersion;
    };
    uint8_t reserved[30];
    uint8_t objects[2048 - (eepromStart + 2 + 30)];
};

static constexpr uint16_t EepromEnd = eepromStart + sizeof(EepromLayout);

#define EepromLocation(x) uint16_t(eepromStart + offsetof(struct EepromLayout, x))
#define EepromLocationEnd(x) uint16_t(EepromLocation(x) + sizeof(EepromLayout::x))
#define EepromLocationSize(x) uint16_t(sizeof(EepromLayout::x))

static_assert(EepromLocationEnd(objects) == 2048, "end of data area is end of 2kb EEPROM");
