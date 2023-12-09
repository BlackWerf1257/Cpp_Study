#include <iostream>
#include "Shape.h"
//#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;



//템플릿 예제 2
template <class T>
T add(T data[], int n) { //배열 dta에서 n개 원소 합한 결과 리턴
    T sum = 0;
    for (int i = 0; i < n; i++) 
        sum += data[i];

    return sum; //Sum과 타입과 리턴 타입 모두 T로 선언됨
}



//템플릿 예제 1
template <class T>
T bigger(T a, T b) { //두 개의 매개 변수 비교 및 큰 값 리턴
    if (a > b) return a;
    else return b;
}

//제너릭 함수 구체화 3/3
class Circle {
    int radius;
public:
    Circle(int radius = 1) { this->radius = radius; }
    int getRadius() { return radius; }
};

template <class T>
T swap(T a, T b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;

    return a + b;
}


//제너릭 함수 구체화 1/3




//추상 클래스
class Calculator {
    void input() {
        cout << "정수 2개 입력 >>";
        cin >> a >> b;
    };

protected:
    int a, b;
    virtual int calc(int a, int b) = 0; //두 정수의 합 리턴
public:
    void run() {
        input();
        cout << "계산된 값 : " << calc(a, b) << endl;
    }
};
class Adder : public Calculator {
protected:
    int calc(int a, int b) { //순수 가상 함수 구현
        return a + b;
    }
};
class Subtractor : public Calculator {
protected:
    int calc(int a, int b) { //순수 가상 함수 구현
        return a - b;
    }
};

//가상 소멸자인 경우
class Base4 {
public:
    virtual ~Base4() { cout << "Called from Base" << endl; };
};
class Derived4 : public Base4 {
public:
    ~Derived4() { cout << "Called from Derived" << endl; };
};

//가상 소멸자가 아닌 경우
class Base3 {
public:
    ~Base3() { cout << "Called from Base" << endl; };
};
class Derived3 : public Base3 {
public:
    ~Derived3() { cout << "Called from Derived" << endl; };
};

//가상 소멸자
class Base2 {
public:
    virtual ~Base2()
    {
        cout << "~Base()" << endl;
    };
};
class Derived2 : public Base2 {
public:
    virtual ~Derived2() {
        cout << "~Derived()" << endl;
    }
};

class Base {
public:
    virtual void f()
    {
        cout << "Base::f() Called" << endl;
    };
};
class Derived : public Base {
public:
    void f() {
        cout << "Derived::f() Called" << endl;
    };
};
class AgainDerived : public Derived {
public:
    void f() {
        cout << "AgainDerived:f() called" << endl;
    }
};


int main()
{
    //템플릿 예제 2
    //int x[] = { 1,2,3,4,5,6,7,8,9,10 };
    //double d[] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 11.0 };

    //cout << "sum of x[] = " << add(x, 10) << endl; //배열 x와 원소 10개 합 계산
    //cout << "sum of d[] = " << add(d, 10) << endl; //배열 d와 워소 10개 합 계산

    //템플릿 예제 1
    /*int a = 20, b = 50;
    char c = 'a', d = 'z';
    cout << "bigger(20, 50)의 결과 : " << bigger(a, b) << endl;
    cout << "bigger('a', 'z')의 결과 : " << bigger(c, d) << endl;*/


    //제너릭 함수의 구체화 3/3
  /*  int a = 4, b = 5;
    swap(a, b);
    cout << "a=" << a << ", " << "b=" << b << endl;

    double c = 0.3, d = 12.5;
    swap(c, d);
    cout << "c=" << c << ", " << "d=" << d << endl;

    Circle donut(5), pizza(20);
    swap(donut, pizza);
    cout << "donut반지름=" << donut.getRadius() << ", ";
    cout << "pizza반지름=" << pizza.getRadius() << endl;*/

    //제너릭 함수의 구체화 1/3
    int a = 4, b = 5;
    cout << swap(a, b) << endl;



    //추상 클래스
    /*Adder adder;
    Subtractor subtractor;
    adder.run();
    subtractor.run();*/

    //가상 함수의 활용
    /*Shape* pStart = NULL;
    Shape* pLast;

    pStart = new Circle();
    pLast = pStart;
    pLast = pLast->add(new Rect());
    pLast = pLast->add(new Circle());
    pLast = pLast->add(new Line());
    pLast = pLast->add(new Rect());

    //현재 연결된 모든 도형 그리기
    Shape* p = pStart;
    while (p != NULL) {
        p->paint();
        p = p->getNext();
    }
    //현재 연결된 모든 도형 삭제
    p = pStart;
    while (p != NULL) {
        Shape* q = p->getNext(); //다음 도형 주소 기억
        delete p; //기본 클래스의 가상 소멸자 호출
        p = q; //다음 도형 주소를 p에 저장
    }*/

    //가상 소멸자인 경우
    /*Base4* pT = new Derived4();
    delete pT;

    //가상 소멸자가 아닌 경우
    Base3* pF = new Derived3();
    delete pF;*/

    //가상 소멸자
    /*Derived2* dp = new Derived2();
    Base2* bp = new Derived2();

    delete dp; //Derived의 포인터로 소멸
    delete bp; //Base의 포인터로 소멸 */

    //Virtual 함수의 오버라이딩
    /*AgainDerived a;
    Base* bp;
    Derived *dp;
    AgainDerived* ap;
    
    bp = dp = ap = &a;

    bp->f();
    dp->f();
    ap->f();*/
}
