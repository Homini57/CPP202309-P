#include "header.h"
#include "recipe.h"
// 페이지 클래스 :  페이지 제목, 메뉴
class Page {
	
protected:
	string title;
	vector <string> menu_list;

public:
	// 열어놓은 페이지들 저장 목록
	static vector <Page*> opened_pages;

	Page(string title = "", vector <string> menu_list = {});
	// 페이지와 관련된 정보들 업데이트
	virtual void UpdatePage();
	// 페이지 제목, 기본 메뉴, 페이지 메뉴 출력
	void PrintMenu(string none_message = "", const vector <string>& basic_menu_list = {"- 1. 이전으로", "0. 메인으로"});
	int InputMenu(string message = "메뉴 선택 : ");
	void DeletePage();
	// PrintMenu 출력, InputMenu 입력, 입력에 따라 페이지 생성, 삭제 등 행동
	virtual int OpenPage();
};
// 메인 페이지 클래스
class MainPage : public Page {
public:
	MainPage();
	void UpdatePage();
	int OpenPage();
};
// 재료 페이지 : 레시피에 필요한 재료 or 냉장고에서 해당 재료를 선택하면 open
class IngredientPage : public Page {
	Ingredient* ingredient;
	vector <string> menu_list;
public:
	IngredientPage(Ingredient* ingredient);
	void UpdatePage();
	void PrintMenu(const vector <string>& basic_menu_list = { "- 1. 이전으로", "0. 메인으로" });
	int OpenPage();
};
// 레시피 페이지 : 레시피 검색, 추천 시 해당 레시피를 선택하면 open
class RecipePage : public Page {
	Recipe recipe;
public:
	RecipePage(string recipe_title);
	void UpdatePage();
	int OpenPage();
};
// 레시피 검색 페이지 : 요리명, 재료명 기준으로 레시피 검색
class SearchPage : public Page {
public:
	SearchPage();
	void UpdatePage();
	int OpenPage();
};

// 레시피 추천 페이지 : 재료들의 냉장고 재고 상태, 선호 상태 기준으로 레시피 추천
class RecommendPage : public Page {
public:
	vector <string> recipe_title_list;
	RecommendPage();
	void UpdatePage();
	//void PrintMenu();
	int OpenPage();

};
// 냉장고 페이지 : 저장된 재료들의 재료 페이지로 이동
class FridgePage : public Page {
public:
	FridgePage();
	void UpdatePage();
	int OpenPage();
};
// 장바구니 페이지 : 장바구니 목록 출력, 구매 
class BasketPage : public Page {
public:
	vector <Ingredient*> basket_list;
	BasketPage();
	void UpdatePage();
	char InputMenu(string message = "");
	int OpenPage();
};
// 구매 페이지 : 선택한 재료 구매
class BuyPage : public Page {
protected:
	Ingredient* item_to_buy;
public:
	BuyPage(Ingredient* item_to_buy);
	void UpdatePage();
	char InputMenu(string message = "");
	int OpenPage();
};
// 마이페이지 : 포인트 확인
class MyPage : public Page {
public:
	MyPage();
	void PrintMenu(const vector <string>& basic_menu_list = { "- 1. 이전으로", "0. 메인으로" });
	void UpdatePage();
	int OpenPage();
};
