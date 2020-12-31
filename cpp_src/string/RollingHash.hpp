class RollingHash {
   public:
    using u128 = __uint128_t;
    using u64 = uint64_t;

    static const u64 mod = (1ull << 61ull) - 1;
    vector<u64> power;
    const u64 base;

    static inline u64 add(u64 a, u64 b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline u64 mul(u64 a, u64 b) {
        u128 c = (u128)a * b;
        return add(c >> 61, c & mod);
    }

    // make sure that no different characters / elements have the same value
    // modulo base
    static inline u64 generate_base(int minB = 1000) {
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<u64> rand(minB, RollingHash::mod - 1);
        return rand(mt);
    }

    inline void expand(int sz) {
        if (power.size() <= sz) {
            int pre_sz = (int)power.size();
            power.resize(sz + 1);
            for (int i = pre_sz - 1; i < sz; i++) {
                power[i + 1] = mul(power[i], base);
            }
        }
    }

    explicit RollingHash(u64 base = generate_base()) : base(base), power{1} {}

    vector<u64> build(const string& s) const {
        int sz = s.size();
        vector<u64> vhash(sz + 1);
        for (int i = 0; i < sz; i++) {
            vhash[i + 1] = add(mul(vhash[i], base), s[i]);
        }
        return vhash;
    }

    template <class T>
    vector<u64> build(const vector<T>& s) const {
        int sz = s.size();
        vector<u64> vhash(sz + 1);
        for (int i = 0; i < sz; i++) {
            vhash[i + 1] = add(mul(vhash[i], base), s[i]);
        }
        return vhash;
    }

    u64 query(const vector<u64>& s, int l, int r) {
        expand(r - l);
        return add(s[r], mod - mul(s[l], power[r - l]));
    }

    u64 merge(u64 h1, u64 h2, int h2len) {
        expand(h2len);
        return add(mul(h1, power[h2len]), h2);
    }

    u64 whole_hash(const string& s) const {
        int sz = s.size();
        u64 res = 0;
        for (auto& c : s) res = add(mul(res, base), c);
        return res;
    }
};