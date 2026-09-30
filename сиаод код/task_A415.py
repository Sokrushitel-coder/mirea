# Написать функцию look_and_say(data, len), которая возвращает список
# из len следующих элементов за data в последовательности смотрю_и_говорю
# Пример последовательности для "1" ==> "11" ("один 1") ==> "21" ("два 1") ==>
# "1211" ("один 2, один 1") ==> "111221" ("один 1, один 2, два 1") ...
#
# Пример:
# look_and_say(1, 7) ==> [11, 21, 1211, 111221, 312211, 13112221, 1113213211]



import traceback


def look_and_say(data, Len):
    result = [str(data)]
    for i in range(Len ):
        count = 1
        next_item = ""
        for j in range(1, len(str(result[i]))):
            if str(result[i])[j] == str(result[i])[j-1]:
                count += 1
            else:
                next_item += str(count) + str(result[i])[j-1]
                count = 1
        next_item += str(count) + str(result[i])[-1]
        result.append(str(int(next_item)))
    #print(result)
    return [int(i) for i in result[1:]]
    



# Тесты
try:
    assert  look_and_say(1, 6) == [11, 21, 1211, 111221, 312211, 13112221]
    assert look_and_say(132, 4) == [111312, 31131112, 1321133112, 11131221232112]
except AssertionError:
    print("TEST ERROR")
    traceback.print_exc()
else:
    print("TEST PASSED")
