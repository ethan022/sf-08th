#include <iostream>
#include <mysql/jdbc.h>
#include <string>

using namespace std;

int main()
{
    try {
        // 드라이브 인스턴스 생성
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        // 서버 주소
        const string server = "tcp://127.0.0.1:3306";
        // 사용자 이름
        const string user_name = "root";
        // 비밀번호
        const string password = "1234";
        // 데이터베이스 연결
        unique_ptr<sql::Connection> con(
            driver->connect(server, user_name, password)
        );
        // 데이터베이스 선택
        con->setSchema("codingon_store_db");
        // 인코딩 설정
        unique_ptr<sql::Statement> stmt(con->createStatement());
        stmt->execute("set names euckr");
        // 쿼리 실행
        unique_ptr<sql::PreparedStatement> pstmt(
            con->prepareStatement("SELECT customer_id, name, email FROM customers")
        );
        // 결과 집합 생성
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
        // 결과 집합 반복
        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

        // 고객 정보 입력
        string new_name, new_email, new_phone;
        cout << "고객 이름: ";
        getline(cin, new_name);
        cout << "이메일 :";
        getline(cin, new_email);
        cout << "전화 번호 : ";
        getline(cin, new_phone);

        // 고객 정보 삽입
        unique_ptr<sql::PreparedStatement> pstmt_insert(
           con->prepareStatement(
               "INSERT INTO customers (name, email, phone) VALUES (?,?,?)"
           )
        );

        // 고객 정보 삽입
        pstmt_insert->setString(1, new_name);
        pstmt_insert->setString(2, new_email);
        pstmt_insert->setString(3, new_phone);

        // 고객 정보 삽입
        int insert_result = pstmt_insert->executeUpdate();

        con->commit();
        cout << insert_result << "명의 고객이 등록 되었습니다." << endl;

        // 고객 정보 수정
        int update_customer_id;
        cout << "수정할 고객 ID : ";
        cin >> update_customer_id;
        cin.ignore();
        string update_name, update_email, update_phone;
        cout << "새 이름: ";
        getline(cin, update_name);
        cout << "새 이메일 :";
        getline(cin, update_email);
        cout << "새 전화 번호 : ";
        getline(cin, update_phone);

        // 고객 정보 수정
        unique_ptr<sql::PreparedStatement> pstmt_update(
           con->prepareStatement(
               "UPDATE customers SET name = ?, email = ?, phone = ? WHERE customer_id = ?"
           )
        );

        // 고객 정보 수정
        pstmt_update->setString(1, update_name);
        pstmt_update->setString(2, update_email);
        pstmt_update->setString(3, update_phone);
        pstmt_update->setInt(4, update_customer_id);

        // 고객 정보 수정
        int update_result = pstmt_update->executeUpdate();

        con->commit();

        cout << update_result << "명의 고객의 정보가 수정 되었습니다." << endl;

        // 고객 정보 삭제
        int delete_customer_id;
        cout << "삭제할 고객 ID : ";
        cin >> delete_customer_id;

        // 고객 정보 삭제
        unique_ptr<sql::PreparedStatement> pstmt_delete(
           con->prepareStatement(
               "DELETE FROM customers WHERE customer_id = ?"
           )
        );

        // 고객 정보 삭제
        pstmt_delete->setInt(1, delete_customer_id);
        int delete_result = pstmt_delete->executeUpdate();
        con->commit();
        cout << delete_result << "명의 고객의 정보가 삭제 되었습니다." << endl;

        // 고객 주문 내역 조회
        unique_ptr<sql::PreparedStatement> pstmt_join(
            con->prepareStatement(
                "SELECT c.name, o.order_id, o.order_date, o.order_status "
                "FROM orders o "
                "JOIN customers c ON o.customer_id = c.customer_id "
                "ORDER BY o.order_date DESC"
            )
        );

        unique_ptr<sql::ResultSet> res_join(pstmt_join->executeQuery());

        cout << "[고객 주문 내역 조회]\n";
        while (res_join->next()) {
            cout << "고객: " << res_join->getString("name")
                << "| 주문번호: " << res_join->getString("order_id")
                << "| 주문일: " << res_join->getString("order_date")
                << "| 상태: " << res_join->getString("order_status")
                << "\n";
        }

    }
    catch (sql::SQLException& e) {
        cerr << "DB 연결 실패: " << e.what() << endl;
        cerr << "Error code: " << e.getErrorCode() << endl;
        cerr << "Sql state: " << e.getSQLState() << endl;
    }



}
