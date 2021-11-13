#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unistd.h>



std::string get_path(){
    char tmp[256];
    getcwd(tmp,256);
    return {tmp};
}

std::vector<std::string> line_to_cmd(const std::string& line){
    std::istringstream input(line);
    std::vector<std::string> commands;
    for (std::string com;input>>com;)
        commands.push_back(com);
    return commands;
}

std::vector<std::string> lbl(const std::string& full_path){
    std::vector<std::string> commands;
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

//TODO: add if/else/endif validators
std::vector<std::string> check_syntax(std::vector<std::string>& cl){
    return cl;
}

std::vector<std::string> read_file (const std::string& file_path){
    std::vector<std::string> commands;
    std::string full_path = get_path()+file_path;
    //std::cout<<full_path<<std::endl;
    return lbl(file_path);
}