#ifdef ACTIVITY_SELECTION_H
#define ACTIVITY_SELECTION_H

#include <vector>
#include "act.h"

using namespace std;

class Seleksi_Aktivitas {
private:
    vector<Aktivitas> aktivitas;    
public:
    void tambahAktivitas(int start, int finish);
    void pilihAktivitas() const;
};

#endif