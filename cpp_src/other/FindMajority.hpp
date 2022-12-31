// ABC272G
// need to check if it is actually majority
template <class T>
T find_majority(const V<T>& a) {
    T x = a[0];
    int c = 0;
    for (int i = 0; i < SZ(a); ++i) {
        if (c == 0) {
            x = a[i];
            c = 1;
        } else if (a[i] == x)
            c++;
        else
            c--;
    }
    return x;
}