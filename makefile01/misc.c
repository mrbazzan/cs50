#include <stdio.h>#define PI 3.142#define HE HI#define LLO _THERE#define HELLO "HI THERE"#define CAT(a, b) a##b#define XCAT(a, b) CAT(a, b)#define CALL(fn) fn(HE, LLO)#define f(a, b) a##b#define g(a) #a#define h(a) g(a)#define WHERESTR "[file %s, line %d]: "#define DATETIME __DATE__, __TIME__#define WHEREARG __FILE__, __LINE__#define DEBUGPRINT2(...) fprintf(stderr, __VA_ARGS__)#line 200 "Makefile"  // Manipulate the definition in __LINE__ and __FILE__#define DEBUGPRINT(_fmt, ...) fprintf(stderr, "[file %s, line %d]: "_fmt, __FILE__, __LINE__, __VA_ARGS__)int main(void){    /** object-like and function-like Macros  **/    printf("%f\n", PI);    printf("%s\n", CAT(HE, LLO));    printf("%s\n", CALL(CAT));    #ifdef HI_THERE    printf("%s\n", XCAT(HE, LLO));    printf("%s\n", CALL(XCAT));    #endif    printf("%s\n", h(f(1, 2)));    printf("%s\n", g(f(1, 2)));    printf("%s\n", g(p = "foo\n"));    printf("%s\n", __func__);  // Returns `main`    /** special directive Macros  **///    printf(WHERESTR, WHEREARG);//    printf("\n%s: %s\n", DATETIME);//    DEBUGPRINT2(WHERESTR "%s %d\n");    DEBUGPRINT("hey, x=%d\n", __STDC__);}