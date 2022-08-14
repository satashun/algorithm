template <class T>
V<T> cumsum(const V<T>& vec) {
    int n = vec.size();
    V<T> res(n + 1);
    rep(i, n) { res[i + 1] = res[i] + vec[i]; }
    return res;
}