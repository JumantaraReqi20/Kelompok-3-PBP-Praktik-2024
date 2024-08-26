#include <iostream>
#include "header1.h"
#include "header1.h"  // Disertakan dua kali untuk melihat efek tanpa guard

#include "header2.h"
#include "header2.h"  // Disertakan dua kali untuk melihat efek dengan guard

void functionFromHeader1() {
    std::cout << "Function from header1.h" << std::endl;
}

void functionFromHeader2() {
    std::cout << "Function from header2.h" << std::endl;
}

int main() {
    functionFromHeader1();
    functionFromHeader2();
    return 0;
}
