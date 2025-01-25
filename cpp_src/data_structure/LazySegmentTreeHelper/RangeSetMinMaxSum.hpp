// set val, range min, range max, range sum

struct Data {
    ll sum;
    int len, mn, mx;
    Data() {
        sum = len = 0;
        mn = INF;
        mx = -INF;
    }
    Data(ll sum, int len, int mn, int mx)
        : sum(sum), len(len), mn(mn), mx(mx) {};
};

struct U {
    using T1 = Data;
    using T2 = int;
    static T1 id1() { return Data(); }
    static T2 id2() { return INF; }
    static T1 op11(const T1& a, const T1& b) {
        T1 res;
        res.len = a.len + b.len;
        res.sum = a.sum + b.sum;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        return res;
    }
    static T1 op21(const T2& b, const T1& a) {
        if (b == INF)
            return a;
        else {
            T1 res;
            res.len = a.len;
            res.sum = ll(b) * a.len;
            res.mn = res.mx = b;

            return res;
        }
    }
    // a : new!
    static T2 op22(const T2& a, const T2& b) {
        if (a == INF)
            return b;
        else
            return a;
    }
};