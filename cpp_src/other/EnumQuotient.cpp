V<pair<ll, ll>> enum_quotient(ll N) {
    V<pair<ll, ll>> res;
    ll l = 1;
    while (l <= N) {
        ll r = N / (N / l) + 1;
        //[l, r)
        res.emplace_back(l, r);
        l = r;
    }
    return res;
}