#include "header.h"
extern User user;
//User Class Method
User::User() { point = 0; }

void User::PlusPoint(int point) {
	this->point += point;
}

int User::GetPoint(User user) { return user.point; }
//Ingredient Class Method
Ingredient::Ingredient(string name ="") {
	this->name = name;
	preference = false;
	stock_state = 0;
}
string Ingredient::GetName() { return name; }
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
void Recipe::InputRating() {
	int rating;
	string category[CATEGORY_SIZE] = { "난이도", "조리 시간", "맛", "가성비" };
	cout << "--------------------------------" << endl;
	cout << "평점을 입력해주세요(1 ~ 5)" << endl;
	for (string ctg : category) {
		cout << ctg << " : ";
		cin >> rating;
		if (rating < 1 || 5 < rating) {
			cout << "입력 범위를 벗어났습니다." << endl;
			for (string ctg : category) {
				SetRating(ctg, 0);
			}
			break;
		}
		SetRating(ctg, rating);
	}
	if (GetRating(category[0]) != 0) {
		user.PlusPoint(5);
	}
}

//Page Class Method
Page::Page(string name, vector <string> menu_list) {
	this->name = name;

	for (string menu:menu_list) {
		this->menu_list.push_back(menu);
	}
}

void Page::PrintFront() {
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	cout << name << endl << endl;
}
void Page::PrintMenu(string additional_menu) {
	int i = 1;
	for (string menu : menu_list) {
		cout <<" " << i << ". " << menu << endl;
		i++;
	}
	cout << "(" << additional_menu << ")" << endl;
	
}


int Page::InputMenu(string message) {
	int next_page = 0;
	cout << endl;
	cout << message;
	cin >> next_page;
	return next_page;
}

/*auto Page::EnterMenu(int page_num) {
	switch (page_num + 1) {
	case 1:
		Page next_page("다음 페이지", {"1번", "2번"});
		return next_page;
	}
	
}*/

MainPage::MainPage(string name, vector<string> menu_list) : Page(name, menu_list) {}

void MainPage::PrintMenu() {
	int i = 1;
	for (string menu : menu_list) {
		cout << " " << i << ". " << menu << endl;
		i++;
	}
}