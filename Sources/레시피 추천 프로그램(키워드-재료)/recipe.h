#include "header.h"
#include "processing_text.h"
#include <fstream>
#include <sstream>
#include <string>
// ������ ������ ������ Ŭ������ ��ȯ
Recipe TitleToRecipe(string recipe_title);
// ������ ����� ��� ����, ��ȣ�� �������� ���� 10���� ������ ��õ
vector <string> RecommendRecipe();
// �丮��, ���� �������� ������ �˻�
vector <string> SearchRecipe(string search_text);
// �������� ���� �ε�
vector <string> ReadRecipeTitleDate();
// �������� �ʿ��� ���� �ε�
map <string, vector <string>> ReadRecipeIngredientsData();
// �������� �丮 ���� �ε�
map <string, vector <string>> ReadRecipeContentsData();
// �������� ���� ������ �ε�
map <string, vector<int>> ReeadRecipeRatingData();
// �Է��� ������ �����ǿ� �ʿ��� ���� ��ȯ
vector <string> GetRecipeIngredients(string recipe_title);
// �Է��� ������ �������� �丮 ���� ��ȯ
vector <string> GetRecipeContents(string recipe_title);
// �Է��� ������ �������� ���� ��ȯ
vector <int> GetRecipeRatings(string recipe_title);
// �������� ������ ������ ���Ͽ� ����
void SaveRecipeRatingData(string recipe_title, vector<int> ratings);
