---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: test/yosupo/suffixarray.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/suffixarray.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-15 11:18:09+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

namespace suffix_array {
template <class T>
void induce(int n, const T s[], bool isL[], int sa[], int l_head[], int B) {
    int buf[B + 2];
    copy_n(l_head, B + 2, buf);

    for (int i = 0; i < n; ++i) {
        if (sa[i] > 0 && isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[buf[pos]++] = sa[i] - 1;
        }
    }

    copy_n(l_head, B + 2, buf);

    for (int i = n - 1; i >= 0; --i) {
        if (sa[i] > 0 && !isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[--buf[pos + 1]] = sa[i] - 1;
        }
    }
}

// sentinel must be added to the end of s in advance

template <class T>
void SA_IS(int n, const T s[], int sa[], int B = 200) {
    bool isL[n];

    isL[n - 1] = false;

    for (int i = n - 2; i >= 0; --i) {
        isL[i] = (s[i] > s[i + 1] || (s[i] == s[i + 1] && isL[i + 1]));
    }

    int l_head[B + 2] = {0};

    for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];

    int sum = 0;

    for (int i = 0; i <= B + 1; ++i) {
        l_head[i] += sum;
        swap(sum, l_head[i]);
    }

    vector<int> lms;
    int lms_id[n];

    fill_n(lms_id, n, -1);

    int buf[B + 2];
    copy_n(l_head, B + 2, buf);

    int now = 0;

    fill_n(sa, n, -1);

    for (int i = 1; i < n; ++i) {
        if (isL[i - 1] && !isL[i]) {
            lms_id[i] = now++;
            lms.push_back(i);
            sa[--buf[(int)s[i] + 1]] = i;
        }
    }

    vector<int> lms2 = lms;
    induce(n, s, isL, sa, l_head, B);

    now = 0;

    for (int i = 0; i < n; ++i) {
        if (lms_id[sa[i]] != -1) {
            lms[now++] = sa[i];
        }
    }

    int s_lms[now], sa_lms[now + 1];

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

    copy_n(l_head, B + 2, buf);

    fill_n(sa, n, -1);

    for (int i = (int)lms.size() - 1; i >= 0; --i) {
        int p = s[lms[i]];
        sa[--buf[p + 1]] = lms[i];
    }

    induce(n, s, isL, sa, l_head, B);
}

template <class T>
void LCP(int n, const T s[], const int sa[], int lcp[]) {
    int rsa[n + 1];
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

const int maxn = 500010;
char s[maxn];
int sa[maxn], lcp[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    suffix_array::SA_IS(n + 1, s, sa);

    rep(i, n) printf("%d%c", sa[i + 1], i == n - 1 ? '\n' : ' ');

    return 0;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/suffixarray.cpp"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define per(i, b) per2(i, 0, b)
#define per2(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define ALL(c) (c).begin(), (c).end()
#define SZ(x) ((int)(x).size())

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

namespace suffix_array {
template <class T>
void induce(int n, const T s[], bool isL[], int sa[], int l_head[], int B) {
    int buf[B + 2];
    copy_n(l_head, B + 2, buf);

    for (int i = 0; i < n; ++i) {
        if (sa[i] > 0 && isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[buf[pos]++] = sa[i] - 1;
        }
    }

    copy_n(l_head, B + 2, buf);

    for (int i = n - 1; i >= 0; --i) {
        if (sa[i] > 0 && !isL[sa[i] - 1]) {
            int pos = (int)s[sa[i] - 1];
            sa[--buf[pos + 1]] = sa[i] - 1;
        }
    }
}

// sentinel must be added to the end of s in advance

template <class T>
void SA_IS(int n, const T s[], int sa[], int B = 200) {
    bool isL[n];

    isL[n - 1] = false;

    for (int i = n - 2; i >= 0; --i) {
        isL[i] = (s[i] > s[i + 1] || (s[i] == s[i + 1] && isL[i + 1]));
    }

    int l_head[B + 2] = {0};

    for (int i = 0; i < n; ++i) ++l_head[(int)s[i]];

    int sum = 0;

    for (int i = 0; i <= B + 1; ++i) {
        l_head[i] += sum;
        swap(sum, l_head[i]);
    }

    vector<int> lms;
    int lms_id[n];

    fill_n(lms_id, n, -1);

    int buf[B + 2];
    copy_n(l_head, B + 2, buf);

    int now = 0;

    fill_n(sa, n, -1);

    for (int i = 1; i < n; ++i) {
        if (isL[i - 1] && !isL[i]) {
            lms_id[i] = now++;
            lms.push_back(i);
            sa[--buf[(int)s[i] + 1]] = i;
        }
    }

    vector<int> lms2 = lms;
    induce(n, s, isL, sa, l_head, B);

    now = 0;

    for (int i = 0; i < n; ++i) {
        if (lms_id[sa[i]] != -1) {
            lms[now++] = sa[i];
        }
    }

    int s_lms[now], sa_lms[now + 1];

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

    copy_n(l_head, B + 2, buf);

    fill_n(sa, n, -1);

    for (int i = (int)lms.size() - 1; i >= 0; --i) {
        int p = s[lms[i]];
        sa[--buf[p + 1]] = lms[i];
    }

    induce(n, s, isL, sa, l_head, B);
}

template <class T>
void LCP(int n, const T s[], const int sa[], int lcp[]) {
    int rsa[n + 1];
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

const int maxn = 500010;
char s[maxn];
int sa[maxn], lcp[maxn];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    suffix_array::SA_IS(n + 1, s, sa);

    rep(i, n) printf("%d%c", sa[i + 1], i == n - 1 ? '\n' : ' ');

    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

