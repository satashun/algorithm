//index of root = 1

template<class U>
struct segtree {
	using T = typename U::T;
	int sz;
	V<T> dat;

	segtree(const V<T>& a) {
		int n = a.size();
		sz = 1;
		while (sz < n) sz <<= 1;
		dat.assign(sz * 2, U::id());
		for (int i = 0; i < n; ++i) {
			dat[sz + i] = a[i];
		}
		for (int i = sz - 1; i >= 1; --i) {
			upd(i);
		}
	}

	void upd(int p) {
		dat[p] = U::op(dat[p<<1], dat[p<<1|1]);
	}

	void build() {
		for (int i = sz - 1; i > 0; --i) {
			dat[i] = U::op(dat[i<<1], dat[i<<1|1]);		
		}
	}

	void modify(int p, T v) {
		p += sz;
		dat[p] = v;
		while (p >>= 1) {
			dat[p] = U::op(dat[p<<1], dat[p<<1|1]);
		}
	}

	//[l, r)

	T query(int l, int r) {
		T lval = U::id(), rval = U::id();
		int res = 0;
		for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lval = U::op(lval, dat[l++]);
			if (r & 1) rval = U::op(dat[--r], rval);
		}
		return U::op(lval, rval);
	}
};

//modify only U to use

const int INF = TEN(9) + 10;

struct U {
    using T = ll;
    using E = ll;
    static T id1() { return 0; }
    static E id2() { return INF; }
    static T op11(const T& a, const T& b) {
    	return min(a, b);
    }
    static T op12(const T& a, const E& b) {
    	return b + a;
    }
    static E op22(const E& a, const E& b) {
    	return a + b;
    }
};