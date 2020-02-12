//E : int or edge class

template<class E>
struct LCA {
	VV<int> anc;
	V<int> dep;
	int lg;
	const VV<E>& g;

	LCA(const VV<E>& g, int root) : g(g) {
		int n = g.size();
		lg = 1;
		while ((1 << lg) < n) lg++;
		anc = VV<int>(lg, V<int>(n, -1));
		dep = V<int>(n);
		dfs(root, -1, 0);

		for (int i = 1; i < lg; i++) {
			for (int j = 0; j < n; j++) {
				anc[i][j] = (anc[i - 1][j] == -1) ? -1 : anc[i - 1][anc[i - 1][j]];
			}
		}		
	}

	void dfs(int v, int p, int d) {
		anc[0][v] = p;
		dep[v] = d;
		for (auto e : g[v]) {
			int to = e;
			if (to == p) continue;
			dfs(to, v, d + 1);
		}
	}

	int query(int u, int v) {
		if (dep[u] < dep[v]) swap(u, v);
		int df = dep[u] - dep[v];
		for (int i = lg - 1; i >= 0; --i) {
			if ((df >> i) & 1) {
				df -= (1 << i);
				u = anc[i][u];
			}
		}
		if (u == v) return u;
		for (int i = lg - 1; i >= 0; --i) {
			if (anc[i][u] != anc[i][v]) {
				u = anc[i][u];
				v = anc[i][v];
			}
		}
		return anc[0][u];
	}
};