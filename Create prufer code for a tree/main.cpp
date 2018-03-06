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

using namespace std;


void pruferCode (int vertex, int *root, int *leaf) {
    
    
    int i,j;
    vector<int> element(vertex, 0);
    vector<int> pruferCode;

    for (i = 0; i < vertex - 1 ; i++) { //dem so so lan xuat hien cua phan tu trong root
        element[root[i]]+= 1;
    }
    
    int min = 1;  while (element[min] > 0) min++;// tim phan tu nho nhat xuat hien trong [leaf]
    for (j = 0; j < vertex - 1; j++) {
        pruferCode.push_back(root[min-1]); //add vao prufercode
        element[min]++; //loai leaf[i] nay di
        element[root[min-1]]--;// giam so lan xuat hien
    
        min = 1;  while (element[min] > 0) min++;
    }
    //print
    for (i = 0; i < vertex - 2; i++) {
        cout << pruferCode[i] << " ";
    }
}

void Sort(int vertex, int *root, int *leaf) {
    int i, min, j;
    for (i = 0; i < vertex - 2; i++) {
        min = i;
        for (j = i + 1; j < vertex - 1; j++) {
            if (leaf[min] > leaf[j]) {
                min = j;
            }
        }
        swap(leaf[min], leaf[i]);
        swap(root[min], root[i]);
    }
}

int main()
{
    int i, vertex;
    cout << "input numbers of vertex :" ; cin >> vertex;

    int root[vertex - 1];
    int leaf[vertex - 1];
 
    for (i = 0; i < vertex - 1; i++) {
        cout << "canh thu " << i + 1 << " : "; cin >>root[i] >> leaf[i];
    }
    //sort
    Sort(vertex, root, leaf);
    pruferCode(vertex, root, leaf);
 
    return 0;
}
