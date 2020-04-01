// allow multiple components

struct Namori {
	int n;
	V<int> deg, par;
	VV<int> g, g2; //g2 for tree from cycles
	V<bool> vis;
	VV<int> cycles;

	Namori(){}
	Namori(int n) : n(n) {
		deg = V<int>(n);
		par = V<int>(n, -1);
		g = VV<int>(n);
		g2 = VV<int>(n);
		vis = V<bool>(n);
	}

	void add_edge(int a, int b) {
		g[a].pb(b); g[b].pb(a);
		++deg[a]; ++deg[b];
	}

	void dfs(int v, V<int>& cycle) {
		vis[v] = true;
		cycle.pb(v);

		for (int to : g[v]) if (deg[to] == 2 && !vis[to]) {
			dfs(to, cycle);
		}
	}

	void dfs2(int v, int p) {
		for (int to : g2[v]) if (to != p) {
			dfs2(to, v);
		}
	}

	void build() {
		queue<int> que;
		rep(i, n) {
			if (deg[i] == 1) {
				que.push(i);
			}
		}

		while (!que.empty()) {
			int v = que.front(); que.pop();
			vis[v] = true;
			for (int to : g[v]) if (deg[to] > 1) {
				g2[to].pb(v);
				par[v] = to;

				if (--deg[to] == 1) {
					que.push(to);
				}
			}
		}

		rep(i, n) if (deg[i] == 2 && !vis[i]) {
			cycles.eb(V<int>{});
			dfs(i, cycles.back());
			V<int> cyc = cycles.back();
			for (int v : cyc) {
				dfs2(v, -1);
			}
		}
	}
};