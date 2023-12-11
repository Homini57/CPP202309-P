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
		Page next_page("���� ������", {"1��", "2��"});
		return next_page;
	}

}*/


// �� �޼���� ���ʿ��Ҽ���?
void Page::DeletePage() {
	//���� �������� ���ư��� �ش� �������� �Ҹ��� ����Ͽ� ����?
	opened_pages.pop_back();
}

int Page::OpenPage() {
	return 0;
}

// ���� ������
MainPage::MainPage() : Page("���� �޴�", { "������ �˻�", "������ ��õ", "�����", "��� ����?", "����������" }) {}



int MainPage::OpenPage() {
	PrintMenu();
	int command = InputMenu("�޴� ���� : ");
	//Opened_pages.push_back(main_page);
	//main_page.EnterMenu();
	//������ ��õ
	//������ �˻�
	//�����
	//��� ����
	//����������
	
	switch (command) {
	
	case 1:
		//opened_pages.push_back(new SearchPage());
		break;
	case 2:
		//������ ��õ �˰��� ���� �Լ�
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
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}
// ������ ��õ : 

RecommendPage::RecommendPage(vector <Recipe> recipe_list) {
	title = "������ ��õ";
	for (Recipe recipe : recipe_list) {
		this->recipe_list.push_back(recipe);
		menu_list.push_back(recipe.GetTitle());
	}
}


// �߿� : ��õ �˰����� ���� �Լ�ȭ �ϰ� ��õ �������� �� ���� ��õ ��������
// �ʿ��� �Է� : ��� ���� != 0 �� ��� ����Ʈ, ��ȣ ��� ����Ʈ, ��� ������ �̸� ����Ʈ
//��õ �켱���� 1. ����� ��� 2. ��ȣ�� 3. ���� �̿�
// 1�� ������ : ������ ���� �켱������	 2�� ������ : �ֿ켱 ������ ������ �� �ְ�
int RecommendPage::OpenPage() {
	PrintMenu();
	int command = InputMenu("������ ���� : ");
	//Opened_pages.push_back(main_page);
	//main_page.EnterMenu();
	//������ ��õ
	//������ �˻�
	//�����
	//��� ����
	//����������

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
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}



/*
RecipePage::RecipePage(Recipe recipe)  {


}
*/


IngredientPage::IngredientPage(Ingredient ingredient) : Page("��� ����", { "��ȣ ���� ����",
	"��� �߰�","��� ���� �ӹ�", "��� ����", "��ٱ��Ͽ� ���", "�ٷ� ����"}) {
	this->ingredient = ingredient;
	if (ingredient.GetPreference() == true) {
		menu_list[0] = "��ȣ ��� ����";
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
		cout << endl << "��ȣ ���" << endl;
	}
	else cout << "        "<< endl;
	cout << i + 1 << ", " << menu_list[i] << endl;
	i++;

	cout <<endl << "��� ���� : ";
	switch (ingredient.GetStockState()) {
		case 0:
			cout << "���� (����)" << endl;
		case 1:
			cout << "���� �ӹ�" << endl;
		case 2:
			cout << "�����" << endl;
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
	//Opened_pages.push_back(main_page);
	//main_page.EnterMenu();
	//������ ��õ
	//������ �˻�
	//�����
	//��� ����
	//����������

	switch (command) {

	case 1:
		if (menu_list[0] == "��ȣ ���� ����") {
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
		// ��ٱ��Ͽ� ��� ��ٱ��� ������ ����
		//opened_pages.push_back(new BasketPage());
		break;
	case 6:
		// ���� ������ ����
		//opened_pages.push_back(new BuyPage());
	case 0:
		return 1;
	case -1:
		DeletePage();
		break;
	default:
		cout << "�߸��� �޴��� �����Ͽ����ϴ�." << endl;
	}
	return 0;
}