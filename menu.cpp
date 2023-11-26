#include <iostream>



#include "Store.h"
#include "menu.h"


int choiceCharacter{ };
int choiceAct{ };



void menu()
{
	std::cout << "Menu :" << std::endl;

	std::cout << "1 - For order pizza " << std::endl
		       << "2 - Go to control panel " << std::endl
		       << "3 - For Exit " << std::endl
		       << "Enter :";

	std::cin >> choiceCharacter;

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
		       << "Enter :";

	std::cin >> choiceAct;

	system("cls");
}

void ChoiceMenu(Store& choicePerson)
{
	auto person = static_cast<TypeMenu>(choiceCharacter);

	switch (person)
	{
		case TypeMenu::client:
		{
			choicePerson.LoadProductsFromFile("HelloPizza.txt", std::ios::app);
			choicePerson.Buy();
			
		}
		break;
		case TypeMenu::admin:
		{
			adminMenu();
		}
		break;
		case TypeMenu::exit:
		{
			std::cout << "See you !" << std::endl;
		}
		break;
		default:
		{
			std::cout << "incorrect input" << std::endl;
		}
			break;
	
	}
}

void AdminMenu(Store& adminAct)
{
	auto ActAdmin = static_cast<AdminChoice>(choiceAct);

	switch (ActAdmin)
	{
		case AdminChoice::ShowAssortment:
		{
			adminAct.ShowProducts();
		}
		break;
		case AdminChoice::AddProduct:
		{
			adminAct.ShowProducts();

			std::cout << "Enter product name for add :";
			std::string name{ "" };
			std::cin >> name;

			std::cout << "Enter price :";
			double price{ };
			std::cin >> price;

			std::cout << "Enter number :";
			int balance{ };
			std::cin >> balance;

			adminAct.AddProduct(name, price, balance);
		}
		break;
		case AdminChoice::RemoveProduct:
		{
			adminAct.ShowProducts();

			std::cout << "Enter product name for remove :";
			std::string name{ "" };
			std::cin >> name;

			adminAct.RemoveProduct(name);
		}
		break;
		case AdminChoice::UpdatePrice:
		{
			adminAct.ShowProducts();

			std::cout << "Enter product name for Uppdate Price:";
			std::string name{ "" };
			std::cin >> name;

			std::cout << "Change price :";
			double NewPrice{ };
			std::cin >> NewPrice;

			adminAct.UpdatePrice(name, NewPrice);
		}
		break;
		case AdminChoice::Inventory:
		{
			adminAct.Inventory();
		}
		break;
		case AdminChoice::Supply:
		{
			std::cout << "Choice supplier :" << std::endl;
			std::cout << "jefree" << std::endl;
			std::cout << "tony" << std::endl;

			std::string supplier{ "" };
			std::cin >> supplier;

			adminAct.LoadProductsFromFile(supplier + ".txt", std::ios::app);

			adminAct.SaveProductsToFile("HelloPizza.txt", std::ios::app);

			std::cout << "Delivery completed" << std::endl;

		}
		break;
		default:
			break;
	
	}
}



