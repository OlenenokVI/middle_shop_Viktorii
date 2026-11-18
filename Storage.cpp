#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

size_t maxStorageSize = 1800;
size_t currentStorageSize = 0;


void CreateStorage(int mode)
{
	if (mode == 0 && !isStorageCreated)
	{
		const size_t staticSize = 10;

		size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10 };
		std::wstring nameArrStatic[staticSize]{
			L"Экспрессо от депрессо", L"Americano", L"Капучинка на кокосовом", L"Капучинка на слезах студентов в сессию",
			L"Базовый Латте для базового дня", L"Пряничный Латте", L"Тыквенный латте с щепоткой позитива",L"Базовый рррраффф",
			L"Раф на банановом со взбитыми сливками, корицей и маршмеллоу",
			L"Самый нежный лавандовый раф для настоящих мужчин"
		};

		size_t countArrStatic[staticSize]{ 67, 50, 34, 28, 33, 19, 18, 41, 17, 100 };
		double priceArrStatic[staticSize]{ 67, 70.3, 120.4, 130.7, 120.8, 150.1, 120, 140.9, 400.4, 300.3 };


		sizeSt = staticSize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArray(idArrStatic, idArr, sizeSt);
		FillArray(nameArrStatic, nameArr, sizeSt);
		FillArray(countArrStatic, countArr, sizeSt);
		FillArray(priceArrStatic, priceArr, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			currentStorageSize += countArrStatic[i];
		}
		isStorageCreated = true;
	}
	else if (mode == 1)
	{
		// to do
	}
	else
	{
		std::wcout << L"Склад уже создан\n\n";
		Sleep(1500);
	}


}
void ShowStorage(int mode){
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		std::wcout << L"\n\t\t << Товары \"Кофе и точка\" >>\n";
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		std::wcout << L"\tID\t" << std::left << std::setw(65) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << L"\t" << idArr[i] << L"\t" << std::left << std::setw(65) << nameArr[i] 
				<< L"\t" << countArr[i] << L"\t" << priceArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		std::wcout << L"\n\t\t << Пополнение товаров \"Кофе и точка\" >>\n";
		std::wcout << L"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
		std::wcout << L"\tID\t" << std::left << std::setw(65) << L"Название товара\t\t"
			<< L"Кол-во\n\n";
		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << L"\t" << idArr[i] << L"\t" << std::left << std::setw(65) << nameArr[i]
				<< L"\t" << countArr[i] << L"\n";
		}
		std::wcout << L"\n\n";
		std::wcout << L"Свободного маста на складе " << currentStorageSize
			<< L" из " << maxStorageSize << L"\n\n";
	}
}
void AddProduct() {
	std::wstring chooseId, chooseCount, choose;
	while (true)
	{
		ShowStorage(1);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);

		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt -1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите кол-во товара для пополнения: ";
				GetLine(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 && count > maxStorageSize - currentStorageSize)
					{
						// продолжить тута
					}
				}
			}

		}




	}


}