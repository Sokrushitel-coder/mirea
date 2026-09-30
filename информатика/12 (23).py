import keyboard
keyboard.block_key('ctrl')
keyboard.block_key('alt')
keyboard.block_key('tab')
keyboard.block_key('shift')
keyboard.block_key('esc')
keyboard.block_key('win')

import random
global alphabet

def InputCheck(s): # Функция проверяет корректность ввода
    if len(s) == 5  and s[0] in alphabet and s[3] in alphabet and 1 <= int(s[1]) <= 8 and 1 <= int(s[4]) <= 8 and s[2] == "-" :
        if alphabet.find(s[0]) + 1 == int(s[4]) and alphabet.find(s[3]) + 1 == int(s[1]):
            return True
        else:
            print("Неправильно заданы координаты диагонали, повторите попытку")
            return False
    else:
        print("Ошибка ввода, повторите попытку")
        return False


a = [[random.randint(1, 100) for i in range(8)] for j in
     range(8)]  # Создаем массив размером 8х8 и заполняем его случайными числами от 1 до 100
alphabet = "ABCDEFGH"  # Создаем переменную, хранящую в себе все буквенные координаты шахматной доски


print("Введите координаты шахматных клеток (Пример: A5-E1)")
s = input()  # Считываем строку, содержащую координаты диагоналей

while not(InputCheck(s)): #Проверяем корректность ввода
    s = input()

print("Исходная матрица")
for i in a:  # Печатаем исходный массив
    print(*i)
print()
x1 = alphabet.find(s[0]) + 1  # Вычленяем из введенной строки координаты и присваиваем их значения новым переменным
y1 = int(s[1])
x2 = alphabet.find(s[3]) + 1
y2 = int(s[4])
x = x1  # Создаем переменные для цикла
y = y1
new = []  # Создаем массив, для сохранения значений на диагонале


while y >= y2 and x <= x2:  # Пока не конец диагонали, добавляем значение в массив
    new.append(a[8 - y][x - 1])
    x += 1
    y -= 1
for i in range(len(new) - 1): # Сортировка полученного массива методом пузырька
    for j in range(len(new) - i - 1):
        if new[j] > new[j + 1]:
            new[j],new[j + 1] = new[j + 1], new[j]
print("Отсортированный список элементов с диагонали") # Вывод отсортированного списка элементов с введенной диагонали
for i in new:
    print(i, end=" ")
print()
print()
for i in range(8):  # Обнуляем все элементы исходного массива
    for j in range(8):
            a[i][j] = 0
x = x1  # Обновляем значение переменных для цикла
y = y1
c = 0 #Счетчик для массива new
while y >= y2 and x <= x2:  # Пока не конец диагонали, присваваем элементу исходного массива значение элемента отсортированного массива
        a[8 - y][x - 1] = new[c]
        x += 1
        y -= 1
        c += 1
print("Конечная матрица")
for i in a:  # Печатаем полученный массив
    print(*i)


