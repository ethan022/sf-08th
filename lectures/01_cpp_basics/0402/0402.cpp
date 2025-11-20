// 0402.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    // 비트 연산자 실습
    // 실습 1
    unsigned char num1 = 0b00010010;
    num1 = num1 | (1 << 5);

    cout << "10진수 : " << int(num1) << endl;
    cout << "2진수 : " << bitset<8>(int(num1)) << endl;

    // 실습 2
    unsigned char num2 = 0b10101111;
    num2 = num2 & ~(1 << 2);
    //  0b10101111
    //& 0b11111011 => 00000100
    //  0b10101011

    cout << "10진수 : " << int(num2) << endl;
    cout << "2진수 : " << bitset<8>(int(num2)) << endl;

    // 실습 3
    unsigned char num3 = 0b11011010;
    num3 = num3 ^ (1 << 4);
    //  0b11011010
    //  0b00010000
    //  0b11001010

    cout << "10진수 : " << int(num3) << endl;
    cout << "2진수 : " << bitset<8>(int(num3)) << endl;

    // 실습 4.
    unsigned char num4 = 0b11011010; // 예시 임의
    //      0b11011010
    //      (num4 >> 4)
    // =>   0b00001101
    // &    0b00000001
    //      0b00000001
    unsigned char bit_4 = (num4 >> 4) & 1;

    cout << "10진수 : " << int(bit_4) << endl;
    cout << "2진수 : " << bitset<8>(int(bit_4)) << endl;

    unsigned int number;

    cout << "숫자를 입력하세요 : " << endl;
    cin >> number;

    if (number & 1) {
        cout << number << "는 홀수 입니다." << endl;
    }
    else {
        cout << number << "는 짝수 입니다." << endl;
    }

    // 2의 거듭 제곱은 
    // 오직 한 비트만 1이고 나머지는 0이기 때문에 
    // 비트 연산자를 사용하여 확인할 수 있습니다.

    // 2^0 = 1
    // 2^1 = 2
    // 2^2 = 4
    // 2^3 = 8

    //  00001000
    //  00010000

    //  00100000 - 1
    //& 00011111
    //  00000000

    //  00101010 - 1
    //& 00101001
    //  00101000

    unsigned char num7;
    cout << "숫자를 입력해 주세요 : ";
    cin >> num7;
    num7 = num7 & (num7 - 1);
    if (num7 == 0) {
        cout << "거듭 제곱 입니다.";
    }
    else {
        cout << "거듭 제곱이 아닙니다.";
    }

    // if 문
    int num = 10;

    if (num > 0) {
        cout << "양수 입니다." << endl;
    }
    else {
        cout << "음수 입니다." << endl;
    }

    int score = 90;

    if (score >= 90) {
        if (score >= 95) {
            cout << "+";
        }
        cout << "A 학점 입니다." << endl;
    }
    else if (score >= 80) {
        if (score >= 85) {
            cout << "+";
        }
        cout << "B 학점 입니다." << endl;
    }
    else if (score >= 70) {
        cout << "C 학점 입니다." << endl;
    }
    else if (score >= 60) {
        cout << "D 학점 입니다." << endl;
    }
    else {
        cout << "F 학점 입니다." << endl;
    }


    // 삼항 연산자
    int a = 40;
    int b = 20;

    int maxValue = a > b ? a : b;
    cout << "maxValue : " << maxValue << endl;

    // switch 문
    int day = 31;

    switch (day % 5 + 1)
    {
    case 1:
        cout << "월요일 입니다." << endl;
        break;
    case 2:
        cout << "화요일 입니다." << endl;
        break;
    case 3:
        cout << "수요일 입니다." << endl;
        break;
    case 4:
        cout << "목요일 입니다." << endl;
        break;
    case 5:
        cout << "금요일 입니다." << endl;
        break;
    default:
        cout << "알 수 없습니다." << endl;
        break;
    }

    // 실습 1
    int age;

    cout << "나이를 입력하세요.";
    cin >> age;

    if (1 <= age && age <= 7) {
        cout << "유아" << endl;
    }
    else if (8 <= age && age <= 13) {
        cout << "초등학생" << endl;
    }
    else if (14 <= age && age <= 16) {
        cout << "중학생" << endl;
    }
    else if (17 <= age && age <= 19) {
        cout << "고등학생" << endl;
    }
    else if (20 <= age && age < 200) {
        cout << "성인" << endl;
    }
    else if (200 <= age) {
        cout << "나이가 너무 많습니다." << endl;
    }
    else {
        cout << "잘못 입력 하셨습니다." << endl;
    }


    // 실습 2.
    string name;

    cout << "이름을 입력하세요. :";
    cin >> name;

    if (name == "홍길동") {
        cout << "남자" << endl;
    }
    else if (name == "성춘향") {
        cout << "여자" << endl;
    }
    else {
        cout << "모르겠어요" << endl;
    }

    // 실습 3
    int num10;
    cout << "숫자를 입력해주세요. : ";
    cin >> num10;

    if (num10 % 5) {
        cout << num10 << "는 5의 배수가 아니네요 ㅜㅜ" << endl;
    }
    else {
        cout << num10 << "는 5의 배수 입니다." << endl;
    }

    int x, y;
    cout << "연산할 정수 두 개를 입력해 주세요. :";
    cin >> x >> y;
    char cal;
    cout << "연산자를 입력해주세요. :";
    cin >> cal;

    cout << "***** 연산결과 --->";

    switch (cal)
    {
    case '+':
        cout << "더하기 : " << x + y << "입니다." << endl;
        break;
    case '-':
        cout << "빼기 : " << x - y << "입니다." << endl;
        break;
    case '*':
        cout << "곱하기 : " << x * y << "입니다." << endl;
        break;
    case '/':
        cout << "몫 : " << x / y << " 나머지 : " << x % y << "입니다." << endl;
        break;
    default:
        cout << "잘못 입력 하셨습니다." << endl;
        break;
    }


    // 반복문 
    // for 문
    //for(초기화; 조건식; 증감식) {
        //반복 실행되는 코드     
    //}

    for (int i = 0; i < 5; i++) {
        cout << i << endl;
    }

    int j = 0;
    for (; j < 10; ) {
        cout << j << endl;
        j++;
    }

    // while 문
    //  while (조건식) {
    //      조건이 참인 동안 반복 실행
    //  }

    int count = 1;
    while (count < 5) {
        cout << "count : " << count << endl;
        count++;
    }
    cout << "현재 count: " << count << endl;
    
    // do while 문
    // do {
    //     반복 실행되는 코드
    // } while (조건식);

    do {
        cout << "한번은 돌아갈까??" << endl;
    } while (count > 5);


    // 실습 1
    int n;  
    cout << "숫자를 입력하세요 : ";
    cin >> n;

    // 왼쪽 정렬
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // 오른쪽 정렬
    for (int i = 1; i <= n; i++) {
        // 공백을 입력
        for (int space = 1; space <= n - i; space++) {
            cout << " ";
        }
        // 별찍기
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    // 실습 구구단
    for (int i = 1; i <= 9; i++) {
        cout << "------" << i << "단 -----" << endl;
        for (int j = 1; j < 10; j++)
        {
            cout << i << " x " << j << " = " << i * j << endl;
        }
        cout << endl;
    }

    // 실습 3   
    int m;
    int sum = 0;
    cout << "1부터 n까지의 합 구하기" << endl;

    cout << "숫자를(양의 정수)를 입력하세요 : ";
    cin >> m;

    int k = 1;
    while (k <= m) {
        sum += k;
        k++;
    }

    for (int i = 0; i <= m; i++) {
        sum += i;
    }

    cout << "1부터 " << m << "까지의 합은 : " << sum << endl;

    // 실습 4
    int input_num;
    cout << "사용자가 입력한 숫자 더하기" << endl;
    cout << endl;
    int total = 0;
    while (true) {
        cout << "숫자를 입력하세요(0: exit) :";
        cin >> input_num;
        if (input_num == 0) {
            break;
        }
        total += input_num;
    }
    cout << "사용자가 입력한 수의 합은 : " << total << endl;

    // 배열
    int arr[3] = { 1,2,3 };

    for (int i = 0; i < 3; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    for (int num : arr) {
        cout << "num : " <<  num << endl;
    }

    // 자동 배열의 크기
    int arr1[] = { 10,20,30,40,50,60 };

    for (int i = 0; i < 7; i++) {
        cout << "arr1[" << i << "] = " << arr1[i] << endl;
    }

    for (int num1 : arr1) {
        cout << "num1 : " << num1 << endl;
    }

    string matrix[2][2] = {
        {"apple", "banana"},
        {"orange", "strawberry"}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "matrix["<< i << "][" << j << "] :"<< matrix[i][j] << endl;
        }
    }

    // 배열의 크기
    int arr2[5] = { 1,2,3,4,5 };
    cout << "배열의 크기 : " << sizeof(arr2) / sizeof(arr2[0]) << endl;

    // 배열의 초기화
    int arr3[5] = { 1,2,3,4,5 };
    int arr4[5] = { 1,2,3 };
    int arr5[5] = { 0 };
    int arr6[] = { 1,2,3,4,5 };
    
    // 반복문
    // 실습 1
    string city[5] = { "한국", "미국","일본" , "중국", "프랑스" };

    cout << "일반 for문" << endl;
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            cout << city[i];
        }
        else {
            cout << city[i] << ", ";
        }
    }
    cout << endl;

    cout << "for-each 문" << endl;
    for (string ci : city) {
        cout << ci << ", ";
    }
    cout << endl;

    //실습 2
    string city2[5];

    cout << "5개의 나라 이름을 입력하세요 :" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "번째 나라:";
        cin >> city2[i];
    }

    cout << "일반 for문" << endl;
    for (int i = 0; i < 5; i++) {
        if (i == 4) {
            cout << city2[i];
        }
        else {
            cout << city2[i] << ", ";
        }
    }
    cout << endl;

    cout << "for-each 문" << endl;
    for (string ci : city2) {
        cout << ci << ", ";
    }
    cout << endl;


    // 실습 3.
    int grade[5]; // 학생들의 성적
    int total = 0; //학생들의 모든 점수

    // 성적 입력 받기
    for (int i = 0; i < 5; i++) {
        cout << i << "번 학생의 성적을 입력하세요 : ";
        cin >> grade[i];
        total += grade[i];
    }

    // 평균 계산
    double avg = static_cast<double>(total) / 5;
    cout << "성적 평균 : " << avg << endl;
    
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
