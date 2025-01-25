// O(NB + Q(N/B)) (B : numver of blocks)
// set B = sqrt(Q) -> O(N sqrt(Q) * F)
// F : cost of operation
// ref : https://ei1333.hateblo.jp/entry/2017/09/11/211011
// ref : https://nyaannyaan.github.io/library/misc/mo.hpp
// https://atcoder.jp/contests/abc293/submissions/39637410
// my sub: https://atcoder.jp/contests/abc293/submissions/40402531

struct Mo {
    V<int> left, right, order;
    int n, Bsize, nl, nr, ptr;

    Mo(int n) : n(n), nl(0), nr(0), ptr(0) {}

    //[l, r)
    void insert(int l, int r) {
        left.push_back(l);
        right.push_back(r);
    }

    void build() {
        // Bsize = n / min<int>(n, sqrt(left.size()));
        Bsize = max<int>(
            1, 1.0 * n / max<double>(1.0, sqrt(left.size() * 2.0 / 3.0)));
        order.resize(left.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            if (left[a] / Bsize != left[b] / Bsize)
                return left[a] < left[b];
            else
                return right[a] < right[b];
        });
    }

    // return next event id
    int proceed() {
        if (ptr == order.size()) return -1;
        int id = order[ptr];
        while (nl > left[id]) query(--nl);
        while (nr < right[id]) query(nr++);
        while (nl < left[id]) query(nl++);
        while (nr > right[id]) query(--nr);
        return (order[ptr++]);
    }

    void query(int p) {}

    template <typename AL, typename AR, typename DL, typename DR, typename F>
    void run(AL add_left, AR add_right, DL del_left, DR del_right, F f) {
        nl = 0, nr = 0;
        for (auto id : order) {
            while (nl > left[id]) add_left(--nl);
            while (nr < right[id]) add_right(nr++);
            while (nl < left[id]) del_left(nl++);
            while (nr > right[id]) del_right(--nr);
            f(id);
        }
    }

    template <typename A, typename D, typename F>
    void run(A add, D del, F f) {
        run(add, add, del, del, f);
    }
};