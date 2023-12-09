#include <iostream>
using namespace std;

//다른 타입과 + 연산자 중복
class Circle6 {
    int radius;
    int price;

public:
    Circle6(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
    void show();
    Circle6 operator+ (Circle6 op2); //+연산자 함수 선언
};
void Circle6::show() { cout << "radius = " << radius << " , " << "price=" << price << endl; }

Circle6 Circle6::operator+(Circle6 op2)
{
    Circle6 tmp; //임시 객체
    tmp.radius = radius + op2.radius; //radius 더하기
    tmp.price = price + op2.price;
    return tmp;
}


//== 연산자 중복
class Circle5 {
    int radius;
    int price;

public:
    Circle5(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
    void show();
    bool operator==(Circle5 op2);
};
void Circle5::show() { cout << "radius = " << radius << " , "  << "price = " << price << endl; }

bool Circle5::operator==(Circle5 op2)
{
    Circle5 tmp; //임시 객체
    if (radius == op2.radius && price == op2.price) return true;
    else return false;
}

//이항 연산자 + 중복
class Circle4 {
    int radius;
    int price;

    public:
        Circle4(int radius = 0, int price = 0) { this->radius = radius; this->price = price; }
        void show();
        Circle4 operator+ (Circle4 op2); //+연산자 함수 선언
};
void Circle4::show() { cout << "radius = " << radius << " , "  << "price=" << price << endl; }

Circle4 Circle4::operator+(Circle4 op2)
{
    Circle4 tmp; //임시 객체
    tmp.radius = this->radius + op2.radius; //radius 더하기
    tmp.price = this->price + op2.price;
    return tmp;
}


//Friend - 다른 클래스의 모든 멤버 함수
class Rectangle3;
class Rectangle3Manager {
    public:
        bool equals(Rectangle3 r, Rectangle3 s);
        void copy(Rectangle3& dest, Rectangle3& src);
};
class Rectangle3 {
    int width, height;
    public:
        Rectangle3(int width, int height) { this->width = width; this->height = height; }
        friend Rectangle3Manager;
};
bool Rectangle3Manager::equals(Rectangle3 r, Rectangle3 s) { if (r.width == s.width && r.height == s.height) return true; else return false; }

void Rectangle3Manager::copy(Rectangle3& dest, Rectangle3& src) { dest.width = src.width; dest.height = src.height; }


//Friend - 다른 클래스의 모든 멤버 함수
class Rectangle2;
class Rectangle2Manager { // RectangleManager 클래스 선언
public:
    bool equals(Rectangle2 r, Rectangle2 s);
};
class Rectangle2 { // Rectangle 클래스 선언
    int width, height;
public:
    Rectangle2(int width, int height) {
        this->width = width; this->height = height;
    }
    friend bool Rectangle2Manager::equals(Rectangle2 r, Rectangle2 s);
};
bool Rectangle2Manager::equals(Rectangle2 r, Rectangle2 s) {
    if (r.width == s.width && r.height == s.height) return true;
    else return false;


    //Friend
    class Rectangle;
    bool equals(Rectangle r, Rectangle s);
    class Rectangle {
        int width, height;
    public:
        Rectangle(int width, int height)
        {
            this->width = width;
            this->height = height;
        }
        friend bool equals(Rectangle r, Rectangle s);
    };
    bool equals(Rectangle r, Rectangle s); {
        if (r.width == s.width && r.height == s.height)
            return true;
        else
            return false;
    }
}


//Static
class Circle {
    private:
        static int numOfCircles;
        int radius;
    public:
        Circle(int r = 1);
        ~Circle() { numOfCircles--; } //생성된 원의 수 감소
        static int getNumOfCircles() { return numOfCircles; };
};
Circle::Circle(int r) {
    radius = r;
    numOfCircles++; // 생성된 원의 수 감소
}
int Circle::numOfCircles = 0; //0으로 초기화


int main()
{
    //다른 타입과 + 연산자 중복
    Circle6 a(3, 5), b;
    a.show();
    b.show();
    b = a + 2; //객체와 정수 더하기
    a.show();
    b.show();


    //== 연산자 중복
    /*Circle5 a(3, 5), b(5, 3);
    a.show();
    b.show();
    if (a == b)
        cout << " 두 원이 같다." << endl;
    else
        cout << " 두 원이 같지않다." << endl;*/

    //이항 연산자 + 중복
    /*Circle4 a(3, 5), b(4, 6), c;
    c = a + b;
    a.show();
    b.show();
    c.show();*/

    //Friend - 다른 클래스의 모든 멤버 함수
    /*Rectangle3 a(3, 4), b(5, 6);
    Rectangle3Manager manage;
    manage.copy(b, a);
    if (manage.equals(a, b))
        cout << "Equal" << endl;
    else
        cout << "Not equal" << endl;*/

    //Friend - 다른 클래스의 멤버 변수
    /*Rectangle2 a(1, 2), b(3, 4);
    Rectangle2Manager manage;
    if (manage.equals(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;*/

    //Friend
    /*Rectangle a(1, 2), b(3, 4);
    if (equals(a, b))
        cout << "Equal" << endl;
    else
        cout << "Not Equal" << endl;*/

    //Static
    //Circle* p = new Circle[10]; //10개 생성자 실행
    //cout << "생성된 원의 수 = " << Circle::getNumOfCircles() << endl;
    //delete[] p; //10개의 소멸자 실행
    //cout << "생성된 원의 수 = " << Circle::getNumOfCircles() << endl;
    //Circle a; //생성자 실행
    //cout << "생성된 원의 수 = " << Circle::getNumOfCircles() << endl;
    //Circle b; //생성자 실행
    //cout << "생성된 원의 수 = " << Circle::getNumOfCircles() << endl;
}
