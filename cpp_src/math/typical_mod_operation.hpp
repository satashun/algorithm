const int maxv = 1000010;

V<Mint> fact(maxv), ifact(maxv), inv(maxv);

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxv; ++i) {
        fact[i] = fact[i-1] * i;
    }

    ifact[maxv-1] = fact[maxv-1].inv();

    for (int i = maxv - 2; i >= 0; --i) {
        ifact[i] = ifact[i+1] * (i+1);
    }

    for (int i = 1; i < maxv; ++i) {
        inv[i] = ifact[i] * fact[i-1];
    }
}

Mint comb(int n, int r) {
    if (n < 0 || r < 0 || r > n) return Mint(0);
    return fact[n] * ifact[r] * ifact[n-r];
}