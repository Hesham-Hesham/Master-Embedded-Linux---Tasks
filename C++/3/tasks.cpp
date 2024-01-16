#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>



// Task: -check if the character is digit ?
bool dig(char inp){
    return isdigit(inp);
}


// Task: -check if all the array is even ?
void allEven(void) {
  int arr[] = {2, 4, 6, 12, 14};
  int len = sizeof(arr) / sizeof(arr[0]);

  // summation of even numbers is even
  int res = std::accumulate(std::begin(arr), std::end(arr), 0);
  if (res % 2 == 0) {
    std::cout << "all elements are even" << std::endl;
  } else {
    std::cout << "NOT all elements are even" << std::endl;
  }
}

// Task: -check if any the array is even ?
void anyEven(void){
	// int arr[] = { 1, 3,5,11};
	int arr[] = { 1, 3,5,11,2};
	int len = sizeof(arr) / sizeof(arr[0]);
    
    //any_of returns true if any of the elements returns true in the lambda expression
	bool res=std::any_of(std::begin(arr),std::end(arr),
    [](int i)-> bool{
        if(i%2==0){
            return true;
        }else {
            return false;
        }
    } 
    );

    std::cout<<"atleast one element is even: "<<res<<std::endl;
}


// Task: 5- calculate accumulate of array
int accumArray(void){

	int arr[] = { 1, 2,1};
	int len = sizeof(arr) / sizeof(arr[0]);

    return std::accumulate(std::begin(arr),std::end(arr),0);

}


// Task: 3- fill array from 10 to 10000 sequentially without for loop
void fillArr(void){
    int arr[9991]={0};

    std::generate(std::begin(arr),std::end(arr),
    [](){
        static int i=9;
        return ++i;}
        );
    
    for (auto i : arr) {
        std::cout<<" "<<i;
    }
}


int main() {
    
    // std::cout<<dig('5')<<std::endl;
    // std::cout<<dig('a')<<std::endl;
    
    // allEven();
    // anyEven();

    // std::cout<<"accumilation="<<accumArray()<<std::endl;

    // fillArr();
    
    return 0;
}
