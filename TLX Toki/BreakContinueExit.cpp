#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;

    for (int i = 0; i <= N; i++){
        if (i < 42){
            if (i % 10 != 0){
                cout << i << endl;
            }

        } else{
            printf("ERROR\n");
            break;
        }
    }   
    return 0;
}