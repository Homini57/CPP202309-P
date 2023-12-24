#include "header.h"
#include "processing_text.h"
#include <fstream>
#include <sstream>
#include <string>
// 레시피 제목을 레시피 클래스로 반환
Recipe TitleToRecipe(string recipe_title);
// 재료들의 냉장고 재고 상태, 선호도 기준으로 상위 10개의 레시피 추천
vector <string> RecommendRecipe();
// 요리명, 재료명 기준으로 레시피 검색
vector <string> SearchRecipe(string search_text);
// 레시피의 제목 로드
vector <string> ReadRecipeTitleDate();
// 레시피의 필요한 재료들 로드
map <string, vector <string>> ReadRecipeIngredientsData();
// 레시피의 요리 과정 로드
map <string, vector <string>> ReadRecipeContentsData();
// 레시피의 평점 데이터 로드
map <string, vector<int>> ReeadRecipeRatingData();
// 입력한 제목의 레시피에 필요한 재료들 반환
vector <string> GetRecipeIngredients(string recipe_title);
// 입력한 제목의 레시피의 요리 과정 반환
vector <string> GetRecipeContents(string recipe_title);
// 입력한 제목의 레시피의 평점 반환
vector <int> GetRecipeRatings(string recipe_title);
// 레시피의 수정된 평점을 파일에 저장
void SaveRecipeRatingData(string recipe_title, vector<int> ratings);
