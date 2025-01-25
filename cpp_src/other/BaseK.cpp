// modified tute's: https:atcoder.jp/contests/abc380/submissions/59844687

V<ll> pw_base{1};

template <ll base, ll sz>
struct Bits {
    vector<ll> data;
    ll value;
    Bits() { data.assign(sz, 0); };
    Bits(ll k) : value(k) {
        data.assign(sz, 0);
        build(k);
    }
    void build(ll k) {
        for (ll i = 0; i < sz; i++) {
            data[i] = k % base;
            k /= base;
        }
    }
    void set(int k, int v) {
        value += pw_base[k] * (v - data[k]);
        data[k] = v;
    }

    // don't change data and val
    ll set_val(int k, int v) { return value + pw_base[k] * (v - data[k]); }

    Bits& operator=(const ll k) {
        fill(ALL(this->data), 0);
        this->build(k);
    }
    ll& operator[](const ll k) { return data[k]; }
    static ll pow(ll k) {
        ll ret = 1;
        while (k--) ret *= base;
        return ret;
    }
    void print() {
        for (ll i = sz - 1; i >= 0; i--) {
            if (i != sz - 1) cout << " ";
            cout << data[i];
        }
        cout << endl;
    }
};

// using bits = Bits<3, 14>;