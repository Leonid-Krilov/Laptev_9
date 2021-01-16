#include "WorkFile.h"

WorkFile::WorkFile()
{
}

WorkFile::~WorkFile()
{
}

void WorkFile::_string()
{
	std::string _we = "we";
	std::string _they = "they";
	std::string str, rez;

	std::ifstream fin;
	fin.open("Input.txt");

	std::stringstream ss;
	ss << fin.rdbuf();
	fin.close();

	std::istringstream ist(ss.str());
	std::list<std::string> list;

	std::copy(std::istream_iterator<std::string>(ist), std::istream_iterator<std::string>(), std::back_inserter(list));
	std::replace(list.begin(), list.end(), _we, _they);

	std::ostringstream res;
	std::copy(list.begin(), list.end(), std::ostream_iterator<std::string>(res, " "));
	rez = res.str();

	std::cout << "Result: ";
	std::cout << rez << std::endl;
}

void WorkFile::_wstring()
{
	std::wstring _we(L"we");
	std::wstring _they(L"they");
	std::wstring str(L"\n");

	std::wifstream fin;
	fin.open("Input.txt");

	std::wstringstream ss;
	ss << fin.rdbuf();
	fin.close();

	std::wistringstream ist(ss.str());
	std::list<std::wstring> list;

	std::copy(std::istream_iterator<std::wstring, wchar_t, std::char_traits<wchar_t> >(ist),
		std::istream_iterator<std::wstring, wchar_t, std::char_traits<wchar_t> >(),
		std::back_inserter(list));

	for_each(list.begin(), list.end(), [_we, _they](auto& element) {
		if (element == _we)
			element = _they;
		});

	std::wostringstream res;

	std::copy(list.begin(), list.end(), std::ostream_iterator<std::wstring, wchar_t>(res, L" "));
	std::cout << "Result: ";
	std::wcout << res.str() << std::endl;
}

void WorkFile::_char()
{
	std::string _we = "we";
	std::string _they = "they";;


	/*std::cout << "Enter string: ";*/

	char* buff = new char[255];
	for (int i = 0; i < 255; i++)
		buff[i] = '\0';

	std::ifstream fin;
	fin.open("Input.txt");
	fin.read(buff, 254);
	fin.close();
	/*std::cin.getline(buff, 255);*/

	char* str = new char[strlen(buff) + 1];
	strcpy(str, buff);

	delete[] buff;

	std::istringstream ist(str);
	std::list<std::string> list;

	std::copy(std::istream_iterator<std::string>(ist), std::istream_iterator<std::string>(), std::back_inserter(list));
	std::replace(list.begin(), list.end(), _we, _they);


	std::ostringstream res;

	std::copy(list.begin(), list.end(), std::ostream_iterator<std::string>(res, " "));

	std::string rez = res.str();
	char* rez1 = new char[rez.size() + 1];

	strcpy(rez1, rez.c_str());

	std::cout << "Result: ";
	std::cout << rez1 << std::endl;

	delete[] str;
	delete[] rez1;
}

void WorkFile::_wchar()
{
	wchar_t _we[] = (L"we");
	wchar_t _they[] = (L"they");

	wchar_t* buff = new  wchar_t[255];

	/*std::wcout << L"Enter string: ";
	std::wcin.getline(buff, 255);*/
	std::wifstream fin;
	fin.open("Input.txt");
	wchar_t ch;
	fin.read(buff, 254);
	fin.close();

	wchar_t* str = new wchar_t[wcslen(buff) + 1];
	wcscpy(str, buff);
	delete[] buff;

	std::wistringstream ist(str);
	std::list<std::wstring> list;
	std::copy(std::istream_iterator<std::wstring, wchar_t, std::char_traits<wchar_t> >(ist),
		std::istream_iterator<std::wstring, wchar_t, std::char_traits<wchar_t> >(),
		std::back_inserter(list));
	for_each(list.begin(), list.end(), [_we, _they](auto& element) {
		if (element == _we)
			element = _they;
		});


	std::wostringstream res;
	std::copy(list.begin(), list.end(), std::ostream_iterator<std::wstring, wchar_t>(res, L" "));

	std::cout << "Result: ";

	std::wstring rez = res.str();
	wchar_t* rez1 = new wchar_t[rez.size() + 1];

	wcscpy(rez1, rez.c_str());

	std::wcout << rez1 << std::endl;

	delete[] str;
	delete[] rez1;

}


