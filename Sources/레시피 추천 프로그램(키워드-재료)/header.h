// 이름 수정 : 재료 or 레시피 관련
#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#define CATEGORY_SIZE 4
using namespace std;
//유저 클래스 : 포인트
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

//재료 클래스 : 이름, 재고 상태, 선호도, 장바구니, 구매 여부, 냉장고
class Ingredient {
private:
	string name;
	bool in_basket;
	bool purchased;
	bool preference;
	int stock_state;	// 재료의 재고 상태 : 0 = 소진 or 없음, 1 = 소진 임박 2 = 냉장고 재료


public:
	// 냉장고 : 저장된 재료들의 벡터
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
	// 재료가 냉장고에 없다면 냉장고에 추가, type = 재고 상태
	void InFridge(int type = 0);
};

// 레시피 클래스 : 제목, 재료, 과정, 평점
class Recipe {
private:
	string title;
	vector <string> ingredient_list;
	vector <string> process_list;
	map<string, int> rating;

public:
	Recipe(string title, vector <string> ingredient_list, vector <string> process_list, vector <int> rating);
	string GetTitle();
	// 입력 항목의 평점을 반환
	int GetRating(string item);
	//입력 항목 설정
	void SetItem(string item);
	// 입력 항목과 평점을 설정
	void SetRating(string item, int rating);
	// ingredient_list 반환
	vector <string> GetIngredients();
	// ingredient_list에 재료 추가
	void SetIngredient(string ingredient);
	// process_list 반환
	vector <string> GetProcessList();
	// rating 반환
	map<string, int> GetRatings();
	// 해당 레시피의 평점을 입력하는 과정 출력
	void InputRating();
};

// 재료 이름을 재료 클래스로 반환
Ingredient* NameToIngredient(string name);

// 냉장고 재료들의 데이터 로드
void ReadIngredientData();
// 현재까지 변경된 재료들의 데이터 저장
void SaveIngredientData();