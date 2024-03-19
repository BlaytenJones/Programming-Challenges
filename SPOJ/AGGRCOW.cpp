#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool can_place_cows(const vector<int>& stalls, int cows, int min_distance) {
    int placed_cows = 1;
    int last_position = stalls[0];
    size_t size = stalls.size();
    for (size_t i = 1; i < size; ++i) {
        if (stalls[i] - last_position >= min_distance) {
            placed_cows++;
            last_position = stalls[i];
        }
        if (placed_cows == cows) return true;
    }
    return false;
}

int max_min_distance(vector<int>& stalls, int cows) {
    sort(stalls.begin(), stalls.end());
    int start = 0; int end = stalls.back() - stalls[0];
    int result = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (can_place_cows(stalls, cows, mid)) {
            result = mid;
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return result;
}

int main() {
    long unsigned numCases; cin >> numCases;
    for (size_t i = 0; i < numCases; i++) {
        unsigned int N, C;
        cin >> N >> C;
        vector<int> stall_locations(N);
        for (size_t j = 0; j < N; j++) {
            cin >> stall_locations[j];
        }
        cout << max_min_distance(stall_locations, C) << endl;
    }
    return 0;
}
