using R = __int128;

ll pollrard_single(ll n) {
    auto f = [&](ll x) { return ((R)x * x + 1) % n; };
    if (miller_rabin_big(n)) return n;
    if (n % 2 == 0) return 2;
    ll st = 0;
    while (true) {
        st++;

        ll x = st, y = f(x);
        while (true) {
            ll p = gcd((y - x + n), n);
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