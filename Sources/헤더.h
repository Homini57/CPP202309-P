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
	User() {
		point = 0;
	}
	void plus_point(int point);

};

class Ingredient {
private:
	string name;
	bool preference;
	// ����� ��� ���� : 0 = ���� or ����, 1 = ���� �ӹ� 2 = ����� ���
	int stock_state;


	Ingredient(string name) {
		this->name = name;
		preference = false;
		stock_state = 0;
	}
public:
	bool Get_preference();
	void Set_preference(bool preference);

};

class Recipe {
private:
	vector <Ingredient> ingredient_list;
	map<string, int> rating;


public:
	Recipe() {
		rating["��"] = 0;
		rating["������"] = 0;
		rating["���̵�"] = 0;
		rating["�����ð�"] = 0;
	}
	int Get_rating(string item);
	void Set_item(string item);
	void Set_rating(string item, int rating);
	void Set_ingredient(Ingredient ingredient);


};
//��ٱ��ϴ� collectionȭ�� ���Ѿ� �ұ�? ����ȭ�� ���Ѿ� �ұ�?
class Page {
private:
	string page_name;
	vector <string> menu_list;
public:
	Page(string page_name) { //, string menu1 = NULL, string menu2 = NULL, string menu3 = NULL, string menu4 = NULL, string menu5 = NULL
		this->page_name = page_name;
		/*vector <string> input{menu1, menu2, menu3, menu4, menu5};
		for (int i = 0; i < 5; i++) {
			this->menu_list[i] = input[i];
		}*/
	}
	void Set_menu(string menu);
	void OpenPage() {
		cout << "--------------------------------" << endl;
		cout << page_name << endl << endl;
		cout << "0. �������� ���ư���" << endl;
		int i = 1;
		for (string menu : menu_list) {
			cout << i <<". " << menu << endl;
			i++;
		}
	}
	int InputMenu() {
		int next_page = 0;
		cout << "�޴� ��ȣ ���� : ";
		cin >> next_page;
		return next_page;
	}

	void EnterMenu(int next_page) {
		switch (next_page + 1) {
		case 1:
			OpenPage();

		}
	}
};

// menu[input -1] = " "

int OpenPage(int first, int second, int third, int forth, int fifth);
string ClassifyIngredient();
int OpenRecommendation();
int OpenSearch();
int OpenFridge();
int OpenBasket();
int OpenMyPage();
int OpenBuy();