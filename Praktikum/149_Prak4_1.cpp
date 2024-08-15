#include <iostream>

using namespace std;

int main(){

    int N;
    cin >> N;

    int total = 0;

    for (int i = 0; i < N; i++){   
        int jumah_hewan_dalam_masing_masing_kandang;
        cin >> jumah_hewan_dalam_masing_masing_kandang;
        total += jumah_hewan_dalam_masing_masing_kandang;
    }
    
    cout << total << endl;

    return 0;
}