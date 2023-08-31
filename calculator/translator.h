#pragma once
#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Expr_node.h"
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
#include "complex_num.h"

using std::string;		using std::vector;
using std::find_if; 	using std::find;

//group 1: find operator.
bool digit(char ch);
bool not_digit(char ch);
bool is_un_optr(const std::string& s);
bool is_bin_optr(const std::string& s);

//group2: match brackets and operators.
bool outside(std::string::const_iterator b,std::string::const_iterator i);
bool outside_pm(std::string::const_iterator b,std::string::const_iterator i);
bool outside_md(std::string::const_iterator b,std::string::const_iterator i);
bool matched_brackets(std::string::const_iterator b,std::string::const_iterator e);

//group3: convert a expression into a binary tree.
Expr trans_digit(std::string::const_iterator b,std::string::const_iterator e);
Expr translator(std::string::const_iterator b,std::string::const_iterator e);

#endif//TRANSLATOR_H

