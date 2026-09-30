import random
import keyboard
keyboard.block_key('ctrl')
keyboard.block_key('alt')
def Vvod():
	try:
		m = int(input())
		return m
	except:
		return -1
def Proverka(m):
	if m < 0:
		print("Вы ввели не целое число!")
		return False
	if m % 2 == 1:
		print("Вы ввели нечетное число! Введите четное!")
		print()
		return False
	if m < 2 or m > 8:
		print("Вы ввели число которое находится не в диапазоне[2;8]")
		print()
		return False
	return True
def Proverka2(m):
	if m < 0:
		print("Вы ввели не целое число!")
		print()
		return False		
	if m != 1 and m != 2:
		print("Вы ввели недопустимое число!")
		print()
		return False
	return True
def Proverka3(m):
	if m < 0:
		print("Вы ввели не целое число!")
		print()
		return False
	if m < 1 or m > 100:
		print("Вы ввели число которое находится не в диапазоне[1; 100]")
		print()
		return False
	return True
flag = False
while not flag:
	print("Введите четное число в диапазоне [2;8]")
	m = Vvod()
	flag = Proverka(m)
print()
flag = False
while not flag:
	print("Выберите вариант заполнения матрицы:")
	print("1.Заполнить случайными числами в диапазоне [1; 100]")
	print("2.Заполнить вручную числами в диапазоне [1; 100]")
	print("Введите цифру варианта, который вы хотите выбрать(1 или 2):")
	v = Vvod()
	flag = Proverka2(v)
res = []
a = [0] * m
for i in range(m):
	a[i] = [0]*m

if v == 1:
	for i in range(m):
		for j in range(m):
			a[i][j] = int(random.random()*100)
else:
	for i in range(m):
		for j in range(m):
			flag = False
			while not flag:
				print("Введите целое число в промежутке [1; 100], которое будет являтся элементом массива a[" + str(i) + "][" + str(j) + "] ")
				a[i][j] = Vvod()
				flag = Proverka3(a[i][j]) 	
print("Исходная матрица:")
for i in range(m):
	print(*a[i])
for i in range(m):
	for j in range(m):
		res.append(a[i][j])
res.sort()
k = int(len(res)/2)
for i in range(0, int(m/2)):
	for j in range(m):
		a[i][j] = res[k]
		k += 1
k = 0
for i in range(int(m/2), m):
	for j in range(m):
		a[i][j] = res[k]
		k += 1	
print("Конечная матрица:")
for i in range(m):
	print(*a[i])
