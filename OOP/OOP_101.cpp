#include <iostream>
#include <windows.h>

using namespace std;

class AbstractPromotion{
    virtual void AskForPromotion() = 0;
};

class Karyawan:AbstractPromotion {
private:
    string Nama; 
    string Perusahaan;
    int Umur;
public:
    void setName(string nama){
        Nama = nama;
    }
    string getName(){
        return Nama;
    }

    void setPerusahaan(string perusahaan){
        Perusahaan = perusahaan;
    }
    string getPerusahaan(){
        return Perusahaan;
    }

    void setUmur(int umur){
        if (umur >= 18)
        {
            Umur = umur;
        }
    }
    int getUmur(){
        return Umur;
    }

    void Perkenalan(){
        cout << "===============\n";
        Sleep(200);
        cout << "Nama: " << Nama << endl;
        Sleep(200);
        cout << "Perusahaan: " << Perusahaan << endl;
        Sleep(200);
        cout << "Umur: " << Umur << endl;
        Sleep(200);
        cout << "===============\n";
    }

    void AskForPromotion(){
        if (Umur > 30){
            cout << "Selamat, "<< Nama << "  Anda mendapat promosi" << endl;
        } else{
            cout << Nama << " tidak eligible untuk dapat promosi" << endl;
        }

    }

    Karyawan(string nama, string perusahaan, int umur){
        Nama = nama;
        Perusahaan = perusahaan;
        Umur = umur;

    }
};


int main(){

    string nama;
    string perusahaan;
    int umur;

    cout << "Masukkan Nama: ";
    getline(cin, nama);

    cout << "Masukkan Perusahaan: ";
    getline(cin, perusahaan);

    cout << "Masukkan Umur: ";
    cin >> umur;


    Karyawan karyawan_1 = Karyawan(nama, perusahaan, umur);
    //Karyawan karyawan_2 = Karyawan("Joan", "Swasta", 35);

    karyawan_1.AskForPromotion();
    //karyawan_2.AskForPromotion();

    //karyawan_1.setUmur(17);
    //Sleep(200);
    //cout << karyawan_1.getName() << " berumur " << karyawan_1.getUmur() << endl;
}