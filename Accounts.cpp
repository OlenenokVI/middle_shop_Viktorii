#include "Accounts.hpp"

size_t userSize = 3;
size_t currentId = 0;
std::wstring currentStatus;

std::wstring* loginArr = new std::wstring[userSize] {L"bro", L"admin", L"user1" };
std::wstring* passArr = new std::wstring[userSize]{ L"bro", L"admin", L"user1" };;
std::wstring* statusArr = new std::wstring[userSize]{ L"Coffee master", L"Super coffee lover", L"Coffee lover" };
size_t* userIdArr = new size_t[userSize]{ 0, 1, 2 };
double* awardArr = new double[userSize] {};
double* fineArr = new double[userSize] {};


size_t maxLogin = 15;
size_t minLogin = 5;
size_t maxPass = 16;
size_t minPass = 6;

bool isSetCreated = false;

std::unordered_set<wchar_t> loginSymvols;
std::unordered_set<wchar_t> passSymvols;

void ShowUsers(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"ID\t" << L"Логин" << std::left << std::setw(maxLogin)
			<< L"\t\t Пароль" << std::left << std::setw(maxPass) << L"\t\t Статус"
			<< L"\t\t Сумма продаж" << L"\t\t Штрафы" << L"\n\n";
		for (size_t i = 0; i < userSize; i++)
		{
			std::wcout << userIdArr[i] << L"\t" << std::left << std::setw(maxLogin)
				<< loginArr[i] << L"\t" << passArr[i] << L"\t\t\t" << std::left << std::setw(maxPass) << statusArr[i]
				<< L"\t  " << awardArr[i] << std::fixed << std::setprecision(2) << L"\t\t\t  " 
				<< fineArr[i] << L"\n\n";
		}
		system("pause");
	}
}

void ChangeAccounts()
{
	std::wstring choose;

	if (!isSetCreated) {
		CreateSet();
	}

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
			CreateNewAccount();
		}
		else if (choose == L"2") {
			ShowUsers();
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
		while (true)
		{
			system("cls");
			std::wcout << L"Введите пароль нового пользователя или \"exit\" для выхода: ";
			GetLine(choosePass);
			if (choosePass == L"exit" || choosePass == L"exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			if (CheckPass(choosePass))
			{


				break;
			}
			else
			{
				Err();
			}
		}
		while (true)
		{
			system("cls");
			std::wcout << L"Введите роль нового пользователя или \"exit\" для выхода:\n ";
			std::wcout << L"1 - Сотрудник\n";
			std::wcout << L"2 - Админ\n";
			std::wcout << L"Ввод: ";
			GetLine(chooseStatus);
			if (chooseStatus == L"exit" || chooseStatus == L"exit")
			{
				std::wcout << L"Отмена создания учетной записи\n\n";
				Sleep(1500);
				return;
			}
			else if (chooseStatus == L"1")
			{
				chooseStatus = L"Coffee lover";
				break;
			}
			else if (chooseStatus == L"2")
			{
				std::wcout << L"Для подтверждения введите пароль Админа: ";
				GetLine(choose);
				if (choose == passArr[0])
				{
					chooseStatus = L"Super coffee lover";
					break;
				}
				else
				{
					Err();
				}
			}
			else
			{
				Err();
			}
		}
		while (true)
		{
			system("cls");
			std::wcout << L"Логин: " << chooseLogin << L"\n";
			std::wcout << L"Пароль: " << choosePass << L"\n";
			std::wcout << L"Статус: " << chooseStatus << L"\n\n";
			std::wcout << L"Подтвердить?\n1 - да\n2 - нет\n\nВвод: ";
			GetLine(choose);
			if (choose == L"1")
			{
				std::wcout << L"Создание учетной записи\n";
				for (size_t i = 0; i < 5; i++)
				{
					Sleep(500);
					std::wcout << L" .";
				}
				Sleep(500);

				ArrPushBack(userIdArr, userSize);
				ArrPushBack(loginArr, userSize);
				ArrPushBack(passArr, userSize);
				ArrPushBack(statusArr, userSize);
				ArrPushBack(fineArr, userSize);
				ArrPushBack(awardArr, userSize);

				userSize++;

				userIdArr[userSize - 1] = userSize - 1;
				loginArr[userSize - 1] = chooseLogin;
				passArr[userSize - 1] = choosePass;
				statusArr[userSize - 1] = chooseStatus;
				fineArr[userSize - 1] = 0.0;
				awardArr[userSize - 1] = 0.0;
				std::wcout << L"\n\n Учетная запись создана\n";
				Sleep(1500);
				break;

			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена создания учетной записи\n ";
				Sleep(1500);
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
	for (wchar_t i = L'A'; i < L'Z'; i++)
	{
		loginSymvols.insert(i);
	}
	for (wchar_t i = L'a'; i < L'z'; i++)
	{
		loginSymvols.insert(i);
	}
	for (wchar_t i = L'!'; i <= L'~'; i++)
	{
		passSymvols.insert(i);
	}
	isSetCreated = true;
}

bool CheckLogin(const std::wstring& login)
{
	if (login.size() < minLogin || login.size() > maxLogin)
	{
		std::wcout << L"Ошибка длины логина! Допустимо от " << minLogin
			<< L" до " << maxLogin << L" символов\n\n";
		Sleep(1500);
		return false;
	}
	if (!IsNotSame(login,loginArr,userSize))
	{
		std::wcout << L"Такой пользователь уже создан\n\n";
		Sleep(1500);
		return false;
	}
	int count = 0;
	for (size_t i = 0; i < login.size(); i++)
	{
		if (!loginSymvols.count(login[i]))
		{
			std::wcout << L"Некорректные символы в логине!\n\n";
			Sleep(1500);
			return false;
		}
		if (!std::iswdigit(login[i]) && count <= 4)
		{
			count++;
		}
	}
	if (count >= 4)
	{
		return true;
	}
	else
	{
		std::wcout << L"Слишком мало буквенных символов( минимум 4 символа верхнего или нижнего регистра\n\n";
		Sleep(1600);
		return false;
	}
}

bool CheckPass(const std::wstring& pass)
{
	if (pass.size() < minPass || pass.size() > maxPass)
	{
		std::wcout << L"Ошибка длины пароля! Допустимо от " << minPass
			<< L" до " << maxPass << L" символов\n\n";
		Sleep(1500);
		return false;
	}
	int symvolCount = 0, letterCount = 0, letterCapCount = 0, numberCount = 0;
	for (size_t i = 0; i < pass.size(); i++)
	{
		if (!passSymvols.count(pass[i]))
		{
			std::wcout << L"Некорректные символы в пароле!\n\n";
			Sleep(1500);
			return false;
		}
		if (!std::iswdigit(pass[i]) && numberCount <= 2)
		{
			numberCount++;
		}
		else if (pass[i] >= L'A' && pass[i] <= L'Z' && letterCapCount <= 1)
		{
			letterCapCount++;
		}
		else if (pass[i] >= L'a' && pass[i] <= L'z' && letterCount <= 3)
		{
			letterCount++;
		}
		else
		{
			symvolCount++;
		}
	}

	if (symvolCount > 0 && letterCount > 2 && letterCapCount > 0 && numberCount > 1)
	{
		return true;
	}
	else
	{
		std::wcout << L"Некорректный пароль! Минимальные требования: \n\n";
		std::wcout << L"1 или более спец символов\n";
		std::wcout << L"3 или более букв нижнего регистра\n";
		std::wcout << L"1 или более букв верхнего регистра\n";
		std::wcout << L"2 или более цифр\n";
		Sleep(2000);
		return false;
	}
}
