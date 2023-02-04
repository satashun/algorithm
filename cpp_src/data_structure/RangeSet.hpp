// ref:
// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
// ABC254G
// 区間をsetで管理するデータ構造(なお実装はmap) 各クエリO(log区間数)

// #### attention! : [l, r] ( include r, not [l, r) )
// if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true

template <class T, bool flagToMergeAdjacentSegment>
class SegmentMap : map<T, T> {
   public:
    using map<T, T>::begin;
    using map<T, T>::end;
    using map<T, T>::erase;
    using map<T, T>::upper_bound;

    SegmentMap() {}

    // __exist -> iterator pair(l, r) (contain p)
    // noexist -> map.end()

    auto get(T p) const {
        auto it = upper_bound(p);
        if (it == begin() || (--it)->second < p) return end();
        return it;
    }

    // insert segment [l, r]
    void insert(T l, T r) {
        auto itl = upper_bound(l),
             itr = upper_bound(r + flagToMergeAdjacentSegment);
        if (itl != begin()) {
            if ((--itl)->second < l - flagToMergeAdjacentSegment) ++itl;
        }
        if (itl != itr) {
            l = min(l, itl->first);
            r = max(r, prev(itr)->second);
            erase(itl, itr);
        }
        (*this)[l] = r;
    }

    // remove segment [l, r]
    void remove(T l, T r) {
        auto itl = upper_bound(l), itr = upper_bound(r);
        if (itl != begin()) {
            if ((--itl)->second < l) ++itl;
        }
        if (itl == itr) return;
        T tl = min(l, itl->first), tr = max(r, prev(itr)->second);
        erase(itl, itr);
        if (tl < l) (*this)[tl] = l - 1;
        if (r < tr) (*this)[r + 1] = tr;
    }

    // ABC256Ex
    // [l,r] -> [l,p-1], [p,r]
    void divide(T p) {
        auto it = get(p);
        if (it == end()) return;
        auto [l, r] = *it;
        if (p > l) {
            erase(it);
            insert(l, p - 1);
            insert(p, r);
        }
    }

    // Is p and q in same segment?
    bool same(T p, T q) const {
        const auto&& it = get(p);
        return it != end() && it->first <= q && q <= it->second;
    }
};