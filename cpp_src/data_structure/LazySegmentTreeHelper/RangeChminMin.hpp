// T1 : result, T2 : action
// range chmin, range minimum
// ABC382F

constexpr int INF = TEN(9);

struct U {
    using T1 = int;
    using T2 = int;
    static T1 id1() { return INF; }
    static T2 id2() { return INF; }
    static T1 op11(const T1& a, const T1& b) { return min(a, b); }
    static T1 op21(const T2& b, const T1& a) { return min(a, b); }
    // a : new!
    static T2 op22(const T2& a, const T2& b) { return min(a, b); }
};