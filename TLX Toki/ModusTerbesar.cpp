#include <iostream>

using namespace std;

int main(){

    int N;
    int arr[1001] = {0};
    int mx = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
       int k;
       cin >> k;

       arr[k]++;
    }
    
    for (int i = 1; i <= 1000; i++)
    {
        mx = max(mx,arr[i]);
    }
    
    for (int i = 1000; i > 0; i--)
    {
        if (arr[i] == mx)
        {
            cout << i << endl;
            break;
        }
        
    }
    

    return 0;
}
