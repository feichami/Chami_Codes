#include <iostream>

using namespace std;

int main(){

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int jarak_x = x1 - x2;
    int jarak_y = y1 - y2;

    if (jarak_x < 0){
        jarak_x = jarak_x * -1;
    }
    if (jarak_y < 0){
        jarak_y = jarak_y * -1;
    }
    
    int result = jarak_x + jarak_y;

    cout << result << endl;


    return 0;
}