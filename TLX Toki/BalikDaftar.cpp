#include <iostream>

using namespace std;

int main(){

    int x[101], i = 0;
    
    while (cin >> x[i])
    {
        i++;
    }
    
    for (int j = i-1; j >= 0; j--)
    {
        cout << x[j] << endl;
    }
    


    
    return 0;
}