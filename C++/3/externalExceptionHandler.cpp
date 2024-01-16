
#include <iostream>
#include <numeric>
#include <string>
#include <csignal>

// Task: 1-handle interrupt signal like (ctrl+c)

void CB(int x){
    static int y=0;
    y++;
    std::cout<<"here "<<x<<" for "<<y<<" times"<<std::endl;
}


int main() {
    
    // signal(SIGINT, CB);
    signal(SIGINT, CB);

    while(1);
    
    return 0;
}
