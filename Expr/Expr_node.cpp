#include "include\Expr_node.h"

double sgn(double _X,double _Y){
	if(_Y>0.0) return 1.0;
	if(_X > 0.0) return 1.0;
	if(_X < 0.0) return -1.0;
	return 0.0;
}

std::ostream& operator<<(std::ostream& os,const Expr_node& e){
	e.print(os); return os;
}

double Unary_node::value(void) const{
	if(Operator == "-" || Operator == "~") 
	return -(Opnd->value());
	if(Operator == "ln") return log(Opnd->value());
	if(Operator == "sin") return sin(Opnd->value());
	if(Operator == "cos") return cos(Opnd->value()); 
	if(Operator == "tan") return tan(Opnd->value()); 
	if(Operator == "arcsin") return asin(Opnd->value()); 
	if(Operator == "arccos") return acos(Opnd->value()); 
	if(Operator == "arctan") return atan(Opnd->value()); 
	if(Operator == "exp") return exp(Opnd->value()); 
	throw std::domain_error("Undefined operator " + this->Operator);
}

double Binary_node::value(void)const{
	if(Operator == "+") return (Left->value()) + (Right->value());
	if(Operator == "-") return (Left->value()) - (Right->value());
	if(Operator == "*") return (Left->value()) * (Right->value());
	if(Operator == "/") return (Left->value()) / (Right->value());
	if(Operator == "^") return sgn(Left->value(),Right->value())*pow(fabs(Left->value()),Right->value());
	throw std::domain_error("Undefined operator " + Operator);
}

std::ostream& operator<<(std::ostream& os, const Expr& t){
	t._Node_ptr->print(os);
	return os;
}