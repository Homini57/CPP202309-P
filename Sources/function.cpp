#include "header.h"
#define CATEGORY_SIZE 4


extern vector <Ingredient> fridge;
extern vector <Recipe> recipe_book;
extern vector <Page> Opened_pages;
// 제품명 분석 및 재료 분류
string ClassifyIngredient() {
	string category; //변수이름이 ingredient가 나으려나?
	return category;
}
// 구매한 재료를 냉장고에 저장


// 페이지 클래스를 만들어서 상속해야 하나?

//1레벨 페이지
//메인 화면 -> 상속 예정
int OpenMainPage() {
	Page main_page("메인 메뉴", { "레시피 추천", "레시피 검색", "냉장고", "재료 구매", "마이페이지" });
	Opened_pages.push_back(main_page);
	main_page.PrintFront();
	main_page.PrintMenu("0. 프로그램 종료");
	//main_page.EnterMenu();
	//레시피 추천
	//레시피 검색
	//냉장고
	//재료 구매
	//마이페이지
	while (1) {
		int next_page = main_page.InputMenu();
		switch (next_page) {
		case 0:
			return 1;
		case 1:
			OpenRecommend();
			break;
		case 2:
			OpenSearch();
			break;
		case 3:
			OpenFridge();
			break;
		case 4:
			OpenBasket();
			break;
		case 5:
			OpenMyPage();
			break;
		default:
			cout << "잘못된 메뉴를 선택하였습니다."<< endl;
			continue;
		}
		break;
	}
	
	return 0;
}

//2레벨 페이지
// 레시피 추천 페이지
int OpenRecommend() {
	Page recommend_page("레시피 추천", { "냉장고 재료","선호 재료" });
	Opened_pages.push_back(recommend_page);
	recommend_page.PrintFront();
	cout << "추천 기준" << endl << endl;
	recommend_page.PrintMenu();
	int next_page = recommend_page.InputMenu();
	// 중요 : 추천 알고리즘은 따로 함수화 하고 추천 페이지는 또 따로 추천 페이지로
	// 필요한 입력 : 재고 상태 != 0 인 재료 리스트, 선호 재료 리스트, 모든 레시피 이름 리스트
	//1. 선호 재료 우선 냉장고 재료로 만들 수 있는 레시피 이름 리스트
	//2. 선호 재료 레시피 이름 리스트
	return 0;
}
//레시피 검색 페이지
int OpenSearch() {
	Page search_page("레시피 검색", {""});
	Opened_pages.push_back(search_page);
	search_page.PrintFront();
	//검색어 입력
	//검색 알고리즘
	// 필요한 입력 : 모든 레시피 이름 리스트, ~~~ 
	return 0;
}

// 냉장고 페이지
int OpenFridge() {
	vector <string> ingredient_list;
	Page fridge_page("냉장고", ingredient_list);
	//냉장고 속 재료를 메뉴화
	for (Ingredient ingredient : fridge) {
		string ingredient_name = ingredient.GetName();
		ingredient_list.push_back(ingredient_name);
	}
	fridge_page.PrintFront();
	fridge_page.PrintMenu();
	int next_page = fridge_page.InputMenu("재료 선택 : ");
	// 재료 & 현재 상태 표시
	// 재료 번호 입력시 : 재료 선호도, 재고 상태 -> 장바구니에 담기
	return 0;
}


// 마이페이지
int OpenMyPage() {
	int next_page = 0;
	// 읽은 레시피
	// 장바구니
	return next_page;
}


//3레벨 페이지
// 재료 페이지
// 레시피 페이지
// 1. 필요 재료 & 현재 상태 표시(재고 상태, 선호도)
// 1-1. 재료 번호 입력시 : 재료 선호도, 재료 소진임박, 소진 -> 장바구니에 담기
// 2. 레시피
// 2-1. 1. 평점 입력, 0 : 메인으로, -1 : 이전 페이지
//재료구매 페이지
//장바구니 페이지
int OpenBasket() {
	int next_page = 0;
	return next_page;
}
int OpenBuy() {
	int num = 0;
	return num;
}




int OpenFridgePage()
{
	return 0;
}

