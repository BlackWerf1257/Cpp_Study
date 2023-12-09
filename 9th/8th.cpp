#include <iostream>
using namespace std;
//Freind -다른 클래스의 멤버 함수
class Rectangle2;
class Rectangle2Manager {
	public:
		bool equals(Rectangle2 r, Rectangle2 s);
};
class Rectangle2 {
	int width, height;
	public:
		Rectangle2(int width, int height) { this->width = width; this->height = height; }
		friend bool Rectangle2Manager::equals(Rectangle2 r, Rectangle2 s);
};
bool Rectangle2Manager::equals(Rectangle2 r, Rectangle2 s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}


//Freind - 외부 전역 함수
class Rectangle;
bool equals(Rectangle r, Rectangle s);
class Rectangle {
	int width, height;
public:
	Rectangle(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rectangle r, Rectangle s);
};
bool equals(Rectangle r, Rectangle s) {
	if (r.width == s.width && r.height == s.height)
		return true;
	else
		return false;
}


//Static 활용 2
class Circle {
private:
	static int numOfCircles;
	int radius;
public:
	Circle(int r = 1);
	~Circle() { numOfCircles--; } //생성된 원의 개수 감소
	static int getNumOfCircles() { return numOfCircles; }
};
Circle::Circle(int r) {
	radius = r;
	numOfCircles++;
}
int Circle::numOfCircles = 0;  //0으로 초기화


//Static 활용 1
class Math {
	public:
		static int abs(int a) { return a > 0 ? a : -a; }
		static int max(int a, int b) { return a > b ? a : b; }
		static int min(int a, int b) { return a > b ? b : a; }
};



class Person2 {

public:
	int money; //개인 소유의 돈
	int id;
	int myAccount;

	void addMoney(int money) { this->money += money; }
	static int sharedMoney; //공금
	static void addShared(int n) { sharedMoney += n;}
};
int Person2::sharedMoney = 10; //10으로 초기화


class Person {
		
		  public:
			  int money; //개인 소유의 돈
			  int id;
			  int myAccount;

			  void addMoney(int money) { this->money += money; }
			  static int sharedMoney; //공금
			  static void addShared(int n) { sharedMoney += n; }
};	
int Person::sharedMoney = 10; //10으로 초기화


int main() {
	//Friend - 다른 클래스의 멤버 함수
	/*Rectangle2 a(1, 2), b(3, 4);
	Rectangle2Manager manage;
	if (manage.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;*/

	//Friend - 외부 전역 변수
	/*Rectangle a(1, 2), b(3, 4);
	if (equals(a, b))
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;*/

	//Static 활용 2
	//Circle* p = new Circle[10]; //10개 생성자 실행
	//cout << "생성된 원의 개수 = " << Circle::getNumOfCircles() << endl;
	//delete[] p; //10개의 소멸자 실행
	//cout << "생성된 원의 개수 = " << Circle::getNumOfCircles() << endl;
	//Circle a; //생성자 실행
	//cout << "생성된 원의 개수 = " << Circle::getNumOfCircles() << endl;
	//Circle b; //생성자 실행
	//cout << "생성된 원의 개수 = " << Circle::getNumOfCircles() << endl;

	//Static 활용 1
	/*cout << Math::abs(-1) << endl;
	cout << Math::max(10, 20) << endl;
	cout << Math::min(-5, 5) << endl;*/

	//예제 5
	//Person2::addShared(50); //공금에 접근해 60으로 설정
	//cout << Person2::sharedMoney << endl;
	//Person2 kim;
	//kim.money = 100;
	//kim.sharedMoney = 200; //공금 : 200
	//
	//Person2::sharedMoney = 300; //공금 : 300
	//Person2::addShared(100); // 공금 ㅣ 400
	//cout << kim.money << ' ' << Person2::sharedMoney << endl;

	//예제 3
	//Person kim;
	//kim.money = 100; //Kim의 개인돈 = 100
	//kim.sharedMoney = 200; //공금이라는 static 변수에 접근해 200으로 설정

	//Person lee;
	//lee.money = 150; //lee의 개인돈  = 150
	//lee.addMoney(200);
	//lee.addShared(200);

	//cout << kim.money << ' ' << lee.money << endl;
	//cout << kim.sharedMoney << ' ' << lee.sharedMoney << endl;
}