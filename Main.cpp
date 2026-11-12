#include <io.h>
#include <fcntl.h>
#include "Autorization.hpp"

int main()
{
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);

	Start();


	 


	return 0;
}

/*
авторизация: логин и пароль
аккаунты: бд пользователей + функции. суперадмин, админ, пользователь
продажи: покупка, оплата, чек
склад: бд товаров, функции
служебные для работы программы


*/



