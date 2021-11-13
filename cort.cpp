#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <cassert>

#include "read_file.h"
#include "operations.h"
#include "if_loops.h"

void do_operations(std::vector<Cont> cmds){
    std::stack<int> pr_stack;
    for (size_t i = 0;i<cmds.size();++i){
        if (cmds[i].op==Operations::OP_PUSH){
            pr_stack.push(cmds[i].arg);
            continue;
        }
        if (cmds[i].op==Operations::OP_DUMP){
            int a = pr_stack.top();
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
        if (cmds[i].op==Operations::OP_DUP){
            int a = pr_stack.top();
            pr_stack.push(a);
            continue;
        }
        if (cmds[i].op==Operations::OP_GREATER){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b>a);
            continue;
        }
        if (cmds[i].op==Operations::OP_GREATEQ){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b>=a);
            continue;
        }
        if (cmds[i].op==Operations::OP_LESS){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b<a);
            continue;
        }
        if (cmds[i].op==Operations::OP_LESSEQ){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b<=a);
            continue;
        }
        if (cmds[i].op==Operations::OP_EQ){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b==a);
            continue;
        }
        if (cmds[i].op==Operations::OP_NEQ){
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b!=a);
            continue;
        }

        std::cerr<<"OPERATION NOT IMPLEMENTED"<<std::endl;
    }


}

std::vector<Cont> hardcode_program(std::vector<std::string> program){
    assert(static_cast<int>(Operations::COUNT_OPS)==11);
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

        try {
            hp.push_back(push(std::stoi(program[i])));
            continue;
        }
        catch(std::exception&){
            std::cerr<<"WRONG COMMAND"<<std::endl;
        }
    }
    return hp;

}

int main(){
    auto cmds = read_file("/tests/02-bool_ops.cort");
    auto h_program = hardcode_program(cmds);
    do_operations(h_program);

    return 0;
}
