---
title: LowLink
documentation_of: ../cpp_src/graph/LowLink.hpp
---

## 橋
- DFS 木の辺 uv が橋 $\iff$ ord[$u$] < low_[$v$]

## 関節点
- DFS 木の根が関節点 $\iff$ (次数) > $1$
- DFS 木の根以外の頂点 $u$ が関節点 $\iff$ $u$ のある子 $v$ に対し ord[$u$] $\leq$ low[$v$]
- 特に、上記を満たす頂点の個数が、$u$ を取り除いたときの連結成分数 


## 参考

- [グラフ探索アルゴリズムとその応用](https://hos.ac/slides/20110504_graph.pdf)
