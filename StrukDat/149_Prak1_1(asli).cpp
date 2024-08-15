#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int id;
    string nama;
    int tgl_lahir, bulan_lahir, tahun_lahir;
    char kelamin;
    string alamat;
    
    Node *next;
};

Node *head = nullptr;

void create(Node* &head, int id, string nama, int tgl_lahir, int bulan_lahir, int tahun_lahir, char kelamin, string alamat){
    
    Node *newNode = new Node;
    newNode->id = id;
    newNode->nama = nama;
    newNode->tgl_lahir = tgl_lahir;
    newNode->bulan_lahir = bulan_lahir;
    newNode->tahun_lahir = tahun_lahir;
    newNode->kelamin = kelamin;
    newNode->alamat = alamat;
    newNode->next = nullptr;
    
    if (head == nullptr){
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next != nullptr){
        temp = temp->next;
        } 
        temp->next = newNode;
    }
}

void show_data(Node* data_supir) {
    if (data_supir == nullptr) {
        cout << "Data sopir tidak ditemukan" << endl;
        return;
    }

    cout << "ID: " << data_supir->id << endl;
    cout << "Nama: " << data_supir->nama << endl;
    cout << "Tanggal Lahir: " << data_supir->tgl_lahir << "-" << data_supir->bulan_lahir << "-" << data_supir->tahun_lahir << endl;
    cout << "Jenis Kelamin: " << data_supir->kelamin << endl;
    cout << "Alamat: " << data_supir->alamat << endl;
}

void show_datalain(Node* head){

    if (head == nullptr) {
        cout << "Data sopir tidak ditemukan" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        show_data(temp);
        cout << "1. Next "<< endl;
        cout << "2. Previous " << endl;
        cout << "0. Exit" << endl;
        int pilihan;
        cout << "> ";
        cin >> pilihan;

        if (pilihan == 1) {
            temp = temp->next;
        } else if (pilihan == 2 && temp != head) {
            Node* prev = head;
            while (prev->next != temp) {
                prev = prev->next;
            }
            temp = prev;
        } else if (pilihan == 0) {
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }
}

void update(){
    int id;
    int pilihan;

    cout << "Input ID supir yang ingin diubah: \n";
    cin >> id;
    Node *temp = head;
    
    cout << "- Mengubah supir dengan Id " << id << " -\n";
    cout << "1. Ubah Nama\n";
    cout << "2. Ubah Kelamin\n";
    cout << "3. Ubah Alamat\n";
    cout << "4. Ubah Tgl Lahir\n";
    cout << "> ";
    cin >> pilihan;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            switch (pilihan) {
            case 1:
            cin >> temp->nama;
            break;
            case 2:
            cin >> temp->kelamin;
            break;
            case 3:
            cin >> temp->alamat;
            break;
            case 4:
            cin >> temp->tgl_lahir;
            break;

            default:
                break;
            }
        break;
        }
    temp = temp->next;
    }
    if (temp == NULL){
        cout << "Data supir dgn ID " << id << "tidak ditemukan\n";
    }
}

void delete_data(){
    int id;
    cout << "Masukkan id supir yg ingin dihapus: \n";
    cin >> id;

    Node *temp = head, *prev = NULL;
    while (temp != NULL){
        if (prev == NULL){
            if (temp->id == id){
                head = head->next;
                } else {
                prev->next = temp->next;
                }
            delete temp;
            break;
        }
    prev = temp;
    temp = temp->next;
    }
    
    if (temp == NULL){
        cout << "Data supir dgn id " << id << "tidak ditemukan!\n";
    }
}

void HapusData(Node* &head){
    Node* temp;
    while (head = nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


int main(){

    int pilihan;
    do {
    cout << "=========================================\n";
    cout << "\t Selamat Datang \t\t\n";
    cout << "=========================================\n";
    cout << "1. Masuk sebagai Admin\n";
    cout << "2. Masuk sebagai User\n";
    cout << "0. Exit\n";
    cout << "> ";
    cin >> pilihan;

    switch (pilihan) {
        case 1: {
            int pilihanAdmin;
            do {
                cout << "======== Dashboard Admin ========\n";
                cout << "1. Menambah Data Supir\n";
                cout << "2. Menghapus Data Supir\n";
                cout << "3. Mengubah Data Supir\n";
                cout << "4. Menampilkan Data Supir\n";
                cout << "0. Exit\n";
                cout << "> ";
                cin >> pilihanAdmin;

                switch (pilihanAdmin) {
                    case 1: {
                        int id, tgl_lahir, bulan_lahir, tahun_lahir;
                        string nama, alamat;
                        char kelamin;

                        cout << "Masukkan ID: ";
                        cin >> id;
                        cout << "Masukkan Nama: ";
                        cin.ignore();
                        getline(cin, nama);
                        cout << "Masukkan tanggal lahir: ";
                        cin >> tgl_lahir >> bulan_lahir >> tahun_lahir;
                        cout << "Masukkan Gender (L/P): ";
                        cin >> kelamin;
                        cout << "Masukkan Alamat: ";
                        cin.ignore();
                        getline(cin, alamat);
    
                        create(head, id, nama, tgl_lahir, bulan_lahir, tahun_lahir, kelamin, alamat);
                        cout << "Data sopir berhasil ditambahkan" << endl;
                        break;
                    }
                    case 2:
                        cout << "Menghapus data supir\n";
                        delete_data();
                        break;

                    case 3:
                        cout << "Mengubah data supir\n";
                        update();
                        break;

                    case 4:
                        show_datalain(head);
                        break;

                    case 0:
                        cout << "Keluar dari Menu Admin\n";
                        break;
                    default:
                        cout << "Pilihan tidak tersedia\n";
                        break;
                }
            } while (pilihanAdmin != 0);
            break;
        }
    
        case 2: {
            int pilihanUser;
                do {
                    cout << "===============================" << endl;
                    cout << "         USER DASHBOARD        " << endl;
                    cout << "===============================" << endl;
                    cout << "1. Lihat data" << endl;
                    cout << "2. Mengedit profil" << endl;
                    cout << "3. Pengaturan" << endl;
                    cout << "0. Keluar" << endl;
                    cout << "> ";
                    cin >> pilihanUser;

                    switch (pilihanUser) {
                        case 1:
                            cout << "Lihat data" << endl;
                            break;

                        case 2:
                            cout << "Mengedit profil" << endl;
                            break;

                        case 3:
                            cout << "Pengaturan" << endl;
                            break;

                        case 0:
                            cout << "Keluar dari User Dashboard" << endl;
                            break;

                        default:
                            cout << "Pilihan tidak tersedia" << endl;
                            break;
                    }
                } while (pilihanUser != 0);
                break;
            }

            case 0:
                cout << "Keluar dari Program" << endl;
                break;

            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
        }
    } while (pilihan != 0);

    HapusData(head);

    return 0;
}