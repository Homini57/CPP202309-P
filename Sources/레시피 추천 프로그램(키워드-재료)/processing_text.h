#include "header.h"
// str_list�� str_value �������� �������� (default : reverse = ��������, stability = o)
void InsertionSort(vector <string>& str_list, map<string, int> str_value, bool reverse); // reverse�� ����Ʈ���� �Լ� ����ο��� �ϸ� error �߻�?
// str1�� str2�� ��ȯ
void swapString(string& str1, string& str2);
// text�� check_text�� �����ϴ��� Ȯ��
bool CheckIncludeText(string text, string check_text);