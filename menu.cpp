#include <iostream>
#include <iomanip>

#include "Store.h"
#include "menu.h"


char choice{ };


void menu()
{
	std::cout << "Menu :" << std::endl;

	std::cout << "1 - For order pizza " << std::endl
		       << "2 - Go to control panel " << std::endl
		       << "3 - For Exit " << std::endl
		       << "Enter :";

	std::cin >> choice;

	system("cls");
}

void adminMenu()
{
	std::cout << "This control panel for store's maneger" << std::endl;
	std::cout << "Select menu item :" << std::endl;

	std::cout << "1 - Show storage" << std::endl
		<< "2 - Add product" << std::endl
		<< "3 - Remove product" << std::endl
		<< "4 - Update price" << std::endl
		<< "5 - Inventory storage" << std::endl
		<< "6 - Suply" << std::endl
		<< "7 - Back to the menu" << std::endl
		<< "Enter :";

	std::cin >> choice;

	system("cls");
}





