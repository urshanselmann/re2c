#include <iostream>
#include <string>
#include "essl_strip.h"

int main() {
    const char *shader =
        "#version 310 es\n"
        "precision mediump float;\n"
        "mediump vec4 color;\n";

    std::string out;
    essl_strip(shader, out);
    std::cout << out;
    return 0;
}
