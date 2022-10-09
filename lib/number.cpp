#include "number.h"
#include <cmath>


uint2022_t from_uint(uint32_t i) {
    uint2022_t digits;

    digits.number[0] = i % 1000000000;
    digits.number[1] = i / 1000000000;
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

    if (length == 1 && buff[0] == '0') {
        digits.number[0] = 0;
    }

    else {

        int step = length;
        int j = 0;

        if (lengthMas > 1) {
            for (i = 0; i < lengthMas; i++) {
                while (j < 9) {
                    digits.number[i] = digits.number[i] + (buff[step - 1] - '0') * pow(10, j);
                    j++;
                    step--;
                    if (step == 0) return digits;
                }
                j = 0;
            }
        } else {
            j = length;
            step = 0;
            while (j != 0) {
                digits.number[lengthMas - 1] = digits.number[lengthMas - 1] + (buff[step] - '0') * pow(10, j - 1);
                j--;
                step++;
            }
        }
    }
    return digits;
}


uint2022_t operator+(const uint2022_t& lhs, const uint2022_t& rhs) {
    int i;
    int digitsEnd_lhs;
    int digitsEnd_rhs;
    uint2022_t rezult;
    for (i = 1; i < 68; i++) {
        if (lhs.number[i] == 0 && lhs.number[i - 1] != 0) {
            digitsEnd_lhs = i - 1; // i
            rezult = lhs;
        }
        if (rhs.number[i] == 0 && rhs.number[i - 1] != 0) {
            digitsEnd_rhs = i - 1; // i
            rezult = rhs;
        }
    }


    int length;
    int moreThanNine = 0;
    if (digitsEnd_lhs > digitsEnd_rhs)
        length = digitsEnd_lhs; // +1
    else
        length = digitsEnd_rhs; // +1
    for (i = length; i >= 0; i--) {
        rezult.number[i] += moreThanNine;
        if ((lhs.number[i] + rhs.number[i] + moreThanNine) >= 1000000000) {
            rezult.number[i] = (lhs.number[i] + rhs.number[i]) - 1000000000;
            moreThanNine = 1;
        }
        else {
            rezult.number[i] = lhs.number[i] + rhs.number[i];
            moreThanNine = 0;
        }
        rezult.number[i + 1] += moreThanNine;
    }
    return rezult;
}


uint2022_t operator-(const uint2022_t& lhs, const uint2022_t& rhs) {

    uint2022_t rezult;

    rezult = lhs;
    int i;
    int digitsEnd_lhs;
    int digitsEnd_rhs;
    bool flag = true;

    for (i = 0; i < 68; i++) {
        if (lhs.number[i] != rhs.number[i]) {
            flag = false;
        }
    }

    for (i = 1; i < 68; i++) {
        if (rhs.number[i] == 0 && rhs.number[i - 1] != 0) {
            digitsEnd_rhs = i - 1;
//            rezult = rhs;
        }
    }

    rezult = lhs;

    int length = digitsEnd_rhs;

    int lessThenZero = 0;
    for (i = length; i >= 0; i--) {
        if (lhs.number[i] < rhs.number[i]) {
//            lessThenZero = 1;
            rezult.number[i + 1] -= 1;
            rezult.number[i] = (lhs.number[i] - rhs.number[i]) + 1000000000;
        }
        else rezult.number[i] = lhs.number[i] - rhs.number[i];
    }
    return rezult;
}


uint2022_t operator*(const uint2022_t& lhs, const uint2022_t& rhs) {
    uint2022_t rezult;

    int i;
    int digitsEnd_lhs;
    int digitsEnd_rhs;

    return rezult;
}

uint2022_t operator/(const uint2022_t& lhs, const uint2022_t& rhs) {
    return uint2022_t();
}

bool operator==(const uint2022_t& lhs, const uint2022_t& rhs) {
    bool flag = true;

    for (int i = 0; i < 68; i++) {
        if (lhs.number[i] != rhs.number[i]) {
            flag = false;
        }
    }

    if (flag) return true;
    else return false;
}

bool operator!=(const uint2022_t& lhs, const uint2022_t& rhs) {
    bool flag = true;
    int digitsEnd = 0;

    for (int i = 0; i < 68; i++) {
        if (lhs.number[i] == 0 && lhs.number[i - 1] != 0) {
            digitsEnd = i - 1;
        }
    }

    for (int i = 0; i < digitsEnd; i++) {
        if (lhs.number[i] == rhs.number[i]) {
            flag = false;
            break;
        }
    }

    if (flag) return true;
    else return false;
}

std::ostream& operator<<(std::ostream& stream, const uint2022_t& value) {
    int digitsEnd;
    int i;
    int j;
    for (i = 1; i < 68; i++) {
        if (value.number[i] == 0 & value.number[i - 1] != 0) {
            digitsEnd = i;
        }
    }
    if (value.number[67] != 0){
        digitsEnd = 67;
    }

    int countDigits;
    int subNumber;
    for (i = digitsEnd; i > 0; i--) {
        countDigits = 0;
        subNumber=value.number[i - 1];
        if (value.number[i - 1] == 0) {
            stream << "000000000";
        }

        else if (i == digitsEnd) {
            stream << value.number[i-1];
        }

        else if (value.number[i - 1] < 100000000 && i != digitsEnd) {
            while(subNumber != 0){
                countDigits++;
                subNumber= subNumber / 10;
            }
            int countLeftZero = 9 - countDigits;

            for(j = 0; j < countLeftZero; j++){
                stream << "0";
            }
            stream << value.number[i-1];
        }

        else {
            stream << value.number[i-1];
        }
    }

    if (digitsEnd == 0) stream << "0";

    return stream;
}