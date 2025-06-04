#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "essl_strip.h"
#include <string>

DOCTEST_TEST_CASE(test_strip_310) {
    const char *shader = "#version 310 es\nprecision mediump float;\nmediump vec4 color;";
    std::string out;
    essl_strip(shader, out);
    DOCTEST_CHECK(out == "#version 430 core\nvec4 color;");
}

DOCTEST_TEST_CASE(test_strip_100) {
    const char *shader = "#version 100\nprecision mediump float;\nmediump vec4 color;";
    std::string out;
    essl_strip(shader, out);
    DOCTEST_CHECK(out == "#version 100\nprecision mediump float;\nmediump vec4 color;");
}
