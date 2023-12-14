#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string university("백석대학교");
    string department("첨단IT");
    string subject("C++");
    string mySubject;
    cout << "사랑합니다 " + university + "입니다" << endl;
    cout << "수강하는 수업은 ";
    getline(cin, mySubject);
    if (subject == mySubject)
        cout << subject + "이 맞습니다" << endl;
    else
        cout << subject + "수업이 아닙니다" << endl;

    /*cout << "학교 주소를 입력하세요: ";
    char addr[100];
    cin.getline(addr, 100, '\n');

    cout << "학교 주소는 " << addr << "입니다\n";*/



    /*char code[11];
    int lock = 1;
    cout << "방 비밀번호를 입력하세요" << endl;
    while (lock)
    {
        cout << "비밀번호:";
        cin >> code;
        if (strcmp(code, "2222") != 0) {
            cout << "잘못 눌렀습니다" << endl;
        }
        else
        {
            cout << "문이 열렸습니다:" << endl;
            lock = 0;
        }
    }*/



  /*  cout << "이름을 입력하세요>>";
    char name[11];
    cin >> name;
    cout << "내 이름은" << name << "입니다" << endl;*/


   /* float data1, data2;
    data1 = 3.14;
    data2 = 5;
    
    cout << "data2: " << data2 << endl;
    cout << data2 * data2 * data1 << endl;*/



 /*   int a, b, c, avg;

    

    cin >> a >> b >> c;
    avg = (a + b + c) / 3;
    cout << a << b << c << avg;*/

    /* 
    a = 70;
    b = 80;
    c = 90;

    avg = (a + b + c) / 3;

    cout << a << b << c << avg;*/



    //예제2
  /*  char data1, data2;

    data1 = 'a';
    data2 = 65;

    cout << "data1: " << data1 << endl;
    cout << "data2: " << data2 << endl;*/

    //예제 1
   /* int x, y;
    int area;

    cout << "가로 길이: ";
    cin >> x;

    cout << "세로 길이: ";
    cin >> y;

    area = x * y;
    
    cout << area;*/
}

