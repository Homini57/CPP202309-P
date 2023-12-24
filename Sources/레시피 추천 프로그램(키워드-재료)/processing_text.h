#include "header.h"
// str_list를 str_value 기준으로 삽입정렬 (default : reverse = 오름차순, stability = o)
void InsertionSort(vector <string>& str_list, map<string, int> str_value, bool reverse); // reverse의 디폴트값을 함수 선언부에서 하면 error 발생?
// str1과 str2를 전환
void swapString(string& str1, string& str2);
// text가 check_text를 포함하는지 확인
bool CheckIncludeText(string text, string check_text);