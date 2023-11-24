#pragma once
#include "Store.h"

extern int choiceCharacter;
extern int choiceAct;

enum class TypeMenu
{
	client = 1,
	admin,
	exit
};

enum class AdminChoice
{
	ShowAssortment = 1,
	AddProduct,
	RemoveProduct,
	UpdatePrice,
	Inventory,
	Supply
};

void menu();

void adminMenu();

void ChoiceMenu(Store& name);
void AdminMenu(Store& t);
