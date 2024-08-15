#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    int arr[n];
    int ans =0 ;

    for (int i = 1; i <= n ; i++){
        cin >> arr[i];
    }
    
    for (int j = 1; j <= n ; j++){
        ans += arr[j];
    }
    
    cout << ans << endl;

    return 0;
}