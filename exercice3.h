//
// Created by cassandre on 17/10/24.
//

#ifndef EXERCICE3_H
#define EXERCICE3_H

#include <cstring>
#include <vector>
#include <deque>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <fstream>
#include <algorithm>
using namespace std;

vector<pair<int,int>> getArbGraph3();

void displayGraph(const vector<pair<int,int>>&);

void displayAdjacenceList(const vector<vector<int>>& tab);
void displayAdjacenceMatrix(const vector<vector<int> > &tab);

vector<deque<int>> adjacenceList(const vector<pair<int,int>>& tab);
vector<vector<int>> adjacenceMatrix(const vector<pair<int,int>>&tab);

vector<pair<int,int>> getSpanningTreeList(vector<pair<int,int>> inputGraph);
vector<pair<int,int>> getSpanningTreeMatrix(vector<pair<int,int>> inputGraph);

vector<pair<int,int>> getEdgesToRemoveList(const vector<deque<int>>& neighborList);
vector<pair<int,int>> getEdgesToRemoveMatrix(const vector<vector<int>>& neighborMatrix);


void output3(const vector<pair<int,int>>& tab);
void exercice3();



#endif //EXERCICE3_H
