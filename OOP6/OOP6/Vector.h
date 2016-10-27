#pragma once
#include "stdafx.h"

class Vector
{
	private:
		float x;
		float y;
		static const int size = 1;
		Vector(int);
		
	public:
		
		void setX(float X);
		void setY(float Y);
		float getX();
		float getY();

		float modul();
		float scalarProduct(Vector a);
		Vector theVectorSum(Vector a);
		Vector theVectorDifference(Vector a);
		void theMultiplication(float a);
		~Vector();
		Vector(float, float);
		Vector();
		Vector(const Vector &);
		void callCloseConstructor(int size);
		static void printInfo();
		void ortogonality(Vector a);
		void collinearity(Vector a);
		Vector& operator+(Vector a)
		{
			this->x += a.x;
			this->y += a.y;
			return *this;
		}

		Vector& operator=(Vector a)
		{
			this->x = a.x;
			this->y = a.y;
			return *this;
		}
};

void ortogonality(Vector a, Vector b);
void collinearity(Vector a, Vector b);

