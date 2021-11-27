// http://qnighy.hatenablog.com/entry/20100117/1263734784
// http://stackoverflow.com/questions/13792118/kmp-prefix-table
// http://tokyo-ct.net/usr/kosaka/for_students/jissen1/akiyojissen1/kougi16.html

vector<int> pre_kmp(string pat) {
	int k;
	vector<int> table((int)pat.size() + 1);
	table[0] = -1;

	for (int i = 1; i <= pat.size(); ++i) {
		k = table[i-1];

		while (k >= 0) {
			if (pat[k] == pat[i-1]) break;
			else k = table[k];
		}

		table[i] = k + 1;
	}

	return table;
}

int match(string t, string p, vector<int> fail) {
	int n = t.size(), m = p.size();
	int count = 0;

	for (int i = 0, k = 0; i < n; ++i) {
		while (k >= 0 && p[k] != t[i]) {
			k = fail[k];
		}
		if (++k >= m) {
			++count; // match at t[i-m+1 .. i]
			k = fail[k];
		}
	}
	return count;
}