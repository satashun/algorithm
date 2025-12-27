// ABC412E
// returns: {prime < N}
V<int> enumerate_prime(int N) {
    V<int> is_prime(N, 1);
    V<int> primes;
    if (N < 2) return primes;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i) is_prime[j] = false;
        }
    }
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) primes.push_back(i);
    }
    return primes;
}

// [L,R)
// 1. enumerate primes < max(sqrt(R), R-L)
// 2. check range
// res[x] = some prime p, p | x or 0
V<int> sieve(ll L, ll R) {
    ll n = max<ll>(sqrt(R), R - L) + 1;
    V<int> res(R - L, 0);
    auto vp = enumerate_prime(n);

    for (auto p : vp) {
        for (ll j = max<ll>(p, (L + p - 1) / p) * p; j < R; j += p) {
            res[j - L] = p;
        }
    }
    return res;
}