#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#include <print.h>

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NUMB 2 // control keys (and numpad on left side)
#define ARROWS 3 // only arrow keys (persistent) 
#define OVERWATCH 4 // overwatch layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  PERSISTENT_LEFT, // left + goes to NUMB layer again
  PERSISTENT_DOWN,
  PERSISTENT_UP,
  PERSISTENT_RIGHT,
  DOT_DOT_SLASH,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [BASE] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_ESCAPE,KC_TRNS,KC_TRNS,KC_F14,
    KC_TRNS,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_F13,
    KC_TAB,KC_A,KC_S,KC_D,KC_F,KC_G,
    OSM(MOD_LSFT),KC_Z,OSL(SYMB),KC_C,KC_V,KC_B,KC_F12,
    KC_TRNS,TG(OVERWATCH),KC_TRNS,KC_TRNS,KC_LGUI,

    // thumb cluster
    KC_F15,KC_F16,KC_F17,
    KC_SPACE,KC_LCTL,OSM(MOD_LALT),
    
    // right hand
    KC_DELETE,KC_TRNS,KC_TRNS,KC_ENTER,KC_TRNS,KC_TRNS,KC_MINUS,
    KC_TRNS,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_TILD,
    KC_H,KC_J,KC_K,KC_L,KC_X,KC_QUOTE,
    KC_TRNS,KC_N,KC_M,KC_COMMA,OSL(NUMB),KC_DOT,KC_SLASH,
    KC_ESCAPE,KC_TRNS,TG(NUMB),KC_TRNS,DEBUG,
    
    // thumb cluster 
    KC_LEFT,KC_RIGHT,KC_UP,
    KC_DOWN,KC_TRNS,KC_BSPACE
  ), 

  [SYMB] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_KP_ASTERISK,KC_LCBR,KC_RCBR,KC_DLR,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_LABK,KC_LPRN,KC_RPRN,KC_RABK,
    KC_TRNS,MO(NUMB),TO(BASE),KC_LBRACKET,KC_RBRACKET,KC_BSLASH,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    
    // thumb cluster 
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,
    
    // right hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_MINUS,KC_UNDS,KC_PIPE,KC_TRNS,KC_TRNS,
    KC_AT,KC_COLN,KC_EQUAL,KC_SCOLON,KC_CIRC,KC_GRAVE,
    KC_TRNS,KC_AMPR,KC_HASH,KC_PERC,KC_PLUS,KC_EXLM,DOT_DOT_SLASH,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    
    
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS
  ),

  [NUMB] = LAYOUT_ergodox(
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
    PERSISTENT_LEFT,PERSISTENT_DOWN,PERSISTENT_UP,PERSISTENT_RIGHT,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_ESCAPE,KC_TRNS,TO(BASE),KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,

    // thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS
  ),

  [ARROWS] = LAYOUT_ergodox(
    // left hand
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    
    // thumb cluster
    KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,
    
    // right hand 
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
    PERSISTENT_LEFT,PERSISTENT_DOWN,PERSISTENT_UP,PERSISTENT_RIGHT,KC_TRNS,KC_TRNS,
    KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,TO(BASE),KC_TRNS,KC_TRNS,
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


uint8_t oneshot_layer;

void persistent_key(keyrecord_t* record, uint16_t keycode){
  if (record->event.pressed) {
    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
    set_oneshot_layer(ARROWS, ONESHOT_START);
    register_code(keycode);
  }
  else {
    clear_oneshot_layer_state(ONESHOT_PRESSED);
    unregister_code(keycode);
  }
}



bool lsft_on ; // is lsft already on
bool shift_tapped = false; // flag to tell loop not to turn led back off if shift's been tapped

bool osm_shifted_key_pressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  lsft_on = keyboard_report->mods & (MOD_BIT(KC_LSFT));

  uprintf("\nkeycode: %u\n", keycode);
  uprintf("keyboard_report: %u\n", keyboard_report);
  uprintf("keyboard_report->mods, %u\n", keyboard_report->mods);
  uprintf("record->event.pressed, %u\n", record->event.pressed);

  switch (keycode) {
    
    // 0101 0101 0000 0010 (tap event for lsft key)
    case 21762:
      // press
      if (record->event.pressed) {
          osm_shifted_key_pressed = false;
      }
      // release
      else {
        if(!lsft_on){
          ergodox_right_led_3_on();
          shift_tapped = true;
        }
        else {
          ergodox_right_led_3_off();
        }
      }
      break;

    case PERSISTENT_LEFT:
      persistent_key(record, KC_LEFT);
      return false;
      break;

    case PERSISTENT_DOWN:
      persistent_key(record, KC_DOWN);
      return false;
      break;

    case PERSISTENT_UP:
      persistent_key(record, KC_UP);
      return false;
      break;

    case PERSISTENT_RIGHT:
      persistent_key(record, KC_RIGHT);
      return false;
      break;

    case DOT_DOT_SLASH:
      if (record->event.pressed) {
          SEND_STRING("../");
          clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
      }
      return false;
      break;

    default:
      if (record->event.pressed) {
          if(osm_shifted_key_pressed){
              // fixes issue on mac where if a OSM'ed key is still held down while another 
              // is pressed, the second will have the same modifier applied
              // resulting in e.g. THe instead of The because T is still down while H
              // is pressed.
              unregister_code(KC_LSHIFT);
          }

          if((get_oneshot_mods() == 2) && !has_oneshot_mods_timed_out()) {
              osm_shifted_key_pressed = true;
          }
      }
      if(shift_tapped){
        shift_tapped = false;
      }
      break;
  }

  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  debug_enable=true;
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  lsft_on = keyboard_report->mods & (MOD_BIT(KC_LSFT));

  if(layer_state_is(OVERWATCH)){

  }
  else if(lsft_on){
    ergodox_right_led_3_on();
  }
  else if(shift_tapped){

  }
  else {
    ergodox_right_led_3_off();
  }
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_set(LED_BRIGHTNESS_HI);
  ergodox_right_led_1_off();
  ergodox_right_led_2_set(LED_BRIGHTNESS_HI);
  ergodox_right_led_2_off();
  ergodox_right_led_3_set(LED_BRIGHTNESS_HI);
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case BASE:
        break;
      case SYMB:
        ergodox_right_led_1_on();
        break;
      case NUMB:
        ergodox_right_led_2_on();
        break;
      case ARROWS:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case OVERWATCH:
        ergodox_right_led_1_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_1_on();
        ergodox_right_led_2_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_2_on();
        ergodox_right_led_3_set(LED_BRIGHTNESS_LO);
        ergodox_right_led_3_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};
