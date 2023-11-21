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
	int stock_state;	// ����� ��� ���� : 0 = ���� or ����, 1 = ���� �ӹ� 2 = ����� ���

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
//��ٱ��ϴ� collectionȭ�� ���Ѿ� �ұ�? ����ȭ�� ���Ѿ� �ұ�?
class Page {
protected:
	string name;
	vector <string> menu_list;

public:
	Page(string name, vector <string> menu_list);
	void PrintFront();
	void PrintMenu(string additional_menu = "0. �������� , -1. ���� ������");
	int InputMenu(string message = "�޴� ���� : ");
	//auto EnterMenu(int next_page);

	void ReturnPage() {
		//���� �������� ���ư��� �ش� �������� �Ҹ��� ����Ͽ� ����

	}
};
//���� �������� �������� ��� �������� �����
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
