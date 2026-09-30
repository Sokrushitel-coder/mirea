#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
bool is_number(const std::string& s)
{
    int i = 0;
    if (s[i]=='+' || s[i]=='-') i++;
    while (i<s.size() && s[i]>='0' && s[i] <='9') i++;
    if (i==s.size()) return true;
    if (s[i]=='.' && i>0 && s[i-1]>='0' && s[i-1]<='9') i++;
    while (i<s.size() && s[i]>='0' && s[i] <='9') i++;
    //cout << '\n' <<  i << " " << s.size()  << " " << s<< '\n';
    if (i<s.size() && (s[i]=='E' ||s[i]=='e')){
        i++;
        if (i<s.size() && (s[i]=='+' || s[i]=='-')) i++;
        while (i<s.size() && s[i]>='0' && s[i] <='9') i++;
    }
    if (i<s.size() && (s[i]=='f' || s[i]=='F' || s[i]=='L' || s[i]=='l')) i++;
    if (i<s.size()) return false;
    else return true;
}
int main(){
    ifstream f("input.txt");
    char c=' ';
    string CS = "H";
    string buf;
    vector <string> asgns;
    vector <string> kwords;
    vector <string> ids;
    vector <string> nms;
    vector <string> dlms;
    vector <string> errs;
    while (f.good()){
        //cout << c;
        if (CS=="H"){// начальное состояние
            if (c=='_' || c>='A' && c<='Z' || c>='a' && c<='z'){
                buf.clear();
                buf.push_back(c);
                CS = "ID";
                continue;
            }else if (c==':'){
                buf.clear();
                buf.push_back(c);
                CS = "ASGN";
                continue;
            }else if (c=='(' || c==')' || c==';' || c=='<' || c=='>' || c=='='){
                buf.clear();
                buf.push_back(c);
                CS = "DLM";
                continue;
            }else if (c>='0' && c<='9' || c=='-' || c=='+' || c=='.' ){
                buf.clear();
                buf.push_back(c);
                CS = "NM";
                continue;
            }else if (c==' ' || c=='\t' || c =='\n'){
                buf.clear();
                if (!f.get(c)) break;

                continue;
            }else{
                buf.clear();
                buf.push_back(c);
                CS = "ERR";
                continue;
            }
        }else if (CS=="ASGN"){ // Состояние ASGN
            if (!f.get(c)) break;
            if (c=='='){
                buf.push_back(c);
                asgns.push_back(buf);
                CS = "H";
                c = ' ';
                buf.clear();
                continue;
            }else{
                buf.push_back(c);
                CS = "ERR";
                continue;
            }
        }else if (CS == "ID"){ // Состояние ID
            if (!f.get(c)) break;
            if (c=='_' || c>='A' && c<='Z' || c>='a' && c<='z'|| c>='0' && c<='9'){
                buf.push_back(c);
                continue;
            }else{
                if (buf=="for" || buf =="do"){
                    kwords.push_back(buf);
                }else{
                    ids.push_back(buf);
                }
                CS = "H";
                buf.clear();
                continue;
            }
        }else if(CS=="NM"){ //состояние NM
            if (!f.get(c)) break;
            if (c=='-' || c=='+' || c=='.' || c>='0' && c<='9' || c=='e' || c=='E'){
                buf.push_back(c);
            }else{
                if (is_number(buf)){
                    nms.push_back(buf);
                    buf.clear();
                    CS = "H";
                }else{
                    CS = "ERR";
                }
            }
        }else if (CS =="DLM"){ //Состояние DLM
            dlms.push_back(buf);
            buf.clear();
            CS = "H";
            c = ' ';
        }else{ // Состояние ERR
            errs.push_back(buf);
            buf.clear();
            c = ' ';
            CS = "H";
        }
    }
    cout << " assignments: ";
    for (auto s:asgns) cout << s << " ";
    cout << "\n key words: ";
    for (auto s:kwords) cout << s << " ";
    cout << "\n identificators: ";
    for (auto s:ids) cout << s << " ";
    cout << "\n numbers: ";
    for (auto s:nms) cout << s << " ";
    cout << "\n delimeters: ";
    for (auto s:dlms) cout << s << " ";
    cout << "\n errors:";
    for (auto s:errs) cout << s << " ";
    cout << '\n';
}
