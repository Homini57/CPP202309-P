#include "���.h"

#define CATEGORY_SIZE 4
void InReviewScore(int score, string category) {

}
int PointByReview(int a);
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
		recipe1.Set_rating(ctg, rating);
	}

	

	// ����Ʈ ���� ���
	my_user.plus_point(5);

	
	// ��� ����
	
	//��� ��ȣ�� ����

	//��� ���� ����

	//�丮�� �ʿ��� ��� ����

	return 0;
}


int PointByReview(int a){
	return 0;
}