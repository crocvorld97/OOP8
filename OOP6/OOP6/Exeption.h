#pragma once
#include "stdafx.h"
#include <exception>
#include <iostream>
using namespace std;

struct ListOverflow : public std::exception
{
	static char* what()
	{
		return "������ ����������, ���������� ��������� ����������!";
	}
};

struct IncorretIndex : public ListOverflow
{
	static char* what()
	{
		return "������������ ������ � ������!";
	}
};

struct EmptyList : public ListOverflow
{
	static char* what()
	{
		return "���������� ���������� ������� �� ������, �.�. �� ����!";
	}
};

struct NullDevision : public ListOverflow
{
	static char* what()
	{
		return "������� �� ���� ����������!";
	}
};