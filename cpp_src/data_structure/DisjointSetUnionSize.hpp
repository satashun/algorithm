class unionfind {
	vector<int> par, size;

public:
	void init(int n) {
		par.resize(n);
		size.resize(n);

		for (int i = 0; i < n; i++) {
			par[i] = i;
			size[i] = 1;
		}
	}

    unionfind() {}
    unionfind(int n) { init(n); }
    
	int find(int x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}

	bool unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return false;
		if (size[x] < size[y]) swap(x, y);

		par[y] = x;
		size[x] += size[y];
        return true;
	}

	bool same(int x, int y) { return (find(x) == find(y)); }
	int get_size(int x) { return size[find(x)]; }

};
