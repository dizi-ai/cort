#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <fstream>

#include "read_file.h"



int main(){
    auto a = read_file("/tests/01-read.cort");
    for (auto i : a)
        std::cout<<i<<std::endl;
    return 0;
}
