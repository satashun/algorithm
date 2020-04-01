#define PROBLEM "https://judge.yosupo.jp/problem/scc"

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

#define call_from_test
#include "../../cpp_src/graph/SCC.hpp"
#undef call_from_test

int main() {
	int N, M; scanf("%d %d", &N, &M);
	SCC scc(N);
	rep(i, M) {
		int a, b;
		scanf("%d %d", &a, &b);
		scc.add_edge(a, b);
	}
	auto v = scc.calc();
	printf("%d\n", v.size());
	rep(i, v.size()) {
		auto &vec = v[i];
		int sz = vec.size();
		printf("%d", sz);
		for (int j = 0; j < vec.size(); ++j) {
			printf(" %d", vec[j]);
		}
		puts("");
	}
	return 0;
}