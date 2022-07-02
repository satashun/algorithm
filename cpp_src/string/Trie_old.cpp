struct Trie {
	int value;
	Trie *next[0x100];
	Trie() { fill(next, next+0x100, nullptr); }
};

Trie *find(const string &t, Trie *r) {
	for (int i = 0; i < t.size(); ++i) {
		char c = t[i];
		if (!r->next[c]) r->next[c] = new Trie;
		r = r->next[c];
	}
	return r;
}