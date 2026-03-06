// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku
//
// 1. Key Positions for 36-key Corne
#define KEYS_L 0 1 2 3 4 10 11 12 13 14 20 21 22 23 24
#define KEYS_R 5 6 7 8 9 15 16 17 18 19 25 26 27 28 29
#define THUMBS 30 31 32 33 34 35

// 2. Define urob's behaviors in the global behaviors node
// We use MIRYOKU_KLUDGE_TOP_LEVEL to inject these at the root of the dtsi
#define MIRYOKU_KLUDGE_TOP_LEVEL \
    / { \
        behaviors { \
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
            }; \
        }; \
    };

// 3. Manually define the Base Layer to use the labels defined above
#define MIRYOKU_LAYER_BASE \
&kp Q,             &kp W,             &kp E,             &kp R,             &kp T,             &kp Y,             &kp U,             &kp I,             &kp O,             &kp P,             \
&hml LGUI A,       &hml LALT S,       &hml LCTRL D,      &hml LSHFT F,      &kp G,             &kp H,             &hmr LSHFT J,      &hmr LCTRL K,      &hmr LALT L,       &hmr LGUI SEMI,    \
&kp Z,             &kp X,             &kp C,             &kp V,             &kp B,             &kp N,             &kp M,             &kp COMMA,         &kp DOT,           &kp SLASH,         \
U_NP,              U_NP,              U_LT(U_MEDIA, ESC),U_LT(U_NAV, SPACE),U_LT(U_MOUSE, TAB),U_LT(U_SYM, RET), U_LT(U_NUM, BSPC), U_LT(U_FUN, DEL),  U_NP,              U_NP
