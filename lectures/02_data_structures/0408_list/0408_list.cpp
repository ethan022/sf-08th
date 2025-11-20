// 0408_list.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

void listShow(list<int> list1) {
	// 반복자 (iterator)
	for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}
int main()
{
	//list<int> mylist = { 1,1,1,2,3,4,4,5,5,5,6,6};

	////// for-each
	////for (int num : mylist) {
	////	cout << num << endl;
	////}

	//mylist.remove(1);
	//cout << "mylist.remove(1) :" << endl;
	//listShow(mylist);

	//mylist.remove_if([](int n) {return n == 4; });
	//cout << "mylist.remove_if([](int n) {return n == 4; }) :" << endl;
	//listShow(mylist);

	//list<int> list2 = { 1,1,1, 20, 40, 60 };
	////mylist.splice(mylist.begin(), list2);
	////cout << "mylist.splice(mylist.begin(), list2) :" << endl;
	////listShow(mylist);

	//mylist.merge(list2);
	//cout << "mylist.merge(list2) :" << endl;
	//listShow(mylist);

	//mylist.unique();
	//cout << "mylist.unique() :" << endl;
	//listShow(mylist);


	list<int> myList1 = { 5,4,3,4,2,1,1 };

	cout << "4가 몇개인지 출력" << endl;
	cout << count(myList1.begin(), myList1.end(), 4) << endl;

	cout << "{1,1,2,3,4,5} 가 나오도록 리스트 변경" << endl;
	myList1.sort();
	listShow(myList1);

	cout << "중복 제거" << endl;
	myList1.unique();
	listShow(myList1);

	cout << "{1,2,3,4,5,6,7} 가 나오도록 리스트 변경" << endl;
	myList1.push_back(6);
	myList1.push_back(7);
	listShow(myList1);

	cout << "{0,1,2,3,4,5,6,7} 가 나오도록 리스트 변경" << endl;
	myList1.push_front(0);
	listShow(myList1);

	
	
	
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
