#include "Menu.h"

void Menu::PrintMenu()
{
	while (true)
	{
		char choice;
		string str;
		WorkFile ChoiceAction;
		
		cout << "Enter:\nPress '1' - string\nPress '2' - wstring\nPress '3' - char\nPress '4' - wchar\nPress '0' - Exit";
		cout << "\n> ";
		cin >> choice;

		getline(cin, str);

		switch (choice)
		{
		case'1':
			ChoiceAction._string();
			break;
		case'2':
			ChoiceAction._wstring();
			break;
		case'3':
			ChoiceAction._char();
			break;
		case'4':
			ChoiceAction._wchar();
			break;
		case'0':
			exit(0);
			break;
		default:
			cout << "\nError!";
			break;
		}


	}
}
