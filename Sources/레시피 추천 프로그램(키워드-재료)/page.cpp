#include "page.h"

extern User user;
// ���� ��� ������ Ŭ���� �ܺο��� ���ǵǾ�� �մϴ�.
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
// ������ ������Ʈ
void Page::UpdatePage() {}
// ������ ���(�⺻ �޴�, ����, �޴�)
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

// �޴� �Է�
int Page::InputMenu(string message) {
	int command = 0;

	cout << message;
	cin >> command;
	return command;
}

// opened_pages���� ������ ������ ���� 
void Page::DeletePage() {
	opened_pages.pop_back();
}

int Page::OpenPage() {
	return 0;
}

// ���� ������
MainPage::MainPage() : Page("���� �޴�", { "������ �˻�", "������ ��õ", "�����", "��ٱ���", "����������" }) {}

void MainPage::UpdatePage() {}

int MainPage::OpenPage() {
	PrintMenu("", { "- 1. ��������", "0. ���α׷� ����" });
	int command = InputMenu("�޴� ���� : ");
	switch (command) {
	
	case 1:
		//������ �˻�
		//opened_pages.push_back(new SearchPage());
		break;
	case 2:
		//������ ��õ �˰��� ���� �Լ�
		//opened_pages.push_back(new RecommendPage());
		break;
	case 3:
		//����� ������
		opened_pages.push_back(new FridgePage());
		break;
	case 4:
		//��� ���� ������
		opened_pages.push_back(new BasketPage());
		break;
	case 5:
		//����������
		opened_pages.push_back(new MyPage());
		break;
	case -1:
		DeletePage();
		break;
	case 0:
		return 1;
	default:
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}

// ������ ��õ ������
RecommendPage::RecommendPage(vector <Recipe> recipe_list) {
	title = "������ ��õ";
	for (Recipe recipe : recipe_list) {
		this->recipe_list.push_back(recipe);
		menu_list.push_back(recipe.GetTitle());
	}
}
void RecommendPage::UpdatePage(){}

// �߿� : ��õ �˰����� ���� �Լ�ȭ �ϰ� ��õ �������� �� ���� ��õ ��������
// �ʿ��� �Է� : ��� ���� != 0 �� ��� ����Ʈ, ��ȣ ��� ����Ʈ, ��� ������ �̸� ����Ʈ
//��õ �켱���� 1. ����� ��� 2. ��ȣ�� 3. ���� �̿�
// 1�� ������ : ������ ���� �켱������	 2�� ������ : �ֿ켱 ������ ������ �� �ְ�
int RecommendPage::OpenPage() {
	PrintMenu();
	int command = InputMenu("������ ���� : ");
	//opened_pages.push_back(main_page);
	//main_page.EnterMenu();
	//������ ��õ
	//������ �˻�
	//�����
	//��� ����
	//����������

	if (0 < command && command <= 10) {
		//opened_pages.push_back(new RecipePage(recipe_list[command - 1]));
	}
	else if (command == 0) {
		opened_pages.push_back(new MainPage());
	}
	else if (command == -1) {
		DeletePage();
		return 0;
	}
	else {
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}

/*
RecipePage::RecipePage(Recipe recipe)  {


}
*/


IngredientPage::IngredientPage(Ingredient* ingredient) : Page("��� ����") {
	vector <string > menus { "��ȣ ���� ����", "��� �߰�", "��� ���� �ӹ�", "��� ����", "��ٱ��Ͽ� ���", "�ٷ� ����" };
	for (string menu : menus) {
		menu_list.push_back(menu);
	}
	this->ingredient = ingredient;
	if (ingredient->GetPreference() == true) {
		menu_list[0] = "��ȣ ��� ����";
	}
}
void IngredientPage::UpdatePage() {
	if (ingredient->GetPreference() == true) {
		menu_list[0] = "��ȣ ��� ����";
	}
	else menu_list[0] = "��ȣ ���� ����";
}
void IngredientPage::PrintMenu(const vector <string>&basic_menu_list) {
	int i = 0;
	cout << endl << endl;
	cout << "--------------------------------" << endl;
	for (string basic_menu : basic_menu_list) {
		cout << basic_menu << "\t";
	}
	cout << endl;
	cout << title << endl << endl;
	cout << ingredient->GetName() << endl;
	if (ingredient->GetPreference() == true) {
		cout << endl << "��ȣ ���" << endl;
	}
	else cout << "        "<< endl;
	cout << i + 1 << ", " << menu_list[i] << endl;
	i++;
	cout <<endl << "��� ���� : ";
	switch (ingredient->GetStockState()) {
		case 0:
			cout << "���� (����)" << endl;
			break;
		case 1:
			cout << "���� �ӹ�" << endl;
			break;
		case 2:
			cout << "�����" << endl;
			break;
	}
	for (int j = 0; j < 3; j++) {
		cout << i + 1 << ", " << menu_list[i] << endl;
		i++;
	}
	cout << endl << "��� ����" << endl;
	for (int j = 0; j < 2; j++) {
		cout << i + 1 << ", " << menu_list[i] << endl;
		i++;
	}
	cout << endl;
}

int IngredientPage::OpenPage() {

	PrintMenu();
	int command = InputMenu("�޴� ���� : ");
	switch (command) {
	case 1:
		if (menu_list[0] == "��ȣ ���� ����") {
			ingredient->SetPreference(true);
		}
		else {
			ingredient->SetPreference(false);
		}
		break;
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
		// ��ٱ��Ͽ� ��� ��ٱ��� ������ ����
		ingredient->SetInBasket(true);
		opened_pages.push_back(new BasketPage());
		break;
	case 6:
		// ���� ������ ����
		opened_pages.push_back(new BuyPage(ingredient));
		break;
	case 0:
		opened_pages.push_back(new MainPage());
		break;
	case -1:
		DeletePage();
		break;
	default:
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}

FridgePage::FridgePage() : Page("�����") {
	for (Ingredient* ingredient : Ingredient::fridge) {
		string ingredient_name = ingredient->GetName();
		menu_list.push_back(ingredient_name);
	}
}
void FridgePage::UpdatePage() {
	menu_list.clear();
	for (Ingredient* ingredient : Ingredient::fridge) {
		string ingredient_name = ingredient->GetName();
		menu_list.push_back(ingredient_name);
	}
}

int FridgePage::OpenPage() {
	PrintMenu("����� ����ֽ��ϴ�.");
	int command = InputMenu("��� ���� : ");
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
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}
BasketPage::BasketPage() : Page("��ٱ���") {
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
	PrintMenu("��ٱ��Ͽ� ��� ��ǰ�� �����ϴ�.", {});
	char command = InputMenu("��ٱ��Ͽ� ��� ��ǰ���� �ٷ� �����Ͻðڽ��ϱ�? (Y / N) : ");
	if (command == 'Y' || command == 'y') {
		for (Ingredient* ingredient : basket_list) {
			ingredient->SetPurchased(true);
			ingredient->SetInBasket(false);
		}
		cout << "���Ű� �Ϸ�Ǿ����ϴ�." << endl;
	}
	else if (command == 'N' || command == 'n'){
		DeletePage();
		return 0;
	}
	else {
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}


BuyPage::BuyPage(Ingredient* item_to_buy) : Page("�ٷ� ����") {
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
	char command = InputMenu("�� ��ǰ�� �ٷ� �����Ͻðڽ��ϱ�? (Y / N) : ");
	if (command == 'Y' || command == 'y') {
		item_to_buy->SetPurchased(true);
		cout << "���Ű� �Ϸ�Ǿ����ϴ�." << endl;
		DeletePage();
	}
	else if (command == 'N' || command == 'n') {
		DeletePage();
	}
	else {
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}
MyPage::MyPage() : Page("���� ������") {}


void MyPage::PrintMenu(const vector <string>& basic_menu_list) {
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

	cout << "����Ʈ : " << user.GetPoint() << endl << endl;
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