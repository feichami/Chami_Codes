#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

void clear_screen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void sleep_ms(int miliseconds){

#ifdef _WIN32
    Sleep(miliseconds);
#else
    usleep(miliseconds * 1000);
#endif
}

int main(){

    srand(time(nullptr));

    clear_screen();

    cout << "Pesan lemao\n\n";

    int D;
    while (true)
    {
        cout << "sesusah apa bg? ";
        cin >> D;
        if (D > 4 && D <= 10)
        {
            break;
        }
        cout << "masukkan angka dari 1 sampai 10\n";
    }

    string M;
    for (int i = 0; i < D; i++)
    {
        M += 'A' + rand() % 26;
    }
    
    clear_screen();

    cout << "kirim kode abgkuh! " << M << endl;

    sleep_ms(500 * D);

    clear_screen();

    cin.ignore();
    string N;
    getline(cin, N);

    if (N == M)
    {
        cout << "anjay bang bener\nwar is over" << endl;
    } else {
        cout << "salah kau bang\ntolol" << endl;
    }

    return 0;
}