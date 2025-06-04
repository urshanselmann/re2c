#ifndef DOCTEST_H
#define DOCTEST_H
#include <vector>
#include <functional>
#include <stdexcept>
#include <iostream>

struct doctest_test {
    const char* name;
    void (*func)();
};
inline std::vector<doctest_test>& doctest_tests(){ static std::vector<doctest_test> v; return v; }
struct doctest_reg { doctest_reg(const char* n, void(*f)()){ doctest_tests().push_back({n,f}); } };
#define DOCTEST_TEST_CASE(name) \
    static void name(); \
    static doctest_reg reg_##name(#name,&name); \
    static void name()

#define DOCTEST_CHECK(expr) do{ if(!(expr)) { std::cerr<<"check failed: "<<#expr<<"\n"; throw std::runtime_error("check failed"); } }while(0)

#ifdef DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
int main(){
    for(auto& t: doctest_tests()){
        try{ t.func(); }
        catch(const std::exception& e){ std::cerr<<"Test "<<t.name<<" failed: "<<e.what()<<"\n"; return 1; }
    }
    return 0;
}
#endif
#endif // DOCTEST_H
