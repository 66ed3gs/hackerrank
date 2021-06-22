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

bool isPrime(int n) {
    if (n < 2) return false;
    FOR(i, 2, n - 1) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    int r;
    vector<int> n;
    REP(i, t) {
        cin >> r;
        n.push_back(r);
    }

    int max = *max_element(ALL(n));
    vector<int> primes;
    for (int i = 0; max > primes.size(); i++) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }

    REP(i, t) { cout << primes[n[i] - 1] << endl; }
}

