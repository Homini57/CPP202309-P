#include "헤더.h"
//User Class Method
User::User() { point = 0; }

void User::PlusPoint(int point) {
	this->point += point;
}

//Ingredient Class Method
Ingredient::Ingredient(string name) {
	this->name = name;
	preference = false;
	stock_state = 0;
}

bool Ingredient::GetPreference() { return preference; }
void Ingredient::SetPreference(bool preference) {
	this->preference = preference;
}


//Recipe Class Method
Recipe::Recipe() {
	vector <string> item_list{ "맛", "가성비", "조리시간", "난이도" };
	for (string item:item_list) {
		rating[item] = 0;
	}
}

int Recipe::GetRating(string item) {
	return rating[item];
}

void Recipe::SetItem(string item) {
	rating[item] = 0;
}

void Recipe::SetRating(string item, int rating) {
	this->rating[item] = rating;
}

void Recipe::SetIngredient(Ingredient ingredient) {
	ingredient_list.push_back(ingredient);
}

//Page Class Method
Page::Page(string name, vector <string> menu_list) {
	this->name = name;

	for (string menu:menu_list) {
		this->menu_list.push_back(menu);
	}
}

void Page::PrintMenu() {
	cout << "--------------------------------" << endl;
	cout << name << endl << endl;
	cout << "0. 메인으로 돌아가기" << endl;
	int i = 1;
	for (string menu : menu_list) {
		cout << i << ". " << menu << endl;
		i++;
	}
}

int Page::InputMenu() {
	int next_page = 0;
	cout << "메뉴 번호 선택 : ";
	cin >> next_page;
	return next_page;
}

auto Page::EnterMenu(int page_num) {
	switch (page_num + 1) {
	case 1:
		Page next_page("다음 페이지", {"1번", "2번"});
		OpenNextPage();
		return next_page;
	}
	
}
