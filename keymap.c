#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include <print.h>

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMS 2 // control keys (and numpad on left side)
#define OVERWATCH 3 // overwatch layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  MON_SHIFT, // monitored shift; identical to shift, except stores current state
  SPACE_ENTER
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(

    // left hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_F14,
    KC_TRNS,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_F13,
    KC_TAB,KC_A,KC_S,KC_D,KC_F,KC_G,
    MON_SHIFT,OSL(1),KC_X,KC_C,KC_V,KC_B,KC_F12,
    OSM(MOD_LSFT),TG(3),KC_TRNS,KC_TRNS,KC_LGUI,

    // thumb cluster
    KC_F15,KC_F16,KC_F17,
    SPACE_ENTER,KC_LCTL,KC_LALT,
    
    // right hand
    KC_DELETE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_MINUS,
    KC_TRNS,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_TILD,
    KC_H,KC_J,KC_K,KC_L,KC_Z,KC_QUOTE,
    KC_TRNS,KC_N,KC_M,KC_COMMA,KC_DOT,OSL(2),KC_SLASH,
    KC_ESCAPE,KC_TRNS,TG(2),KC_TRNS,KC_TRNS,
    
    // thumb cluster 
    KC_LEFT,KC_RIGHT,KC_UP,KC_DOWN,KC_ENTER,KC_BSPACE
  
  ),

  [SYMB] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_KP_ASTERISK,KC_LCBR,KC_RCBR,KC_DLR,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_LABK,KC_LPRN,KC_RPRN,KC_RABK,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_LBRACKET,KC_RBRACKET,KC_BSLASH,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    
    // thumb cluster 
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,
    
    // right hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_PERC,KC_MINUS,KC_UNDS,KC_PIPE,KC_HASH,KC_TRNS,
    KC_AT,KC_COLN,KC_EQUAL,KC_SCOLON,KC_CIRC,KC_GRAVE,
    KC_TRNS,KC_AMPR,KC_DOT,KC_COMMA,KC_KP_PLUS,KC_EXLM,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    
    
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS
  
  ),

  [NUMS] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_7,KC_8,KC_9,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_0,KC_4,KC_5,KC_6,KC_0,
    KC_TRNS,KC_TRNS,KC_1,KC_2,KC_3,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    
    // thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,
    
    // right hand 
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,RESET,
    KC_TRNS,KC_0,KC_CIRC,KC_DLR,KC_ESCAPE,KC_TRNS,KC_TRNS,
    KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_ESCAPE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

    // thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS
  ),

  [OVERWATCH] = LAYOUT_ergodox(
    // left hand
    KC_ESCAPE,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TAB,KC_Q,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_Y,
    KC_BSLASH,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_LSHIFT,KC_Z,KC_X,KC_TRNS,KC_TRNS,KC_TRNS,KC_H,
    KC_LCTL,KC_TRNS,KC_I,KC_O,KC_QUOTE,
    
    // thumb cluster
    KC_U,KC_J,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,

    // right hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

    // thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS
  ),

};



const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};


 

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0:
      if (record->event.pressed) {
      }
      break;
  }
  return MACRO_NONE;
};


bool mon_shift_on = false;
bool mon_shift_held = false;
bool key_pressed = false;

bool mon_shift_toggled_on = false;

uint16_t mon_shift_first_press_time = 0; 
uint16_t mon_shift_second_press_time = 0; 

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  if(!mon_shift_held && !mon_shift_toggled_on && key_pressed){
    unregister_code(KC_LSFT);
    mon_shift_on = false;
    key_pressed = false;
    ergodox_right_led_3_off();
  }

  switch (keycode) {
    
    case MON_SHIFT:
      if (record->event.pressed) {
        // not on yet
        if(!mon_shift_on){
          register_code(KC_LSFT);
          mon_shift_on = true;
          mon_shift_held = true;
          mon_shift_first_press_time = record->event.time;

          ergodox_right_led_3_on();
        }
        // already on
        else {
          mon_shift_second_press_time = record->event.time; 

          // toggled on, so cancel it
          if(mon_shift_toggled_on){
            unregister_code(KC_LSFT);
            mon_shift_on = false;
            mon_shift_held = false;
            mon_shift_toggled_on = false;
            ergodox_right_led_3_off();
          }
          else {
            // if greater than timeout, cancel the one shot situation
            if(mon_shift_second_press_time - mon_shift_first_press_time > 1000){
              unregister_code(KC_LSFT);
              mon_shift_on = false;
              mon_shift_held = false;
              mon_shift_toggled_on = false;
              ergodox_right_led_3_off();
            }
            // if less than timeout (double tap) toggle it on
            else {
              ergodox_right_led_3_on();
              mon_shift_on = true;
              mon_shift_toggled_on = true;
            }
          }
        }
      }
      // released
      else {
        // if it's just been toggled on (this block will execute after second tap in double tap
        if(mon_shift_toggled_on){

        }
        // released from held mode
        else {
          mon_shift_held = false;

          if(key_pressed){
            unregister_code(KC_LSFT);
            mon_shift_on = false;
            key_pressed = false;
            ergodox_right_led_3_off();
          }
        }
      }

      return false;
      break;

    case SPACE_ENTER:
      if (record->event.pressed) {
        if(mon_shift_on){
          register_code(KC_ENTER);
          key_pressed = true;
        }
        else{
          register_code(KC_SPACE);
        }
      }
      else{
        unregister_code(KC_SPACE);
        unregister_code(KC_ENTER);
      }
      return false;
      break;

    default:
      if(mon_shift_on){
        key_pressed = true;
      }
      break;
  }

  

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
