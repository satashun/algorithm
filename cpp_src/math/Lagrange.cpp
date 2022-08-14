// https://github.com/ei1333/library/blob/master/math/combinatorics/lagrange-polynomial.cpp
// y_i = f(i) for i = 0, 1, ..., N
// evaluate f(t)

template <typename T>
T lagrange_interpolation(const vector<T> &y, ll t) {
    int N = y.size() - 1;
    if (t <= N) return y[t];
    T ret(0);
    vector<T> dp(N + 1, 1), pd(N + 1, 1);
    for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * (t - i);
    for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * (t - i);
    for (int i = 0; i <= N; i++) {
        T tmp = y[i] * dp[i] * pd[i] * ifact[i] * ifact[N - i];
        if ((N - i) & 1)
            ret -= tmp;
        else
            ret += tmp;
    }
    return ret;
}