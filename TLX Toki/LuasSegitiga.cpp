#include <iostream>
#include <iomanip>

using namespace std;

int main(){

    double a, t, Hasil;

    cin >> a >> t;

    Hasil = 0.5 * a * t;

    cout << fixed << setprecision(2) << Hasil << endl;

    return 0;
}