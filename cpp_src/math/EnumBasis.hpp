// ABC283G
// modified noshi basis

template <class T>
V<T> enum_basis(V<T> a) {
    V<T> basis;

    for (auto e : a) {
        for (auto b : basis) chmin(e, e ^ b);
        if (e) {
            for (auto& x : basis) {
                chmin(x, x ^ e);
            }
            basis.push_back(e);
        }
    }
    return basis;
}