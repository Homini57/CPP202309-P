#include "header.h"

class Page {
	
protected:
	string title;
	vector <string> menu_list;

public:
	static vector <Page*> opened_pages;

	Page(string title = "", vector <string> menu_list = {""});
	void UpdatePage();
	void PrintMenu(const vector <string>& basic_menu_list = {"- 1. 이전으로", "0. 메인으로" });
	int InputMenu(string message = "메뉴 선택 : ");
	//auto EnterMenu(int next_page);
	void DeletePage() {
		//이전 페이지로 돌아가고 해당 페이지는 소멸자 사용하여 제거
	}
	virtual int OpenPage();
};

//메인 페이지만 페이지의 상속 페이지로 만들기
class MainPage : public Page {
public:
	MainPage();

	int OpenPage();

};

// menu[input -1] = " "

class RecommendPage : public Page {
public:
	vector <Recipe> recipe_list;
	RecommendPage(vector <Recipe> recipe_list);

	void PrintMenu();

	int OpenPage();

};

class SearchPage : public Page {
public:
	SearchPage();

	void PrintMenu();

	int OpenPage();
};

class FridgePage : public Page {
public:
	FridgePage();

	void PrintMenu();

	int OpenPage();
};

class BasketPage : public Page {
public:
	BasketPage();

	void PrintMenu();

	int OpenPage();
};

class BuyPage : public Page {
public:
	BuyPage();

	void PrintMenu();

	int OpenPage();
};

class MyPage : public Page {
public:
	MyPage();

	void PrintMenu();

	int OpenPage();
};
class RecipePage : public Page {
public:
	RecipePage(Recipe recipe);
};

class IngredientPage : public Page {
	Ingredient ingredient;
	vector <string> menu_list;
public:
	IngredientPage(Ingredient ingredient);
	void PrintMenu (const vector <string>& basic_menu_list = { "- 1. 이전으로", "0. 메인으로" }) ;
	int OpenPage();
};
//int OpenIngredient();


string ClassifyIngredient();