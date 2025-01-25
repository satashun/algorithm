template <class T>
void make_unique(vector<T>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}

template <class T>
T pow(T x, ll k) {
    T res(1);
    while (k) {
        if (k & 1) {
            res = res * x;
        }
        k >>= 1;
        x = x * x;
    }
    return res;
}

// x^k mod m
// m*m must not overflow!!
template <class T>
T powmod(T x, ll k, T m) {
    T res(1);
    while (k) {
        if (k & 1) {
            res = res * x % m;
        }
        k >>= 1;
        x = x * x % m;
    }
    return res;
}

template <class T>
V<int> compress(const V<T>& vec) {
    int n = SZ(vec);
    auto xs = vec;
    mkuni(xs);
    V<int> res(n);
    rep(i, n) { res[i] = lower_bound(ALL(xs), vec[i]) - xs.begin(); }
    return res;
}

// 0 <= vec[i] < n
template <class T>
ll inversion(const V<T>& vec) {
    int n = vec.size();
    BIT<int> bit(n + 10);
    ll res = 0;
    rep(i, n) {
        res += i - bit.sum(vec[i] + 1);
        bit.add(vec[i], 1);
    }
    return res;
}

// binary search
// ARC189C
// strict
template <class T>
int longest_increasing_subsequence(const V<T>& vec) {
    int sz = SZ(vec);
    if (sz == 0) return 0;
    T INF = *max_element(ALL(vec)) + 1;
    V<T> dp(sz + 1, INF);
    dp[0] = -INF;

    for (auto v : vec) {
        auto it = lower_bound(ALL(dp), v);
        *it = v;
    }

    return arglb(dp, INF) - 1;
}