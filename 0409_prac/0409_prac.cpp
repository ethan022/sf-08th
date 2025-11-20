
#include <iostream>
using namespace std;

class Rectangle {
public:
  // 생성자
	Rectangle(int w, int h) {
		width = w;
		height = h;
	}

    // 복사 생성자
	Rectangle(const Rectangle& other) {
		width = other.width;
		height = other.height;
	}

    // 멤버 변수
	int width;
	int height;
	
  
    // 멤버 함수
	int area() {
		return width * height;
	}
};

class BankAccount {
public:

    BankAccount() {
        accountNumber = "1234567890";
        balance = 0;
    }

    ~BankAccount() {
        cout << "계좌가 소멸되었습니다." << accountNumber  << endl;
    }

    int balance;
    string accountNumber;

    int deposit(int amount) {
        balance += amount;
        return balance;
    }
    int withdraw(int amount) {
        balance -= amount;
        return balance;
    }
};


class Character {
public:
    string name;
    int level;
    int item_num;

    Character(string name1) {
        name = name1;
        level = 1;
        item_num = 0;
    }

    void changeName() {
        cout << "이름을 입력하세요" << endl;
        cin >> name;
    }

    void levelUp() {
        level++;
    }

    void addItem() {
        item_num++;
    }

    void removeItem() {
        item_num--;
    }

    void showInfo() {
        cout << "이름: " << name << " 레벨: " << level << " 아이템 개수: " << item_num << endl;
    }
};

int main()
{
    //실습 1
    //사용자 입력
    int width, height;
    cout << "사각형의 너비와 높이를 입력하세요" << endl;
    cin >> width >> height;
    // 객체 생성
    Rectangle rect(width, height);
    // 멤버 함수 호출
    cout << "사각형의 넓이는 " << rect.area() << "이다." << endl;

    //실습 2
    Rectangle rect2 = rect;
    // 멤버 함수 호출
    cout << "rect2의 넓이는 " << rect2.area() << "이다." << endl;

    //실습 3
    BankAccount bankAccount;
    bankAccount.deposit(1000);
    bankAccount.withdraw(500);
    cout << "현재 잔액은 " << bankAccount.balance << "원 입니다." << endl;

    //실습 4
    // 캐릭터 이름 받기
    string name;    
    cout << "캐릭터의 이름을 입력하세요" << endl;
    cin >> name;
    Character character(name);
    while (true) {
        cout << "1. 이름 변경 2. 레벨 증가 3. 아이템 추가 4. 아이템 제거 5. 정보 보기 0. 종료" << endl;
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            character.changeName();
        }
        else if (choice == 2) {
            character.levelUp();
        }
        else if (choice == 3) {
            character.addItem();
        }
        else if (choice == 4) {
            character.removeItem();
        }
        else if (choice == 5) {
            character.showInfo();
        }
        else if (choice == 0) {
            break;
        }
    }
}