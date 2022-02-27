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

using R = __int128;

ll pollrard_single(ll n) {
    auto f = [&](ll x) { return ((R)x * x + 1) % n; } if (is_prime(n)) return n;
    int x = 0;
    while (true) {
        x++;
        ll y = f(x);
        while (true) {
            ll p = __gcd((y - x + n), n);
            if (p == 0 || p == n) break;
            if (p != 1) return p;
            x = f(x);
            y = f(f(y));
        }
    }
}

V<ll> pollrard(ll n) {
    if (n == 1) return {};
    ll x = pollrard_single(n);
    if (x == n) return {x};
    V<ll> v1 = pollrard(x), v2 = pollrard(n / x);
    v1.insert(v1.end(), ALL(v2));
    return v1;
}