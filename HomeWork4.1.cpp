#include <iostream>

#include "Store.h"
#include "menu.h"


int main()
{
	Store client;
	Store admin;

	while (true)
	{	
		menu();
		
		// For client 
		if (choice == '1')
		{
			client.LoadProductsFromFile("HelloPizza.txt", std::ios::app);
			client.Buy();
			break;
		}

		// For admin
		if (choice == '2')
		{
			adminMenu();

			// Show assortment
			if (choice == '1')
			{
				admin.ShowProducts();
				break;
			}

			// Add product
			if (choice == '2')
			{
				
				admin.AddProduct("TomatoChilitto", 9.99, 3);
				
				break;
			}

			// Remove product
			if (choice == '3')
			{
				admin.RemoveProduct("Diavola");
				break;
			}

			// Update price
			if (choice == '4')
			{
				admin.UpdatePrice("Tonno", 70.99);
				break;
			}

			// Inventory 
			if (choice == '5')
			{
				admin.Inventory();
			
				break;
			}

			// Suply  
			if (choice == '6')
			{
				//admin.LoadProductsFromFile("Partner.txt", std::ios::app);

				admin.LoadProductsFromFile("Ingridients.txt", std::ios::app);

				admin.SaveProductsToFile("HelloPizza.txt", std::ios::app);

				std::cout << "Delivery completed" << std::endl;

				break;
			}
		}

		// Exit
		if (choice == '3')
		{
			std::cout << "See you!" << std::endl;
			break;
		}
	}
}




