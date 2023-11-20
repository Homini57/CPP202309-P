#include "헤더.h"
// 제품명 분석 및 재료 분류
string ClassifyIngredient() {
	string category; //변수이름이 ingredient가 나으려나?
	return category;
}
// 구매한 재료를 냉장고에 저장


// 페이지 클래스를 만들어서 상속해야 하나?

//1레벨 페이지
//메인 화면
int OpneMainPage() {
	int next_page = 0;
	cout << "--------------------------------" << endl;
	cout << "-1. 이전 페이지" << endl;
	vector<string> main_menu { "레시피 추천", "레시피 검색", "냉장고", "재료 구매", "마이페이지" };
	int i = 1;
	for (string menu : main_menu) {
		cout <<  i << menu << endl;
		i++;
	}
	cout << "메뉴 번호 선택 : ";
	cin >> next_page;
	switch (next_page + 1) {
		case 1 :
			OpenRecommendation();

	}
	//레시피 추천
	//레시피 검색
	//냉장고
	//재료 구매
	//마이페이지
	return next_page;
}
//2레벨 페이지
// 레시피 추천 페이지
int OpenRecommendation() {
	int next_page = 0;
	// 중요 : 추천 알고리즘은 따로 함수화 하고 추천 페이지는 또 따로 추천 페이지로
	// 필요한 입력 : 재고 상태 != 0 인 재료 리스트, 선호 재료 리스트, 모든 레시피 이름 리스트
	//1. 선호 재료 우선 냉장고 재료로 만들 수 있는 레시피 이름 리스트
	//2. 선호 재료 레시피 이름 리스트
	return next_page;
}
//레시피 검색 페이지
int OpenSearch() {
	int next_page = 0;
	//검색 알고리즘은 따로 만들기
	// 필요한 입력 : 모든 레시피 이름 리스트, ~~~ 
	return next_page;
}

// 냉장고 페이지
int OpenFridge() {
	int next_page = 0;
	// 재료 & 현재 상태 표시
	// 재료 번호 입력시 : 재료 선호도, 재고 상태 -> 장바구니에 담기
	return next_page;
}

//재료구매 페이지
int OpenBuy() {
	int num = 0;
	return num;
}
// 마이페이지
int OpenMyPage() {
	int next_page = 0;
	// 읽은 레시피
	// 장바구니
	return next_page;
}

//장바구니 페이지
int OpenBasket() {
	int next_page = 0;
	return next_page;
}
//3레벨 페이지
// 재료 페이지
// 레시피 페이지
// 1. 필요 재료 & 현재 상태 표시(재고 상태, 선호도)
// 1-1. 재료 번호 입력시 : 재료 선호도, 재료 소진임박, 소진 -> 장바구니에 담기
// 2. 레시피
// 2-1. 1. 평점 입력, 0 : 메인으로, -1 : 이전 페이지

int OpenNextPage() {
	int next_page = 0;
	return next_page;
}
