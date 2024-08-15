#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <queue>
#include <windows.h>

using namespace std;

struct DataSupir {
    int id;
    string name;
    int birthdate;
    int birthmonth;
    int birthyear;
    char gender;
    string address;
};

struct Node {
    DataSupir data;
    string id; 
    Node *next;
};

struct Order {
    string id;
    string nama;
    string supir;
    string platNomor;
    string tujuan;
    string status;
    Order* next;
};

struct car_unit {
    string license_plate;
    string car_model;
    string car_brand;
    car_unit *next;
    car_unit *prev;
};

car_unit *headCar, *tailCar, *currectCar, *eraseCar, *newNodeCar;
int counterCAr = 0;

class DriverList {
    Node *head;
    Node *tail;
    int idCounter;
    Order *headOrder;
    Order *tailOrder;
    stack<Order> completedOrders;

private:
    queue<Order> antrianPesanan;
    queue<Order> orderQueue;
    queue<Order> acceptedOrders;
    queue<Order> deniedOrders;

public:
    DriverList() : head(nullptr){
        
        head = NULL;
        tail = NULL;
        headOrder = NULL;
        tailOrder = NULL;
        idCounter = 0;
        Order* headOrder = nullptr;
    }
    
Order* getHeadOrder() {
    return headOrder;
}    

    void displayCompletedOrders(){
    stack<Order> tempstack = completedOrders;
    cout << "Order has been receive:" << endl;
    while (!tempstack.empty()) {
        Order currentOrder = tempstack.top();
        cout << "ID            : " << currentOrder.id << endl;
        cout << "Name          : " << currentOrder.nama << endl;
        cout << "Driver        : " << currentOrder.supir << endl;
        cout << "License Plate : " << currentOrder.platNomor << endl;
        cout << "Destination   : " << currentOrder.tujuan << endl;
        cout << endl;
        tempstack.pop();

        Order* current = headOrder;
        while (current != nullptr && current->status != "On process")
        {
            current = current->next;
        }

        if ( current != nullptr){
            current->status = "Order Completed";
        }
    }
}

void addOrderToList(Order newOrder){
    Order* newNode = new Order;
    newNode->id = newOrder.id;
    newNode->nama = newOrder.nama;
    newNode->supir = newOrder.supir;
    newNode->platNomor = newOrder.platNomor;
    newNode->tujuan = newOrder.tujuan;
    newNode->next = nullptr;

    if (headOrder == nullptr) {
        headOrder = newNode;
    } else {
        Order* current = headOrder;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addOrder(Order newOrder){
    Order *newNode = new Order;
    newNode->id = newOrder.id;
    newNode->nama = newOrder.nama;
    newNode->supir = newOrder.supir;
    newNode->platNomor = newOrder.platNomor;
    newNode->tujuan = newOrder.tujuan;
    newNode->next = nullptr;

    if (headOrder == nullptr) {
        headOrder = newNode;
        tailOrder = newNode;
    } else {
        tailOrder->next = newNode;
        tailOrder = newNode;
    }
}

void displayOrders(){
    Order *current = headOrder;
    while (current != nullptr) {
        cout << "ID            : " << current->id << endl;
        cout << "Name          : " << current->nama << endl;
        cout << "Driver        : " << current->supir << endl;
        cout << "License Plate : " << current->platNomor << endl;
        cout << "Destination   : " << current->tujuan << endl;
        cout << endl;
        current = current->next;
    }
}

    string generateId_ForDriver(DataSupir supir) {
        string id = "";
        int hurufAwal = abs(tolower(supir.name[0]) - tolower(supir.name[supir.name.length() - 1]));
        id += to_string(hurufAwal / 10) + to_string(hurufAwal % 10);

        if (supir.gender == 'l' || supir.gender == 'L') {
            id += "1";
        } else {
            id += "0";
        }

        int date = supir.birthdate % 10;
        int month = (supir.birthmonth / 10) + (supir.birthmonth % 10);
        int year = supir.birthyear % 1000;
        int digit4 = (date + month + year) % 9;
        id += to_string(digit4);

        int duplikat = 0;
        Node *temp = head;
        while (temp != NULL) {
            if (temp->id == id + to_string(duplikat)) {
                duplikat++;
            }
            temp = temp->next;
        }
        id += to_string(duplikat);

        return id;
    }    

    void add_DataSupir() {
        DataSupir supir;
        cout << "Insert Name                    : ";
        getline(cin >> ws, supir.name);
        Sleep(300);
        cout << "Insert Date of Birth (dd mm yy): ";
        cin >> supir.birthdate >> supir.birthmonth >> supir.birthyear;
        Sleep(300);
        cout << "Insert Gender (L/P)            : ";
        cin >> supir.gender;
        cin.ignore();
        Sleep(300);
        cout << "Insert Address                 : ";
        getline(cin >> ws, supir.address);

        string id = generateId_ForDriver(supir);
        Node *newNode = new Node;
        newNode->data = supir;
        newNode->id = id;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        idCounter++;

        cout << "Data added successfully!" << endl;
    }

void displaySupir(Node *current) {
        cout << "Name            : " << current->data.name << endl;
        cout << "Id              : " << current->id << "\n";
        cout << "Date of Birth   : " << current->data.birthdate << "-" << current->data.birthmonth << "-" << current->data.birthyear << endl;
        cout << "Gender          : " << current->data.gender << endl;
        cout << "Address         : " << current->data.address << endl;
}

void displayListAdmin() {
        int index = 0;
        Node *current = head;

        while (true) {
            displaySupir(current);
            char choice;
            cout << "1. Next" << endl;
            cout << "2. Previous" << endl;
            cout << "3. Exit" << endl;
            cout << "> ";
            cin >> choice;

            if (choice == '1') {
                if (current->next == NULL) {
                    current = head;
                } else {
                    current = current->next;
                }
            } else if (choice == '2') {
                if (current == head) {
                    while (current->next != NULL) {
                        current = current->next;
                    }
                } else {
                    Node *temp = head;
                    while (temp->next != current) {
                        temp = temp->next;
                    }
                    current = temp;
                }
            } else if (choice == '3') {
                break;
            } else {
                cout << "Your choice is not valid." << endl;
            }
        }
    }

    void edit_SupirData() {
        string idSupir;
        cout << "Insert the Driver's Id that you want to change : ";
        cin >> idSupir;
        
        Node* current = head;
        while (current != NULL && current->id != idSupir) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Driver's Id not found." << endl;
            return;
        }
        
        int choice;
        cout << "- Change Driver's Data with ID of " << idSupir << " -" << endl;
        Sleep(300);
        cout << "1. Change Name" << endl;
        Sleep(300);
        cout << "2. Change Date Of Birth" << endl;
        Sleep(300);
        cout << "3. Change Gender" << endl;
        Sleep(300);
        cout << "4. Change Address" << endl;
        Sleep(300);
        cout << "> ";
        Sleep(300);
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Insert the new name: ";
                cin.ignore();
                getline(cin >> ws, current->data.name);
                current->id = generateId_ForDriver(current->data);
                cout << "Data Id " << idSupir << " has been changed !" << endl;
                break;
            }
            case 2: {
                cout << "Insert the new date of birth (dd mm yyyy) : ";
                cin >> current->data.birthdate >> current->data.birthmonth >> current->data.birthyear;
                current->id = generateId_ForDriver(current->data);
                cout << "Data Id " << idSupir << " has been changed !" << endl;
                break;
            }
            case 3: {
                cout << "Insert the new gender (L/P) : ";
                cin >> current->data.gender;
                current->id = generateId_ForDriver(current->data);
                cout << "Data Id " << idSupir << " has been changed !" << endl;
                break;
            }
            case 4: {
                cout << "Insert the new address: ";
                cin.ignore();
                getline(cin >> ws, current->data.address);
                break;
            }
            default:
            cout << "your choice is not valid." << endl;
        }
        cout << "data has been updated!" << endl;
    }

    void Erase_Supir() {
        string idSupir;
        cout << "Insert the Id you want to delete : ";
        cin >> idSupir;
        
        Node* current = head;
        Node* prev = NULL;
        
        while (current != NULL && current->id != idSupir) {
            prev = current;
            current = current->next;
        }
        if (current == NULL) {
            cout << "Driver's Id is not found" << endl;
        return;
        }
        
        char konfirmasi;
        cout << "Driver's data below is going to be deleted :" << endl;
        
        displaySupir(current);
        cout << "Proceed? (Y/N) > ";
        cin >> konfirmasi;
        
        if (konfirmasi == 'Y' || konfirmasi == 'y') {
            if (prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
        delete current;
        idCounter--;
        cout << "Driver with Id: " << idSupir << " has been deleted !" << endl;
        } else {
            cout << "Driver data deletion is cancelled." << endl;
        }
    }
      
void tambah_mobil(string license_plate, string car_model, string car_brand){

    if (headCar == NULL)
    {
        headCar = new car_unit();
        headCar->license_plate = license_plate;
        headCar->car_model = car_model;
        headCar->car_brand = car_brand;

        headCar->next = NULL;
        tailCar = headCar;
    }else{
        newNodeCar = new car_unit();
        newNodeCar->license_plate = license_plate;
        newNodeCar->car_model = car_model;
        newNodeCar->car_brand = car_brand;

        newNodeCar->prev = tailCar;
        tailCar->next = newNodeCar;
        newNodeCar->next = NULL;
        tailCar = newNodeCar;
    }
}

void tambah_mobil(){
    car_unit mobil;
    char a;

    do
    {
        cout << "Insert the License Number: \n";
        cin.ignore();
        getline(cin, mobil.license_plate);
        Sleep(350);
        cout << "Insert the Car Type: \n";
        cin >> mobil.car_model;
        Sleep(350);
        cout << "Insert the car brand: \n";
        cin >> mobil.car_brand;

        tambah_mobil(mobil.license_plate, mobil.car_model, mobil.car_brand);
        cout << "Data has been added" << endl;
        cout << "Want to add new unit? (y/n): \n";
        cin >> a;
    } while (a == 'Y' || a == 'y');
}

void showCar(){
    
    if (headCar == NULL)
    {
        cout << "There's no data available\n";
    } else {
        currectCar = tailCar;

        if (currectCar != NULL){
            cout << "License Plate" << "-" << "Car Type" << "-" << "Car Model" << endl;
            cout << currectCar->license_plate << "-" << currectCar->car_model << "-" << currectCar->car_brand << endl;
        }
    }
}

void showListOfCars(){
    bool keluar = false;
    do
    {
        showCar();
        char pil;
        cout << "0. exit" << endl;
        cout << "> ";
        cin >> pil;
        switch (pil)
        {
        case '0':
            keluar = true;
            break;
        default:
            cout << "Not Valid" << endl;
            break;
        }
    } while (!exit);
}

void car_out(){
    if (counterCAr == 1){
        currectCar = headCar;
        while (currectCar != NULL){
            eraseCar = currectCar;
            headCar = headCar->next;
            delete eraseCar;
            currectCar = currectCar->next;
        }
        
    } else {
        eraseCar = tailCar;
        tailCar = tailCar->prev;
        tailCar->next = NULL;
        delete eraseCar;
    }
    counterCAr--;
}

void displayListUser() {
    Node *here = head;
    queue<Order> orderQueue;
    string idSupir;

    while (true) {
        displaySupir(here);

        char choice;
        cout << "1. Next" << endl;
        Sleep(300);
        cout << "2. Previous" << endl;
        Sleep(300);
        cout << "3. Order" << endl;
        Sleep(300);
        cout << "4. Exit" << endl;
        Sleep(300);
        cout << "> ";
        cin >> choice;

        if (choice == '1') {
            if (here->next == NULL) {
                here = head;
            } else {
                here = here->next;
            }
        } else if (choice == '2') {
            if (here == head) {
                while (here->next != NULL) {
                    here = here->next;
                }
            } else {
                Node *temp = head;
                while (temp->next != here) {
                    temp = temp->next;
                }
                here = temp;
            }
        } else if (choice == '3') {
            orderMenu();
        } else if (choice == '4') {
            break;
        } else {
            cout << "Your choice is not valid." << endl;
        }
    }
}

void orderMenu(){
    string nama_Pelanggan;
    string tujuan_Pelanggan;
    char orderLagi;

    do {
        cout << "Insert your name > ";
        cin >> nama_Pelanggan;
        cout << "Insert your destination > ";
        cin >> tujuan_Pelanggan;

        string idSupir;
        Node *currentSupir = head;
        cout << "Drivers List:" << endl;
        while (currentSupir != NULL) {
            cout << "Name: " << currentSupir->data.name << " ID: " << currentSupir->id << endl;
            currentSupir = currentSupir->next;
        }
        cout << "Insert the Driver's ID you want to choose: ";
        cin >> idSupir;
        
        Node *current = head;
        while (current != NULL && current->id != idSupir) {
            current = current->next;
        }

        if (current != NULL) {
            DataSupir supirPilihan = current->data;

            string orderId;
            orderId += to_string(toupper("L 1996 YZ"[0]) - 'A' + 1);
            orderId = string(2 - orderId.length(), '0') + orderId;
            orderId += idSupir;
            orderId = string(7 - orderId.length(), '0') + orderId;
            int tujuanSum = toupper(tujuan_Pelanggan[tujuan_Pelanggan.length() - 2]) - 'A' + 1 +
                            toupper(tujuan_Pelanggan[tujuan_Pelanggan.length() - 1]) - 'A' + 1;
            orderId += to_string(tujuanSum);
            orderId = string(9 - orderId.length(), '0') + orderId;
            int nameSum = 0;
            for (char c : nama_Pelanggan) {
                nameSum += toupper(c) - 'A' + 1;
            }
            orderId += to_string(nameSum % 10);

            Order newOrder;
            newOrder.id = orderId;
            newOrder.nama = nama_Pelanggan;
            newOrder.supir = supirPilihan.name;
            newOrder.platNomor = "L 1996 YZ";
            newOrder.tujuan = tujuan_Pelanggan;

            orderQueue.push(newOrder);

            cout << endl;
            cout << "Order has been made !!!" << endl;
            cout << "Id            : " << newOrder.id << endl;
            cout << "Name          : " << newOrder.nama << endl;
            cout << "Driver        : " << newOrder.supir << endl;
            cout << "License Plate : " << newOrder.platNomor << endl;
            cout << "Destination   : " << newOrder.tujuan << endl;
            cout << endl;
            cout << "Driver's ID is not valid. Please try again.\n";
        }

        cout << "Want to another order? (y/n) > ";
        cin >> orderLagi;

    } while (orderLagi == 'y' || orderLagi == 'Y');
}

    void processOrder() {
    if (!orderQueue.empty()) {
        Order order = orderQueue.front();
        orderQueue.pop();
        cout << "ID              : " << order.id << "\n";
        cout << "Name            : " << order.nama << "\n";
        cout << "Driver          : " << order.supir << "\n";
        cout << "License Plate   : " << order.platNomor << "\n";
        cout << "Destination     : " << order.tujuan << "\n";

        char acceptOrder;
        cout << "Accept the Order? (y/n) > ";
        cin >> acceptOrder;

        if (acceptOrder == 'y' || acceptOrder == 'Y') {
            acceptedOrders.push(order);
            cout << "Your order is confirmed." << endl;
            cout << endl;
        } else {
            deniedOrders.push(order);
            cout << "Your order has been declined" << endl;
            cout << endl;
        }
    }else {
        cout << "Nothing here, brudda.\n";
    }
    }

};

/*string DriverList::generateId_ForOrder(int driverId, const string& tujuan, const string& customerName, const string& plateNumber) {
    string orderId;
    
    orderId += to_string(toupper(plateNumber[0]) - 'A' + 1);
    orderId = string(2 - orderId.length(), '0') + orderId;


    orderId += to_string(driverId);
    orderId = string(5 - orderId.length(), '0') + orderId;


    int tujuanSum = toupper(tujuan[tujuan.length() - 2]) - 'A' + 1 +
                         toupper(tujuan[tujuan.length() - 1]) - 'A' + 1;
    orderId += to_string(tujuanSum);
    orderId = string(2 - orderId.length(), '0') + orderId;

    int nameSum = 0;
    for (char c : customerName) {
        nameSum += toupper(c) - 'A' + 1;
    }
    orderId += to_string(nameSum % 10);

    return orderId;
}*/



int main(){
    int pil;

    DriverList obj;

    while (true) {
        cout << "================" << endl;
        cout << "    Welcome!    " << endl;
        cout << "================" << endl;
        Sleep(300);
        cout << "Choose what to do:" << endl;
        Sleep(300);
        cout << "1. Enter as Admin" << endl;
        Sleep(300);
        cout << "2. Enter as User" << endl;
        Sleep(300);
        cout << "3. Exit" << endl;
        Sleep(300);
        cout << "> ";
        cin >> pil;

        if (pil == 1) {
            int pil_admin;
            while (true) {
                cout << "============================" << endl;
                cout << "   Welcome to Admin Panel!  " << endl;
                cout << "============================" << endl;
                Sleep(300);
                cout << "Choose what to do: " << endl;
                Sleep(300);
                cout << "1. Add Driver" << endl;
                Sleep(300);
                cout << "2. Edit Driver's Data" << endl;
                Sleep(300);
                cout << "3. Delete Driver's Data" << endl;
                Sleep(300);
                cout << "4. See Driver List" << endl;
                Sleep(300);
                cout << "5. Process Order" << endl;
                Sleep(300);
                cout << "6. Add Car" << endl;
                Sleep(300);
                cout << "7. See Car List" << endl;
                Sleep(300);
                cout << "0. Back" << endl;
                Sleep(300);
                cout << "> ";
                cin >> pil_admin;

                if (pil_admin == 1) {
                    obj.add_DataSupir();
                } 
                else if (pil_admin == 2) {
                    obj.edit_SupirData();
                } 
                else if (pil_admin == 3) {
                    obj.Erase_Supir();
                } 
                else if (pil_admin == 4) {
                    obj.displayListAdmin();
                } else if (pil_admin == 5) {
                    obj.processOrder();
                } else if (pil_admin == 6){
                    obj.tambah_mobil();
                }else if (pil_admin == 7){
                    obj.showListOfCars();
                } else if (pil_admin == 0) {
                    break;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
            }
        } else if (pil == 2) {
            int pil_user;
                    cout << "=================================" << endl;
                    cout << "      Welcome to User Panel!     " << endl;
                    cout << "=================================" << endl;
                    Sleep(300);
                    cout << "Choose on what to do: " << endl;
                    Sleep(300);
                    cout << "1. See Driver's Data" << endl;
                    Sleep(300);
                    cout << "2. Edit Profile" << endl;
                    Sleep(300);
                    cout << "3. Settings" << endl;
                    Sleep(300);
                    cout << "0. Exit" << endl;
                    Sleep(300);
                    cout << "> ";
                    Sleep(300);
                    cin >> pil_user;
                    
                 if (pil_user == 1) {
                    obj.displayListUser();
                } else if (pil_user == 0) {
                    break;
                } else {
                    cout << "Your choice is not valid." << endl;
                }
        } else if (pil == 3) {
            break;
        } else {
            cout << "Your choice is not valid." << endl;
        }
    }
     return 0;
}

