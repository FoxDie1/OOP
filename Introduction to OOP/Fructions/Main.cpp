#include<iostream>
using namespace std;
class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;//цела€ часть
	int nomerator;//числитель
	int denominator;//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return nomerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_nomerator(int nomerator)
	{
		this->nomerator = nomerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//           Constructors
	Fraction()
	{
		integer = nomerator = 0;
		denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->nomerator = 0;
		this->denominator = 1;
		cout << "largConstructor:\t" << this << endl;
	}
	Fraction(int nomerator , int denominator )
	{
		this->integer = 0;
		this->nomerator = nomerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer , int nomerator, int denominator )
	{
		this->integer = integer;
		this->nomerator = nomerator;
		set_denominator(denominator);//когда нужна фильтраци€ данных даже внутри класса лучше исп. set методы
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->nomerator = other.nomerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
		~Fraction()
		{
			cout << "Destructor:\t\t" << this << endl;
	    }

		//                    operators
		Fraction& operator=(const Fraction& other)
		{
			this->integer = other.integer;
			this->nomerator = other.nomerator;
			this->denominator =other. denominator;
			cout << "CopyAssignment:\t\t" << this << endl;
			return *this;
		}
		Fraction& operator*=(const Fraction& other)
		{
			return *this=*this*other;
		}
		Fraction& operator/=(const Fraction& other)
		{
			return *this = *this / other;
		}


		//                increment/decrement
		Fraction& operator++()
		{
			integer++;
			return *this;
		}
		Fraction operator++(int)
		{
			Fraction old = *this;
			integer++;
			return old;
		}

		Fraction& operator--()
		{
			integer--;
			return *this;
		}
			Fraction operator--(int)
			{
				Fraction old = *this;
				integer--;
				return old;
			}
			
		Fraction& operator()(int integer, int nomerator, int denominator)
		{
			set_integer(integer);
			set_nomerator(nomerator);
			set_denominator(denominator);
			return *this;
		}
		//                    method
		Fraction& to_proper()
		{
			//¬ыдел€ет из неправильной дроби целую часть
			integer += nomerator / denominator;
			nomerator %= denominator;
			return *this;
		}
		Fraction& to_improper()
		{
			//÷елую часть интегрирует в числитель
			nomerator += integer * denominator;
			integer = 0;
			return *this;
		}
		Fraction& inverse()
		{
			to_improper();
			int buffer = nomerator;
			nomerator = denominator;
			denominator = buffer;
			return *this;
		}
		void print()const
		{
			if (integer)cout << integer;
			if (nomerator)
			{
				if (integer)cout << "(";
				cout << nomerator << "/" << denominator;
				if (integer)cout << ")";
			}
			if (integer == 0 && nomerator == 0)cout << 0;
			cout << endl;
		}
		friend ostream& operator <<(ostream& os, const Fraction& obj);
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	//Fraction result(left.get_nomerator()*right.get_nomerator(),left.get_denominator()*right.get_denominator());
	//result.set_nomerator(left.get_nomerator() * right.get_nomerator());
	//result.set_denominator(left.get_denominator() * right.get_denominator());
	//return result;
	return
		Fraction
		(
			left.get_numerator() * right.get_numerator(),
			left.get_denominator() * right.get_denominator()
		). to_proper();//€вно вызываем конструктор

}

Fraction operator/(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();

	return Fraction
		(
			left.get_numerator() * right.get_denominator(),
			left.get_denominator() * right.get_numerator()
		).to_proper();
	return left * right.inverse();
}


Fraction operator+(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}

Fraction operator -(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return Fraction
	(
		left.get_integer() + right.get_integer(),
		left.get_numerator() * right.get_denominator() - right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
	
}

ostream& operator <<(ostream& os, const Fraction& obj)
{
	if (obj.integer)cout <<obj.integer;
	if (obj.nomerator)
	{
		if (obj.integer)cout << "(";
		cout << obj.nomerator << "/" <<obj.denominator;
		if (obj.integer)cout << ")";
	}
	if (obj.integer == 0 && obj.nomerator == 0)cout << 0;
	return os;

}
//#define Constructors_CHECK
#define ARITHMETICAL_OPERATORS_CHECK
//#define NO_ONE

void main()
{
	setlocale(LC_ALL, "");
#ifdef Constructor_CHECK
	Fraction A;//конструктор по умолчанию
	A.print();
	Fraction B = 5;//Single-argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;//CopyConstructor
	E.print();
	Fraction F;
	F = D; //CopyAssigment
	F.print();
#endif  Constructor_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a * b;
	Fraction A(23, 3);
	A.print();
	Fraction B(8, 4, 5);
	B.print();
	Fraction C = A * B;
	C.print();
	(A / B).print();
	(A + B).print();
	(A - B).print();
	A *= B;
	//A.print();
	cout << A << endl;
#endif
#ifdef NO_ONE
	/*for (double i = .5; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (Fraction A(1, 2); A.get_integer() < 10; ++A)
	{
		cout << A << "\t";
	}
	cout << endl;*/
	Fraction A(1, 2);
	/*A.set_integer(7);
	A.set_nomerator(2);
	A.set_denominator(3);*/
	A(7, 2, 3);
	cout << A << endl;
#endif 
}