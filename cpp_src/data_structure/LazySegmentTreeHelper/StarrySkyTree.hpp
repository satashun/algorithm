// so called "starry sky tree" counting minimum
// support range addition, range minimum, range (count of minimum)
// GCJ 2022 round 3 problem B

constexpr ll INF = TEN(18);

struct U {
    // (minimum, count)
    using T1 = pair<ll, ll>;
    using T2 = ll;

    static T1 id1() { return mp(INF, 0ll); }
    static T2 id2() { return 0; }

    static T1 op11(const T1& a, const T1& b) {
        ll nx_mini = min(a.first, b.first);
        ll nx_cnt = (a.first == nx_mini ? a.second : 0) +
                    (b.first == nx_mini ? b.second : 0);
        return mp(nx_mini, nx_cnt);
    }

    static T1 op21(const T2& b, const T1& a) {
        return mp(a.first + b, a.second);
    }
    // a : new!
    static T2 op22(const T2& a, const T2& b) { return a + b; }
};