// docs : https://boostjp.github.io/tips/multiprec-float.html
// -I /usr/local/include/

#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

using Bint = mp::cpp_int;
using Real = mp::number<mp::cpp_dec_float<30>>;
