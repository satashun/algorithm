//run length encoding

V<pair<char, int>> rle(const string& s) {
    V<pair<char, int>> res;
    for (auto c : s) {
        if (res.size() > 0 && res.back().first == c) {
            res.back().second++;
        } else {
            res.emplace_back(c, 1);
        }
    }
    return res;
}

template <class T>
V<pair<T, int>> rle(const V<T>& vec) {
    V<pair<T, int>> res;
    for (auto v : vec) {
        if (res.size() > 0 && res.back().first == v) {
            res.back().second++;
        } else {
            res.emplace_back(v, 1);
        }
    }
    return res;
}