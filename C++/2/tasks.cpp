
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>


// Task: 1- create a function to ﬁnd the maximum number of array
void arrMax(void){
    int arr[]={1,2,3,20};
    int size=sizeof(arr)/sizeof(arr[0]);

    int* ptr=std::max_element(arr,arr+size);
    std::cout<<"Max is:"<<*ptr<<std::endl;
}

// Task: 2- create a function to search to the number in the array which number is taken from user
void numInArr(int target){

    int arr[]={1,2,3,6,15,4,0,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int *result=nullptr;
    // int start=0;
    // int end=0;
    // int midPoint=size/2;

    // //starting point is 0, mid point is midPoint, and ending point is size
    
    // //Sort the array before checking
    // std::sort(arr,arr+size);


    // if(arr[midPoint]>target){   //element is in the first half
    //   start = 0;
    //   end = midPoint;

    // } else { // element is in the second half
    //     start=midPoint;
    //     end = size;
    // }
    // for (size_t i = start; i < end; i++) {
    //   if (arr[i] == target) {
    //     //Return the index containing the target
    //     std::cout<<"Element "<<target<<" was found"<<std::endl;
    //     result=1;
    //     break;
    //   }
    // }

    // //Target wasn't found
    // if(result==0){
    //   std::cout << "Element " << target << " was NOT found" << std::endl;
    // }


    result=std::find(arr,arr+size,target);

    if(result == (&arr[size]) && arr[size]!=target){
        //Target wasn't found
        std::cout << "Element " << target << " was NOT found" << std::endl;
    }else
    {    
        //Return the index containing the target
        std::cout<<"Element "<<target<<" was found at index: "<<result-arr<<std::endl;
    }
}

// Task: 3- delete number in array
void removeNumber(int target){
    int arr[]={1,2,3,6,15,4,0,9};
    int size=sizeof(arr)/sizeof(arr[0]);

    std::cout<<"old array is:";
    for (auto i : arr) {
        std::cout<<" "<<std::setw(4)<<i;
    }
    auto end = std::remove(std::begin(arr), std::end(arr), target);
    std::cout<<std::endl<<"removed number: "<<target<<std::endl;
    std::cout<<"new array is: ";
    for (int i = 0; i <size-1; i++) {
      std::cout << " " << std::setw(4) << arr[i];
    }
    std::cout<<std::endl;
}


// Task: 4- merge two arrays together
void mergeTwoArrays(void){
    int arr1[]={1,2,3};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={6,15,4,0,9};
    int size2=sizeof(arr2)/sizeof(arr2[0]);

    int newSize=size1+size2;
    int arr3[newSize];
    
    auto t = std::merge(arr1,arr1+size1,arr2,arr2+size2,arr3);
    std::cout<<"merged array is:";
    for (auto i : arr3) {
        std::cout<<" "<<std::setw(4)<<i;
    }
}


// Task: 5-ﬁnd the even and odd numbers in the array



// Task: Simple Lambda: Write a lambda function to calculate the square of a given number.
auto sqr=[](int num)->int{
    return num*num;
};

// Task: Sort with Lambda: Use lambda functions to sort an array of integers in ascending and descending order.
auto arrSort=[](int arr[], int size, int order)->void{

    if(order==1){   //ascending
        std::sort(arr,arr+size);
    }else {
        std::sort(arr, arr + size,
         [](int a, int b) {
        return a > b;  // This comparison sorts in descending order
    });
    }
    
    for (int i = 0; i <size; i++) {
      std::cout << " " << std::setw(4) << arr[i];
    }
    std::cout<<std::endl;
};



int main() {

    // arrMax();    
    // numInArr(1000);
    
    // numInArr(9);
    // numInArr(155);

    // removeNumber(2);

    // mergeTwoArrays();

    int arr[] = {5, 1, 4, 2, 3};
    int size1 = sizeof(arr) / sizeof(arr[0]);
    arrSort(arr,size1,1);
    arrSort(arr,size1,0);

    return 0;
}
