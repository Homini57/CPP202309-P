#include "Çì´õ.h"
//User Class Method
void User::plus_point(int point) {
	this->point += point;
}

//Ingredient Class Method
bool Ingredient::Get_preference() { return preference; }
void Ingredient::Set_preference(bool preference) {
	this->preference = preference;
}


//Recipe Class Method
int Recipe::Get_rating(string item) { return rating[item]; }
void Recipe::Set_item(string item) {
	rating[item] = 0;
}
void Recipe::Set_rating(string item, int rating) {
	this->rating[item] = rating;
}
void Recipe::Set_ingredient(Ingredient ingredient) {
	ingredient_list.push_back(ingredient);
}

void Page::Set_menu(string menu) {
	menu_list.push_back(menu);
}
