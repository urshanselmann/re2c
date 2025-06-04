#include <iostream>
#include <string>
#include <cstring>
#include "essl_strip.h"

int main() {
    const char *shader =
        "#version 310 es\n"
        "precision mediump float;\n"
        "mediump vec4 color;\n";

    size_t len = std::strlen(shader);
    std::string buf(shader, len);
    buf.append(YYMAXFILL + 1, '\0');

    std::string out;
    essl_strip(buf.c_str(), out);
    std::cout << out;
    return 0;
}
