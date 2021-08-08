class tree_hash {
   public:
    using u128 = __uint128_t;
    using u64 = uint64_t;

    static const u64 mod = (1ull << 61ull) - 1;

    static inline u64 add(u64 a, u64 b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline u64 mul(u64 a, u64 b) {
        u128 c = (u128)a * b;
        return add(c >> 61, c & mod);
    }

    vector<u64> hs;
    vector<u64> rnum;
    const int N;
    vector<vector<int>> G;

    tree_hash(int N) : N(N), G(N), hs(N) {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<u64> rand(1000, tree_hash::mod - 1);

        while ((int)rnum.size() < N) {
            auto x = rand(mt);
            rnum.push_back(x);
        }
    }

    void add_edge(const int a, const int b) {
        G[a].push_back(b), G[b].push_back(a);
    }

    pair<int, u64> hash_dfs(int v, int p) {
        int depth = 0;
        u64 res = 1;
        for (auto to : G[v]) {
            if (to == p) continue;
            auto [d, val] = hash_dfs(to, v);
            depth = max(depth, d + 1);
            res = mul(res, val);
        }
        res = add(res, rnum[depth]);
        hs[v] = res;
        return make_pair(depth, res);
    }

    void calc(int root = 0) { hash_dfs(root, -1); }
};