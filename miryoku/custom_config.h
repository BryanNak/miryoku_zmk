// Copyright 2021 Manna Harbour
// https://github.com/manna-harbour/miryoku
//

#undef MIRYOKU_SHIFT_FUNCTION
#define MIRYOKU_SHIFT_FUNCTION(alphas_tap, mod) &hml mod alphas_tap

#undef MIRYOKU_SHIFT_FUNCTION_R
#define MIRYOKU_SHIFT_FUNCTION_R(alphas_tap, mod) &hmr mod alphas_tap
