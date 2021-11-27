---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "import sys\nimport itertools\nimport numpy as np\n\nread = sys.stdin.buffer.read\n\
    readline = sys.stdin.buffer.readline\nreadlines = sys.stdin.buffer.readlines\n\
    \n\ndef read_np(dtype=np.int64):\n    return np.fromstring(read().decode(), dtype=dtype,\
    \ sep=' ')\n\n\ndef readline_np(dtype=np.int64):\n    return np.fromstring(readline().decode(),\
    \ dtype=dtype, sep=' ')\n"
  dependsOn: []
  isVerificationFile: false
  path: py_src/template.py
  requiredBy: []
  timestamp: '2021-11-27 23:06:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: py_src/template.py
layout: document
redirect_from:
- /library/py_src/template.py
- /library/py_src/template.py.html
title: py_src/template.py
---
