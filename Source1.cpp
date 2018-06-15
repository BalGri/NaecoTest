#include <iostream>
#include <array>
#include <algorithm>

void get(const std::pair<int, int>& pair) {
	std::cout << pair.first << "," << pair.second << " ";
}

void filter(const std::array<std::pair<int, int>, 14>& pair_array, int pair_count, int rate) {
	int range_length = 0;
	for (int i = 0; i < pair_count; i++) {
		if (((i - 1 >= 0) && (pair_array[i].second == pair_array[i - 1].second))) {
			range_length++;
			if ((range_length % rate == 0) || !((i + 1 < pair_count) && (pair_array[i].second == pair_array[i + 1].second))) {
				get(pair_array[i]);
			}
		}
		else {
			range_length = 1;
			get(pair_array[i]);
		}
	}
	std::cout << "\n";
}

int main() {
	setlocale(LC_ALL, "RUS");
	auto p1 = std::make_pair(1, 10); auto p8 = std::make_pair(8, 11);
	auto p2 = std::make_pair(2, 11); auto p9 = std::make_pair(9, 11);
	auto p3 = std::make_pair(3, 11); auto p10 = std::make_pair(10, 11);
	auto p4 = std::make_pair(4, 11); auto p11 = std::make_pair(11, 11);
	auto p5 = std::make_pair(5, 11); auto p12 = std::make_pair(12, 11);
	auto p6 = std::make_pair(6, 10); auto p13 = std::make_pair(13, 11);
	auto p7 = std::make_pair(7, 11); auto p14 = std::make_pair(14, 10);
	
	std::cout << "Исходная последовательность: \n";
	const std::array<std::pair<int, int>, 14> pair_array = { p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14 };
	std::for_each(pair_array.begin(), pair_array.end(), get);
	std::cout << "\n";

	std::cout << "\nРезультат при n = 3: \n";
	filter(pair_array, 14, 3);
	std::cout << "\nРезультат при n = 4: \n";
	filter(pair_array, 14, 4);
	std::cout << "\n";

	system("pause");
	return 0;
}