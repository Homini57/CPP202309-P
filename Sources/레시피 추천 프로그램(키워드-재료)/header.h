// �̸� ���� : ��� or ������ ����
#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#define CATEGORY_SIZE 4
using namespace std;
//���� Ŭ���� : ����Ʈ
class User {
private:
	int point;

public:
	User();
	void PlusPoint(int point);
	int GetPoint();
	void SetPoint(int point);
	void ReadUserPoint();
	void SavevUserPoint();
};

//��� Ŭ���� : �̸�, ��� ����, ��ȣ��, ��ٱ���, ���� ����, �����
class Ingredient {
private:
	string name;
	bool in_basket;
	bool purchased;
	bool preference;
	int stock_state;	// ����� ��� ���� : 0 = ���� or ����, 1 = ���� �ӹ� 2 = ����� ���


public:
	// ����� : ����� ������ ����
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
	// ��ᰡ ����� ���ٸ� ����� �߰�, type = ��� ����
	void InFridge(int type = 0);
};

// ������ Ŭ���� : ����, ���, ����, ����
class Recipe {
private:
	string title;
	vector <string> ingredient_list;
	vector <string> process_list;
	map<string, int> rating;

public:
	Recipe(string title, vector <string> ingredient_list, vector <string> process_list, vector <int> rating);
	string GetTitle();
	// �Է� �׸��� ������ ��ȯ
	int GetRating(string item);
	//�Է� �׸� ����
	void SetItem(string item);
	// �Է� �׸�� ������ ����
	void SetRating(string item, int rating);
	// ingredient_list ��ȯ
	vector <string> GetIngredients();
	// ingredient_list�� ��� �߰�
	void SetIngredient(string ingredient);
	// process_list ��ȯ
	vector <string> GetProcessList();
	// rating ��ȯ
	map<string, int> GetRatings();
	// �ش� �������� ������ �Է��ϴ� ���� ���
	void InputRating();
};

// ��� �̸��� ��� Ŭ������ ��ȯ
Ingredient* NameToIngredient(string name);

// ����� ������ ������ �ε�
void ReadIngredientData();
// ������� ����� ������ ������ ����
void SaveIngredientData();