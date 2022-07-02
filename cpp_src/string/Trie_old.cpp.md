---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"cpp_src/string/Trie_old.cpp\"\nstruct Trie {\n\tint value;\n\
    \tTrie *next[0x100];\n\tTrie() { fill(next, next+0x100, nullptr); }\n};\n\nTrie\
    \ *find(const string &t, Trie *r) {\n\tfor (int i = 0; i < t.size(); ++i) {\n\t\
    \tchar c = t[i];\n\t\tif (!r->next[c]) r->next[c] = new Trie;\n\t\tr = r->next[c];\n\
    \t}\n\treturn r;\n}\n"
  code: "struct Trie {\n\tint value;\n\tTrie *next[0x100];\n\tTrie() { fill(next,\
    \ next+0x100, nullptr); }\n};\n\nTrie *find(const string &t, Trie *r) {\n\tfor\
    \ (int i = 0; i < t.size(); ++i) {\n\t\tchar c = t[i];\n\t\tif (!r->next[c]) r->next[c]\
    \ = new Trie;\n\t\tr = r->next[c];\n\t}\n\treturn r;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/Trie_old.cpp
  requiredBy: []
  timestamp: '2022-07-02 19:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/Trie_old.cpp
layout: document
redirect_from:
- /library/cpp_src/string/Trie_old.cpp
- /library/cpp_src/string/Trie_old.cpp.html
title: cpp_src/string/Trie_old.cpp
---
