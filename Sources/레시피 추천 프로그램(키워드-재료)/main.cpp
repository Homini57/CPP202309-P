#include "page.h"

User user;
vector <Ingredient> fridge;
vector <Recipe> recipe_book;


int main(void) {


	Page page; // �����޸𸮷� �����ұ�?

	page.opened_pages.push_back(new MainPage());
	while (1){
		int last_index = page.opened_pages.size() - 1;
		auto next_page = page.opened_pages[last_index];
		
		int terminate = next_page->OpenPage(); // ���� ������ ���� or ���� ������ ���� or ���� �޽��� ?
			if (terminate == 1) {
				// ���� �� ���๮
				break;
			}
	}
        


	/*
	cout << "������ ��õ ���α׷�";
	do {
		int exit = OpenMainPage();
	} while (!exit);
	
	
	*/

	// ��� ����
	
	//��� ��ȣ�� ����

	//��� ���� ����

	//�丮�� �ʿ��� ��� ����

	return 0;
}


