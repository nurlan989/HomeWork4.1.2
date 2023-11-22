#include "Store.h"

#include <fstream>
#include <iostream>
#include <iomanip>


#define TAB    "           "


void Store::SaveProductsToFile(const std::string& name, char n)
{
	std::ofstream outputFile(name, n);

	if (outputFile)
	{
		for (const auto& product : m_products)
		{
			outputFile << product.name << " " << product.price << " " << product.balance << std::endl;
		}
		outputFile.close();
	}
	else
	{
		std::cout << "Unable to open file !" << std::endl;
	}
}

void Store::LoadProductsFromFile(const std::string& name, char flag)
{
	std::ifstream inputFile(name, flag);

	if (inputFile)
	{
		m_products.clear();
	}
	if (!inputFile)
	{
		std::cout << "File doesn't exist" << std::endl;
	}
	else
	{
		while (!inputFile.eof())
		{

			Product element;

			inputFile >> element.name >> element.price >> element.balance;

			if (!inputFile.fail())
			{
				m_products.push_back(element);
			}
		}
		inputFile.close();
	}
}

void Store::AddProduct(const std::string& name, double price, int balance)
{

	m_products.push_back({ name, price, balance });

	SaveProductsToFile("HelloPizza.txt", std::ios::app);

	std::cout << "Products added successfully" << std::endl;
}

void Store::ShowProducts()
{
	std::cout << "Current balance :" << std::endl;

	LoadProductsFromFile("HelloPizza.txt", std::ios::app);

	if (m_products.empty())
	{
		std::cout << "No products available" << std::endl;
	}
	else
	{
		for (const auto& product : m_products)
		{
			std::cout << "pizza :" << std::setw(15) << product.name << TAB << " price :" << std::setw(6) << product.price << TAB << " balance :" << product.balance << std::endl;
		}
	}
}

void Store::RemoveProduct(const std::string& name)
{
	LoadProductsFromFile("HelloPizza.txt", std::ios::app);

	for (auto& product : m_products)
	{
		if (product.name == name)
		{
			product.name = "-";
			product.price = 0.00;
			product.balance = 0;
			SaveProductsToFile("HelloPizza.txt", std::ios::trunc);
		}
	}
	std::cout << "Position deleted successfully !" << std::endl;
}

void Store::UpdatePrice(const std::string& name, double anotherPrice)
{
	LoadProductsFromFile("HelloPizza.txt", std::ios::app);

	for (auto& product : m_products)
	{
		if (product.name == name)
		{
			product.price = anotherPrice;

		}
	}
	SaveProductsToFile("HelloPizza.txt", std::ios::trunc);

	std::cout << "Price update successfully" << std::endl;
}

void Store::Inventory()
{
	ShowProducts();

	int summChoicedPizzas{ };
	std::string name{ };

	std::cout << "For exit press \"q\"" << std::endl;

	while (name != "q")
	{
		std::cout << "Select product :";
		std::cin >> name;

		for (auto& product : m_products)
		{
			if (product.name == name)
			{
				summChoicedPizzas += product.balance;
			}
		}
	}
	std::cout << "Total number of selected pizzas :" << summChoicedPizzas << std::endl;
}

void Store::Buy()
{
	if (m_products.empty())
	{
		std::cout << "The Store is not open" << std::endl;
	}
	else
	{
		double summ{ };
		double sale{ 0.8 };

		std::cout << "Discount for orders over $30 - 20%!" << std::endl;
		ShowProducts();

		std::string name{ "" };
		std::cout << "For order press \"o\"" << std::endl;

		while (name != "o")
		{
			std::cout << "Select product :";
			std::cin >> name;

			m_cart.push_back(name);

			for (auto& product : m_products)
			{
				if (product.name == name)
				{
					summ += product.price;
					if (summ > 30)
					{
						summ *= sale;
					}
					product.balance -= 1;

				}
			}
		}
		system("cls");
		m_cart.pop_back();

		std::cout << "Order is accepted" << std::endl;
		std::cout << "To pay :" << summ << std::endl;
		std::cout << "Bon apetit" << std::endl;
	}
}
