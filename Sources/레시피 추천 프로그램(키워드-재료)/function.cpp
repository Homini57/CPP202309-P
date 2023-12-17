#include "page.h"
#include <fstream>
#include <sstream>
#include <string>
/*
extern vector <Recipe> recipe_book;
*/
//
void ReadIngredientData(){
	ifstream igd_data{ "ingredient_data.csv" };
	if (!igd_data.is_open()) {
		std::cerr << "Error" << std::endl;
		return;
	}
	
	string line;
	while (getline(igd_data, line)) {
		Ingredient* pigd = new Ingredient();
		istringstream iss{ line };
		string data;
		int i = 0;
		while (getline(iss, data, ',')) {
			switch (i % 5) {
			case 0:
				pigd->SetName(data);
				break;
			case 1:
				pigd->SetInBasket(stoi(data));
				break;
			case 2:
				pigd->SetPurchased(stoi(data));
				break;
			case 3:
				pigd->SetPreference(stoi(data));
				break;
			case 4:
				pigd->SetStockState(stoi(data));
				break;
			}
			i++;
		}
		Ingredient::fridge.push_back(pigd);
	}
	
	igd_data.close();
}

void SaveIngredientData(){
	ofstream igd_data{ "ingredient_data.csv" };
	if (!igd_data.is_open()) {
		std::cerr << "Error" << std::endl;
		return;
	}
	for (Ingredient* pigd : Ingredient::fridge) {
		string name;
		int in_basket, purchased, preference, stock_state;

		name = pigd->GetName();
		in_basket = pigd->GetInBasket();
		purchased = pigd->GetPurchased();
		preference = pigd->GetPreference();
		stock_state = pigd->GetStockState();
		igd_data << name << ",";
		igd_data << in_basket << "," << purchased << ",";
		igd_data << preference << "," << stock_state << "," << endl;
	}
	igd_data.close();
}


// ��ǰ�� �м� �� ��� �з�
string ClassifyIngredient() {
	string category; //�����̸��� ingredient�� ��������?
	return category;
}
// ������ ��Ḧ ����� ����


//2���� ������
// ������ ��õ ������
/*
/������ �˻� ������
int OpenSearch() {
	Page search_page("������ �˻�", {""});
	Opened_pages.push_back(search_page);
	search_page.PrintFront();
	//�˻��� �Է�
	//�˻� �˰���
	// �ʿ��� �Է� : ��� ������ �̸� ����Ʈ, ~~~
	return 0;
}
*/
/*
// ����� ������
int OpenFridge() {
	vector <string> ingredient_list;
	Page fridge_page("�����", ingredient_list);
	//����� �� ��Ḧ �޴�ȭ
	for (Ingredient ingredient : fridge) {
		string ingredient_name = ingredient.GetName();
		ingredient_list.push_back(ingredient_name);
	}
	fridge_page.PrintFront();
	fridge_page.PrintMenu();
	int next_page = fridge_page.InputMenu("��� ���� : ");
	// ��� & ���� ���� ǥ��
	// ��� ��ȣ �Է½� : ��� ��ȣ��, ��� ���� -> ��ٱ��Ͽ� ���
	return 0;
}

*/



// ������ ������
// 1. �ʿ� ��� & ���� ���� ǥ��(��� ����, ��ȣ��)
// 1-1. ��� ��ȣ �Է½� : ��� ��ȣ��, ��� �����ӹ�, ���� -> ��ٱ��Ͽ� ���
// 2. ������
// 2-1. 1. ���� �Է�, 0 : ��������, -1 : ���� ������