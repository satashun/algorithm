struct LowLink {
	VV<int> g;
	V<int> ord, low;
	V<bool> vis;
	vector<pair<int, int> > bridge;
	vector<int> articulation;

	void init(int n) {
		g.resize(n);
		ord.resize(n);
		low.resize(n);
		vis.resize(n);
	}

	void add_edge(int u, int v) {
		g[u].push_back(v);
		g[v].push_back(u);
	}

	void dfs(int v, int p, int &k) {
		vis[v] = true;

		ord[v] = k++;
		low[v] = ord[v];

		bool isArticulation = false;
		int ct = 0;

		for (int to : g[v]) {
			if (!vis[to]) {
				ct++;
				dfs(to, v, k);
				low[v] = min(low[v], low[to]);
				if (~p && ord[v] <= low[to]) isArticulation = true;
				if (ord[v] < low[to]) bridge.push_back(minmax(v, to));
			} else if (to != p) {
				low[v] = min(low[v], ord[to]);
			}
		}

		if (p == -1 && ct > 1) isArticulation = true;
		if (isArticulation) articulation.push_back(v);
	}
};

//BiConnectedComponents (node)
VV<pii> bc;
V<pii> tmp;

void gen(int v, int p) {
	vis[v] = 1;
	for (int to : g[v]) if (to != p) {
		if (!vis[to] || ord[to] < ord[v]) {
			tmp.eb(min(v, to), max(v, to));
		}
		if (!vis[to]) {
			gen(to, v);
			if (low[to] >= ord[v]) {
				bc.eb();
				while (true) {
					auto e = tmp.back();
					bc.back().eb(e);
					tmp.pop_back();
					if (e.fi == min(to, v) && e.se == max(to, v)) {
						break;
					}
				}
			}
		}
	}
}

//edge 

int cmp[MX];
void DFS(int v, int p, int &k) {
	if (p != -1 && ord[p] >= low[v]) {
		cmp[v] = cmp[p];
	} else {
		cmp[v] = k++;
	}

	for (int to : g[v]) {
		if (cmp[to] == -1) {
			DFS(to, v, k);
		}
	}
}

V<int> gg[MX];
void build(int n) {
	memset(cmp, -1, sizeof(cmp));
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (cmp[i] == -1) {
			DFS(i, -1, k);
		}
	}
	for (auto &e : bridge) {
		int u = cmp[e.fi], v = cmp[e.se];
		gg[u].push_back(v); gg[v].push_back(u);
	}
}