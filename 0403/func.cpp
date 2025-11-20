#include  <iostream>
#include "func.h"

using namespace std;


// 전역 변수
int globalVar2 = 100;

// 피보나치 수열
int fibonacci(int n) {
    if (n <= 0) return 0;
    else if (n == 1) return 1;
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

// 전역 변수 호출
void func3() {
    // 0403.cpp의 static 전역 변수 호출 불가능
    // cout << "globalVar : " << globalVar << endl;
    
    // 전역 변수 호출
    cout << "func.cpp === globalVar2 : " << globalVar2 << endl;
}