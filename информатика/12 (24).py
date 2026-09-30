from random import randint
from keyboard import block_key
block_key('ctrl')
block_key('alt')
def create_arr():
    deck = []
    for row in range(8):
        in_deck = []
        for column in range(8):
            in_deck.append(randint(1, 100))
        deck.append(in_deck)
    return deck
def print_matx(arr):
    for row in range(8):
        for column in range(8):
            print(arr[row][column], end=" ")
        print()
def add_arr(deck, index):
    arr = []
    for x in range(index - 1, 64, 2):
        arr.append(deck[x // 8][x % 8])
    return arr

deck = create_arr()


print("Перед вами шахматная доска с числами на каждой клетке:")
print_matx(deck)

print("Выберите цвет:\n1. Белый\n2. Чёрный")
while(True):
    try: i = input()
    except: i = ""
    if i.isdigit() and (int(i) == 1 or int(i) == 2):
        arr = add_arr(deck, int(i))
        break
    else: print("Неверные данные. Попробуйте ещё раз")

print("Отсортированный массив со значениями с клеток выбранного цвета")
print(*sorted(arr))
