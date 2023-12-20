using namespace std;
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <fstream>

int square(int x) { return x * x; }


//istream
void get1() {
    cout << "Enter키가 입력될때까지 계속 입력 및 출력됨>>";
    int ch; //EOF 비교를 위해 int
    while ((ch = cin.get()) != EOF) { //문자 읽기, EOF=-1
        cout.put(ch); //읽은 문자 출력

        if (ch == '\n') break; //Enter키 입력시 함수 종료
    }
}
    void get2() {
        cout << "Enter키가 입력될때까지 계속 입력 및 출력됨>>";
        int ch; //EOF 비교를 위해 int
        while ((ch = cin.get()) != EOF) { //문자 읽기, EOF=-1
            cout.put(ch); //읽은 문자 출력

            if (ch == '\n') break; //Enter키 입력시 함수 종료
    }
}

int main()
{
    //예외 처리
    /*int n, sum, average;
    while (true)
    {
        cout << "합을 입력하세요 : ";
        cin >> sum;
        cout << "인원수를 입력하세요 : ";
        cin >> n;

        try {
            if (n <= 0) //오류 탐지
                throw n; //catch(int x) 블록으로 점프
            else
                average = sum / n;
        }
        catch (int x) {
            cout << "예외 발생 " << x << "으로 나눌 수 없음" << endl;
            average = 0;
            cout << endl;
            continue;
        }
        cout << "평균 : " << average << endl << endl; //평균 출력
    }*/

    //파일의 연결
    /*const char* firstFile = "D:\\23-2\\CPP\\test_write2.txt";
    const char* secondFile = "C:\\Windows\\system.ini";
    
    fstream fout(firstFile, ios::out | ios::app); //쓰기 모드로 파일 열기
        if (!fout) {
            cout << firstFile << "열기 오류";
            return 0;
        }

        fstream fin(secondFile, ios::in); //읽기 모드로 파일 열기
        if (!fin) {
            cout << secondFile << "열기 오류";
            return 0;
        }
        int c;
        while ((c = fin.get()) != EOF)  //파일 끝까지 문자 읽기
            fout.put(c); // 읽은 문자 기록

        fin.close(); //입력 파일 닫기
        fout.close(); //출력 파일 닫기*/


    //파일 출력 예제
    /*char name[10], dept[20];
    int sid;
    //키보드로부터 읽기
    cout << " 이름 : ";
    cin >> name; //키보드에서 이름 입력 받음
    cout << " 학번 : ";
    cin >> sid; 
    cout << " 학과 : ";
    cin >> dept;

    //파일 열기 및 출력 스트림 생성
    ofstream fd("D:\\23-2\\CPP\\test.txt");
    if (!fd) { //열기 실패 검사
        cout << "파일을 열수 없습니다.";
        return 0;
    }
    //파일 쓰기
    fd << name << endl; //name 쓰기
    fd << sid << endl << endl;
    fd << dept << endl;
    cout << "파일 쓰기 성공" << endl;
    fd.close(); //파일 닫기 */


    /* //조작자
    cout << showbase;

    //타이틀 출력
    cout << setw(8) << "Number";
    cout << setw(10) << "Octal";
    cout << setw(10) << "Hexa" << endl;

    //하나의 수를 10, 8, 16진수 형태로 한줄에 출력
    for (int i = 0; i < 50; i += 5) {
        cout << setw(8) << setfill('.') << dec << i; //10진수
        cout << setw(10) << setfill('.') << oct << i; //8진수
        cout << setw(10) << setfill('.') << hex << i << endl; //16진수 
    } */



    //포맷 플래그
    /* cout << 30 << endl; //10진수 출력
    cout.unsetf(ios::dec); //10진수 해제
    cout.setf(ios::hex); //16진수로 설정
    cout << 30 << endl;

    cout.setf(ios::showbase); //16진수로 설정
    cout << 30 << endl;

    cout.setf(ios::uppercase); //16진수의 A~F는 대문자로 출력
    cout << 30 << endl;

    cout.setf(ios::dec | ios::showpoint); //10진수 표현과 동시에 소수점 이하 나머지는 0으로 출력

    cout << 23.5 << endl;

    cout.setf(ios::scientific); //실수를 과학산술용 표현으로 출력
    cout << 23.5 << endl;

    cout.setf(ios::showpos); //양수인 경우 + 부호도 함께 출력
    cout << 23.5; */


    //매개 변수 있는 조작자
    //cout << setw(10) << setfill('^') << "Test" << endl;
    //매개변수 없는 조작자
    //cout << hex << showbase << 30 << endl;
    //cout << dec << showpos << 100 << endl;

    //istream
    //get1(); //cin.get() 이용
    //get2(); //cin.get(char &) 이용
    


    //ostream
    //Hello! 출력하고 다음 줄로 이동
    //cout.put('H');
    //cout.put('e');
    //cout.put('l');
    //cout.put('l');
    //cout.put('o');
    //cout.put(33);
    //cout.put('\n');

    ////C++ 출력
    //cout.put('C').put('+').put('+').put(' ');

    //char str[] = "Hello World";
    //cout.write(str, 5);

    //auto 이용한 변수 선언
    /* auto c = 'a'; //char 타입
    auto pi = 3.14; //double 타입
    auto one = 1; //int
    auto* p = &one; //int* 타입

    cout << c << " " << pi << " " << one << " " << *p << endl;

    //함수의 리턴 타입으로 추론
    auto ret = square(3); //square()의 리턴타입이 int이므로 int

    cout << *p << " " << ret << endl;

    vector<int> vec = { 1,2,3,4,5 }; //벡터 vec에 5개 원소 1,2,3,4,5 삽입
    vector<int>::iterator iter;
    for (iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " "; //1 2 3 4 5 출력
    cout << endl;

    //템플릿에 auto를 사용해 간소화
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        cout << *iter << " "; //1 2 3 4 5 출력 */


    //STL 알고리즘 sort()의 예제
    /*vector<int> v; //정수 벡터 생성
    cout << "5개의 정수 입력하세요 : ";
        for (int i = 0; i < 5; i++)
        {
            int n;
            cin >> n;
            v.push_back(n); //키보드에 읽은 정수를 벡터에 삽입
        }
        //v.begin() - v.end() 사이의 값을 오름차순으로 정렬
        //sort() 함수의 실행결과 : 벡터 v의 원소 순서 변경
        sort(v.begin(), v.end());
        
        vector<int>::iterator it; //벡터 내 원소를 탐색하는 iterator 변수 선언
        for (it = v.begin(); it != v.end(); it++)
            cout << *it << ' ';
        cout << endl;*/

    //Map의 활용
    /*map<string, string> dic;
    dic.insert(make_pair("love", "사랑"));
    dic.insert(make_pair("apple", "사과"));

    dic["cherrry"] = "체리"; //("cherry", "체리") 저장
    cout << "사전의 단어 수 : " << dic.size() << endl;

    string eng;
    while (true)
    {
        cout << "찾고 싶은 단어 :";
        getline(cin, eng); //사용자로부터 단어 입력

        if (eng == "exit")
            break;
        if (dic.find(eng) == dic.end()) //해당 키가 존재 X할 경우
            cout << "값 존재 X" << endl;
        else
            cout << dic[eng] << endl;
    }
    cout << "종료" << endl; */
}
