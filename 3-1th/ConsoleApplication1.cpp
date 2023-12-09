// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//예제 2
class Rectangle {
public:
    int width, height;
    int getArea();
};

int Rectangle::getArea() {
    return width * height;
}


//예제 1
class Circle {
public:
    int radius;
    double getArea();
};

double Circle:: getArea() {
        return 3.14 * radius * radius;
    };

int main()
{
    //예제 2
    cout << "예제 2 \n" << endl;
    Rectangle rect;
    rect.width = 10;
    rect.height = 20;
    cout << "사각형 면적: " << rect.getArea() << endl;


    //예제 1
    cout << "예제 1 \n" << endl;
    Circle donut;
    donut.radius = 10;
    double area = donut.getArea();
    cout << "크기: " << area << endl;

    Circle pizza;
    pizza.radius = 30;
    double area2 = pizza.getArea();
    cout << "크기: " << area2 << endl;


    //포인터 예제
    /*int b = 10;
    int* pb = &b;

    cout << "b의 값" << b << endl;
    cout << "b의 주소 값" << pb << endl << endl;


    char a = 10;
    char* p = &a;

    cout << "a의 값" << a << endl;
    cout << "a의 주소 값" << *p;*/
}

