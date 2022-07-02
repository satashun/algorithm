long long maximum_rectangle(const std::vector<int> &h)
{
    int n = h.size();
    stack<int> s;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        while (s.size() && h[s.top()] >= h[i]) s.pop();
        L[i] = s.size() ? (s.top() + 1) : 0;
        s.push(i);
    }
    while (s.size()) s.pop();
    for (int i = n - 1; i >= 0; i--) {
        while (s.size() > 0 && h[s.top()] >= h[i]) s.pop();
        R[i] = s.size() ? s.top() : n;
        s.push(i);
    }
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, (long long)h[i] * (R[i] - L[i]));
    }
    return res;
}