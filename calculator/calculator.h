#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "translator.h"
#include "complex_num.h"
#include "Expr_node.h"
#include <fstream>

class calculator{
public:
    calculator(void):active(true){}
    void run(void);
private:
    bool active;    
};

#endif//CALCULATOR-H