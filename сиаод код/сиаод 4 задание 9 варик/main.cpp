#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef struct elem elem;
struct elem {
    int key;
    string value[4];
};
typedef struct tab tab;
struct tab {
    int n;
    //int count;
    elem* items = new elem[n];
    //for (int i=0; i < n; i++){
   //     items[i] = new elem;
    //}

};

elem cin_elem(elem item){
     cout<<"Введите номер поезда"<<endl;

     cin>>item.key;
     cout<<"Введите через пробел номер вагона, номер места, дату отправления и стоимость билета"<<endl;
     for (int i=0;i<4;i++){
        cin>>item.value[i];
     }
     return item;
}
void cout_tab(tab a){
    for (int j=0;j<a.n;j++){
        cout<<a.items[j].key<<"\t";
        for (int i=0;i<4;i++){
            cout<<a.items[j].value[i]<<"\t";
        }

        cout<<endl;
    }
}
void count_ticket(int num,string date,tab a){
    int c=0;
    for (int i=0;i<a.n;i++){
        if (a.items[i].key==num and a.items[i].value[2]==date){
            c++;
        }
    }
    cout<<c<<endl;
}
void cout_all_counts(int num,tab &a){
    string vagon[a.n];
    int counts[a.n];
    for (int i=0;i<a.n;i++){
        counts[i]=0;
    }
    for (int i=0;i<a.n;i++){
        if (a.items[i].key==num){
            for (int j=0;j<a.n;j++){
                if (counts[j]==0 or vagon[j]==a.items[i].value[0]){
                    vagon[j]=a.items[i].value[0];
                    counts[j]++;
                    break;
                }
            }
        }
    }
    for (int i=0;i<a.n;i++){
        if (counts[i]!=0 and vagon[i]!=""){
            cout<<"В вагоне "<<vagon[i]<<" продано "<<counts[i]<<" билетов."<<endl;
        }
        else{
            break;
        }
    }

}
void delete_ticket(int num, string s[4],tab &a){
    int t=0;
    for (int i=0;i<a.n;i++){
        if (a.items[i].key==num){
            int b=0;
            for (int j=0;j<4;j++){
                if (a.items[i].value[j]!=s[j]){
                    b=1;
                    break;
                }
            }
            if (b==0){
                a.items[i].key=0;
                cout<<"Запись успешно удалена"<<endl;
                t=1;
            }
        }
    }
    if (t==0){
        cout<<"Запись не найдена"<<endl;
    }
}
int main(){
    system("chcp 1251");
    int choose1;
    cout<<"Введите режим заполнения таблицы:\n 1 - ручной\n 2 - на готовых тестовых данных"<<endl;
    cin>>choose1;
    tab a;
    if (choose1==2){
        int n=4;
        a.n=n;

        string l[16]={"1","1","12:30","400","1","2","12:30","500","1","2","13:30","500","2","1","12:30","700"};
        for (int j=0;j<4;j++){
        a.items[j].key=1;
        for (int i=0;i<4;i++){

            a.items[j].value[i]=l[i+j*4];

            //cout<<l[i+j*4]<<endl;

        }
        }
        cout<<"Исходная таблица: "<<endl;
        cout_tab(a);
    }
    else{
        cout<<"Введите максимальную размерность таблицы"<<endl;
        int n;
        cin>>n;

        a.n=n;
        for (int i=0;i<a.n;i++){
            a.items[i].key=0;
        }
    }

    //cout_tab(a);
    while (1){
        cout<<"\nВведите номер операции:\n 1 - Добавить запись о продаже билета в таблицу.\n 2 - Определить количество билетов, проданных на поезд заданного номера и дате отправления.\n 3 - Удалить запись из таблицы по проданному билету.\n 4 - Вывести сведения о количестве проданных билетов в каждый вагон поезда."<<endl;
        int choose;
        cin>>choose;
        switch (choose){
            case (1): {
                elem item;
                item=cin_elem(item);
                for (int i=0;i<a.n;i++){
                    if (a.items[i].key==0){
                        a.items[i]=item;
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
                int num;
                string date;
                cout<<"Введите через пробел номер поезда и дату отправления"<<endl;
                cin>>num;
                cin>>date;

                int c=0;
                for (int i=0;i<a.n;i++){
                    if (a.items[i].key==num and a.items[i].value[2]==date){
                        c++;
                    }
                }
                cout<<"Количество билетов, проданных на этот поезд: "<<c<<endl;
                break;
            }
            case (3):{
                cout<<"Введите через пробел номер поезда, номер вагона, номер места, дату отправления и стоимость билета"<<endl;
                int num;
                string s[4];
                cin >> num;
                for (int i=0;i<4;i++){
                    cin>>s[i];
                }
                delete_ticket(num, s,a);
                //cout_tab(a);
                break;
            }
            case (4):{
                cout<<"Введите номер поезда"<<endl;
                int num;
                cin>>num;
                cout_all_counts(num,a);
                break;
            }

        }
    }

}
