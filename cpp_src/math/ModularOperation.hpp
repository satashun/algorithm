V<Mint> fact, ifact, inv;

void init() {
    const int maxv = 1000010;
    fact.resize(maxv);
    ifact.resize(maxv);
    inv.resize(maxv);

    fact[0] = 1;
    for (int i = 1; i < maxv; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    ifact[maxv - 1] = fact[maxv - 1].inv();

    for (int i = maxv - 2; i >= 0; --i) {
        ifact[i] = ifact[i + 1] * (i + 1);
    }

    for (int i = 1; i < maxv; ++i) {
        inv[i] = ifact[i] * fact[i - 1];
    }
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return fact[n] * ifact[r] * ifact[n - r];
}

// O(k)

Mint comb_slow(ll n, ll k) {
    Mint res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i) * inv[i + 1];
    }
    return res;
}

// line up
// a 'o' + b 'x'
Mint comb2(int a, int b) {
    if (a < 0 || b < 0) return 0;
    return comb(a + b, a);
}

// divide a into b groups
Mint nhr(int a, int b) {
    if (b == 0) return Mint(a == 0);
    return comb(a + b - 1, a);
}

// O(p + log_p n)

Mint lucas(ll n, ll k, int p) {
    if (n < 0 || k < 0 || k > n) return Mint(0);
    Mint res = 1;
    while (n > 0) {
        res *= comb(n % p, k % p);
        n /= p;
        k /= p;
    }
    return res;
}