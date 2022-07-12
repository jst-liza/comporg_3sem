#include <dos.h>
#include <stdlib.h>
#include <bios.h>
#include <conio.h>

int k;
void interrupt(*oldvec)(...);
void interrupt flag(...) {
    k = rand() % 3 + 1;
    clrscr();
    if (k==1) {
        cprintf("\n\r");
        cprintf("\n\r");
        cprintf(" .       .  \n\r");
        cprintf(" |\\_---_/|  \n\r");
        cprintf("/   o_o   \\ \n\r");
        cprintf("|    U    | \n\r");
        cprintf("\\  ._I_.  / \n\r");
        cprintf(" `-_____-'  \n\r");
        delay(200);
        }

        else {
            if(k==2) {
                cprintf("\n\r");
                cprintf("\n\r");
                cprintf(" .       .  \n\r");
                cprintf(" |\\_---_/|  \n\r");
                cprintf("/   o_o   \\ \n\r");
                cprintf("|    U    | \n\r");
                cprintf("\\  -_I_-  / \n\r");
                cprintf(" `-_____-'  \n\r");
                delay(200);
                }
        else {
            if (k==3) {
            cprintf("\n\r");
                cprintf("\n\r");
                cprintf(" .       .  \n\r");
                cprintf(" |\\_---_/|  \n\r");
                cprintf("/   o_o   \\ \n\r");
                cprintf("|    U    | \n\r");
                cprintf("\\  \\_I_/  / \n\r");
                cprintf(" `-_____-'  \n\r");
                delay(200);
                }
        }
    }
}
int main() {
    srand(time(NULL));
    _setcursortype(_NOCURSOR);
    oldvec = getvect(0x1c);
    setvect(0x1c,flag);
    getch();
    setvect(0x1c,oldvec);
    return 0;
}
