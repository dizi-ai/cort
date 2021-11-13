
enum Operations{
OP_PUSH,
OP_DUMP,
OP_PLUS,
OP_MINUS,
OP_DUP,
//bool operations
OP_GREATER,
OP_GREATEQ,
OP_LESS,
OP_LESSEQ,
OP_EQ,
OP_NEQ,

COUNT_OPS
};

struct Cont{
    Cont(Operations o,int val){
        op=o;
        arg=val;
    }
    explicit Cont(Operations o){
        op=o;
    }
    Operations op;
    int arg;
};

Cont push(int val){
    return {OP_PUSH,val};
}
Cont dump(){
    return {OP_DUMP,0};
}
Cont plus(){
    return {OP_PLUS,0};
}
Cont minus(){
    return {OP_MINUS,0};
}
Cont dup(){
    return {OP_DUP,0};
}

Cont greater(){
    return {OP_GREATER,0};
}
Cont greateq(){
    return {OP_GREATEQ,0};
}
Cont less(){
    return {OP_LESS,0};
}
Cont lesseq(){
    return {OP_LESSEQ,0};
}
Cont eq(){
    return {OP_EQ,0};
}
Cont neq(){
    return {OP_NEQ,0};
}
