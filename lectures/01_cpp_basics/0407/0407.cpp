// 0407.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

void coutFunc(const int* x) {
    cout << "출력 :" << x << endl;
    //*x = 200;
}

void hello() {
    cout << "hello" << endl;
}

int add(int x, int y) {
    return x + y;
}

void executeCallback(void (*callback)()) {
    cout << "executeCallback 콜백 함수를 호출합니다. :" << endl;
    callback();
}

void myCallback() {
    cout << "myCallback 콜백 함수를 호출합니다. :" << endl;
}

int main()
{
    // 콜백 함수 호출
    executeCallback(myCallback);

    // 변수의 주소값 출력
    int num = 42;

    coutFunc(&num);

    // 변수의 주소값 출력
    cout << "num의 값은 : " << num << endl;
    cout << "num의 주소값은" << &num << endl;

    // 포인터 변수 선언
    int* ptr = &num;

    // 포인터 변수의 값 출력
    cout << "ptr의 값은 : " << ptr << endl;
    cout << "ptr의 역참조 : " << *ptr << endl;

    // 포인터 변수의 값 변경
    *ptr = 20;

    // 변수의 값 출력
    cout << "2. num의 값은 : " << num << endl;
    cout << "2. num의 주소값은" << &num << endl;

    // 배열의 주소값 출력
    int arr1[6] = { 1,2,3,4,5,6 };
    cout << "3. arr배열의 주소값 : " << arr1 << endl;
    cout << "3. arr[1]배열의 주소값 : " << arr1 + 1 << endl;
    cout << "3. arr[2]배열의 주소값 : " << arr1 + 2 << endl;

    // 배열의 주소값 출력
    cout << "4. arr배열의 주소값 : " << *arr1 << endl;
    cout << "4. arr[1]배열의 주소값 : " << *(arr1 + 1) << endl;
    cout << "4. arr[2]배열의 주소값 : " << *(arr1 + 2) << endl;

    // 변수의 주소값 출력
    int num1 = 42;
    double num2 = 42;
    long num3 = 42;
    float num4 = 42;
    long num5 = 42;
    long num6 = 42;
    double num7 = 42;
    //int* ptr2 = &num1;

    // 변수의 주소값 출력
    num5 = 2;
    void* ptr1 = &num5;

    // 변수의 주소값 출력
    cout << "5. void ptr1 주소값 : " << ptr1 << endl;
    //cout << "5. void ptr1 값 : " << *(int*)ptr1 << endl;

    // sizof 바이트 (자료형의) 크기
    int a = 20;
    int b = 20;
    int* ptr2 = &a;
    int* ptr3 = &b;

    // int 포인터 자료형의 크기 출력
    cout << "6. int 포인터 자료형의 크기 : " << sizeof(ptr2) << endl;
    cout << "6. long long 포인터 자료형의 크기 : " << sizeof(ptr3) << endl;

    // 힙에 정수 공간 할당
    int* ptr11 = new int;
    // 값을 저장
    *ptr11 = 42;

    // 힙에 정수 공간 할당
    cout << "ptr 값 : " << *ptr11 << endl;

    // 메모리 해제
    delete ptr11;

    // 배열의 크기를 입력 하세요 :
    int size;
    cout << "배열의 크기를 입력 하세요 :";
    cin >> size;

    int* arr = new int[size];

    // 배열의 값을 입력 하세요 :
    for (int i = 0; i < size; i++) {
        arr[i] = i + 10;
        cout << arr[i] << " ";
    }

    // 배열 메모리 해제
    delete[] arr;

    // 포인터 변수 선언
    int a1 = 20;
    int* ptr_a1 = &a1;
    int** ptr_ptr_a1 = &ptr_a1;

    // 포인터 변수의 값 출력
    int arr2[2] = { 1,2 };
    cout << "arr2 의 주소값 : "<< arr2 << endl;

    // 포인터 변수의 값 출력
    //int a2 = 10;
    //int b2 = 20;

    // 포인터 변수의 값 출력
    //int* arr[2] = { &a2,&b2 };

    //int row1[] = { 1,2 };
    //int row2[] = { 2,3 };

    // 포인터 변수의 값 출력
    //int arr[2][2] = {
    //    *row1,
    //    *row2
    //};

    // 포인터 변수의 값 출력
    //int arr[2][2] = {
    //   { 1,2 },
    //   { 2,3 }
    //};

    // 포인터 변수의 값 출력
    int rows = 3, cols = 3;
    // 이중 포인터 변수 선언
    int** matrix = new int* [rows];
    // { 
    //  &arr1, 
    //  &arr2,
    //  &arr3,
    // }

    // 이중 포인터 동적 할당
    for (int i = 0; i < rows; i++) {
        // 각 행에 열 할당
        matrix[i] = new int[cols];
    }
    // {
    //  {, , }
    //  {, , }
    //  {, , }
    // }

    // 이중 포인터 값 할당
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i * 3 + j + 1;
        }
    }
    // {
    //  {1, 2, 3}
    //  {4, 5, 6}
    //  {7, 8, 9}
    // }

    // 이중 포인터 값 출력
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << ", ";
        }
        cout << endl;
    }

    // 이중 포인터 메모리 해제
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // 함수 포인터 선언
    void (*funcPtr)();
    funcPtr = hello;
    funcPtr();
    cout << "hello : " << hello << endl;
    hello();;

    // 함수 포인터 선언
    int(*funcPtr1)(int, int);
    funcPtr1 = add;
    cout << "10 + 20 = " << funcPtr1(10, 20) << endl;
    cout << "10 + 20 = " << add(10, 20) << endl;
    return 0;
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
