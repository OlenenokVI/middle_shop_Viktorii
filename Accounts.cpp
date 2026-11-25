#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize] {L"bro", L"admin", L"user1" };
std::wstring* passArr = new std::wstring[userSize]{ L"bro", L"admin", L"user1" };;
std::wstring* statusArr = new std::wstring[userSize]{ L"Coffee master", L"Super coffee lover", L"Coffee lover" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };

size_t maxLogin = 15;
size_t minLogin = 5;
size_t maxPass = 16;
size_t minPass = 6;

std::unordered_set<wchar_t> loginSymvols;
std::unordered_set<wchar_t> passSymvols;

void ChangeAccounts()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::wcout << L"\t Редактор учетных записей\n";
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::wcout << L"1 - Создать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить пароль\n";
		std::wcout << L"4 - Изменить уровни доступа\n";
		std::wcout << L"5 - Редактировать премии и штрафы сотрудников\n";
		std::wcout << L"6 - Удалить аккаунт\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		GetLine(choose);

		if (choose == L"1") {
			
		}
		else if (choose == L"2") {
			
		}
		else if (choose == L"3") {
			
		}
		else if (choose == L"4") {

		}
		else if (choose == L"5") {

		}
		else if (choose == L"6") {

		}
		else if (choose == L"0")
		{
			std::wcout << L"\nВыход из редактора склада\n\n";
			Sleep(1500);
			break;
		}
		else {
			Err();
		}
	}
}

void CreateNewAccount()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"Введите логин нового пользователя или \"exit\" для выхода: ";
			GetLine(chooseLogin);
			if (chooseLogin == L"exit" || chooseLogin == L"exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			if (CheckLogin(chooseLogin))
			{


				break;
			}
			else
			{
				Err();
			}
		}
	}
}

void CreateSet()
{
	for (wchar_t i = L'0'; i < L'9'; i++)
	{
		loginSymvols.insert(i);
	}
}

bool CheckLogin(const std::wstring& login)
{
	return false;
}
