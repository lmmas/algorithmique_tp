//
// Created by cassandre on 17/10/24.
//

#include "exercice3.h"



vector<pair<int,int>> getArbGraph3() {
    ifstream myText("../INPARBGRAPH.txt");
    vector<pair<int,int>> tabGraph;
    if (myText) {
        int sommet;
        int arete;
        string line;
        getline(myText,line);
        string sommetStr = strtok(line.data(), " ");
        sommet = stoi(sommetStr);
        string areteStr = strtok(nullptr, " ");;
        arete = stoi(areteStr);
        tabGraph.emplace_back(sommet, arete);
        for (int i = 0; i < arete; i++) {
            getline(myText, line);
            string sommet1Str = strtok(line.data(), " ");
            int sommet1 = stoi(sommet1Str);
            string sommet2Str = strtok(nullptr, "");
            int sommet2 = stoi(sommet2Str);
            tabGraph.emplace_back(sommet1, sommet2);
        }
        return tabGraph;
    }
    cout << "Error opening file" << endl;
    return tabGraph;
}

void displayGraph(const vector<pair<int,int>>& tab) {

    for (const auto & i : tab) {
        cout << i.first << "  " << i.second << endl;
    }
}

vector<deque<int>> adjacenceList(const vector<pair<int,int>>& tab) {
    vector<deque<int>> neighborList(tab.front().first);
    for (int i=1; i<tab.size(); i++) {
        pair<int,int> edge = tab.at(i);
        neighborList.at(edge.first - 1).push_back(edge.second);
        neighborList.at(edge.second - 1).push_back(edge.first);
    }
    return neighborList;

}

vector<vector<int>> adjacenceMatrix(const vector<pair<int,int>>&tab) {
    vector neighborMatrix(tab.front().first, vector (tab.front().first, 0));
    for (int i=1; i<tab.size();i++) {
        pair<int,int> edge = tab.at(i);
        neighborMatrix.at(edge.second-1).at(edge.first-1) = 1;
        neighborMatrix.at(edge.first-1).at(edge.second-1)=1;
    }
    return neighborMatrix;
}

vector<pair<int,int>> getEdgesToRemoveList(const vector<deque<int>>& neighborList) {
    vector<pair<int,int>> outputList;
    for (int i=2; i < neighborList.size(); i++) {
        int neighborCount  = 0;
        for(int element: neighborList.at(i)) {
            if(element <= i) {
                neighborCount++;
                if(neighborCount == 2) {
                    outputList.emplace_back(i + 1, element);
                    neighborCount--;
                }
            }
        }
    }
    return outputList;
}


vector<pair<int,int>> getEdgesToRemoveMatrix(const vector<vector<int>>& neighborMatrix) {
    vector<pair<int,int>> outputList;
    for (int i=2; i<neighborMatrix.size();i++) {
        int neighborCount = 0;
        for(int j = 0; j <i; j++) {
            if (neighborMatrix.at(i).at(j) == 1) {
                neighborCount++;
                if (neighborCount == 2) {
                    outputList.emplace_back(i+1, j+1);
                    neighborCount--;
                }
            }
        }
    }
    return outputList;
}

vector<pair<int,int>> getSpanningTreeList(vector<pair<int,int>> inputGraph) {
    const auto neighborList = adjacenceList(inputGraph);
    auto edgesToRemove = getEdgesToRemoveList(neighborList);
    for(const auto& edge: edgesToRemove) {
        auto toRemove = find(inputGraph.begin(), inputGraph.end(), edge);
        if(toRemove != inputGraph.end()) {
            inputGraph.erase(toRemove);
        }
        else {
            toRemove = find(inputGraph.begin(), inputGraph.end(),make_pair(edge.second, edge.first));
            inputGraph.erase(toRemove);
        }
    }
    return inputGraph;
}

vector<pair<int,int>> getSpanningTreeMatrix(vector<pair<int,int>> inputGraph) {
    const auto neighborMatrix = adjacenceMatrix(inputGraph);
    auto edgesToRemove = getEdgesToRemoveMatrix(neighborMatrix);

    for(const auto& edge: edgesToRemove) {
        auto toRemove = find(inputGraph.begin(), inputGraph.end(), edge);
        if(toRemove != inputGraph.end()) {
            inputGraph.erase(toRemove);
        }
        else {
            toRemove = find(inputGraph.begin(), inputGraph.end(),make_pair(edge.second, edge.first));
            inputGraph.erase(toRemove);
        }
    }
    return inputGraph;
}


void displayAdjacenceList(const vector<deque<int>>& tab) {

    for (const auto & i : tab) {
        for (int element:i) {
            cout << element << ", ";
        }
       cout << endl;
    }
}

void displayAdjacenceMatrix(const vector<vector<int> > &tab) {
    for (const auto &i:tab) {
        for (int element:i) {
            cout<< element<< ", ";
        }
        cout << endl;
    }
}


void output3(const vector<pair<int,int>>& tab) {
    ofstream myFile("../OUTARBGRAPH.txt");
    bool isFirst = true;
    for (const auto & i : tab) {
        if (isFirst) {
            isFirst = false;
            continue;
        }
        myFile << i.first << "  " << i.second << endl;
    }
    myFile.close();
}

void exercice3(){
    vector<pair<int,int>> graph = getArbGraph3();
    vector<vector<int>> matrix = adjacenceMatrix(graph);
    //displayAdjacenceMatrix(matrix);
    //displayGraph(graph);
    auto spanningTree = getSpanningTreeList(graph);
    //auto spanningTree = getSpanningTreeMatrix(graph);
    displayGraph(spanningTree);
    output3(spanningTree);
}