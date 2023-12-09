using namespace std;
#include <iostream>
//객체 생성 소멸
class Circle3
{
public:
    int radius;
    Circle3();
    Circle3(int r);
    ~Circle3();
    double getArea();
};
Circle3::Circle3() {
    radius = 1;
    cout << "반지름 " << radius << " 원 생성" << endl;
}
Circle3::Circle3(int r) {
    radius = r;
    cout << "반지름 " << radius << " 원 생성" << endl;
}
Circle3::~Circle3() {
    cout << "반지름 " << radius << " 원 소멸" << endl;
}
double Circle3::getArea() {
    return 3.14 * radius * radius;
}
//객체 생성과 소멸
Circle3 globalDonut(1000);
Circle3 globalPizza(2000);
void func() {
    Circle3 fDonut(100);
    Circle3 fPizza(200);
}



//소멸자의 사용
class Circle2 {
public: int radius;

      Circle2();
      Circle2(int r);
      ~Circle2(); //소멸자
      double getArea();
};
Circle2::Circle2() {
    radius = 5;
    cout << "지름  " << radius * 2 << " 원 생성" << endl;
}
Circle2::Circle2(int r) {
    radius = r;
    cout << "지름  " << radius * 2 << " 원 생성" << endl;
}
Circle2::~Circle2() {
    cout << "지름 " << radius * 2 << " 원 소멸" << endl;
}
double Circle2::getArea() {
    return 3.14 * radius * radius;
}




//기본 생성자
class Rectangle
{
public:
    int width, height;
    Rectangle();
    Rectangle(int w, int h);
    Rectangle(int length);
    bool isSquare;
};
Rectangle::Rectangle() { width = height = 1; }
Rectangle::Rectangle(int w, int h) { width = w, height = h; }
Rectangle::Rectangle(int length) { width = height = length; }
//bool isSquare() {
//    if (width = height) return true;
//    else return 
//}


//위임 생성자 이용 멤버변수 초기화
class Point 
{
    int x, y;
public:
    Point();
    Point(int a, int b);
    void Show() { cout << "(" << x << "," << y << ")" << endl; };
};
Point::Point() : Point(0, 0) {} //위임 생성자
Point::Point(int a, int b) : x(a), y(b) {}


class Circle
{
public:
    int radius;
    Circle(); //위임 생성자
    Circle(int r); //타겟 생성자
    double getArea();
};
Circle::Circle() {
    radius = 10;
    cout << "반지름 " << radius << " 원 생성" << endl;
}
Circle::Circle(int r) {
    radius = r;
    cout << "반지름 " << radius << "원 생성" << endl;
}
double Circle::getArea() {
    return 3.14 * radius * radius;
}

//생성자 호출 생성자
//Circle::Circle():Circle(1) {} //위임 생성자
//Circle::Circle(int r) //타겟 생성자
//{
//    radius = r;
//    cout << "반지름" << radius << "원 생성" << endl;
//}



int main()
{
    Circle mainDonut;
    Circle mainPizza(30);
    func();

    //소멸자 사용
    /*Circle2 donut;
    Circle2 pizza(10);
    return 0;*/

    //기본 생성자3
    Rectangle rect1, rect2(3, 5), rect3(3);
    /*if (rect1.isSquare()) cout << "rect1은 정사각형" << endl;
    if (rect2.isSquare()) cout << "rect2은 정사각형" << endl;
    if (rect3.isSquare()) cout << "rect3은 정사각형" << endl;*/
    
    //위임 생성자 이용한 멤버변수 초기화
    /*Point origin;
    Point target(10, 20);
    origin.Show();
    target.Show();*/

    Circle donut;
    double area = donut.getArea();
    cout << "면적 " << area << endl;
    Circle pizza(30);
    area = pizza.getArea();
    cout << "pizza 면적 : " << area << endl;

    //생성자 예제
    /*Circle donut;
    double area = donut.getArea();
    cout << "면적 : " << area << endl;

    Circle pizza(300);
    area = pizza.getArea();
    cout << "면적 : " << area << endl;*/

}
