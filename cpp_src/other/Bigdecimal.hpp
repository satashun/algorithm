// docs : https://boostjp.github.io/tips/multiprec-float.html
// -I /usr/local/include/

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

using Bint = mp::cpp_int;
using Real = mp::number<mp::cpp_dec_float<30>>;

string to_string(__int128_t x) {
    if (x == 0) return "0";
    string result;
    if (x < 0) {
        result += "-";
        x *= -1;
    }
    string t;
    while (x) {
        t.push_back('0' + x % 10);
        x /= 10;
    }
    reverse(t.begin(), t.end());
    return result + t;
}

ostream& operator<<(ostream& o, __int128_t x) { return o << to_string(x); }