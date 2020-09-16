---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"cpp_src/math/fft_arbitrarymod.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing ll = long long;\nusing pii = pair<int, int>;\ntemplate<class\
    \ T> using V = vector<T>;\ntemplate<class T> using VV = V<V<T>>;\n\n#define pb\
    \ push_back\n#define eb emplace_back\n#define mp make_pair\n#define fi first\n\
    #define se second\n#define rep(i,n) rep2(i,0,n)\n#define rep2(i,m,n) for(int i=m;i<(n);i++)\n\
    #define ALL(c) (c).begin(),(c).end()\n\n#ifdef LOCAL\n#define dump(x) cerr <<\
    \ __LINE__ << \" \" << #x << \" = \" << (x) << endl\n#else \n#define dump(x) true\n\
    #endif\n\nconstexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\n\
    template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }\n\
    template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }\n\
    \ntemplate<class T, class U>\nostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n\tos<<\"(\"<<p.first<<\",\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n\tos<<\"{\";\n\t\
    rep(i, v.size()) {\n\t\tif (i) os<<\",\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\t\
    return os;\n}\n\ntemplate <unsigned int MOD>\nstruct ModInt {\n\tusing uint =\
    \ unsigned int;\n\tusing ull = unsigned long long;\n\tusing M = ModInt;\n\n\t\
    uint v;\n\n\tModInt(ll _v = 0) { set_norm(_v % MOD + MOD); }\n\tM& set_norm(uint\
    \ _v) { //[0, MOD * 2)->[0, MOD)\n\t\tv = (_v < MOD) ? _v : _v - MOD;\n\t\treturn\
    \ *this;\n\t}\n\n\texplicit operator bool() const { return v != 0; }\n\tM operator+(const\
    \ M& a) const { return M().set_norm(v + a.v); }\n\tM operator-(const M& a) const\
    \ { return M().set_norm(v + MOD - a.v); }\n\tM operator*(const M& a) const { return\
    \ M().set_norm(ull(v) * a.v % MOD); }\n\tM operator/(const M& a) const { return\
    \ *this * a.inv(); }\n\tM& operator+=(const M& a) { return *this = *this + a;\
    \ }\n\tM& operator-=(const M& a) { return *this = *this - a; }\n\tM& operator*=(const\
    \ M& a) { return *this = *this * a; }\n\tM& operator/=(const M& a) { return *this\
    \ = *this / a; }\n\tM operator-() const { return M() - *this; }\n\tM& operator++(int)\
    \ { return *this = *this + 1; }\n\tM& operator--(int) { return *this = *this -\
    \ 1; }\n\n\tM pow(ll n) const {\n\t\tif (n < 0) return inv().pow(-n);\n\t\tM x\
    \ = *this, res = 1;\n\t\twhile (n) {\n\t\t\tif (n & 1) res *= x;\n\t\t\tx *= x;\n\
    \t\t\tn >>= 1;\n\t\t}\n\t\treturn res;\n\t}\n\n\tM inv() const {\n\t\tll a = v,\
    \ b = MOD, p = 1, q = 0, t;\n\t\twhile (b != 0) {\n\t\t\tt = a / b;\n\t\t\tswap(a\
    \ -= t * b, b);\n\t\t\tswap(p -= t * q, q);\n\t\t}\n\t\treturn M(p);\n\t}\n\n\t\
    bool operator==(const M& a) const { return v == a.v; }\n\tbool operator!=(const\
    \ M& a) const { return v != a.v; }\n\tfriend ostream& operator<<(ostream& os,\
    \ const M& a) { return os << a.v; }\n\tstatic int get_mod() { return MOD; }\t\n\
    };\n\n//depend on ModInt, must use NTT friendly mod\n\ntemplate<class D>\nstruct\
    \ NumberTheoreticTransform {\n\tD root;\n\tV<D> roots = {0, 1};\n\tV<int> rev\
    \ = {0, 1};\n\tint base = 1, max_base = -1;\n\n\tvoid init() {\n\t\tint mod =\
    \ D::get_mod();\n\t\tint tmp = mod - 1;\n\t\tmax_base = 0;\n\t\twhile (tmp % 2\
    \ == 0) {\n\t\t\ttmp /= 2;\n\t\t\tmax_base++;\n\t\t}\n\n\t\troot = 2;\n\t\t\n\t\
    \twhile (true) {\n\t\t\tif (root.pow(1 << max_base).v == 1) {\n\t\t\t\tif (root.pow(1\
    \ << (max_base - 1)).v != 1) {\n\t\t\t\t\tbreak;\n\t\t\t\t}\n\t\t\t}\n\t\t\troot++;\n\
    \t\t}\n\t}\n\n\tvoid ensure_base(int nbase) {\n\t\tif (max_base == -1) init();\n\
    \t\tif (nbase <= base) return;\n\t\tassert(nbase <= max_base);\n\n\t\trev.resize(1\
    \ << nbase);\n\t\tfor (int i = 0; i < (1 << nbase); ++i) {\n\t\t\trev[i] = (rev[i\
    \ >> 1] >> 1) + ((i & 1) << (nbase - 1));\n\t\t}\n\t\troots.resize(1 << nbase);\n\
    \n\t\twhile (base < nbase) {\n\t\t\tD z = root.pow(1 << (max_base - 1 - base));\n\
    \t\t\tfor (int i = 1 << (base - 1); i < (1 << base); ++i) {\n\t\t\t\troots[i <<\
    \ 1] = roots[i];\n\t\t\t\troots[(i << 1) + 1] = roots[i] * z;\n\t\t\t}\n\t\t\t\
    ++base;\n\t\t}\n\t}\n\n\tvoid ntt(V<D> &a, bool inv = false) {\n\t\tint n = a.size();\n\
    \      //assert((n & (n - 1)) == 0);\n\t\tint zeros = __builtin_ctz(n);\n\t\t\
    ensure_base(zeros);\n\t\tint shift = base - zeros;\n\n\t\tfor (int i = 0; i <\
    \ n; i++) {\n\t\t\tif (i < (rev[i] >> shift)) {\n\t\t\t\tswap(a[i], a[rev[i] >>\
    \ shift]);\n\t\t\t}\n\t\t}\n\n\t\tfor (int k = 1; k < n; k <<= 1) {\n\t\t\tfor\
    \ (int i = 0; i < n; i += 2 * k) {\n\t\t\t\tfor (int j = 0; j < k; j++) {\n\t\t\
    \t\t\tD x = a[i + j];\n\t\t\t\t\tD y = a[i + j + k] * roots[j + k];\n\t\t\t\t\t\
    a[i + j] = x + y;\n\t\t\t\t\ta[i + j + k] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \n\t\tint v = D(n).inv().v;\n\t\tif (inv) {\n\t\t\treverse(a.begin() + 1, a.end());\n\
    \t\t\tfor (int i = 0; i < n; i++) {\n\t\t\t\ta[i] *= v;\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tV<D> mul(V<D> a, V<D> b) {\n\t\tint s = a.size() + b.size() - 1;\n\t\tint\
    \ nbase = 1;\n\t\twhile ((1 << nbase) < s) nbase++;\n\t\tint sz = 1 << nbase;\n\
    \t\ta.resize(sz);\n\t\tb.resize(sz);\n\t\tntt(a);\n\t\tntt(b);\n\n\t\tfor (int\
    \ i = 0; i < sz; i++) {\n\t\t\ta[i] *= b[i];\n\t\t}\n\t\tntt(a, true);\n\n\t\t\
    a.resize(s);\n\t\treturn a;\n\t}\n};\n\n//math314\n\ntemplate<class T> T ext_gcd(T\
    \ a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x\
    \ -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }\n\ntemplate<class\
    \ T> T zmod(T a, T b) {\na %= b;\nif (a < 0) a += b;\nreturn a;\n}\n\ntemplate<class\
    \ T> T invmod(T a, T m) {\nll x, y;\next_gcd(a, m, x, y);\nreturn zmod(x, m);\n\
    }\n\n// \u3053\u3053\u3092 mod \u306B\u5FDC\u3058\u3066\u9069\u5207\u306B\u5909\
    \u3048\u308B\nll mulmod(ll x, ll y, ll mod) {\n\treturn x * y % mod;\n}\n\nusing\
    \ pll = pair<ll, ll>;\n\nll garner(vector<pll> mr, ll mod) {\n\tmr.push_back(pll(mod,\
    \ 0));\n\n\tvector<ll> coffs(mr.size(), 1);\n\tvector<ll> constants(mr.size(),\
    \ 0);\n\n\trep(i, (int)mr.size() - 1) {\n    // coffs[i] * v + constants[i] ==\
    \ mr[i].second (mod mr[i].first) \u3092\u89E3\u304F\n\t\tll v = mulmod(zmod(mr[i].second\
    \ - constants[i], mr[i].first),\n\t\t\tinvmod<ll>(coffs[i], mr[i].first), mr[i].first);\n\
    \t\tassert (v >= 0);\n\n\t\tfor (int j = i + 1; j < (int) mr.size(); j++) {\n\t\
    \t\t(constants[j] += mulmod(coffs[j], v, mr[j].first)) %= mr[j].first;\n\t\t\t\
    coffs[j] = mulmod(coffs[j], mr[i].first, mr[j].first);\n\t\t}\n\t}\n\n\treturn\
    \ constants[mr.size() - 1];\n}\n\n// size : up to 2^20 \n\nusing Mint1 = ModInt<1012924417>;\
    \ //5\nusing Mint2 = ModInt<1224736769>; //3\nusing Mint3 = ModInt<1007681537>;\
    \ //3\nusing Mint4 = ModInt<1045430273>; //4\n\nvector<ll> arbmod_convolution(vector<ll>\
    \ a, vector<ll> b, ll mod) {\n\tfor (auto& x : a) {\n\t\tx %= mod;\n\t}\n\tfor\
    \ (auto& x : b) {\n\t\tx %= mod;\n\t}\n\n\tNumberTheoreticTransform<Mint1> ntt1;\n\
    \tNumberTheoreticTransform<Mint2> ntt2;\n\tNumberTheoreticTransform<Mint3> ntt3;\n\
    \tNumberTheoreticTransform<Mint4> ntt4;\n\n\tntt1.init(); ntt2.init(); ntt3.init();\
    \ ntt4.init();\n\n\tV<Mint1> a1(ALL(a)), b1(ALL(b));\n\tV<Mint2> a2(ALL(a)), b2(ALL(b));\n\
    \tV<Mint3> a3(ALL(a)), b3(ALL(b));\n\tV<Mint4> a4(ALL(a)), b4(ALL(b));\n\n\tauto\
    \ x = ntt1.mul(a1, b1);\n\tauto y = ntt2.mul(a2, b2);\n\tauto z = ntt3.mul(a3,\
    \ b3);\n\tauto w = ntt4.mul(a4, b4);\n\n\tvector<ll> ret(x.size());\n\tvector<pll>\
    \ mr(4);\n\n\trep(i, x.size()) {\n\t\tmr[0] = pll(Mint1::get_mod(), x[i].v);\n\
    \t\tmr[1] = pll(Mint2::get_mod(), y[i].v);\n\t\tmr[2] = pll(Mint3::get_mod(),\
    \ z[i].v);\n\t\tmr[3] = pll(Mint4::get_mod(), w[i].v);\n\t\tret[i] = garner(mr,\
    \ mod);\n\t}\n\n\treturn ret;\n}\n\nint main() {\n\tint N, M; scanf(\"%d %d\"\
    , &N, &M);\n\tV<ll> a(N), b(M);\n\trep(i, N) {\n\t\tscanf(\"%d\", &a[i]);\n\t\
    }\n\trep(i, M) {\n\t\tscanf(\"%d\", &b[i]);\n\t}\t\n\tauto res = arbmod_convolution(a,\
    \ b, TEN(9) + 7);\n\tint sz = res.size();\n\trep(i, sz) printf(\"%d%c\", res[i],\
    \ i == sz-1 ? '\\n' : ' ');\n\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nusing ll = long long;\n\
    using pii = pair<int, int>;\ntemplate<class T> using V = vector<T>;\ntemplate<class\
    \ T> using VV = V<V<T>>;\n\n#define pb push_back\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define fi first\n#define se second\n#define rep(i,n) rep2(i,0,n)\n\
    #define rep2(i,m,n) for(int i=m;i<(n);i++)\n#define ALL(c) (c).begin(),(c).end()\n\
    \n#ifdef LOCAL\n#define dump(x) cerr << __LINE__ << \" \" << #x << \" = \" <<\
    \ (x) << endl\n#else \n#define dump(x) true\n#endif\n\nconstexpr ll TEN(int n)\
    \ { return (n == 0) ? 1 : 10 * TEN(n-1); }\n\ntemplate<class T, class U> void\
    \ chmin(T& t, const U& u) { if (t > u) t = u; }\ntemplate<class T, class U> void\
    \ chmax(T& t, const U& u) { if (t < u) t = u; }\n\ntemplate<class T, class U>\n\
    ostream& operator<<(ostream& os, const pair<T, U>& p) {\n\tos<<\"(\"<<p.first<<\"\
    ,\"<<p.second<<\")\";\n\treturn os;\n}\n\ntemplate<class T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n\tos<<\"{\";\n\trep(i, v.size()) {\n\t\tif (i) os<<\"\
    ,\";\n\t\tos<<v[i];\n\t}\n\tos<<\"}\";\n\treturn os;\n}\n\ntemplate <unsigned\
    \ int MOD>\nstruct ModInt {\n\tusing uint = unsigned int;\n\tusing ull = unsigned\
    \ long long;\n\tusing M = ModInt;\n\n\tuint v;\n\n\tModInt(ll _v = 0) { set_norm(_v\
    \ % MOD + MOD); }\n\tM& set_norm(uint _v) { //[0, MOD * 2)->[0, MOD)\n\t\tv =\
    \ (_v < MOD) ? _v : _v - MOD;\n\t\treturn *this;\n\t}\n\n\texplicit operator bool()\
    \ const { return v != 0; }\n\tM operator+(const M& a) const { return M().set_norm(v\
    \ + a.v); }\n\tM operator-(const M& a) const { return M().set_norm(v + MOD - a.v);\
    \ }\n\tM operator*(const M& a) const { return M().set_norm(ull(v) * a.v % MOD);\
    \ }\n\tM operator/(const M& a) const { return *this * a.inv(); }\n\tM& operator+=(const\
    \ M& a) { return *this = *this + a; }\n\tM& operator-=(const M& a) { return *this\
    \ = *this - a; }\n\tM& operator*=(const M& a) { return *this = *this * a; }\n\t\
    M& operator/=(const M& a) { return *this = *this / a; }\n\tM operator-() const\
    \ { return M() - *this; }\n\tM& operator++(int) { return *this = *this + 1; }\n\
    \tM& operator--(int) { return *this = *this - 1; }\n\n\tM pow(ll n) const {\n\t\
    \tif (n < 0) return inv().pow(-n);\n\t\tM x = *this, res = 1;\n\t\twhile (n) {\n\
    \t\t\tif (n & 1) res *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tM inv() const {\n\t\tll a = v, b = MOD, p = 1, q = 0, t;\n\t\twhile (b\
    \ != 0) {\n\t\t\tt = a / b;\n\t\t\tswap(a -= t * b, b);\n\t\t\tswap(p -= t * q,\
    \ q);\n\t\t}\n\t\treturn M(p);\n\t}\n\n\tbool operator==(const M& a) const { return\
    \ v == a.v; }\n\tbool operator!=(const M& a) const { return v != a.v; }\n\tfriend\
    \ ostream& operator<<(ostream& os, const M& a) { return os << a.v; }\n\tstatic\
    \ int get_mod() { return MOD; }\t\n};\n\n//depend on ModInt, must use NTT friendly\
    \ mod\n\ntemplate<class D>\nstruct NumberTheoreticTransform {\n\tD root;\n\tV<D>\
    \ roots = {0, 1};\n\tV<int> rev = {0, 1};\n\tint base = 1, max_base = -1;\n\n\t\
    void init() {\n\t\tint mod = D::get_mod();\n\t\tint tmp = mod - 1;\n\t\tmax_base\
    \ = 0;\n\t\twhile (tmp % 2 == 0) {\n\t\t\ttmp /= 2;\n\t\t\tmax_base++;\n\t\t}\n\
    \n\t\troot = 2;\n\t\t\n\t\twhile (true) {\n\t\t\tif (root.pow(1 << max_base).v\
    \ == 1) {\n\t\t\t\tif (root.pow(1 << (max_base - 1)).v != 1) {\n\t\t\t\t\tbreak;\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\troot++;\n\t\t}\n\t}\n\n\tvoid ensure_base(int nbase)\
    \ {\n\t\tif (max_base == -1) init();\n\t\tif (nbase <= base) return;\n\t\tassert(nbase\
    \ <= max_base);\n\n\t\trev.resize(1 << nbase);\n\t\tfor (int i = 0; i < (1 <<\
    \ nbase); ++i) {\n\t\t\trev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));\n\
    \t\t}\n\t\troots.resize(1 << nbase);\n\n\t\twhile (base < nbase) {\n\t\t\tD z\
    \ = root.pow(1 << (max_base - 1 - base));\n\t\t\tfor (int i = 1 << (base - 1);\
    \ i < (1 << base); ++i) {\n\t\t\t\troots[i << 1] = roots[i];\n\t\t\t\troots[(i\
    \ << 1) + 1] = roots[i] * z;\n\t\t\t}\n\t\t\t++base;\n\t\t}\n\t}\n\n\tvoid ntt(V<D>\
    \ &a, bool inv = false) {\n\t\tint n = a.size();\n      //assert((n & (n - 1))\
    \ == 0);\n\t\tint zeros = __builtin_ctz(n);\n\t\tensure_base(zeros);\n\t\tint\
    \ shift = base - zeros;\n\n\t\tfor (int i = 0; i < n; i++) {\n\t\t\tif (i < (rev[i]\
    \ >> shift)) {\n\t\t\t\tswap(a[i], a[rev[i] >> shift]);\n\t\t\t}\n\t\t}\n\n\t\t\
    for (int k = 1; k < n; k <<= 1) {\n\t\t\tfor (int i = 0; i < n; i += 2 * k) {\n\
    \t\t\t\tfor (int j = 0; j < k; j++) {\n\t\t\t\t\tD x = a[i + j];\n\t\t\t\t\tD\
    \ y = a[i + j + k] * roots[j + k];\n\t\t\t\t\ta[i + j] = x + y;\n\t\t\t\t\ta[i\
    \ + j + k] = x - y;\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\n\t\tint v = D(n).inv().v;\n\t\
    \tif (inv) {\n\t\t\treverse(a.begin() + 1, a.end());\n\t\t\tfor (int i = 0; i\
    \ < n; i++) {\n\t\t\t\ta[i] *= v;\n\t\t\t}\n\t\t}\n\t}\n\n\tV<D> mul(V<D> a, V<D>\
    \ b) {\n\t\tint s = a.size() + b.size() - 1;\n\t\tint nbase = 1;\n\t\twhile ((1\
    \ << nbase) < s) nbase++;\n\t\tint sz = 1 << nbase;\n\t\ta.resize(sz);\n\t\tb.resize(sz);\n\
    \t\tntt(a);\n\t\tntt(b);\n\n\t\tfor (int i = 0; i < sz; i++) {\n\t\t\ta[i] *=\
    \ b[i];\n\t\t}\n\t\tntt(a, true);\n\n\t\ta.resize(s);\n\t\treturn a;\n\t}\n};\n\
    \n//math314\n\ntemplate<class T> T ext_gcd(T a, T b, T& x, T& y) { for (T u =\
    \ y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v);\
    \ swap(b -= q * a, a); } return b; }\n\ntemplate<class T> T zmod(T a, T b) {\n\
    a %= b;\nif (a < 0) a += b;\nreturn a;\n}\n\ntemplate<class T> T invmod(T a, T\
    \ m) {\nll x, y;\next_gcd(a, m, x, y);\nreturn zmod(x, m);\n}\n\n// \u3053\u3053\
    \u3092 mod \u306B\u5FDC\u3058\u3066\u9069\u5207\u306B\u5909\u3048\u308B\nll mulmod(ll\
    \ x, ll y, ll mod) {\n\treturn x * y % mod;\n}\n\nusing pll = pair<ll, ll>;\n\n\
    ll garner(vector<pll> mr, ll mod) {\n\tmr.push_back(pll(mod, 0));\n\n\tvector<ll>\
    \ coffs(mr.size(), 1);\n\tvector<ll> constants(mr.size(), 0);\n\n\trep(i, (int)mr.size()\
    \ - 1) {\n    // coffs[i] * v + constants[i] == mr[i].second (mod mr[i].first)\
    \ \u3092\u89E3\u304F\n\t\tll v = mulmod(zmod(mr[i].second - constants[i], mr[i].first),\n\
    \t\t\tinvmod<ll>(coffs[i], mr[i].first), mr[i].first);\n\t\tassert (v >= 0);\n\
    \n\t\tfor (int j = i + 1; j < (int) mr.size(); j++) {\n\t\t\t(constants[j] +=\
    \ mulmod(coffs[j], v, mr[j].first)) %= mr[j].first;\n\t\t\tcoffs[j] = mulmod(coffs[j],\
    \ mr[i].first, mr[j].first);\n\t\t}\n\t}\n\n\treturn constants[mr.size() - 1];\n\
    }\n\n// size : up to 2^20 \n\nusing Mint1 = ModInt<1012924417>; //5\nusing Mint2\
    \ = ModInt<1224736769>; //3\nusing Mint3 = ModInt<1007681537>; //3\nusing Mint4\
    \ = ModInt<1045430273>; //4\n\nvector<ll> arbmod_convolution(vector<ll> a, vector<ll>\
    \ b, ll mod) {\n\tfor (auto& x : a) {\n\t\tx %= mod;\n\t}\n\tfor (auto& x : b)\
    \ {\n\t\tx %= mod;\n\t}\n\n\tNumberTheoreticTransform<Mint1> ntt1;\n\tNumberTheoreticTransform<Mint2>\
    \ ntt2;\n\tNumberTheoreticTransform<Mint3> ntt3;\n\tNumberTheoreticTransform<Mint4>\
    \ ntt4;\n\n\tntt1.init(); ntt2.init(); ntt3.init(); ntt4.init();\n\n\tV<Mint1>\
    \ a1(ALL(a)), b1(ALL(b));\n\tV<Mint2> a2(ALL(a)), b2(ALL(b));\n\tV<Mint3> a3(ALL(a)),\
    \ b3(ALL(b));\n\tV<Mint4> a4(ALL(a)), b4(ALL(b));\n\n\tauto x = ntt1.mul(a1, b1);\n\
    \tauto y = ntt2.mul(a2, b2);\n\tauto z = ntt3.mul(a3, b3);\n\tauto w = ntt4.mul(a4,\
    \ b4);\n\n\tvector<ll> ret(x.size());\n\tvector<pll> mr(4);\n\n\trep(i, x.size())\
    \ {\n\t\tmr[0] = pll(Mint1::get_mod(), x[i].v);\n\t\tmr[1] = pll(Mint2::get_mod(),\
    \ y[i].v);\n\t\tmr[2] = pll(Mint3::get_mod(), z[i].v);\n\t\tmr[3] = pll(Mint4::get_mod(),\
    \ w[i].v);\n\t\tret[i] = garner(mr, mod);\n\t}\n\n\treturn ret;\n}\n\nint main()\
    \ {\n\tint N, M; scanf(\"%d %d\", &N, &M);\n\tV<ll> a(N), b(M);\n\trep(i, N) {\n\
    \t\tscanf(\"%d\", &a[i]);\n\t}\n\trep(i, M) {\n\t\tscanf(\"%d\", &b[i]);\n\t}\t\
    \n\tauto res = arbmod_convolution(a, b, TEN(9) + 7);\n\tint sz = res.size();\n\
    \trep(i, sz) printf(\"%d%c\", res[i], i == sz-1 ? '\\n' : ' ');\n\n\treturn 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/math/fft_arbitrarymod.hpp
  requiredBy: []
  timestamp: '2020-09-17 02:07:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/math/fft_arbitrarymod.hpp
layout: document
redirect_from:
- /library/cpp_src/math/fft_arbitrarymod.hpp
- /library/cpp_src/math/fft_arbitrarymod.hpp.html
title: cpp_src/math/fft_arbitrarymod.hpp
---
