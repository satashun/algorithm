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
  bundledCode: '#line 1 "cpp_src/other/Bigdecimal.hpp"

    // docs : https://boostjp.github.io/tips/multiprec-float.html

    // -I /usr/local/include/


    #include <boost/multiprecision/cpp_dec_float.hpp>

    #include <boost/multiprecision/cpp_int.hpp>

    namespace mp = boost::multiprecision;


    using Bint = mp::cpp_int;

    using Real = mp::number<mp::cpp_dec_float<30>>;

    '
  code: '// docs : https://boostjp.github.io/tips/multiprec-float.html

    // -I /usr/local/include/


    #include <boost/multiprecision/cpp_dec_float.hpp>

    #include <boost/multiprecision/cpp_int.hpp>

    namespace mp = boost::multiprecision;


    using Bint = mp::cpp_int;

    using Real = mp::number<mp::cpp_dec_float<30>>;

    '
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/other/Bigdecimal.hpp
  requiredBy: []
  timestamp: '2021-08-18 21:00:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/other/Bigdecimal.hpp
layout: document
redirect_from:
- /library/cpp_src/other/Bigdecimal.hpp
- /library/cpp_src/other/Bigdecimal.hpp.html
title: cpp_src/other/Bigdecimal.hpp
---
