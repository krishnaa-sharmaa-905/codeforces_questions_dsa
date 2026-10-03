#include <bits/stdc++.h>
using namespace std;

long long digitSumBase3(long long num) {
    long long sum = 0;
    while (num > 0) {
        sum += num % 3;
        num /= 3;
    }
    return sum;
}

long long extraMergeCost(long long num, long long mergesAllowed) {
    long long extraCost = 0;
    long long carryOver = num;
    long long placeValue = 1;

    while (mergesAllowed > 0 && carryOver > 0) {
        long long possibleMerges = min(mergesAllowed, carryOver / 3);
        if (possibleMerges > 0) {
            extraCost += possibleMerges * placeValue;
            mergesAllowed -= possibleMerges;
        }
        carryOver /= 3;
        placeValue *= 3;
    }
    return extraCost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    if (!(cin >> testCases)) return 0;

    while (testCases--) {
        long long n, k;
        cin >> n >> k;

        long long base3DigitSum = digitSumBase3(n);

        if (k < base3DigitSum) {
            cout << -1 << '\n';
            continue;
        }

        long long initialCost = 3LL * n;

        if (k >= n) {
            cout << initialCost << '\n';
            continue;
        }

        long long neededMerges = (n - k + 1) / 2;
        long long extraCost = extraMergeCost(n, neededMerges);

        cout << (initialCost + extraCost) << '\n';
    }
    return 0;
}
