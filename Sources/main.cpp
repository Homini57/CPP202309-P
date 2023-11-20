#include "헤더.h"

#define CATEGORY_SIZE 4
void InReviewScore(int score, string category) {

}
int PointByReview(int a);
int main(void) {
	User my_user;
	// 항목별 평점 수집
	Recipe recipe1;
	int rating;
	string category[CATEGORY_SIZE] = { "난이도", "조리 시간", "맛", "가성비" };
	cout << "--------------------------------" << endl;
	cout << "평점을 입력해주세요" << endl;
	for (string ctg : category) {
		cout << ctg << " : ";
		cin >> rating;
		recipe1.Set_rating(ctg, rating);
	}

	

	// 포인트 적립 기능
	my_user.plus_point(5);

	
	// 재료 관리
	
	//재료 선호도 관리

	//재료 소진 관리

	//요리에 필요한 재료 구매

	return 0;
}


int PointByReview(int a){
	return 0;
}