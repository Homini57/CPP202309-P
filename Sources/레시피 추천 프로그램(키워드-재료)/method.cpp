#include "page.h"
#include "recipe.h"
extern User user;
//User Class Method
User::User() {
	this->ReadUserPoint();
}

void User::PlusPoint(int point) { this->point += point; }
int User::GetPoint() { return point; }
void User::SetPoint(int point) {this->point = point;}
void User::ReadUserPoint() {
	int point;
	ifstream user_point{ "user_point.txt" };
	if (!user_point.is_open()) {
		std::cerr << "Error" << std::endl;
	}
	user_point >> point;
	this->SetPoint(point);
}
void User::SavevUserPoint() {
	ofstream ofs{ "user_point.txt" };
	if (!ofs.is_open()) {
		std::cerr << "Error" << std::endl;
	}
	ofs << this->GetPoint();
}

vector <Ingredient*> Ingredient::fridge;
//Ingredient Class Method
Ingredient::Ingredient(string name) {
	this->name = name;
	in_basket = false;
	purchased = false;
	preference = false;
	stock_state = 2;

}
string Ingredient::GetName() { return name; }
void Ingredient::SetName(string name) { this->name = name; }
bool Ingredient::GetPreference() { return preference; }
void Ingredient::SetPreference(bool preference) { this->preference = preference; }
int Ingredient::GetStockState() { return stock_state; }
void Ingredient::SetStockState(int stock_state) { this->stock_state = stock_state; }

bool Ingredient::GetInBasket() { return in_basket; }
void Ingredient::SetInBasket(bool in_basket) { this->in_basket = in_basket; }
bool Ingredient::GetPurchased() { return purchased; }
void Ingredient::SetPurchased(bool purchased) { this->purchased = purchased; }
Ingredient* NameToIngredient(string name) {
	for (Ingredient* ingredient: Ingredient::fridge) {
		if (ingredient->GetName() == name) {
			return ingredient;
		}
	}
	Ingredient* none_ingredient = new Ingredient(name);
	none_ingredient->SetStockState(0);
	return none_ingredient;
}
void Ingredient::InFridge(int type) {
	// is_in_fridge : ����� ��ᰡ ������ true, ������ false
	bool is_in_fridge = false;
	for (Ingredient* ingredient : Ingredient::fridge) {
		if (name == ingredient->GetName()) {
			is_in_fridge = true;
		}
	}
	// ��ᰡ ����� ���ٸ� type�� ���� ��� ���� ���� �� ����� �߰�
	if (is_in_fridge == false) {
		this->SetStockState(type);
		Ingredient::fridge.push_back(this);
	}
}
//Recipe Class Method
Recipe::Recipe(string title, vector <string> ingredient_list, vector <string> process_list, vector <int> rating) {
	vector <string> item_list{ "��", "������", "�����ð�", "���̵�" };
	this->title = title;
	this->ingredient_list = ingredient_list;
	this->process_list = process_list;
	for (int i = 0; i < item_list.size();i++ ) {
		this->rating[item_list[i]] = rating[i];
	}
}
string Recipe::GetTitle() { return title; }
int Recipe::GetRating(string item) { return rating[item]; }
void Recipe::SetItem(string item) { rating[item] = 0; }
void Recipe::SetRating(string item, int rating) { this->rating[item] = rating; }
vector <string> Recipe::GetIngredients() { return ingredient_list; }
void Recipe::SetIngredient(string ingredient) { ingredient_list.push_back(ingredient); }
vector <string> Recipe::GetProcessList() { return process_list; }
map<string, int> Recipe::GetRatings() { return rating; }
void Recipe::InputRating() {
	int rating;
	vector <int> ratings;
	string category[CATEGORY_SIZE] = { "��", "������", "�����ð�", "���̵�" };
	cout << "--------------------------------" << endl;
	cout << "������ �Է����ּ���(1 ~ 5)" << endl;
	for (string ctg : category) {
		cout << ctg << " : ";
		cin >> rating;
		// �Է� ������ ��� ��� �׸���� ��� ������ 0���� ����
		if (rating < 1 || 5 < rating) {
			cout << "�Է� ������ ������ϴ�." << endl;
			for (string ctg : category) {
				SetRating(ctg, 0);
			}
			break;
		}
		ratings.push_back(rating);
		SetRating(ctg, rating);
	}
	// ������ ��� �Է��ϸ� ���� ����Ʈ 5�� ����
	if (GetRating(category[0]) != 0) {
		user.PlusPoint(5);
		user.SavevUserPoint();
	}
	SaveRecipeRatingData(title, ratings);
}