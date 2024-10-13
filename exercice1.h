//
// Created by cassandre on 11/10/24.
//

#ifndef EXERCICE1_H
#define EXERCICE1_H

#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <fstream>
using namespace std;

vector<int> getSeq1();
vector<int> getSubSeq(const vector<int>& inputSequence);
void output1(const vector<int>& tab);

int findNewIndex(const vector<int>& list, int newElement);
void exercice1();

#endif //EXERCICE1_H
