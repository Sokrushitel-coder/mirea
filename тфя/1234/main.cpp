#include <iostream>
#include "C:\Users\ho6oT\Documents\לטנ‎א\עפÿ\1234\src\lexic_analyzer.h"
#include "C:\Users\ho6oT\Documents\לטנ‎א\עפÿ\1234\src\syntax_analyzer.h"
using namespace std;

int main()
{
    lexic_analyzer LA("input.txt");
    LA.analyze();
    auto lexic_errors = LA.get_errors();
    if (!lexic_errors.empty()){
        cout << "Lexic errors\n";
        for (auto p:lexic_errors){
            cout << p << '\n';
        }
        return 0;
    }
    syntax_analyzer SA(LA.get_lexems(), LA.get_pos());
    SA.analyze();
}
