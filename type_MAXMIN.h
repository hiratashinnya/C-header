#ifndef _TYPE_MAXMIN_

#define _TYPE_MAXMIN_ /* typedef and set maxmin */
#include "type.h"   /* typedef */

/* max */
#define U1_MAX (U1)0xFF
#define U2_MAX (U2)0xFFFF
#define U4_MAX (U4)0xFFFFFFFF
#define S1_MAX (S1)0x7F
#define S2_MAX (S2)0x7FFF
#define S4_MAX (S4)0x7FFFFFFF

/* min */
#define U1_MIN (U1)0x00
#define U2_MIN (U2)0x0000
#define U4_MIN (U4)0x00000000
#define S1_MIN (S1)0x80
#define S2_MIN (S2)0x8000
#define S4_MIN (S4)0x80000000

#endif