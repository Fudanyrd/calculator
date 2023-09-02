#include "include\translator.h"

using std::string;		using std::vector;
using std::find_if; 	using std::find;

//group 1: find operator.
bool digit(char ch){
	return (ch>='0'&&ch<='9') || ch=='.' || ch=='j';
}
bool not_digit(char ch){
	return !digit(ch);
}
bool is_un_optr(const std::string& s){
	static const std::string opt_u[3]={"~","-","a"};
	const std::string* pt = std::find(opt_u,opt_u+3,s);
	return pt == opt_u+3? false: true;
}
bool is_bin_optr(const std::string& s){
	static const std::string opt_b[4]={"+","-","*","/"};
	const std::string* pt = std::find(opt_b,opt_b+4,s);
	return pt == opt_b+4? false: true;
}

//group2: match brackets and operators.
bool outside(string::const_iterator b,string::const_iterator i){
	int count = 0;
	while(i != b){
		if(*i=='(') ++count;
		else if(*i==')') --count;
		--i;
	}
	if(*b == '(') ++count;
	else if(*b == ')') --count;
	return count == 0;
}
bool outside_pm(string::const_iterator b,string::const_iterator i){
	return (*i=='+'||*i=='-') && outside(b,i); 
}
bool outside_md(string::const_iterator b,string::const_iterator i){
	return (*i=='*'||*i=='/'||*i=='^') && outside(b,i);
}
bool matched_brackets(string::const_iterator b,string::const_iterator e){
    unsigned int left = 0u,right = 0u;
    while(b!=e){
        if(*b == '(') left++;
        else if(*b == ')') ++right;
        ++b;
    }
    return left == right;
}

//group 3:
Expr trans_digit(string::const_iterator b,string::const_iterator e){
	string s(b,e);
	string::const_iterator i = find(b,e,'j');
	if(i == e)
	return atof(s.c_str());
	return converter(std::string(b,e));
}
Expr translator(string::const_iterator b,string::const_iterator e){
	string::const_iterator i1 = find_if(b,e,not_digit);
    if(!matched_brackets(b,e)) throw std::domain_error("unmatched brackets");
	if(i1 == e) return trans_digit(b,e);
	
	string::const_iterator i = b;//deal with + and -.
	vector<string::const_iterator> get;
	while(i != e){
		if(outside_pm(b,i)) get.push_back(i);
		++i;
	}
	if(!get.empty()){
		Expr res = translator(b,get[0]);
		vector<string::const_iterator>::size_type l = 0;
		while(l != get.size() - 1){
			res = Expr(*(get[l])=='+'?"+":"-",res,
			translator(get[l]+1,get[l+1]));
			++l;
		}
		res = Expr(*(get[l])=='+'?"+":"-",res,
		translator(get[l]+1,e));
		return res;
	}
	
	vector<string::const_iterator> collect;
	i = b;
	while(i != e){
		if(outside_md(b,i)) collect.push_back(i);
		++i;
	}
	if(!collect.empty()){
		Expr res = translator(b,collect[0]);
		vector<string::const_iterator>::size_type l = 0;
		while(l != collect.size() - 1){
			if(*(collect[l])=='^') res = 
			Expr("^",res,translator(collect[l]+1,e));
			else
			res = Expr(*(collect[l])=='*'?"*":"/",res,
			translator(collect[l]+1,collect[l+1]));
			++l;
		}
		
		if(*(collect[l])=='^') res = Expr("^",res,translator(collect[l]+1,e));
		else
		res = Expr(*(collect[l])=='*'?"*":"/",res,
			translator(collect[l]+1,e));
		return res;
	}
	else{
		if(*b=='(' && *(e-1)==')') return translator(b+1, e-1);
		if(*b == '~') return Expr("~",translator(b+1,e));
		if(*b == '-') return Expr("-",translator(b+1,e));
		if(*b >='a' && *b <='z'){
			string::const_iterator i = b;
			while(*i >='a' && *i <='z') ++i;
			return Expr(string(b,i),translator(i,e));
		}
	}

	return Expr(complex_num(0.0));
}