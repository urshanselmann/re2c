// re2c $INPUT -o $OUTPUT -c -i
#include <string>

/*!conditions:re2c*/
#include "essl_strip.h"

void essl_strip(const char *s, std::string &out) {
    const char *YYCURSOR = s, *YYMARKER;
    int c = yycINITIAL;
    /*!re2c
        re2c:api:style = free-form;
        re2c:define:YYCTYPE   = char;
        re2c:define:YYGETCONDITION = "c";
        re2c:define:YYSETCONDITION = "c = @@;";
        re2c:yyfill:enable    = 0;

        Ws          = [ \t\r\n]+;
        OptWs       = [ \t\r\n]*;
        Any         = [\x00-\xFF];
        Qual        = "lowp" | "mediump" | "highp";
        Ident       = [a-zA-Z_][a-zA-Z0-9_]*;

        V300        = "#version" Ws "300" Ws "es";
        V310        = "#version" Ws "310" Ws "es";
        V320        = "#version" Ws "320" Ws "es";
        V100        = "#version" Ws "100";

        <INITIAL> "\x00" { return; }
        <INITIAL> V300    { out.append("#version 330 core\n"); goto yyc_CODE; }
        <INITIAL> V310    { out.append("#version 430 core\n"); goto yyc_CODE; }
        <INITIAL> V320    { out.append("#version 450 core\n"); goto yyc_CODE; }
        <INITIAL> V100    { out.append("#version 100\n"); goto yyc_CODE100; }
        <INITIAL> Any     { out.push_back(*YYCURSOR); }

        <CODE> "\x00" { return; }
        <CODE> "precision" Ws Qual Ws Ident OptWs ";"   { /* drop */ }
        <CODE> Qual Ws                                { /* skip token */ }
        <CODE> Any                                    { out.push_back(*YYCURSOR); }

        <CODE100> "\x00" { return; }
        <CODE100> Any     { out.push_back(*YYCURSOR); }
    */
}
