struct Mo {
	V<int> left, right, order;
	V<bool> v;
	int Bsize, nl, nr, ptr;

	Mo(int n) : Bsize((int)sqrt(n+1)), nl(0), nr(0), ptr(0), v(n) {}

	//[l, r)
	void insert(int l, int r) {
		left.push_back(l);
		right.push_back(r);
	}

	void build() {
		order.resize(left.size());
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&](int a, int b) {
			if (left[a] / Bsize != left[b] / Bsize) return left[a] < left[b];
			else return right[a] < right[b];
		});
	}

	//return next event id
	int proceed() {
		if (ptr == order.size()) return -1;
		int id = order[ptr];
		while (nl > left[id]) query(--nl);
		while (nr < right[id]) query(nr++);
		while (nl < left[id]) query(nl++);
		while (nr > right[id]) query(--nr);
		return (order[ptr++]);
	}

	void query(int p) {
		v[p] = !v[p];
		if (v[p]) add(p);
		else del(p);
	}

	void add(int p) {
	}

	void del(int p) {
	}
};