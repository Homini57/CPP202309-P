#include "page.h"
extern User user;
//User Class Method
User::User() { point = 0; }

void User::PlusPoint(int point) {
	this->point += point;
}

int User::GetPoint(User user) { return user.point; }
//Ingredient Class Method
Ingredient::Ingredient(string name) {
	this->name = name;
	preference = false;
	stock_state = 0;
}
string Ingredient::GetName() { return name; }
bool Ingredient::GetPreference() { return preference; }
void Ingredient::SetPreference(bool preference) {
	this->preference = preference;
}
bool Ingredient::GetStockState() { return stock_state; }
void Ingredient::SetStockState(int stock_state) {
	this->stock_state = stock_state;
}

//Recipe Class Method
Recipe::Recipe() {
	vector <string> item_list{ "��", "������", "�����ð�", "���̵�" };
	for (string item : item_list) {
		rating[item] = 0;
	}
}
string Recipe::GetTitle() {
	return title;
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
	string category[CATEGORY_SIZE] = { "���̵�", "���� �ð�", "��", "������" };
	cout << "--------------------------------" << endl;
	cout << "������ �Է����ּ���(1 ~ 5)" << endl;
	for (string ctg : category) {
		cout << ctg << " : ";
		cin >> rating;
		if (rating < 1 || 5 < rating) {
			cout << "�Է� ������ ������ϴ�." << endl;
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

