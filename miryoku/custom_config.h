// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku

// 1. Define Key Positions for a 36-key Corne (3x5+3)
#define KEYS_L 0 1 2 3 4 10 11 12 13 14 20 21 22 23 24
#define KEYS_R 5 6 7 8 9 15 16 17 18 19 25 26 27 28 29
#define THUMBS 30 31 32 33 34 35

// 2. urob's "Timeless" behaviors
// We put these in the 'ZMK_BEHAVIORS' node via the Miryoku kludge
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

// 3. The "Glue" Logic
// Miryoku uses U_MT(MOD, TAP). We need to map it to our hml/hmr.
// Because Miryoku uses a single macro for all HRMs, we use a helper
// that urob uses to choose the behavior based on the key position.
#define U_MT(MOD, TAP) &u_mt MOD TAP

// This is the tricky part. For Miryoku to not crash, u_mt must
// accept exactly two arguments and return a single behavior.
#define u_mt(mod, tap) &hml mod tap


// Redefine the mapping so Left keys use hml and Right keys use hmr
#undef MIRYOKU_LAYOUT_MAPPING
#define MIRYOKU_LAYOUT_MAPPING( \
    K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
    N30, N31, K32, K33, K34,      K35, K36, K37, N38, N39 \
) \
K00, K01, K02, K03, K04,      K05, K06, K07, K08, K09, \
K10, K11, K12, K13, K14,      K15, K16, K17, K18, K19, \
K20, K21, K22, K23, K24,      K25, K26, K27, K28, K29, \
          K32, K33, K34,      K35, K36, K37
