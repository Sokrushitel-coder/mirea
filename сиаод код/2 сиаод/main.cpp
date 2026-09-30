#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Структура записи в бинарном файле
struct Record {
    int key;
    char field1[31]; // 30 символов + завершающий нуль
    char field2[51]; // 50 символов + завершающий нуль
};
bool createBinaryFile(const string& textFileName, const string& binaryFileName) {
    ifstream textFile(textFileName);
    if (!textFile) {
        cerr << "Error: Unable to open text file" << endl;
        return false;
    }

    ofstream binaryFile(binaryFileName, ios::binary);
    if (!binaryFile) {
        cerr << "Error: Unable to create binary file" << endl;
        return false;
    }

    Record record;
    while (textFile >> record.key >> ws) { // Пропускаем пробельные символы
        textFile.getline(record.field1, 31);
        textFile.getline(record.field2, 51);
        binaryFile.write(reinterpret_cast<const char*>(&record), sizeof(Record));
    }

    return true;
}
// Функция замены значения первой записи на значение записи под заданным номером
bool replaceFirstRecord(const string& binaryFileName, int index) {
    fstream binaryFile(binaryFileName, ios::in | ios::out | ios::binary);
    if (!binaryFile) {
        cerr << "Error: Unable to open binary file" << endl;
        return false;
    }

    Record firstRecord;
    binaryFile.seekp(index * sizeof(Record));
    binaryFile.read(reinterpret_cast<char*>(&firstRecord), sizeof(Record));
    binaryFile.seekp(1);


    binaryFile.write(reinterpret_cast<const char*>(&firstRecord), sizeof(Record));

    cout << "First record replaced with record #" << index << endl;
    cout << "" << endl;
    return true;
}

int main() {
    const string textFileName = "data.txt";
    const string binaryFileName = "data.bin";

    createBinaryFile(textFileName, binaryFileName);
    const int replaceIndex = 3;

    // Заменить значение первой записи на значение записи под заданным номером
    replaceFirstRecord(binaryFileName, replaceIndex);

    return 0;
}
