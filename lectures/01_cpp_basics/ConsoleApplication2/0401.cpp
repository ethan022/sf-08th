// ConsoleApplication2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    
    //cout << "Hello World!\n";


    // 선언만 하기
    int number;

    // 선언 후 초기화
    int count;
    count = 20;

    // 선언과 동시에 초기화
    int value = 30; // 할당 초기화
    int score(30); // 직접 초기화

    cout << "score : " << score << endl;

    // 선언만 하기
    float number;

    // 선언 후 초기화
    float count;
    count = 20.2456f;

    float value = 30.2; // 할당 초기화
    float score(30.1); // 직접 초기화
    //소수점 n번째 자리수 출력해주는 
    cout.precision(10);
    cout << "count : " << count << endl;


    // 불리언 자료형
    bool isDog = false;
    bool isCat = true;

    cout << "isDog : " << isDog << "\n isCat : " <<  isCat << endl;

    // 문자 자료형
    char a = 'a';
    char b = 'c';
    cout << "a b : " << a << b << endl;

    string str1 = "문자열 입니다.";
    string str2 = "오류가 날까요?";
    cout << "str1 + str2은 : " << str1 + str2 << endl;

    int test1;
    string test2;

    cin >> test1;
    cin >> test2;
    cout << test1 << test2 << endl;

    string user_name;
    cout << "이름을 입력하세요." << endl;;
    cin >> user_name;

    string user_age;
    cout << "나이를 입력하세요." << endl;;
    cin >> user_age;

    cout << "안녕하세요!" << user_name << "님(" << user_age << "세)" << endl;

    // 산술 연산자
    int a = 10, b = 3;
    int sum = a + b; // 13
    int differnce = a - b; // 7
    int product = a * b; // 30
    int quotient = a / b; // 정수 나눗셈 3
    int remainder = a % b; // 1

    // 실수 나눗셈
    double result = static_cast<double>(a) / b; // 3.3333

    // 증감 연산자
    int x = 5;
    x++; // 후위 증가: x = 6
    x--; // 후위 감소: x = 5 
    ++x; // 전위 증가: x = 6
    --x; // 전위 감소: x = 5

    int a = 5, b = 5;
    int resultA = ++a; // 전위 증가
    cout << "resultA : " << resultA << endl;
    int resultB = b++; // 후위 증가
    cout << "resultB : " << resultB << endl;

    // 비교 연산자
    int x = 10, y = 20;
    bool isEqual = (x == y); // false
    bool isNotEqual = (x != y); // true
    bool isGreater = (x > y); // false
    bool isLess = (x < y); // true
    bool isGreaterOrEqual = (x >= y); //false
    bool isLessOrEqual = (x <= y); // true

    // 논리 연산자
    bool condition1 = true, condition2 = false;
    bool andResult = condition1 && condition2; // false
    bool orResult = condition1 || condition2; // true
    bool notResult = !condition1; // false

    // 복합 논리 연산자
    bool complexLogic = (x > 5 && y < 30) || (x == y); // true
    cout << "complexLogic : " << complexLogic;


    // 비트 연산자
    int FLAG_A = 1; // 0001
    int FLAG_B = 2; // 0010

    int flags = 0; // 0000

    flags = flags | FLAG_A; //    0001
    //      0001
    // or   0000
    //      0001

    flags = flags | FLAG_B; //    0011
    //      0001
    // or   0010
    //      0011

    flags = flags & ~FLAG_A; // 0011 & 1110 = 0010
    //      0011
    //      1110
    //      0010

    unsigned char num = 0b00010010;
    //       00010010
    // or    00100000
    //       00110010
    // 다섯번째 비트를 1로 설정
    num = num | (1 << 5);

    cout << "결과 : " << (int)num << endl;
    cout << "결과 : " << bitset<8>((int)num) << endl;

    // 비트 플래그 확인
    if (flags & FLAG_A) {
        cout << "FLAG_A가 설정되어 있습니다." << endl;
    }
    
    // 비트 플래그 확인
    if (flags & FLAG_B) {
        cout << "FLAG_B가 설정되어 있습니다." << endl;
    }

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
