#include <iostream>
#include <vector>

using namespace std;

struct Student {
  int key;
  int variant;
};

const int TABLE_SIZE = 23;

int hashFunction(int key, int size) {
  return key % TABLE_SIZE;
}

bool isPrime(int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) return false;
  }
  return true;
}
int nextPrime(int n) {
  if (n <= 1) return 2;
  int prime = n;
  bool found = false;
  while (!found) {
    prime++;
    if (isPrime(prime)) found = true;
  }
  return prime;
}

void insert(vector<Student>& table, int key, int variant) {
  int index = hashFunction(key, table.size());

  // коллизии
  while (table[index].key != -1 && table[index].key != key) {
    index = (index + 1) % TABLE_SIZE;
  }

  table[index].key = key;
  table[index].variant = variant;
}

void displayTable(const vector<Student>& table) {
  cout << "Ключ\tВариант\tКоллизия" << endl;
  for (int i = 0; i < TABLE_SIZE; ++i) {
    cout << table[i].key << "\t" << table[i].variant << "\t";
    if (table[i].key == -1 || i == hashFunction(table[i].key, TABLE_SIZE)) {
      cout << "Нет";
    }
    else {
      cout << "Да";
    }
    cout << endl;
  }
}

void displayComparisonOperations(const vector<int>& operations) {
  cout << "Ключ\tОперации Сравнения" << endl;
  for (int i = 0; i < operations.size(); ++i) {
    cout << i + 1 << "\t" << operations[i] << endl;
  }
}

void rehash(vector<Student>& oldHashTable, int oldSize) {
  int newSize = nextPrime(oldSize * 2);
  vector<Student> newHashTable(newSize, { -1, -1 });
  for (int i = 0; i < oldSize; ++i) {
    if (oldHashTable[i].key != -1) {
      int index = hashFunction(oldHashTable[i].key, newSize);
      while (newHashTable[index].key != -1) {
        index = (index + 1) % newSize;
      }
      newHashTable[index] = oldHashTable[i];
    }
  }
  oldHashTable = newHashTable;
  oldSize = newSize;
}

int main() {
  setlocale(0, "");
  vector<Student> hashTable(TABLE_SIZE, { -1, -1 });

  insert(hashTable, 11, 1);
  insert(hashTable, 15, 2);
  insert(hashTable, 17, 3);
  insert(hashTable, 3, 4);
  insert(hashTable, 7, 5);
  insert(hashTable, 44, 6);
  insert(hashTable, 55, 7);
  insert(hashTable, 33, 8);
  insert(hashTable, 34, 9);
  insert(hashTable, 12, 10);
  // 4 задание:
  insert(hashTable, 30, 11); // коллизия
  insert(hashTable, 36, 13); // коллизия
  insert(hashTable, 50, 23); // открытый адрес
  // ключи для rehash();
  insert(hashTable, 25, 14);
  insert(hashTable, 38, 15);
  insert(hashTable, 42, 16);


  displayTable(hashTable);


  cout << endl;
  vector<int> comparisonOperations(TABLE_SIZE, 0);
  for (int i = 0; i < TABLE_SIZE; ++i) {
    if (hashTable[i].key != -1) {
      int index = hashFunction(hashTable[i].key, TABLE_SIZE);
      int count = 0;
      while (hashTable[index].key != -1 && hashTable[index].key != hashTable[i].key) {
        index = (index + 1) % TABLE_SIZE;
        ++count;
      }
      comparisonOperations[i] = count + 1;
    }
  }
  displayComparisonOperations(comparisonOperations);

  cout << "\nРехеширование:\n" << endl;
  rehash(hashTable, TABLE_SIZE);
  displayTable(hashTable);

  cout << endl;
  displayComparisonOperations(comparisonOperations);

  cout << endl;
  int keyToSearch = 80;
  int comparisons = 0;
  int index = hashFunction(keyToSearch, TABLE_SIZE);
  while (hashTable[index].key != -1 && hashTable[index].key != keyToSearch) {
    index = (index + 1) % TABLE_SIZE;
    comparisons++;
  }

  if (hashTable[index].key == keyToSearch) {
    cout << "Ключ найден. Количество сравнений: " << comparisons << endl;
  }
  else {
    cout << "Ключ не найден. Количество сравнений: " << comparisons << endl;
  }
  cout << "Поиск завершился на элементе хеш-таблицы с индексом: " << index << endl;

  return 0;
}
