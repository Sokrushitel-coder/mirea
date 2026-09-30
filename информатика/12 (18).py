from random import randint
import keyboard
keyboard.block_key('ctrl')
keyboard.block_key('alt')
def print_matrix(arr,M):
    for row in range(M):
        for column in range(M):
            print(arr[row][column], end=" ")
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
q='qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM'
Q='QWRTPSDFGHJKLZXCVBNM'

while 1:
    print("Заполнить матрицу вручную или случайными словами? (0/1)")
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
    print("Введите все слова из 5 букв, по М слов в строке через пробел")
    i=0
    while i<M:
        a=input().split()
        if len(a)!=M:
            print("Ошибка ввода, попробуйте ввести эту строку еще раз.")
            #i-=1
            continue
        c=0
        for j in a:
            if len(j)!=5:  
                c=1
                break
            for e in range(5):
                if j[e] not in q:
                    c=1
                    break
        if c==1:
            print("Ошибка ввода, попробуйте ввести эту строку еще раз.")
            continue
        for j in range(M):
            
            
            l[i][j]=a[j]
        
        i+=1
else:
    for i in range(M):
        for j in range(M):
            for e in range(5):
                l[i][j]+=q[randint(0,len(q)-1)]



print("Исходная матрица:")
print_matrix(l,M)
for i in range(M):
    for j in range(M):
        a=0
        b=0
        for e in range(5):
            if l[i][j][e].upper() in Q:
                b+=1
            else:
                a+=1
        l[i][j]=int(str(a)+str(b))


for i in range(M):
    for j in range(M):
        for e  in range(M-1):
            if l[i][e]>l[i][e+1]:
                l[i][e],l[i][e+1]=l[i][e+1],l[i][e]
print("Конечная матрица:")
print_matrix(l,M)



