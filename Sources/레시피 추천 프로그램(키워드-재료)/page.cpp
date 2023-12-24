#include "page.h"

extern User user;
vector<Page*> Page::opened_pages;

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
// 페이지 업데이트
void Page::UpdatePage() {}
// 페이지 출력(기본 메뉴, 제목, 메뉴)
void Page::PrintMenu(string none_message, const vector <string>& basic_menu_list) {
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	int i = 1;
	for (string basic_menu : basic_menu_list) {
		cout << basic_menu << "\t";
		if (i % 2 == 0) {
			cout << endl;
		}
		i++;
	}
	cout << endl << endl;
	cout << title << endl << endl;

	if (menu_list.size() == 0) {
		cout  << none_message << endl << endl;
		return;
	}
	i = 1;
	for (string menu : menu_list) {
		cout << " " << i << ". " << menu << endl;
		i++;
	}
	cout << endl;
}

// 메뉴 입력
int Page::InputMenu(string message) {
	int command = 0;

	cout << message;
	cin >> command;
	return command;
}

// opened_pages에서 마지막 페이지 삭제 
void Page::DeletePage() {
	opened_pages.pop_back();
}

int Page::OpenPage() {
	return 0;
}

// 메인 페이지
MainPage::MainPage() : Page("메인 메뉴", { "레시피 검색", "레시피 추천", "냉장고", "장바구니", "마이페이지" }) {}

void MainPage::UpdatePage() {}

int MainPage::OpenPage() {
	PrintMenu("", { "- 1. 이전으로", "0. 프로그램 종료" });
	int command = InputMenu("메뉴 선택 : ");
	switch (command) {
	
	case 1:
		//레시피 검색
		opened_pages.push_back(new SearchPage());
		break;
	case 2:
		//레시피 추천 알고리즘 관련 함수
		opened_pages.push_back(new RecommendPage());
		break;
	case 3:
		//냉장고 페이지
		opened_pages.push_back(new FridgePage());
		break;
	case 4:
		//재료 구매 페이지
		opened_pages.push_back(new BasketPage());
		break;
	case 5:
		//마이페이지
		opened_pages.push_back(new MyPage());
		break;
	case -1:
		DeletePage();
		break;
	case 0:
		return 1;
	default:
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}

RecipePage::RecipePage(string recipe_title) :Page("필요한 재료"), recipe(TitleToRecipe(recipe_title)) {
	// 메뉴 : 필요한 재료
	vector <string> ingredients = recipe.GetIngredients();
	for (string ingredient : ingredients) {
		menu_list.push_back(ingredient);
	}
}
void RecipePage::UpdatePage(){}

int RecipePage::OpenPage(){
	// 페이지 제목 : 레시피 제목
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	cout << recipe.GetTitle();
	// 필요한 재료들 출력
	PrintMenu();
	// 요리 과정 출력
	cout << endl << "요리 과정" << endl << endl;
	int i = 1;
	vector <string> process_list = recipe.GetProcessList();
	for (string process : process_list) {
		cout << " " << i << "." << process << endl;
		i++;
	}
	// 평점 출력
	map <string, int> ratings = recipe.GetRatings();
	cout << endl << "평점" << endl;
	vector <string> category_list { "맛", "가성비", "조리시간", "난이도" };
	for (int i = 0; i < CATEGORY_SIZE; i++) {
		string category = category_list[i];
		cout << " " << category << ":" << ratings[category] << endl;
	}
	// 메뉴로 재료들을 입력
	cout << endl << "-2. 평점 입력" << endl << endl;
	int command = InputMenu("\n재료 선택 : ");
	if (1 <= command && command <= menu_list.size()) {
		Ingredient* ingredient_to_watch = NameToIngredient(menu_list[command - 1]);
		opened_pages.push_back(new IngredientPage(ingredient_to_watch));
	}
	else if (command == 0) { opened_pages.push_back(new MainPage()); }
	else if (command == -1) {
		DeletePage();
		return 0;
	}
	//  -2 입력시 평점 변경
	else if (command == -2) {
		recipe.InputRating();
	}
	else {
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}

//재료 페이지의 메뉴 설정 
IngredientPage::IngredientPage(Ingredient* ingredient) : Page("재료 관리") {
	vector <string > menus { "선호 재료로 지정", "재료 추가", "재료 소진 임박", "재료 소진", "장바구니에 담기", "바로 구매" };
	for (string menu : menus) {
		menu_list.push_back(menu);
	}
	this->ingredient = ingredient;
	if (ingredient->GetPreference() == true) {
		menu_list[0] = "선호 재료 해제";
	}
}
void IngredientPage::UpdatePage() {
	if (ingredient->GetPreference() == true) {
		menu_list[0] = "선호 재료 해제";
	}
	else menu_list[0] = "선호 재료로 지정";
}
void IngredientPage::PrintMenu(const vector <string>&basic_menu_list) {
	int i = 0;
	// 기본 메뉴와 재료 이름 출력
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	for (string basic_menu : basic_menu_list) {
		cout << basic_menu << "\t";
	}
	cout << endl;
	cout << title << endl << endl;
	cout << ingredient->GetName() << endl;
	// 재료 선호 상태 , 선호 상태 변경 메뉴 출력 
	if (ingredient->GetPreference() == true) {
		cout << endl << "선호 재료" << endl;
	}
	else cout << "        "<< endl;
	cout << i + 1 << ", " << menu_list[i] << endl;
	i++;
	// 재고 상태, 재고 상태 변경 메뉴 출력
	cout <<endl << "재고 상태 : ";
	switch (ingredient->GetStockState()) {
		case 0:
			cout << "소진 (없음)" << endl;
			break;
		case 1:
			cout << "소진 임박" << endl;
			break;
		case 2:
			cout << "충분함" << endl;
			break;
	}
	for (int j = 0; j < 3; j++) {
		cout << i + 1 << ", " << menu_list[i] << endl;
		i++;
	}
	// 재료 구매 메뉴 출력
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
	switch (command) {
		// 선호 상태 변경
	case 1:
		if (menu_list[0] == "선호 재료로 지정") {
			ingredient->SetPreference(true);
		}
		else {
			ingredient->SetPreference(false);
		}
		break;
		// 재고 상태 변경
	case 2:
		ingredient->SetStockState(2);
		break;
	case 3:
		ingredient->SetStockState(1);
		break;
	case 4:
		ingredient->SetStockState(0);
		break;
	case 5:
		// 장바구니에 담고 장바구니 페이지 열기
		ingredient->InFridge();
		ingredient->SetInBasket(true);
		opened_pages.push_back(new BasketPage());
		break;
	case 6:
		// 구매 페이지 열기
		opened_pages.push_back(new BuyPage(ingredient));
		break;
		// 메인 페이지
	case 0:
		opened_pages.push_back(new MainPage());
		break;
	case -1:
		DeletePage();
		break;
	default:
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}

// 레시피 추천 페이지
RecommendPage::RecommendPage() :Page("레시피 추천") {
	vector <string> recipe_title_list = RecommendRecipe();
	for (string recipe_title : recipe_title_list) {
		menu_list.push_back(recipe_title);
	}
}
void RecommendPage::UpdatePage() {
	menu_list.clear();
	vector <string> recipe_title_list = RecommendRecipe();
	for (string recipe_title : recipe_title_list) {
		menu_list.push_back(recipe_title);
	}
}

int RecommendPage::OpenPage() {

	PrintMenu();
	int command = InputMenu("레시피 선택 : ");
	// 선택한 레시피의 레시피 페이지 열기
	if (0 < command && command <= 10) {
		opened_pages.push_back(new RecipePage(menu_list[command - 1]));
	}
	// 메인 페이지 열기
	else if (command == 0) {
		opened_pages.push_back(new MainPage());
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

SearchPage::SearchPage() : Page("레시피 검색") {}
void SearchPage::UpdatePage() {}
int SearchPage::OpenPage() {
	// 레시피 검색
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	cout << title << endl << endl << "검색 : ";
	string search_text;
	cin >> search_text;
	// 검색 단어를 기반으로 레시피 메뉴 출력
	menu_list = SearchRecipe(search_text);
	PrintMenu();
	int command = InputMenu("레시피 선택 : ");
	// 선택한 레시피의 레시피 페이지 열기
	if (0 < command && command <= menu_list.size()) {
		opened_pages.push_back(new RecipePage(menu_list[command - 1]));
	}
	else if (command == 0) {
		opened_pages.push_back(new MainPage());
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

//냉장고 페이지
FridgePage::FridgePage() : Page("냉장고") {
	for (Ingredient* ingredient : Ingredient::fridge) {
		if (ingredient->GetStockState() != 0) {
			string ingredient_name = ingredient->GetName();
			menu_list.push_back(ingredient_name);
		}
	}
}
void FridgePage::UpdatePage() {
	menu_list.clear();
	for (Ingredient* ingredient : Ingredient::fridge) {
		if (ingredient->GetStockState() != 0) {
			string ingredient_name = ingredient->GetName();
			menu_list.push_back(ingredient_name);
		}
	}
}
int FridgePage::OpenPage() {
	if (menu_list.size() == 0) {
		cout << "냉장고가 비어있습니다.";
	}
	PrintMenu();
	int command = InputMenu("재료 선택 : ");
	// 선택한 재료의 재료 페이지 열기
	if (1 <= command && command <= Ingredient::fridge.size()) {
		Ingredient* ingredient_to_watch = Ingredient::fridge[command - 1];
		opened_pages.push_back(new IngredientPage(ingredient_to_watch));
	}
	else if (command == 0) { opened_pages.push_back(new MainPage()); }
	else if (command == -1) {
		DeletePage();
		return 0;
	}
	else {
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}

// 장바구니 페이지
BasketPage::BasketPage() : Page("장바구니") {
	for (Ingredient* ingredient : Ingredient::fridge) {
		bool in_basket = ingredient->GetInBasket();
		if (in_basket == true) { basket_list.push_back(ingredient); }
	}
	for (Ingredient* ingredient : basket_list) {
		string ingredient_name = ingredient->GetName();
		menu_list.push_back(ingredient_name);
	}
}
void BasketPage::UpdatePage(){
	basket_list.clear();
	menu_list.clear();
	for (Ingredient* ingredient : Ingredient::fridge) {
		bool in_basket = ingredient->GetInBasket();
		if (in_basket == true) { basket_list.push_back(ingredient); }
	}
	for (Ingredient* ingredient : basket_list) {
		string ingredient_name = ingredient->GetName();
		menu_list.push_back(ingredient_name);
	}
}
char BasketPage::InputMenu(string message) {
	char command = 0;
	cout << message;
	cin >> command;
	return command;
}
int BasketPage::OpenPage() {
	PrintMenu("장바구니에 담긴 상품이 없습니다.", {});
	// 장바구니에서 재료 구매시 장바구니 상태 해제, 구매 상태 지정
	char command = InputMenu("장바구니에 담긴 상품들을 바로 구매하시겠습니까? (Y / N) : ");
	if (command == 'Y' || command == 'y') {
		for (Ingredient* ingredient : basket_list) {
			ingredient->SetPurchased(true);
			ingredient->SetInBasket(false);
		}
		cout << "구매가 완료되었습니다." << endl;
	}
	else if (command == 'N' || command == 'n'){
		DeletePage();
		return 0;
	}
	else {
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}

// 구매 페이지
BuyPage::BuyPage(Ingredient* item_to_buy) : Page("바로 구매") {
	this->item_to_buy = item_to_buy;
	menu_list.push_back(item_to_buy->GetName());
}
void BuyPage::UpdatePage(){}
char BuyPage::InputMenu(string message){
	char command = 0;
	cout << message;
	cin >> command;
	return command;
}
int BuyPage::OpenPage() {
	PrintMenu("",{});
	// 재료 구매 시 재료를 냉장고에 넣고 구매 상태 지정
	char command = InputMenu("위 상품을 바로 구매하시겠습니까? (Y / N) : ");
	if (command == 'Y' || command == 'y') {
		item_to_buy->InFridge();
		item_to_buy->SetPurchased(true);
		cout << "구매가 완료되었습니다." << endl;
		DeletePage();
	}
	else if (command == 'N' || command == 'n') {
		DeletePage();
	}
	else {
		cout << "잘못된 메뉴를 선택하였습니다." << endl;
	}
	return 0;
}
MyPage::MyPage() : Page("마이 페이지") {}
void MyPage::UpdatePage() {}

// 마이 페이지
void MyPage::PrintMenu(const vector <string>& basic_menu_list) {
	user.ReadUserPoint();
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	int i = 1;
	for (string basic_menu : basic_menu_list) {
		cout << basic_menu << "\t";
		if (i % 2 == 0) {
			cout << endl;
		}
		i++;
	}
	cout << "\n\n" << endl;
	cout << title << endl << endl;
	cout << "포인트 : " << user.GetPoint() << endl << endl;
}
int MyPage::OpenPage() {
	PrintMenu();
	int command = InputMenu();
	switch (command) {
	case 0:
		opened_pages.push_back(new MainPage());
		break;
	case -1:
		DeletePage();
		break;
	}
	return 0;
}