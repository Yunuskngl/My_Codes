#include <bits/stdc++.h> // Bu satır, standart kütüphanelerin hepsini içeri aktarır. Bu, genellikle yarışmalar veya hızlı prototipleme için kullanılır.

using namespace std; // std namespace'ini kullanacağımızı belirtir.

int main() { 
    int n, m; // n: düğüm sayısı, m: kenar sayısı
    cin >> n >> m; // Kullanıcıdan düğüm ve kenar sayılarını alır.

    // İlişki listesini tutmak için bir vektör vektörü oluşturulur.
    // İlk olarak her düğümün boş bir ilişki listesi vardır.
    vector<vector<int>> adj(n);  

    // Kullanıcıdan kenarların bağlantılarını alır ve ilişki listesine ekler.
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--; // Kullanıcı dostu indeksleme yapmak için 1 çıkarır.
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    // İlişki listesindeki düğümleri sıralar ve ekrana yazdırır.
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end()); // Her düğümün ilişki listesini sıralar.
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] + 1 << " "; // 1 ekleyerek kullanıcı dostu indeksleme yapar.
        }
        cout << endl;
    }
    // İlişki matrisini oluşturur ve ekrana yazdırır.
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Eğer j düğümü i düğümüne komşu ise 1, değilse 0 yazdırır.
            if (find(adj[i].begin(), adj[i].end(), j) != adj[i].end()){
             // find() fonksiyonu, j'nin i'nin ilişki listesinde olup olmadığını kontrol eder.
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    return 0; 
}
