template <class T, class U>
T powmod(T x, U k, T m) {
    x %= m;
    T res = 1 % m;
    while (k) {
        if (k & 1) {
            res = res * x % m;
        }
        k >>= 1;
        x = x * x % m;
    }
    return res;
}

// see : https://joisino.hatenablog.com/entry/2017/08/03/210000
// see : https://misteer.hatenablog.com/entry/miller-rabin
// test : https://yukicoder.me/problems/no/3030
// ref : http://miller-rabin.appspot.com/
// check if n is prime
// n < 4,759,123,141 -> call miller_rabin
// 2^64 > n >= 4,759,123,141 -> call miller_rabin_big
// O(k log^3 n)

bool miller_rabin(ll n) {
    static const vector<ll> v = {2, 7, 61};
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    for (auto a : v) {
        if (a % n == 0) continue;
        auto x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;

        rep(r, s) {
            auto y = x * x % n;
            if (y == 1) {
                if (x != 1 && x != n - 1) {
                    return false;
                } else {
                    x = 1;
                    break;
                }
            }
            x = y;
        }
        if (x != 1) return false;
    }
    return true;
}

using R = __int128_t;
using ull = unsigned long long;
bool miller_rabin_big(ull n) {
    static const vector<R> v = {2,      325,     9375,      28178,
                                450775, 9780504, 1795265022};

    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }

    ull d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    for (auto a : v) {
        if (a % n == 0) continue;
        auto x = powmod(a, d, R(n));
        if (x == 1 || x == n - 1) continue;

        rep(r, s) {
            auto y = x * x % n;
            if (y == 1) {
                if (x != 1 && x != n - 1) {
                    return false;
                } else {
                    x = 1;
                    break;
                }
            }
            x = y;
        }
        if (x != 1) return false;
    }
    return true;
}
