#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main() {

    /*Input Kata*/
    string KXA, KXB;
    getline (cin, KXA);
    getline (cin, KXB);

    /*memastikan biar kata A & B tidak sama*/
    if (KXA == KXB)
    {
        cout << "BUKAN" << endl;
        return 0;
    }

    /*biar ga salah ye kan*/
    sort(KXA.begin(), KXA.end());
    sort(KXB.begin(), KXB.end());

    /*koreksi dlu sayyy*/
    if (KXA == KXB) {
        cout << "YA" << endl;
            } else {
                cout << "BUKAN" << endl;
    }

    return 0;
}
