//
// Created by cassandre on 11/10/24.
//

#ifndef EXERCICE2_H
#define EXERCICE2_H
#include <cstring>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <fstream>
#include <algorithm>
using namespace std;

pair<vector<int>,int> getSeq2();
vector<int> getSubSeq2(vector<int> inputSequence, int divisor);
void output2(const vector<int>& tab);
vector<int> tryToSum(int divisor, int targetRemainder, int numberOfTerms, int remainderCounts[]);
vector<int> tryToSumRec(int divisor, int targetRemainder, int numberOfTerms, int startingRemainder, int remainderCounts[]);
int positiveModulo(int value, int divisor);

void exercice2();
#endif //EXERCICE2_H
