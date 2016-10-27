// OOP6.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include "List.h"

template <class T> T minimum(List<T> a)
{
	T min = a[0];
	for (int i = 0; i < a.getListSize(); i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	return min;
}

template <> Vector minimum(List<Vector> a)
{
	Vector min = a[0];
	for (int i = 0; i < a.getListSize(); i++)
	{
		if (a[i].modul() < min.modul())
		{
			min = a[i];
		}
	}
	return min;
}

int main()
{
	setlocale(LC_CTYPE, "Russian");
	List <int>  NewList;
	NewList.add(5);
	NewList.add(3);
	NewList.add(4);
	cout << "Начальный вид первого списка:\n";
	NewList.show();
	cout << endl << endl;
	List <int>  NewList2;
	NewList2.add(1);
	NewList2.add(3);
	NewList2.add(2);
	if (NewList == NewList2)
	{
		cout << "Списки равны!\n";
	}
	else
	{
		cout << "Списки не равны!\n";
	}
	--NewList;
	cout << "После использования -- :\n";
	NewList.show();
	cout << endl << endl << "Второй список:\n";
	NewList2.show();
	NewList = NewList + NewList2;
	cout << endl << endl << "К первому списку добавили второй:\n";
	NewList.show();

	List <float>  NewList3;
	NewList3.add(1.3F);
	NewList3.add(2.4F);
	NewList3.add(3.5F);
	if (NewList3())
	{
		cout << "Список пуст!\n";
	}
	else
	{
		cout << "Список не пуст:\n";
		NewList3.show();
		cout << endl << endl;
	}

	
	List <char> NewList4;
	NewList4.add('b');
	NewList4.add('c');
	NewList4.show();
	cout << endl << endl;

	Vector vector(3.0F, 4.3F);
	Vector vector2(4.5F, 6.6F);
	Vector vector3(11.1F, 2.0F);
	List <Vector> NewListVector;
	NewListVector.add(vector);
	NewListVector.add(vector2);
	NewListVector.add(vector3);
	NewListVector.show();
	cout << endl << endl;
	
	cout << minimum<float> (NewList3) << endl;
	Vector vectorMin = minimum<Vector> (NewListVector);
	cout << "{" << vectorMin.getX() << ";" << vectorMin.getY() << "}" << endl;
	

    return 0;
}

