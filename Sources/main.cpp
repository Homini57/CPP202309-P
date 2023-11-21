#include "header.h"
#define CATEGORY_SIZE 4

User user;
vector <Ingredient> fridge;
vector <Recipe> recipe_book;
vector <Page> Opened_pages;

int main(void) {
	cout << "레시피 추천 프로그램";
	do {
		int exit = OpenMainPage();
	} while (!exit);
	
	

	
	
	// 재료 관리
	
	//재료 선호도 관리

	//재료 소진 관리

	//요리에 필요한 재료 구매

	return 0;
}
/*
// 항목별 평점 수집
Recipe recipe1;
int rating;
string category[CATEGORY_SIZE] = { "난이도", "조리 시간", "맛", "가성비" };
cout << "--------------------------------" << endl;
cout << "평점을 입력해주세요" << endl;
for (string ctg : category) {
	cout << ctg << " : ";
	cin >> rating;
	recipe1.SetRating(ctg, rating);
}



// 포인트 적립 기능
user.PlusPoint(5);
*/