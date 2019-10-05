/*
 * plot.c - plots sin wave
 * cc plot.c -lm
 * Tom Way, 7/16/97
*/

#include<math.h>
main(){float x,y;while(x+=.1,putchar('\n'))for(y=
-1.;y<=1.03;y+=.03)putchar(y-sin(x)<.01?42:32);}