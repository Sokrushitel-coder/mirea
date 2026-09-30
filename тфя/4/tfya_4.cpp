#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
class state{
public:
    string name;
    bool is_initial;
    bool is_final;
    vector <pair<string, string> > transitions;
    vector <string> parents;
    state(string name){
        this->name = name;
        is_initial = false;
        is_final = false;
    }
};
int main(){
    cout << "Enter set of states:\n";
    string s;
    getline(cin, s);
    string buf;
    vector <state> states;
    for (int i=0; i<s.size(); i++){
        if (s[i]==' ' && buf.size()){
            state tmp(buf);
            states.push_back(tmp);
            buf.clear();
        }else buf.push_back(s[i]);
    }
    if (buf.size()){
        state tmp(buf);
        states.push_back(tmp);
        buf.clear();
    }
    string alphabet;
    cout << "Enter the input alphabet:\n";
    getline(cin, alphabet);
    cout << "Enter state-transitions function (current state, input character, next state):\n";
    getline(cin, s);
    for (int i=0; i<s.size(); i++){
        if (s[i]=='(' || s[i]==' ') continue;
        else if (s[i]==')'){
            string s1, s2, s3;
            string tmp;
            int j = 0;
            for (;; j++){
                if (buf[j]==','){
                    s1 = tmp;
                    tmp.clear();
                    j++;
                    break;
                }else tmp.push_back(buf[j]);
            }
            for (;; j++){
                if (buf[j]==','){
                    s2 = tmp;
                    tmp.clear();
                    j++;
                    break;
                }else tmp.push_back(buf[j]);
            }
            for (;j<buf.size(); j++){
                tmp.push_back(buf[j]);
            }
            s3 = tmp;
            cout << s1 << " " << s2 << " " << s3 << '\n';
            for (auto &e:states){
                if (e.name==s1){
                    e.transitions.push_back({s2, s3});
                    break;
                }
            }
            buf.clear();
        }else buf.push_back(s[i]);
    }
    cout << "Enter a set of initial states:\n";
    getline(cin, s);
    buf.clear();
    for (int i=0; i<s.size(); i++){
        if (s[i]==' ' && buf.size()){
            for (auto &e:states){
                if (e.name==buf){
                    e.is_initial = true;
                }
            }
            buf.clear();
        }else buf.push_back(s[i]);
    }
    if (buf.size()){
        for (auto &e:states){
            if (e.name==buf){
                e.is_initial = true;
            }
        }
        buf.clear();
    }
    cout << "Enter a set of final states:\n";
    set <string> final_states;
    getline(cin, s);
    buf.clear();
    for (int i=0; i<s.size(); i++){
        if (s[i]==' ' && buf.size()){
            final_states.insert(buf);
            for (auto &e:states){
                if (e.name==buf){
                    e.is_final = true;
                }
            }
            buf.clear();
        }else buf.push_back(s[i]);
    }
    if (buf.size()){
        final_states.insert(buf);
        for (auto &e:states){
            if (e.name==buf){
                e.is_final = true;
            }
        }
        buf.clear();
    }
    vector <state> new_states;
    set <string> new_st;
    for (auto e: states){
        if (e.is_initial){
            e.parents.push_back(e.name);
            new_st.insert(e.name);
            new_states.push_back(e);
        }
    }

    for (int i=0; i<new_states.size(); i++){
        new_states[i].transitions.clear();
        map <string, vector<string> > trs;
        for (auto p:new_states[i].parents){
            for (auto e:states){
                if (e.name==p){
                    for (auto tr:e.transitions){
                        trs[tr.first].push_back(tr.second);
                    }
                }
            }
        }
        for (auto& tr:trs){
            sort(tr.second.begin(), tr.second.end());
            tr.second.erase(unique(tr.second.begin(), tr.second.end()), tr.second.end());
            if (tr.second.size()>1){
                string new_s;
                for (auto e:tr.second){
                    new_s+=e;
                }
                if (new_st.find(new_s)==new_st.end()){
                    new_st.insert(new_s);
                    state tmp(new_s);
                    tmp.parents = tr.second;
                    new_states.push_back(tmp);
                }
                new_states[i].transitions.push_back({tr.first, new_s});
            }else{
                if (new_st.find(tr.second[0])==new_st.end()){
                    new_st.insert(tr.second[0]);
                    state tmp(tr.second[0]);
                    tmp.parents = tr.second;
                    new_states.push_back(tmp);
                }
                new_states[i].transitions.push_back({tr.first, tr.second[0]});
            }
        }
    }
    for (auto &st:new_states){
        bool f = 0;
        for (auto p:st.parents){
            if (final_states.find(p)!=final_states.end()){
                f = 1;
                break;
            }
        }
        if (f) st.is_final = true;
    }
    cout << "\n\nDFA:\n";
    cout << "Set of states: ";
    cout << new_states[0].name;
    for (int i=1; i<new_states.size(); i++){
        cout << ", " << new_states[i].name;
    }
    cout << "\n\nInput alphabet: " << alphabet;
    cout << "\n\nState-transitions function:\n";
    for (auto st:new_states){
        for (auto tr:st.transitions){
            cout << "D(" << st.name << ", " << tr.first << ") = " << tr.second << '\n';
        }
    }
    cout << "\nInitial states: ";
    for (auto st:new_states){
        if (st.is_initial) cout << st.name << " ";
    }
    cout << "\n\nFinal states: ";
    for (auto st:new_states){
        if (st.is_final) cout << st.name << " ";
    }
}
/* Test ¹1
1 2 3
a b
(1,a,1) (1,a,2) (1,b,3) (2,a,2) (2,b,1) (2,b,3) (3,a,3) (3,b,3)
1
3
*/
/* Test ¹2
1 2 3 4
a b
(1,a,1) (1,a,2) (1,b,1) (2,a,3) (2,b,3) (3,a,4) (3,b,4)
1
4
*/
