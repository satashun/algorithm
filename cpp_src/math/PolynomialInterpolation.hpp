template<class D>
struct PolyBuf {
	const V<D> &xs;
	PolyBuf(const V<D>& xs) : xs(xs) {}
	using P = Poly<D>;
	map<pii, P> buf;
	const P& get(int l, int r) {
		if (buf.count(mp(l, r))) {
			return buf[mp(l, r)];
		}
		if (r - l == 1) {
			return buf[mp(l, r)] = P{-xs[l], 1};
		}
		return buf[mp(l, r)] = get(l, (l + r) / 2) * get((l + r) / 2, r);
	}
};

template<class D>
Poly<D> interpolate(const V<D>& xs, const V<D>& ys) {
	MultiEval<D> U(xs);
	auto vd = U.dpol.diff();
	auto res = U.eval(vd);
	PolyBuf<D> buf(xs);

	function<Poly<D>(int,int)>rec=[&](int l, int r) {
		if (r - l == 1) {
			return Poly<D>{ys[l] / res[l]};
		}
		int m = (l + r) / 2;
		return rec(l, m) * buf.get(m, r) + rec(m, r) * buf.get(l, m);
	};
	return rec(0, xs.size());
}