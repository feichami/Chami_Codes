#include <iostream>

using namespace std;

int main(){

    int values[5] = {3,1,6,7,10};
    for (int i = 0; i < 5; i++){
        cout << values[i] << endl;
    }

    values[3] = -13;

    for (int i = 0; i < 5; i++){
        cout << values[i] << endl;
    }
    

    return 0;
}