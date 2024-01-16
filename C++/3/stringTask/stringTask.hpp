
#include <cstring>
#include <iostream>
#include <vector>

class string_1{
		private:
		std::vector<char> name;
		int len;
		static int noOfStrings;

		protected:
		std::vector<char>::iterator beg()
		{    
		    return name.begin(); 
		}	


		public:

		string_1();
		string_1(char* str);
		~string_1()=default;
		
		//Copy constructor
		string_1(const string_1&  other){
			this->name=other.name;
			this->len=other.len;
		}

		//String Capacity
		int length(void);
		bool empty(void);


		//Element Access

		// Get character
		char at(int index);

		// Get first char
		char front(void);

		// Get last char (usually null)
		char back(void);


		// String operations
		void append(char* str);								//append to the string
		bool compare(string_1& other);						//compare
        void concatenate(char *other);						//concatenate
		void erase(int start=0, int end=-1);				//erase using a start and an end index
		void erasen(int start, int numberOfElements);		//erase a certain number of chars
		int findChar(char* x, int direction=1);				//find first or last occurance of a character
		void replaceChar(char* old_char, char* new_char);	//replace a char with another
		
		//Printers
		void printString(bool newLine=false);
		void printTotalNoOfStrings(void);

		//External
		friend void copy(string_1& dest, string_1& src);
		friend void copyn(string_1& dest, string_1& src, int num);


		/////////////////////////////////////////////
		/////////////////////////////////////////////
		/////////////////////////////////////////////


		// + overloading
		string_1 operator+(string_1& temp){
				string_1 ret;
				// auto i = 0;
				for (auto i=0; this->name.at(i) != '\0'; i++) {
					ret.name.push_back(this->name.at(i));
				}
				ret.name.push_back(' ');

				for (auto i=0; temp.name.at(i) != '\0'; i++) {
					ret.name.push_back(temp.name.at(i));
				}
				ret.name.push_back('\0');
				ret.len=ret.name.size()-1;
				return ret;
		}

		// == overloading
		bool operator==(string_1& other){

			if(this->name == other.name){
				return true;
			}else {
				return false;
			}
		}

		//Copy assignment (= overloading)
		string_1& operator=(string_1& other){
			std::cout<<"Copy construc" <<std::endl;
			//self-assignment (a=a)
			if(this==&other){
				return *this;
			}

			this->name=other.name;
			this->len=other.len;      

			return *this;
		}
		
};

void copy(string_1& dest, string_1& src);
void copyn(string_1& dest, string_1& src, int num);




