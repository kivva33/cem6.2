#define _test_h_
#ifdef _test_h_

#include <iostream>

template<typename T>
void run_test(T& func, const std::string& nameFunc){
    std::cout << __func__ << std::endl;
    std::cout << "------\n" << "start test\n";
    std::cout << "---\n";

    func();
}

#define RUN_TEST(func) run_test(func, #func)

//void run_test(void (*test)(), const std::string& nameFunc){}

template<typename T>
void assert_equal(T expr, T& expr_true,
                  const std::string& exprString,
                  const std:: string exprTrueString,
                  int numTest)
{
    static int currentTest = 0;
    //что-то, что лучше взять с ГитХаб
    std::cout << "\ttest" << numTest;

#ifdef TEST_FULL_INFO
    std::cout << exprString << " == " << , exprTrueString << " ";
#endif
    if(expr == expr_true){
        std::cout << "RASSED";
        return;
    }
    std::cout<< "BAD";
}

#endif