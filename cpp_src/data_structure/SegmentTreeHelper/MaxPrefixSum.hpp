// ABC292H
constexpr ll INF = TEN(18);

// maximum prefix sum
struct Data {
    ll sum, maxi;
    Data() { sum = maxi = 0; }
    Data(ll sum, ll maxi) : sum(sum), maxi(maxi) {}
};

// modify only U
struct U {
    using T = Data;
    static T id() { return Data(0ll, -INF); }
    static T op(const T& a, const T& b) {
        Data res;
        res.sum = a.sum + b.sum;
        res.maxi = max(a.maxi, a.sum + b.maxi);
        return res;
    }
};