#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;


struct menu_items
{
    string name;
    double harga;
};

void menampikan_menu(const menu_items menu[], int banyak_menu) {
    Sleep(200);
    cout << "Menu Cafe A: " << endl;
    for (int i = 0; i < banyak_menu; i++)
    {
        Sleep(200);
        cout << i + 1 << ". " << menu[i].name << " - $" << fixed << setprecision(2) << menu[i].harga << endl;
    }
}

void masukkan_pesanan(int banyak_pesanan[], int banyak_menu){
    Sleep(200);
    cout << "\nMasukkan Pesanan (nomor dan banyak pesanan), (nol untuk selesai): " << endl;
    int nomor_item, kuantitas;

    while (true)
    {
        cout << "nomor item (nol untuk menyelesaikan) ";
        Sleep(200);
        cin >> nomor_item;

        if(nomor_item == 0){
            break;
        }

        if (nomor_item < 1 || nomor_item >> banyak_menu) {
            cout << "Invalid, mohon isi kembali" << endl;
            continue;
        }
        
        cout << "banyak pesanan: ";
        cin >> kuantitas;

        banyak_pesanan[nomor_item - 1] += kuantitas; 
    }
    
}



int main(){

    const int banyak_menu = 7;
    menu_items menu[banyak_menu] = {
        {"Kopi Luwak", 10.000},
        {"Latte", 11.000},
        {"Espresso", 12.000},
        {"Matcha", 10.000},
        {"Cheese Cake", 15.000},
        {"Sandwich", 12.000},
        {"Chocolate Cake", 15.000}
    };

    int banyak_pesanan[banyak_menu] = {0};

    menampikan_menu(menu, banyak_menu);
    masukkan_pesanan(banyak_pesanan, banyak_menu);

    Sleep(150);
    cout << "\nList Pesanan: " << endl;
    double total_harga = 0.0;

    for (int i = 0; i < banyak_menu; ++i)
    {
        if (banyak_pesanan[i] >0)
        {
        
        double total_pesanan = banyak_pesanan [i] * menu[i].harga;
        Sleep(150);
        cout << menu[i].name << " x " << banyak_pesanan[i] << " - $" << fixed << setprecision(2) << total_pesanan << endl;

        total_harga += total_pesanan;
        }
    }
    
    Sleep(150);
    cout << "\nTotal cost: $" << fixed << setprecision(2) << total_harga << endl;

    return 0;
}