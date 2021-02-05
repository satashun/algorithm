struct starry_sky_tree {
    const int inf = -1e9;
    V<int> all, ma;
    int sz;

    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        all.resize(sz * 2);
        ma.resize(sz * 2);
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            all[k] += x;
            return;
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] =
            max(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
    }

    int get(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return inf;
        if (a <= l && r <= b) {
            return ma[k] + all[k];
        }

        int lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        int rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        return max(lc, rc) + all[k];
    }

    int get() { return ma[0] + all[0]; }
} seg;

int sz;
const int INF = TEN(9);

struct starry_sky_tree {
    int all[1<<19], ma[1<<19], cnt[1<<19];

    void init(int n) {
        sz = 1;
        while (sz < n) sz *= 2;
        rep(i, sz * 2) {
            all[i] = 0;
            ma[i] = 0;
            cnt[i] = 0;
        }
        for (int i = sz - 1; i < sz * 2 - 1; ++i) {
            cnt[i] = 1;
        }
        for (int i = sz - 1 + n; i < sz * 2 - 1; ++i) {
            ma[i] = INF;
        }
        for (int i = sz - 2; i >= 0; --i) {
            ma[i] = min(ma[i * 2 + 1], ma[i * 2 + 2]);
            cnt[i] = 0;
            if (ma[i] == ma[i * 2 + 1]) {
                cnt[i] += cnt[i * 2 + 1];
            }
            if (ma[i] == ma[i * 2 + 2]) {
                cnt[i] += cnt[i * 2 + 2];
            }           
        }
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if (b <= l || r <= a) return ;
        if (a <= l && r <= b) {
            all[k] += x; return ; 
        }

        add(a, b, x, k * 2 + 1, l, (l + r) / 2);
        add(a, b, x, k * 2 + 2, (l + r) / 2, r);
        ma[k] = min(ma[k * 2 + 1] + all[k * 2 + 1], ma[k * 2 + 2] + all[k * 2 + 2]);
        cnt[k] = 0;
        if (ma[k] == ma[k * 2 + 1] + all[k * 2 + 1]) {
            cnt[k] += cnt[k * 2 + 1];
        }
        if (ma[k] == ma[k * 2 + 2] + all[k * 2 + 2]) {
            cnt[k] += cnt[k * 2 + 2];
        }        
    }

    pii get(int a, int b, int k, int l, int r) {
        if (b <= l || r <= a) return mp(INF, 0);
        if (a <= l && r <= b) {
            return mp(ma[k] + all[k], cnt[k]);
        }

        pii lc = get(a, b, k * 2 + 1, l, (l + r) / 2);
        pii rc = get(a, b, k * 2 + 2, (l + r) / 2, r);
        int num = 0;
        int mini = min(lc.fi, rc.fi);
        if (mini == lc.fi) {
            num += lc.se;
        }
        if (mini == rc.fi) {
            num += rc.se;
        }
        return mp(mini + all[k], num);
    }
} seg;