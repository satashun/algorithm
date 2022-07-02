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
  bundledCode: "#line 1 \"cpp_src/string/Trie.cpp\"\ntemplate <int char_size>\nstruct\
    \ TrieNode {\n    array<int, char_size> nxt;\n\n    int exist;\n    vector<int>\
    \ accept;\n\n    TrieNode() : exist(0) { fill(nxt.begin(), nxt.end(), -1); }\n\
    };\n\ntemplate <int char_size, int margin>\nstruct Trie {\n    using Node = TrieNode<char_size>;\n\
    \n    vector<Node> nodes;\n    int root, node_ptr;\n\n    void expand() {\n  \
    \      int sz = nodes.size();\n        nodes.resize(sz * 2);\n    }\n\n    Trie()\
    \ : root(0), node_ptr(1) { nodes.push_back(Node()); }\n\n    void update_direct(int\
    \ node, int id) { nodes[node].accept.push_back(id); }\n\n    void update_child(int\
    \ node, int child, int id) { ++nodes[node].exist; }\n\n    void add(const string\
    \ &str, int str_index, int node_index, int id) {\n        if (str_index == str.size())\
    \ {\n            update_direct(node_index, id);\n        } else {\n          \
    \  const int c = str[str_index] - margin;\n            if (nodes[node_index].nxt[c]\
    \ == -1) {\n                int nxt_id = node_ptr++;\n                nodes[node_index].nxt[c]\
    \ = nxt_id;\n                if (nxt_id >= nodes.size()) expand();\n         \
    \   }\n\n            add(str, str_index + 1, nodes[node_index].nxt[c], id);\n\
    \            update_child(node_index, nodes[node_index].nxt[c], id);\n       \
    \ }\n    }\n\n    void add(const string &str, int id) { add(str, 0, 0, id); }\n\
    \    void add(const string &str) { add(str, nodes[0].exist); }\n\n    int count()\
    \ const { return nodes[0].exist; }\n};\n"
  code: "template <int char_size>\nstruct TrieNode {\n    array<int, char_size> nxt;\n\
    \n    int exist;\n    vector<int> accept;\n\n    TrieNode() : exist(0) { fill(nxt.begin(),\
    \ nxt.end(), -1); }\n};\n\ntemplate <int char_size, int margin>\nstruct Trie {\n\
    \    using Node = TrieNode<char_size>;\n\n    vector<Node> nodes;\n    int root,\
    \ node_ptr;\n\n    void expand() {\n        int sz = nodes.size();\n        nodes.resize(sz\
    \ * 2);\n    }\n\n    Trie() : root(0), node_ptr(1) { nodes.push_back(Node());\
    \ }\n\n    void update_direct(int node, int id) { nodes[node].accept.push_back(id);\
    \ }\n\n    void update_child(int node, int child, int id) { ++nodes[node].exist;\
    \ }\n\n    void add(const string &str, int str_index, int node_index, int id)\
    \ {\n        if (str_index == str.size()) {\n            update_direct(node_index,\
    \ id);\n        } else {\n            const int c = str[str_index] - margin;\n\
    \            if (nodes[node_index].nxt[c] == -1) {\n                int nxt_id\
    \ = node_ptr++;\n                nodes[node_index].nxt[c] = nxt_id;\n        \
    \        if (nxt_id >= nodes.size()) expand();\n            }\n\n            add(str,\
    \ str_index + 1, nodes[node_index].nxt[c], id);\n            update_child(node_index,\
    \ nodes[node_index].nxt[c], id);\n        }\n    }\n\n    void add(const string\
    \ &str, int id) { add(str, 0, 0, id); }\n    void add(const string &str) { add(str,\
    \ nodes[0].exist); }\n\n    int count() const { return nodes[0].exist; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/Trie.cpp
  requiredBy: []
  timestamp: '2022-07-02 19:40:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/Trie.cpp
layout: document
redirect_from:
- /library/cpp_src/string/Trie.cpp
- /library/cpp_src/string/Trie.cpp.html
title: cpp_src/string/Trie.cpp
---
