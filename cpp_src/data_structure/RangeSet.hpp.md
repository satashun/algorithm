---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://satanic0258.github.io/snippets/data-structure/SegmentMap.html
  bundledCode: "#line 1 \"cpp_src/data_structure/RangeSet.hpp\"\n// ref:\n// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    // ABC254G\n// \u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\
    \u30BF\u69CB\u9020(\u306A\u304A\u5B9F\u88C5\u306Fmap) \u5404\u30AF\u30A8\u30EA\
    O(log\u533A\u9593\u6570)\n\n// #### attention! : [l, r] ( include r, not [l, r)\
    \ )\n// if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true\n\
    \ntemplate <class T, bool flagToMergeAdjacentSegment>\nclass SegmentMap : map<T,\
    \ T> {\n   public:\n    using map<T, T>::begin;\n    using map<T, T>::end;\n \
    \   using map<T, T>::erase;\n    using map<T, T>::upper_bound;\n\n    SegmentMap()\
    \ {}\n\n    // __exist -> iterator pair(l, r) (contain p)\n    // noexist -> map.end()\n\
    \n    auto get(T p) const {\n        auto it = upper_bound(p);\n        if (it\
    \ == begin() || (--it)->second < p) return end();\n        return it;\n    }\n\
    \n    // insert segment [l, r]\n    void insert(T l, T r) {\n        auto itl\
    \ = upper_bound(l),\n             itr = upper_bound(r + flagToMergeAdjacentSegment);\n\
    \        if (itl != begin()) {\n            if ((--itl)->second < l - flagToMergeAdjacentSegment)\
    \ ++itl;\n        }\n        if (itl != itr) {\n            l = min(l, itl->first);\n\
    \            r = max(r, prev(itr)->second);\n            erase(itl, itr);\n  \
    \      }\n        (*this)[l] = r;\n    }\n\n    // remove segment [l, r]\n   \
    \ void remove(T l, T r) {\n        auto itl = upper_bound(l), itr = upper_bound(r);\n\
    \        if (itl != begin()) {\n            if ((--itl)->second < l) ++itl;\n\
    \        }\n        if (itl == itr) return;\n        T tl = min(l, itl->first),\
    \ tr = max(r, prev(itr)->second);\n        erase(itl, itr);\n        if (tl <\
    \ l) (*this)[tl] = l - 1;\n        if (r < tr) (*this)[r + 1] = tr;\n    }\n\n\
    \    // ABC256Ex\n    // [l,r] -> [l,p-1], [p,r]\n    void divide(T p) {\n   \
    \     auto it = get(p);\n        if (it == end()) return;\n        auto [l, r]\
    \ = *it;\n        if (p > l) {\n            erase(it);\n            insert(l,\
    \ p - 1);\n            insert(p, r);\n        }\n    }\n\n    // Is p and q in\
    \ same segment?\n    bool same(T p, T q) const {\n        const auto&& it = get(p);\n\
    \        return it != end() && it->first <= q && q <= it->second;\n    }\n};\n"
  code: "// ref:\n// https://satanic0258.github.io/snippets/data-structure/SegmentMap.html\n\
    // ABC254G\n// \u533A\u9593\u3092set\u3067\u7BA1\u7406\u3059\u308B\u30C7\u30FC\
    \u30BF\u69CB\u9020(\u306A\u304A\u5B9F\u88C5\u306Fmap) \u5404\u30AF\u30A8\u30EA\
    O(log\u533A\u9593\u6570)\n\n// #### attention! : [l, r] ( include r, not [l, r)\
    \ )\n// if merge [l, c] and [c+1, r], set flagToMergeAdjacentSegment to true\n\
    \ntemplate <class T, bool flagToMergeAdjacentSegment>\nclass SegmentMap : map<T,\
    \ T> {\n   public:\n    using map<T, T>::begin;\n    using map<T, T>::end;\n \
    \   using map<T, T>::erase;\n    using map<T, T>::upper_bound;\n\n    SegmentMap()\
    \ {}\n\n    // __exist -> iterator pair(l, r) (contain p)\n    // noexist -> map.end()\n\
    \n    auto get(T p) const {\n        auto it = upper_bound(p);\n        if (it\
    \ == begin() || (--it)->second < p) return end();\n        return it;\n    }\n\
    \n    // insert segment [l, r]\n    void insert(T l, T r) {\n        auto itl\
    \ = upper_bound(l),\n             itr = upper_bound(r + flagToMergeAdjacentSegment);\n\
    \        if (itl != begin()) {\n            if ((--itl)->second < l - flagToMergeAdjacentSegment)\
    \ ++itl;\n        }\n        if (itl != itr) {\n            l = min(l, itl->first);\n\
    \            r = max(r, prev(itr)->second);\n            erase(itl, itr);\n  \
    \      }\n        (*this)[l] = r;\n    }\n\n    // remove segment [l, r]\n   \
    \ void remove(T l, T r) {\n        auto itl = upper_bound(l), itr = upper_bound(r);\n\
    \        if (itl != begin()) {\n            if ((--itl)->second < l) ++itl;\n\
    \        }\n        if (itl == itr) return;\n        T tl = min(l, itl->first),\
    \ tr = max(r, prev(itr)->second);\n        erase(itl, itr);\n        if (tl <\
    \ l) (*this)[tl] = l - 1;\n        if (r < tr) (*this)[r + 1] = tr;\n    }\n\n\
    \    // ABC256Ex\n    // [l,r] -> [l,p-1], [p,r]\n    void divide(T p) {\n   \
    \     auto it = get(p);\n        if (it == end()) return;\n        auto [l, r]\
    \ = *it;\n        if (p > l) {\n            erase(it);\n            insert(l,\
    \ p - 1);\n            insert(p, r);\n        }\n    }\n\n    // Is p and q in\
    \ same segment?\n    bool same(T p, T q) const {\n        const auto&& it = get(p);\n\
    \        return it != end() && it->first <= q && q <= it->second;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/RangeSet.hpp
  requiredBy: []
  timestamp: '2023-02-04 17:43:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/RangeSet.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/RangeSet.hpp
- /library/cpp_src/data_structure/RangeSet.hpp.html
title: cpp_src/data_structure/RangeSet.hpp
---
