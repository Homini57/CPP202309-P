#include "page.h"

User user;
vector <Ingredient> fridge;
vector <Recipe> recipe_book;


int main(void) {


	Page page; // 동적메모리로 생성할까?

	page.opened_pages.push_back(new MainPage());
	while (1){
		int last_index = page.opened_pages.size() - 1;
		auto next_page = page.opened_pages[last_index];
		
		int terminate = next_page->OpenPage(); // 다음 페이지 생성 or 현재 페이지 삭제 or 종료 메시지 ?
			if (terminate == 1) {
				// 종료 전 실행문
				break;
			}
	}
        


	/*
	cout << "레시피 추천 프로그램";
	do {
		int exit = OpenMainPage();
	} while (!exit);
	
	
	*/

	// 재료 관리
	
	//재료 선호도 관리

	//재료 소진 관리

	//요리에 필요한 재료 구매

	return 0;
}


