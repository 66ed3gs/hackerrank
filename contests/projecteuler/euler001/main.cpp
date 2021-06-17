#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long n, t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        long long sum = 0;

        n -= 1;
        sum += (n / 3 * (n / 3 + 1) / 2) * 3;
        sum += (n / 5 * (n / 5 + 1) / 2) * 5;
        sum -= (n / 15 * (n / 15 + 1) / 2) * 15;

        cout << sum << endl;
    }
}

