#include <bit>
#include <iostream>
#include <stdio.h>
#include <stdint.h>

int main() {
    if (std::endian::native == std::endian::big)
        std::cout << "big-endian\n";
    else if (std::endian::native == std::endian::little)
        std::cout << "little-endian\n";
    else
        std::cout << "mixed-endian\n";

    uint16_t x = 0x0001;
    printf("%s-endian\n", *((uint8_t *) &x) ? "little" : "big");
}
