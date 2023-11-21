#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

class User {
private:
	int point;

public:
	User();
	void PlusPoint(int point);
};

class Ingredient {
private:
	string name;
	bool preference;
	int stock_state;	// 재료의 재고 상태 : 0 = 소진 or 없음, 1 = 소진 임박 2 = 냉장고 재료

public:
	Ingredient(string name);
	string GetName();
	bool GetPreference();
	void SetPreference(bool preference);
};

class Recipe {
private:
	//bool is_read;
	vector <Ingredient> ingredient_list;
	vector <string> process_list;
	map<string, int> rating;

public:
	Recipe();
	int GetRating(string item);
	void SetItem(string item);
	void SetRating(string item, int rating);
	void SetIngredient(Ingredient ingredient);
};
//장바구니는 collection화를 시켜야 할까? 파일화를 시켜야 할까?
class Page {
protected:
	string name;
	vector <string> menu_list;

public:
	Page(string name, vector <string> menu_list);
	void PrintFront();
	void PrintMenu(string additional_menu = "0. 메인으로 , -1. 이전 페이지");
	int InputMenu(string message = "메뉴 선택 : ");
	//auto EnterMenu(int next_page);

	void ReturnPage() {
		//이전 페이지로 돌아가고 해당 페이지는 소멸자 사용하여 제거

	}
};
//메인 페이지만 페이지의 상속 페이지로 만들기
class MainPage : public Page {
public:
	MainPage(string name, vector <string> menu_list);
	void PrintMenu();
};

// menu[input -1] = " "

string ClassifyIngredient();
int OpenMainPage();
int OpenRecommend();
int OpenSearch();
int OpenFridge();
int OpenBasket();
int OpenMyPage();
int OpenBuy();
