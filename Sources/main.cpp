#include "header.h"
#define CATEGORY_SIZE 4

User user;
vector <Ingredient> fridge;
vector <Recipe> recipe_book;
vector <Page> Opened_pages;

int main(void) {
	cout << "������ ��õ ���α׷�";
	do {
		int exit = OpenMainPage();
	} while (!exit);
	
	

	
	
	// ��� ����
	
	//��� ��ȣ�� ����

	//��� ���� ����

	//�丮�� �ʿ��� ��� ����

	return 0;
}
/*
// �׸� ���� ����
Recipe recipe1;
int rating;
string category[CATEGORY_SIZE] = { "���̵�", "���� �ð�", "��", "������" };
cout << "--------------------------------" << endl;
cout << "������ �Է����ּ���" << endl;
for (string ctg : category) {
	cout << ctg << " : ";
	cin >> rating;
	recipe1.SetRating(ctg, rating);
}



// ����Ʈ ���� ���
user.PlusPoint(5);
*/