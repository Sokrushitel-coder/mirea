#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Односвязный список
struct Node {
    char data;
    Node* next;
};

void insertBeforeFirst(Node*& head, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void removeByKey(Node*& head, char key) {
    if (head == nullptr) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return;
        }
        curr = curr->next;
    }

    std::cout << "Узел с ключом " << key << " не найден" << std::endl;
}

// Функция для добавления элемента в конец списка
void pushBack(Node*& head, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Функция для создания списка L, включающего элементы, значения которых входят в список L1 и не входят в список L2
Node* createList(Node* L1, Node* L2) {
    Node* L = nullptr;
    Node* temp = L1;
    while (temp != nullptr) {
        bool found = false;
        Node* temp2 = L2;
        while (temp2 != nullptr) {
            if (temp->data == temp2->data) {
                found = true;
                break;
            }
            temp2 = temp2->next;
        }
        if (!found) {
            pushBack(L, temp->data);
        }
        temp = temp->next;
    }
    return L;
}

// Функция для удаления подсписка списка L1 заданным диапазоном позиций
void removeSublist(Node*& head, int start, int end) {
    if (head == nullptr) {
        return;
    }
    //if (start == 1) {
    //    Node* temp = head;
   //     head = head->next;
   //     delete temp;
   //     start++;
   //     end--;
   // }
    Node* subListStart = head;
    int pos = 0;
    while (subListStart != nullptr && pos < start) {
        subListStart = subListStart->next;
        pos++;
    }
    if (subListStart == nullptr || subListStart->next == nullptr) {
        return;
    }
    Node* temp = subListStart->next;
    while (temp != nullptr && pos <= end+start-1 ) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
        pos++;
    }
    subListStart->next = temp;
}

// Функция для упорядочивания списка L2, располагая его значения в порядке возрастания
void sortList(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    vector<char> values;
    Node* temp = head;
    while (temp != nullptr) {
        values.push_back(temp->data);
        temp = temp->next;
    }
    sort(values.begin(), values.end());
    temp = head;
    for (char value : values) {
        temp->data = value;
        temp = temp->next;
    }
}

// Функция для печати списка на экран
void printList(const Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    system("chcp 1251");
    cout<<"Выберите способ функционирования программы\n 1 - автоматический;\n 2 - ручной ввод"<<endl;
    int choose;
    cin>>choose;
    if (choose==1){
    Node* L1 = nullptr;
    Node* L2 = nullptr;

    // Добавление элементов в
    // список L1
    pushBack(L1, 'a');
    pushBack(L1, 'b');
    pushBack(L1, 'c');
    pushBack(L1, 'd');

    // Добавление элементов в список L2
    pushBack(L2, 'c');
    pushBack(L2, 'f');
    pushBack(L2, 'e');
    pushBack(L2, 'd');
    cout << "Список L1: ";
    printList(L1);
    cout << "Список L2: ";
    printList(L2);
    // Создание списка L, включающего элементы, значения которых входят в список L1 и не входят в список L2
    Node* L = createList(L1, L2);

    // Печать списка L
    cout << "Список L: ";
    printList(L);

    // Удаление подсписка списка L1 заданным диапазоном позиций
    removeSublist(L1, 2, 3);

    // Печать списка L1 после удаления подсписка
    cout << "Список L1 после удаления подсписка со второго элемента трех: ";
    printList(L1);

    // Упорядочивание списка L2, располагая его значения в порядке возрастания
    sortList(L2);

    // Печать списка L2 после сортировки
    cout << "Список L2 после сортировки: ";
    printList(L2);

    // Освобождение памяти, занятой списками
    Node* temp = nullptr;
    while (L1 != nullptr) {
        temp = L1;
        L1 = L1->next;
        delete temp;
    }
    while (L2 != nullptr) {
        temp = L2;
        L2 = L2->next;
        delete temp;
    }
    while (L != nullptr) {
        temp = L;
        L = L->next;
        delete temp;
    }

    return 0;
    }
    if (choose==2){
        int j=0;
        Node* L1 = nullptr;
        cout<<"Введите список L1 на одной строке:"<<endl;
        while(1){


            char item=getchar();
            //cout<<tmp->item;
            if (item=='\n' and j!=0 or item==EOF){
                break;
            }
            pushBack(L1, item);
            j++;
        }
        j=0;
        Node* L2 = nullptr;
        cout<<"Введите список L2 на одной строке:"<<endl;
        while(1){


            char item=getchar();
            //cout<<tmp->item;
            if (item=='\n' and j!=0 or item==EOF){
                break;
            }
            pushBack(L2, item);
            j++;
        }
        while (1){
            cout<<"Выберите действие:\n 1. формирование списка L, включив в него по одному разу элементы, значения которых входят в список L1 и не входят в список L2.\n 2. удалить подсписок списка L1 заданный диапазоном позиций. \n 3. упорядочить значения списка L2, располагая их в порядке возрастания.\n";
            int choose1;
            cin>>choose1;
            if (choose1==1){
                Node* L = createList(L1, L2);
                cout << "Список L: ";
                printList(L);
            }
            else if (choose1==2){
                int From,Count;
                cout<<"Введите через пробел индекс элемента (счет начинается с нуля), с которого удалять, и количество элементов для удаления"<<endl;
                cin>>From;
                cin>>Count;
                removeSublist(L1, From, Count);

                // Печать списка L1 после удаления подсписка
                cout << "Список L1 после удаления подсписка: ";
                printList(L1);
            }
            else if (choose1==3){
                sortList(L2);

                // Печать списка L2 после сортировки
                cout << "Список L2 после сортировки: ";
                printList(L2);
            }

        }

    }

}
