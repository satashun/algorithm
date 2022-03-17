// O(sqrt(x))
ll totient(ll x) {
    ll res = x;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x != 1) {
        res = res / x * (x - 1);
    }
    return res;
}

// O(sqrt(x))
bool is_prime(ll x) {
    if (x <= 1) return false;
    for (ll i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

// p:prime
// ord p of n!
ll ord_fac(ll n, ll p) {
    ll res = 0;
    while (n) {
        n /= p;
        res += n;
    }
    return res;
}