ll rand_int(ll l, ll r) {  //[l,r]
    static random_device rd;
    static mt19937 gen(rd());
    // for Codeforces:
    // static mt19937
    // gen(chrono::steady_clock::now().time_since_epoch().count())
    return uniform_int_distribution<ll>(l, r)(gen);
}