//big mod
#include <bits/stdc++.h>
using namespace std;

long long bigMod(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long base, exp, mod;
    cout << "Enter base, exponent, and modulus: ";
    cin >> base >> exp >> mod;
    cout << "Result: " << bigMod(base, exp, mod) << endl;
    return 0;
}
