#include "���.h"
// ��ǰ�� �м� �� ��� �з�
string ClassifyIngredient() {
	string category; //�����̸��� ingredient�� ��������?
	return category;
}
// ������ ��Ḧ ������� ����


// ������ Ŭ������ ���� ����ؾ� �ϳ�?
int OpenPage(int first = 0, int second = 0, int third = 0, int forth = 0, int fifth = 0) {
	int next_page = 0;
	return next_page;
}

//ù ������ ȭ��
int OpneMainPage() {
	int next_page = 0;
	cout << "--------------------------------" << endl;
	cout << "-1. ���� ������" << endl;
	vector<string> main_menu { "������ ��õ", "������ �˻�", "�����", "��� ����", "����������" };
	int i = 1;
	for (string menu : main_menu) {
		cout <<  i << menu << endl;
		i++;
	}
	cout << "�޴� ��ȣ ���� : ";
	cin >> next_page;
	switch (next_page + 1) {
		case 1 :
			OpenRecommendation();

	}
	//������ ��õ
	//������ �˻�
	//�����
	//��� ����
	//����������
	return next_page;
}
// ������ ��õ ������
int OpenRecommendation() {
	int next_page = 0;
	//1. ��ȣ ��� �켱 ����� ���� ���� �� �ִ� ������ �̸� ����Ʈ
	//2. ��ȣ ��� ������ �̸� ����Ʈ
	return next_page;
}
//������ �˻� ������
int OpenSearch() {
	int next_page = 0;
	return next_page;
}
// ������ ������
// 1. �ʿ� ��� & ���� ���� ǥ��(��� ����, ��ȣ��)
// 1-1. ��� ��ȣ �Է½� : ��� ��ȣ��, ��� �����ӹ�, ���� -> ��ٱ��Ͽ� ���
// 2. ������
// 2-1. 1. ���� �Է�, 0 : ��������, -1 : ���� ������

// ����� ������
int OpenFridge() {
	int next_page = 0;
	// ��� & ���� ���� ǥ��
	// ��� ��ȣ �Է½� : ��� ��ȣ��, ��� ���� -> ��ٱ��Ͽ� ���
	return next_page;
}

//��ᱸ�� ������
int OpenBuy() {

}
// ����������
int OpenMyPage() {
	int next_page = 0;
	// ���� ������
	// ��ٱ���
	return next_page;
}

//��ٱ��� ������
int OpenBasket() {
	int next_page = 0;
	return next_page;
}