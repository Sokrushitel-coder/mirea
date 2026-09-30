#include <iostream>
#include <bitset>
using namespace std;

void bin(unsigned int x){
    for (int i=31; i>=0; i--){
        unsigned int mask = 1<<i;
        cout << ((x&mask)>>i);
    }
    cout << '\n';
}

void task1(){
    unsigned int a = 0x9B3E6726;
    bin(a);
    a = a|(1<<7)|(1<<9)|(1<<11);
    bin(a);
}

void task2(unsigned int a){
    cout << "a = " << a << '\n';
    bin(a);
    int n = 32;
    unsigned int x = 0b01010101010101010101010101010101;
    a = a&x;
    bin(a);
}
void task3(unsigned int a){
    cout << "a = " << a << '\n';
    bin(a);
    a = a<<7;
    cout << "a = " << a << '\n';
    bin(a);
}
void task4(unsigned int a){
    cout << "a = " << a << '\n';
    bin(a);
    a = a>>7;
    cout << "a = " << a << '\n';
    bin(a);
}
void task5(unsigned int a, int n){
    cout << "a = " << a << ", n = " << n << '\n';
    bin(a);
    unsigned int mask = 1<<0;
    //bin(mask);
    a = a&(~(mask<<n));
    cout << "a = " << a << ", n = " << n << '\n';
    bin(a);
}

#include <algorithm>
#include <vector>
void solve(int n){
    cout << "n = " << n << '\n';
    char a[(10000000+7)/8];
    for (int i=0; i<(10000000+7)/8; i++){
        a[i] = 0;
    }
    for (int i=0; i<n; i++){
        int x;
        //cin >> x;

        int maxx=10000000;
        int minn=1000000;
        x = abs(minn+minn*rand())%(maxx-minn+1); //- для тестирования при больших n
        //cout<<x<<endl;
        a[x/8] = a[x/8]|(1<<(x%8));
    }
    cout << '\n';
    for (int i=0; i<(10000000+7)/8; i++){
        for (int j=0; j<8; j++){
            if (a[i]&(1<<j)){
                cout << i*8+j<< " ";
                1;
            }
        }
    }

}

void task6(unsigned int x, unsigned int y, int n, int p){
    int mask = (~0)^(~0<<n);
    cout << "x = ";
    bin(x);
    cout << "y = ";
    bin(y);
    x = (x&(~(mask<<p)))|((y&mask)<<p);
    cout << "new x = ";
    bin(x);
}


int main() {
    setlocale(LC_ALL, "rus");
    const int numNumbers = 10; // 10*7 семизначных чисел
    vector<bitset<28>> data;
    cout << "Введите " << numNumbers << " семизначных чисел:" << endl;
    for (int i = 0; i < numNumbers; ++i) {
        int num;
        cin >> num;
        if (num >= 1000000 && num <= 9999999) {
            bitset<28> bits(num);
            data.push_back(bits);
        }
        else{
            cout << "Некорректное число: "<< num << " Пожалуйста, введите семизначное число." << endl;
            --i; // Повтор ввода
        }
    }
    // Сортировка данных с использованием явного компаратора
    sort(data.begin(), data.end(), compareBitsets);
    // Вывод отсортированных данных
    cout << "Отсортированные числа:" << endl;
    for (const auto& bits : data) {
        int num = static_cast<int>(bits.to_ulong());
        cout << num << endl;
    }
    return 0;
}

void main1(){
    //task5(1024,10);
    solve(10);
    task5(1234,10);
    //task6(0b1110000, 0b101, 3, 4);
}
