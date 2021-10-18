#ifndef RAEEDH_TAPDANCE_H
#define RAEEDH_TAPDANCE_H

#include "quantum.h"
#include "process_keycode/process_tap_dance.h"

typedef struct {
  bool is_press_action;
  int state;
} xtap;

enum {
  SINGLE_TAP = 1,
  SINGLE_HOLD = 2,
  DOUBLE_TAP = 3,
  DOUBLE_HOLD = 4,
  DOUBLE_SINGLE_TAP = 5, //send two single taps
  TRIPLE_TAP = 6,
  TRIPLE_HOLD = 7,
};

// Tap dance enums
enum {
    LPRN_DANCE,
    RPRN_DANCE,
};

// #ifdef TAP_DANCE_ENABLE
// #define       TD(F1F13)
// #else //just to make things compile
// #define F1_F13      KC_1
// #endif

int cur_dance (qk_tap_dance_state_t *state);

// td_state_t cur_dance(qk_tap_dance_state_t *state);

// For the LPRN tap dance. Put it here so it can be used in any keymap
void lprn_finished(qk_tap_dance_state_t *state, void *user_data);
void lprn_reset(qk_tap_dance_state_t *state, void *user_data);
void rprn_finished(qk_tap_dance_state_t *state, void *user_data);
void rprn_reset(qk_tap_dance_state_t *state, void *user_data);

#endif
