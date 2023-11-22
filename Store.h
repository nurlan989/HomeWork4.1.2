#pragma once

#include <string>
#include <vector>

struct Product
{
	std::string name{ "" };
	double price{ };
	int balance{ };
};

class Store
{

public:

	Store() = default;

	void SaveProductsToFile(const std::string& name, char n);

	void LoadProductsFromFile(const std::string& name, char n);

	void ShowProducts();

	void AddProduct(const std::string& name, double price, int balance);

	void RemoveProduct(const std::string& name);

	void UpdatePrice(const std::string& name, double anotherPrice);

	void Inventory();

	void Buy();

private:

	std::vector<std::string>m_cart{};
	std::vector<Product>m_products{ };
};

