#include <iostream>
using namespace std;
//#include "Circle.h"
// 
//동적 할당 응용 3
class DynamicCircleEx3 {
    int radius;
public:
    DynamicCircleEx3();
    ~DynamicCircleEx3();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};
DynamicCircleEx3::DynamicCircleEx3()
{
    radius = 1;
}





//동적 할당 응용
class DynamicCircleEx {
    int radius;
public:
    DynamicCircleEx();
    DynamicCircleEx(int r);
    ~DynamicCircleEx();
    void setRadius(int r) { radius = r; }
    double getArea() { return 3.14 * radius * radius; }
};
DynamicCircleEx::DynamicCircleEx()
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}
DynamicCircleEx::DynamicCircleEx(int r)
{
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}
DynamicCircleEx::~DynamicCircleEx() {
    cout << "소멸자 실행 radius = " << radius << endl;
}



//동적 할당
class DynamicCircle {
    int radius;
    public:
        DynamicCircle();
        DynamicCircle(int r);
        ~DynamicCircle();
        void setRadius(int r) { radius = r; }
        double getArea() { return 3.14 * radius * radius; }
};
DynamicCircle::DynamicCircle()
{
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}
DynamicCircle::DynamicCircle(int r)
{
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}
DynamicCircle::~DynamicCircle() {
    cout << "소멸자 실행 radius = " << radius << endl;
}


class CircleMultiArray {
    int radius;
public:
    CircleMultiArray() { radius = 1; }
    CircleMultiArray(int r) { radius = r; }
    void setRadius(int r)
    {
        radius = r;
    }
    double getArea();
};
double CircleMultiArray::getArea() {
    return 3.14 * radius * radius;
}


class CircleArray {
    int radius;
    public:
        CircleArray() { radius = 1; }
        CircleArray(int r) { radius = r; }
        void setRadius(int r)
            {radius = r; }
        double getArea();
};
double CircleArray::getArea() {
    return 3.14 * radius * radius;
    }


class CirclePointer {
    int radius;
    public:
        CirclePointer() { radius = 1; }
        CirclePointer(int r) { radius = r; }
        double getArea();
};
double CirclePointer::getArea() {
    return 3.14 * radius * radius;
}

int main()
{
    //객체의 동적 할당 응용 3
    //cout << "생성하는 원의 개수 : ";
    //int n, radius;
    //cin >> n;
    //DynamicCircleEx3 *pArrary = new DynamicCircleEx3[n];
    //for (int i = 0; i < n; i++)
    //{
    //    cout << "원" << i + 1 << ":";
    //    cin >> radius; //반지름 입력
    //    pArrary[i].setRadius(radius);
    //}
    //int count = 0; //카운트 변수
    //DynamicCircleEx3 *p = pArrary;
    //for (int i = 0; i < n; i++)
    //{
    //    cout << p->getArea() << ' ';
    //    if (p->getArea() >= 100 && p->getArea() <= 300)
    //        count++;
    //    p++;
    //}

    //cout << endl << "면적이 100 ~ 300 사이인 원의 개수 : " 
    //    << count << endl;
    //delete[] pArrary;


    //객체의 동적 할당 응용
    //int radius;
    //while (true)
    //{
    //    cout << "정수 반지름 입력(음수면 종료) >>";
    //    cin >> radius;
    //    if (radius < 0) break; //음수가 입력되어 종료

    //    DynamicCircleEx* p = new DynamicCircleEx(radius); //동적 객체 생성
    //    cout << "원의 면적은 " << p->getArea() << endl;
    //    delete p; //객체 반환
    //}
    


    // //객체의 동적 할당
    /*DynamicCircle *p, * q;
    p = new DynamicCircle;
    q = new DynamicCircle(30);
    cout << p->getArea() << endl << q->getArea() << endl;
    delete p;
    delete q;*/



    //동적 메모리 사용
    //cout << "입력 개수는?";
    //int n;
    //cin >> n;
    //if (n <= 0) return 0;
    //int* p = new int[n];
    //if (!p) {
    //    cout << "메모리를 할당할 수 없습니다.";
    //    return 0;
    //}
    //for (int i = 0; i < n; i++)
    //{
    //    cout << i + 1 << "번째 입력 : ";
    //    cin >> p[i]; //정수 입력
    //}
    //int sum = 0;
    //for (int i = 0; i < n; i++)
    //    sum += p[i];
    //cout << "총합 = " << sum << endl;
    //delete[] p; //배열 메모리 반환



    //동적 메모리 할당 연산자
    int *p;
    p = new int;
    if (!p)
    {
        cout << "메모리를 할당할 수 없습니다";
        return 0;
    }
    *p = 5;
    int n = *p;
    cout << "*p = " << *p << '\n';
    cout << "n = " << n << '\n';
    delete p;


    //다차원 객체 배열
    /*CircleMultiArray donutArray[2][3];
    donutArray[0][0].setRadius(1);
    donutArray[0][1].setRadius(2);
    donutArray[0][2].setRadius(3);
    donutArray[1][0].setRadius(4);
    donutArray[1][1].setRadius(5);
    donutArray[1][2].setRadius(6);

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            cout << "Donut[" << i << "," << j << "]의 면적은 " << donutArray[i][j].getArea() << endl;*/


    //객체 배열
    //CircleArray donutArray[3];
    ////배열을 이용한 객체 접근
    //donutArray[0].setRadius(10);
    //donutArray[1].setRadius(20);
    //donutArray[2].setRadius(30);

    //for (int i = 0; i < 3; i++)
    //    cout << "Donut " << i << " 의 면적은 " << donutArray[i].getArea() << endl;
    //CircleArray* p;
    //p = donutArray;
    //for (int i = 0; i < 3; i++) {
    //    cout << "Donut " << i << " 의 면적은" << p->getArea() << endl;
    //    p++;
    //}

    //객체 포인터
    //CirclePointer donut;
    //CirclePointer pizza(30);

    ////객체 이름으로 멤버 접근
    //CirclePointer *p;
    //p = &donut;
    //cout << p->getArea() << endl; //donut의 getArea() 호출
    //cout << (*p).getArea() << endl; //donut의 getArea() 호출

    //p = &pizza;
    //cout << p->getArea() << endl; //pizza의 getArea() 호출
    //cout << (*p).getArea() << endl; //pizza의 getArea() 호출



    //파일 분리
    /*Circle donut;
    double area = donut.getArea();
    cout << " donut 면적은 :";
    cout << area << endl;

    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적은: ";
    cout << area << endl;*/
}


