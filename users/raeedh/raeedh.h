#ifndef RAEEDH
#define RAEEDH

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

// for tap dances
typedef struct {
  bool is_press_action;
  int state;
} xtap;

enum {
  SINGLE_TAP,
  DOUBLE_TAP,
  TRIPLE_TAP,
//   SINGLE_HOLD = 2,
//   DOUBLE_HOLD = 4,
//   DOUBLE_SINGLE_TAP = 5,
//   TRIPLE_HOLD = 7,
};

enum tap_dance_codes {
    // Tap Dance
    LPRN_DANCE,
    RPRN_DANCE,
};

// #ifdef TAP_DANCE_ENABLE
// #define LPRN_DANCE      TD(LPRN_DANCE)
// #define RPRN_DANCE      TD(RPRN_DANCE)
// #else //just to make things compile
// #define LPRN_DANCE      KC_1
// #define RPRN_DANCE      KC_1
// #endif

int cur_dance (qk_tap_dance_state_t *state);

// td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the LPRN tap dance. Put it here so it can be used in any keymap
void lprn_finished(qk_tap_dance_state_t *state, void *user_data);
void lprn_reset(qk_tap_dance_state_t *state, void *user_data);
void rprn_finished(qk_tap_dance_state_t *state, void *user_data);
void rprn_reset(qk_tap_dance_state_t *state, void *user_data);

#endif
