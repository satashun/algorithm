template <class T>
struct BIT {
    int n;
    vector<T> bit;

    BIT(int _n = 0) : n(_n), bit(n + 1) {}

    // ABC368G
    BIT(const V<T>& vec) : n(SZ(vec)), bit(n + 1) {
        rep(i, n) bit[i + 1] = vec[i];
        for (int i = 1; i <= n; ++i) {
            int j = i + (i & -i);
            if (j <= n) {
                bit[j] += bit[i];
            }
        }
    }

    // sum of [0, i), 0 <= i <= n
    T sum(int i) {
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    // 0 <= i < n
    void add(int i, T x) {
        ++i;
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }

    //[l, r) 0 <= l < r < n
    T sum(int l, int r) { return sum(r) - sum(l); }

    // verify!!!!
    // smallest i, sum(i) >= w, none -> n + 1
    int lower_bound(T w) {
        if (w <= 0) return 0;
        int x = 0, l = 1;
        while (l * 2 <= n) l *= 2;

        for (int k = l; k > 0; k /= 2) {
            if (x + k <= n && bit[x + k] < w) {
                w -= bit[x + k];
                x += k;
            }
        }
        return x + 1;
    }

    // ABC380G
    V<T> recover() {
        V<T> res(n);
        rep(i, n) res[i] = sum(i, i + 1);
        return res;
    }
};