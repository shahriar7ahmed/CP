#include <bits/stdc++.h>
using namespace std;

void sieve(int n) {
    vector<bool> isPrime(n + 1, true); 
    isPrime[0] = isPrime[1] = false;  

    for (int p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isPrime[i] = false;
            }
        }   
    }

    cout << "Prime numbers up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    sieve(n);
    return 0;
}
