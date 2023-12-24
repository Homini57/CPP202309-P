#include "recipe.h"

vector <string> RecommendRecipe() {
	vector <string> recipe_title_list = ReadRecipeTitleDate();
	map <string, vector<string>> recipe_ingredients_data = ReadRecipeIngredientsData();
	map <string, int> preference_rank;
	map <string, int> shortage_rank;
	// �� �����ǿ� ���Ͽ�
	for (string recipe_title : recipe_title_list) {
		preference_rank[recipe_title] = 0;
		shortage_rank[recipe_title] = 0;
		vector <string> recipe_ingredients = recipe_ingredients_data[recipe_title];
		// �����ǿ� �ʿ��� �� ���鿡 ���Ͽ�
		for (string recipe_ingredient : recipe_ingredients) {
			// is_in_fridge : �ش� ��ᰡ ����� ������ true, ������ false
			bool is_in_fridge = false;
			// �ش� ����� ��ȣ ���°� 1�̸� preference_rank 1 ���
			// �ش� ����� ��� ���°� 0�̶�� shortage_rank 1 ���
			for (Ingredient* ingredient : Ingredient::fridge) {
				if (recipe_ingredient == ingredient->GetName()) {
					is_in_fridge = true;
					preference_rank[recipe_title] += ingredient->GetPreference();
					if (ingredient->GetStockState() == 0) {
						shortage_rank[recipe_title] += 1;
					}
				}
				// �ش� ��ᰡ ����� ������ shortage_rank 1 ���
				if (is_in_fridge == false) {
					shortage_rank[recipe_title] += 1;
				}
			}
		}
	}
	// ��ȣ�� ������ ������ �̸� ����
	InsertionSort(recipe_title_list, preference_rank, true);
	// shortage_rank �������� ������ �̸� ����
	InsertionSort(recipe_title_list, shortage_rank, false);
	vector <string> Top10recipe_title_list;
	for (int i = 0; i < 10; i++) {
		Top10recipe_title_list.push_back(recipe_title_list[i]);
	}
	return Top10recipe_title_list;
}

vector <string> SearchRecipe(string search_text) {
	vector <string> search_list;
	vector <string> recipe_title_list = ReadRecipeTitleDate();
	map <string, vector<string>> recipe_ingredients_data = ReadRecipeIngredientsData();
	// �� �����ǿ� ���Ͽ� ������ ���� �˻� �ܾ �����ϸ� search_list�� �߰�
	for (string recipe_title : recipe_title_list) {
		if (CheckIncludeText(recipe_title, search_text)) {
			search_list.push_back(recipe_title);
		}
	}
	// �� �����ǿ� ���Ͽ�
	for (const auto& title_ingredients : recipe_ingredients_data) {
		string recipe_title = title_ingredients.first;
		vector <string> ingredients = title_ingredients.second;
		bool is_in_list = false;
		// �ش� �����ǰ� search_list�� �߰��Ǿ��ٸ� �ش� �����ǿ� ���� �˻� ����
		for (string searched_title : search_list) {
			if (recipe_title == searched_title) {
				is_in_list = true;
				break;
			}
		}
		// �ش� �������� ��� �߿� �˻� �ܾ �����ϴ� �����Ǹ� search_list�� �߰�
		if (is_in_list == false) {
			for (string ingredient : ingredients) {
				if (CheckIncludeText(ingredient, search_text)) {
					search_list.push_back(recipe_title);
				}
			}
		}
	}
	return search_list;
}

Recipe TitleToRecipe(string recipe_title) {
	vector <string> ingredients = GetRecipeIngredients(recipe_title);
	vector <string> contents = GetRecipeContents(recipe_title);
	vector <int> ratings = GetRecipeRatings(recipe_title);
	Recipe recipe(recipe_title, ingredients, contents, ratings);
	return recipe;
}
vector <string> GetRecipeIngredients(string recipe_title) {
	map <string, vector<string>> recipe_ingredients_data = ReadRecipeIngredientsData();
	vector <string> ingredients = recipe_ingredients_data[recipe_title];
	return ingredients;
}
vector <string> GetRecipeContents(string recipe_title) {
	map <string, vector<string>> recipe_contents_data = ReadRecipeContentsData();
	vector <string> contents = recipe_contents_data[recipe_title];
	return contents;
}
vector <int> GetRecipeRatings(string recipe_title) {
	map <string, vector<int>> recipe_rating_data = ReeadRecipeRatingData();
	vector <int> ratings = recipe_rating_data[recipe_title];
	return ratings;
}
vector <string> ReadRecipeTitleDate() {
	ifstream recipe_contents_data{ "recipe_contents_data.csv" };
	if (!recipe_contents_data.is_open()) {
		std::cerr << "Error" << std::endl;
	}
	vector <string> recipe_name_list;
	string line;
	while (getline(recipe_contents_data, line)) {
		istringstream iss{ line };
		string recipe_name;
		getline(iss, recipe_name, ',');
		recipe_name_list.push_back(recipe_name);
	}
	recipe_contents_data.close();
	return recipe_name_list;
}
map <string, vector <string>> ReadRecipeIngredientsData() {
	ifstream recipe_ingredients_data{ "recipe_ingredients_data.csv" };
	if (!recipe_ingredients_data.is_open()) {
		std::cerr << "Error" << std::endl;
	}
	map <string, vector <string>> ingredients_data;
	string line;
	while (getline(recipe_ingredients_data, line)) {
		istringstream iss{ line };
		string data;
		getline(iss, data, ',');
		string recipe_title = data;
		vector <string> ingredients;
		while (getline(iss, data, ',')) {
			if (data == "") break;
			ingredients.push_back(data);
		}
		ingredients_data[recipe_title] = ingredients;
	}
	recipe_ingredients_data.close();
	return ingredients_data;
}
map <string, vector <string>> ReadRecipeContentsData() {
	ifstream recipe_contents_data{ "recipe_contents_data.csv" };
	if (!recipe_contents_data.is_open()) {
		std::cerr << "Error" << std::endl;
	}
	map <string, vector <string>> contents_data;
	string line;
	while (getline(recipe_contents_data, line)) {
		istringstream iss{ line };
		string data;
		getline(iss, data, ',');
		string recipe_name = data;
		vector <string> contents;
		while (getline(iss, data, ',')) {
			if (data == "") break;
			contents.push_back(data);
		}
		contents_data[recipe_name] = contents;
	}
	recipe_contents_data.close();
	return contents_data;
}
map <string, vector<int>> ReeadRecipeRatingData() {
	ifstream recipe_rating_data{ "recipe_rating_data.csv" };
	if (!recipe_rating_data.is_open()) {
		std::cerr << "Error" << std::endl;
	}
	map <string, vector<int>> rating_data;
	string line;
	while (getline(recipe_rating_data, line)) {
		istringstream iss{ line };
		string recipe_name;
		getline(iss, recipe_name, ',');
		string rating;
		vector <int> rating_list;
		while (getline(iss, rating, ',')) {
			rating_list.push_back(stoi(rating));

		}
		rating_data[recipe_name] = rating_list;
	}
	recipe_rating_data.close();
	return rating_data;
}
void SaveRecipeRatingData(string recipe_title, vector<int> ratings) {
	map<string, vector<int>> recipe_rating_data = ReeadRecipeRatingData();
	recipe_rating_data[recipe_title] = ratings;
	ofstream ofs{ "recipe_rating_data.csv" };
	if (!ofs.is_open()) {
		std::cerr << "Error" << std::endl;
	}
	for (const auto& rating_pair : recipe_rating_data) {
		string title = rating_pair.first;
		vector <int> ratings = rating_pair.second;
		ofs << title << ",";
		for (int rating : ratings) {
			ofs << rating << ",";
		}
		ofs << endl;
	}
	ofs.close();
}
/*
map <string, int> ReadPreferenceData() {
	ifstream ingredient_data{ "ingredient_data.csv" };
	if (!ingredient_data.is_open()) {
		std::cerr << "Error" << std::endl;
		return;
	}
	map <string, int> preference_data;
	string line;
	while (getline(ingredient_data, line)) {
		string recipe_name;
		istringstream iss{ line };
		string data;
		int i = 0;
		while (getline(iss, data, ',')) {
			switch (i % 5) {
			case 0:
				recipe_name = data;
			case 5:
				preference_data[recipe_name] = stoi(data);
			}
			i++;
		}
	}
	ingredient_data.close();
	return preference_data;
}
*/





