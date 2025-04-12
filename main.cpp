#include <iostream>
#include "TableTestKit.h"
#include "ScanTable.h"
#include <random> // c++11
#include <algorithm> // c++11

std::string generateRandomString(size_t length) {
	const std::string CHARACTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> distribution(0, CHARACTERS.size() - 1);

	std::string random_string;

	for (size_t i = 0; i < length; ++i) {
		random_string += CHARACTERS[distribution(generator)];
	}

	return random_string;
}

int main(){
	std::vector<std::string> keys;
	for (int i = 0; i < 100; i++) {
		keys.push_back(generateRandomString(8));
	}
	std::cout << "hello\n";
	ScanTable scanTable(100);
	TableTestKit test(scanTable);
	std::cout << "print 1\n";
	test.ShowTable();
	std::cout << "print 2\n";
	test.GenBenchmarkTab(keys);
	std::cout << "print 3\n";
	test.ShowTable();
}