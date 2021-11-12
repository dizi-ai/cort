#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unistd.h>



std::string get_path(){
    char tmp[256];
    getcwd(tmp,256);
    return std::string(tmp);
}

std::vector<std::string> line_to_cmd(std::string line){
    std::istringstream input(line);
    std::vector<std::string> commands;
    for (std::string com;input>>com;)
        commands.push_back(com);
    return commands;
}


std::vector<std::string> read_file (std::string file_path){
    std::vector<std::string> commands;
    std::string full_path = get_path()+file_path;
    std::fstream file(full_path);
    if (file.is_open()){
        for( std::string line; std::getline( file, line); ){
            auto temp = line_to_cmd(line);
            commands.insert(commands.end(),temp.begin(), temp.end());
        }
    }
    else{
        std::cerr<<"No such file"<<std::endl;
    }
    return commands;
}
