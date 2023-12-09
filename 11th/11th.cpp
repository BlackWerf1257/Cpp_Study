using namespace std;
#include <string>
#include <iostream>

using namespace std;
#include <string>
#include <iostream>

//가상함수와 오버라이딩
class Base { public: virtual void f() { cout << "Base::f() Called" << endl; } };
class Derived : public Base { public: virtual void f() { cout << "Derived::f() called" << endl; } };

//다중 상속
class Adder { protected: int add(int a, int b) { return a + b; } };
class Subtractor { protected: int minus(int a, int b) { return a - b; } };

class Calculator : public Adder, public Subtractor { public: int calc(char op, int a, int b); };
int Calculator::calc(char op, int a, int b) {
    int res = 0;
    switch (op){
        case '+': res = add(a,b); break;
        case '-': res = minus(a, b); break;
        }
    return res;
}



// 생성자 매개 변수 전달
class TV {
    int size; //스크린 크기
public:
    TV() { size = 20; }
    TV(int size) { this->size = size; }
    int getSize() { return size; }
};
class WideTV : public TV { //TV 상속받는 WideTV
    bool videoIn;
public:
    WideTV(int size, bool videoIn) : TV(size) { this->videoIn = videoIn; }
    bool getVideoIn() { return videoIn; }
};

class SmartTV : public WideTV { //WideTV 상속받는 SmartTV
    string ipAddr; //인터넷 주소
public:
    SmartTV(string ipAddr, int size) : WideTV(size, true) { this->ipAddr = ipAddr; }
    string getIpAddr() { return ipAddr; }
};

//
class Shape {
protected:
    int x, y; //한점 (x,y) 좌표값
public:
    void set(int x, int y);
    void showShape();
};
void Shape::set(int x, int y) { this->x = x; this->y = y; }
void Shape::showShape() { cout << "(" << x << "," << y << ")" << endl; }

class Circle : public Shape {
    string color;
public:
    void setColor(string color);
    void showCircle();
    bool equals(Circle p);
};
void Circle::setColor(string color) { this->color = color; }
void Circle::showCircle() {
    cout << color << ':';
    showShape(); //Shape 클래스의 showShape() 호출
}
bool Circle::equals(Circle p) {
    if (x == p.x && p.y && color == p.color)
        return true; //정상
    else
        return false;
}

int main()
{
    //가상 함수와 오버라이딩
    Derived d, * pDer;
    pDer = &d;
    pDer->f(); //Derived::f() 호출

    Base* pBase;
    pBase = pDer; //업 캐스팅
    pBase->f(); // 동적 바인딩 발생 Derived::f() 실행

    //다중 상속
    /*Calculator handCalculator;
    cout << " 2 + 4 = " << handCalculator.calc('+', 2, 4) << endl;
    cout << "100 - 8 = " << handCalculator.calc('-', 100, 8) << endl;*/


    //생성자 매개 변수 전달
    //32인치 크기에 192.0.0.1 인터넷 주소 가지는 스마트 Tv 객체
    /*SmartTV htv("192.0.0.1", 32);
    cout << "size = " << htv.getSize() << endl;
    cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;
    cout << "IP = " << htv.getIpAddr() << endl;*/

    //
    //Shape p;
    //p.set(2, 3); //정상
    ////p.x - 5; //오류
    ////p.y = 5; //오류
    //p.showShape();

    //Circle cp;
    //cp.set(3, 4);
    ////cp.x = 10; //오류
    ////cp.y - 10; //오류
    //cp.setColor("Red");
    //cp.showCircle();

    //Circle cp2;
    //cp2.set(3, 4);
    //cp2.setColor("Red");
    //cout << ((cp.equals(cp2)) ? "true" : "false");
}
