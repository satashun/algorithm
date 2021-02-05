//depend on ModInt, must use NTT friendly mod

template<class D>
struct NumberTheoreticTransform {
	D root;
	V<D> roots = {0, 1};
	V<int> rev = {0, 1};
	int base = 1, max_base = -1;

	void init() {
		int mod = D::get_mod();
		int tmp = mod - 1;
		max_base = 0;
		while (tmp % 2 == 0) {
			tmp /= 2;
			max_base++;
		}

		root = 2;
		
		while (true) {
			if (root.pow(1 << max_base).v == 1) {
				if (root.pow(1 << (max_base - 1)).v != 1) {
					break;
				}
			}
			root++;
		}
	}

	void ensure_base(int nbase) {
		if (max_base == -1) init();
		if (nbase <= base) return;
		assert(nbase <= max_base);

		rev.resize(1 << nbase);
		for (int i = 0; i < (1 << nbase); ++i) {
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
		}
		roots.resize(1 << nbase);

		while (base < nbase) {
			D z = root.pow(1 << (max_base - 1 - base));
			for (int i = 1 << (base - 1); i < (1 << base); ++i) {
				roots[i << 1] = roots[i];
				roots[(i << 1) + 1] = roots[i] * z;
			}
			++base;
		}
	}

	void ntt(V<D> &a, bool inv = false) {
		int n = a.size();
      //assert((n & (n - 1)) == 0);
		int zeros = __builtin_ctz(n);
		ensure_base(zeros);
		int shift = base - zeros;

		for (int i = 0; i < n; i++) {
			if (i < (rev[i] >> shift)) {
				swap(a[i], a[rev[i] >> shift]);
			}
		}

		for (int k = 1; k < n; k <<= 1) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					D x = a[i + j];
					D y = a[i + j + k] * roots[j + k];
					a[i + j] = x + y;
					a[i + j + k] = x - y;
				}
			}
		}

		int v = D(n).inv().v;
		if (inv) {
			reverse(a.begin() + 1, a.end());
			for (int i = 0; i < n; i++) {
				a[i] *= v;
			}
		}
	}

	V<D> mul(V<D> a, V<D> b) {
		if (a.size() == 0 && b.size() == 0) return {};
		int s = a.size() + b.size() - 1;
		int nbase = 1;
		while ((1 << nbase) < s) nbase++;
		int sz = 1 << nbase;
		a.resize(sz);
		b.resize(sz);
		ntt(a);
		ntt(b);

		for (int i = 0; i < sz; i++) {
			a[i] *= b[i];
		}
		ntt(a, true);

		a.resize(s);
		return a;
	}
};