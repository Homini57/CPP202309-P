#include "page.h"
User user;
int main(void) {
	ReadIngredientData();
	// ���α׷� ���� �� ù ������ : MainPage
	Page::opened_pages.push_back(new MainPage());
	// ���α׷��� �̸� ���
	cout << "������ ��õ ���α׷�" << endl;
	// OpenPage���� �߰��� �ֽ� ������ or �ֱ� open�� �������� open
	while (1){
		int last_index = (int)Page::opened_pages.size() - 1;
		auto next_page = Page::opened_pages[last_index];
		next_page->UpdatePage();
		int terminate = next_page->OpenPage();
			// ���α׷� ���� ��
			if (terminate == 1) {
				// ������ �����͸� ����
				SaveIngredientData();
				break;
			}
	}
	return 0;
}


