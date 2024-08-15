    #include <iostream>

    using namespace std;

    int main(){

        int a, b = 0;

        while (scanf("%d", &a) != EOF){
            b += a;
        }
        
        printf ("%d", b);

        return 0;
    }