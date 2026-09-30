#ifndef SYNTAX_ANALYZER_H_INCLUDED
#define SYNTAX_ANALYZER_H_INCLUDED
#include <vector>
#include <string>
#include <set>
using namespace std;
class syntax_analyzer{
private:
    vector <pair<string, string> > LEXEMS;
    vector<pair<int, int> > POS;
    int i;
    string curr_lex;
    string curr_type;
    set <string> id_table;
public:
    syntax_analyzer(vector <pair<string, string> > LEXEMS, vector<pair<int, int> > POS);
    void analyze();
    void up_lex();
    void PROG();
    void DEF();
    void OPER();
    void COMB();
    void ASGN();
    void COND();
    void FCL();
    void CCL();
    void IN();
    void OUT();
    void EXPR();
    void OPRD();
    void SM();
    void ML();
};


#endif // SYNTAX_ANALYZER_H_INCLUDED
