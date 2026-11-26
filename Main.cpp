#include <io.h>
#include <fcntl.h>
#include "Autorization.hpp"

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	Start();

	delete[]loginArr;
	delete[]passArr;
	delete[]statusArr;
	delete[]userIdArr;
	delete[]fineArr;
	delete[]awardArr;
	
	if (isStorageCreated)
	{
		delete[]idArr;
		delete[]nameArr;
		delete[]countArr;
		delete[]priceArr;
	}
	

	return 0;
}

/*
авторизация: логин и пароль
аккаунты: бд пользователей + функции. суперадмин, админ, пользователь
продажи: покупка, оплата, чек
склад: бд товаров, функции
служебные для работы программы


*/



