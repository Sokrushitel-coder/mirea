import random
import keyboard
keyboard.block_key('ctrl')
keyboard.block_key('alt')
q='0123456789ABCDEF'
def print_matrix(l,M):
    for row in range(M):
        for column in range(M):
            print(q[l[row][column]//16]+q[l[row][column]%16], end=" ")
        print()
l=[[0]*4 for i in range(4)]

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
    print("Введите все двузначные шестнадцатеричные числа, по 4 числа в строке через пробел, используя цифры и латинские буквы")
    i=0
    while i<4:
        a=input().split()
        if len(a)!=4:
            print("Ошибка ввода, попробуйте ввести эту строку еще раз.")
            #i-=1
            continue
        c=0
        for j in a:
            try:

                if not 15<int(j,16)<256:        
                    c=1
                    break
                    
            except:
                c=1
        if c==1:
            print("Ошибка ввода, попробуйте ввести эту строку еще раз.")
            continue
        for j in range(4):
            l[i][j]=int(a[j],16)
        i+=1
else:
    for i in range(4):
        for j in range(4):
            l[i][j]=random.randint(16,255)
print("Исходная матрица:")
print_matrix(l,4)
l2=[]
for i in range(4):
    l2+=l[i]

for i in range(16):
    for j in range(15):
        if l2[j]<l2[j+1]:
            l2[j],l2[j+1]=l2[j+1],l2[j]



for i in range(4):
    for j in range(4):
        if j<2:
            l[i][j]=l2.pop()
        else:
            l[i][j]=l2.pop(0)

print("Преобразованная матрица:")
print_matrix(l,4)
