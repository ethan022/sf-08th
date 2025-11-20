// 0408_vector.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void vectorShow(vector<int> v) {
    for (int i = 0; i < v.end() - v.begin(); i++) {
        cout << v[i] << ", ";
    }
    cout << endl;
}


int main()
{
    // 빈 벡터 선언
    vector<int> v1;
    vector<int> v2(5, 10);
    vector<int> v3 = { 1,2,3,4,5 };

    cout << "v2.at(2) : " << v2.at(2) << endl;
    cout << "v3[2] : " << v3[2] << endl;

    cout << "v3.front() : " << v3.front() << endl;
    cout << "v3.back() : " << v3.back() << endl;

    for (int i = 0; i < v3.end() - v3.begin(); i++) {
        cout << v3[i] << ", ";
    }
    cout << endl;
    cout << "v3.end() - v3.begin() : " << v3.end() - v3.begin() << endl;
    cout << "v3.begin()의 역참조 : " << *(v3.begin() + 1) << endl;

    v3.push_back(6);
    cout << "v3.push_back(6) :";
    vectorShow(v3);

    v3.pop_back();
    cout << "v3.pop_back() :";
    vectorShow(v3);

    v3.insert(v3.begin() + 3, 3);
    cout << "v3.insert(v3.begin() + 3, 3) :";
    vectorShow(v3);

    v3.erase(v3.end() - 2 );
    cout << "v3.erase(v3.end() - 2) :";
    vectorShow(v3);

    vector<int> v4 = {3, 3,1,5,2,4 };
    cout << "v4 :";
    vectorShow(v4);

    reverse(v4.begin(), v4.end());
    cout << "reverse(v4.begin(), v4.end()) :";
    vectorShow(v4);

    sort(v4.begin(), v4.end());
    cout << "sort(v4.begin(), v4.end()) :";
    vectorShow(v4);
    reverse(v4.begin(), v4.end());
    cout << "reverse(v4.begin(), v4.end()) :";
    vectorShow(v4);

    auto it = find(v4.begin(), v4.end(), 3);
    cout << "it - v4.begin() :"<<it - v4.begin() << endl;

    auto count1 = count(v4.begin(), v4.end(), 3);
    cout << "count(v4.begin(), v4.end(), 3) :" << count1 << endl;


    vector<vector<int>> matrix(3, vector<int>(3, 0));
    cout <<"matrix[1][1] :" << matrix[1][1] << endl;
    //{ 
    //    { 0, 0, 0 },
    //    { 0,0,0 },
    //    { 0,0,0 },
    //}


    /*cout << "Vector를 사용하여 정수를 저장하는 빈 벡터 선언" << endl;
    vector<int> v5;

    cout << "사용자로부터 5개의 정수를 입력받아 벡터에 저장" << endl;
    for (int i = 0; i < 5; i++) {
        int num;
        cin >> num;
        v5.push_back(num);
    }
    cout << "벡터의 크기 출력" << endl;
    cout << "v5.size() : " << v5.size() << endl;
    */
    //cout << "벡터의 용량 출력" << endl;
    //cout << "v5.capacity() : " << v5.capacity() << endl;

    //cout << "벡터가 비어있는지 확인" << endl;
    //cout << "v5.empty() : " << v5.empty() << endl;
    
    //cout << "벡터의 모든 원소 출력" << endl;
    //for (int i = 0; i < v5.size(); i++) {
    //    cout << v5[i] << ", ";
    //}
    ////for (int i = 0; i < v5.end() - v5.begin(); i++) {
    ////    cout << v5[i] << ", ";
    ////}
    //cout << endl;

    //cout << "벡터의 가장 큰 값" << endl;
    //int max_value = v5[0];
    //for (int i = 0; i < v5.size(); i++) {
    //    if (max_value < v5[i]) {
    //        max_value = v5[i];
    //    }
    //}
    //cout << "max_element(v5.begin(), v5.end()) : " << *max_element(v5.begin(), v5.end()) << endl;
    //cout << "max_value : " << max_value << endl;

    //cout << "벡터의 가장 작은 값" << endl;
    //int min_value = v5[0];
    //for (int i = 0; i < v5.size(); i++) {
    //    if (min_value > v5[i]) {
    //        min_value = v5[i];
    //    }
    //}
    //cout << "min_element(v5.begin(), v5.end()) : " << *min_element(v5.begin(), v5.end()) << endl;
    //cout << "min_value : " << min_value << endl;

    //cout << "벡터의 모든 원소를 두배로 만들기" << endl;
    //for (int i = 0; i < v5.size(); i++) {
    //    v5[i] *= 2;
    //}

    //cout << "벡터의 모든 원소 출력" << endl;
    //for (int i = 0; i < v5.size(); i++) {
    //    cout << v5[i] << ", ";
    //}
    //cout << endl;

    //cout << "인덱스를 입력받아 해당 인덱스에 있는 원소 제거" << endl;
    //cout << "인덱스를 입력하세요 : ";
    //int index;
    //cin >> index;
    //v5.erase(v5.begin() + index);
    //cout << "벡터의 모든 원소 출력" << endl;
    //for (int i = 0; i < v5.size(); i++) {
    //    cout << v5[i] << ", ";
    //}
    //cout << endl;

    //cout << "인덱스를 입력 받아 새로운 원소 삽입" << endl;
    //cout << "인덱스를 입력하세요 : ";
    //cin >> index;
    //cout << "새로운 원소를 입력하세요 : ";
    //int new_element;
    //cin >> new_element;
    //v5.insert(v5.begin() + index, new_element);
    //cout << "벡터의 모든 원소 출력" << endl;
    //for (int i = 0; i < v5.size(); i++) {
    //    cout << v5[i] << ", ";
    //}
    //cout << endl;
    
    // 이차원 행렬 만들기
    //cout << "행과 열을 입력하세요 : ";
    //int rows, cols;
    //cin >> rows >> cols;

    //vector<vector<int>> matrix2(rows, vector<int>(cols, 0));
    //cout << "이차원 행렬의 크기 출력" << endl;
    //cout << "matrix2.size() : " << matrix2.size() << endl;
    //cout << "matrix2[0].size() : " << matrix2[0].size() << endl;

    //// 이차원 행렬의 모든 원소 초기화
    //for (int i = 0; i < matrix2.size(); i++) {
    //    for (int j = 0; j < matrix2[i].size(); j++) {
    //        matrix2[i][j] = (i + 1) * (j + 1);
    //    }
    //    cout << endl;
    //}

    //cout << "이차원 행렬의 모든 원소 출력" << endl;
    //for (int i = 0; i < matrix2.size(); i++) {
    //    for (int j = 0; j < matrix2[i].size(); j++) {
    //        cout << matrix2[i][j] << ", ";
    //    }
    //    cout << endl;
    //}
    //
    // 2차원 행렬 만들기
    // 행과 열을 입력 받아 이차원 행렬 만들기
    cout << "행과 열을 입력하세요 : ";
    int row, col;
    cin >> row >> col;
    vector<vector<int>> matrix3(row, vector<int>(col, 0));
    cout << "이차원 행렬의 크기 출력" << endl;
    cout << "matrix3.size() : " << matrix3.size() << endl;
    cout << "matrix3[0].size() : " << matrix3[0].size() << endl;

    // 이차원 행렬의 모든 원소 초기화
    for (int i = 0; i < matrix3.size(); i++) {
        for (int j = 0; j < matrix3[i].size(); j++) {
            matrix3[i][j] = (i * matrix3.size()) + (j + 1);
        }
        cout << endl;
    }

    cout << "이차원 행렬의 모든 원소 출력" << endl;
    for (int i = 0; i < matrix3.size(); i++) {
        for (int j = 0; j < matrix3[i].size(); j++) {
            cout << matrix3[i][j] << ", ";
        }
        cout << endl;
    }

    //각 행의 합
    for (int i = 0; i < matrix3.size(); i++) {
        int sum = 0;
        for (int j = 0; j < matrix3[i].size(); j++) {
            sum += matrix3[i][j];
        }
        cout << "matrix3[" << i << "]의 합 : " << sum << endl;
    }
    
    //각 열의 합
    for (int j = 0; j < matrix3[0].size(); j++) {
        int sum = 0;
        for (int i = 0; i < matrix3.size(); i++) {
            sum += matrix3[i][j];
        }
        cout << "matrix3[" << j << "]의 합 : " << sum << endl;
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
