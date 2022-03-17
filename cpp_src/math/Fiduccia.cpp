/**
 * @docs docs/Fiduccia.md
 */

// ref :
// https://qiita.com/ryuhe1/items/da5acbcce4ac1911f47a#%E5%BD%A2%E5%BC%8F%E7%9A%84%E3%81%B9%E3%81%8D%E7%B4%9A%E6%95%B0
// a_i = \sum_{j=1}^d c_j * a_{i-j}
// input
// a_0, a_1, a_2, ..., a_{d-1}
// c_1, c_2, c_3, ..., c_d
// n
// calculate a_n

template <class T>
T fiduccia(V<T> a, V<T> c, ll n) {
    if (n < a.size()) return a[n];
    int k = SZ(c);
    // char poly
    V<T> vc(k + 1);
    rep(i, k) vc[k - 1 - i] = -c[i];
    vc[k] = 1;

    Poly<T> mono{0, 1};
    mono = mono.powmod(n, vc);

    T ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += mono.at(i) * a[i];
    }
    return ans;
}