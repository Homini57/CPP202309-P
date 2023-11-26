#include "header.h"
extern User user;

void TestInputRating(Recipe recipe) {
	recipe.InputRating();
	string category[CATEGORY_SIZE] = { "���̵�", "���� �ð�", "��", "������" };
	for (string ctg : category) {
		cout << ctg << recipe.GetRating(ctg) << endl;
	}

	cout << user.GetPoint(user) << endl;
}
