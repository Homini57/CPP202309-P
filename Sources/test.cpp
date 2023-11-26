#include "header.h"
extern User user;

void TestInputRating(Recipe recipe) {
	recipe.InputRating();
	string category[CATEGORY_SIZE] = { "난이도", "조리 시간", "맛", "가성비" };
	for (string ctg : category) {
		cout << ctg << recipe.GetRating(ctg) << endl;
	}

	cout << user.GetPoint(user) << endl;
}
