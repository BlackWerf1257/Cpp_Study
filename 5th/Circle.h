//헤더 중복 처리 방법
#ifndef  Circle_H
#define Circle_H

class Circle {
	private:
		int radius;
	public:
		Circle();
		Circle(int r);
		double getArea();
};

#endif
