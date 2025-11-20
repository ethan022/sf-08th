// 0408.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

bool isCheck(string s) {
	for (char c : s) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}

int main()
{
	string s1 = "Hello ";
	string s2 = "World!";

	cout << s1 + s2 << endl;
	cout << (s1 < s2) << endl;

	//string sentence;
	//cout << "문장을 입력하세요: ";
	//getline(cin, sentence);
	//cout << "당신이 입력한 문장은: " << sentence << endl;

	// string 함수
	cout << "s1.at(2) : " << s1.at(2) << endl;
	cout << "s2.at(2) : " << s2.at(2) << endl;

	cout << "s1[4] : " << s1[4] << endl;
	cout << "s2[4] : " << s2[4] << endl;

	cout << "s1.front() : " << s1.front() << endl;
	cout << "s1.back() : " << s1.back() << endl;

	cout << "s2.front() : " << s2.front() << endl;
	cout << "s2.back() : " << s2.back() << endl;

	cout << "s1.length() : " << s1.length() << endl;
	cout << "s1.size() : " << s1.size() << endl;

	s1.resize(10);
	cout << "s1.resize(10) : " << s1 << endl;;
	cout << "s1.length() : " << s1.length() << endl;

	s1.resize(11 , 'a');
	cout << "s1.resize(11 , 'a') : " << s1 << endl;
	cout << "s1.length() : " << s1.length() << endl;

	string s3 = "hello! ";
	string s4 = "world!";
	//cout << "s3.empty() : " << s3.empty() << endl;

	//s3.append(s4);
	//cout << "s3.append(s4) : " << s3 << endl;

	//s3.append(s4, 1, 3);
	//cout << "s3.append(s4, 3, 4) : " << s3 << endl;

	//s3.insert(1, s4);
	//cout << "s3.insert(1, s4) : " << s3 << endl;

	//s3.replace(2,1, s4);
	//cout << "s3.replace(1,3, s4) : " << s3 << endl;

	//s3.clear();
	//cout << "s3.clear() : " << s3 << endl;

	//s3.erase(1, 2);
	//cout << "s3.erase(1, 2) : " << s3 << endl;
	

	s3 += s4;
	cout << "s3 :" << s3 << endl;

	string s5 = "!!";
	cout << "s3.find(!) : " << s3.find(s5) << endl;
	cout << "s3.find(!, 6) : " << s3.find(s5, 6) << endl;

	size_t pos = s3.find(s5);
	// 문자열을 찾으면 실행
	// 못찾으면 npos와 같이 동일
	if (pos != string::npos) {
		cout << "찾은 문자열 첫 인덱스: " << pos << endl;
	}

	cout << "s3.substr(3) :" << s3.substr(3) << endl;
	cout << "s3.substr(3, 3) :" << s3.substr(3,3) << endl;

	string s6 = "aaa";
	string s7 = "ccc";
	cout << "s6.compare(s7) :" << s6.compare(s7) << endl;

	cout << "isdigit('5') :" << isdigit('5') << endl;
	cout << "isdigit('a') :" << isdigit('a') << endl;

	cout << "isalpha('3') :" << isalpha('3') << endl;
	cout << "isalpha('a') :" << isalpha('a') << endl;

	cout << "toupper('a') :" << char(toupper('a')) << endl;
	cout << "toupper('C') :" << char(toupper('C')) << endl;

	cout << "tolower('C') :" << char(tolower('C')) << endl;
	cout << "tolower('b') :" << char(tolower('b')) << endl;

	cout << "stoi('19') :" << typeid(stoi("19")).name() << endl;
	cout << "stof('19.23') :" << typeid(stof("19.23")).name() << endl;

	cout << "to_string(19.23) :" << typeid(to_string(19.23)).name() << endl;



	string str1 = "Police say two people are suspected of trying to create a shortcut for their construction work.The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";

	cout << "1. str1 문자열의 길이 : " << str1.length() << endl;
	cout << "1. str1 문자열의 길이 : " << str1.size() << endl;
	cout << "2. 100번째 문자 : " << str1.at(100) << endl;
	cout << "3. 100번째 문자 : " << str1[100] << endl;
	cout << "4. two라는 문자가 처음 나오는 위치 : " << str1.find("two") << endl;
	cout << "5. two라는 문자가 두번째로 나오는 위치 : " << str1.find("two", str1.find("two") + 1) << endl;

	string str2 = "Codingon";
	str2[0] = (tolower(str2.front()));
	cout << "1. 첫번째 문자 소문자로 변경 : " << (tolower(str2.front())) << endl;
	cout << "1. 첫번째 문자 소문자로 변경 : " << str2 << endl;
	cout << "2. ding 이라는 부분문자열 반환 : " << str2.substr(2, 4) << endl;
	cout << "3. coooooon이 되도록 변경 : " << str2.replace(2, 4,"oooo") << endl;
	cout << "4. con이 되도록 변경 : " << str2.erase(2,5) << endl;

	string str3 = "", str4 = "";
	cout << "1. 두 문자열을 입력 받아서 둘 모두 숫자인지 검사, 아니면 다시 입력 받기 : " << endl;

	while (true) {
		cin >> str3 >> str4;
		// 확인용
		//bool isdigit1 = true;
		//bool isdigit2 = true;

		//for (char c : str3) {
		//	if (!isdigit(c)) {
		//		isdigit1 = false;
		//	}
		//}
		//for (char c : str4) {
		//	if (!isdigit(c)) {
		//		isdigit2 = false;
		//	}
		//}

		if (isCheck(str3) && isCheck(str4)) {
			break;
		}
		else {
			cout << "두 문자열은 숫자가 아닙니다. 다시 입력 받기 : " << endl;
		}
	}

	cout << "두 문자열은 숫자입니다." << endl;

	cout << "2. 두 문자열을 더한 결과 : " << str3 + str4 << endl;

	cout << "3. 두 숫자의 합 결과 : " << stoi(str3) + stoi(str4) << endl;
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
