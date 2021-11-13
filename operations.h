
enum Operations{
OP_PUSH,
OP_DUMP,
OP_PLUS,
OP_MINUS,
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
