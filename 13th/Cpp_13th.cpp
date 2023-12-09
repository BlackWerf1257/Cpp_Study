#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 2개의 제네릭 타입 가진 클래스
template <class T1, class T2>
class GClass {
    T1 data1;
    T2 data2;

public:
    GClass();
    void set(T1 a, T2 b);
    void get(T1& a, T2& b);;
};
template <class T1, class T2>
GClass<T1, T2>::GClass() {
    data1 = 0;
    data2 = 0;
}
template < class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
    data1 = a;
    data2 = b;
}
template <class T1, class T2>
void GClass<T1, T2>::get(T1& a, T2& b) {
    a = data1;
    b = data2;
}


///포인터를 이용한 제네릭 클래스
template <class T>
class MyStack3 {
    int tos; //스택의 Top
    T data[100]; //크기 100짜리 스택

public:
    MyStack3();
    void push(T element);  //element를 data에 삽입
    T pop();
};
template <class T>
MyStack3<T>::MyStack3() {//생성자
    tos = -1; //스택은 비어있음
}
template <class T>
void MyStack3<T>::push(T element) {
    if (tos == 99) {
        cout << "stack full";
        return;
    }

    tos++;
    data[tos] = element;
}

template<class T>
T MyStack3<T>::pop() {
    T retData;
    if (tos == -1) {
        cout << "stack empty";
        return 0; //오류 표시
    }
    retData = data[tos--];
    return retData;
}
class Point3 {
    int x, y;
public:
    Point3(int x = 0, int y = 0) { this->x = x; this->y = y; }
    void show() { cout << '(' << x << ',' << y << ')' << endl; }
};



//제네릭 클래스 활용
template <class T>
class MyStack2 {
    int tos; //스택의 Top
    T data[100]; //크기 100짜리 스택

public:
    MyStack2();
    void push(T element); //element를 data[] 배열에 삽입
    T pop(); //스택의 top 위치의 데이터를 data[] 배열에서 리턴
};
template <class T>
MyStack2<T>::MyStack2(){
    tos = -1;
}

template <class T>
void MyStack2<T>::push(T element) {
    if (tos == 99) {
        cout << "stack full";
        return;
    }
    tos++;
    data[tos] = element;
}
template <class T>
T MyStack2<T>::pop() {
    T retData;
    if (tos == -1) {
        cout << "stack empty";
        return 0; //오류 표시
    }

    retData = data[tos--];
    return retData;
}

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
    void show() {
        cout << '(' << x << ',' << y << ')' << endl;
    }
};

//제네릭 클래스 선언
template <class T>
class MyStack {
    int tos;
    T data[100]; //T타입의 배열

public:
    MyStack();
    void push(T element);
    T pop();
};

//제네릭 클래스 구현
template <class T>
void MyStack<T>::push(T element) { //매개 변수에 템플릿 활용
    if (tos == 99) {
        cout << "stack full";
        return;
    }
    tos++;
    data[tos] = element;
}
template <class T> T MyStack<T>::pop() {
    T retData;
    if (tos == -1) {
        cout << "stack empty";
        return 0; //오류 표시
    }

    retData = data[tos--];
    return retData;
}

////////////////////////////////////
//템플릿의 char형 구체화 문제 - 해결버전(기존 예제는 (int) 제거)
template <class T>
void print(T array[], int n) {
    for (int i = 0; i < n; i++)
        cout << (int)array[i] << '\t';
    cout << endl;
}

//2개
template <class T1, class T2>
void myCopy(T1 src[], T2 dest[], int n) //src[]의 n개 원소를 dest[]에 복사
{
    for (int i = 0; i < n; i++)
        dest[i] = (T2)src[i]; //T1타입의 값을 T2 타입으로 변경
}

int main()
{
    //iterator 예제
    //vector<int> vec;
    //vec.push_back(1);
    //vec.push_back(2);
    //vec.push_back(3);
    //vector<int>::iterator iter; //벡터 v의 원소에 대한 포인터 iter 선언
    //for (iter = vec.begin(); iter != vec.end(); iter++) { //iterator를 이용해 모든 원소 탐색
    //    int n = *iter; //iter가 가르키는 원소값 리턴
    //    n = n * 2;
    //    *iter = n; //iter가 가르키는 원소에 값 쓰기
    //}
    //for (iter = vec.begin(); iter != vec.end(); iter++)
    //    cout << *iter << ' ';
    //cout << endl;

    //Vector 예제 2
    /*vector<string> sv;
    string name;
    cout << "이름 4개 입력" << endl;
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ">>";
        getline(cin, name);
        sv.push_back(name);
   }
    name = sv.at(0); //벡터의 첫 원소
    for (int i = 1; i < sv.size(); i++) {
        if (name < sv[i]) //sv[i]의 문자열이 name보다 사전에서 뒤에 나옴
            name = sv[i]; //name을 sv[i]의 문자열로 변경
    }
    cout << "사전에서 가장 뒤에 나오는 이름 : " << name << endl;*/

    //Vector 예제 1
    /*vector<int> v; //정수만 삽입 가능한 벡터 생성
    v.push_back(1); //벡터에 정수 1 삽입
    v.push_back(2);
    v.push_back(3);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;

    v[0] = 10; //벡터의 첫번째 원소를 10으로 변경
    int n = v[2]; //n에 3이 저장
    v.at(2) = 5; //벡터의 3번째 원소를 5로 변경

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl; */

    //2개의 제네릭 타입 가진 클래스
    /*int a;
    double b;
    GClass<int, double> x;
    x.set(2, 0.5);
    x.get(a, b);
    cout << "a=" << a << '\t' << "b=" << b << endl;

    char c;
    float d;
    GClass<char, float> y;
    y.set('m', 12.5);
    y.get(c, d);
    cout << "c=" << c << '\t' << "d=" << d << endl;*/


    //포인터를 이용한 제네릭 클래스
    MyStack3<int*> ipStack;
    int* p = new int[3];
    for (int i = 0; i < 3; i++)
        p[i] = i * 10; //0,10,20으로 초기화
    ipStack.push(p); //포인터 push

    int* q = ipStack.pop(); //포인터 pop
    for (int i = 0; i < 3; i++)
        cout << q[i] << ' ';
    cout << endl;
    delete[] p;

    MyStack3<Point> pointStack; //Point 객체 저장 스택
    Point a(2, 3), b;
    pointStack.push(a); //Point 객체 a 푸시, 복사되어 저장
    b = pointStack.pop(); //point 객체 pop
    b.show(); 

    MyStack3<Point*> pStack;
    pStack.push(new Point(10, 20));
    Point* pPoint = pStack.pop(); //Point 객체의 포인터 Pop
    pPoint->show(); //Point 객체 출력

    MyStack3<string> stringStack; //문자열만 저장하는 스택
    string s = "C++";
    stringStack.push(s);
    stringStack.push("Java");
    cout << stringStack.pop() << ' ';
    cout << stringStack.pop() << endl;


    //제네릭 클래스의 활용 - 예제
    //MyStack2<int> iStack; //int만 저장하는 스택
    //iStack.push(3);
    //cout << iStack.pop() << endl;

    //MyStack2<double> dStack; //double만 저장
    //dStack.push(3.5);
    //cout << dStack.pop() << endl;

    //MyStack2<char>* p = new MyStack2<char>(); //char만 저장
    //p->push('a');
    //cout << p->pop() << endl;
    //delete p;


    // 템플릿을 이용한 제네릭 클래스 활용
    /*MyStack<int> iStack;
    MyStack<double> dStack;

    iStack.push(3);
    int n = iStack.pop();

    dStack.push(3.5);
    double d = dStack.pop();*/


    //템플릿의 char형 구체화 문제
    //int x[] = { 1,2,3,4,5 };
    //double d[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    //print(x, 5);  // 템플릿 T가 int 타입으로 구체화
    //print(d, 5);

    //char c[5] = { 1, 2, 3, 4, 5 };
    //print(c, 5); // 템플릿 T가 char 타입으로 구체화


    // 2개 제너릭 타입 갖는 템플릿
    /*int x[] = {1,2,3,4,5};
    double d[5];
    char c[5] = { 'H', 'e', 'l','l','o' }, e[5];

    myCopy(x, d, 5); //int x[]의 원소 5개를 double d[]에 복사
    myCopy(c, e, 5); //char c[]의 원소 5개를 char e[]에 복사
    for (int i = 0; i < 5; i++) 
        cout << d[i] << ' '; //d[] 출력
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << e[i] << ' '; //e[] 출력
    cout << endl;*/
}
