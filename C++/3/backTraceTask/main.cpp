#include "backTrace.hpp"

#include <string>
#include <iostream>
#include <vector>

backTr::backTr(std::string name) {
  st = name;
  table.push_back(st);
  std::cout << "Enter to [" << st << "]" << std::endl;
}

void backTr::printBT(void) {
  int counter = 0;
  for (auto i : table) {

    std::cout << counter << "- " << i << std::endl;
    counter++;
  }
}

std::vector<std::string> backTr::table;


void func2() {
	enterFunc;

	printBackTrace;

}
void func1() {
	enterFunc;
	 func2();
}



int main() {
	
	enterFunc;
	func1();

	
	return 0;
}