#include "lexic_analyzer.h"
lexic_analyzer::lexic_analyzer(string file_path){
    this->f.open(file_path);
}
void lexic_analyzer::analyze(){
    int row = 1, column = -1;
    while (f.good()){
        //cout << c;
        if (CS=="H"){// начальное состояние
            if (c>='A' && c<='Z' || c>='a' && c<='z'){
                buf.clear();
                buf.push_back(c);
                CS = "ID";
                continue;
            }else if(c>='0' && c<='9' || c=='.'){
                buf.clear();
                buf.push_back(c);
                CS = "NUM";
                continue;
            }else if (c==':' ||c==','){
                if (c=='\n'){
                    row++;
                    column = -1;
                }
                buf.clear();
                buf.push_back(c);
                LEXEMS.push_back({buf, "LEX"});
                column++;
                LEXEMS_POS.push_back({row, column});
                buf.clear();
                if (!f.get(c)) break;
                continue;
            }else if ( c=='\n' || c==';' || c=='{' || c=='}' || c=='(' || c==')'){
                if (c=='\n'){
                    row++;
                    column = -1;
                }
                buf.clear();
                buf.push_back(c);
                LEXEMS.push_back({buf, "SEP"});
                column++;
                LEXEMS_POS.push_back({row, column});
                buf.clear();
                if (!f.get(c)) break;
                continue;

            }else if (c=='='){
                buf.clear();
                LEXEMS.push_back({"=", "ASGN"});
                column++;
                LEXEMS_POS.push_back({row, column});
                if (!f.get(c)) break;
                continue;
            }else if (c=='~'){
                buf.clear();
                LEXEMS.push_back({"~", "OPUN"});
                LEXEMS_POS.push_back({row, column});
                if (!f.get(c)) { column++; break;}
                continue;
            }else if (c==' ' || c=='\t'){
                if (c=='\t') column+=4;
                else column++;
                buf.clear();
                if (!f.get(c)) { column++; break;}
                continue;
            }else{
                buf.clear();
                buf.push_back(c);
                CS = "ERR";
                continue;
            }
        }else if (CS == "ID"){ // Состояние ID
            bool fl;
            if (f.get(c)) column++, fl = 1;
            else fl = 0;
            if (fl && (c>='A' && c<='Z' || c>='a' && c<='z'|| c>='0' && c<='9')){
                buf.push_back(c);
                continue;
            }else if (c=='_'){
                buf.push_back(c);
                CS = "END_ELSE";
                continue;
            }else{
                if (key_words.find(buf)!=key_words.end()){
                    LEXEMS.push_back({buf, "KWRD"});
                    LEXEMS_POS.push_back({row, column});
                }else if (logic_const.find(buf)!=logic_const.end()){
                    LEXEMS.push_back({buf, "LCST"});
                    LEXEMS_POS.push_back({row, column});
                }else if (types.find(buf)!=types.end()){
                    LEXEMS.push_back({buf, "TYPE"});
                    LEXEMS_POS.push_back({row, column});
                }else if (OPAT.find(buf)!=OPAT.end()){
                    LEXEMS.push_back({buf, "OPAT"});
                    LEXEMS_POS.push_back({row, column});
                }else if (OPSM.find(buf)!=OPSM.end()){
                    LEXEMS.push_back({buf, "OPSM"});
                    LEXEMS_POS.push_back({row, column});
                }else if (OPML.find(buf)!=OPML.end()){
                    LEXEMS.push_back({buf, "OPML"});
                    LEXEMS_POS.push_back({row, column});
                }else{
                    LEXEMS.push_back({buf, "ID"});
                    LEXEMS_POS.push_back({row, column});
                }
                if (fl==0) break;
                CS = "H";
                buf.clear();
                continue;
            }
        }else if(CS=="NUM"){ //состояние NM
            bool fl;
            if (f.get(c)) column++, fl = 1;
            else fl = 0;
            if (fl && (c>='0' && c<='9' || c>='A' && c<='F' || c>='a' && c<='f' || c=='h' || c=='H' || c=='o' || c=='O' || c=='.' || c=='+' || c=='-')){
                buf.push_back(c);
            }else{
                if (fl==1 && c!=' ' && c!='\t' && c!='\n' && c!=')' && c!='}' && c!=';'){
                    CS = "ERR";
                    continue;
                }
                if (is_bin(buf) || is_oct(buf) || is_hex(buf) || is_dec(buf)){
                    LEXEMS.push_back({buf, "INT"});
                    LEXEMS_POS.push_back({row, column});
                    buf.clear();
                    CS = "H";
                    continue;
                }
                if (is_real(buf)){
                    LEXEMS.push_back({buf, "REAL"});
                    LEXEMS_POS.push_back({row, column});
                    buf.clear();
                    CS = "H";
                    continue;
                }
                if (fl==0) break;
                CS = "ERR";
            }
        }else if (CS =="END_ELSE"){
            bool fl;
            if (f.get(c)) column++, fl = 1;
            else fl = 0;
            if (fl && c>='a' && c<='z'){
                buf.push_back(c);
                continue;
            }else{
                if (buf=="end_else"){
                    LEXEMS.push_back({buf, "KWRD"});
                    LEXEMS_POS.push_back({row, column});
                }else{
                    CS = "ERR";
                    continue;
                }
            }
            if (fl==0) break;
            buf.clear();
            CS = "H";
        }else{ // Состояние ERR
            buf.push_back(c);
            ERRS.push_back(buf);
            buf.clear();
            if (!f.get(c)) { column++; break;}
            CS = "H";
        }
    }

    cout << "LEXEMS:\n";
    for (int i=0; i<LEXEMS.size(); i++){
        cout << "(" << LEXEMS[i].first << ", " << LEXEMS[i].second << "): " << LEXEMS_POS[i].first << " " << LEXEMS_POS[i].second << "\n";
    }

}
vector <pair<string, string> > lexic_analyzer::get_lexems(){
    return LEXEMS;
}
vector <string> lexic_analyzer::get_errors(){
    return ERRS;
}
vector <pair<int, int> > lexic_analyzer::get_pos(){
    return LEXEMS_POS;
}
