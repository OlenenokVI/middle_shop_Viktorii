#include "Storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

void CreateStorage(int mode)
{
	const size_t staticSize = 10;

	size_t idArrStatic[staticSize]{ 1,2,3,4,5,6,7,8,9,10};
	std::wstring nameArrStatic[staticSize]{
		L"Экспрессо от депрессо", L"Американо", L"Капучинка на кокосовом", L"Капучинка с корицей и перцем",
		L"Базовый Латте для базового дня", L"Пряничный Латте", L"Тыквенный латте с щепоткой позитива",L"Базовый рррраффф",
		L"Раф на банановом со взбитыми сливками, корицей, маршмеллоу и шоколадной крошкой из дубайского шоколада",
		L"Лавандовый раф для настоящих мужчин"
	};
	size_t countArrStatic[staticSize]{ 67, 20, 34, 28, 33, 19, 18, 41, 66, 100 };
	double priceArrStatic[staticSize]{ 60, 70, 120, 130, 120, 150, 120, 140, 200, 300 };
};
