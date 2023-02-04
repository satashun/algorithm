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
    - https://ei1333.github.io/library/string/aho-corasick.hpp.html
  bundledCode: "#line 1 \"cpp_src/string/AhoCorasick.hpp\"\n// ref: https://ei1333.github.io/library/string/aho-corasick.hpp.html\n\
    // depends on Trie\n// ABC268H\n\ntemplate <int char_size, int margin>\nstruct\
    \ AhoCorasick : public Trie<char_size + 1, margin> {\n    using Trie<char_size\
    \ + 1, margin>::Trie;\n\n    const int FAIL = char_size;\n    vector<int> correct;\n\
    \n    void build(bool heavy = true) {\n        correct.resize(this->size());\n\
    \        for (int i = 0; i < this->size(); i++) {\n            correct[i] = (int)this->nodes[i].accept.size();\n\
    \        }\n        queue<int> que;\n        for (int i = 0; i <= char_size; i++)\
    \ {\n            if (~this->nodes[0].nxt[i]) {\n                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL]\
    \ = 0;\n                que.emplace(this->nodes[0].nxt[i]);\n            } else\
    \ {\n                this->nodes[0].nxt[i] = 0;\n            }\n        }\n  \
    \      while (!que.empty()) {\n            auto& now = this->nodes[que.front()];\n\
    \            int fail = now.nxt[FAIL];\n            correct[que.front()] += correct[fail];\n\
    \            que.pop();\n            for (int i = 0; i < char_size; i++) {\n \
    \               if (~now.nxt[i]) {\n                    this->nodes[now.nxt[i]].nxt[FAIL]\
    \ =\n                        this->nodes[fail].nxt[i];\n                    if\
    \ (heavy) {\n                        auto& u = this->nodes[now.nxt[i]].accept;\n\
    \                        auto& v = this->nodes[this->nodes[fail].nxt[i]].accept;\n\
    \                        vector<int> accept;\n                        set_union(begin(u),\
    \ end(u), begin(v), end(v),\n                                  back_inserter(accept));\n\
    \                        u = accept;\n                    }\n                \
    \    que.emplace(now.nxt[i]);\n                } else {\n                    now.nxt[i]\
    \ = this->nodes[fail].nxt[i];\n                }\n            }\n        }\n \
    \   }\n\n    map<int, int> match(const string& str, int now = 0) {\n        map<int,\
    \ int> result;\n        for (auto& c : str) {\n            now = this->nodes[now].nxt[c\
    \ - margin];\n            for (auto& v : this->nodes[now].accept) result[v] +=\
    \ 1;\n        }\n        return result;\n    }\n\n    pair<int64_t, int> move(const\
    \ char& c, int now = 0) {\n        now = this->nodes[now].nxt[c - margin];\n \
    \       return {correct[now], now};\n    }\n\n    pair<int64_t, int> move(const\
    \ string& str, int now = 0) {\n        int64_t sum = 0;\n        for (auto& c\
    \ : str) {\n            auto nxt = move(c, now);\n            sum += nxt.first;\n\
    \            now = nxt.second;\n        }\n        return {sum, now};\n    }\n\
    };\n"
  code: "// ref: https://ei1333.github.io/library/string/aho-corasick.hpp.html\n//\
    \ depends on Trie\n// ABC268H\n\ntemplate <int char_size, int margin>\nstruct\
    \ AhoCorasick : public Trie<char_size + 1, margin> {\n    using Trie<char_size\
    \ + 1, margin>::Trie;\n\n    const int FAIL = char_size;\n    vector<int> correct;\n\
    \n    void build(bool heavy = true) {\n        correct.resize(this->size());\n\
    \        for (int i = 0; i < this->size(); i++) {\n            correct[i] = (int)this->nodes[i].accept.size();\n\
    \        }\n        queue<int> que;\n        for (int i = 0; i <= char_size; i++)\
    \ {\n            if (~this->nodes[0].nxt[i]) {\n                this->nodes[this->nodes[0].nxt[i]].nxt[FAIL]\
    \ = 0;\n                que.emplace(this->nodes[0].nxt[i]);\n            } else\
    \ {\n                this->nodes[0].nxt[i] = 0;\n            }\n        }\n  \
    \      while (!que.empty()) {\n            auto& now = this->nodes[que.front()];\n\
    \            int fail = now.nxt[FAIL];\n            correct[que.front()] += correct[fail];\n\
    \            que.pop();\n            for (int i = 0; i < char_size; i++) {\n \
    \               if (~now.nxt[i]) {\n                    this->nodes[now.nxt[i]].nxt[FAIL]\
    \ =\n                        this->nodes[fail].nxt[i];\n                    if\
    \ (heavy) {\n                        auto& u = this->nodes[now.nxt[i]].accept;\n\
    \                        auto& v = this->nodes[this->nodes[fail].nxt[i]].accept;\n\
    \                        vector<int> accept;\n                        set_union(begin(u),\
    \ end(u), begin(v), end(v),\n                                  back_inserter(accept));\n\
    \                        u = accept;\n                    }\n                \
    \    que.emplace(now.nxt[i]);\n                } else {\n                    now.nxt[i]\
    \ = this->nodes[fail].nxt[i];\n                }\n            }\n        }\n \
    \   }\n\n    map<int, int> match(const string& str, int now = 0) {\n        map<int,\
    \ int> result;\n        for (auto& c : str) {\n            now = this->nodes[now].nxt[c\
    \ - margin];\n            for (auto& v : this->nodes[now].accept) result[v] +=\
    \ 1;\n        }\n        return result;\n    }\n\n    pair<int64_t, int> move(const\
    \ char& c, int now = 0) {\n        now = this->nodes[now].nxt[c - margin];\n \
    \       return {correct[now], now};\n    }\n\n    pair<int64_t, int> move(const\
    \ string& str, int now = 0) {\n        int64_t sum = 0;\n        for (auto& c\
    \ : str) {\n            auto nxt = move(c, now);\n            sum += nxt.first;\n\
    \            now = nxt.second;\n        }\n        return {sum, now};\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/string/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2023-02-04 17:43:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/string/AhoCorasick.hpp
layout: document
redirect_from:
- /library/cpp_src/string/AhoCorasick.hpp
- /library/cpp_src/string/AhoCorasick.hpp.html
title: cpp_src/string/AhoCorasick.hpp
---
