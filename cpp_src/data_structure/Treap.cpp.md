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
  bundledCode: "#line 1 \"cpp_src/data_structure/Treap.cpp\"\n// based on merge, split\
    \ operations\n// pos : 1-indexed\n\nconst int INF = TEN(9);\n\nstruct node_t {\n\
    \    int val;\n    node_t *lch, *rch;\n    int pri;\n    int cnt;\n    int mini;\n\
    \    node_t(int v) : val(v), cnt(1), mini(v) {\n        pri = abs(rand()) % INF;\n\
    \        rch = lch = nullptr;\n    }\n};\n\nint sol_count(node_t *t) { return\
    \ !t ? 0 : t->cnt; }\nint sol_mini(node_t *t) { return !t ? INF : t->mini; }\n\
    \nnode_t *update(node_t *t)\n{\n    t->cnt = sol_count(t->lch) + sol_count(t->rch)\
    \ + 1;\n    t->mini = min(min(sol_mini(t->lch), sol_mini(t->rch)), t->val);\n\
    \    return t;\n}\n\nnode_t *merge(node_t *l, node_t * r)\n{\n    if(!l || !r)\
    \ return !l ? r : l;\n    if(l->pri > r->pri){\n        l->rch = merge(l->rch,\
    \ r);\n        return update(l);\n    }else{\n        r->lch = merge(l, r->lch);\n\
    \        return update(r);\n    }\n}\n\npair<node_t*, node_t*> split(node_t *t,\
    \ int pos)\n{\n    if (!t) return mp((node_t*)NULL, (node_t*)NULL);\n    if (pos\
    \ <= sol_count(t->lch)) {\n        pair<node_t*, node_t*> s = split(t->lch, pos);\n\
    \        t->lch = s.second;\n        return mp(s.first, update(t));\n    } else\
    \ {\n        pair<node_t*, node_t*> s = split(t->rch, pos - sol_count(t->lch)\
    \ - 1);\n        t->rch = s.first;\n        return mp(update(t), s.second);\n\
    \    }\n}\n\nnode_t *insert(node_t *t, int pos, node_t *n)\n{\n    pair<node_t*,\
    \ node_t*> s = split(t, pos - 1);\n    return merge(merge(s.first, n), s.second);\n\
    }\n\nnode_t *remove(node_t *t, int pos)\n{\n    pair<node_t*, node_t*> s;\n  \
    \  s = split(t, pos - 1);\n    return merge(s.first, split(s.second, 1).second);\n\
    }\n\nint get(node_t* t, int pos) {\n    pair<node_t*, node_t*> s = split(t, pos\
    \ - 1);\n    pair<node_t*, node_t*> u = split(s.second, 1);\n    int v = u.first->val;\n\
    \    t = merge(s.first, merge(u.first, u.second));\n    return v;\n}\n"
  code: "// based on merge, split operations\n// pos : 1-indexed\n\nconst int INF\
    \ = TEN(9);\n\nstruct node_t {\n    int val;\n    node_t *lch, *rch;\n    int\
    \ pri;\n    int cnt;\n    int mini;\n    node_t(int v) : val(v), cnt(1), mini(v)\
    \ {\n        pri = abs(rand()) % INF;\n        rch = lch = nullptr;\n    }\n};\n\
    \nint sol_count(node_t *t) { return !t ? 0 : t->cnt; }\nint sol_mini(node_t *t)\
    \ { return !t ? INF : t->mini; }\n\nnode_t *update(node_t *t)\n{\n    t->cnt =\
    \ sol_count(t->lch) + sol_count(t->rch) + 1;\n    t->mini = min(min(sol_mini(t->lch),\
    \ sol_mini(t->rch)), t->val);\n    return t;\n}\n\nnode_t *merge(node_t *l, node_t\
    \ * r)\n{\n    if(!l || !r) return !l ? r : l;\n    if(l->pri > r->pri){\n   \
    \     l->rch = merge(l->rch, r);\n        return update(l);\n    }else{\n    \
    \    r->lch = merge(l, r->lch);\n        return update(r);\n    }\n}\n\npair<node_t*,\
    \ node_t*> split(node_t *t, int pos)\n{\n    if (!t) return mp((node_t*)NULL,\
    \ (node_t*)NULL);\n    if (pos <= sol_count(t->lch)) {\n        pair<node_t*,\
    \ node_t*> s = split(t->lch, pos);\n        t->lch = s.second;\n        return\
    \ mp(s.first, update(t));\n    } else {\n        pair<node_t*, node_t*> s = split(t->rch,\
    \ pos - sol_count(t->lch) - 1);\n        t->rch = s.first;\n        return mp(update(t),\
    \ s.second);\n    }\n}\n\nnode_t *insert(node_t *t, int pos, node_t *n)\n{\n \
    \   pair<node_t*, node_t*> s = split(t, pos - 1);\n    return merge(merge(s.first,\
    \ n), s.second);\n}\n\nnode_t *remove(node_t *t, int pos)\n{\n    pair<node_t*,\
    \ node_t*> s;\n    s = split(t, pos - 1);\n    return merge(s.first, split(s.second,\
    \ 1).second);\n}\n\nint get(node_t* t, int pos) {\n    pair<node_t*, node_t*>\
    \ s = split(t, pos - 1);\n    pair<node_t*, node_t*> u = split(s.second, 1);\n\
    \    int v = u.first->val;\n    t = merge(s.first, merge(u.first, u.second));\n\
    \    return v;\n}"
  dependsOn: []
  isVerificationFile: false
  path: cpp_src/data_structure/Treap.cpp
  requiredBy: []
  timestamp: '2021-10-25 19:28:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpp_src/data_structure/Treap.cpp
layout: document
redirect_from:
- /library/cpp_src/data_structure/Treap.cpp
- /library/cpp_src/data_structure/Treap.cpp.html
title: cpp_src/data_structure/Treap.cpp
---
