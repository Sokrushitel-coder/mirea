#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX_disease = 1000;
const int MAX_table_length=10;
using namespace std;
typedef struct elem elem;
struct elem {
    int key=0;

    string pers[3];
    int* codes=new int[MAX_disease];
//    for (int i=0;i<MAX_disease;i++){codes[i]=0;}
    string names[MAX_disease];
};
typedef struct tab tab;
struct tab {
    int n;
    elem* items = new elem[MAX_table_length];
    //elem items[n];
};

void cin_elem(elem &item){
     cout<<"Введите номер полиса"<<endl;
     cin>>item.key;
     cout<<"Введите через пробел фамилию, имя, отчество"<<endl;
     for (int i=0;i<3;i++){
        cin>>item.pers[i];
     }

     for (int i=0;i<MAX_disease;i++){
        item.codes[i]=0;
        item.names[i]=" ";
     }

}
void cout_tab(tab a){
    for (int j=0;j<a.n;j++){
        if (a.items[j].key==0){
            break;
        }
        cout<<"Пациент:"<<endl;
        cout<<a.items[j].key<<"\t";
        for (int i=0;i<3;i++){
            cout<<a.items[j].pers[i]<<"\t";

        }

        cout<<endl<<"Список заболеваний:"<<endl;

        for (int e=0;e<MAX_disease;e++){
            if (a.items[j].codes[e]==0){
                break;
            }
            cout<<"\t"<<e+1<<") "<<a.items[j].codes[e]<<" "<<a.items[j].names[e]<<endl;
        }
        cout<<endl;
    }
}


int main(){
    system("chcp 1251");
    int choose1;
    cout<<"Введите режим заполнения таблицы:\n 1 - ручной\n 2 - на готовых тестовых данных"<<endl;
    cin>>choose1;
    tab a;
    //a.n=10;
    if (choose1==2){
        int n=3;
        a.n=n;

        string l[16]={"1","Фамилия1","Имя1","Отчество1","2","Фамилия2","Имя2","Отчество2","3","Фамилия3","Имя3","Отчество3"};
        for (int j=0;j<3;j++){
        a.items[j].key=stoi(l[j*4]);
        for (int i=0;i<MAX_disease;i++){
        a.items[j].codes[i]=0;
        a.items[j].names[i]=" ";
        }
        for (int i=0;i<3;i++){

            a.items[j].pers[i]=l[i+j*4+1];

            //cout<<l[i+j*4]<<endl;

        }
        }
        a.items[0].codes[0]=1;
        a.items[0].names[0]="12:12:2012";
        a.items[1].codes[0]=1;
        a.items[1].names[0]="21:12:2012";
        a.items[2].codes[0]=3;
        a.items[2].names[0]="21:12:2022";

        cout<<"Исходная таблица: "<<endl;
        cout_tab(a);

    }
    else{
        cout<<"Введите максимальную размерность таблицы"<<endl;
        int n;
        cin>>n;

        a.n=n;

    }

    //for (int i=0;i<a.n;i++){
        //a.items[i].key=0;
    //    cout<<a.items[i].key<<" ";
    //}
    //cout_tab(a);
    while (1){
        cout<<"\nВведите номер операции:\n 1 - Заполнить запись по пациенту с клавиатуры, не заполняя список заболеваний.\n 2 - Добавить запись о пациенте в таблицу.\n 3 - Вставить новую запись по заболеванию в начало списка заболеваний заданного пациента.\n 4 - Сформировать список пациентов, которым поставлен диагноз с заданным кодом заболевания.\n";
        int choose;

        cin>>choose;
        switch (choose){
            case (1): {
                elem it;
                cin_elem(it);
                for (int i=0;i<a.n;i++){
                    if (a.items[i].key==it.key){
                        cout<<"Пациент уже добавлен ранее."<<endl;
                        break;
                    }
                    if (a.items[i].key==0){
                        a.items[i]=it;
                        cout<<"Запись успешно добавлена."<<endl;
                        break;
                    }
                    if (i==a.n-1){
                        cout<<"Ошибка: таблица полностью заполнена."<<endl;
                    }
                }
                //cout_tab(a);
                break;
            }
            case (2): {
                elem item;
                cin_elem(item);
                cout<<"Введите количество заболеваний для добавления в список."<<endl;
                int count_disease;
                cin>>count_disease;
                cout<<"Вводите через пробел на каждой новой строке код заболевания и дату установления заболевания."<<endl;
                for (int i=0;i<count_disease;i++){
                    int code;
                    string date;
                    cin>>code;
                    cin>>date;
                    item.codes[i]=code;
                    item.names[i]=date;
                }
                for (int i=0;i<a.n;i++){
                    if (a.items[i].key==item.key){
                        cout<<"Пациент уже добавлен ранее."<<endl;
                        break;
                    }
                    if (a.items[i].key==0){
                        a.items[i]=item;
                        cout<<"Запись успешно добавлена."<<endl;
                        break;
                    }
                    if (i==a.n-1){
                        cout<<"Ошибка: таблица полностью заполнена."<<endl;
                    }
                }
                break;
            }
            case (3):{
                int num;
                cout<<"Введите номер полиса"<<endl;
                cin>>num;
                cout<<"Введите через пробел код заболевания и дату установки диагноза"<<endl;
                int code;
                string s;
                cin >> code;
                cin>>s;
                for (int i=0;i<a.n;i++){
                    if (a.items[i].key==num){
                        for (int j=0;j<MAX_disease;j++){
                            if (a.items[i].codes[j]==0){
                                a.items[i].codes[j]=code;
                                a.items[i].names[j]=s;
                                cout<<"Заболевание успешно добавлено."<<endl;
                                break;
                                //cout<<a.items[i].codes[j]<<" "<<a.items[i].names[j];
                            }
                        }
                        break;
                    }
                    if (i==a.n-1){
                        cout<<"Ошибка: полис не найден."<<endl;
                    }
                }
                //cout_tab(a);
                break;
            }
            case (4):{
                cout<<"Введите код заболевания"<<endl;
                int code;
                cin>>code;
                cout<<"Список пациентов с заданным кодом заболевания:"<<endl;
                for (int i=0;i<a.n;i++){
                    for (int j=0;j<MAX_disease;j++){
                        if (a.items[i].codes[j]==code){
                            cout<<"\t"<<a.items[i].key<<"\t";
                            for (int e=0;e<3;e++){
                                cout<<a.items[i].pers[e]<<"\t";
                            }
                            cout<<endl;
                        }
                    }
                }
                break;
            }

        }
    }

}
