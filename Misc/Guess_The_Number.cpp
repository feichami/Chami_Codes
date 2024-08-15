#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main(){

    srand(time(0));

    int AnswerNumber = rand() % 100 + 1;
    int tebak;
    int percobaan = 0;
    bool benar = false;

    while (!benar)
    {
     
        cout << "Tebak Angka!" << endl;
        Sleep(350);
        cin >> tebak;
        percobaan++;

        if (tebak == AnswerNumber)
        {
            cout << "Benar! anda sudah mencoba dalam " << percobaan << " kali" << endl;
            benar == true;
            break;
        } else if (tebak < AnswerNumber)
        {
            cout << "angkanya kekecilan" << endl;
        } else {
            cout << "angkanya kegedean" << endl;
        }
        // break;
    }
    

    return 0;
}