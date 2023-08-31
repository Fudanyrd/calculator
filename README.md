#This is a Definition of a Calculator

##Data type
    complex number

##Supported operator
    +, -, *, /, ^(pow), ~(conjucate complex numbers)

##supported functions
    ln, sin, cos, tan, arcsin, arccos, arctan, exp
    *since ln of a complex number has no meaning, when you pass a complex number to it,it will just take in its real part*
    *but as for exp(), when you pass a complex number to it, it will work according to Euler Formula"exp(a*j) = cos(a) + j*sin(a)"*

##features
    after running, it will create the file work_log.txt containing the sequence of calculation and result.

##how to use it
    1. using make to get the calculator.exe(prerequisite: you have installed GNU make)
        in your command line, run the following command:
            make -f this.mk
    2. using git bash(or whatever bash) to get the calculator.exe
        in the git bash, run the following command:
            source this.sh; this calculator
    *last*. type in the expressions and you'll get their values, type "exit" to quit whenever you are done.

##examples
    *open calculator.exe, type in "(exp(1.0))^(2.0) and you'll get the two lines*
    (exp(1.0))^(2.0) = 7.38906 + 0j = 7.38906 {0
    Expr = ((exp1)^2)
    *this first line tells you the result is 7.38906+0j, and 7.38906 {0 tells you that the modulus and amplitude of the result*
    *the second line tells you it will firstly calculate exp(1) and then pow(exp(1),2)*

#Warning:
    *use 1j or 1.0j instead of j*
    *use (function(data)) instead of function(data) unless you have good reasons*
    *No whitespaces are allowed in your input expressions(otherwise it will split into more than one expressions and calculate them respectively)*