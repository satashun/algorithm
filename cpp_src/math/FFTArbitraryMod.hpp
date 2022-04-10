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

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    V<ll> a(N), b(M);
    rep(i, N) { scanf("%d", &a[i]); }
    rep(i, M) { scanf("%d", &b[i]); }
    auto res = arbmod_convolution(a, b, TEN(9) + 7);
    int sz = res.size();
    rep(i, sz) printf("%d%c", res[i], i == sz - 1 ? '\n' : ' ');

    return 0;
}
