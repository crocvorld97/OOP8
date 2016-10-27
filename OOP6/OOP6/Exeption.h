#pragma once
#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;

struct ListOverflow : public std::exception
{
	static char* what()
	{
		return "Список переполнен, добавление элементов невозможно!";
	}
};

struct IncorretIndex : public ListOverflow
{
	static char* what()
	{
		return "Некорректный индекс в списке!";
	}
};

struct EmptyList : public ListOverflow
{
	static char* what()
	{
		return "Невозможно выталкнуть элемент из списка, т.к. он пуст!";
	}
};

struct NullDevision : public ListOverflow
{
	static char* what()
	{
		return "Деление на ноль невозможно!";
	}
};