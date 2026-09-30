#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct list{
    char item; //полезна€ информаци€ узла списка
    list *next;//ссылка на следующий элемент списка.
};

void show (list *start){
    cout<<"“екущий вид списка: \n";
    list *p_list; //рабочий указатель
    p_list = start->next;//в начале он ссылаетс€ на второй узел списка.
    while (p_list != NULL){
        cout << p_list->item;//¬ыводим данные
        p_list = p_list->next;//передвигаем указатель на один узел.
    }
    cout<<endl;
}
void Switch(list *start){
    list *p_prev,*p_list,*p_next,*end1,*end15,*end2;
    p_list = start->next;
    p_prev=start;
    if (p_list==NULL){
        return;
    }

    p_next = p_list->next;
    while (p_next != NULL){

        if (p_list->item==' '){
            end1=p_prev;
            end15=p_list;
            end2=p_next;
            //break;
        }
        p_prev=p_prev->next;
        p_list=p_list->next;
        p_next=p_next->next;
    }
    //list *tmp;
    //tmp->item=' ';
    //tmp->next=NULL;
    //p_next=tmp;
    end1->next=NULL;
    p_list->next=end15;
    end15->next=start->next;

    start->next=end2;

}
void DeleteSecond(list *start){
    list *p_list,*p_next,*space1,*space2;
    p_list = start->next;

    if (p_list==NULL){
        return;
    }
    int j=0;
    p_next = p_list->next;
    while (p_next != NULL){

        if (j==0 and p_next->item==' '){
            space1=p_list;
            //space2->item='\n';
            //space2->next=NULL;
            j++;
            //break;
        }
        if (j==1 and p_list->item==' '){
            space2=p_list;
            j++;
        }
        if (j==1){
            p_list=p_next;
        }
        p_list=p_list->next;
        p_next=p_next->next;
    }
    space1->next=space2;

}
void Replace(int k,list *start,list *elem,list *elem_end){
    list *p_list,*p_next,*space1,*space2;
    p_list = start->next;

    if (p_list==NULL){
        return;
    }
    int j=0;
    p_next = p_list->next;
    //space2->item=NULL;
    while (p_next != NULL){
        if (p_next->item==' ' and k==1){

            elem_end->next=p_next;
            start->next=elem;

            //p_list->next=elem_end;
            return;
        }

        if (j==k-2 and p_next->item==' '){
            space1=p_list;
            //space2=NULL;
            j++;
            //break;
        }
        if (j==k-1 and p_list->item==' '){
            space2=p_list;
            elem_end->next=space2;
            break;
            j++;
        }
        if (j==k-1){p_list=p_next;}
        if (j<k-2 and p_next->item==' '){
            j++;
        }

        p_list=p_list->next;
        p_next=p_next->next;
    }
    list *tmp = new list;
    tmp->item=' ';
    tmp->next=elem;
    //if (space2->item)


    space1->next=tmp;

}
int main(){
    system("chcp 1251");
    cout<<"123213123"<<endl;
    list *start = new list; //выдел€ем пам€ть дл€ первого элемента
    start->next = NULL; // на данный момент первый элемент одновременно €вл€етс€ и последним том next ссылаетс€ на NULL
    list *p_list = start;
    cout<<"¬ведите слова, разделенные пробелами"<<endl;
    int j=0;

    while(1){

        list *tmp = new list;

        tmp->item=getchar();
        //cout<<tmp->item;
        if (tmp->item=='\n' and j!=0 or tmp->item==EOF){
            break;
        }
        //tmp->item = i; // здесь все пон€тно
        tmp->next = NULL; //мы вставл€ем узел в конец списка и поэтому next = NULL
        p_list->next = tmp; //теперь p_list-> next указывает на созданный узел
        p_list = p_list->next;// ѕередвигаем указатель на последний элемент.
        j++;
    }

    show(start);
    while (1){
        cout<<"¬ыберите действие:\n 1 - Ќайти последнее слово и переставить его в начало списка.\n 2 - ”далить второе слово.\n 3 - «аменить k-ое слово на новое слово. ƒлина нового слова может быть больше длины k-ого слова."<<endl;
        int c;
        cin>>c;
        switch (c){
        case (1):{
            Switch(start);
            show(start);
            break;
        }
        case (2):{
            DeleteSecond(start);
            show(start);
            break;
        }
        case (3):{
            list *elem = new list;
            int k;
            cout<<"¬ведите в первой строке слово, во второй - позицию"<<endl;
            int j=0;
            elem->next = NULL; // на данный момент первый элемент одновременно €вл€етс€ и последним том next ссылаетс€ на NULL
            list *p_list = elem;
            list *elem_end;
            while(1){
                list *tmp = new list;
                tmp->item=getchar();
                if (tmp->item=='\n' and j!=0 or tmp->item==EOF){

                    break;
                }
                if (tmp->item=='\n'){
                    continue;
                }
                tmp->next = NULL; //мы вставл€ем узел в конец списка и поэтому next = NULL
                p_list->next = tmp; //теперь p_list-> next указывает на созданный узел
                p_list = p_list->next;// ѕередвигаем указатель на последний элемент.
                elem_end=tmp;
                j++;
            }
            cout<<elem_end->item<<endl;
            show(elem);
            cin>>k;
            //break;
            Replace(k,start,elem,elem_end);
            show(start);

        }
        }


    }

}
