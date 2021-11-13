#pragma once

enum class BasicOps{
    OP_PUSH,
    OP_DUMP,
    OP_PLUS,
    OP_MINUS,
    OP_DUP,

    COUNT_OPS1//5
};

enum class BooleanOps{
    OP_GREATER,
    OP_GREATEQ,
    OP_LESS,
    OP_LESSEQ,
    OP_EQ,
    OP_NEQ,

    COUNT_OPS2//6

};

enum class ifnloops{
    OP_IF,
    OP_THEN,
    OP_ELSE,
    OP_ENDIF,
    OP_WHILE,
    OP_DO,
    OP_ENDWHILE,

    COUNT_OPS3//4
};
enum class op_types{
    BASIC_OPS,
    BOOLEAN_OPS,
    IFNLOOPS
};


struct Cont{
    Cont(op_types o,int en,int val){
        op = o;
        enumber = en;
        arg = val;
    }
    Cont(op_types o,int en){
        op = o;
        enumber = en;
    }
    op_types op;
    int enumber;
    int arg;
};

Cont push(int val){
    return {op_types::BASIC_OPS,0,val};
}
Cont dump(){
    return {op_types::BASIC_OPS,1};
}
Cont plus(){
    return {op_types::BASIC_OPS,2};
}
Cont minus(){
    return {op_types::BASIC_OPS,3};
}
Cont dup(){
    return {op_types::BASIC_OPS,4};
}

Cont greater(){
    return {op_types::BOOLEAN_OPS,0};
}
Cont greateq(){
    return {op_types::BOOLEAN_OPS,1};
}
Cont less(){
    return {op_types::BOOLEAN_OPS,2};
}
Cont lesseq(){
    return {op_types::BOOLEAN_OPS,3};
}
Cont eq(){
    return {op_types::BOOLEAN_OPS,4};
}
Cont neq(){
    return {op_types::BOOLEAN_OPS,5};
}

Cont if_(){
    return {op_types::IFNLOOPS,0};
}
Cont then(){
    return {op_types::IFNLOOPS,1};
}
Cont else_(){
    return {op_types::IFNLOOPS,2};
}
Cont endif(){
    return {op_types::IFNLOOPS,3};
}