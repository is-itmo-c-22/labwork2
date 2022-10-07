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
    long int length = 0;
    int chislo;

//    while (buff[i] != '\0') {
//        i++;
//        length++;
//    }


    std::string number_string = buff;

    number_string.erase(0, std::min(number_string.find_first_not_of('0'), number_string.size()-1));

    if (number_string.size() < 9) {
        digits.number[0] = std::stoi(number_string.substr(0, number_string.size()));
    }

    else if (number_string.size() >= 9) {
        length = number_string.size();

        int count = (length - 1) / 9;

        int step = 9;
        int start;

        for (i = length; i > 0; i -= 9) {
            start = i - 9;
            if (i - 9 < 0) {
                step = 9 - i - 1;
                start = 0;
            }
            digits.number[count] = std::stoi(number_string.substr(start, step));
            count--;
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
    stream << "Implement me";
    int i;

    for (i = 0; i < 68; i++) {
        if (value.number[i]) {
            stream << value.number[i];
        }
    }

    return stream;
}
