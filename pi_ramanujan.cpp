#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/math/constants/constants.hpp>

int main()
{
    boost::multiprecision::cpp_dec_float_50 pi_ram = 0;

    for (int k = 0; k < 10; ++k) {
        boost::multiprecision::cpp_dec_float_50 num = boost::multiprecision::factorial(4 * k) * (1103 + 26390 * k);
        boost::multiprecision::cpp_dec_float_50 den = boost::multiprecision::pow(boost::multiprecision::factorial(k), 4) * boost::multiprecision::pow(396, 4 * k);
        pi_ram += num / den;
    }

    pi_ram *= boost::multiprecision::cpp_dec_float_50(2) * boost::multiprecision::sqrt(boost::multiprecision::cpp_dec_float_50(2)) / 9801;

    pi_ram = 1 / pi_ram;


    boost::multiprecision::cpp_dec_float_50 pi_boost = boost::math::constants::pi<boost::multiprecision::cpp_dec_float_50>();

    std::cout << "Computed value of π using Ramanujan's formula: " << pi_ram.str(50) << std::endl;
    std::cout << "Value of π from the boost library: " << pi_boost.str(50) << std::endl;

    return 0;
}
