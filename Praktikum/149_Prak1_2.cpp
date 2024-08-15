#include <iostream>
#include <cmath>

using namespace std;

int main(){

    int nilaiTugas, nilaiKuis, nilaiUTS, nilaiUAS;
    double nilaiAkhir;

    cin >> nilaiTugas;

    cin >> nilaiKuis;

    cin >> nilaiUTS;

    cin >> nilaiUAS;

    nilaiAkhir = (0.2 * nilaiTugas) + (0.2 * nilaiKuis) + (0.3 * nilaiUTS) + (0.3 * nilaiUAS);

    cout << nilaiAkhir << endl;

    return 0;
}