#include <vector>
#include <iostream>
#include <algorithm>
int main() {
    int N = 5;
    std::vector<int> a = {10, 3, 1, 10 ,11};
    std::vector<int> rez;

    for (int i=size(a) -1; i>=0; --i) {
        int flag = 0; // если он так и останется 0,значит надо вывести -1
        for (int j=size(a)-1; j>=i+1; --j) {
            // как только я наеш самого молодого с меньшим возрастом, все считаю (индексы у мекня есть) и делаю break
            if (a[i] > a[j]) {  // те если морж старший
                // мы нашли самого удаленного, надо зафиксировать прибыль и вывести кол-во. j-i+1
                rez.push_back(j-i-1);
                flag = 1;
                break; // начинаем перебирать для нового
            }
        }
        //Если не нашли то -1
        if (flag == 0) {
            rez.push_back(-1);
        }
    
    }
    std::reverse(rez.begin(), rez.end());
    for (int i: rez) {
        std::cout << i << " ";
    }
    return 0;
}