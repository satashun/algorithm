void enum_partition(int rem, int la, V<int>& cur, VV<int>& all) {
    if (rem == 0) {
        all.pb(cur);
        return;
    }
    for (int j = la; j <= rem; ++j) {
        cur.push_back(j);
        enum_partition(rem - j, j, cur, all);
        cur.pop_back();
    }
}

// ABC226F
// N=50 : 204226
VV<int> enum_partition_exec(int N) {
    VV<int> vec;
    {
        V<int> cur;
        enum_partition(N, 1, cur, vec);
    }
    return vec;
}