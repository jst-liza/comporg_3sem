#include <conio.h>
#include <stdio.h>
#include <dos.h>
#include <time.h>

void scroll (int direction, int str, char l_row, char l_col, char r_row, char r_col, char attr) {
   union REGS r;
   if (direction) {
      r.h.al = str;
      r.h.ah = direction;
   }
   else {
      r.h.al = str;
      r.h.ah = 6;
   }
   r.h.ch = l_row;
   r.h.cl = l_col;
   r.h.dh = r_row;
   r.h.dl = r_col;
   r.h.bh = attr;
   int86(0x10, &r, &r);
}

int main (){
   clrscr();
   window(20, 5, 60, 15);
   for (int i = 0; i < 16; i++)
      for (int j = 0; j < 16; j++) {
         textbackground (j);
            textcolor (i);
            cprintf("\n\rBackground color: %d", j);
         cprintf("    Text color: %d", i);
           delay(500);
         scroll(6, 3, 4, 19, 14, 59, 0x07,);
         }
   getchar();
   return 0;
}
