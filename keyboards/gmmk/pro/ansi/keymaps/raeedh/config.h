#pragma once

/* Force NKRO on boot up regardless of the setting saved in the EEPROM */
#define FORCE_NKRO

/* Send up to 12 key press events per scan (not sure if this is actually necessary?) */
#undef QMK_KEYS_PER_SCAN
#define QMK_KEYS_PER_SCAN 12

/* disable RGB lighting when sleep */
#define RGB_DISABLE_WHEN_USB_SUSPENDED
#define RGB_DISABLE_TIMEOUT 300000 // 5 mins (5 * 60 * 1000ms)
