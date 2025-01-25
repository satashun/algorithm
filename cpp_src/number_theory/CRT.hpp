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

// ABC315G
// ax + by = c
// returs (x0, y0, gcd(a,b))
// x0, y0 <= max(a,b)^2,|c|
// x = x0 + b't, y = y0 - a't
tuple<ll, ll, ll> solve_eq(ll a, ll b, ll c) {
    auto res = ext_gcd(a, b);
    ll x = res.x, y = res.y, g = res.g;
    if (c % g) {
        return make_tuple(-1, -1, -1);
    }
    x *= (c % b) / g;
    y *= (c % b) / g;
    y += c / b;
    return make_tuple(x, y, g);
}

ll inv_mod(ll x, ll md) {
    auto z = ext_gcd(x, md).x;
    return (z % md + md) % md;
}

// ** 271
// find x s.t. x = b_i mod c_i
pair<ll, ll> crt(const V<ll>& b, const V<ll>& c) {
    int n = int(b.size());
    ll r = 0, m = 1;
    for (int i = 0; i < n; i++) {
        auto eg = ext_gcd(m, c[i]);
        ll g = eg.g, im = eg.x;
        if ((b[i] - r) % g) return {0, -1};
        ll tmp = (b[i] - r) / g * im % (c[i] / g);
        r += m * tmp;
        m *= c[i] / g;
    }
    return {(r % m + m) % m, m};
}