---
title: ACL の備忘録
---

## 動的 mod

$m$ が入力で与えられるとき $\mod m$ に設定するには:

``` cpp
using mint = atcoder::modint;
mint::set_mod(m)
```

## lazy_segtree

- 困ったら，単位元かどうかのフラグを持つとよい (例: ABC255Ex)