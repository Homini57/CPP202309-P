#include "page.h"
User user;
void ReadIngredientData();
void SaveIngredientData();

vector <Recipe> recipe_book;


int main(void) {
	ReadIngredientData();
	Page::opened_pages.push_back(new MainPage());
	cout << "레시피 추천 프로그램" << endl;
	while (1){
		int last_index = (int)Page::opened_pages.size() - 1;
		auto next_page = Page::opened_pages[last_index];
		next_page->UpdatePage();
		int terminate = next_page->OpenPage();
			if (terminate == 1) {
				// 종료 전 실행문
				SaveIngredientData();
				break;
			}
	}
	return 0;
}


