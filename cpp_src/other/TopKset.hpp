// ABC281E : https://atcoder.jp/contests/abc281/submissions/37651034
// sl ... to kth smallest elements

void maintain_topk() {
    multiset<ll> sl, sr;
    ll suml = 0, sumr = 0;

    auto del = [&](ll x) {
        if (sl.find(x) != sl.end()) {
            sl.erase(sl.find(x));
            suml -= x;
        } else {
            sr.erase(sr.find(x));
            sumr -= x;
        }
    };

    auto add = [&](ll x) {
        if (SZ(sl) == 0 || *sl.rbegin() >= x) {
            sl.insert(x);
            suml += x;
        } else {
            sr.insert(x);
            sumr += x;
        }
    };

    auto balance = [&]() {
        while (SZ(sl) < K && SZ(sr) > 0) {
            ll f = *sr.begin();
            sr.erase(sr.begin());
            sl.insert(f);
            suml += f;
            sumr -= f;
        }
        while (SZ(sl) > K) {
            ll f = *(--sl.end());
            sl.erase(--sl.end());
            sr.insert(f);
            suml -= f;
            sumr += f;
        }
    };
}