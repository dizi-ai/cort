#pragma once

#include <stack>
#include <vector>
#include <iostream>

#include "operations.h"

template <typename It>
size_t find_cons_keywords(const It& beg,const It& end){
    assert(static_cast<int>(ifnloops::COUNT_OPS3)==7);
    auto what = static_cast<ifnloops>(beg->enumber);
    int to_find=(beg->enumber==static_cast<int>(ifnloops::OP_IF)?static_cast<int>(ifnloops::OP_ENDIF):-7);
    int count_statement=0;
    for (auto i = beg ; i<end;++i){
        if ((i->op==op_types::IFNLOOPS)&&(static_cast<ifnloops>(i->enumber)==what))
            count_statement++;
        if ((i->op==op_types::IFNLOOPS)&&(i->enumber==to_find))
            count_statement--;
        if (count_statement==0)
            return std::distance(beg,i);
    }
    std::cerr<<"IF/WHILE WITHOUT END"<<std::endl;
    exit(1);
}

std::vector<Cont> find_in_if(const std::vector<Cont>& cmds,bool elseend){
    int if_closed=0;
    int i = 0;
    for (;(if_closed==0 && cmds[i].op==op_types::IFNLOOPS && (cmds[i].enumber==2 || cmds[i].enumber==3))==0;++i){
        if (cmds[i].op==op_types::IFNLOOPS && cmds[i].enumber==0)
            if_closed++;
        if (cmds[i].op==op_types::IFNLOOPS && cmds[i].enumber==3)
            if_closed--;
    }
    if (elseend)
        return {cmds.begin(),cmds.begin()+i};
    else
        return {cmds.begin()+i+1,cmds.end()};
}

std::vector<Cont> if_statement(const std::vector<Cont>& cmds,std::stack<int>& pr_stack){
    if (cmds.empty()) {
        std::cerr << "WRONG COMMAND" << std::endl;
        exit(1);
    }
    int i = 0;
    for (; static_cast<ifnloops>(cmds[i].enumber)!=ifnloops::OP_THEN || cmds[i].op!=op_types::IFNLOOPS;++i)
        do_operation(cmds[i],pr_stack);
    ++i;
    int then_end = i;
    int cond = pr_stack.top();
    pr_stack.pop();
    if (cond){
        return find_in_if({cmds.begin()+then_end,cmds.end()},true);
    }
    else{
        return find_in_if({cmds.begin()+then_end,cmds.end()}, false);
    }
}

size_t while_statement(const std::vector<Cont>& program_part){
    return program_part.size();
}
