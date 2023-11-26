#include "header.h"
#define CATEGORY_SIZE 4


extern vector <Ingredient> fridge;
extern vector <Recipe> recipe_book;
extern vector <Page> Opened_pages;
// ��ǰ�� �м� �� ��� �з�
string ClassifyIngredient() {
	string category; //�����̸��� ingredient�� ��������?
	return category;
}
// ������ ��Ḧ ����� ����


// ������ Ŭ������ ���� ����ؾ� �ϳ�?

//1���� ������
//���� ȭ�� -> ��� ����
int OpenMainPage() {
	Page main_page("���� �޴�", { "������ ��õ", "������ �˻�", "�����", "��� ����", "����������" });
	Opened_pages.push_back(main_page);
	main_page.PrintFront();
	main_page.PrintMenu("0. ���α׷� ����");
	//main_page.EnterMenu();
	//������ ��õ
	//������ �˻�
	//�����
	//��� ����
	//����������
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
			cout << "�߸��� �޴��� �����Ͽ����ϴ�."<< endl;
			continue;
		}
		break;
	}
	
	return 0;
}

//2���� ������
// ������ ��õ ������
int OpenRecommend() {
	Page recommend_page("������ ��õ", { "����� ���","��ȣ ���" });
	Opened_pages.push_back(recommend_page);
	recommend_page.PrintFront();
	cout << "��õ ����" << endl << endl;
	recommend_page.PrintMenu();
	int next_page = recommend_page.InputMenu();
	// �߿� : ��õ �˰����� ���� �Լ�ȭ �ϰ� ��õ �������� �� ���� ��õ ��������
	// �ʿ��� �Է� : ��� ���� != 0 �� ��� ����Ʈ, ��ȣ ��� ����Ʈ, ��� ������ �̸� ����Ʈ
	//1. ��ȣ ��� �켱 ����� ���� ���� �� �ִ� ������ �̸� ����Ʈ
	//2. ��ȣ ��� ������ �̸� ����Ʈ
	return 0;
}
//������ �˻� ������
int OpenSearch() {
	Page search_page("������ �˻�", {""});
	Opened_pages.push_back(search_page);
	search_page.PrintFront();
	//�˻��� �Է�
	//�˻� �˰���
	// �ʿ��� �Է� : ��� ������ �̸� ����Ʈ, ~~~ 
	return 0;
}

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


// ����������
int OpenMyPage() {
	int next_page = 0;
	// ���� ������
	// ��ٱ���
	return next_page;
}


//3���� ������
// ��� ������
// ������ ������
// 1. �ʿ� ��� & ���� ���� ǥ��(��� ����, ��ȣ��)
// 1-1. ��� ��ȣ �Է½� : ��� ��ȣ��, ��� �����ӹ�, ���� -> ��ٱ��Ͽ� ���
// 2. ������
// 2-1. 1. ���� �Է�, 0 : ��������, -1 : ���� ������
//��ᱸ�� ������
//��ٱ��� ������
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

