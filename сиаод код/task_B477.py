"""
Создать txt-файл, вставить туда любую англоязычную статью из Википедии.
Реализовать одну функцию, которая выполняет следующие операции:
- прочитать файл построчно;
- непустые строки добавить в список;
- удалить из каждой строки все цифры, знаки препинания, скобки, кавычки и т.д. (остаются латинские буквы и пробелы);
- объединить все строки из списка в одну, используя метод join и пробел, как разделитель;
- создать словарь вида {“слово”: количество, “слово”: количество, … } для подсчета количества разных слов,
  где ключом будет уникальное слово, а значением - количество;
- вывести в порядке убывания 10 наиболее популярных слов, используя форматирование
  (вывод примерно следующего вида: “ 1 place --- sun --- 15 times \n....”);
- заменить все эти слова в строке на слово “PYTHON”;
- создать новый txt-файл;
- записать строку в файл, разбивая на строки, при этом на каждой строке записывать не более 100 символов
  при этом не делить слова.
"""

def wiki_function():
    # Тело функции
    alf='qwertyuiopasdfghjklzxcvbnm'
    with open('wiki.txt','r+') as f:
        l=[]
        for a in f:
            if a!='\n':
                l.append(a)
    for i in range(len(l)):
        j=0
        while j <len(l[i]):
            if not l[i][j] in alf+alf.upper()+' ':
                
                l[i]=l[i][:j]+l[i][j+1:]
                j-=1
            j+=1
    s=' '.join(l)
    d=dict()
    for i in s.split():
        try:
            d[i]+=1
        except:
            d[i]=1
    text=s.split()
    e=1
    for i,j  in sorted(d.items(), key=lambda item: item[1])[::-1]:
        print(f" {e} place --- {i} --- {j} times ")
        
        for q in range(len(text)):
            if text[q]==i:
                text[q]="PYTHON"
        if e==10:
            break
        e+=1
    
    #print(' '.join(text))
    with open("out.txt","w") as f:
        counter=0
        for i in text:
            if len(i)+counter<100:
                f.write(i)
                counter+=len(i)+1
            else:
                counter=len(i)+1
                f.write("\n"+i)
            
    return 1


# Вызов функции
wiki_function()
