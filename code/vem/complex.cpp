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

complex &complex::operator+=(const complex &other) noexcept {
    real += other.real;
    imaginary += other.imaginary;
    return *this;
}

complex &complex::operator-=(const complex &other) noexcept {
    real -= other.real;
    imaginary -= other.imaginary;
    return *this;
}

complex &complex::operator*=(const complex &other) noexcept {
    real = real * other.real - imaginary * other.imaginary;
    imaginary = real * other.imaginary + imaginary * other.real;
    return *this;
}

complex &complex::operator/=(const complex &other) noexcept {
    const double denominator{ 1.0 / (other.real * other.real + other.imaginary * other.imaginary) };
    real = (real * other.real + imaginary * other.imaginary) * denominator;
    imaginary = (real * other.imaginary - imaginary * other.real) * denominator;
    return *this;
}

complex complex::operator+(const complex &other) const noexcept {
    return complex{ *this } += other;
}

complex complex::operator-(const complex &other) const noexcept {
    return complex{ *this } -= other;
}

complex complex::operator*(const complex &other) const noexcept {
    return complex{ *this } *= other;
}

complex complex::operator/(const complex &other) const noexcept {
    return complex{ *this } /= other;
}

bool complex::operator==(const complex &other) const noexcept {
    return real == other.real && imaginary == other.imaginary;
}

} // nemaspace vem
