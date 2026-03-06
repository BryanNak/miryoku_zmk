// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// 1. Define Key Positions for a 36-key Corne (3x5+3)
#define KEYS_L 0 1 2 3 4 10 11 12 13 14 20 21 22 23 24
#define KEYS_R 5 6 7 8 9 15 16 17 18 19 25 26 27 28 29
#define THUMBS 30 31 32 33 34 35

// 2. urob's "Timeless" behaviors
#define MIRYOKU_KLUDGE_TAP_P \
    hml: homrow_mods_left { \
        compatible = "zmk,behavior-hold-tap"; \
        #binding-cells = <2>; \
        flavor = "balanced"; \
        tapping-term-ms = <280>; \
        quick-tap-ms = <175>; \
        require-prior-idle-ms = <150>; \
        bindings = <&kp>, <&kp>; \
        hold-trigger-key-positions = <KEYS_R THUMBS>; \
        hold-trigger-on-release; \
    }; \
    hmr: homrow_mods_right { \
        compatible = "zmk,behavior-hold-tap"; \
        #binding-cells = <2>; \
        flavor = "balanced"; \
        tapping-term-ms = <280>; \
        quick-tap-ms = <175>; \
        require-prior-idle-ms = <150>; \
        bindings = <&kp>, <&kp>; \
        hold-trigger-key-positions = <KEYS_L THUMBS>; \
        hold-trigger-on-release; \
    };

// 3. The Fix for the "2 arguments" error
// Miryoku uses U_MT(MOD, TAP). This redirection is cleaner:
#define U_MT(MOD, TAP) &u_mt_helper MOD TAP
#define u_mt_helper(MOD, TAP) &hml MOD TAP
