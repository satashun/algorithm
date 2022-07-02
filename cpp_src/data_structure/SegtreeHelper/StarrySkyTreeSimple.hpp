// ex: https://atcoder.jp/contests/tenka1-2016-qualb/tasks/tenka1_2016_qualB_d
// range addition, range minimum
// initialization must be cared (set all to 0, while id1 = INF)

constexpr ll INF = TEN(18);

struct U {
    using T1 = ll;
    using T2 = ll;
    static T1 id1() { return INF; }
    static T2 id2() { return 0; }
    static T1 op11(const T1& a, const T1& b) { return min(a, b); }
    static T1 op21(const T2& b, const T1& a) { return b + a; }
    // a : new!
    static T2 op22(const T2& a, const T2& b) { return a + b; }
};