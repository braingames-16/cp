#include <bits/stdc++.h>
#include <iostream>
using namespace std;

using ll = long long;
#define pb push_back

// ==================== MATH & COMBINATORICS TOOKIT ====================
const ll mod = 1000000007; // Change to 998244353 if required by the problem
const int MAXN = 200005;  // Adjust this limit based on the problem's N constraint

vector<ll> fact(MAXN);
vector<ll> inv_fact(MAXN);

// Binary Exponentiation: O(log exp)
ll power(ll base, ll exp) {
    ll res = 1;
    base %= mod;
    if (base < 0) base += mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Modular Inverse via Fermat's Little Theorem: O(log mod)
ll modInverse(ll n) {
    return power(n, mod - 2);
}

// Precomputes Factorials and Inverse Factorials globally: O(MAXN)
void precompute() {
    fact[0] = 1;
    inv_fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    // Compute the largest inverse factorial, then step backward in O(1) per element
    inv_fact[MAXN - 1] = modInverse(fact[MAXN - 1]);
    for (int i = MAXN - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}

// Efficient Binomial Coefficient calculation: O(1)
ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n - r] % mod;
}
// =====================================================================

#include <chrono>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve(){
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    unordered_map<ll, vector<ll>, custom_hash> unis;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Run math precomputations once before handling testcases
    precompute();
    
    ll t;
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}
