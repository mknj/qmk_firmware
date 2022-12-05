#pragma once

#include "config_common.h"
//#define TAPPING_TERM 175
#define TAPPING_TERM 300
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* pcb default pin-out */
#define MATRIX_COL_PINS { GP28,GP22,GP21,GP16,GP17,GP27,GP15,GP14,GP13,GP12,GP11,GP10 }
#define MATRIX_ROW_PINS { GP19,GP18,GP20,GP26 }
//#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW
//#define UNICODE_SELECTED_MODES UC_LINX
#define DYNAMIC_KEYMAP_LAYER_COUNT 8
