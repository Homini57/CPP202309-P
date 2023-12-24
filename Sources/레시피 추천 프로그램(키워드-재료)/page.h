#include "header.h"
#include "recipe.h"
// ������ Ŭ���� :  ������ ����, �޴�
class Page {
	
protected:
	string title;
	vector <string> menu_list;

public:
	// ������� �������� ���� ���
	static vector <Page*> opened_pages;

	Page(string title = "", vector <string> menu_list = {});
	// �������� ���õ� ������ ������Ʈ
	virtual void UpdatePage();
	// ������ ����, �⺻ �޴�, ������ �޴� ���
	void PrintMenu(string none_message = "", const vector <string>& basic_menu_list = {"- 1. ��������", "0. ��������"});
	int InputMenu(string message = "�޴� ���� : ");
	void DeletePage();
	// PrintMenu ���, InputMenu �Է�, �Է¿� ���� ������ ����, ���� �� �ൿ
	virtual int OpenPage();
};
// ���� ������ Ŭ����
class MainPage : public Page {
public:
	MainPage();
	void UpdatePage();
	int OpenPage();
};
// ��� ������ : �����ǿ� �ʿ��� ��� or ������� �ش� ��Ḧ �����ϸ� open
class IngredientPage : public Page {
	Ingredient* ingredient;
	vector <string> menu_list;
public:
	IngredientPage(Ingredient* ingredient);
	void UpdatePage();
	void PrintMenu(const vector <string>& basic_menu_list = { "- 1. ��������", "0. ��������" });
	int OpenPage();
};
// ������ ������ : ������ �˻�, ��õ �� �ش� �����Ǹ� �����ϸ� open
class RecipePage : public Page {
	Recipe recipe;
public:
	RecipePage(string recipe_title);
	void UpdatePage();
	int OpenPage();
};
// ������ �˻� ������ : �丮��, ���� �������� ������ �˻�
class SearchPage : public Page {
public:
	SearchPage();
	void UpdatePage();
	int OpenPage();
};

// ������ ��õ ������ : ������ ����� ��� ����, ��ȣ ���� �������� ������ ��õ
class RecommendPage : public Page {
public:
	vector <string> recipe_title_list;
	RecommendPage();
	void UpdatePage();
	//void PrintMenu();
	int OpenPage();

};
// ����� ������ : ����� ������ ��� �������� �̵�
class FridgePage : public Page {
public:
	FridgePage();
	void UpdatePage();
	int OpenPage();
};
// ��ٱ��� ������ : ��ٱ��� ��� ���, ���� 
class BasketPage : public Page {
public:
	vector <Ingredient*> basket_list;
	BasketPage();
	void UpdatePage();
	char InputMenu(string message = "");
	int OpenPage();
};
// ���� ������ : ������ ��� ����
class BuyPage : public Page {
protected:
	Ingredient* item_to_buy;
public:
	BuyPage(Ingredient* item_to_buy);
	void UpdatePage();
	char InputMenu(string message = "");
	int OpenPage();
};
// ���������� : ����Ʈ Ȯ��
class MyPage : public Page {
public:
	MyPage();
	void PrintMenu(const vector <string>& basic_menu_list = { "- 1. ��������", "0. ��������" });
	void UpdatePage();
	int OpenPage();
};
