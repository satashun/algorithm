const int maxv = 1000010;

Mint fact[maxv], finv[maxv], inv[maxv];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxv; ++i) {
        fact[i] = fact[i-1] * i;
    }

    finv[maxv-1] = fact[maxv-1].inv();
    for (int i = maxv - 2; i >= 0; --i) {
        finv[i] = finv[i+1] * (i+1);
    }

    for (int i = 1; i < maxv; ++i) {
        inv[i] = finv[i] * fact[i-1];
    }
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return fact[n] * finv[r] * finv[n-r];
}