#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int val) {
        if (top == MAX_SIZE - 1) {
            cout << "Стек переполнен" << endl;
            return;
        }
        arr[++top] = val;
        //cout<<"top "<<top<<endl;
    }

    void pop() {
        if (top == -1) {
            cout << "Стек уже пуст" << endl;
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Стек пуст" << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void clear() {
        top = -1;
    }
};
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = nullptr;
    }
};

class Stack1 {
private:
    Node* top;

public:
    Stack1() {
        top = nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Стек пуст" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Стек пуст" << endl;
            return -1;
        }
        return top->val;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void clear() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
string addTwoNumbers(string num1, string num2) {
    Stack1 stack1;
    Stack1 stack2;
    Stack1 result;

    // Заполнение стеков числами
    for (char c : num1) {
        stack1.push(c - '0');
    }
    for (char c : num2) {
        stack2.push(c - '0');
    }

    int carry = 0; // Значение для переноса разряда
    while (!stack1.isEmpty() || !stack2.isEmpty()) {
        int sum = carry;
        if (!stack1.isEmpty()) {
            sum += stack1.peek();
            stack1.pop();
        }
        if (!stack2.isEmpty()) {
            sum += stack2.peek();
            stack2.pop();
        }

        result.push(sum % 10);
        carry = sum / 10;
    }

    if (carry > 0) {
        result.push(carry);
    }

    string sumStr;
    while (!result.isEmpty()) {
        sumStr += to_string(result.peek());
        result.pop();
    }

    return sumStr;
}


int main() {
    system("chcp 1251");
    int task;
    cout<<"Введите номер задания (1 или 2)"<<endl;
    cin>>task;
    if (task==1){
    int choose;
    cout<<"Введите тип стека (1 - на массиве, 2 - на односвязном списке)\n";
    cin>>choose;
    if (choose==1){
        Stack s;
        while (1){
            cout<<"Введите номер действия:\n1. втолкнуть элемент в стек\n2. вытолкнуть элемент из стека\n3. вернуть значение элемента в вершине стека\n4. сделать стек пустым\n5. определить пуст ли стек\n";
            int c;
            cin>>c;
            switch (c){
            case 1:
                cout<<"Введите значение элемента"<<endl;
                int elem;
                cin>>elem;
                s.push(elem);
                cout<<"Элемент добавлен"<<endl;
                break;
            case 2:

                s.pop();
                cout<<"Элемент вытолкнут из стека "<<endl;
                break;
            case 3:
                cout << "Верхний элемент: " << s.peek() << endl;
                break;
            case 4:
                s.clear();
                cout << "Стек теперь пуст" << endl;
                break;
            case 5:
                if (s.isEmpty())
                    cout << "Стек пуст" << endl;
                else
                    cout << "Стек не пуст" << endl;
                break;

            }
            cout<<endl;
        }
    }
    if (choose==2){
        Stack1 s;
        while (1){
            cout<<"Введите номер действия:\n1. втолкнуть элемент в стек\n2. вытолкнуть элемент из стека\n3. вернуть значение элемента в вершине стека\n4. сделать стек пустым\n5. определить пуст ли стек\n";
            int c;
            cin>>c;
            switch (c){
            case 1:
                cout<<"Введите значение элемента"<<endl;
                int elem;
                cin>>elem;
                s.push(elem);
                cout<<"Элемент добавлен"<<endl;
                break;
            case 2:

                s.pop();
                cout<<"Элемент вытолкнут из стека "<<endl;
                break;
            case 3:
                cout << "Верхний элемент: " << s.peek() << endl;
                break;
            case 4:
                s.clear();
                cout << "Стек теперь пуст" << endl;
                break;
            case 5:
                if (s.isEmpty())
                    cout << "Стек пуст" << endl;
                else
                    cout << "Стек не пуст" << endl;
                break;

            }
            cout<<endl;
        }
    }
    }else if (task==2){
        int choose;
        cout<<"Введите способ тестирования (1 - автоматическое, 2 - ручное)"<<endl;
        cin>>choose;
        if (choose==1){
        string num1 = "123456789";
        string num2 = "987654321";
        string sum = addTwoNumbers(num1, num2);
        cout << "Сумма 123456789 и 987654321: " << sum << endl;
        }else if (choose==2){
        string num1;
        string num2;
        cout<<"Введите через пробел два числа, которые надо сложить"<<endl;
        cin>>num1>>num2;
        string sum = addTwoNumbers(num1, num2);
        cout << "Сумма: " << sum << endl;
        }
    return 0;
    }
    return 0;


}
