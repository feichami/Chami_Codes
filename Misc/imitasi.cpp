#include <iostream>
#include <string>

using namespace std;

struct date
{
    int tgl;
    int bulan;
    int tahun;
};

struct supir
{
    string id;
    string nama;
    date tglLahir;
    char kelamin;
    string alamat;
    supir *prev;
    supir *next;
};

supir *head, *tmp;

void tampil(supir *i)
{
    supir *index;
    index = i;

    if (head != NULL)
    {
        if (index != nullptr)
        {
            cout << "|----------------------------------- \n"
                 << "|Nama\t\t: " << index->nama << "\n"
                 << "|Id\t\t: " << index->id << "\n"
                 << "|Tgl Lahir\t: " << index->tglLahir.tgl << '-' << index->tglLahir.bulan << '-' << index->tglLahir.tahun << "\n";

            if (index->kelamin == 'l')
            {
                cout << "|Kelamin\t: Laki-laki \n";
            }
            else if (index->kelamin == 'p')
            {
                cout << "|Kelamin\t: Perempuan \n";
            }

            cout << "|Alamat\t\t: " << index->alamat << "\n"
                 << "|----------------------------------- \n";
        }
    }
    else
    {
        cout << "Supir masih kosong \n";
    }
}

void menu()
{
    system("cls");
    cout << "==================== \n"
         << "Selamat Datang !! \n"
         << "==================== \n"
         << "1. Masuk Sebagai Admin \n"
         << "2. Masuk Sebagai User \n"
         << "0. Keluar program \n"
         << "> ";
}

void admin()
{
    system("cls");
    cout << "==== Dashboard Admin ==== \n \n"
         << "1. Mencari Data Supir \n"
         << "2. Menghapus Data Supir \n"
         << "3. Mengubah Data Supir \n"
         << "4. Menambah Data Supir \n"
         << "0. Exit \n"
         << "> ";
}

void user(supir *i)
{
    system("cls");
    tampil(i);
    cout << "1. Next \n"
         << "2. Prev \n"
         << "3. Order \n"
         << "0. Exit \n"
         << "> ";
}

void pressAny()
{
    string any;
    cout << "\nketik apa saja utk kembali ke menu sebelumnya \n> ";
    cin >> any;
}

supir *search(string id)
{
    supir *index;
    index = head;

    while (index != nullptr)
    {
        if (index->id == id)
        {
            return index;
        }
        index = index->next;

        if (index == head)
        {
            break;
        }
    }

    cout << "id tidak ditemukan \n";
    return nullptr;
}

string checkId(string newId)
{
    int i = 0;
    while (search(newId) != nullptr && i <= 9)
    {
        newId = newId.substr(0, newId.length() - 1) + to_string(i);
        i++;
    }
    if (search(newId) != nullptr)
    {
        newId = newId.substr(0, newId.length() - 1) + "00";
        newId = checkId(newId);
    }
    else
    {
        system("cls");
    }

    return newId;
}

string generateId(string newName, char newGender, int newDate, int newMonth, int newYear)
{
    string newId;
    int i = 0;

    while (newName[i] != '\0')
    {
        if (newName[i] >= 'A' && newName[i] <= 'Z')
        {
            newName[i] = newName[i] + 32;
        }
        else
        {
        }
        i++;
    }

    int d1 = abs((int)newName[0] - (int)newName[newName.length() - 1]);
    int d2;
    if (newGender == 'l')
    {
        d2 = 1;
    }
    else if (newGender == 'p')
    {
        d2 = 0;
    }
    int d3 = (newDate % 10 + newMonth % 10 + newYear % 10) % 9;

    if (d1 <= 9)
    {
        newId = '0' + to_string(d1) + to_string(d2) + to_string(d3) + '0';
    }
    else
    {
        newId = to_string(d1) + to_string(d2) + to_string(d3) + '0';
    }

    return checkId(newId);
}

void tambah()
{
    system("cls");
    string newName, newAddress;
    int newDate, newMonth, newYear;
    char newGender;
    cout << "Nama: ";
    cin.ignore();
    getline(cin, newName);
    cout << "Tgl lahir (dd): ";
    cin >> newDate;
    cout << "Bulan lahir (mm): ";
    cin >> newMonth;
    cout << "Tahun lahir (yyyy): ";
    cin >> newYear;
    cout << "Kelamin (l/p): ";
    cin >> newGender;
    cout << "Alamat: ";
    cin.ignore();
    getline(cin, newAddress);

    supir *baru;
    baru = new supir;
    baru->id = generateId(newName, newGender, newDate, newMonth, newYear);
    baru->nama = newName;
    baru->tglLahir.tgl = newDate;
    baru->tglLahir.bulan = newMonth;
    baru->tglLahir.tahun = newYear;
    baru->kelamin = newGender;
    baru->alamat = newAddress;
    baru->next = baru;
    baru->prev = baru;
    if (head == NULL)
    {
        head = baru;
        head->next = head;
        head->prev = head;
    }
    else
    {
        tmp = head->prev;
        tmp->next = baru;
        baru->prev = tmp;
        baru->next = head;
        head->prev = baru;
    }
    cout << "Supir telah ditambahkan\n";
}

void hapus(string id)
{
    system("cls");
    supir *hapus;

    hapus = search(id);

    if (head != NULL)
    {
        if (hapus != nullptr)
        {
            tampil(hapus);
            char sure;
            cout << "Lanjutkan ? (y/n) >";
            cin >> sure;

            if (sure == 'y')
            {
                if (hapus != hapus->prev)
                {
                    hapus->prev->next = hapus->next;
                    hapus->next->prev = hapus->prev;
                    delete hapus;
                }
                else
                {
                    head = NULL;
                    delete hapus;
                }
            }

            cout << "Supir dengan id " << id << " terhapus\n";
        }
    }
    else
        cout << "Masih kosong\n";
}

void update(string id)
{
    system("cls");
    supir *update;

    update = search(id);

    tampil(update);

    if (head != NULL)
    {
        if (update != nullptr)
        {
            int pilihUbah;
            cout << "- Mengubah supir dengan id" << id << " -\n\n"
                 << "1. Ubah Nama \n"
                 << "2. Ubah Kelamin \n"
                 << "3. Ubah Alamat \n"
                 << "4. Ubah Tgl Lahir \n"
                 << "> ";
            cin >> pilihUbah;

            if (pilihUbah == 1)
            {
                string updateName;
                cout << "\nMasukkan nama baru \n> ";
                cin.ignore();
                getline(cin, updateName);
                update->nama = updateName;
            }
            else if (pilihUbah == 2)
            {
                char updateGender;
                cout << "\nMasukkan kelamin baru (l/p) \n> ";
                cin >> updateGender;
                update->kelamin = updateGender;
            }
            else if (pilihUbah == 3)
            {
                string updateAddress;
                cout << "\nMasukkan alamat baru \n> ";
                cin.ignore();
                getline(cin, updateAddress);
                update->alamat = updateAddress;
            }
            else if (pilihUbah == 4)
            {
                int updateDate, updateMonth, updateYear;
                cout << "\nMasukkan tanggal lahir baru (dd) > ";
                cin >> updateDate;
                cout << "\nMasukkan bulan lahir baru (mm) > ";
                cin >> updateMonth;
                cout << "\nMasukkan tahun lahir baru (yyyy) > ";
                cin >> updateYear;
                update->tglLahir.tgl = updateDate;
                update->tglLahir.bulan = updateMonth;
                update->tglLahir.tahun = updateYear;
            }

            update->id = generateId(update->nama, update->kelamin, update->tglLahir.tgl, update->tglLahir.bulan, update->tglLahir.tahun);

            cout << "\nSupir dengan id " << id << " diupdate\n";
        }
    }
    else
        cout << "Masih kosong\n";
}

int main()
{
    int pilihMenu, pilihAdmin, pilihUser;
    while (pilihMenu != 0)
    {
        menu();
        cin >> pilihMenu;
        pilihAdmin = 1;
        pilihUser = 1;
        if (pilihMenu == 1)
        {
            while (pilihAdmin != 0)
            {
                admin();
                cin >> pilihAdmin;
                if (head != NULL && pilihAdmin != 4)
                {
                    if (pilihAdmin == 1)
                    {
                        string idSearch;
                        cout << "Masukkan id supir yg mau dicari: ";
                        cin >> idSearch;

                        system("cls");
                        tampil(search(idSearch));

                        pressAny();
                    }
                    else if (pilihAdmin == 2)
                    {
                        string idHapus;
                        cout << "Masukkan id supir yg mau dihapus: ";
                        cin >> idHapus;
                        hapus(idHapus);

                        pressAny();
                    }
                    else if (pilihAdmin == 3)
                    {
                        string idUpdate;
                        cout << "Masukkan id supir yg mau update: ";
                        cin >> idUpdate;
                        update(idUpdate);

                        pressAny();
                    }
                }
                else if (pilihAdmin == 4)
                {
                    tambah();

                    pressAny();
                }
                else if (pilihAdmin == 0)
                {
                }
                else
                {
                    system("cls");
                    cout << "\ndata masih kosong atau inputan salah \n";
                    pressAny();
                }
            }
        }

        else if (pilihMenu == 2)
        {
            supir *i;
            i = head;
            while (pilihUser != 0)
            {
                user(i);
                cin >> pilihUser;

                if (head != NULL)
                {
                    if (pilihUser == 1)
                    {
                        i = i->next;
                    }
                    else if (pilihUser == 2)
                    {
                        i = i->prev;
                    }
                    else if (pilihUser == 3)
                    {
                        cout << "---------- Terimakasih telah order ---------- \n";
                        pressAny();
                        pilihUser = 0;
                    }
                }
            }
        }
        system("cls");
        cout << "Babay - babayy";
    }
}