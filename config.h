// See https://github.com/qmk/qmk_firmware/blob/master/docs/config_options.md for a full reference.

// how long before the leader key times out, if there's no valid sequence
#undef LEADER_TIMEOUT
#define LEADER_TIMEOUT 300

// how many taps before triggering the toggle
#undef ONESHOT_TAP_TOGGLE
#define ONESHOT_TAP_TOGGLE 2

// how long before oneshot modifier key times out (currently only shift)
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2000

// Enable HID_listen commands.
// #define NO_DEBUG
// #undef NO_PRINT
#define USER_PRINT
//#define CONSOLE_ENABLE

// how long before a tap becomes a hold
#undef TAPPING_TERM
#define TAPPING_TERM 150

// makes tap and hold keys work better for fast typers who don't want tapping term set above 500
#define PERMISSIVE_HOLD

// tap anyway, even after TAPPING_TERM, if there was no other key interruption between press and release
#define RETRO_TAPPING

