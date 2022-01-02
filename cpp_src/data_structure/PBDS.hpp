// example : https://atcoder.jp/contests/arc033/submissions/12068324
// see:
// https://xuzijian629.hatenablog.com/entry/2018/12/01/000010
// http://hogloid.hatenablog.com/entry/2014/09/23/132440

// only normal set, use pair for duplication

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// kth (0-indexed) element : find_by_order(k)
// position of x order_of_key(x)

// other : gp_hash_table