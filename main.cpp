#include <iostream>
#include "little_framework.h"
#define A(n) foo(n, #n) // # - возвращает стрококое значение переменной
/*заглавными буквами обозначают макросы. Могут быть любыми, которые задас пользователь
 *
 *
 */
void foo(int n, const std::string& NameN){/*передаем по ссылке, пишем const, чтобы показать при определенит, что не будем
    менять переменную. Передача по ссылке быстрее*/
    std::cout << n << " " << NameN << std::endl;
}
// заглавные буквы обозначают макрос
#undef TEST//убирает определение

#ifdef TEST// проверяет есть ли определение если есть, какие-то действия
    std::cout << "stary_test" << endl;
    RUN_TEST();
#endif



//у любого #ifdef должен быть свой #endif. аналог блока. между ними выполняется код,если макрос в #ifde определен
#define TEST
#ifndef TEST //если не определен
    std::cout << "undef";
#endif

void test_test(){
    std::cout << "xz";
}





int main() {


#ifdef TEST
    std::cout << "start Test" << std::endl;
#endif

#ifdef TEST
    std::cout << "ifdef";
#else
    std::cout << "else";
#endif
    //нельзя определелять дерективы препроцессора(штука со #) для проверки кода не в какой-то функции
    std::cout << std::endl;
    foo(1, "Name");
    A(2);

    RUN_TEST(test_test);
    return 0;
}
/*
 * all : main.o
 *
 */