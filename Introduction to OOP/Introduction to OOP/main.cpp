#include<iostream>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

//�������� ���������:
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
		if (x < 0)x = 0;
		if (x > 1000)x = 1000;
		this->x = x;
	}
	void set_y(double y)
	{
		if (y < 0)y = 0;
		if (y > 1000)y = 1000;
		this->y = y;
	}

	//						Constructors:
	/*Point()
	{
		x = y = int();
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)	//����������� ����������� �������� ������
	{
		//� ������, ����������� ������ ������ ������ ������ ������������� �������.
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//						Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	//					Increment/Decrement
	Point& operator++()		//Prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int)	//Suffix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
		true || false;//bool
	}

	//						Methods:
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print()const
	{
		cout << "X = " << x << "\t" << "Y = " << y << endl;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}
Point operator-(const Point& left, const Point& right)
{
	Point res(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	return res;
}

bool operator==(const Point& left, const Point& right)
{
	if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;
}

double distance(const Point& A, const Point& B)
{
	/*double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance*x_distance + y_distance * y_distance);
	return distance;*/
	//return sqrt(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2));
	return pow(pow(A.get_x() - B.get_x(), 2) + pow(A.get_y() - B.get_y(), 2), .5);
}

#define delimiter "\n-----------------------------------\n"

//#define STRUCT_POINT
//#define DISTANCE
//#define CONSTRUCTORS_CHECK
//#define ASSIGNMENT_CHECK
//#define OPERATORS
//#define ARITHMENTICAL_OPERATORS

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	int a;		//���������� ���������� 'a' ���� 'int'
	Point A;	//���������� ���������� 'A' ���� 'Point'
				//���������� ������� 'A' ��������� 'Point'
				//�������� ������� 'A' ��������� 'Point'
				//�������� ���������� ��������� 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT

	//cout << int() << endl;	//Default value for int
	//Seems like we explicitly call default constructor for int

#ifdef DISTANCE
	Point A;	//Default constructor
	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	//get-������
	Point B;	//Default constructor
	B.set_x(4);
	B.set_y(5);
	B.print();
	//����� distance - ���������� ���������� �� ��������� �����.
	cout << "\n-----------------------------------\n";
	cout << A.distance(B) << endl;
	cout << "\n-----------------------------------\n";
	cout << B.distance(A) << endl;
	cout << "\n-----------------------------------\n";
	cout << distance(A, B) << endl;
	cout << "\n-----------------------------------\n";
	cout << distance(B, A) << endl;
	cout << "\n-----------------------------------\n";
	//�������� ������� distance(), ������� ���������� ���������� ����� ����� �������.  
#endif // DISTANCE

#ifdef CONSTRUCTORS_CHECK
			/*for (int i = 0; i < 10; i++)
{
	cout << i << "\t";
}*/
//cout << i << endl;
/*cout << endl;
{
	int a;
}
cout << a << endl;*/
	Point A;		//Default constructor
	A.print();
	Point B(2, 3);
	B.print();
	Point C = B;	//Copy constructor
	C.print();
	Point D(C);		//Copy constructor
	Point E;	//Default constructor
	E = C;	//Copy assignment
	E.print();
	A = B;
	A.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	Point A, B, C;	//Default constructor ��� ���� ���� �����
	cout << delimiter << endl;
	A = B = C = Point(15, 18);
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

#ifdef OPERATORS
	int a = 2;
	int b = 3;
	a + b;	//������� ���������
	a;	//���������� ���������
	;	//������ ���������
	int c = a + b;	//������� (���������) ���������
	a += b;
#endif // OPERATORS

#ifdef ARITHMENTICAL_OPERATORS
	Point A(2, 3);
	Point B(3, 4);
	A += B;
	A.print();
	Point C = A + B;
	C.print();
	C = A - B;
	C.print();
	Point D = C++;
	C.print();
	D.print();
#endif // ARITHMENTICAL_OPERATORS

	Point A(2, 3);
	//Point B(3, 4);
	Point B = A;
	//B++;
	if (A == ++B)
	{
		cout << "����� �����" << endl;
	}
	else
	{
		cout << "����� ������" << endl;
	}
}