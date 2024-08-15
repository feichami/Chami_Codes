#include <iostream>

using namespace std;

void PerintahArray(int arr[], int T){

	// looping untuk angka/bil yg akan di jabarkan
	for (int i = 0; i < T; i++){
		cin >> arr[i];
	}
	// pengambilan 3 bilangan tengah
	cout << arr[T/2-1] << arr[T/2] << arr[T/2+1];
}

int main(){

	// input banyak bilangan
	int T;
	cin >> T;

	int arr[T];	

	PerintahArray(arr, T);

	return 0;
}