// based on merge, split operations
// pos : 1-indexed

const int INF = TEN(9);

struct node_t {
    int val;
    node_t *lch, *rch;
    int pri;
    int cnt;
    int mini;
    node_t(int v) : val(v), cnt(1), mini(v) {
        pri = abs(rand()) % INF;
        rch = lch = nullptr;
    }
};

int sol_count(node_t *t) { return !t ? 0 : t->cnt; }
int sol_mini(node_t *t) { return !t ? INF : t->mini; }

node_t *update(node_t *t)
{
    t->cnt = sol_count(t->lch) + sol_count(t->rch) + 1;
    t->mini = min(min(sol_mini(t->lch), sol_mini(t->rch)), t->val);
    return t;
}

node_t *merge(node_t *l, node_t * r)
{
    if(!l || !r) return !l ? r : l;
    if(l->pri > r->pri){
        l->rch = merge(l->rch, r);
        return update(l);
    }else{
        r->lch = merge(l, r->lch);
        return update(r);
    }
}

pair<node_t*, node_t*> split(node_t *t, int pos)
{
    if (!t) return mp((node_t*)NULL, (node_t*)NULL);
    if (pos <= sol_count(t->lch)) {
        pair<node_t*, node_t*> s = split(t->lch, pos);
        t->lch = s.second;
        return mp(s.first, update(t));
    } else {
        pair<node_t*, node_t*> s = split(t->rch, pos - sol_count(t->lch) - 1);
        t->rch = s.first;
        return mp(update(t), s.second);
    }
}

node_t *insert(node_t *t, int pos, node_t *n)
{
    pair<node_t*, node_t*> s = split(t, pos - 1);
    return merge(merge(s.first, n), s.second);
}

node_t *remove(node_t *t, int pos)
{
    pair<node_t*, node_t*> s;
    s = split(t, pos - 1);
    return merge(s.first, split(s.second, 1).second);
}

int get(node_t* t, int pos) {
    pair<node_t*, node_t*> s = split(t, pos - 1);
    pair<node_t*, node_t*> u = split(s.second, 1);
    int v = u.first->val;
    t = merge(s.first, merge(u.first, u.second));
    return v;
}