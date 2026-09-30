//#include <iostream>
//#include <stack>  // подключаем библиотеку для
//                  // использования стека
//using namespace std;
//
//int main() {
//  setlocale(LC_ALL,"rus");
//  stack <string> steck;  // создаем стек
//
//
//
//  cout << "Введите выражение без пробелов" << endl; // предлагаем пользователю
//                                                      // ввести 6 чисел
//
//    string a;
//    cin >> a;
//    for (int i=0;i<a.length();i++){
//            string b=a[i];
//        steck.push(a[i]);  // добавляем введенные числа
//
//    }
//
//
//  if (steck.empty()) cout << "Стек не пуст";  // проверяем пуст ли стек (нет)
//
//  cout << "Верхний элемент стека: " << steck.top() << endl; // выводим верхний элемент
//  cout << "Давайте удалим верхний элемент " << endl;
//
//  steck.pop();  // удаляем верхний элемент
//
//  cout << "А это новый верхний элемент: " << steck.top(); // выводим уже новый
//                                                          // верхний элемент
//  system("pause");
//  return 0;
//}



//#include <iostream>
//#include <stack>
//using namespace std;
//
//struct list{
//    char item; //полезная информация узла списка
//    list *next;//ссылка на следующий элемент списка.
//};
//void show (list *start){
//    cout<<"Текущий вид списка: \n";
//    list *p_list; //рабочий указатель
//    p_list = start->next;//в начале он ссылается на второй узел списка.
//    while (p_list != NULL){
//        cout << p_list->item;//Выводим данные
//        p_list = p_list->next;//передвигаем указатель на один узел.
//    }
//    cout<<endl;
//}
//int main(){
//    system("chcp 1251");
//    cout << "Hello world!" << endl;
//    //string a;
//    //cin>>a;
//    list *start = new list;
//    start->next = NULL;
//    list *p_list = start;
//    int j=0;
//    while(1){
//
//        list *tmp = new list;
//
//        tmp->item=getchar();
//        cout<<tmp->item;
//        //cout<<tmp->item;
//        if (tmp->item=='\n' and j!=0 or tmp->item==EOF){
//            break;
//        }
//        //tmp->item = i; // здесь все понятно
//        tmp->next = NULL; //мы вставляем узел в конец списка и поэтому next = NULL
//        p_list->next = tmp; //теперь p_list-> next указывает на созданный узел
//        p_list = p_list->next;// Передвигаем указатель на последний элемент.
//        j++;
//    }
//    show(p_list);
//    cout<<p_list->item;
//
//}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	vector <string> answer; // строка ответа
	vector <char> oper; // стек
	string number; // строка для записи многозначных чисел
	int bal = 0;
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] and s[i] <= '9') { // случай встречи цифры
			number.push_back(s[i]);
		}
		else if (s[i] == ' ') { // случай встречи пробельного символа


				if (number.length() > 0)     {
					answer.push_back((number)); number = "";

				}
		}
		else if (s[i] == '+' or s[i] == '-') { // случай встречи + или -

			if (s[i] == '-' and (i == 0 or s[i - 1] == '(')) { //проверка на унарный минус
					answer.push_back(0);
			}
			if (number.length() > 0) {
				answer.push_back((number));
				number = "";
			}
			while (!oper.empty() and oper.back() != '(') { // проход по стеку с переносом в строку ответа операций с >= приоритетом
				string w;
				w.push_back(oper.back());
				answer.push_back(w);
				oper.pop_back();
			}
			oper.push_back(s[i]); // добавление в стек операции
		}
		else if (s[i] == '*' || s[i] == '/') { // случай встречи * или /

			if (number.length() > 0) {
				answer.push_back((number));
				number = "";

			}
			while (!oper.empty() and oper.back() != '(' and oper.back() != '+' and oper.back() != '-') { // проход по стеку с переносом в строку ответа операций с >= приоритетом
				string w;
				w.push_back(oper.back());
				answer.push_back(w);
				oper.pop_back();
			}
			oper.push_back(s[i]);
		}
		else if (s[i] == '(') { // случай встречи (
			if (number.length() > 0) {
				answer.push_back((number));
				number = "";
			}
			oper.push_back(s[i]); bal++;
		}
		else if (s[i] == ')') { // случай встречи )
			bal--;
			if (number.length() > 0) {
				answer.push_back((number));
				number = "";
			}
			if (bal < 0) {
				cout << "WRONG";
				return 0;
			}
			while (oper.back() != '(') { // удаление всех символов из стека до (
				string w; w.push_back(oper.back());
				answer.push_back(w);
				oper.pop_back();
			}
			oper.pop_back();
		}
		else {
			cout << "WRONG";
			return 0;
		}
	}
	if (bal != 0) {
		cout << "WRONG";
		return 0;
	}
	if (number.length() > 0) {
		answer.push_back((number));
		number = "";
	}
	while (!oper.empty()) { // добавление всех элементов из стека в строку ответа
		string w;
		w.push_back(oper.back());
		answer.push_back(w);
		oper.pop_back();
	}
	int ans = 0;
	vector <int> st;
	for (auto e : answer) {
		cout << e << ' '; // вывод элементов строки ответа
		if (e == "+") { // случай встречи +
			if (st.size() < 2) {
				cout << "WRONG";
				return 0;
			}
			int a = st.back();
			st.pop_back();
			int b = st.back();
			st.pop_back();
			st.push_back(a + b);
		}
		else if (e == "-") { // случай встречи -
			if (st.size() < 2) {
				cout << "WRONG";
				return 0;
			}
			int a = st.back();
			st.pop_back();
			int b = st.back();
			st.pop_back();
			st.push_back(b - a);
		}
		else if (e == "*") { // случай встречи *
			if (st.size() < 2) {
				cout << "WRONG";
				return 0;
			}
			int a = st.back();
			st.pop_back();
			int b = st.back();
			st.pop_back();
			st.push_back(a * b);
		}
		else if (e == "/") { // случай встречи /
			if (st.size() < 2) {
				cout << "WRONG";
				return 0;
			}
			int a = st.back();
			st.pop_back();
			int b = st.back();
			st.pop_back();
			st.push_back(b / a);
		}
		else {
			st.push_back(stoi(e)); // случай встречи числа
		}
	}
	if (!(st.size() == 1)) {
		cout << "WRONG";
		return 0;
	}
	else {
		cout << '\n' << st.back(); // вывод значения выражения
	}
}
