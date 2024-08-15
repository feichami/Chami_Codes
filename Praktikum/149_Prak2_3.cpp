#include <iostream>

using namespace std;

int main (){

    int Y;

    cin >> Y;

    if (Y > 0){
        if (Y%400==0){
            cout << "Tahun Kabisat" << endl;
        } else if (Y%4==0 && Y%100!=0){
            cout << "Tahun Kabisat" << endl;
        } else {
            cout << "Bukan Tahun Kabisat" << endl;
        }
        
        }
    return 0;
}