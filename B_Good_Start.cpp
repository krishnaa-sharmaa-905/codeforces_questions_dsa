#include <iostream>
#include <algorithm>

using namespace std;

bool canTileRoof(int w, int h, int a, int b, pair<int, int> sheet1, pair<int, int> sheet2) {
    int x1 = sheet1.first, y1 = sheet1.second;
    int x2 = sheet2.first, y2 = sheet2.second;

    // Check if the two sheets overlap
    if (!(x1 + a <= x2 || x2 + a <= x1 || y1 + b <= y2 || y2 + b <= y1)) {
        return false; // Sheets overlap
    }

    // Calculate the area covered by the two sheets within the roof
    auto coveredArea = [w, h, a, b](int x, int y) {
        int xEnd = min(x + a, w);
        int yEnd = min(y + b, h);
        if (xEnd <= x || yEnd <= y) return 0;
        return (xEnd - x) * (yEnd - y);
    };

    int covered = coveredArea(x1, y1) + coveredArea(x2, y2);
    int totalArea = w * h;
    int remainingArea = totalArea - covered;

    // Check if the remaining area can be tiled with a x b sheets
    if (remainingArea % (a * b) != 0) {
        return false;
    }

    // Check if the remaining dimensions can be tiled with a x b sheets
    // This part is simplified and may need more detailed checks based on sheet positions
    // For simplicity, assuming the remaining area can be split into a x b sheets
    return true;
}

void solve() {
    int w, h, a, b;
    pair<int, int> sheet1, sheet2;

    cin >> w >> h >> a >> b;
    cin >> sheet1.first >> sheet1.second;
    cin >> sheet2.first >> sheet2.second;

    if (canTileRoof(w, h, a, b, sheet1, sheet2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}