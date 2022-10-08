
#include <lib/number.h>
#include <iostream>

int main() {
    uint2022_t a = from_string("12345678912345678912456789123654789");
    uint2022_t b = from_string("1000000");
    std::cout << a + b;

    return 0;
}
