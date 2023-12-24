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
	while (getline(igd_data, line)) { // igd_data에서 한줄씩 line에 저장
		Ingredient* pigd = new Ingredient();
		istringstream iss{ line }; // line(한줄)을 데이터 추출 가능 형태로 저장
		string data;
		int i = 0;
		while (getline(iss, data, ',')) { // iss에서 ',' 기준으로 데이터 추출
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
	// 냉장고의 각 재료들의 데이터들을 igd_data에 저장
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