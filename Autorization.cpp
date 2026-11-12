#include "Autorization.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			if (currentStatus == L"Coffee master")
			{
				// to_do
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
					return true;
				}
			}
			std::wcout << L"Неверный логин или пароль( Повторите попытку \n\n";
		}
	}
}