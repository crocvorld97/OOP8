#include "stdafx.h"
#include "Vector.h"

void Vector::setX(float X)
{
	x = X;
}

void Vector::setY(float Y)
{
	y = Y;
}

float Vector::getX()
{
	return this->x;
}
float Vector::getY()
{ 
	return this->y;
}

float Vector::modul()
{
	return sqrt(((this->x * this->x) + (this->y * this->y)));
}

float Vector::scalarProduct(Vector a)
{
	return ((this->x * a.x) + (this->y * a.y));
}

Vector Vector::theVectorSum(Vector a)
{
	Vector sum(1.0, 1.0);
	sum.x = this->x + a.x;
	sum.y = this->y + a.y;
	return sum;
}

Vector Vector::theVectorDifference(Vector a)
{
	Vector difference;
	difference.x = this->x - a.x;
	difference.y = this->y - a.y;
	return difference;
}

void Vector::theMultiplication(float a)
{
	this->x = this->x * a;
	this->y = this->y * a;
}

void Vector::ortogonality(Vector a)
{
	if (a.scalarProduct(*this) == 0)
	{
		std::cout << "������� ������������!!!\n";
		return;
	}
	else
	{
		std::cout << "������� �� ������������!!!\n";
		return;
	}
}

void ortogonality(Vector a, Vector b)
{
	if (a.scalarProduct(b) == 0)
	{
		std::cout << "������� ������������!!!\n";
		return;
	}
	else
	{
		std::cout << "������� �� ������������!!!\n";
		return;
	}
}

void Vector::collinearity(Vector a)
{
	if ((a.getX() / this->getX()) == (a.getY() / this->getY()))
	{
		std::cout << "������� �����������!!!\n";
		return;
	}
	else
	{
		std::cout << "������� �� �����������!!!\n";
		return;
	}
}

void collinearity(Vector a, Vector b)
{
	if ((a.getX() / b.getX()) == (a.getY() / b.getY()))
	{
		std::cout << "������� �����������!!!\n";
		return;
	}
	else
	{
		std::cout << "������� �� �����������!!!\n";
		return;
	}
}

Vector::Vector(float X, float Y)
{
	x = X;
	y = Y;
	std::cout << "������ ����������� � ��������� �����������: " << this->x << " " << this->y << std::endl;
}

Vector::Vector()
{
	this->x = size; 
	this->y = size;
	std::cout << "������ ����������� ��� ����������\n";
}

Vector::Vector(const Vector& forCopy)
{
	std::cout << "����� ������������ �����������\n";
	x = forCopy.x;
	y = forCopy.y;
}

Vector::~Vector()
{
	std::cout << "����� �����������\n";
}

Vector::Vector(int size)
{
	x = size;
	y = size;
}

void Vector::callCloseConstructor(int size)
{
	std::cout << "������� �������� ���������� ��� ����������\n";
	Vector::Vector(size);
}

void Vector::printInfo()
{
	std::cout << "������� ����������� �������\n";
}