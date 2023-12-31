// https://atcoder.jp/contests/abc332/tasks/abc332_f
// range a*x+b


struct U {
    using T2 = pair<Mint, Mint>;
    using T1 = Mint;
    static T2 id2() { return mp(Mint(1), Mint(0)); }
    static T1 id1() { return Mint(0); }
    static T1 op11(const T1& a, const T1& b) { return a + b; }
    static T1 op21(const T2& b, const T1& a) { return a * b.fi + b.se; }
    // a : new!
    static T2 op22(const T2& a, const T2& b) {
        return mp(a.fi * b.fi, a.fi * b.se + a.se);
    }
};