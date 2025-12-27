// vector version
// ARC151E: https://atcoder.jp/contests/arc151/submissions/71591899

namespace suffix_array {
template <class T>
void induce(int n, V<T>& s, V<int> isL, V<int>& sa, V<int> l_head, int B) {
    V<int> buf = l_head;

    for (int i = 0; i < n; ++i) {
        if (sa[i] > 0 && isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[buf[pos]++] = sa[i] - 1;
        }
    }

    buf = l_head;
    for (int i = n - 1; i >= 0; --i) {
        if (sa[i] > 0 && !isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[--buf[pos + 1]] = sa[i] - 1;
        }
    }
}

// sentinel must be added to the end of s in advance

template <class T>
void SA_IS(int n, V<T>& s, V<int>& sa, int B = 200) {
    V<int> isL(n);
    isL[n - 1] = false;

    for (int i = n - 2; i >= 0; --i) {
        isL[i] = (s[i] > s[i + 1] || (s[i] == s[i + 1] && isL[i + 1]));
    }

    V<int> l_head(B + 2);
    for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];

    int sum = 0;

    for (int i = 0; i <= B + 1; ++i) {
        l_head[i] += sum;
        swap(sum, l_head[i]);
    }

    V<int> lms;
    V<int> lms_id(n, -1);

    V<int> buf = l_head;
    int now = 0;
    rep(i, n) sa[i] = -1;

    for (int i = 1; i < n; ++i) {
        if (isL[i - 1] && !isL[i]) {
            lms_id[i] = now++;
            lms.push_back(i);
            sa[--buf[(int)s[i] + 1]] = i;
        }
    }

    V<int> lms2 = lms;
    induce(n, s, isL, sa, l_head, B);

    now = 0;

    for (int i = 0; i < n; ++i) {
        if (lms_id[sa[i]] != -1) {
            lms[now++] = sa[i];
        }
    }

    V<int> s_lms(now), sa_lms(now + 1);

    now = 0;
    s_lms[lms_id[lms[0]]] = 0;

    for (int i = 1; i < lms.size(); ++i) {
        int u = lms[i - 1], v = lms[i];

        bool diff = false;

        for (int j = 0; j < n; ++j) {
            if (s[u + j] != s[v + j] || isL[u + j] != isL[v + j]) {
                diff = true;
                break;
            }

            if (j > 0 && (lms_id[u + j] != -1 || lms_id[v + j] != -1)) break;
        }

        if (diff) now++;
        s_lms[lms_id[lms[i]]] = now;
    }

    if (now + 1 != lms.size()) {
        SA_IS(lms.size(), s_lms, sa_lms, now);
    } else {
        for (int i = 0; i < lms.size(); ++i) {
            sa_lms[s_lms[i]] = i;
        }
    }

    for (int i = 0; i < lms.size(); ++i) {
        lms[i] = lms2[sa_lms[i]];
    }

    buf = l_head;
    rep(i, n) sa[i] = -1;

    for (int i = (int)lms.size() - 1; i >= 0; --i) {
        int p = s[lms[i]];
        sa[--buf[p + 1]] = lms[i];
    }

    induce(n, s, isL, sa, l_head, B);
}

template <class T>
void LCP(int n, V<T> s, V<int> sa, V<int>& lcp) {
    V<int> rsa(n + 1);
    for (int i = 0; i <= n; i++) {
        rsa[sa[i]] = i;
    }

    int h = 0;
    for (int i = 0; i < n; i++) {
        int j = sa[rsa[i] - 1];

        if (h > 0) h--;
        for (; j + h < n && i + h < n; h++) {
            if (s[j + h] != s[i + h]) break;
        }
        lcp[rsa[i] - 1] = h;
    }
}
};  // namespace suffix_array