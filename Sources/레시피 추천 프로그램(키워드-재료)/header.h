// 이름 수정 : 재료 or 레시피 관련
#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#define CATEGORY_SIZE 4
using namespace std;
class User {
private:
	int point;

public:
	User();
	void PlusPoint(int point);
	int GetPoint();
};

class Ingredient {
private:
	string name;
	bool in_basket;
	bool purchased;
	bool preference;
	int stock_state;	// 재료의 재고 상태 : 0 = 소진 or 없음, 1 = 소진 임박 2 = 냉장고 재료


public:
	static vector <Ingredient*> fridge;
	Ingredient(string name = "");
	string GetName();
	void SetName(string name);
	bool GetPreference();
	void SetPreference(bool preference);
	int GetStockState();
	void SetStockState(int stock_state);
	bool GetInBasket();
	void SetInBasket(bool in_basket);
	bool GetPurchased();
	void SetPurchased(bool purchased);
};

class Recipe {
private:
	//bool is_read;
	string title;
	vector <Ingredient> ingredient_list;
	vector <string> process_list;
	map<string, int> rating;

public:
	Recipe();
	string GetTitle();
	int GetRating(string item);
	void SetItem(string item);
	void SetRating(string item, int rating);
	void SetIngredient(Ingredient ingredient);
	void InputRating();
};



