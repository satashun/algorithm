//vector size : power of 2

template<class T>
void and_fwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                T x = f[i+j], y = f[i+j+d];
                f[i+j] = x + y;
            }
        }
    }
}

template<class T>
void and_ifwt(vector<T>& f) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                T x = f[i+j], y = f[i+j+d];
                f[i+j] = x - y;
            }
        }
    }
}

template <class T>
void xor_fwt(vector<T>& f, bool rev) {
    int n = f.size();
    for (int d = 1; d < n; d <<= 1) {
        for (int i = 0; i < n; i += d * 2) {
            for (int j = 0; j < d; ++j) {
                T x = f[i + j], y = f[i + j + d];
                f[i + j] = x + y;
                f[i + j + d] = x - y;
            }
        }
    }

    if (rev) {
        T r = T(1) / n;
        for (auto& x : f) x *= r;
    }
}