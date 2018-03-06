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
    clock_t tStart = clock(); //dem thoi gian thuc hien

    int vertex;
    std::ifstream infile("/Users/dailong/Desktop/C++Basics/Create prufer code for a tree/Create prufer code for a tree/Node.txt");
    infile >> vertex;
    cout << vertex - 1 <<" Canh." <<endl;
    
    int root[vertex - 1];
    int leaf[vertex - 1];
    //
    for (int i = 0; i < vertex - 1; i++) {
        infile >> root[i] >> leaf[i];
    }
    infile.close();
    
    //sort
    Sort(vertex, root, leaf);
    pruferCode(vertex, root, leaf);
 
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    return 0;
}
