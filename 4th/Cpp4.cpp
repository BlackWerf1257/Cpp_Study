// Cpp4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

//객체 포인터
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



//구조체
struct Circle {
	private:
		int radius;
	public:
		Circle(int r) { radius = r; }
		double getArea();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}



//인라인 함수
int divide(int x) {
	return (x / 2);
}


//소멸자 사용
//class Circle {
//	public:
//		int radius;
//
//		Circle();
//		Circle(int r);
//		~Circle(); //소멸자
//		double getArea();
//};
//Circle::Circle() {
//	radius = 5;
//	cout << "지름이 " << radius * 2 << "인 원 생성" << endl;
//}
//Circle::Circle(int r) {
//	radius = 5;
//	cout << "지름이 " << r * 2 << "인 원 생성" << endl;
//}
//Circle::~Circle() {
//	cout << "지름이 " << radius * 2 << "인 원 소멸" << endl;
//}
//double Circle::getArea() {
//	return 3.14 * radius * radius;
//}



//객체의 생성과 소멸
//Circle globalDonut(1000);
//Circle globalPizza(2000);
//void f() {
//	Circle fDonut(100);
//	Circle fPizza(200);
//}

int main()
{
	//객체 포인터
	CirclePointer donut;
	CirclePointer pizza(30);

	//객체 이름으로 멤버 접근
	cout << donut.getArea() << endl;

	//객체 포인터로 멤버 접근
	CirclePointer *p;
	p = &donut;
	cout << p->getArea() << endl; //donut의 getArea 호출
	cout << (*p).getArea() << endl; //donut의 getArea 호출

	p = &pizza;
	cout << p->getArea() << endl; // pizza의 getArea 호출
	cout << (*p).getArea() << endl; // pizza의 getArea 호출




	//구조체
	/*Circle donut(5);
	cout << "면적은 " << donut.getArea();*/



	//인라인 함수
	//int sum = 0;


	//객체의 생성과 소멸
	/*Circle maninDonut();
	Circle mainPizza(30);
	f();*
	



	//소멸자 사용
	/*Circle donut;
	Circle pizza(10);
	return 0;*/
}


//소멸자 테스트
//class Circle {
//    Circle();
//    Circle(int r);
//    ~Circle();
//};
//Circle::~Circle(){}




