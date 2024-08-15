#include <iostream>

using namespace std;

int main(int argc, char** argv){
    int mat1[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    cout << "Diberikan matriks"<< endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << mat1[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "transpos matriks" << endl;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout<<mat1[j][i] << "\t";
        }
        cout << endl;
    }
    
    
    



    return 0;
}