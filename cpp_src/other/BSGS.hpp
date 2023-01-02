// Baby Step Giant Step
// ABC270G
// x_0 = S, x_{i+1}= (Ax_i + B) % P
// smallest i s.t. x_i = G

ll BSGS(int P, int A, int B, int S, int G) {
    const int L = sqrt(P) + 1;

    using mint = atcoder::modint;
    mint::set_mod(P);

    if (S == G) {
        return 0;
    }

    if (A == 0) {
        // S,B,B,..
        if (G == B) {
            return 1;
        } else {
            return -1;
        }
    }

    V<pair<mint, mint>> vs(L + 1);
    vs[0] = mp(mint(1), mint(0));
    rep(i, L) {
        auto [a, b] = vs[i];
        vs[i + 1] = mp(a * A, b * A + B);
    }

    unordered_map<int, int> T;
    rep(i, L) {
        auto [a, b] = vs[i];
        auto r = mint(G - b) * a.inv();
        if (!T.count(r.val())) {
            T[r.val()] = i;
        }
    }

    mint cur = S;
    for (int i = 0; i < P; i += L) {
        // cur*a+b=G
        if (T.count(cur.val())) {
            return i + T[cur.val()];
        }
        cur = cur * vs[L].fi + vs[L].se;
    }
    return -1;
}