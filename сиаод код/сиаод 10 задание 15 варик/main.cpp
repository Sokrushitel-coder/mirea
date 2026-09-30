#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<int> buildBadCharTable(const string& pattern) {
    vector<int> badCharTable(256, -1);
    int patternLength = pattern.length();
    for (int i = 0; i < patternLength - 1; i++) {
        badCharTable[static_cast<unsigned char>(pattern[i])] = i;
    }
    return badCharTable;
}

vector<int> searchBoyerMoore(const string& text, const string& pattern) {
    vector<int> results;
    int textLength = text.length();
    int patternLength = pattern.length();

    vector<int> badCharTable = buildBadCharTable(pattern);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            // Образец найден
            results.push_back(shift);
            shift += (shift + patternLength < textLength) ? patternLength - badCharTable[static_cast<unsigned char>(text[shift + patternLength])] : 1;
        } else {
            shift += max(1, j - badCharTable[static_cast<unsigned char>(text[shift + j])]);
        }
    }

    return results;
}


bool containsName(const string& text) {
    regex pattern("(Анна|Антонина|Алевтина|Алла)");
    return regex_search(text, pattern);
}

int main() {
    system("chcp 1251");
    int choose;
    cout<<"Введите номер задания (1 или 2)"<<endl;
    cin>>choose;
    if (choose==1){
        cout<<"Введите тип тестирования (1 - ручное, 2 - автоматическое)"<<endl;
        int choose1;
        cin>>choose1;
        if (choose1==1){
            string text;
            int count_patterns;
            cout<<"Введите предложение"<<endl;
            getline(cin, text);
            getline(cin, text);
            //cout<<text;
            cout<<"Введите количество образцов"<<endl;
            cin>>count_patterns;
            vector<string> patterns;
            vector<int> occurrences(count_patterns, 0);
            cout<<"Введите через пробел образцы"<<endl;
            for (int i=0;i<count_patterns;i++){
                string in;
                cin>>in;

                patterns.push_back(in);

            }
            for (int i = 0; i < count_patterns; i++) {

                vector<int> results = searchBoyerMoore(text, patterns[i]);
                occurrences[i] = results.size();
            }

            cout << "Таблица вхождений образцов в текст:\n";
            for (int i = 0; i < count_patterns; i++) {
                cout << patterns[i] << ": " << occurrences[i] << " раз(а)\n";
            }
        }else if(choose1==2){
            string text = "Этот текст содержит несколько образцов, включая образец 123 и образец abc.";
            vector<string> patterns = { "образец", "123", "abc" };

            vector<int> occurrences(patterns.size(), 0);

            for (int i = 0; i < patterns.size(); i++) {

                vector<int> results = searchBoyerMoore(text, patterns[i]);
                occurrences[i] = results.size();
            }

            cout << "Таблица вхождений образцов в текст:\n";
            for (int i = 0; i < patterns.size(); i++) {
                cout << patterns[i] << ": " << occurrences[i] << " раз(а)\n";
            }
        }
    }else if (choose==2){

        int choose1;
    cout<<"Введите тип тестирования (1 - ручное, 2 - автоматическое)"<<endl;
    cin>>choose1;
    string sentence;
    if (choose1==2){
    sentence = "Меня зовут Антонина.";

    }else if (choose1==1){
        cout<<"Введите предложение"<<endl;
        getline(cin, sentence);

        getline(cin, sentence);
        cout<<sentence;
    }
    if (containsName(sentence)) {
        cout << "Предложение содержит одно из имен." << endl;
    } else {
        cout << "Предложение не содержит имен." << endl;
    }

    }
}
