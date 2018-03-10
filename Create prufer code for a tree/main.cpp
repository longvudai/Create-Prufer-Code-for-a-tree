//
//  main.cpp
//  Create prufer code for a tree
//
//  Created by Dai Long on 3/2/18.
//  Copyright © 2018 Dai Long. All rights reserved.
//

#include<iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>

using namespace std;

void pruferCode (int vertex, int *root, int *leaf) {
    int i,j;
    vector<int> element(vertex, 0);
    vector<int> pruferCode;
    
    for (i = 0; i < vertex - 1 ; i++) { //dem so so lan xuat hien cua phan tu trong root
        element[root[i]]+= 1;
        element[leaf[i]]+= 1;
    }
  
    int min = 1;  while (element[min] > 1) min++;// tim phan tu nho nhat xuat hien trong [leaf]
    for (i = 0; i < vertex - 2 ; i++) {
        for (j = 0; j < vertex - 1; j++) {
            if (root[j] == min) {
                element[min] += 1;
                root[j] = 0;
                pruferCode.push_back(leaf[j]);
                element[leaf[j]] -= 1;
                leaf[j] = 0;
                break;
            
            }
            if (leaf[j] == min) {
                element[min] += 1;
                leaf[j] = 0;
                pruferCode.push_back(root[j]);
                element[root[j]] -= 1;
                root[j] = 0;
                break;
            }
        }
        min = 1;  while (element[min] > 1) min++;
    }
    
    //print
    for (i = 0; i < vertex - 2; i++) {
        cout << pruferCode[i] << " ";
    }
}


int main() {
    int vertex;
    cout << "nhap vao so canh: " ; cin >> vertex;
    vertex += 1;
    
    int root[vertex - 1];
    int leaf[vertex - 1];
    
    for (int i = 0; i < vertex - 1; i++) {
        cout << "nhap canh thu " << i + 1 << ": "; cin >> root[i] >> leaf[i];
    }
    pruferCode(vertex, root, leaf);
    return 0;
}
