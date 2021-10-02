#include <iostream>
using namespace std;

#define tab "\t"

//�������� ���������
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	double distance(Point Other)
	{
		double x_distance = this->x - Other.x;
		double y_distance = this->y - Other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
};

double distance(Point A, Point B)
{
	//double x_distance = B.get_x() - A.get_x();
	//double y_distance =B.get_y()-A.get_y();
	double distance = sqrt(pow(A.get_x()-B.get_x(),2)+ pow(A.get_y()-B.get_y(),2));
	return distance;

}//#define STRUCT_POINT
void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	int a;//���������� ���������� '�' ���� int
	Point A;//�������� ������� 'A' ��������� 'Point'
			//���������� ���������� ���� 'Point'
			//���������� ������� '�' ��������� 'Point'
			//�������� ���������� ��������� 'Point'  
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif STRUCT_POINT

	cout << int() << endl;

	Point A;
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << tab << A.get_y() << endl;
	//Get-������
	Point B;
	B.set_x(4);
	B.set_y(5);
	//����� distance-���������� ���������� �� ��������� �����
	cout << A.distance(B) << endl;
	cout << B.distance(A) << endl;
	cout << distance(A, B) << endl;
	cout << distance(B, A) << endl;
}