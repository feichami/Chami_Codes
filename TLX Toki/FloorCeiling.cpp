#include <iostream>
#include <cmath>

using namespace std;

int main(){

    float input;
    scanf("%f", &input);

    int N = trunc(input);

    if (input == N){
        printf("%d %d", N, N);
    }
    else if (input > 0){
        printf("%d %d", N, N+1);
    }
    else if (input < 0){
        printf("%d %d", N-1, N);
    }
    
    return 0;
}