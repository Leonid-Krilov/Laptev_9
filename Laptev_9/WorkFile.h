#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<list>
#include<algorithm>
#include<iterator>
#pragma warning(disable : 4996)

class WorkFile
{
public:
	WorkFile();
	~WorkFile();

	void _string();
	void _wstring();
	void _char();
	void _wchar();

private:
	std::string InputFile = "Input.txt";
};

