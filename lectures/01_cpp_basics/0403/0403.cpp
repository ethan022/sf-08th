// 0403.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "func.h"

using namespace std;

static int globalVar = 10;

// 더하기 함수
int add(int a, int b) {
    int sum = a + b;
    return sum;
}

// 빼기 함수
int sub(int a, int b) {
    if (a > b) {
        return a - b;
    }
    else {
        return b - a;
    }
}

// 곱하기 함수
int mul(int x, int y) {
    return x * y;
}

// 나누기 함수
double divi(int x, int y) {
    return static_cast<double>(x) / y;
}

// int 반환 함수 
int getAge() {
    return 25;
}

// double 반환 함수
double getPI() {
    return 3.1415926;
}

// char 반환 함수
char getGrade() {
    return 'A';
}

// bool 반환 함수
bool isValid() {
    return true;
}

// void 반환 함수
void printMessage() {
    cout << "message" << endl;
    // return 문 필요 없다!!!!
}

// 홀짝 판별기
void checkOddEven(int num) {
    if (num % 2) {
        cout << "홀수 입니다." << endl;
    }
    else {
        cout << "짝수 입니다." << endl;
    }
}

int findMax(int a, int b, int c) {
    if (a > b && a > c) {
        return a;
    }
    else if (b > a && b > c) {
        return b;
    }
    else {
        return c;
    }
}


void recursiveFunction(int n) {
    // 기본 조건 (base case)
    if (n == 0) return;

    cout << "재귀 함수 호출 : " << n << endl;
    recursiveFunction(n - 1);
    cout << "재귀 함수 반환 : " << n << endl;
}

int factorial(int n) {

    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}
// 5 * factorial(4)
// 5 * 4 * 3 * 2 * 1



int power(int a, int b) {
    if (b == 0) return 1;
    return a * power(a, b - 1);
}

void func1() {
    // 정적 변수
    // 초기화 되지 않은 정적 변수는 0으로 초기화 된다.
    // 정적 변수는 프로그램 전체에서 사용 가능하다.
    static int count = 0;
    count++;
    cout << "count : " << count << endl;
    cout << "globalVar : " << globalVar << endl;
    // 전역 변수
    // 전역 변수는 프로그램 전체에서 사용 가능하다.
    // 전역 변수는 메모리에 저장되어 있어 프로그램 종료 전까지 유지된다.
    globalVar++;
    cout << "0403.cpp ==== globalVar : " << globalVar << endl;
}

int main()
{

    // 분할 구현
    func1();
    func1();
    func1();

    // 전역 변수 호출
    func3();
    


    // 더하기 함수 호출
    //int result1 = add(10, 20);
    //cout << "10 + 20 = " << result1 << endl;

    //// 빼기 함수 호출
    //int result2 = sub(10, 20);
    //cout << "20 - 10 = " << result2 << endl;

    //// 곱하기 함수 호출
    // int result3 = mul(4, 5);
    //cout << "4 * 5 = " << result3 << endl;

    //// 나누기 함수 호출
    //double result4 = divi(10, 4);
    //cout << "10 / 4 = " << result4 << endl;

    //int num;
    //cout << "숫자를 입력하세요 : ";
    //cin >> num;
    //checkOddEven(num);


    //cout << findMax(29, 14, 16) << endl;

    //recursiveFunction(5);

    //int n;
    //cout << "정수를 입력하세요 : ";
    //cin >> n;

    //int result = 1;
    //// 팩토리얼
    //for (int i = 1; i <= n; i++) {
    //    result *= i;
    //}
    //
    //cout << n << "! = " << result << endl;

    //cout << "재귀함수 값 : " << factorial(n) << endl;
    //return 0;

 /*   int n;
    cout << "피보나치 수열의 항 개수를 입력하세요 : ";
    cin >> n;

    if (n <= 0) {
        cout << "0 이하의 수가 입력 되어 0을 리턴합니다." << endl;
    }

    int a = 0, b = 1;
    int next;
    cout << "피보나치 수열 반복문 : " ;

    for (int i = 0; i < n; i++) {
        if (i == 0) next = 0;
        else if (i == 1) next = 1;
        else {
            next = a + b;
            a = b;
            b = next;
        }
        cout << next << " ";
    }
    cout << endl;

    cout << "피보나치 수열 (재귀 함수) : ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }*/

    //int a, b;
    //cout << "정수 두개를 입력 하세요. : ";
    //cin >> a >> b;

    //// 반복문
    //int result = 1;
    //for (int i = 0; i < b; i++) {
    //    result *= a;
    //}
    //// 재귀 함수
    ////int result = power(a, b);
    //cout << a << "의 " << b << "제곱은 " << result << "입니다." << endl;

}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
