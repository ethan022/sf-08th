// 0403.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

// 더하기 함수
int add(int a, int b) {
    int sum = a + b;
    return sum;
}
// 빼기 함수
int subtract(int a, int b) {
    return a - b;
}

// 곱하기 함수
int multiply(int x, int y) {
    return x * y;
}

// 나누기 함수
double divide(int a, int b) {
    return static_cast<double>(a) / b;
}

// 홀짝 판별기
void checkOddEven(int num) {
    if (num % 2 == 0) {
        cout << "짝수입니다." << endl;
    }
    else {
        cout << "홀수입니다." << endl;
    }
}

// 최대값 찾기
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

// 팩토리얼 계산
int factorial(int n) {
    // 기본 조건 (base case)
    if (n <= 1) {
        return 1;
    }
    // 재귀 함수 호출
    return n * factorial(n - 1);
}

// 피보나치 수열
int fibonacci(int n) {
    // 기본 조건 (base case)
    if (n <= 1) {
        return n;
    }
    // 재귀 함수 호출
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 거듭 제곱
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    return base * power(base, exponent - 1);
}

int main()
{
    // 더하기 함수 호출
    int result1 = add(10, 20);
    cout << "10 + 20 = " << result1 << endl;

    // 빼기 함수 호출
    int result2 = subtract(10, 20);
    cout << "10 - 20 = " << result2 << endl;

    // 곱하기 함수 호출
    int result3 = multiply(4, 5);
    cout << "4 * 5 = " << result3 << endl;

    // 나누기 함수 호출
    double result4 = divide(10, 3);
    cout << "10 / 3 = " << result4 << endl;

    // 홀짝 판별기
    int num;
    cout << "숫자를 입력하세요 : ";
    cin >> num;
    checkOddEven(num);

    // 최대값 찾기
    int maxNum = findMax(10, 20, 30);
    cout << "최대값 : " << maxNum << endl;

    // 팩토리얼 계산
    int n;
    cout << "정수를 입력하세요 : ";
    cin >> n;
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    // 반복문 호출
    cout << n << "! = " << result << endl;
    // 재귀함수 호출
    cout << "재귀함수 값 : " << n << "! = " << factorial(n) << endl;


    // 피보나치 수열
    int fibo;
    cout << "피보나치 수열을 입력하세요 : ";
    cin >> fibo;

    // 피보나치 수열 호출 (반복문)
    int fibo1 = 0, fibo2 = 1;
    for (int i = 2; i <= fibo; i++) {
        int next = fibo1 + fibo2;
        fibo1 = fibo2;
        fibo2 = next;
    }
    cout << "피보나치 수열 : " << fibo2 << endl;

    // 피보나치 수열 호출 (재귀 함수)
    cout << "피보나치 수열 : " << fibonacci(fibo) << endl;

    //거듭 제곱
    int base, exponent;
    cout << "밑과 지수를 입력하세요 : ";
    cin >> base >> exponent;

    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    cout << "거듭 제곱 : " << result << endl;

    // 재귀 함수 호출
    cout << "재귀 함수 거듭 제곱 : " << power(base, exponent) << endl;
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
