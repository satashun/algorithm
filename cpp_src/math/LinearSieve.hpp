//https://cp-algorithms.com/algebra/prime-sieve-linear.html

const int maxv = 10000010;
// lowest prime factor
int lp[maxv];
bool pri[maxv];
vector<int> pr;

void linear_sive() {
    for (int i = 2; i < maxv; ++i) pri[i] = true;
    for (int i = 2; i < maxv; ++i) {
        if (pri[i]) {
            lp[i] = i;
            pr.pb(i);
        }
        for (int j = 0;
             j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < maxv; ++j) {
            pri[i * pr[j]] = false;
            lp[i * pr[j]] = pr[j];
            if (i % pr[j] == 0) break;
        }
    }
}