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
    - http://hogloid.hatenablog.com/entry/2014/09/23/132440
    - https://atcoder.jp/contests/arc033/submissions/12068324
    - https://xuzijian629.hatenablog.com/entry/2018/12/01/000010
  bundledCode: "#line 1 \"cpp_src/data_structure/PBDS.hpp\"\n// example : https://atcoder.jp/contests/arc033/submissions/12068324\n\
    // see:\n// https://xuzijian629.hatenablog.com/entry/2018/12/01/000010\n// http://hogloid.hatenablog.com/entry/2014/09/23/132440\n\
    \n// only normal set, use pair for duplication\n\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds;\ntemplate\
    \ <class T>\nusing ordered_set =\n    tree<T, null_type, less<T>, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n\n// kth (0-indexed) element : find_by_order(k)\n\
    // position of x order_of_key(x)\n\n// other : gp_hash_table\n"
  code: "// example : https://atcoder.jp/contests/arc033/submissions/12068324\n//\
    \ see:\n// https://xuzijian629.hatenablog.com/entry/2018/12/01/000010\n// http://hogloid.hatenablog.com/entry/2014/09/23/132440\n\
    \n// only normal set, use pair for duplication\n\n#include <ext/pb_ds/assoc_container.hpp>\n\
    #include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds;\ntemplate\
    \ <class T>\nusing ordered_set =\n    tree<T, null_type, less<T>, rb_tree_tag,\
    \ tree_order_statistics_node_update>;\n\n// kth (0-indexed) element : find_by_order(k)\n\
    // position of x order_of_key(x)\n\n// other : gp_hash_table"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/PBDS.hpp
  requiredBy: []
  timestamp: '2022-01-02 16:22:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/PBDS.hpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/PBDS.hpp
- /library/cpp_src/data_structure/PBDS.hpp.html
title: cpp_src/data_structure/PBDS.hpp
---
