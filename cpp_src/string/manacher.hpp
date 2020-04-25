vector<int> manacher(const string &_s) {
    int n = _s.size();

    string s(n*2-1, '#');

    for (int i = 0; i < n; ++i) {
        s[i*2] = _s[i];
    }

    n = s.size();

    vector<int> rad(n);

    int i = 0, j = 0;

    while (i < n) {
        while (i-j >= 0 && i+j<n && s[i-j] == s[i+j]) ++j;
        rad[i] = j;

        int k = 1;
        while (i-k >= 0 && i+k < n && k+rad[i-k] < j) {
            rad[i+k] = rad[i-k];
            ++k;
        }

        i += k;
        j -= k;
    }

    return rad;
}