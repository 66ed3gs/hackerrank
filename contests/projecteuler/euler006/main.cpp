#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for (int i = m; i < n; i++)

#define ALL(v) v.begin(), v.end()

typedef long long ll;

// sort(ALL(a)), sortALL(a), greater<>())
//

using namespace std;

int main() {
    int t;
    cin >> t;

    int read;
    vector<int> n;
    for (int i = 0; i < t; i++) {
        cin >> read;
        n.push_back(read);
    }

    long sum, result;
    for (int i = 0; i < t; i++) {
        sum = 0;
        result = 0;
        for (int l = 1; l <= n[i]; l++) {
            sum += l;
            result -= l * l;
        }
        result += sum * sum;

        cout << result << endl;
    }
}
