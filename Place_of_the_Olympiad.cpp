#include <iostream>
using namespace std;
typedef long long ll;


bool canSeat(ll rows, ll cols, ll participants, ll size) {
    ll fullBenches = cols / (size + 1);
    ll remainingSeats = cols % (size + 1);
    ll totalSeats = (size * fullBenches + remainingSeats) * rows;

    return totalSeats >= participants;
}

void findMinBenchSize() {
    ll rows, cols, participants;
    cin >> rows >> cols >> participants;

    ll start = 1, end = cols, result = cols;

    while (start <= end) {
        ll mid = (start + end) / 2;
        if (canSeat(rows, cols, participants, mid)) {
            result = mid;
            end = mid - 1; 
        } else {
            start = mid + 1;
        }
    }

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCases;
    cin >> testCases;
    while (testCases--) {
        findMinBenchSize();
    }

    return 0;
}
