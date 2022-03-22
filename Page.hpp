#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

namespace ariel {
	class Page {
	private:
		unordered_map<int, char[100]> rows;
	};
}