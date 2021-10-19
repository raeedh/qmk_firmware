#include "raeedh.h"
#include "quantum.h"
#include "action.h"
#include "process_keycode/process_tap_dance.h"

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) return SINGLE_TAP;
    else if (state->count == 2) return DOUBLE_TAP;
    else if (state->count == 3) return TRIPLE_TAP;
    else return 8;
};

// Create an instance of 'td_tap_t' for the 'lprn' tap dance.
static xtap lprn_state = {
  .is_press_action = true,
  .state = 0
};

void lprn_finished (qk_tap_dance_state_t *state, void *user_data) {
  lprn_state.state = cur_dance(state);
  switch (lprn_state.state) {
    case SINGLE_TAP: register_code16(KC_LPRN); break;
    case DOUBLE_TAP: register_code(KC_LBRC); break;
    case TRIPLE_TAP: register_code16(KC_LCBR); break;
  }
}

void lprn_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (lprn_state.state) {
    case SINGLE_TAP: unregister_code16(KC_LPRN); break;
    case DOUBLE_TAP: unregister_code(KC_LBRC); break;
    case TRIPLE_TAP: unregister_code16(KC_LCBR); break;
  }
  lprn_state.state = 0;
}

// Create an instance of 'td_tap_t' for the 'lprn' tap dance.
static xtap rprn_state = {
  .is_press_action = true,
  .state = 0
};

void rprn_finished (qk_tap_dance_state_t *state, void *user_data) {
  rprn_state.state = cur_dance(state);
  switch (rprn_state.state) {
    case SINGLE_TAP: register_code16(KC_RPRN); break;
    case DOUBLE_TAP: register_code(KC_RBRC); break;
    case TRIPLE_TAP: register_code16(KC_RCBR); break;
  }
}

void rprn_reset (qk_tap_dance_state_t *state, void *user_data) {
  switch (rprn_state.state) {
    case SINGLE_TAP: unregister_code16(KC_RPRN); break;
    case DOUBLE_TAP: unregister_code(KC_RBRC); break;
    case TRIPLE_TAP: unregister_code16(KC_RCBR); break;
  }
  rprn_state.state = 0;
}


// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [LPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lprn_finished, lprn_reset),
    [RPRN_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rprn_finished, rprn_reset),
};
