template <class T>
using Point = complex<T>;

template <class T>
T cross(const Point<T> &a, const Point<T> &b) {
    return (conj(a) * b).imag();
}

// ARC130F
// lower convex hull of (i, a[i])
// returns: indices
template <class T>
V<int> convex_hull(const V<T> &a) {
    using P = Point<T>;
    int n = SZ(a);
    V<P> pt(n);
    rep(i, n) pt[i] = P(i, a[i]);

    V<int> vec;
    rep(i, n) {
        while (vec.size() > 1 && cross(pt[vec.end()[-1]] - pt[vec.end()[-2]],
                                       pt[i] - pt[vec.end()[-1]]) <= 0) {
            vec.pop_back();
        }
        vec.pb(i);
    }
    return vec;
}