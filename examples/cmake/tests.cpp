#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "essl_strip.h"
#include <string>
#include <cstring>

DOCTEST_TEST_CASE(test_strip_310) {
    const char *shader = "#version 310 es\nprecision mediump float;\nmediump vec4 color;";
    size_t len = std::strlen(shader);
    std::string buf(shader, len);
    buf.append(YYMAXFILL + 1, '\0');
    std::string out;
    essl_strip(buf.c_str(), out);
    DOCTEST_CHECK(out == "#version 430 core\nvec4 color;");
}

DOCTEST_TEST_CASE(test_strip_100) {
    const char *shader = "#version 100\nprecision mediump float;\nmediump vec4 color;";
    size_t len = std::strlen(shader);
    std::string buf(shader, len);
    buf.append(YYMAXFILL + 1, '\0');
    std::string out;
    essl_strip(buf.c_str(), out);
    DOCTEST_CHECK(out == "#version 100\n\nprecision mediump float;\nmediump vec4 color;");
}
