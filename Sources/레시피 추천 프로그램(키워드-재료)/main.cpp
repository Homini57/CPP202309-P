#include "page.h"
User user;
int main(void) {
	ReadIngredientData();
	// 프로그램 시작 시 첫 페이지 : MainPage
	Page::opened_pages.push_back(new MainPage());
	// 프로그램의 이름 출력
	cout << "레시피 추천 프로그램" << endl;
	// OpenPage에서 추가된 최신 페이지 or 최근 open한 페이지를 open
	while (1){
		int last_index = (int)Page::opened_pages.size() - 1;
		auto next_page = Page::opened_pages[last_index];
		next_page->UpdatePage();
		int terminate = next_page->OpenPage();
			// 프로그램 종료 시
			if (terminate == 1) {
				// 재료들의 데이터를 저장
				SaveIngredientData();
				break;
			}
	}
	return 0;
}


