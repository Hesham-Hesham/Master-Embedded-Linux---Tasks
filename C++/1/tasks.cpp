#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>
#include <string>
#include <bitset>


// Task : 1-Create a table for ASCII code

void ascii_table(void) {
    int c=0;
    char asc=0;
    
    std::cout<<"table for ASCII code:"<<std::endl;

    std::cout<<"    Char  |  ASCII  "<<std::endl;
    for (int i=0; i<129; i++) {
        
        std::cout<<"      "<<i<<"   |    "<<static_cast<char>(i)<<"  "<<std::endl;
    }
}


// Task : 2- maximum number between three values
int maxNum(int x,int y,int z){
    int a = std::max(x,y);
    return std::max(a,z);
}


// Task : 3-RIGHT angle triangle
int rightAngle(int leg_a,int leg_b,int hypo){
    if((leg_a*leg_a + leg_b*leg_b) == hypo*hypo){
        return 50;
    }else {
        return 20;
    }
}

// Task : 4-decide the letter is vowel or not
int vow1(std::string a){

    std::string vowels="aeouiAEOUI";
    if( (vowels.find(a)) != std::string::npos) {
        return 50;
    }
    else{
        return 20;
    }
}

// Task : 5-multiplication table
void multiplication_table(void){

    std::cout<<"Multiplication Table:"<<std::endl;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            std::cout<<i<<"x"<<j<<"="<<i*j<<std::endl;
        } 
    }
}

// Task: 6-summation the digits of integer entered by user
int sum_of_digits(std::string input){

    // Initialize the sum to 0
    int sum = 0;

    // Iterate through each character in the string
    for (char digit : input) {
        // Check if the character is a digit
        if (isdigit(digit)) {
            // Subtract '0' to convert the character to its integer equivalent
            //ascii of 0 is element 48 in the ascii table, so the decimal of '5' is '5'- 48 
            int num = digit - '0';  

            // Add the digit to the sum
            sum += num;
        }
    }

    return sum ;

}

// Task: 7-change from decimal to binary and vice versa
void dec_to_bin(void){

    std::string bin = std::bitset<4>(3).to_string(); //to binary
    std::cout<<bin<<"\n";

}

void bin_to_dec(void){

    std::bitset<4> bin{"0011"};

    std::cout<<"Binary: "<<bin.to_string()<<std::endl;
    std::cout<<"Decimal: "<<bin.to_ulong()<<std::endl;

    
}


int main(int argc, const char** argv) {

    // std::cout<<maxNum(10,2,3)<<std::endl;
    // std::cout<<rightAngle(33,4,5)<<std::endl;
    // std::cout<<vow1("k")<<std::endl;
    // multiplication_table();
    // bin_to_dec();
    dec_to_bin();

}
