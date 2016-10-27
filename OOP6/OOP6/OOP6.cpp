// OOP6.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"

#include "List.h"
#include <cstring>
//#define NDEBUG
#include <cassert>

template <class T> T minimum(List<T> a)
{
	assert(a.getListSize() != NULL);
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

class Abstract
{
	Vector *a;
public:

	Abstract(int n = 3)
	{
		a = new Vector[n];
		std::cout << "�����\n";
	}
	~Abstract()
	{
		delete[] a;
	}
};

int main()
{
	setlocale(LC_CTYPE, "Russian");
	try {
		//Abstract a(-1);		bad_alloc ����������
		
		List <int>  NewList;
		int* myarray = new int;
		NewList.add(5);	
		NewList.add(3);
		NewList.add(4);
		NewList.add(6);
		//NewList.add(8);
		//NewList.add(9);						������ ������������ ������

		//int a = NewList[-1];					������������� ������������ �������
		//cout << a << endl;

		cout << "��������� ��� ������� ������:\n";
		NewList.show();
		cout << endl << endl;
		List <int>  NewList2;
		NewList2.add(1);
		NewList2.add(3);
		NewList2.add(2);
		if (NewList == NewList2)
		{
			cout << "������ �����!\n";
		}
		else
		{
			cout << "������ �� �����!\n";
		}
		--NewList;
		cout << "����� ������������� -- :\n";
		NewList.show();
		cout << endl << endl << "������ ������:\n";
		NewList2.show();
		NewList = NewList + NewList2;
		cout << endl << endl << "� ������� ������ �������� ������:\n";
		NewList.show();

		List <float>  NewList3;
		NewList3.add(1.3F);
		NewList3.add(2.4F);
		NewList3.add(3.5F);

		//--NewList3;
		//--NewList3;
		//--NewList3;
		//--NewList3;
		
		
		if (NewList3())
		{
			cout << "������ ����!\n";
		}
		else
		{
			cout << "������ �� ����:\n";
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

		cout << minimum<float>(NewList3) << endl;
		Vector vectorMin = minimum<Vector>(NewListVector);
		cout << "{" << vectorMin.getX() << ";" << vectorMin.getY() << "}" << endl;

		List<int> NewList6 = NewList / 6;	// �������� �� NULL ��� ������������ ������

		//List<int> NewList5;					������� assert ������� ��������� ���������� ���������
		//cout << minimum(NewList5) << endl;
	}

	catch (std::bad_alloc& exp)
	{
		std::cout << exp.what() << std::endl;
	}

	catch (IncorretIndex& ex)
	{
		cout << ex.what() << endl;
	}

	catch (EmptyList& ex)
	{
		cout << ex.what() << endl;
	}

	catch (NullDevision& ex)
	{
		cout << ex.what() << endl;
	}

	catch (ListOverflow& ex)
	{
		cout << ex.what() << endl;
	}

	

    return 0;
}

