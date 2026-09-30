#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<cmath>
#include <time.h>

using namespace std;
void poiskF(long long int p)
{
    clock_t start = clock();
    ifstream fileStrmpoisk("fbin.txt", ios::binary);

    // Find the size of the binary file
    fileStrmpoisk.seekg(0, ios::end);
    int fileSize = fileStrmpoisk.tellg();
    fileStrmpoisk.seekg(0, ios::beg);

    int fibM_minus_2 = 0;
    int fibM_minus_1 = 1;
    int fibM = fibM_minus_1 + fibM_minus_2;

    while (fibM < fileSize / (sizeof(long long int) + sizeof(string)))
    {
        fibM_minus_2 = fibM_minus_1;
        fibM_minus_1 = fibM;
        fibM = fibM_minus_1 + fibM_minus_2;
    }

    long long int a_;
    string name_;
    int f = 0;

    while (fibM > 0)
    {
        int pos = min((unsigned long long )fibM_minus_2, fileSize / (sizeof(long long int) + sizeof(string)) - 1);
        fileStrmpoisk.seekg(pos * (sizeof(long long int) + sizeof(string)), ios::beg);

        fileStrmpoisk.read((char *)&a_, sizeof(long long int));
        fileStrmpoisk.read((char *)&name_, sizeof(name_));

        if (a_ == p)
        {
            cout << "<Участок был найден>" << endl;
            cout << "Участок: " << name_ << endl;
            f = 1;
            break;
        }
        else if (a_ < p)
        {
            fibM = fibM_minus_1;
            fibM_minus_1 = fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        }
        else
        {
            fibM = fibM_minus_2;
            fibM_minus_1 = fibM_minus_1 - fibM_minus_2;
            fibM_minus_2 = fibM - fibM_minus_1;
        }
    }

    if (f == 0)
    {
        cout << "<Участок не найден>" << endl;
    }
    clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Поиск Фибоначчи работал: %f секунд\n", elapsed_time);
}
void poisk(long long int p)
{
    clock_t start = clock();
	fstream fileStrmpoisk("fbin.txt", ios::binary | ios::in | ios::out);
	long long int a_;
	fileStrmpoisk.seekg(0, fileStrmpoisk.beg);
	fileStrmpoisk.tellg();
	string name_;
	int f = 0;
	while (fileStrmpoisk.read((char*)&a_, sizeof(long long int)) &&
		fileStrmpoisk.read((char*)&name_, sizeof(name_)))
	{
		if (a_ == p)
		{
			cout << "<Участок был найден>" << endl;
			cout << "Участок: " << name_ << endl;
			f = 1;
			break;
		}
	}
	if (f == 0)
	{
		cout << "<Участок не найден>" << endl;
	}
	clock_t end = clock();

    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Поиск линейный работал: %f секунд\n", elapsed_time);

    //fileStrmpoisk.close();
}

long long int generator()
{
	int n;
	long long int r = 0;
	for (int i = 0; i < 7; i++)
	{
		n = rand() % 10;
		r = r + n * pow(10, i);
	}
	if (r<1000000)
		r = generator();
	return r;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
	long long int a;
	string name;
	setlocale(LC_ALL, "rus");
	ofstream fileStrmOut("fbin.txt", ios::binary);
	cout << "Ведите количество строк : " << endl;
	int size;
	cin >> size;
		for (int i = 0; i < size; ++i) {
			a = generator();
			fileStrmOut.write((char*)&a, sizeof(long long int));
			//cout << "Введите название страховой организации организации : " << endl;
			 name="Text"+to_string(i-1000);
			 //cout << name<<endl;
			int howManyBytes = name.size() * sizeof(char);
			//cout << howManyBytes << " \n";
			fileStrmOut.write((char*)&name, sizeof(name));
		}
	fileStrmOut.close();
	ifstream fileStrmIn("fbin.txt", ios::binary);
	while (fileStrmIn.read((char*)&a, sizeof(long long int)) && fileStrmIn.read((char*)&name, sizeof(name)) )
	{
		cout << "Регистрация земельного участка в СНТ: ";
		cout <<"кадастровый номер: "<< a << ' ';
		cout <<"адрес СНТ: "<< name << endl;
	}
	cout << "Введите искомое значение : ";
	fileStrmIn.close();
	long long int p;

	cin >> p;
	int rrr;

	cout<<"Выберите тип поиска (1-линейный, 2-фибоначчи)"<<endl;
	cin>>rrr;
	if (rrr==1){
        poisk(p);
	}
	else poiskF(p);

	return 0;
}
