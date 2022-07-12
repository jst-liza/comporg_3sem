#include <dos.h>
#include <conio.h>
#include <stdio.h>

int key() {
   union REGS r;
   r.h.ah = 0;
   int86(0x16, &r, &r);
   return r.h.ah;
}

int press(){
    union REGS r;
    r.h.ah = 11;
    int86(0x21,&r,&r);
    if (r.h.al==0)
        return 0;
    else
        return 1;
}

int main() {
   int x1 = 20, y1 = 5, x2 = 60, y2 = 15;
    int x = 40, y = 10, ch = 0, direction = 0;
    clrscr();
    window(x1, y1, x2, y2);
   do {
      do {
         clrscr();
         if (direction == 1)
            if (x > 1)
                    x -= 1;
            else if (y == 1) {
               y = y2-y1;
               x = x2-x1;
            }
            else {
               y -= 1;
               x = x2-x1;
            }
         if (direction == 0)
            if (x < x2-x1)
                    x += 1;
            else if (y == y2-y1+1) {
               y = 1;
               x = 1;
            }
            else {
               y += 1;
               x = 1;
            }
         gotoxy(x, y);
         putch('*');
         delay(100);
      } while (press() == 0);
      ch = key();
         switch (ch) {
         case 59:
            direction = 1;
            break;
         case 60:
            direction = 0;
            break;
         }

   } while (ch != 1);
   return 0;
}