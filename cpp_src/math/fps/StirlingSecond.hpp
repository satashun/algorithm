// divide n people into k groups
// enumerate S(n, k)
// for 0 \leq k \leq n
// S(n, k) = \sum_{i=1}^k (-1)^(n-k) * \binom{k}{i} * i^n
// We can calculate i^n in O(n loglog n) time
// ref : https://min-25.hatenablog.com/entry/2015/04/07/160154

V<Mint> stirling_second(int n) {
    V<Mint> a(n + 1), b(n + 1);
    for (int i = 0; i <= n; ++i) {
        a[i] = ifact[i] * (i % 2 ? -1 : 1);
        b[i] = Mint(i).pow(n) * ifact[i];
    }
    auto c = ntt.mul(a, b);
    c.resize(n + 1);
    return c;
}