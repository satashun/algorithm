// yukicoder 2243
// https://yukicoder.me/submissions/869720
template <class D>
struct MultiEval {
    using P = MultiEval*;
    P lc, rc;
    V<D> xs;
    int sz;
    Poly<D> dpol;

    const int B = 100;

    MultiEval(const V<D>& _xs, int l, int r) : sz(r - l) {
        if (r - l <= B) {
            xs = {_xs.begin() + l, _xs.begin() + r};
            dpol = {{1}};
            for (auto x : xs) {
                dpol *= {-x, 1};
            }
            return;
        }
        lc = new MultiEval(_xs, l, (l + r) / 2);
        rc = new MultiEval(_xs, (l + r) / 2, r);
        dpol = lc->dpol * rc->dpol;
    }

    MultiEval(const V<D>& xs) : MultiEval(xs, 0, xs.size()) {}

    void eval(const Poly<D>& poly, V<D>& res) {
        auto p = poly % dpol;
        if (sz <= B) {
            for (auto x : xs) {
                res.pb(p.eval(x));
            }
            return;
        }
        lc->eval(p, res);
        rc->eval(p, res);
    }

    V<D> eval(const Poly<D>& poly) {
        V<D> res;
        eval(poly, res);
        return res;
    }
};