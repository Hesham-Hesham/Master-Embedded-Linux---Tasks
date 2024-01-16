#ifndef BACKTRACE_HPP
#define BACKTRACE_HPP


#include <string>
#include <iostream>
#include <vector>


#define enterFunc		backTr a(__func__)
#define printBackTrace	a.printBT()


class backTr{

std::string st;
static std::vector<std::string> table;

public:

	backTr(std::string name);


	void printBT(void);


	~backTr(){
		std::cout<<"Exit from [" <<st<<"]"<<std::endl;
	}

};



#endif


