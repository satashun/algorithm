ll near(ll x, ll d) {
    bool p = x >= 0;
    x = abs(x);
    ll t = x % d * 2 >= d ? x / d + 1 : x / d;
    if (!p) t = -t;
    return t;
}

pair<ll, ll> get(ll p, ll q, ll r, ll s) {
    if (r == 0 && s == 0) return mp(p, q);
    ll g = r * r + s * s;
    ll np = near(p * r + q * s, g), nq = near(q * r - p * s, g);
    ll a = p - (np * r - nq * s), b = q - (nq * r + np * s);
    return get(r, s, a, b);
};