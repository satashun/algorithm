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
    - https://atcoder.jp/contests/abc281/submissions/37651034
  bundledCode: "#line 1 \"cpp_src/other/TopKset.hpp\"\n// ABC281E : https://atcoder.jp/contests/abc281/submissions/37651034\n\
    // sl ... to kth smallest elements\n\nvoid maintain_topk() {\n    multiset<ll>\
    \ sl, sr;\n    ll suml = 0, sumr = 0;\n\n    auto del = [&](ll x) {\n        if\
    \ (sl.find(x) != sl.end()) {\n            sl.erase(sl.find(x));\n            suml\
    \ -= x;\n        } else {\n            sr.erase(sr.find(x));\n            sumr\
    \ -= x;\n        }\n    };\n\n    auto add = [&](ll x) {\n        if (!(SZ(sr)\
    \ != 0 || *sr.begin() <= x)) {\n            sl.insert(x);\n            suml +=\
    \ x;\n        } else {\n            sr.insert(x);\n            sumr += x;\n  \
    \      }\n    };\n\n    auto balance = [&]() {\n        while (SZ(sl) < K && SZ(sr)\
    \ > 0) {\n            ll f = *sr.begin();\n            sr.erase(sr.begin());\n\
    \            sl.insert(f);\n            suml += f;\n            sumr -= f;\n \
    \       }\n        while (SZ(sl) > K) {\n            ll f = *(--sl.end());\n \
    \           sl.erase(--sl.end());\n            sr.insert(f);\n            suml\
    \ -= f;\n            sumr += f;\n        }\n    };\n}\n"
  code: "// ABC281E : https://atcoder.jp/contests/abc281/submissions/37651034\n//\
    \ sl ... to kth smallest elements\n\nvoid maintain_topk() {\n    multiset<ll>\
    \ sl, sr;\n    ll suml = 0, sumr = 0;\n\n    auto del = [&](ll x) {\n        if\
    \ (sl.find(x) != sl.end()) {\n            sl.erase(sl.find(x));\n            suml\
    \ -= x;\n        } else {\n            sr.erase(sr.find(x));\n            sumr\
    \ -= x;\n        }\n    };\n\n    auto add = [&](ll x) {\n        if (!(SZ(sr)\
    \ != 0 || *sr.begin() <= x)) {\n            sl.insert(x);\n            suml +=\
    \ x;\n        } else {\n            sr.insert(x);\n            sumr += x;\n  \
    \      }\n    };\n\n    auto balance = [&]() {\n        while (SZ(sl) < K && SZ(sr)\
    \ > 0) {\n            ll f = *sr.begin();\n            sr.erase(sr.begin());\n\
    \            sl.insert(f);\n            suml += f;\n            sumr -= f;\n \
    \       }\n        while (SZ(sl) > K) {\n            ll f = *(--sl.end());\n \
    \           sl.erase(--sl.end());\n            sr.insert(f);\n            suml\
    \ -= f;\n            sumr += f;\n        }\n    };\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/TopKset.hpp
  requiredBy: []
  timestamp: '2023-12-31 13:48:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/TopKset.hpp
layout: document
redirect_from:
- /library/cpp_src/other/TopKset.hpp
- /library/cpp_src/other/TopKset.hpp.html
title: cpp_src/other/TopKset.hpp
---
