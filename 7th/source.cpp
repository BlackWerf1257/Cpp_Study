#include <iostream>
using namespace std;

//디폴트 매개 변수
void drawStar(int a = 3); //원형 선언
void msg(int id, string text = "");
void drawStar(int a) {
	//함수 구현
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << endl;
}
void msg(int id, string text) { cout << id << ' ' << text << endl; }

//생성자/소멸자의 함수 중복
class Circle2 {
	private:
		int radius;

	public:
		Circle2() { radius = 1; cout << radius << endl; }
		Circle2(int r) { radius = r; cout << radius << endl;
		}
};
class stringClass {
	public:
		stringClass ();
		stringClass(string& str);
		stringClass(char* s);
};



//함수 중복의 예2

//두 수중 큰 수 반환
int compare(int a, int b) 
{ if (a > b) return a; 
  else return b; }
//배열에서 가장 큰 수 반환
int compare(int a[], int size) {
	int result = a[0];
	for (int i = 1; i < size; i++)
		if (result < a[i]) result = a[i];
	return result;
}

//함수 중복의 예1
int sum(int a, int b, int c) { return a + b + c; }
double sum(double a, double b) { return a + b; }
int sum(int a, int b) { return a + b; }
int sum(int a) { return a; }

//참조 리턴
char& find(char s[], int index) { return s[index]; }

 //참조에 의한 객체 전달
class Circle
{
	private:
		int radius;
	public:
		Circle():Circle(1){}
		Circle(int radius) {
			this->radius = radius;
			//radius = r;
			cout << "생성자 실행 radius= " << radius << endl;
		}


		~Circle() { cout << "소멸자 실행 radius = " << radius << endl; }
		double getArea() { return 3.14 * radius * radius; }
		int getRadius() { return radius; }
		void setRadius(int radius) { this->radius = radius; }

};

//참조를 이용한 반환
bool average(int a[], int size, int& avg)
{
	if (size <= 0)
		return false;
	
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += a[i];

		avg = sum / size;
		return true;
}
void increaseCircle(Circle& c)
{
	int r = c.getRadius();
	c.setRadius(r + 1);
}


int main() {
	//디폴트 매개변수
	drawStar();
	drawStar(5);
	msg(5);
	msg(10, "Hello");

	//생성자/소멸자의 함수 중복
	/*Circle2 donut;
	Circle2 pizza(30);

	//빈 문자열 가진 스트링 객체 생성
	stringClass str;
	//문자열 가진 스트링 객체 생성
	stringClass address('충남 천안시 백석대학교');
	//address 문자열 복사한 별도의 copyAddress 생성
	string copyAddress(address); */
	
	
	//함수 중복의 예2
	/*int array[5] = { 2,10,7,8,5 };
	cout << "두 수중 큰 수 : " << compare(5, 7) << endl;
	cout << "배열에서 제일 큰 수 : " << compare(array, 5) << endl;*/


	//함수 중복의 예1
	/*cout << sum(1, 2, 3);
	cout << sum(1.1, 2.2);
	cout << sum(4, 5);
	cout << sum(5);*/

	//참조 리턴
	char name[] = "Mike";
	cout << name << endl;
	find(name, 0) = 'S'; //name[0]=S로 변경
	cout << name << endl;

	char& ref = find(name, 2);
	ref = 't'; //name = "Site
	cout << name << endl;


	//참조에 의한 객체 전달
	/*Circle ring(30);
	increaseCircle(ring);
	cout << ring.getRadius() << endl;*/

	//참조를 이용한 반환
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개 변수 오류 " << endl;
	if (average(x, -2, avg)) cout << "평균은 " << avg << endl;
	else cout << "매개변수 오류 " << endl;
}
