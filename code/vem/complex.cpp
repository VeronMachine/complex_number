#include <cstdio>

#include "vem/complex.hpp"

namespace vem {

complex::complex(const double real_part, const double imagine_part) noexcept
    : real{ real_part }, imaginary{ imagine_part }
{}

void complex::display() const {
    if(imaginary < 0) {
        std::printf("(%.2f%.2fi)", real, imaginary);
    } else {
        std::printf("(%.2f+%.2fi)", real, imaginary);
    }
}

complex complex::operator+(const complex &other) const noexcept {
    return complex{ real + other.real, imaginary + other.imaginary };
}

complex complex::operator-(const complex &other) const noexcept {
    return complex{ real - other.real, imaginary - other.imaginary };
}

complex complex::operator*(const complex &other) const noexcept {
    return complex{
        real * other.real - imaginary * other.imaginary,
        real * other.imaginary + imaginary * other.real
    };
}

complex complex::operator/(const complex &other) const noexcept {
    const double denominator{ 1.0 / (other.real * other.real + other.imaginary * other.imaginary) };
    return complex{
        (real * other.real + imaginary * other.imaginary) * denominator,
        (real * other.imaginary - imaginary * other.real) * denominator
    };
}

} // nemaspace vem
