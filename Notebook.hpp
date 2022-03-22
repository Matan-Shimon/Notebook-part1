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
		void write(unsigned int page, unsigned int row, unsigned int column, Direction direction, string to_write) {}
		string read(unsigned int page, unsigned int row, unsigned int column, Direction direction, unsigned int number_of_chars) {
			return "";
		}
		void erase(unsigned int page,unsigned int row,unsigned int column, Direction direction,unsigned int number_of_chars){}
		string show(unsigned int page) {
			return "";
		}
	};
}