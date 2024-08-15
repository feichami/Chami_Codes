#include <iostream>

using namespace std;

int factorial(int num);

int main(){

    cout << factorial(10);

    return 0;
}

int factorial(int num){       // iterative way
    int result = 1;
    for (int i = 0; i <= num; i++)
    {
        result = result * i;
    }
    return result;
}

if (num > 1)              // recursive approach
    {
        return num * factorial(num - 1);
    }
    else{
        return 1;
    }