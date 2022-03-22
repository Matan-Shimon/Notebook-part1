#include <iostream>
#include <string>
#include "Page.hpp"
#include "Direction.hpp"
#include <unordered_map>

using namespace std;
using namespace ariel;

namespace ariel {
	class Notebook {
	private:
		unordered_map<int, Page> pages;
	public:
		void write(int page, int row, int column, Direction direction, string to_write) {}
		string read(int page, int row, int column, Direction direction, int number_of_chars) {
			return "";
		}
		void erase(int page, int row, int column, Direction direction, int number_of_chars){}
		string show(int page) {
			return "";
		}
	};
}