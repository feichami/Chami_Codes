#include "Act_Selection.h"
#include <vector>
#include <iostream>

using namespace std;

bool compare(Aktivitas a1, Aktivitas a2) {
    return a1.finish < a2.finish;
};

void ActivitySelection::addActivity(int start, int finish) {
    Activity activity = {start, finish};
    activities.push_back(activity);
}

void ActivitySelection::selectActivities() const {
    // Urutkan aktivitas berdasarkan waktu selesai
    vector<Activity> sortedActivities = activities;
    sort(sortedActivities.begin(), sortedActivities.end(), compare);

    cout << "Selected activities: \n";

    // Pilih aktivitas pertama
    int lastFinishTime = sortedActivities[0].finish;
    cout << "Activity(" << sortedActivities[0].start << ", " << sortedActivities[0].finish << ")\n";

    // Pilih aktivitas berikutnya yang mulai setelah aktivitas yang dipilih terakhir selesai
    for (size_t i = 1; i < sortedActivities.size(); ++i) {
        if (sortedActivities[i].start >= lastFinishTime) {
            cout << "Activity(" << sortedActivities[i].start << ", " << sortedActivities[i].finish << ")\n";
            lastFinishTime = sortedActivities[i].finish;
        }
    }
}