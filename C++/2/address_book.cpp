
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


class address_book{

private:
//   Vectors
  static std::vector<std::string> names;
  static std::vector<std::string> numbers;
  bool delByNum=true;


	
    template <typename T>
    void deleteElement(const std::string& element, T& container) {
		if(container.size()==0){
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Phonebook is empty"<<std::endl<<std::endl;
			return;
		}
        auto it = std::find(container.begin(), container.end(), element);
        if (it != container.end()) {
            auto index = std::distance(container.begin(), it);
            auto it2 = std::next((delByNum ? names : numbers).begin(), index);
            container.erase(it);
            (delByNum ? names : numbers).erase(it2);
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Contact Deleted"<<std::endl<<std::endl;
        } else {
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Contact not found"<<std::endl<<std::endl;
        }
    }



	template<typename T>
	void searchElement(const std::string& element, T temp_vec){
		if(temp_vec.size()==0){
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Phonebook is empty"<<std::endl<<std::endl;
			return;
		}
		bool found = false;
		for (auto i=0 ; i< temp_vec.size();i++) {
			if(temp_vec[i].find(element) != temp_vec[i].npos){
				std::cout<<std::endl<<"Name: " <<names.at(i);
				std::cout<<"	Number: " <<numbers.at(i)<<std::endl;
				found = true;
			}
		
		}

		if (found == false) {
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Contact not found"<<std::endl<<std::endl;

		}
	}


public:

	void add(std::string name, std::string number){
		names.push_back(name);
		numbers.push_back(number);
	}

	void list(void){
		if(names.size()==0){
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Phonebook is empty"<<std::endl<<std::endl;
			return;
		}
		for (size_t i = 0; i < names.size(); i++)
		{
			std::cout<<std::endl<<"Name: " <<names.at(i);
			std::cout<<"	| Number: " <<numbers.at(i)<<std::endl<<std::endl;
		}
	}

    void deleteByNum(std::string number) {
        delByNum = true;
        deleteElement(number, numbers);
    }

    void deleteByName(std::string name) {
        delByNum = false;
        deleteElement(name, names);
    }

	void deleteAll(void){
		if(names.size()==0){
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Phonebook is empty"<<std::endl<<std::endl;
			return;
		}else{
			numbers.clear();
			names.clear();
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Deleted all contacts"<<std::endl<<std::endl;
		}
	}

	void searchByName(std::string name){
        searchElement(name,names);
	}
	void searchByNum(std::string number){
        searchElement(number,numbers);
	}


};

std::vector<std::string> address_book::names;
std::vector<std::string> address_book::numbers;

int main() {
	std::string choice = "";
	std::string number = "";
	std::string name = "";
	address_book book;

        do {
          std::cout << std::left<< std::setw(20) << "| List" 
                    << "| Lists all users" << std::endl;
          std::cout << std::left<< std::setw(20) << "| Add" 
                    << "| Adds a user" << std::endl;
          std::cout << std::left<< std::setw(20) << "| Delete" 
                    << "| Deletes a user" << std::endl;
          std::cout << std::left<< std::setw(20) << "| Delete all" 
                    << "| Deletes all users" << std::endl;
          std::cout << std::left<< std::setw(20) << "| Search" 
                    << "| Searches for a user" << std::endl;
          std::cout << std::left<< std::setw(20) << "| Close" 
                    << "| Closes the address book" << std::endl;

          std::cin >> choice;

          if (choice == "List" || choice == "list") {
            book.list();
          } else if (choice == "Add" || choice == "add") {
            std::cout << "Name: ";
            std::cin >> name;
            std::cout << std::endl << "Number: ";
            std::cin >> number;
            book.add(name, number);
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Contact added"<<std::endl<<std::endl;
          } else if (choice == "Delete" || choice == "delete") {
            std::cout << "Delete by name or number? " << std::endl;
            std::cin >> choice;
            if (choice == "name" || choice == "Name") {
              std::cout << "Name: ";
              std::cin >> name;
              book.deleteByName(name);
            } else if (choice == "number" || choice == "Number") {
              std::cout << std::endl << "Number: ";
              std::cin >> number;
              book.deleteByNum(number);
            }else{
			  std::cout<<std::endl<<std::setw(30)<<std::internal<<"Enter a valid choice"<<std::endl<<std::endl;
			}
			
          } else if (choice == "Delete all" || choice == "delete all") {

			book.deleteAll();
          } else if (choice == "Search" || choice == "search") {
			std::cout << "Search by name or number? " << std::endl;
            std::cin >> choice;
            if (choice == "name" || choice == "Name") {
              std::cout << "Enter the full name or a part of it: ";
              std::cin >> name;
              book.searchByName(name);
            } else if (choice == "number" || choice == "Number") {
              std::cout << std::endl << "Enter the full number or a part of it: ";
              std::cin >> number;
              book.searchByNum(number);
            }
          }else {
			std::cout<<std::endl<<std::setw(30)<<std::internal<<"Enter a valid choice"<<std::endl<<std::endl;
		  }

        } while (choice != "Close" && choice != "close");
		std::cout<<std::endl<<std::setw(30)<<std::internal<<"Bye Bye <3"<<std::endl<<std::endl;

    

	
	return 0;
}
