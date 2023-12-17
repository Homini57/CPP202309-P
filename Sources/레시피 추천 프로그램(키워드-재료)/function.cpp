#include "page.h"
#include <fstream>
#include <sstream>
#include <string>
/*
extern vector <Recipe> recipe_book;
*/
//
void ReadIngredientData(){
	ifstream igd_data{ "ingredient_data.csv" };
	if (!igd_data.is_open()) {
		std::cerr << "Error" << std::endl;
		return;
	}
	
	string line;
	while (getline(igd_data, line)) {
		Ingredient* pigd = new Ingredient();
		istringstream iss{ line };
		string data;
		int i = 0;
		while (getline(iss, data, ',')) {
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


// 제품명 분석 및 재료 분류
string ClassifyIngredient() {
	string category; //변수이름이 ingredient가 나으려나?
	return category;
}
// 구매한 재료를 냉장고에 저장


//2레벨 페이지
// 레시피 추천 페이지
/*
/레시피 검색 페이지
int OpenSearch() {
	Page search_page("레시피 검색", {""});
	Opened_pages.push_back(search_page);
	search_page.PrintFront();
	//검색어 입력
	//검색 알고리즘
	// 필요한 입력 : 모든 레시피 이름 리스트, ~~~
	return 0;
}
*/
/*
// 냉장고 페이지
int OpenFridge() {
	vector <string> ingredient_list;
	Page fridge_page("냉장고", ingredient_list);
	//냉장고 속 재료를 메뉴화
	for (Ingredient ingredient : fridge) {
		string ingredient_name = ingredient.GetName();
		ingredient_list.push_back(ingredient_name);
	}
	fridge_page.PrintFront();
	fridge_page.PrintMenu();
	int next_page = fridge_page.InputMenu("재료 선택 : ");
	// 재료 & 현재 상태 표시
	// 재료 번호 입력시 : 재료 선호도, 재고 상태 -> 장바구니에 담기
	return 0;
}

*/



// 레시피 페이지
// 1. 필요 재료 & 현재 상태 표시(재고 상태, 선호도)
// 1-1. 재료 번호 입력시 : 재료 선호도, 재료 소진임박, 소진 -> 장바구니에 담기
// 2. 레시피
// 2-1. 1. 평점 입력, 0 : 메인으로, -1 : 이전 페이지