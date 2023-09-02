#include "include\calculator.h"
using std::string;      using std::ofstream;
using std::ostream;     using std::cout;
using std::cin;         using std::endl;

void calculator::run(void){
    static const string hint ="e = 2.7182818284590452353602874713527 = exp(1.0)\n"
    "PI= 3.1415926535897932384626433832795 = arccos(-1.0)\n"
    "sqrt(x) = (x)^(0.5), sqr(x) = (x)^(2.0). \n\n";
    if(active){
        cout << hint;
    }

    string s;
    Expr res;
    ofstream out("workLog.txt",std::ostream::app);
    complex_num c;

    while(active){
        cout << "<<< ";
        cin >> s;

        if(s == "quit" || s=="exit" || s.empty()) break;
        if(s == "hint"){
            cout << hint; continue;
        }

        try{
            res = translator(s.begin(),s.end());
        }
        catch(std::domain_error e){
            cout << e.what() << endl;
            continue;
        }
        c = res.cval();

        out << s << " = " << c <<" = "; 
        c.report(out);
        out << endl;
        out << "Expr = " << res << '\n' << endl;
        cout << c << " (";
        c.report(cout);
        cout << ')' << endl;
    }
}
