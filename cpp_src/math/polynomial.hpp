//depends on FFT libs
//basically use with ModInt

NumberTheoreticTransform<Mint> ntt;

template<class D>
struct Poly : public V<D> {
	template<class...Args>
	Poly(Args...args):V<D>(args...){}
	Poly(initializer_list<D>init):V<D>(init.begin(),init.end()){}

	int size() const { return V<D>::size(); }
	D at(int p) const { return (p < this->size() ? (*this)[p] : D(0)); }

	//first len terms
	Poly pref(int len) const {
		return Poly(this->begin(), this->begin() + min(this->size(), len));
	}

	//for polynomial division
	Poly rev() const {
		Poly res = *this;
		reverse(res.begin(), res.end());
		return res;
	} 	

	Poly operator+(const Poly& r) const {
		auto n = max(size(), r.size());
		V<D> tmp(n);
		for (int i = 0; i < n; ++i) {
			tmp[i] = at(i) + r.at(i);
		}
		return tmp;
	}
	Poly operator-(const Poly& r) const {
		auto n = max(size(), r.size());
		V<D> tmp(n);
		for (int i = 0; i < n; ++i) {
			tmp[i] = at(i) - r.at(i);
		}
		return tmp;
	}

	//scalar
	Poly operator*(const D& k) const {
		int n = size();
		V<D> tmp(n);
		for (int i = 0; i < n; ++i) {
			tmp[i] = at(i) * k;
		}
		return tmp;
	}

	Poly operator*(const Poly& r) const {
		Poly a = *this;
		Poly b = r;
		auto v = ntt.mul(a, b);
		return v; 
	}

	//scalar
	Poly operator/(const D& k) const {
		return *this * k.inv();
	}

	Poly operator/(const Poly& r) const {
		if (size() < r.size()) {
			return {{}};
		}
		int d = size() - r.size() + 1;
		return (rev().pref(d) * r.rev().inv(d)).pref(d).rev();
	}

	Poly operator%(const Poly& r) const {
		auto res = *this - *this / r * r;
		while (res.size() && !res.back()) {
			res.pop_back();
		}
		return res;
	}

	Poly diff() const {
		V<D> res(max(0, size() - 1));
		for (int i = 1; i < size(); ++i) {
			res[i - 1] = at(i) * i;
		}
		return res;
	}

	Poly inte() const {
		V<D> res(size() + 1);
		for (int i = 0; i < size(); ++i) {
			res[i + 1] = at(i) / (D)(i + 1);
		}
		return res;
	}

	//f * f.inv(m) === 1 mod (x^m)
	//f_0 ^ -1 must exist
	Poly inv(int m) const {
		Poly res = Poly({D(1) / at(0)});
		for (int i = 1; i < m; i *= 2) {
			res = (res * D(2) - res * res * pref(i * 2)).pref(i * 2);
		}
		return res.pref(m);
	}

	//f_0 = 1 must hold
	Poly log(int n) const {
		auto f = pref(n);
		return (f.diff() * f.inv(n - 1)).pref(n - 1).inte();
	}

	//f_0 = 0 must hold
	Poly exp(int n) const {
		auto h = diff();
		Poly f({1}), g({1});

		for (int m = 1; m < n; m *= 2) {		
			g = (g * D(2) - f * g * g).pref(m); 
			auto q = h.pref(m - 1);
			auto w = (q + g * (f.diff() - f * q)).pref(m * 2 - 1);
			f = (f + f * (*this - w.inte()).pref(m * 2)).pref(m * 2);
		}

		return f.pref(n);
	}

	//f_0 = 0 must hold?
	//**537
	Poly pow(int n, ll k) const {
		return (log(n) * (D)k).exp(n);
	}

	//f_0 = 1 must hold (use it with modular sqrt)
	//CF250E
	Poly sqrt(int n) const {
		Poly f = pref(n);
		Poly g({1});
		for (int i = 1; i < n; i *= 2) {
			g = (g + f.pref(i * 2) * g.inv(i * 2)) * D(2).inv();
		}
		return g.pref(n);
	}

	D eval(D x) const {
		D res = 0, c = 1;
		for (auto a : *this) {
			res += a * c;
			c *= x;
		}
		return res;
	} 

	Poly& operator+=(const Poly& r) { return *this = *this + r; }
	Poly& operator-=(const Poly& r) { return *this = *this - r; }
	Poly& operator*=(const D& r) { return *this = *this * r; }
	Poly& operator*=(const Poly& r) { return *this = *this * r; }
	Poly& operator/=(const Poly& r) { return *this = *this / r; }
	Poly& operator/=(const D &r) { return *this = *this / r; }
	Poly& operator%=(const Poly& r) { return *this = *this % r; }

	friend ostream& operator<<(ostream& os, const Poly& pl) {
		if (pl.size() == 0) return os << "0";
		for (int i = 0; i < pl.size(); ++i) {
			if (pl[i]) {
				os << pl[i] << "x^" << i;
				if (i + 1 != pl.size()) os << ",";
			}
		}
		return os;
	}
};

//calculate characteristic polynomial
//c_0 * s_i + c_1 * s_{i+1} + ... + c_k * s_{i+k} = 0
//c_k = -1

template<class T>
Poly<T> berlekamp_massey(const V<T>& s) {
	int n = int(s.size());
	V<T> b = {T(-1)}, c = {T(-1)};
	T y = Mint(1);
	for (int ed = 1; ed <= n; ed++) {
		int l = int(c.size()), m = int(b.size());
		T x = 0;
		for (int i = 0; i < l; i++) {
			x += c[i] * s[ed - l + i];
		}
		b.push_back(0);
		m++;
		if (!x) {
			continue;
		}
		T freq = x / y;
		if (l < m) {
			auto tmp = c;
			c.insert(begin(c), m - l, Mint(0));
			for (int i = 0; i < m; i++) {
				c[m - 1 - i] -= freq * b[m - 1 - i];
			}
			b = tmp;
			y = x;
		} else {
			for (int i = 0; i < m; i++) {
				c[l - 1 - i] -= freq * b[m - 1 - i];
			}
		}
	}
	return c;
}