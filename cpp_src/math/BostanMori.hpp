// ref :
// https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0
// a_i = \sum_{j=1}^d c_j * a_{i-j}
// input
// a_0, a_1, a_2, ..., a_{d-1}
// c_1, c_2, c_3, ..., c_d
// n
// calculate a_n

template <class T>
T bostan_mori(Poly<T> a, Poly<T> c, ll n) {
    if (n < a.size()) return a[n];
    using P = Poly<T>;

    auto even = [&](const P& a) {
        int sz = SZ(a);
        P b((sz + 1) / 2);
        for (int i = 0; i < SZ(a); i += 2) {
            b[i / 2] = a[i];
        }
        return b;
    };
    auto odd = [&](const P& a) {
        int sz = SZ(a);
        P b(sz / 2);
        for (int i = 1; i < SZ(a); i += 2) {
            b[i / 2] = a[i];
        }
        return b;
    };
    // a(x) -> a(-x)
    auto neg = [&](const P& a) {
        auto b = a;
        for (int i = 1; i < SZ(b); i += 2) {
            b[i] = -b[i];
        }
        return b;
    };

    int d = SZ(c);
    P q(d + 1);
    q[0] = 1;
    rep(i, SZ(c)) q[i + 1] = -c[i];
    P p = a * q;
    p = p.pref(d);

    while (n > 0) {
        debug(p, q);
        auto u = p * neg(q);
        if (n % 2 == 0) {
            p = even(u);
        } else {
            p = odd(u);
        }
        q = even(q * neg(q));
        n /= 2;
    }
    return p[0] / q[0];
}