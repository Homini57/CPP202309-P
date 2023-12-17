#include "header.h"

class Page {
	
protected:
	string title;
	vector <string> menu_list;

public:
	static vector <Page*> opened_pages;

	Page(string title = "", vector <string> menu_list = {});
	virtual void UpdatePage();
	void PrintMenu(string none_message = "", const vector <string>& basic_menu_list = {"- 1. ��������", "0. ��������"});
	int InputMenu(string message = "�޴� ���� : ");
	//auto EnterMenu(int next_page);
	//���� �������� ���ư��� �ش� �������� �Ҹ��� ����Ͽ� ����
	void DeletePage();
	virtual int OpenPage();
};

//���� �������� �������� ��� �������� �����
class MainPage : public Page {
public:
	MainPage();
	void UpdatePage();
	int OpenPage();
};

// menu[input -1] = " "

class RecommendPage : public Page {
public:
	vector <Recipe> recipe_list;
	RecommendPage(vector <Recipe> recipe_list);
	void UpdatePage();
	//void PrintMenu();
	int OpenPage();

};

class FridgePage : public Page {
public:
	FridgePage();
	void UpdatePage();
	int OpenPage();
};

class BasketPage : public Page {
public:
	vector <Ingredient*> basket_list;
	BasketPage();
	void UpdatePage();
	char InputMenu(string message = "");
	int OpenPage();
};

class BuyPage : public Page {
protected:
	Ingredient* item_to_buy;
public:
	BuyPage(Ingredient* item_to_buy);
	void UpdatePage();
	char InputMenu(string message = "");
	int OpenPage();
};

class MyPage : public Page {
public:
	MyPage();
	void PrintMenu(const vector <string>& basic_menu_list = { "- 1. ��������", "0. ��������" });
	int OpenPage();
};
/*
class SearchPage : public Page {
public:
	SearchPage();

	void PrintMenu();

	int OpenPage();
};


class RecipePage : public Page {
public:
	RecipePage(Recipe recipe);
};


*/


class IngredientPage : public Page {
	Ingredient* ingredient;
	vector <string> menu_list;
public:
	IngredientPage(Ingredient* ingredient);
	void UpdatePage();
	void PrintMenu (const vector <string>& basic_menu_list = { "- 1. ��������", "0. ��������" }) ;
	int OpenPage();
};
//int OpenIngredient();


string ClassifyIngredient();