/// g:gcd(a, b), ax+by=g
struct EG {
    ll g, x, y;
};

EG ext_gcd(ll a, ll b) {
    if (b == 0) {
        if (a >= 0)
            return EG{a, 1, 0};
        else
            return EG{-a, -1, 0};
    } else {
        auto e = ext_gcd(b, a % b);
        return EG{e.g, e.y, e.x - a / b * e.y};
    }
}

ll inv_mod(ll x, ll md) {
    auto z = ext_gcd(x, md).x;
    return (z % md + md) % md;
}

template <class T>
T zmod(T a, T b) {
    a %= b;
    if (a < 0) a += b;
    return a;
}

// ここを mod に応じて適切に変える
ll mulmod(ll x, ll y, ll mod) { return x * y % mod; }

ll garner(const V<ll>& b, const V<ll>& c) {
    vector<ll> coffs(b.size(), 1);
    vector<ll> constants(b.size(), 0);

    rep(i, (int)b.size() - 1) {
        // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) を解く
        ll v = mulmod(zmod(b[i] - constants[i], c[i]), inv_mod(coffs[i], c[i]),
                      c[i]);
        assert(v >= 0);

        for (int j = i + 1; j < (int)b.size(); j++) {
            (constants[j] += mulmod(coffs[j], v, c[j])) %= c[j];
            coffs[j] = mulmod(coffs[j], c[i], c[j]);
        }
    }

    return constants[b.size() - 1];
}

using Mint1 = ModInt<1012924417>;  // 5
using Mint2 = ModInt<1224736769>;  // 3
using Mint3 = ModInt<1007681537>;  // 3
using Mint4 = ModInt<1045430273>;  // 4

NumberTheoreticTransform<Mint1> ntt1;
NumberTheoreticTransform<Mint2> ntt2;
NumberTheoreticTransform<Mint3> ntt3;
NumberTheoreticTransform<Mint4> ntt4;

// D : modint
template <class D>
V<D> arbmod_convolution(V<D> _a, V<D> _b, ll mod) {
    V<ll> a(SZ(_a)), b(SZ(_b));
    rep(i, SZ(_a)) a[i] = _a[i].v;
    rep(i, SZ(_b)) b[i] = _b[i].v;
    V<Mint1> a1(ALL(a)), b1(ALL(b));
    V<Mint2> a2(ALL(a)), b2(ALL(b));
    V<Mint3> a3(ALL(a)), b3(ALL(b));
    V<Mint4> a4(ALL(a)), b4(ALL(b));

    auto x = ntt1.mul(a1, b1);
    auto y = ntt2.mul(a2, b2);
    auto z = ntt3.mul(a3, b3);
    auto w = ntt4.mul(a4, b4);

    V<D> res(x.size());
    V<ll> c{1012924417, 1224736769, 1007681537, 1045430273, mod};

    rep(i, SZ(x)) {
        V<ll> b{x[i].v, y[i].v, z[i].v, w[i].v, 0ll};
        res[i] = garner(b, c);
    }

    return res;
}

template <class D>
struct Poly : public V<D> {
    template <class... Args>
    Poly(Args... args) : V<D>(args...) {}
    Poly(initializer_list<D> init) : V<D>(init.begin(), init.end()) {}

    int size() const { return V<D>::size(); }
    D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }

    void shrink() {
        while (this->size() > 0 && this->back() == D(0)) this->pop_back();
    }

    // first len terms
    Poly pref(int len) const {
        return Poly(this->begin(), this->begin() + min(this->size(), len));
    }

    // for polynomial division
    Poly rev() const {
        Poly res = *this;
        reverse(res.begin(), res.end());
        return res;
    }

    Poly shiftr(int d) const {
        int n = max(size() + d, 0);
        Poly res(n);
        for (int i = 0; i < size(); ++i) {
            if (i + d >= 0) {
                res[i + d] = at(i);
            }
        }
        return res;
    }

    Poly operator+(const Poly& r) const {
        auto n = max(size(), r.size());
        V<D> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = at(i) + r.at(i);
        }
        return tmp;
    }
    Poly operator-(const Poly& r) const {
        auto n = max(size(), r.size());
        V<D> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = at(i) - r.at(i);
        }
        return tmp;
    }

    // scalar
    Poly operator*(const D& k) const {
        int n = size();
        V<D> tmp(n);
        for (int i = 0; i < n; ++i) {
            tmp[i] = at(i) * k;
        }
        return tmp;
    }

    Poly operator*(const Poly& r) const {
        Poly a = *this;
        Poly b = r;
        auto v = arbmod_convolution(a, b, D::get_mod());
        return v;
    }

    // scalar
    Poly operator/(const D& k) const { return *this * k.inv(); }

    Poly operator/(const Poly& r) const {
        if (size() < r.size()) {
            return {{}};
        }
        int d = size() - r.size() + 1;
        return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();
    }

    Poly operator%(const Poly& r) const {
        auto res = *this - *this / r * r;
        res.shrink();
        return res;
    }

    Poly diff() const {
        V<D> res(max(0, size() - 1));
        for (int i = 1; i < size(); ++i) {
            res[i - 1] = at(i) * i;
        }
        return res;
    }

    Poly inte() const {
        V<D> res(size() + 1);
        for (int i = 0; i < size(); ++i) {
            res[i + 1] = at(i) / (D)(i + 1);
        }
        return res;
    }

    // f * f.inv(m) === 1 mod (x^m)
    // f_0 ^ -1 must exist
    Poly inv(int m) const {
        Poly res = Poly({D(1) / at(0)});
        for (int i = 1; i < m; i *= 2) {
            res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);
        }
        return res.pref(m);
    }

    // f_0 = 1 must hold
    Poly log(int n) const {
        auto f = pref(n);
        return (f.diff() * f.inv(n - 1)).pref(n - 1).inte();
    }

    // f_0 = 0 must hold
    Poly exp(int n) const {
        auto h = diff();
        Poly f({1}), g({1});

        for (int m = 1; m < n; m *= 2) {
            g = (g * D(2) - f * g * g).pref(m);
            auto q = h.pref(m - 1);
            auto w = (q + g * (f.diff() - f * q)).pref(m * 2 - 1);
            f = (f + f * (*this - w.inte()).pref(m * 2)).pref(m * 2);
        }

        return f.pref(n);
    }

    // front n elements of f(x)^k
    // be careful when k = 0
    Poly pow(ll k, int n) const {
        int zero = 0;
        while (zero < size() && at(zero) == 0) {
            zero++;
        }

        if (zero == size() || zero * k >= n) {
            Poly res(n);
            if (n > 0 && k == 0) res[0] = 1;
            return res;
        }

        Poly h(this->begin() + zero, this->end());
        debug(h);
        D a = h[0], ra = D(1) / a;
        h *= ra;
        h = h.log(n - zero * k) * D(k);
        h = h.exp(n - zero * k);
        h = h.shiftr(zero * k) * a.pow(k);
        return h;
    }

    // f_0 = 1 must hold (use it with modular sqrt)
    // CF250E
    Poly sqrt(int n) const {
        Poly f = pref(n);
        Poly g({1});
        for (int i = 1; i < n; i *= 2) {
            g = (g + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();
        }
        return g.pref(n);
    }

    D eval(D x) const {
        D res = 0, c = 1;
        for (auto a : *this) {
            res += a * c;
            c *= x;
        }
        return res;
    }

    Poly powmod(ll k, const Poly& md) {
        auto v = *this % md;
        Poly res{1};
        while (k) {
            if (k & 1) {
                res = res * v % md;
            }
            v = v * v % md;
            k /= 2;
        }
        return res;
    }

    Poly& operator+=(const Poly& r) { return *this = *this + r; }
    Poly& operator-=(const Poly& r) { return *this = *this - r; }
    Poly& operator*=(const D& r) { return *this = *this * r; }
    Poly& operator*=(const Poly& r) { return *this = *this * r; }
    Poly& operator/=(const Poly& r) { return *this = *this / r; }
    Poly& operator/=(const D& r) { return *this = *this / r; }
    Poly& operator%=(const Poly& r) { return *this = *this % r; }

    friend ostream& operator<<(ostream& os, const Poly& pl) {
        if (pl.size() == 0) return os << "0";
        for (int i = 0; i < pl.size(); ++i) {
            if (pl[i]) {
                os << pl[i] << "x^" << i;
                if (i + 1 != pl.size()) os << ",";
            }
        }
        return os;
    }

    explicit operator bool() const {
        bool f = false;
        for (int i = 0; i < size(); ++i) {
            if (at(i)) {
                f = true;
            }
        }
        return f;
    }
};