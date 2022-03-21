//https://cp-algorithms.com/algebra/prime-sieve-linear.html
//mimic ksun48 implementation

const int X = 1e7;

bitset<X> is_prime;
vector<int> pr;

int mu[X];  // moebius
int pf[X];  // pf[i] := smallest prime p s.t. p | i

void sieve() {
    is_prime.flip();
    is_prime[0] = is_prime[1] = false;
    mu[1] = 1;

    for (int i = 2; i < X; i++) {
        if (is_prime[i]) {
            pr.push_back(i);
            pf[i] = i;
            mu[i] = -1;
        }

        for (int p : pr) {
            if (ll(i) * p >= X) break;
            is_prime[i * p] = false;
            mu[i * p] = -mu[i];
            pf[i * p] = p;
            if (i % p == 0) {
                mu[i * p] = 0;
                break;
            }
        }
    }
}

struct PrimePrepare {
    PrimePrepare() { sieve(); }
} prep_prime;

vector<pii> factorize(int x) {
    vector<pii> vec;
    while (pf[x] > 1) {
        int d = pf[x];
        int c = 0;
        while (x % d == 0) {
            x /= d;
            c++;
        }
        vec.emplace_back(d, c);
    }
    if (x != 1) {
        vec.emplace_back(x, 1);
    }
    return vec;
}