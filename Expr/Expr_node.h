#pragma once
#ifndef EXPR_NODE_H
#define EXPR_NODE_H

#include <iostream>
#include <string>
#include <cmath>
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include "..\complex_num\complex_num.h"

double sgn(double _X,double _Y);

class Expr;
class Expr_node{
	friend std::ostream& operator<<(std::ostream&,const Expr_node&);
	friend std::ostream& operator<<(std::ostream&, const Expr&);
	friend class Expr;
	friend class Expr_node_ptr;
	friend class Double_node;
	friend class Binary_node;
	friend class Unary_node;
protected:
	
	virtual void print(std::ostream&) const = 0;
	virtual ~Expr_node(){}
	virtual double value(void) const = 0;
	virtual complex_num complex_value(void) const = 0;
};

class Expr_node_ptr{//handle class for Expr_node.
public:
	Expr_node_ptr(): _Pointer(0), _Size(new size_t(1)){}
	Expr_node_ptr(const Expr_node_ptr& p): _Pointer(p._Pointer),
	_Size(p._Size){ if(p._Pointer != 0) ++*_Size; }
	Expr_node_ptr(Expr_node* pt): _Pointer(pt), _Size(new size_t(1)){}
	
	Expr_node_ptr& operator=(const Expr_node_ptr& rhs){
		++*(rhs._Size);
		if(--*_Size == 0) delete _Pointer;
		_Pointer = rhs._Pointer;
		_Size = rhs._Size;
	}
	
	Expr_node& operator*(){
		return *_Pointer;
	}
	const Expr_node& operator*()const{ return *_Pointer;}
	Expr_node* operator->(){
		return _Pointer;
	}
	const Expr_node* operator->()const{ return _Pointer; } 
	
	~Expr_node_ptr(){
		if(--*_Size==0) delete _Pointer;
	}
private:
	Expr_node* _Pointer;
	size_t* _Size;
};

std::ostream& operator<<(std::ostream& os,const Expr_node& e);

class Double_node: public Expr_node{
	friend class Expr;
	Double_node(const std::string& s){
		if(s[0]=='P') this->_Value = acos(-1.0);
		if(s[0]=='e') this->_Value = exp(1.0);
	}
	Double_node(double d): _Value(d){}
	
	double _Value;
	void print(std::ostream& os)const{ os << _Value; }
	double value(void) const { return _Value; }
	complex_num complex_value(void) const{ return complex_num(_Value,0.0); }
};
class Complex_node: public Expr_node{
	friend class Expr;
	Complex_node(const complex_num &x): _Value(x){}
	complex_num _Value;
	void print(std::ostream& os)const{ os << _Value;}
	double value(void) const { return _Value.real(); }
	complex_num complex_value(void) const { return _Value; }
};

class Unary_node: public Expr_node{
	friend class Expr;
	std::string Operator;
	Expr_node_ptr Opnd;
	
	Unary_node(const std::string& s,Expr_node_ptr o): Operator(s), Opnd(o){}
	void print(std::ostream& os)const{
		os << "(" << Operator << *Opnd << ")";
	}
	double value(void)const;
	complex_num complex_value(void) const{
		if(Operator == "-" ) 
		return complex_num(0,0)-(Opnd->complex_value());
		if(Operator=="~")
		return ~(Opnd->complex_value());
		if(Operator == "exp"){
			return 
			complex_num(exp(Opnd->value()) *cos((Opnd->complex_value()).imagery()),
			exp(Opnd->value()) *sin(Opnd->complex_value().imagery()));
		}
		return this->value();
	}
};

class Binary_node: public Expr_node{
	friend class Expr;
	std::string Operator;
	Expr_node_ptr Left;
	Expr_node_ptr Right;
	
	Binary_node(const std::string& s,Expr_node_ptr l,Expr_node_ptr r): Operator(s),
	Left(l),Right(r){}
	void print(std::ostream& os)const{
		os << "(" << *Left << Operator <<
		*Right << ")" ; 
	}
	double value(void)const;
	complex_num complex_value(void) const{
		if(Operator == "+") return (Left->complex_value()) 
		+ (Right->complex_value());
		if(Operator == "-") return (Left->complex_value()) 
		- (Right->complex_value());
		if(Operator == "*") return (Left->complex_value()) 
		* (Right->complex_value());
		if(Operator == "/") return (Left->complex_value()) 
		/ (Right->complex_value());
		if(Operator == "^") return 
		sgn(Left->value(),Right->value())*pow(fabs(Left->value()),Right->value());
		throw std::domain_error("Undefined operator " + this->Operator);
	}
};

class Expr{
	friend std::ostream& operator<<(std::ostream&, const Expr&);
private:
	Expr_node_ptr _Node_ptr;
public:
	Expr(){}
	Expr(double d):_Node_ptr(new Double_node(d)){}
	Expr(complex_num x):_Node_ptr(new Complex_node(x)){}
	Expr(const std::string& s, Expr e):
	_Node_ptr(new Unary_node(s, e._Node_ptr)){}

	Expr(const std::string& s, Expr e1, Expr e2):
	_Node_ptr(new Binary_node(s,e1._Node_ptr, e2._Node_ptr)){}
	
	double eval(void)const{ return _Node_ptr->value(); }
	complex_num cval(void)const{ return _Node_ptr->complex_value();}
};

std::ostream& operator<<(std::ostream& os, const Expr& t);

#endif//EXPR_NODE_H
