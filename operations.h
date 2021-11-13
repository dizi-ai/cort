#pragma once

#include <stack>
#include <cassert>
#include <iostream>

#include "operations_imp.h"

void basic_ops(int en,int arg, std::stack<int>& pr_stack){
    assert(static_cast<int>(BasicOps::COUNT_OPS1)==5);
    switch (static_cast<BasicOps>(en)){
        case BasicOps::OP_PUSH:{
            pr_stack.push(arg);
            break;
        }
        case BasicOps::OP_DUMP:{
            int a = pr_stack.top();
            pr_stack.pop();
            std::cout<<a<<std::endl;
            break;
        }
        case BasicOps::OP_PLUS: {
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b+a);
            break;
        }
        case BasicOps::OP_MINUS: {
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b-a);
            break;
        }

        case BasicOps::OP_DUP: {
            int a = pr_stack.top();
            pr_stack.push(a);
            break;
        }

        default : std::cerr<<"NOT IMPLEMENTED"<<std::endl;
    }
}

void boolean_ops(int en, std::stack<int>& pr_stack){
    assert(static_cast<int>(BooleanOps::COUNT_OPS2)==6);
    switch (static_cast<BooleanOps>(en)){
        case BooleanOps::OP_GREATER:{
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b>a);
            break;
        }
        case BooleanOps::OP_GREATEQ:{
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b>=a);
            break;
        }
        case BooleanOps::OP_LESS:{
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b<a);
            break;
        }
        case BooleanOps::OP_LESSEQ:{
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b<=a);
            break;
        }
        case BooleanOps::OP_EQ:{
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b==a);
            break;
        }
        case BooleanOps::OP_NEQ:{
            int a = pr_stack.top();
            pr_stack.pop();
            int b = pr_stack.top();
            pr_stack.pop();
            pr_stack.push(b!=a);
            break;
        }
        default : std::cerr<<"NOT IMPLEMENTED"<<std::endl;
    }
}

void keyword_ops(int c, std::stack<int> pr_stack){
    assert(static_cast<int>(ifnloops::COUNT_OPS3)==4);
}

void global_assert(){
    assert(static_cast<int>(BasicOps::COUNT_OPS1)==5);
    assert(static_cast<int>(BooleanOps::COUNT_OPS2)==6);
    assert(static_cast<int>(ifnloops::COUNT_OPS3)==7);
}

void do_operation(const Cont& c, std::stack<int>& pr_stack){
    switch (c.op) {
        case op_types::BASIC_OPS: basic_ops(c.enumber,c.arg,pr_stack); break;
        case op_types::BOOLEAN_OPS: boolean_ops(c.enumber,pr_stack); break;
        default: std::cerr<<"NOT IMPLEMENTED"<<std::endl;
    }
}
