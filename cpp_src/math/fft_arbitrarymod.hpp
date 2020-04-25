#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

template <unsigned int MOD>
struct ModInt {
	using uint = unsigned int;
	using ull = unsigned long long;
	using M = ModInt;

	uint v;

	ModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }
	M& set_norm(uint _v) { //[0, MOD * 2)->[0, MOD)
		v = (_v < MOD) ? _v : _v - MOD;
		return *this;
	}

	explicit operator bool() const { return v != 0; }
	M operator+(const M& a) const { return M().set_norm(v + a.v); }
	M operator-(const M& a) const { return M().set_norm(v + MOD - a.v); }
	M operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD); }
	M operator/(const M& a) const { return *this * a.inv(); }
	M& operator+=(const M& a) { return *this = *this + a; }
	M& operator-=(const M& a) { return *this = *this - a; }
	M& operator*=(const M& a) { return *this = *this * a; }
	M& operator/=(const M& a) { return *this = *this / a; }
	M operator-() const { return M() - *this; }
	M& operator++(int) { return *this = *this + 1; }
	M& operator--(int) { return *this = *this - 1; }

	M pow(ll n) const {
		if (n < 0) return inv().pow(-n);
		M x = *this, res = 1;
		while (n) {
			if (n & 1) res *= x;
			x *= x;
			n >>= 1;
		}
		return res;
	}

	M inv() const {
		ll a = v, b = MOD, p = 1, q = 0, t;
		while (b != 0) {
			t = a / b;
			swap(a -= t * b, b);
			swap(p -= t * q, q);
		}
		return M(p);
	}

	bool operator==(const M& a) const { return v == a.v; }
	bool operator!=(const M& a) const { return v != a.v; }
	friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
	static int get_mod() { return MOD; }	
};

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

//math314

template<class T> T ext_gcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }

template<class T> T zmod(T a, T b) {
a %= b;
if (a < 0) a += b;
return a;
}

template<class T> T invmod(T a, T m) {
ll x, y;
ext_gcd(a, m, x, y);
return zmod(x, m);
}

// ここを mod に応じて適切に変える
ll mulmod(ll x, ll y, ll mod) {
	return x * y % mod;
}

using pll = pair<ll, ll>;

ll garner(vector<pll> mr, ll mod) {
	mr.push_back(pll(mod, 0));

	vector<ll> coffs(mr.size(), 1);
	vector<ll> constants(mr.size(), 0);

	rep(i, (int)mr.size() - 1) {
    // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first) を解く
		ll v = mulmod(zmod(mr[i].second - constants[i], mr[i].first),
			invmod<ll>(coffs[i], mr[i].first), mr[i].first);
		assert (v >= 0);

		for (int j = i + 1; j < (int) mr.size(); j++) {
			(constants[j] += mulmod(coffs[j], v, mr[j].first)) %= mr[j].first;
			coffs[j] = mulmod(coffs[j], mr[i].first, mr[j].first);
		}
	}

	return constants[mr.size() - 1];
}

// size : up to 2^20 

using Mint1 = ModInt<1012924417>; //5
using Mint2 = ModInt<1224736769>; //3
using Mint3 = ModInt<1007681537>; //3
using Mint4 = ModInt<1045430273>; //4

vector<ll> arbmod_convolution(vector<ll> a, vector<ll> b, ll mod) {
	for (auto& x : a) {
		x %= mod;
	}
	for (auto& x : b) {
		x %= mod;
	}

	NumberTheoreticTransform<Mint1> ntt1;
	NumberTheoreticTransform<Mint2> ntt2;
	NumberTheoreticTransform<Mint3> ntt3;
	NumberTheoreticTransform<Mint4> ntt4;

	ntt1.init(); ntt2.init(); ntt3.init(); ntt4.init();

	V<Mint1> a1(ALL(a)), b1(ALL(b));
	V<Mint2> a2(ALL(a)), b2(ALL(b));
	V<Mint3> a3(ALL(a)), b3(ALL(b));
	V<Mint4> a4(ALL(a)), b4(ALL(b));

	auto x = ntt1.mul(a1, b1);
	auto y = ntt2.mul(a2, b2);
	auto z = ntt3.mul(a3, b3);
	auto w = ntt4.mul(a4, b4);

	vector<ll> ret(x.size());
	vector<pll> mr(4);

	rep(i, x.size()) {
		mr[0] = pll(Mint1::get_mod(), x[i].v);
		mr[1] = pll(Mint2::get_mod(), y[i].v);
		mr[2] = pll(Mint3::get_mod(), z[i].v);
		mr[3] = pll(Mint4::get_mod(), w[i].v);
		ret[i] = garner(mr, mod);
	}

	return ret;
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	V<ll> a(N), b(M);
	rep(i, N) {
		scanf("%d", &a[i]);
	}
	rep(i, M) {
		scanf("%d", &b[i]);
	}	
	auto res = arbmod_convolution(a, b, TEN(9) + 7);
	int sz = res.size();
	rep(i, sz) printf("%d%c", res[i], i == sz-1 ? '\n' : ' ');

	return 0;
}
