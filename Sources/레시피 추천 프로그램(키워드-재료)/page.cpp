#include "page.h"

//Page Class Method
Page::Page(string title, vector <string> menu_list) {
	this->title = title;
	// UpdatePage()
	// PrintMenu()
	// OpenPage()
	// InOpenedPages
	for (string menu : menu_list) {
		this->menu_list.push_back(menu);
	}
}

void Page::UpdatePage() {
	Page::Page(title, menu_list);
}

void Page::PrintMenu(const vector <string>& basic_menu_list) {
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	for (string basic_menu : basic_menu_list) {
		cout << basic_menu << "\t\t";
	}
	cout << "\n\n" << endl;
	cout << title << endl << endl;

	
	int i = 1;
	for (string menu : menu_list) {
		cout << " " << i << ". " << menu << endl;
		i++;
	}
	cout << endl;
}


int Page::InputMenu(string message) {
	int command = 0;

	cout << message;
	cin >> command;
	return command;
}

/*auto Page::EnterMenu(int page_num) {
	switch (page_num + 1) {
	case 1:
		Page next_page("다음 페이지", {"1번", "2번"});
		return next_page;
	}

}*/


// 이 메서드는 안필요할수도?
void Page::DeletePage() {
	//이전 페이지로 돌아가고 해당 페이지는 소멸자 사용하여 제거?
	opened_pages.pop_back();
}

int Page::OpenPage() {
	return 0;
}

// 메인 페이지
MainPage::MainPage() : Page("메인 메뉴", { "레시피 검색", "레시피 추천", "냉장고", "재료 구매?", "마이페이지" }) {}



int MainPage::OpenPage() {
	PrintMenu();
	int command = InputMenu("메뉴 선택 : ");
	//Opened_pages.push_back(main_page);
	//main_page.EnterMenu();
	//레시피 추천
	//레시피 검색
	//냉장고
	//재료 구매
	//마이페이지
	
	switch (command) {
	
	case 1:
		//opened_pages.push_back(new SearchPage());
		break;
	case 2:
		//레시피 추천 알고리즘 관련 함수
		//opened_pages.push_back(new RecommendPage());
		break;
	case 3:
		//opened_pages.push_back(new FridgePage());
		break;
	case 4:
		//opened_pages.push_back(new BasketPage());
		break;
	case 5:
		//opened_pages.push_back(new MyPage());
		break;
	case 0:
		return 1;
	case -1:
		DeletePage();
		break;
	default:
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}
// 레시피 추천 : 

RecommendPage::RecommendPage(vector <Recipe> recipe_list) {
	title = "레시피 추천";
	for (Recipe recipe : recipe_list) {
		this->recipe_list.push_back(recipe);
		menu_list.push_back(recipe.GetTitle());
	}
}


// 중요 : 추천 알고리즘은 따로 함수화 하고 추천 페이지는 또 따로 추천 페이지로
// 필요한 입력 : 재고 상태 != 0 인 재료 리스트, 선호 재료 리스트, 모든 레시피 이름 리스트
//추천 우선순위 1. 냉장고 재료 2. 선호도 3. 자주 이용
// 1번 선택지 : 무조건 위의 우선순위로	 2번 선택지 : 최우선 순위를 선택할 수 있게
int RecommendPage::OpenPage() {
	PrintMenu();
	int command = InputMenu("레시피 선택 : ");
	//Opened_pages.push_back(main_page);
	//main_page.EnterMenu();
	//레시피 추천
	//레시피 검색
	//냉장고
	//재료 구매
	//마이페이지

	if (0 < command && command <= 10) {
		opened_pages.push_back(new RecipePage(recipe_list[command - 1]));
	}
	else if (command == 0) {
		return 1;
	}
	else if (command == -1) {
		DeletePage();
		return 0;
	}
	else {
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}



/*
RecipePage::RecipePage(Recipe recipe)  {


}
*/


IngredientPage::IngredientPage(Ingredient ingredient) : Page("재료 관리", { "선호 재료로 지정",
	"재료 추가","재료 소진 임박", "재료 소진", "장바구니에 담기", "바로 구매"}) {
	this->ingredient = ingredient;
	if (ingredient.GetPreference() == true) {
		menu_list[0] = "선호 재료 해제";
	}
}


void IngredientPage::PrintMenu(const vector <string>& basic_menu_list) {
	int i = 0;
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	for (string basic_menu : basic_menu_list) {
		cout << basic_menu << "\t\t";
	}
	cout << endl;
	cout << title << endl << endl;
	cout << ingredient.GetName() << endl;
	if (ingredient.GetPreference() == true) {
		cout << endl << "선호 재료" << endl;
	}
	else cout << "        "<< endl;
	cout << i + 1 << ", " << menu_list[i] << endl;
	i++;

	cout <<endl << "재고 상태 : ";
	switch (ingredient.GetStockState()) {
		case 0:
			cout << "소진 (없음)" << endl;
		case 1:
			cout << "소진 임박" << endl;
		case 2:
			cout << "충분함" << endl;
	}
	for (int j = 0; j < 3; j++) {
		cout << i + 1 << ", " << menu_list[i] << endl;
		i++;
	}

	cout << endl << "재료 구매" << endl;
	for (int j = 0; j < 2; j++) {
		cout << i + 1 << ", " << menu_list[i] << endl;
		i++;
	}
	cout << endl;
}

int IngredientPage::OpenPage() {
	PrintMenu();
	int command = InputMenu("메뉴 선택 : ");
	//Opened_pages.push_back(main_page);
	//main_page.EnterMenu();
	//레시피 추천
	//레시피 검색
	//냉장고
	//재료 구매
	//마이페이지

	switch (command) {

	case 1:
		if (menu_list[0] == "선호 재료로 지정") {
			ingredient.SetPreference(true);
		}
		else {
			ingredient.SetPreference(false);
		}
		break;
	case 2:
		ingredient.SetStockState(2);
		break;
	case 3:
		ingredient.SetStockState(1);
		break;
	case 4:
		ingredient.SetStockState(0);
		break;
	case 5:
		// 장바구니에 담고 장바구니 페이지 열기
		//opened_pages.push_back(new BasketPage());
		break;
	case 6:
		// 구매 페이지 열기
		//opened_pages.push_back(new BuyPage());
	case 0:
		return 1;
	case -1:
		DeletePage();
		break;
	default:
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}