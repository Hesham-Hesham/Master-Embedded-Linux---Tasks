#include "stringTask.hpp"

#include <iostream>
#include <iterator>
#include <vector>
#include <stdexcept>



// Initializing a static member
int string_1::noOfStrings=0;

// Delegating the no-arg constructor to the one-arg constructor
string_1::string_1() : string_1("") {}

// One arg-constructor
string_1::string_1(char *str) {
  auto i = 0;
  for (; str[i] != '\0'; i++) {
    this->name.push_back(str[i]);
  }
  name.push_back('\0');
  this->len = name.size();
  noOfStrings++;
  std::cout << "String ";
  printString();
  std::cout << " created" << std::endl;
}


// Printers
void string_1::printString(bool newLine){
    // std::cout<<std::endl;
    for (size_t i = 0; this->name.at(i) !='\0' ; i++)
    {
      std::cout << this->name.at(i);
    }
    if (newLine==true)
    {
      std::cout << std::endl;
    }
}

void string_1::printTotalNoOfStrings(void) {
    std::cout<<"Number of strings created: "<<this->noOfStrings<<std::endl;
}



////////////////////////////////
////////////////////////////////


// Capacity:

int string_1::length(void) {
  // std::cout << "Length of string ";
  // printString();
  // std::cout << " is: " << this->len << std::endl;
  return this->len;
}

bool string_1::empty(void) {
  if (this->len==0)
  {
    return true;
  }else {
    return false;
  }
}


////////////////////////////////
////////////////////////////////


// Element Access

// Get character
char string_1::at(int index) {
  if (index > this->len) {
    throw std::runtime_error("error");
  } else {
    return this->name.at(index);
  }
}

// Get first char
char string_1::front(void) { return this->name.front(); }

// Get last char (null)
char string_1::back(void) { return this->name.back(); }



////////////////////////////////
////////////////////////////////



// String operations:

// Erase using a start and an end index
void string_1::erase(int start, int end){
	
	if(end==-1 && start==0){	//default start and end (clear the whole string)
		this->name.clear();
		
		// Add a null (empty string)
		this->name.push_back('\0');

		// Only one element (null)
		this->len=1;
		return;
	}

	if(end==-1){				//default end argument
		end=this->len;
	}

	// -Erase member in std::vector accepts iterators not ints, so we pass an iterator 
	//that points to the beginning and add the start or end to it
	this->name.erase(this->beg()+start,this->beg()+end+1);

}


// Erase a certain number of chars
void string_1::erasen(int start, int numberOfElements){
	// We can use the same erase member that we implemented
	this->erase(start,start+numberOfElements-1);
}


// Use the .concatinate
void string_1::append(char* str){
	this->concatenate(str);
}


// Concatinate
void string_1::concatenate(char* other){
  
  this->name.pop_back();
  for (size_t i = 0; other[i] != '\0'; i++)
  {
  this->name.push_back(other[i]);
  }
  name.push_back('\0');
}


// Compare
bool string_1::compare(string_1& other){
  if(this->name==other.name){
    return true;
  }else {
    return false;
  }
}

// Find first occurance of a character
int string_1::findChar(char *x, int direction) {
  int start = (direction == 1) ? 0 : this->len;
  int end = (direction == 1) ? this->len : 0;
  int step = (direction == 1) ? 1 : -1;

  for (auto i = start; i != end; i += step) {
    if (this->name.at(i) == x[0]) {
      return i;
    }
  }
  std::cout << "Couldn't find the char" << std::endl;
  return -1;
}

//replace a char with another
void string_1::replaceChar(char* old_char, char* new_char){
	if(*old_char==*new_char){
		return;
	}

	for (auto& i : this->name) {
		if(i==*old_char){
			i=*new_char;
		}
	}
}



////////////////////////////////
////////////////////////////////




//External:

// Copy a string to another using the copy constructor
void copy(string_1& dest, string_1& src){
  dest=src;
}

// Copy a certain number of elements from a string to another
void copyn(string_1& dest, string_1& src, int num){
  int i;
  for (i = 0; i < num; i++)
  {
    if(i>dest.len){
      dest.name.push_back(src.name.at(i));
    } else {
      dest.name.at(i) = src.name.at(i);
    }
  }
  if(src.len>dest.len){
    dest.name.push_back('\0');
    dest.len=num;
  }

}



int main() {
    
    // string_1 s1 {"abcde"};
	
	// s1.printString(true);
	// // s1.erase(3,3);
	// s1.erasen(1,1);
	// s1.printString(true);


	string_1 s2 {"aaabbaaa"};
	s2.printString(true);
	s2.replaceChar("b", "k");
	s2.printString(true);


    return 0;
}
