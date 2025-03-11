# graf oluşturma : 

graf = {
    'A' : ['B','C'],
    'B' : ['A' ,'D'],
    'C' : ['A','D'],
    'D' : ['B','C']   
}


def dfs(graf , baslangic , ziyaret_edilenler = None): 
    if ziyaret_edilenler is None:
        ziyaret_edilenler = set()
    
    ziyaret_edilenler.add(baslangic)
    print(baslangic)
    
    for komsu in graf[baslangic]:
        if komsu not in ziyaret_edilenler:
            dfs(graf,komsu,ziyaret_edilenler)
            
from collections import deque

def bfs(graf, baslangic):
    ziyaret_edilenler = set()
    kuyruk = deque([baslangic])
    ziyaret_edilenler.add(baslangic)
    
    while kuyruk: 
        node = kuyruk.popleft()
        print(node)
        
        for komsu in graf[node]:
            if komsu not in ziyaret_edilenler:
                ziyaret_edilenler.add(komsu)
                kuyruk.append(komsu)
                
print("Dfs ziyaret sırası: ")
dfs(graf,'A')

print("Bfs ziyaret sırası: ")
bfs(graf,'A')
            
