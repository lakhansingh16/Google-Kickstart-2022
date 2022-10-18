from operator import itemgetter
import sys
t = int(input())
if(t<1 or t>100):
    sys.exit(1)
for i in range(t):
    n = int(input())
    counter=0
    uids = list()
    clothes = list()
    ada,charles=list(),list()
    for j in range(n):
        color,dur,uid = input().split()
        color = color.lower()
        dur = int(dur)
        uid = int(uid)
        if uid in uids:
            sys.exit(1)
        if(len(color)>10):
            sys.exit(1)
        d = {'color':color, 'dur':dur,'uid':uid}
        clothes.append(d)
        uids.append(uid)
    ada = sorted(clothes, key=itemgetter('color'))
    charles = sorted(clothes, key=itemgetter('dur'))
    for k in range(len(clothes)-1):
        if(ada[k]['color'] == ada[k+1]['color'] and ada[k]['uid']>ada[k+1]['uid']):
            ada[k],ada[k+1] = ada[k+1],ada[k]
        if(charles[k]['dur'] == charles[k+1]['dur'] and charles[k]['uid']>charles[k+1]['uid']):
            charles[k],charles[k+1] = charles[k+1],charles[k]
    for k in range(len(clothes)):
        if(ada[k]['uid'] == charles[k]['uid']):
            counter +=1
    print(f"Case #{i+1}: {counter}")
