#include "���.h"
#define CATEGORY_SIZE 4

User user;
vector <Ingredient> fidge;
vector <Recipe> recipe_book;

int main(void) {
	User my_user;
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
	my_user.PlusPoint(5);

	
	// ��� ����
	
	//��� ��ȣ�� ����

	//��� ���� ����

	//�丮�� �ʿ��� ��� ����

	return 0;
}

