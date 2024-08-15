#include <iostream>

using namespace std;

int main(){

    int N, T, A, B;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> T;
        if (i == 0){
            B = T;
            A = T;
        } else {
            if (T < B){
                B = T;
            } else if (T > A){
                A = T;
            }
            
            
        }
        
        
    
    }

    cout << A << " " << B;

    return 0;
}