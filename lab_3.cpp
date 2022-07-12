#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <conio.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int graph_driver = DETECT, graph_mode, graph_ec;
    float real_value[590]; int dots_x_y[590];
    int i, coef = 10;
    float max_value = -1;
    char a[2][30] = {"Max value of function = 7,808"};
    char signature[28][5] = {"0", "pi", "2", "3", "4", "5", "6", "7", "8", "9",
                             "10","11", "12", "13", "14", "15", "16", "17", "18pi",
                             "1", "2", "3", "4", "5", "6", "7", "8"};

    initgraph(&graph_driver, &graph_mode, "C:\\TC\\BGI");
    graph_ec = graphresult();

    if (graph_ec != grOk) {
        return 255;
    }
    else {
        setbkcolor(0);
        setcolor(4);

        real_value[0] = 3*M_PI/2; //x0
        for (i = 1; i < 590; i += 2) {
            real_value[i]= - pow(sin(real_value[i - 1] / 4), 2) + sqrt(real_value[i - 1]);
            real_value[i + 1]= real_value[i - 1] + M_PI / 19;
            if ((real_value[i] >= max_value) && (i % 2 == 1))
                max_value = real_value[i];
        }
        for (i = 0; i < 590; ++i) {
            if (i % 2 == 0)
                dots_x_y[i] = int(real_value[i] * coef) + 20;
            else
                dots_x_y[i] = 120 - int(real_value[i] * coef);
        }
        drawpoly(295, dots_x_y);

        setcolor(12);
        line(20,10,20,130); // Vert
        line(10,120,600,120); //Hor
        line(20,10,15,15); //ArrVleft
        line(20,10,25,15); //ArrVright
        line(600,120,595,115); //ArrHup
        line(600,120,595,125); //ArrHdown

        for (i = 0; i <= 18; ++i) {
            if (i) {
                line(20 + i*M_PI*coef, 115, 20 + i*M_PI*coef, 125);
                line(5 + i*M_PI*coef, 118, 5 + i*M_PI*coef, 122);
            }
            outtextxy(19 + i*M_PI*coef, 130, signature[i]);
        }
        for (i = 1; i <= 8; ++i) {
            line(15, 120-i*coef, 25, 120-i*coef);
            outtextxy(5, 115-i*coef, signature[i + 18]);
        }

        setlinestyle(0,0,3);
        line(10,150,600,150);
        settextstyle(0,0,1);
        outtextxy(20,165,a[0]);

        getch();
        clrscr();
        closegraph();
    }
    return 0;
}
