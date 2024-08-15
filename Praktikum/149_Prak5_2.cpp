#include <iostream>

using namespace std;

string fbnstrg(int a, string u[]){

    //hitungan bil. fibonacci
    if (a == 0){
        return u[0];
    }
    else if (a == 1){
        return u[1];
    }
    else{
        return fbnstrg(a - 1, u) + fbnstrg(a - 2, u);
    }
    
}

int main(){

    // input jumlah yang fibonacci yg ingin dihitung
    int a, T, i;
    cin >> T;

    string u[2];
    string hasil[T];


    // looping untuk masukan angka & karakter, i.e "2 a b"
    for (i = 0; i < T; i++){
        cin >> a >> u[0] >> u[1];
        hasil[i] = fbnstrg(a, u);
    }    
    // looping untuk output
    for (i = 0; i < T; i++){
        cout << "Case #" << i + 1 << ": " << hasil[i] << endl;
    }
    return 0;
}






