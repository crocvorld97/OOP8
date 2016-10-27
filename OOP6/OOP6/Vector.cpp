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
		std::cout << "Вектора ортогональны!!!\n";
		return;
	}
	else
	{
		std::cout << "Вектора не ортогональны!!!\n";
		return;
	}
}

void ortogonality(Vector a, Vector b)
{
	if (a.scalarProduct(b) == 0)
	{
		std::cout << "Вектора ортогональны!!!\n";
		return;
	}
	else
	{
		std::cout << "Вектора не ортогональны!!!\n";
		return;
	}
}

void Vector::collinearity(Vector a)
{
	if ((a.getX() / this->getX()) == (a.getY() / this->getY()))
	{
		std::cout << "Вектора коллинеарны!!!\n";
		return;
	}
	else
	{
		std::cout << "Вектора не коллинеарны!!!\n";
		return;
	}
}

void collinearity(Vector a, Vector b)
{
	if ((a.getX() / b.getX()) == (a.getY() / b.getY()))
	{
		std::cout << "Вектора коллинеарны!!!\n";
		return;
	}
	else
	{
		std::cout << "Вектора не коллинеарны!!!\n";
		return;
	}
}

Vector::Vector(float X, float Y)
{
	x = X;
	y = Y;
	std::cout << "Создан конструктор с указаными параметрами: " << this->x << " " << this->y << std::endl;
}

Vector::Vector()
{
	this->x = size; 
	this->y = size;
	std::cout << "Создан конструктор без параметров\n";
}

Vector::Vector(const Vector& forCopy)
{
	std::cout << "Вызов конструктора копирования\n";
	x = forCopy.x;
	y = forCopy.y;
}

Vector::~Vector()
{
	std::cout << "Вызов деструктора\n";
}

Vector::Vector(int size)
{
	x = size;
	y = size;
}

void Vector::callCloseConstructor(int size)
{
	std::cout << "Вызован закрытый констуртор без параметров\n";
	Vector::Vector(size);
}

void Vector::printInfo()
{
	std::cout << "Вызвана статическая функция\n";
}