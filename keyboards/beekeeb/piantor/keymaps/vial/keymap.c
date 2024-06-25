// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#define BASE     0
#define NAV      1
#define MOUSE    2
#define MEDIA    3
#define NUM      4
#define SYM      5
#define FUN      6
#define BUTTON   7

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤Bsp│   │Ent├───┘
      *                       └───┘   └───┘
      */
    [BASE] = LAYOUT_split_3x6_3(
        KC_NO,  ALGR_T(KC_Q),              KC_W,          KC_F,          LT(BUTTON, KC_P),              KC_B,                                                         KC_J,              LT(BUTTON, KC_L),          KC_U,          ALGR_T(KC_Y),              KC_QUOT,                 KC_NO,
        KC_NO,  LGUI_T(KC_A),      LALT_T(KC_R),  LCTL_T(KC_S),  LSFT_T(KC_T),      KC_G,                                                         KC_M,              LSFT_T(KC_N),  LCTL_T(KC_E),  LALT_T(KC_I),      LGUI_T(KC_O),            KC_NO,
        KC_NO,  LT(BUTTON, KC_Z),  KC_X,  KC_C,          KC_D,              KC_V,                                                         KC_K,              KC_H,          KC_COMM,       KC_DOT,            KC_SLSH,                 KC_NO,
                                                                 LT(MEDIA, KC_ESC), LT(NAV, KC_SPC),  LT(MOUSE, KC_TAB),        LT(SYM, KC_ENT),  LT(NUM, KC_BSPC),  LT(FUN, KC_DEL)
    ),

    [NAV] = LAYOUT_split_3x6_3(
        KC_NO,  QK_REBOOT,         KC_NO,             KC_NO,              KC_NO,              KC_NO,                   LCTL(KC_Y),             LCTL(KC_V),             LCTL(KC_C),             LCTL(KC_X),             LCTL(KC_Z),                   KC_NO,
        KC_NO,  KC_LGUI,           KC_LALT,           KC_LCTL,            KC_LSFT,            KC_NO,                   KC_CAPS,                 KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,                 KC_NO,
        KC_NO,  KC_NO,             KC_ALGR,           KC_NO,              KC_NO,              KC_NO,                   KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,                  KC_NO,
                                                                                      KC_NO,              KC_NO,              KC_NO,                   KC_ENT,            KC_BSPC,           KC_DEL
    ),

    [MOUSE] = LAYOUT_split_3x6_3(
        KC_NO,  QK_REBOOT,             KC_NO,             KC_NO,              KC_NO,              KC_NO,                   LCTL(KC_Y),             LCTL(KC_V),             LCTL(KC_C),             LCTL(KC_X),             LCTL(KC_Z),                   KC_NO,
        KC_NO,  KC_LGUI,           KC_LALT,           KC_LCTL,            KC_LSFT,            KC_NO,                   KC_NO,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,                 KC_NO,
        KC_NO,  KC_NO,             KC_ALGR,           KC_NO,              KC_NO,              KC_NO,                   KC_NO,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,                 KC_NO,
                                                                  KC_NO,              KC_NO,              KC_NO,                   KC_BTN1,           KC_BTN3,           KC_BTN2
    ),

    [MEDIA] = LAYOUT_split_3x6_3(
        KC_NO,  QK_REBOOT,             KC_NO,             KC_NO,              KC_NO,              KC_NO,                   RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,                 KC_NO,
        KC_NO,  KC_LGUI,           KC_LALT,           KC_LCTL,            KC_LSFT,            KC_NO,                   OUT_AUTO,          KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,                 KC_NO,
        KC_NO,  KC_NO,             KC_ALGR,           KC_NO,              KC_NO,              KC_NO,                   KC_NO,              KC_NO,              KC_NO,              KC_NO,              KC_NO,                    KC_NO,
                                                                  KC_NO,              KC_NO,              KC_NO,                   KC_MSTP,           KC_MPLY,           KC_MUTE
    ),

    [NUM] = LAYOUT_split_3x6_3(
        KC_NO,  KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,                KC_NO,              KC_NO,              KC_NO,              KC_NO,             QK_REBOOT,                   KC_NO,
        KC_NO,  KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,                 KC_NO,              KC_LSFT,            KC_LCTL,            KC_LALT,           KC_LGUI,                 KC_NO,
        KC_NO,  KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,                KC_NO,              KC_NO,              KC_NO,              KC_ALGR,           KC_NO,                   KC_NO,
                                                                  KC_DOT,            KC_0,              KC_MINS,                KC_NO,              KC_NO,              KC_NO
    ),

    [SYM] = LAYOUT_split_3x6_3(
        KC_NO,  KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,                KC_NO,              KC_NO,              KC_NO,              KC_NO,             QK_REBOOT,                   KC_NO,
        KC_NO,  KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,                KC_NO,              KC_LSFT,            KC_LCTL,            KC_LALT,           KC_LGUI,                 KC_NO,
        KC_NO,  KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,                KC_NO,              KC_NO,              KC_NO,              KC_ALGR,           KC_NO,                   KC_NO,
                                                                  KC_LPRN,           KC_RPRN,           KC_UNDS,                KC_NO,              KC_NO,              KC_NO
    ),

    [FUN] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                KC_NO,              KC_NO,              KC_NO,              KC_NO,             QK_REBOOT,                   KC_NO,
        KC_NO,  KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SLCK,                KC_NO,              KC_LSFT,            KC_LCTL,            KC_LALT,           KC_LGUI,                 KC_NO,
        KC_NO,  KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,                KC_NO,              KC_NO,              KC_NO,              KC_ALGR,           KC_NO,                   KC_NO,
                                                                  KC_APP,            KC_SPC,            KC_TAB,                 KC_NO,              KC_NO,              KC_NO
    ),

    [BUTTON] = LAYOUT_split_3x6_3(
        KC_NO,  LCTL(KC_Z),             LCTL(KC_X),             LCTL(KC_C),             LCTL(KC_V),             LCTL(KC_Y),                  LCTL(KC_Y),              LCTL(KC_V),          LCTL(KC_C),              LCTL(KC_X),             LCTL(KC_Z),                   KC_NO,
        KC_NO,  KC_LGUI,                KC_LALT,                KC_LCTL,                KC_LSFT,                KC_NO,                       KC_NO,                   KC_LSFT,             KC_LCTL,            KC_LALT,           KC_LGUI,                 KC_NO,
        KC_NO,  LCTL(KC_Z),             LCTL(KC_X),             LCTL(KC_C),             LCTL(KC_V),             LCTL(KC_Y),                  LCTL(KC_Y),              LCTL(KC_V),          LCTL(KC_C),              LCTL(KC_X),             LCTL(KC_Z),                   KC_NO,
                                                                KC_BTN2,                KC_BTN3,                KC_BTN1,                     KC_BTN1,                 KC_BTN3,            KC_BTN2
    )
};
