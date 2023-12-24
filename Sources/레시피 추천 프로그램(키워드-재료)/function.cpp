#include "header.h"
#include <fstream>
#include <sstream>
#include <string>


void ReadIngredientData(){
	ifstream igd_data{ "ingredient_data.csv" };
	if (!igd_data.is_open()) {
		std::cerr << "Error" << std::endl;
		return;
	}
	
	string line;
	while (getline(igd_data, line)) { // igd_data���� ���پ� line�� ����
		Ingredient* pigd = new Ingredient();
		istringstream iss{ line }; // line(����)�� ������ ���� ���� ���·� ����
		string data;
		int i = 0;
		while (getline(iss, data, ',')) { // iss���� ',' �������� ������ ����
			switch (i % 5) {
			case 0:
				pigd->SetName(data);
				break;
			case 1:
				pigd->SetInBasket(stoi(data));
				break;
			case 2:
				pigd->SetPurchased(stoi(data));
				break;
			case 3:
				pigd->SetPreference(stoi(data));
				break;
			case 4:
				pigd->SetStockState(stoi(data));
				break;
			}
			i++;
		}
		Ingredient::fridge.push_back(pigd);
	}
	
	igd_data.close();
}

void SaveIngredientData(){
	ofstream igd_data{ "ingredient_data.csv" };
	if (!igd_data.is_open()) {
		std::cerr << "Error" << std::endl;
		return;
	}
	// ������� �� ������ �����͵��� igd_data�� ����
	for (Ingredient* pigd : Ingredient::fridge) {
		string name;
		int in_basket, purchased, preference, stock_state;

		name = pigd->GetName();
		in_basket = pigd->GetInBasket();
		purchased = pigd->GetPurchased();
		preference = pigd->GetPreference();
		stock_state = pigd->GetStockState();
		igd_data << name << ",";
		igd_data << in_basket << "," << purchased << ",";
		igd_data << preference << "," << stock_state << "," << endl;
	}
	igd_data.close();
}