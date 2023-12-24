#include "processing_text.h"

void InsertionSort(vector <string>& str_list, map<string, int> str_value, bool reverse = false) {
	if (reverse == false) {
		for (int i = 0; i < str_list.size(); i++) {
			for (int j = i; j >= 1; j--) {
				if (str_value[str_list[j - 1]] > str_value[str_list[j]]) {
					swapString(str_list[j - 1], str_list[j]);
				}
				else break;
			}
		}
	}
	else {
		for (int i = 0; i < str_list.size(); i++) {
			for (int j = i; j >= 1; j--) {
				if (str_value[str_list[j - 1]] < str_value[str_list[j]]) {
					swapString(str_list[j - 1], str_list[j]);
				}
				else break;
			}
		}
	}
}
void swapString(string& str1, string& str2) {
	string temp;
	temp = str1;
	str1 = str2;
	str2 = temp;
}
bool CheckIncludeText(string text, string check_text) {
	for (int i = 0; i <= (int) text.size() - (int) check_text.size(); i++) {
		size_t start_index = i;
		size_t len_text = check_text.size();
		string sub_text = text.substr(start_index, len_text);
		if (sub_text == check_text) return true;
	}
	return false;
}