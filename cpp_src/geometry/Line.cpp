using Line = tuple<ll, ll, ll>;

// ax + by + c = 0

Line normalize(ll a, ll b, ll c) {
    if (a < 0) {
        a *= -1, b *= -1, c *= -1;
    }
    if (a == 0 && b < 0) {
        a *= -1, b *= -1, c *= -1;
    }
    ll d = gcd(abs(a), abs(b));
    d = gcd(d, abs(c));
    a /= d, b /= d, c /= d;
    return make_tuple(a, b, c);
}