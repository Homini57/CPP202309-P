#include "page.h"
extern User user;
//User Class Method
User::User() { point = 0; }

void User::PlusPoint(int point) { this->point += point; }
int User::GetPoint() { return point; }


vector <Ingredient*> Ingredient::fridge;
//Ingredient Class Method
Ingredient::Ingredient(string name) {
	this->name = name;
	in_basket = false;
	purchased = false;
	preference = false;
	stock_state = 2;

}
string Ingredient::GetName() { return name; }
void Ingredient::SetName(string name) { this->name = name; }
bool Ingredient::GetPreference() { return preference; }
void Ingredient::SetPreference(bool preference) { this->preference = preference; }
int Ingredient::GetStockState() { return stock_state; }
void Ingredient::SetStockState(int stock_state) { this->stock_state = stock_state; }

bool Ingredient::GetInBasket() { return in_basket; }
void Ingredient::SetInBasket(bool in_basket) { this->in_basket = in_basket; }
bool Ingredient::GetPurchased() { return purchased; }
void Ingredient::SetPurchased(bool purchased) { this->purchased = purchased; }

//Recipe Class Method
Recipe::Recipe() {
	vector <string> item_list{ "맛", "가성비", "조리시간", "난이도" };
	for (string item : item_list) {
		rating[item] = 0;
	}
}
string Recipe::GetTitle() { return title; }
int Recipe::GetRating(string item) { return rating[item]; }
void Recipe::SetItem(string item) { rating[item] = 0; }
void Recipe::SetRating(string item, int rating) { this->rating[item] = rating; }
void Recipe::SetIngredient(Ingredient ingredient) { ingredient_list.push_back(ingredient); }
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

