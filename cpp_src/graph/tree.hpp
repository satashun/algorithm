#include "graph_template.hpp"

template <class T>
class forest : public Graph<T> {
   public:
    using Graph<T>::g;
    using Graph<T>::edges;
    forest = default;
    forest(int n) : g(n){};
};