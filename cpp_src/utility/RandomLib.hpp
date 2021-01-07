ll rand_int(ll l, ll r) {  //[l,r]
    static mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}

// Fisher–Yates
template <class T>
vector<T> random_perm(vector<T> vec) {
    vector<T> res;
    rep(i, vec.size()) {
        res.pb(vec[i]);
        int j = rand_int(0, i);
        swap(res[j], res[i]);
    }
    return res;
}