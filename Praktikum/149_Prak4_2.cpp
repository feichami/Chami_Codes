#include <iostream>
#include <string>

using namespace std;

int main(){

    /*Input Kalimat*/
    string masukan;
    getline (cin, masukan);

    /*Mencari Kata terakhir*/
    int s = masukan.rfind(" "); //* alt bisa find_last_of *//
    string ambil = masukan.substr(s + 1);

    cout << ambil << endl;

    return 0;
}