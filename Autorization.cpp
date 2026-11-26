#include "Autorization.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			if (currentStatus == L"Coffee master")
			{
				CreateStorage();
				SuperAdminMenu();
			}
			else if (currentStatus == L"Super coffee lover")
			{
				// to_do
			}
			else if (currentStatus == L"Coffee lover")
			{
				// to_do
			}
			else
			{
				std::wcerr << L"_CURRENT_STATUS_LOGIN_ERROR_";
			}
		}
		else
		{

		}
	}
}

bool Login() {
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::wcout << L"\n\t\t\tЗдравствуй, дорогой гость!";
		std::wcout << L"\n\n\t\t   Вас приветствует << Кофе и точка >> \n\n";
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		GetLine(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			GetLine(pass);
			for (size_t i = 0; i < userSize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"\nДобро пожаловать в кофейню, " << loginArr[i] << L"!\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentId = userIdArr[i];
					currentStatus = statusArr[i];
					Sleep(1500);
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль( Повторите попытку \n\n";
		}
	}
}

void SuperAdminMenu()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::wcout << L"\t\t Меню для Coffee master\n";
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		std::wcout << L"1 - Начать продажу\n";
		std::wcout << L"2 - Показать склад\n";
		std::wcout << L"3 - Пополнить товары\n";
		std::wcout << L"4 - Списать товары\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактирование сотрудников\n";
		std::wcout << L"8 - Отчет о прибыли\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		GetLine(choose);

		if (choose == L"1") {

		}
		else if (choose == L"2") {
			ShowStorage();
		}
		else if (choose == L"3" && sizeSt > 0) {
			AddProduct();
		}
		else if (choose == L"4" && sizeSt > 0) {
			RemoveProduct();
		}
		else if (choose == L"5" && sizeSt > 0) {
			ChangePrice();
		}
		else if (choose == L"6") {
			ChangeStorage();
		}
		else if (choose == L"7") {
			ChangeAccounts();
		}
		else if (choose == L"8") {

		}
		else {
			Err();
		}
	}
}
