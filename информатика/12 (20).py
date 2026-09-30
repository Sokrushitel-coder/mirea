from random import randint
from keyboard import block_key
block_key('ctrl')
block_key('alt')
def rand_arr():
    deck = []
    for row in range(6):
        in_deck = []
        for column in range(6):
            in_deck.append(randint(0, 100))
        deck.append(in_deck)
    return deck
def print_matx(arr,M):
    for row in range(M):
        for column in range(M):
            print(arr[row][column], end=" ")
        print()
def add_arr(deck, index):
    arr = []
    for x in range(index - 1, 64, 2):
        arr.append(deck[x // 8][x % 8])
    return arr




print("Выберите способ заполнения матрицы: вручную или случайными числами (0/1)")
while 1:
    a=input()
    if a=="1":
        arr=rand_arr()
    elif a=="0":
        print("Введите элементы матрицы по 6 чисел через пробел в строке")
        arr=[[0]*6 for i in range(6)]
        
        i=0
        while i<6:
            a=input().split()
            
            if len(a)!=6:
                print("Ошибка ввода, введите эту строку еще раз")
                continue
            c=0
            for j in a:
                try:
                    if not 0<=int(j)<=100:
                        c=1
                        break
                except:
                    c=1
                    break
            if c==1:
                print("Ошибка ввода, введите эту строку еще раз")
                continue
            for j in range(6):
                arr[i][j]=int(a[j])
            i+=1
    else:
        print("Ошибка ввода, введите 0 или 1")
        continue
    break    
print("Исходная матрица:")
print_matx(arr,6)

new_arr=[[0]*6 for i in range(3)]
for i in range(3):
    for j in range(6):
        try:
            new_arr[i][j]=arr[i*2+1][j]/arr[i*2][j]
        except:
            print("Ошибка, деление на ноль попробуйте еще раз")
new_new_arr=[[0]*3 for i in range(3)]
for i in range(3):
    for j in range(3):
        try:
            new_new_arr[i][j]=new_arr[i][j*2+1]/new_arr[i][j*2]
        except:
            print("Ошибка, деление на ноль попробуйте еще раз")
for j in range(3):
    for e in range(3):
        for u in range(2):
            if new_new_arr[u][j]>new_new_arr[u+1][j]:
                new_new_arr[u][j],new_new_arr[u+1][j]=new_new_arr[u+1][j],new_new_arr[u][j]
print("Конечный массив:")
print_matx(new_new_arr,3)
