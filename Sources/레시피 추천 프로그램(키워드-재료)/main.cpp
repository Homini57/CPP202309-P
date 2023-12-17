#include "page.h"
User user;
void ReadIngredientData();
void SaveIngredientData();

vector <Recipe> recipe_book;


int main(void) {
	ReadIngredientData();
	Page::opened_pages.push_back(new MainPage());
	cout << "������ ��õ ���α׷�" << endl;
	while (1){
		int last_index = (int)Page::opened_pages.size() - 1;
		auto next_page = Page::opened_pages[last_index];
		next_page->UpdatePage();
		int terminate = next_page->OpenPage();
			if (terminate == 1) {
				// ���� �� ���๮
				SaveIngredientData();
				break;
			}
	}
	return 0;
}


