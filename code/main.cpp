#include <cstdio>

#include <complex>
#include "vem/complex.hpp"

void show_operation(const vem::complex &lhv, const vem::complex &rhv, const char oper) {
    lhv.display();
    std::printf(" %c ", oper);
    rhv.display();
    std::printf(" = ");
}

int main() {
    const vem::complex left_number{ -5.5, 3.8 };
    const vem::complex right_number{ 9.5, -4.6 };

    const vem::complex result{ left_number + right_number };
    show_operation(left_number, right_number, '+');
    result.display();
    std::printf("\n");

    const vem::complex result_diff{ left_number - right_number};
    show_operation(left_number, right_number, '-');
    result_diff.display();
    std::printf("\n");

    const vem::complex result_mul{ left_number * right_number};
    show_operation(left_number, right_number, '*');
    result_mul.display();
    std::printf("\n");

    const vem::complex result_div{ left_number / right_number };
    show_operation(left_number, right_number, '/');
    result_div.display();
    std::printf("\n");
}
