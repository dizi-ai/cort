#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>

#include "read_file.h"
#include "operations.h"

void do_operations(std::vector<Cont> cmds){
    std::stack<int> pr_stack;
    for (size_t i = 0;i<cmds.size();++i){
        if (cmds[i].op==Operations::OP_PUSH){
            pr_stack.push(cmds[i].arg);
            continue;
        }
        if (cmds[i].op==Operations::OP_DUMP){
            auto a = pr_stack.top();
            pr_stack.pop();
            std::cout<<a<<std::endl;
            continue;
        }
        if (cmds[i].op==Operations::OP_PLUS){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b+a);
            continue;
        }
        if (cmds[i].op==Operations::OP_MINUS){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b-a);
            continue;
        }
        std::cerr<<"OPERATION NOT IMPLEMENTED"<<std::endl;
    }


}

std::vector<Cont> hardcode_program(std::vector<std::string> program){
    assert(static_cast<int>(Operations::COUNT_OPS)==4);
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
    auto cmds = read_file("/tests/01-basic_ops.cort");
    auto h_program = hardcode_program(cmds);
    do_operations(h_program);

    return 0;
}
