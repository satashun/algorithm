// floor(a / b)
ll div_floor(ll a, ll b) {
    return a / b - (((a ^ b) < 0 && a % b != 0) ? 1 : 0);
}

// ceil(a / b)
ll div_ceil(ll a, ll b) {
    return a / b + (((a ^ b) > 0 && a % b != 0) ? 1 : 0);
}

constexpr ll floor_sqrt(ll n) {
    if (n == 0) return 0;
    return llround(trunc(floor(sqrt((long double)n))));
}

// from USACO
using ull = unsigned long long;
using L = __uint128_t;

struct FastMod {
    ull b, m;
    FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
    ull reduce(ull a) {
        ull q = (ull)((L(m) * a) >> 64);
        ull r = a - q * b;  // can be proven that 0 <= r < 2*b
        return r >= b ? r - b : r;
    }
};