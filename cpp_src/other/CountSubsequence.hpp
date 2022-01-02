// ABC239F
// count distinct subsequences
template <class T>
Mint count_subsequence(const V<T>& vec) {
    map<T, int> la;
    int n = SZ(vec);
    V<Mint> dp(n), ps(n + 1);

    rep(i, n) {
        int l = -1;
        if (la.count(vec[i])) {
            l = la[vec[i]];
        }

        if (l == -1) {
            dp[i]++;
            l = 0;
        }

        dp[i] += ps[i] - ps[l];
        ps[i + 1] = ps[i] + dp[i];
        la[vec[i]] = i;
    }

    Mint ans = accumulate(ALL(dp), Mint(0)) + 1;
    return ans;
}