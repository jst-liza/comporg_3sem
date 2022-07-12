#include <iostream>
#include <cstdio>
#include<limits>
using namespace std;

#define UC_SIZE sizeof(unsigned char)
#define F_SIZE sizeof(float)

void UC_Bin_Output(unsigned char dec_uc);
void Float_Bin_Output(float dec_fl);
unsigned char UC_Bites(unsigned char uc_raw);
float F_Bites(float f_raw);

int main(){
    int choice, exit = 0;
    cout << "Sup! ";
    do {
        cout << "If you wanna work with unsigned char input - 1, float - 2, something else = exit" << endl;
        cout << "Ur choice: ";
        cin >> choice;
        system("cls");
        switch (choice) {
            case 1: {
                int flag_1, repeat_1;
                do {
                    int num1, result1;
                    cout << "Input the unsigned char(num less than 255, without minus): ";
                    while (!(cin >> num1) || (num1 > 255) || (num1 < 0)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input data. Try again" << endl;
                    }
                    fflush(stdin);
                    cout << "Binary representation:" << endl;
                    UC_Bin_Output(num1);
                    cout << endl << "Do you wanna change some bites?(1 == yes): ";
                    cin >> flag_1;
                    if (flag_1 == 1) {
                        result1 = UC_Bites(num1);
                        cout << "Result: " << result1 << endl;
                        cout << "Binary representation:" << endl;
                        UC_Bin_Output(result1);
                        cout << endl;
                        flag_1 = 0;
                    }
                    cout << "Do you wanna to repeat the algorithm?(1 == yes): ";
                    cin >> repeat_1;
                    system("cls");
                } while (repeat_1 == 1);
                break;
            }

            case 2: {
                int flag_2, repeat_2;
                do {
                    float num2, result2;
                    cout << "Input the float num:" << endl;
                    while (!(cin >> num2)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Incorrect input data. Try again" << endl;
                    }
                    fflush(stdin);
                    cout << "Binary representation:" << endl;
                    Float_Bin_Output(num2);
                    cout << endl << "Do you wanna to change some bites?(1 == yes): ";
                    cin >> flag_2;
                    if (flag_2 == 1) {
                        result2 = F_Bites(num2);
                        cout << "Result: " << result2 << endl;
                        cout << "Binary representation:"<< endl;
                        Float_Bin_Output(result2);
                        cout << endl;
                        flag_2 = 0;
                    }
                    cout << "Do you wanna to repeat the algorithm?(1 == yes): ";
                    cin >> repeat_2;
                    system("cls");
                } while (repeat_2 == 1);
                break;
            }
            default: {
                cout << "Bye!" << endl;
                system("pause");
                exit = 1;
                break;
            }
        }
    } while (exit == 0);
    return 0;
}

void UC_Bin_Output(unsigned char dec_uc){
    for (int i = UC_SIZE * 8 - 1; i >= 0; i--)
        cout << ((dec_uc >> i) & 1);
}

void Float_Bin_Output(float dec_f){
    unsigned char bytes[F_SIZE];
    memcpy(bytes, &dec_f, F_SIZE);
    for (int i = F_SIZE - 1; i >= 0; i--)
        UC_Bin_Output(bytes[i]);
}

unsigned char UC_Bites(unsigned char uc_raw){
    int msb, amount, value, bit;
    cout << "Write msb to begin with(can be 9 -> 1): ";
    while (!(cin >> msb) || (msb > 9) || (msb < 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input data. Try again" << endl;
    }
    fflush(stdin);
    cout << "How many bits you wanna change(from 0 -> 8): ";
    while (!(cin >> amount) || (amount > 8) || (amount < 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input data. Try again" << endl;
    }
    fflush(stdin);
    cout << "Write value(1 or 0): ";
    while (!(cin >> value) || ((value != 1) && (value != 0))) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input data. Try again" << endl;
    }
    fflush(stdin);
    for (int i = msb; i > msb - amount; i--){
        bit = (uc_raw >> i-1) & 1;
        if (bit != value)
            uc_raw += bit ? -(1 << i-1) : (1 << i-1);
    }
    return uc_raw;
}

float F_Bites(float f_raw){
    unsigned char bytes[F_SIZE];
    float f_new;
    int msb, amount, value, bit;
    memcpy(bytes, &f_raw, F_SIZE);
    cout << "Write msb to begin with(can be 32 -> 1): ";
    while (!(cin >> msb) || (msb > 32) || (msb < 1)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input data. Try again" << endl;
    }
    fflush(stdin);
    cout << "How many bits you wanna change(from 0 -> 32): ";
    while (!(cin >> amount) || (amount > 32) || (amount < 0)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input data. Try again" << endl;
    }
    fflush(stdin);
    cout << "Write value(1 or 0): ";
    while (!(cin >> value) || ((value != 1) && (value != 0))) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Incorrect input data. Try again" << endl;
    }
    fflush(stdin);
    for (int i = msb; i > msb - amount; i--){
        int div = (i - 1) / 8, mod = (i - 1) % 8;
        bit = (bytes[div] >> mod) & 1;
        if (bit != value)
            bytes[div] += bit ? -(1 << mod) : (1 << mod);
    }
    memcpy(&f_new, bytes, F_SIZE);
    return f_new;
}