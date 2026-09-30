#include <iostream>
#include <stdio.h>
using namespace std;

struct list{
    int item; //полезна€ информаци€ узла списка
    list *next;//ссылка на следующий элемент списка.
};

//“еперь нам нужно создать переменную start типа list, котора€ будет указывать на первый элемент
//списка.



void show (list *start){

    cout<<"“екущий вид списка: \n";
    list *p_list; //рабочий указатель
    p_list = start->next;//в начале он ссылаетс€ на второй узел списка.
    while (p_list != NULL){
        cout << p_list->item << " ";//¬ыводим данные
        p_list = p_list->next;//передвигаем указатель на один узел.
    }
    cout<<endl;
}
void Insert(list *elem,list *start){
    list *p_list,*p_next;
    p_list = start->next;
    if (p_list==NULL){
        p_list=elem;
        start->next=p_list;
        return;
    }
    p_next = p_list->next;
    while (p_list != NULL){

        if (p_list->item>elem->item){

            elem->next=p_list;
            start->next=elem;
            break;
        }
        if (p_next==NULL){
            p_next=elem;
            p_list->next=elem;
            break;
        }
        if (p_next->item>elem->item){
            p_list->next=elem;
            elem->next=p_next;
            break;
        }
        p_list=p_list->next;
        p_next=p_next->next;
    }
}
void Delete(int i,list *start){
    list *p_list,*p_next;
    p_list = start->next;
    p_next = p_list->next;
    while(p_next!=NULL){
        if (p_list->item>i){
            start->next=NULL;
            break;
        }
        if (p_next->item>i){
            p_list->next=NULL;
            break;
        }
        p_list=p_list->next;
        p_next=p_next->next;
    }
}
list* reversed(list *start){
    list *start1 = new list; //выдел€ем пам€ть дл€ первого элемента
    start1->next = NULL; // на данный момент первый элемент одновременно €вл€етс€ и последним том next ссылаетс€ на NULL
    list *p1_list = start1;
    list *p_list,*p_next;
    int i=10000;
    //p1_list=start1->next;
    while (p_list!=start->next){
        p_list = start->next;
        p_next = p_list->next;
        int j=0;
        while (p_next != NULL and j<i-1){

            p_list=p_list->next;
            p_next=p_next->next;
            j++;
        }

        list *tmp = new list;
        tmp->item=p_list->item;
        tmp->next=NULL;
        //cout<<tmp->item;
        p1_list->next=tmp;

        p1_list=p1_list->next;
        i=j;
    }
    return start1;
    //show(start1);
}
int main(){
    system("chcp 1251");
    list *start = new list; //выдел€ем пам€ть дл€ первого элемента
    start->next = NULL; // на данный момент первый элемент одновременно €вл€етс€ и последним том next ссылаетс€ на NULL
    list *p_list = start;
    for (int i=0; i<4; i+=2){
        list *tmp = new list;
        tmp->item = i; // здесь все пон€тно
        tmp->next = NULL; //мы вставл€ем узел в конец списка и поэтому next = NULL
        p_list->next = tmp; //теперь p_list-> next указывает на созданный узел
        p_list = p_list->next;// ѕередвигаем указатель на последний элемент.
    }

    show(start);
    while (1){
        cout<<"¬ыберите действие:\n 1 - ¬ставить новое значение в список L, сохран€€ упор€доченность списка.\n 2 - ”далить из списка L все узлы, значени€ в которых большие заданного.\n 3 - Cоздать новый список L2 из значений узлов списка L, так что в списке L2 узлы упор€дочены в пор€дке убывани€ их значений."<<endl;
        int c;
        cin>>c;
        switch (c){
        case (1):{
            list *elem = new list;
            elem->next=NULL;
            cout<<"¬ведите новое значение:"<<endl;
            int z;
            cin>>z;
            elem->item=z;
            Insert(elem,start);
            show(start);
            break;
        }
        case (2):{
            cout<<"¬ведите значение:"<<endl;
            int z;
            cin>>z;
            Delete(z,start);
            show(start);
            break;
        }
        case (3):{
            list *L2;
            L2=reversed(start);
            cout<<"—писок L1:"<<endl;
            show(start);
            cout<<"—писок L2:"<<endl;
            show(L2);

        }
        }


    }

}
