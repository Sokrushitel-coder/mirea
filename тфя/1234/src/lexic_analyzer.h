#ifndef LEXIC_ANALYZER_H_INCLUDED
#define LEXIC_ANALYZER_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <exception>
using namespace std;
class lexic_analyzer{
private:
    inline bool is_real(const std::string& s)
    {
        int i = 0;
        while (i<s.size() && s[i]>='0' && s[i]<='9') i++;
        bool f = 0;
        if (i==s.size() || s[i]!='E' && s[i]!='e' && s[i]!='.') return false;
        else i++;
        if (s[i-1]=='e' || s[i-1]=='E') f = 1;
        if (f && i==1) return false;
        if (f){
            if (i<s.size() && (s[i]=='+' || s[i]=='-')) i++;
            if (i==s.size()) return false;
            while (i<s.size() && s[i]>='0' && s[i]<='9') i++;
            if (i==s.size()) return true;
            return false;
        }
        if (i==s.size()) return false;
        if (!(s[i]>='0' && s[i]<='9')) return false;
        while (i<s.size() && s[i]>='0' && s[i]<='9') i++;
        if (i<s.size() && (s[i]=='E' || s[i]=='e')){
            i++;
            if (i<s.size() && (s[i]=='+' || s[i]=='-')) i++;
            if (i==s.size()) return false;
            while (i<s.size() && s[i]>='0' && s[i]<='9') i++;
            if (i==s.size()) return true;
            return false;
        }
        if (i==s.size()) return true;
        return false;
    }
    inline bool is_bin(const std::string& s){
        int i = 0;
        while (i<s.size() && s[i]>='0' && s[i]<='1') i++;
        if (i<s.size() && (s[i]=='B' || s[i]=='b')) i++;
        else return false;
        if (i<s.size()) return false;
        return true;
    }
    inline bool is_oct(const std::string& s){
        int i = 0;
        while (i<s.size() && s[i]>='0' && s[i]<='7') i++;
        if (i<s.size() && (s[i]=='O' || s[i]=='o')) i++;
        else return false;
        if (i<s.size()) return false;
        return true;
    }
    inline bool is_hex(const std::string& s){
        int i = 0;
        while (i<s.size() && (s[i]>='0' && s[i]<='9' || s[i]>='A' && s[i]<='F' || s[i]>='a' && s[i]<='f')) i++;
        if (i<s.size() && (s[i]=='H' || s[i]=='h')) i++;
        else return false;
        if (i<s.size()) return false;
        return true;
    }
    inline bool is_dec(const std::string& s){
        int i = 0;
        while (i<s.size() && s[i]>='0' && s[i]<='9') i++;
        if (i<s.size() && (s[i]=='D' || s[i]=='d')) i++;
        if (i<s.size()) return false;
        return true;
    }
    ifstream f;
    char c=' ';
    string CS = "H";
    string buf;
    vector <pair<string, string> > LEXEMS;
    vector <pair<int, int> > LEXEMS_POS;
    vector <string> ERRS;
    set <string> logic_const = {"true", "false"};
    set <string> types = {"integer", "real", "boolean"};
    set <string> key_words = {"end", "let", "if", "then", "else", "for", "do", "while", "input", "output"};
    set <string> OPAT = {"NE", "EQ", "LT", "LE", "GT", "GE"};
    set <string> OPSM = {"plus", "minus", "or"};
    set <string> OPML = {"mult", "div", "and"};
public:
    lexic_analyzer(string file_path);
    void analyze();
    vector <pair<string, string> > get_lexems();
    vector <pair<int, int> > get_pos();
    vector <string> get_errors();
};


#endif // LEXIC_ANALYZER_H_INCLUDED
