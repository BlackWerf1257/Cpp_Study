#include <iostream>
using namespace std;

//����Ʈ �Ű� ����
void drawStar(int a = 3); //���� ����
void msg(int id, string text = "");
void drawStar(int a) {
	//�Լ� ����
	for (int i = 0; i < a; i++)
		cout << '*';
	cout << endl;
}
void msg(int id, string text) { cout << id << ' ' << text << endl; }

//������/�Ҹ����� �Լ� �ߺ�
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



//�Լ� �ߺ��� ��2

//�� ���� ū �� ��ȯ
int compare(int a, int b) 
{ if (a > b) return a; 
  else return b; }
//�迭���� ���� ū �� ��ȯ
int compare(int a[], int size) {
	int result = a[0];
	for (int i = 1; i < size; i++)
		if (result < a[i]) result = a[i];
	return result;
}

//�Լ� �ߺ��� ��1
int sum(int a, int b, int c) { return a + b + c; }
double sum(double a, double b) { return a + b; }
int sum(int a, int b) { return a + b; }
int sum(int a) { return a; }

//���� ����
char& find(char s[], int index) { return s[index]; }

 //������ ���� ��ü ����
class Circle
{
	private:
		int radius;
	public:
		Circle():Circle(1){}
		Circle(int radius) {
			this->radius = radius;
			//radius = r;
			cout << "������ ���� radius= " << radius << endl;
		}


		~Circle() { cout << "�Ҹ��� ���� radius = " << radius << endl; }
		double getArea() { return 3.14 * radius * radius; }
		int getRadius() { return radius; }
		void setRadius(int radius) { this->radius = radius; }

};

//������ �̿��� ��ȯ
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
	//����Ʈ �Ű�����
	drawStar();
	drawStar(5);
	msg(5);
	msg(10, "Hello");

	//������/�Ҹ����� �Լ� �ߺ�
	/*Circle2 donut;
	Circle2 pizza(30);

	//�� ���ڿ� ���� ��Ʈ�� ��ü ����
	stringClass str;
	//���ڿ� ���� ��Ʈ�� ��ü ����
	stringClass address('�泲 õ�Ƚ� �鼮���б�');
	//address ���ڿ� ������ ������ copyAddress ����
	string copyAddress(address); */
	
	
	//�Լ� �ߺ��� ��2
	/*int array[5] = { 2,10,7,8,5 };
	cout << "�� ���� ū �� : " << compare(5, 7) << endl;
	cout << "�迭���� ���� ū �� : " << compare(array, 5) << endl;*/


	//�Լ� �ߺ��� ��1
	/*cout << sum(1, 2, 3);
	cout << sum(1.1, 2.2);
	cout << sum(4, 5);
	cout << sum(5);*/

	//���� ����
	char name[] = "Mike";
	cout << name << endl;
	find(name, 0) = 'S'; //name[0]=S�� ����
	cout << name << endl;

	char& ref = find(name, 2);
	ref = 't'; //name = "Site
	cout << name << endl;


	//������ ���� ��ü ����
	/*Circle ring(30);
	increaseCircle(ring);
	cout << ring.getRadius() << endl;*/

	//������ �̿��� ��ȯ
	int x[] = { 0,1,2,3,4,5 };
	int avg;
	if (average(x, 6, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű� ���� ���� " << endl;
	if (average(x, -2, avg)) cout << "����� " << avg << endl;
	else cout << "�Ű����� ���� " << endl;
}
