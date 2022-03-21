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
    - https://boostjp.github.io/tips/multiprec-float.html
  bundledCode: "#line 1 \"cpp_src/other/Bigdecimal.hpp\"\n// docs : https://boostjp.github.io/tips/multiprec-float.html\n\
    // -I /usr/local/include/\n\n#include <boost/multiprecision/cpp_dec_float.hpp>\n\
    #include <boost/multiprecision/cpp_int.hpp>\nnamespace mp = boost::multiprecision;\n\
    \nusing Bint = mp::cpp_int;\nusing Real = mp::number<mp::cpp_dec_float<30>>;\n\
    \nstring to_string(__int128_t x) {\n    if (x == 0) return \"0\";\n    string\
    \ result;\n    if (x < 0) {\n        result += \"-\";\n        x *= -1;\n    }\n\
    \    string t;\n    while (x) {\n        t.push_back('0' + x % 10);\n        x\
    \ /= 10;\n    }\n    reverse(t.begin(), t.end());\n    return result + t;\n}\n\
    \nostream& operator<<(ostream& o, __int128_t x) { return o << to_string(x); }\n"
  code: "// docs : https://boostjp.github.io/tips/multiprec-float.html\n// -I /usr/local/include/\n\
    \n#include <boost/multiprecision/cpp_dec_float.hpp>\n#include <boost/multiprecision/cpp_int.hpp>\n\
    namespace mp = boost::multiprecision;\n\nusing Bint = mp::cpp_int;\nusing Real\
    \ = mp::number<mp::cpp_dec_float<30>>;\n\nstring to_string(__int128_t x) {\n \
    \   if (x == 0) return \"0\";\n    string result;\n    if (x < 0) {\n        result\
    \ += \"-\";\n        x *= -1;\n    }\n    string t;\n    while (x) {\n       \
    \ t.push_back('0' + x % 10);\n        x /= 10;\n    }\n    reverse(t.begin(),\
    \ t.end());\n    return result + t;\n}\n\nostream& operator<<(ostream& o, __int128_t\
    \ x) { return o << to_string(x); }"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/Bigdecimal.hpp
  requiredBy: []
  timestamp: '2022-03-21 17:35:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/Bigdecimal.hpp
layout: document
redirect_from:
- /library/cpp_src/other/Bigdecimal.hpp
- /library/cpp_src/other/Bigdecimal.hpp.html
title: cpp_src/other/Bigdecimal.hpp
---
