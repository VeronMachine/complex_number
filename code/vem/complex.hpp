#pragma once

namespace vem {

class complex {
public:
    complex(const double real_part, const double imagine_part) noexcept;

    void display() const;

    complex operator+(const complex &other) const noexcept;
    complex operator-(const complex &other) const noexcept;
    complex operator*(const complex &other) const noexcept;
    complex operator/(const complex &other) const noexcept;

private:
    double real{};
    double imaginary{};
};

} // namespace vem
