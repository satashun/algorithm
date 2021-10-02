// reference
// https://nyaannyaan.github.io/library/ntt/multivariate-multiplication.hpp
// https://rushcheyo.blog.uoj.ac/blog/6547

// f(x_1, x_2, ..., x_k) * g(x_1, x_2, ..., x_k) mod (x_1^n_1, \cdots, x_k^n_k)
// base : {n_1, n_2, \cdots, n_k}
// i = i_1 + i_2 * n_1 + \cdots + i_k * (n_1 * n_2 \cdots * n_{k-1})
// also useful for subset convolution

template <class T>
V<T> multivariate_convolution(V<T> a, V<T> b, V<int> base) {
    NumberTheoreticTransform<T> ntt;
    ntt.init();

    int K = base.size();

    if (K == 0) {
        return V<T>{a[0] * b[0]};
    }

    int n = a.size();
    int w = 1;
    while (w < n * 2) w *= 2;

    V<int> chi(n);
    for (int i = 0; i < n; ++i) {
        int t = i;
        int res = 0;
        for (int j = 0; j < K - 1; ++j) {
            t /= base[j];
            res = (res + t) % K;
        }
        chi[i] = res;
    }

    VV<T> F(K, V<T>(w)), G(K, V<T>(w));

    for (int i = 0; i < n; ++i) {
        F[chi[i]][i] += a[i];
        G[chi[i]][i] += b[i];
    }

    for (int i = 0; i < K; ++i) {
        ntt.ntt(F[i]);
        ntt.ntt(G[i]);
    }

    VV<T> A(K, V<T>(w));
    rep(p, w) {
        V<Mint> res(K);
        rep(i, K) {
            rep(j, K) { res[(i + j) % K] += F[i][p] * G[j][p]; }
        }
        rep(i, K) A[i][p] += res[i];
    }
    rep(i, K) ntt.ntt(A[i], true);
    V<T> res(n);
    rep(i, n) res[i] = A[chi[i]][i];
    return res;
}