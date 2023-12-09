#include <iostream>
using namespace std;

//상속 2
class Shape2 {
	int x, y; //한 점 (x,y)의 좌표값
	int type; //0: 미지정 1: 원 2: 사각형
public:
	Shape2() { type = 0; }
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << '(' << x << ',' << y << ')' << endl; }
};
class Circle_Inheritance2 : public Shape2 {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showCircle();
};
void Circle_Inheritance2::showCircle() {
	cout << color << ':';
	showPoint(); //Shape2의 showPoint 호출
}


// 상속 1
class Shape1 {
	int x, y; //한 점 (x,y)의 좌표값
	int type; //0: 미지정 1: 원 2: 사각형
public:
	Shape1() { type = 0; }
	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() { cout << '(' << x << ',' << y << ')' << endl; }
};
class Circle_Inheritance : public Shape1 {
	string color;
public:
	void setColor(string color) { this->color = color; }
	void showCircle();
};
void Circle_Inheritance::showCircle() {
	cout << color << ':';
	showPoint(); //Shape1의 showPoint 호출
}

//참조 반환하는 << 연산자 중복
class Circle7 {
	int radius, price;

public:
	Circle7(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
	void show();
	Circle7& operator << (int n);
};
void Circle7::show() { cout << "radius=" << radius << ',' << "price=" << price << endl; }
Circle7& Circle7::operator<< (int n) {
	radius += n;
	price += n;
	cout << "inputed value : " << n << endl;
	return *this; //이 객체의 참조 리턴
}

//Friend 이용한 ++ 연산자 중복
class Circle6 {
	int radius;
	int price;
public:
	Circle6(int radius = 0, int price = 0) {
		this->radius = radius; this->price = price;
	}
	void show();
	friend Circle6& operator++(Circle6& op);
	friend Circle6 operator++(Circle6& op, int x);
};
void Circle6::show() {
	cout << "radius=" << radius << ',' << "price=" << price << endl;
}
Circle6& operator++(Circle6& op) {// 전위 연산자
	op.radius++;
	op.price++;
	return op; // 연산 결과 리턴
}
Circle6 operator++(Circle6& op, int x) {// 후위 연산자
	Circle6 tmp = op; // 변경하기 전의 op 상태 저장
	op.radius++;
	op.price++;
	return tmp; // 변경 이전의 op 리턴
}


//Friend 이용한 + 연산자 중복
// 4/4
class Circle5 {
	int radius, price;
public:
	Circle5(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
	void show();
	friend Circle5 operator+ (int op1, Circle5 op2); //프렌드 선언
};
void Circle5::show() { cout << "radius=" << radius << ',' << "price=" << price << endl; }
	Circle5 operator+(int op1, Circle5 op2) {
	Circle5 tmp; //임시 객체 생성
	tmp.radius = op1 + op2.radius; //radius 더하기
	tmp.price = op1 + op2.price; //price 더하기
	return tmp; //임시 객체 리턴
}


//2/4
class Circle4 {
	int radius, price;
public:
	Circle4(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
	void show();
	friend Circle4 operator+ (Circle4 op1, Circle4 op2); //프렌드 선언
};
void Circle4::show() { cout << "radius=" << radius << ',' << "price=" << price << endl; }
Circle4 operator+(Circle4 op1, Circle4 op2) {
	Circle4 tmp; //임시 객체 생성
	tmp.radius = op1.radius + op2.radius; //radius 더하기
	tmp.price = op1.price + op2.price; //price 더하기
	return tmp; //임시 객체 리턴
}


class Circle3 {
	int radius, price;

public:
	Circle3(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
	void show();
	Circle3 operator++ (int x); //후위 ++ 연산자 함수 선언
};
	void Circle3::show() { cout << "radius=" << radius << ',' << "price=" << price << endl; }
	Circle3 Circle3::operator++(int x) { Circle3 tmp = *this; //증가 이전 객체 상태 저장
	radius++;
	price++;
	return tmp; //증가 이전 객체 상태 리턴
	}

class Circle2 {
	int radius;
	int price;

public:
	Circle2(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
	void show();
	bool operator! (); //!연산자 중복
};
	void Circle2::show() { cout << "radius=" << radius << ',' << "price=" << price << endl; }
	bool Circle2::operator!() {
		if (radius == 0 && price == 0) return true;
		else return false;
	}

class Circle {
	int radius, price;

	public:
		Circle(int radius=0, int price = 0) { this->radius = radius; this->price = price; }
		void show();
		Circle& operator++(); //++ 연산자 함수 선언
};
	void Circle::show() { cout << "radius=" << radius << ',' << "price=" << price << endl; }
	Circle& Circle::operator++() {
		radius++;
		price++;
		return *this;
	}


int main()
{
	char v = 10;
	char* p;
	p = &v;
	cout << v << endl;
	//cout << p;


	//상속2


	//상속
	//Shape1 p; //기본 클래스의 객체 생성
	//Circle_Inheritance cp; //파생 클래스의 객체 생성
	//cp.set(3, 4); //기본 클래스의 멤버 호출
	//cp.setColor("Red"); //파생 클래스의 멤버 호출
	//cp.showCircle();

	//참조 반환하는 << 연산자 중복
	/*Circle7 a(1, 2);
	a << 3 << 5 << 6;
	a.show();*/

	//Friend 이용한 ++ 연산자 중복
	//Circle6 a(3, 5), b;
	//b = ++a; //전위 ++ 연산자
	//a.show();
	//b.show();
	//b = a++; //후위 ++ 연산자
	//a.show();
	//b.show();

	//Friend 이용한 + 연산자 중복
	// 4/4
	/*Circle5 a(3, 5), b;
	a.show();
	b.show();
	b = 2 + a;
	a.show();
	b.show();*/

	//2/4
	/*Circle4 a(3, 5), b(4, 6), c;
	c = a + b;
	a.show();
	b.show();
	c.show();*/

	//전위 ! 연산자 중복
	/*Circle2 a(0, 0), b(5, 5);
	if (!a) cout << "원 a의 크기와 가격이 0" << endl;
	else cout << "원 a의 크기와 가격이 0이 아님" << endl;
	if (!b) cout << "원 b의 크기와 가격이 0" << endl;
	else cout << "원 b의 크기와 가격이 0이 아님" << endl;*/

	//후위 ++ 연산자
	/*Circle3 a(3, 5), b;
	a.show();
	b.show();
	b = a++;
	a.show();
	b.show();*/

	//전위 ++ 연산자
	/*Circle a(1, 2), b;
	a.show();
	b.show();
	b = ++a;
	a.show();
	b.show();*/
}
