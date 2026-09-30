from random import randint
import keyboard
keyboard.block_key('ctrl')
keyboard.block_key('alt')
def print_matrix(l,M):
    for row in range(M):
        for column in range(M):
            print(l[row][column], end=" ")
        print()
while 1:
    print("Введите размер матрицы M в диапазоне [2,5]")
    try:
        M=input()
        if len(M)!=1:
            print("Ошибка ввода, попробуйте еще раз.")
            continue

        M=int(M)
        if not (2<=M<=5):
            print("Ошибка ввода, попробуйте еще раз.")
            continue
    except:
        print("Ошибка ввода, попробуйте еще раз.")
        continue
    break

l=[['']*M for i in range(M)]


while 1:
    print("Заполнить матрицу вручную или случайными числами? (0/1)")
    try:
        in_or_rand=input()
        
        if in_or_rand!="0" and in_or_rand!="1" :
            print("Ошибка ввода, попробуйте еще раз.")
            continue
    except:
        print("Ошибка ввода, попробуйте еще раз.")
        continue
    break

if in_or_rand == "0":
    print("Введите все целые числа из диапазона [1, 100], по М чисел в строке через пробел")
    i=0
    while i<M:
        a=input().split()
        if len(a)!=M:
            print("Ошибка ввода, попробуйте ввести эту строку еще раз.")
            #i-=1
            continue
        c=0
        for j in a:
            try:

                if not 0<int(j)<101:
                    c=1
                    break
                    
            except:
                c=1
        if c==1:
            print("Ошибка ввода, попробуйте ввести эту строку еще раз.")
            continue
        for j in range(M):
            
            
            l[i][j]=a[j]
        
        i+=1
else:           
    for i in range(M):
        for j in range(M):
            l[i][j]=randint(1,100)
l1=sorted([l[i][-i-1] for i in range(M)])[::-1]

for i in range(M):
    l[i][-i-1]=l1[i]


print("Преобразованная матрица:")
print_matrix(l,M)

while 1:
    print("Введите номер минимума в побочной диагонали, который необходимо вывести")
    try:
        N=input()
        if len(N)!=1:
            
            print("Ошибка ввода, попробуйте еще раз.")
            continue

        N=int(N)
        if not (1<=N<=M):
            print("Ошибка ввода, попробуйте еще раз.")
            continue
    except:
        print("Ошибка ввода, попробуйте еще раз.")
        continue
    break
print(l1[-N])









   


