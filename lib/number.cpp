#include "number.h"
#include <cmath>


uint2022_t from_uint(uint32_t i) {
    uint2022_t digits;
    digits.number[67] = i;
    return digits;
}


uint2022_t from_string(const char* buff) {
    uint2022_t digits;
    int i = 0;
    int length = 0;
    int lengthMas = 1;

    while (buff[i] != '\0') {
        i++;
        length++;
        if ((length - 1) % 9 == 0 && length > 1) {
            lengthMas++;
        }
    }

    int step = length;
    int j = 0;

    if (lengthMas > 1) {
        for (i = 0; i < lengthMas; i++) {
            while (j < 9) {
                digits.number[i] = digits.number[i] + (buff[step - 1]-'0') * pow(10, j);
                j++;
                step--;
                if (step == 0) return digits;
            }
            j = 0;
        }
    }
    else {
        j = length;
        step = 0;
        while (j != 0) {
            digits.number[lengthMas - 1] = digits.number[lengthMas - 1] + (buff[step] - '0') * pow(10, j - 1);
            j--;
            step++;
        }
    }
    return digits;
}


uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    return false;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    return false;
}

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    int i;

    for (i = 0; i < 68; i++) {
        if (value.number[i]) {
            stream << value.number[i];
        }
    }

    return stream;
}