#pragma once

/* Force NKRO on boot up regardless of the setting saved in the EEPROM */
#define FORCE_NKRO

/* Send up to 12 key press events per scan (not sure if this is actually necessary?) */
#undef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 12

/* If defined, the RGB lighting will be switched off when the host goes to sleep */
#define RGBLIGHT_SLEEP
