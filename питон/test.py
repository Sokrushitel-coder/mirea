##22222222222222222222222222222222222222222222222
##from math import *
##
##
##def main(y):
##    if y < 111:
##        o = (97 * y)**4
##    elif 111 <= y < 124:
##        o = (y**2 + 0.01)**4
##    elif 124 <= y < 213:
##        o = log(y**2, 10)**6
##    else:
##        o = tan(72 * y**3) + y + 9 * (y**3 - 1)**3
##    return o
##from math import *
##
##
##def main(y):
##    return (97 * y)**4 if y < 111 else (y**2 + 0.01)**4 if 111 <= y < 124 else log(y**2, 10)**6 if 124 <= y < 213 else tan(72 * y**3) + y + 9 * (y**3 - 1)**3
##print(main(int(input())))
####3333333333333333333333333333333333333333333333333333333333333
##from math import *
##
##
##def main(b, p, n):
##    o = 0
##    a = 1
##    for i in range(1, b+1):
##        a *= 69 * p**4 - i
##    o = a
##    a = 1
##    for i in range(1, n+1):
##        a *= sum([34 * (14 * k + k**3)**5 - log(
##            i**3, e)**2 / 72 - i**6 for k in range(1, b+1)])
##    return o - a

##from math import *
##
##
##def main(b, p, n):
##    o = 0
##    a = 1
##    i = 1
##    while i < b+1:
##        a *= 69 * p**4 - i
##        i += 1
##    o = a
##    a = 1
##    i = 1
##    while i < n+1:
##        q = 0
##        k = 1
##        while k < b+1:
##            q += 34 * (14 * k + k**3)**5 - log(
##                i**3, e)**2 / 72 - i**6
##            k += 1
##        i += 1
##        a *= q
##    return o - a
##
##from math import *
##
##
##def f(b, p, a, i):
##    if i == b + 1:
##        return a
##    return f(b, p, a * (69 * p**4 - i), i + 1)
##
##def E(b, p, n, k, q, i):
##    if k == b + 1:
##        return q
##    return E(b, p, n, k + 1, q + 34 * (14 * k + k**3)**5 - log(
##                i**3, e)**2 / 72 - i**6, i)
##def g(b, p, n, i, a):
##    if i == n + 1:
##        return a
##    return g(b, p, n, i + 1, a * E(b, p, n, 1, 0, i))
##def main(b, p, n):
##    o = 0
##    a = 1
##    i = 1
##    o = f(b, p, a, i)
##    
##    return o - g(b, p, n, 1, 1)
##print(main(2, -0.45, 6))
##from math import *
##
##
##def main(b, p, n):
##    o = 0
##    a = 1
##    i = 1
##    while i < b+1:
##        a *= 69 * p**4 - i
##        i += 1
##    o = a
##    a = 1
##    i = 1
##    while i < n+1:
##        
##        a *= sum([34 * (14 * k + k**3)**5 - log(
##            i**3, e)**2 / 72 - i**6 for k in range(1, b+1)])
##        i += 1
##    return o - a
##4444444444444444444444444444444444444
##from math import *
##
##
##
##def main(n):
##    if n == 0:
##        return 0.73
##    return main(n - 1)**2 - log(
##        1 + main(n - 1)**2 + main(n - 1) / 25, 10) / 99
##

##5555555555
##from math import *
##
##
##def main(y, x):
##    n = 3
##    return 71 * sum([sin(83 * y[n + 1 - i - 1] ** 2 + x[
##        i - 1]) ** 2 / 20 for i in range(1, n + 1)])

##from math import *
##
##
##def main(y, x):
##    o = 0
##    i = 1
##    while i < 4:
##        o += sin(83 * y[3 + 1 - i - 1] ** 2 + x[
##        i - 1]) ** 2 / 20
##        i += 1
##    return 71 * o

##from math import *
##
##
##def f(y, x, i, o):
##    if i == 4:
##        return o
##    return f(y, x, i+1, o + sin(
##        83 * y[3 + 1 - i - 1] ** 2 + x[
##        i - 1]) ** 2 / 20)
##def main(y, x):
##    return 71 * f(y, x, 1, 0)

##
##from math import *
##
##
##def main(y, x):
##    o = sin(83 * y[3 + 1 - 1 - 1] ** 2 + x[
##        1 - 1]) ** 2 / 20 + sin(
##        83 * y[3 + 1 - 2 - 1] ** 2 + x[
##            2 - 1]) ** 2 / 20 + sin(
##        83 * y[3 + 1 - 3 - 1] ** 2 + x[
##        	3 - 1]) ** 2 / 20
##    return 71 * o
##
##print(main([0.38, 0.34, 0.92],
##[-0.12, -0.96, 0.77]))
##6666666666666666
##from math import floor
##
##
##def main(L: set):
##    E = set([(abs(ll) - floor(ll / 2)) * (ll in L) for ll in range(-19, 67)])
##    E.remove(0)
##    OO = set([abs(ll) * (ll in L) for ll in range(-45, 1000000)])
##    M = set([s * o * (s <= o) for s in E for o in OO])
##    M.remove(0)
##    K = set([o * (-35 < o <= 36 and o != 0) for o in OO])
##
##    return len(M) - sum([floor(k / 9) for k in K])
##
##777777777777777777777777777777777777777777
##from math import *
##
##
##def main(x):
##    if len(x) != 4:
##        return
##    if x[2] == 1958:
##        return 11
##    elif x[2] == 1982:
##        if x[3] == 'X10':
##            if x[1] == 1962:
##                return 6
##            elif x[1] == 1989:
##                return 7
##        elif x[3] == "OOC":
##            if x[1] == 1962:
##                return 8
##            elif x[1] == 1989:
##                return 9
##        elif x[3] == "SHELL":
##            return 10
##    elif x[2] == 2011:
##        if x[0] == 1982:
##            if x[1] == 1962:
##                return 0
##            elif x[1] == 1989:
##                return 1
##        elif x[0] == 1958:
##            return 2
##        elif x[0] == 2009:
##            if x[3] == 'X10':
##                return 3
##            elif x[3] == 'OOC':
##                return 4
##            elif x[3] == 'SHELL':
##                return 5
##def main(x):
##    if len(x) != 4:
##        return None
##    year, model, version, software = x
##    if version == 1958:
##        return 11
##    elif version == 1982:
##        if software == 'X10':
##            return 6 if model == 1962 else 7 if model == 1989 else None
##        elif software == "OOC":
##            return 8 if model == 1962 else 9 if model == 1989 else None
##        elif software == "SHELL":
##            return 10
##    elif version == 2011:
##        if year == 1982:
##            return 0 if model == 1962 else 1 if model == 1989 else None
##        elif year == 1958:
##            return 2
##        elif year == 2009:
##            return 3 if software == 'X10' else 4 if software == 'OOC' else 5 if software == 'SHELL' else None
##
##print(main([2009, 1962, 1982, 'X10']))
        
##88888888888888888888888888888888888888888
##def main(x):
##    x = '0'*14+bin(x)[2:]
##    print(x)
##    return hex(int(x[-7:], 2)), hex(int(x[-9:-7], 2)), hex(
##        int(x[-11:-9], 2)), hex(int(x[-12:-11], 2))
##
##print(main(1741))
##999999999999999999999999999999999999999999
##def main(x):
##    d = dict()
##    for i in '<>=,[.]\n':
##        x = x.replace(i, ' ')
##    x = x.replace('variable', ' ')
##    for i in x.split():
##        if i[0] == '#':
##            e = i[1:]
##        else:
##            d[i] = int(e)
##    return d
##
##print(main("""[ << variable#3817 ==>arti. >>, <<variable #3821 ==> ralaer_852. >>,\n<<variable #-4627 ==> atve. >>, ]"""))
##1010101010101010101010
##def main(x):
##    L = []
##    s = set()
##    for name, num, num1, mail, per in x:
##        if num not in s:
##            if num is not None:
##                l1 = [num[-7:], name.split()[-1], mail[:mail.index('@')],
##                      str(int(float(per) * 100)) + '%']
##                L += [l1]
##                s.add(num)
##    L = sorted(L)
##    
##    for i in range(len(L)):
##        num, name, mail, per = L[i]
##        L[i] = [name, num[-7:-4] + '-' + num[-4:-2] + '-' + num[-2:],
##                mail, per]
##    return L
##111111111111111111111111111111111111111111
##class MealyError(Exception):
##    pass
##
##
##class mili():
##
##    def __init__(self):
##        self.state = 'a'
##
##    def f(self, d, m):
##        s = self.state
##        try:
##            self.state = d[s][1]
##            return d[s][0]
##        except KeyError:
##            raise MealyError(m)
##
##    def hike(self):
##        dh = {'a': [0, 'b'], 'b': [3, 'b'], 'f': [9, 'a']}
##        return self.f(dh, 'hike')
##
##    def jog(self):
##        dj = {'b': [4, 'd'], 'd': [6, 'e'], 'f': [8, 'g']}
##        return self.f(dj, 'jog')
##
##    def leer(self):
##        dl = {'b': [2, 'c'], 'c': [5, 'd'], 'e': [7, 'f'], 'a': [1, 'd']}
##        return self.f(dl, 'leer')
##
##
##def main():
##    return mili()
##
##
##def test():
##    m = main()
##    try:
##        m.jog()
##    except MealyError:
##        pass
##    m.hike()
##    m.leer()
##12121212121212121211212121121
##import struct
##b = bytearray(b'\xe3RTOY\xc9\xa9\x11\x00RLgev\x00\x00\x00\x02\x9c\xc1~\xcesjqqjokb\xbd\xb3'
## b'\xc7\x04\xee\x1d\xb9\x8cVe\x03\xf4\x843\xde\xb5JO\x98\xc4\x1f\xbb'
## b'\xc3\x0e\xd4\x82{\xc9\xae\xed\xc9\x92\x9b\x15%\xa4\x85\xc9\xfc\xd5%\xa0'
## b'){\xd1qU\xfb\xccp\xac\x0c\xc6i\xc6\xe3\x86\xb9\xc0M\x8f\x13n9\xdd\x87'
## b'\x10\xa1P\x80:\xeac\x01,\x07\xc7\xa7<\x19\x88)\x9e\xd1\xdc\xf1'
## b'\x08\xc4\xbc\xf1\xd9\xd8\x1c\x84p\x13.\xb7\xdfX\xb4?\x94\xe9\x9ft'
## b'\x1e\x00\x00\x00J\x00\x00\x00K|Y\x13\x87)\x85\xfc\xfc^\xa6\x81R-D\xd9'
## b'\x08z\x17r\x9c!\xfb&\x1bN\xe0\xb8\xb4\x12$\xdd\xef')
##
##print(b)
##print(struct.unpack('<HHII',b[5:12+5]))
##print(struct.unpack('<Icp',b[5+17:5+17+8+]))
##def A(b):
##    li=struct.unpack('<HHII',b[5:12+5])
    
def main(x):
    x=int(x)
    x = '0'*27+bin(x)[2:]
    x = x[::-1]
##    print(x)
    x = x[:14]+x[22:28]+x[14:21]+x[21]
    x = x[::-1]
##    print(x)
    print(hex(int(x,2)))
    return hex(int(x[-7:], 2)), hex(int(x[-9:-7], 2)), hex(
        int(x[-11:-9], 2)), hex(int(x[-12:-11], 2))
main('56340542')
