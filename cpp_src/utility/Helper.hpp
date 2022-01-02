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