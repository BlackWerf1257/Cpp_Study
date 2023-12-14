#include <iostream>
#include <string>
using namespace std;

//객체의 참조
class Circle3 {
    int radius;
public:
    Circle3() { radius = 1; }
    Circle3(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};


//객체의 치환과 함수 반환
class Circle2
{
    int radius;
public:
    Circle2() { radius = 1; }
    Circle2(int radius) { this->radius = radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
    Circle2 getCircle() {
    Circle2 tmp(30); return tmp; } // 객체 tmp을 리턴한다.
};




//값에 의한 객체 전달
class Circle
{
    private:
        int radius;
    public:
        Circle():Circle(1){};
        Circle(int r);
        ~Circle()
        { cout << "소멸자 실행 radius = " << radius << endl; }
        double getArea() { return 3.14 * radius * radius; }
        int getRadius() { return radius; }
        void setRadius(int radius) { this->radius = radius; }
};
Circle::Circle(int radius)
{ this->radius = radius; cout << "생성자 실행 radius = " << radius << endl; }
void increase(Circle c)
{
    int r = c.getRadius();
    c.setRadius(r + 1);
}

//주소에 의한 객체 전달
void plus10(Circle* p)
{
    int tmp;
    tmp = p->getRadius();
    p->setRadius(tmp + 10);
}


//주소에 의한 호출
void swap(int* a, int* b) 
{
     int tmp = *a;
    *a = *b;
    *b = tmp;
}

//값에 의한 호출
void swap(int a, int b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    cout << a << " " << b;

}


int main()
{
    //객체의 참조
    Circle3 circle;
    Circle3& refc = circle;
    refc.setRadius(10);
    cout << refc.getArea() << " " << circle.getArea();



    //변수의 참조
    //cout << "a" << '\t' << "b" << '\t' << "refb" << endl;
    //int a = 1;
    //int b = 2;
    //int& refb = b;
    //b = 4;
    //refb++; // refb=5 b=5
    //cout << a << '\t' << b << '\t' << refb << endl;

    //refb = a;
    //refb++; //refb: 2, b:2
    //cout << a << '\t' << b << '\t' << refb << endl;

    //int* p = &refb;
    //*p = 20; //refb=20, b=20
    //cout << a << '\t' << b << '\t' << refb << endl;


    //객체의 치환과 함수반환
    //Circle2 c1(10);
    //Circle2 c2;
    //cout << c2.getArea() << endl;
    //c2 = c1;
    //cout << c2.getArea() << endl;
    ////c2.getCircle();
    //cout << c2.getArea() << endl;

    //주소에 의한 객체 전달
    //Circle ring(10);
    //plus10(&ring);
    //cout << ring.getRadius();


    //값에 의한 객체 전달
    /*Circle donut(30);
    increase(donut);
    cout << donut.getRadius() << endl;*/

    //주소에 의한 호출
    /*int m = 2, n = 9;
    swap(&m, &n);
    cout << m << " " << n;*/

    //값에 의한 호출
    //swap(2, 9);



    //string 문자열 찾기와 교체
    //string s;
    //cout << "여러 줄의 문자열 입력. 입력의 끝은 &문자." << endl;
    //getline(cin, s, '&');
    //cin.ignore(); //&뒤에 enter키 제거
    //string f, r;
    //cout << endl << "find: ";
    //getline(cin, f, '\n'); //검색할 문자열 입력
    //cout << "replace: ";
    //getline(cin, r, '\n'); //대치할 문자열 입력

    //int startindex = 0;
    //while (true)
    //{
    //    int findex = s.find(f, startindex); //startindex부터 문자열 f 검색  
    //    if (findex == -1)
    //        break; //문자열 s의 끝까지 변경함

    //    s.replace(findex, f.length(), r); //findex부터 문자열 f의 길이만큼 문자열 r로 변경
    //    startindex = findex + r.length();
    //}
    //    cout << s << endl;


    //String 문자열 분리와 합치기
    //string s;
    //cout << "문자열 입력 " << endl;
    //getline(cin, s, '\n'); //문자열 입력
    //int len = s.length(); //문자열 길이

    //for (int i = 0; i < len; i++)
    //{
    //    string first = s.substr(0, 1); //맨 앞 문자 1개를 문자열로 분리
    //    string sub = s.substr(1, len - 1); //나머지 문자들을 문자열로 분리
    //    s = sub + first; //두 문자열 연결해 새 문자열로 만듬
    //    cout << s << endl;
    //}



    //String 배열
    //string names[5]; //문자열 배열 선언
    //for (int i = 0; i < 5; i++)
    //{
    //    cout << "이름 >> ";
    //    getline(cin, names[i], '\n');
    //}
    //string latter = names[0];
    //for (int i = 1; i < 5; i++)
    //{
    //    if (latter < names[i]) //사전순으로 정렬
    //        latter = names[i];
    //}
    //cout << "사전에서 가장 뒤에 나오는 문자열은 " << latter << endl;
}
