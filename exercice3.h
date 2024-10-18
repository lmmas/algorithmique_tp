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
void displayNeighborList(const vector<vector<int>>& tab);
vector<deque<int>> vertexNeighborList(const vector<pair<int,int>>& tab);
vector<pair<int,int>> getEdgesToRemove(const vector<deque<int>>& neighborList);
void output3(const vector<pair<int,int>>& tab);
void exercice3();



#endif //EXERCICE3_H
