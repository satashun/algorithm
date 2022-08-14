template <class T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}

// a / b
template <class T>
struct Fraction {
    T a, b;
    Fraction(T _a = 0) : a(_a), b(1) {}
    Fraction(T _a, T _b) {
        if (_b < 0) {
            _a *= -1;
            _b *= -1;
        }
        T g = gcd(abs(_a), abs(_b));
        a = _a / g;
        b = _b / g;
    }

    using F = Fraction;

    F operator-() const {
        F f;
        f.a = -a;
        f.b = b;
        return f;
    }

    F operator+(const F& r) const { return {r.b * a + b * r.a, b * r.b}; }
    F operator-(const F& r) const { return *this + (-r); }
    F operator*(const F& r) const { return {a * r.a, b * r.b}; }
    F operator/(const F& r) const { return {a * r.b, b * r.a}; }
    F& operator+=(const F& r) { return *this = *this + r; }
    F& operator-=(const F& r) { return *this = *this - r; }
    F& operator*=(const F& r) { return *this = *this * r; }
    F& operator/=(const F& r) { return *this = *this / r; }
    bool operator<(const F& r) const { return a * r.b < b * r.a; }
    bool operator>(const F& r) const { return r < *this; }
    bool operator<=(const F& r) const { return !(r < *this); }
    bool operator>=(const F& r) const { return !(*this < r); }
    bool operator==(const F& r) const { return !(*this < r) && !(r < *this); }
    bool operator!=(const F& r) const { return !(*this == r); }
    friend ostream& operator<<(ostream& os, const F& v) {
        return os << v.a << '/' << v.b;
    }
};