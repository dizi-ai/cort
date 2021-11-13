#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

#include "read_file.h"
#include "operations.h"
#include "if_loops.h"



void do_operations(const std::vector<Cont>& cmds,std::stack<int>& pr_stack){
    for (size_t i = 0;i<cmds.size();++i){
        if (cmds[i].op==op_types::IFNLOOPS){
            size_t temp = find_cons_keywords(cmds.begin()+i,cmds.end());
            auto a = if_statement({cmds.begin()+i+1,cmds.begin()+i+temp},pr_stack);
            do_operations(a,pr_stack);
            i += temp;
        }
        else
            do_operation(cmds[i],pr_stack);
    }
}

std::vector<Cont> hardcode_program(std::vector<std::string> program){
    global_assert();
    std::vector<Cont> hp;
    for (size_t i = 0; i < program.size();++i){
        if (program[i]=="dump"){
            hp.push_back(dump());
            continue;
        }
        if (program[i]=="+"){
            hp.push_back(plus());
            continue;
        }
        if (program[i]=="-"){
            hp.push_back(minus());
            continue;
        }
        if (program[i]=="dup"){
            hp.push_back(dup());
            continue;
        }
        if (program[i]==">"){
            hp.push_back(greater());
            continue;
        }
        if (program[i]==">="){
            hp.push_back(greateq());
            continue;
        }
        if (program[i]=="<"){
            hp.push_back(less());
            continue;
        }
        if (program[i]=="<="){
            hp.push_back(lesseq());
            continue;
        }
        if (program[i]=="="){
            hp.push_back(eq());
            continue;
        }
        if (program[i]=="!="){
            hp.push_back(neq());
            continue;
        }
        if (program[i]=="if"){
            hp.push_back(if_());
            continue;
        }
        if (program[i]=="then"){
            hp.push_back(then());
            continue;
        }
        if (program[i]=="else"){
            hp.push_back(else_());
            continue;
        }
        if (program[i]=="endif"){
            hp.push_back(endif());
            continue;
        }
        //TODO: WHILE IMPLEMENT
        try {
            hp.push_back(push(std::stoi(program[i])));
        }
        catch(std::exception&){
            std::cerr<<"WRONG COMMAND"<<std::endl;
        }
    }
    return hp;

}

int main(){
    auto cmds = read_file("/home/dz/programming/cpp/cort/tests/03-if.cort");
    auto h_program = hardcode_program(cmds);
    std::stack<int> pr_stack;
    do_operations(h_program,pr_stack);
    return 0;
}
