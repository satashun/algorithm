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