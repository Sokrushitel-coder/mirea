#include "syntax_analyzer.h"
#include <iostream>
#include <exception>
syntax_analyzer::syntax_analyzer(vector <pair<string, string> > LEXEMS, vector<pair<int, int> > POS){
    //system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    this->LEXEMS = LEXEMS;
    this->POS = POS;
    this->i = 0;
}
void syntax_analyzer::up_lex(){
    if (i==LEXEMS.size()) throw logic_error("No lexems: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    curr_lex = LEXEMS[i].first;
    curr_type = LEXEMS[i].second;
    i++;
}
void syntax_analyzer::analyze(){
    PROG();
}
void syntax_analyzer::PROG(){
    up_lex();
    if (curr_type=="ID"){
        up_lex();
        if (curr_type=="ASGN"){
            i-=2;
            OPER();
        }else{
            i-=2;
            DEF();
        }
    }else if(!(curr_lex==":" || curr_lex=="\n")){
        i--;
        //cout << i;
        OPER();
    }else i--;
    up_lex();
    if (curr_lex!=":" && curr_lex!="\n") throw logic_error("Отсутствует ':' или перенос строки после операции: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    while (curr_lex!="end"){
        if (curr_type=="ID"){
            up_lex();
            if (curr_type=="ASGN"){
                i-=2;
                OPER();
            }else{
                i-=2;
                DEF();
            }
        }else if(!(curr_lex==":" || curr_lex=="\n")){
            i--;
            OPER();
        }else i--;
        up_lex();
        if (curr_lex!=":" && curr_lex!="\n") throw logic_error("Отсутствует ':' или перенос строки после операции: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
        up_lex();
    }
    cout << "No syntax Error!\n";
}
void syntax_analyzer::DEF(){
    up_lex();
    if (curr_type!="ID") throw logic_error("Не найден идентификатор в объявлении: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    if (id_table.find(curr_lex)==id_table.end()) id_table.insert(curr_lex);
    else throw logic_error("Переопределение идентификатора "+curr_lex+": "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    while(curr_lex==","){
        up_lex();
        if (curr_type!="ID") throw logic_error("Ожидается идентификатор после ',' в объявлении: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
        if (id_table.find(curr_lex)==id_table.end()) id_table.insert(curr_lex);
        else throw logic_error("Переопределение идентификатора "+curr_lex+": "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
        up_lex();
    }
    if (curr_lex!=":") throw logic_error("Ожидается ':' после списка идентификаторов в объявлении: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_type!="TYPE") throw logic_error("Не найден тип в объявлении: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!=";") throw logic_error("Не найдена ';' после объявления: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
}
void syntax_analyzer::OPER(){
    up_lex();
    i--;
    if (curr_lex=="{") COMB();
    else if (curr_lex=="let" || curr_type=="ID") ASGN();
    else if (curr_lex=="if") COND();
    else if (curr_lex=="for") FCL();
    else if (curr_lex=="do") CCL();
    else if (curr_lex=="input") IN();
    else if (curr_lex=="output") OUT();
    else throw logic_error("Некорректный оператор:: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second)+curr_lex);
}
void syntax_analyzer::COMB(){
    up_lex();
    if (curr_lex!="{") throw logic_error("Отсутствует '{' в комбинированном операторе: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    OPER();
    up_lex();
    while (curr_lex!="}"){
        if (curr_lex!=";") throw logic_error("Отсутствует ';' между операторами в комбинированном операторе: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
        OPER();
        up_lex();
    }
}
void syntax_analyzer::ASGN(){
    up_lex();
    if (curr_lex=="let") up_lex();
    if (curr_type!="ID") throw logic_error("Не найден идентификатор в присвоении: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    if (id_table.find(curr_lex)==id_table.end()) throw logic_error("Неопределённый идентификатор "+curr_lex+": "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!="=") throw logic_error("не найден '=' в присвоении: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    EXPR();
}
void syntax_analyzer::COND(){
    up_lex();
    if (curr_lex!="if") throw logic_error("не найден 'if' в условном операторе: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    EXPR();
    up_lex();
    if (curr_lex!="then") throw logic_error("не найден 'then' в условном операторе: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    OPER();
    up_lex();
    if (curr_lex=="else"){
        OPER();
        up_lex();
    }
    if (curr_lex!="end_else") throw logic_error("не найден 'end_else' в условном операторе: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
}
void syntax_analyzer::FCL(){
    up_lex();
    //cout << 0;
    if (curr_lex!="for") throw logic_error("не найден 'for' в цикле с фиксированным цислом повторений: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    //cout << 0;
    up_lex();
    if (curr_lex!="(") throw logic_error("не найдена '(' в цикле с фиксированным цислом повторений: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!=";"){
        i--;
        //cout << 0;
        EXPR();
        up_lex();
    }
    if (curr_lex!=";") throw logic_error("не найдена ';' в цикле с фиксированным цислом повторений: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!=";"){
        i--;
        EXPR();
        up_lex();
    }
    if (curr_lex!=";") throw logic_error("не найдена ';' в цикле с фиксированным цислом повторений: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!=")"){
        i--;
        EXPR();
        up_lex();
    }
    if (curr_lex!=")") throw logic_error("не найдена ')' в цикле с фиксированным цислом повторений: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    OPER();
}
void syntax_analyzer::CCL(){
    up_lex();
    if (curr_lex!="do") throw logic_error("не найдено 'do' в цикле с предусловием: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!="while") throw logic_error("не найдено 'while' в цикле с предусловием: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    EXPR();
    OPER();
    up_lex();
    if (curr_lex!="loop") throw logic_error("не найдено 'loop' в цикле с предусловием: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
}
void syntax_analyzer::IN(){
    up_lex();
    if (curr_lex!="input") throw logic_error("не найдено 'input' в операторе ввода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!="(") throw logic_error("не найдено '(' в операторе ввода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_type!="ID") throw logic_error("ожидается идентификатор в операторе ввода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    if (id_table.find(curr_lex)==id_table.end()) throw logic_error("Неопределённый идентификатор "+curr_lex+": "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    while (curr_lex!=")"){
        if (curr_type!="ID") throw logic_error("ожидается идентификатор в операторе ввода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
        if (id_table.find(curr_lex)==id_table.end()) throw logic_error("Неопределённый идентификатор "+curr_lex+": "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
        up_lex();
    }
    if (curr_lex!=")") throw logic_error("не найдено ')' в операторе ввода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
}
void syntax_analyzer::OUT(){
    up_lex();
    if (curr_lex!="output") throw logic_error("не найдено 'output' в операторе вывода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    up_lex();
    if (curr_lex!="(") throw logic_error("не найдено '(' в операторе вывода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    EXPR();
    up_lex();
    while (curr_lex!=")"){
        i--;
        EXPR();
        up_lex();
    }
    if (curr_lex!=")") throw logic_error("не найдено ')' в операторе вывода: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
}
void syntax_analyzer::EXPR(){
    //cout << 0;
    OPRD();
    up_lex();
    while (curr_type=="OPAT"){
        OPRD();
        up_lex();
    }
    i--;
}
void syntax_analyzer::OPRD(){
    //cout << 0;
    SM();
    up_lex();
    while (curr_type=="OPSM"){
        SM();
        up_lex();
    }
    i--;
}
void syntax_analyzer::SM(){

    ML();
    up_lex();
    while (curr_type=="OPML"){
        ML();
        up_lex();
    }
    i--;
}
void syntax_analyzer::ML(){
    up_lex();
    if (curr_type=="ID" && id_table.find(curr_lex)==id_table.end()) throw logic_error("Неопределённый идентификатор "+curr_lex+": "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
    if (curr_type=="ID" || curr_type=="INT" || curr_type=="REAL" || curr_type=="LCST") return;
    if (curr_type=="OPUN"){
        ML();
        return;
    }
    if (curr_lex=="("){
        EXPR();
        up_lex();
        if (curr_lex!=")") throw logic_error("не найдена ')' в множителе: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
        return;
    }
    throw logic_error("некорректный множитель: "+to_string(POS[i-2].first)+":"+to_string(POS[i-2].second));
}
