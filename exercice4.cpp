//
// Created by cassandre on 20/10/24.
//

#include "exercice3.h"
#include "exercice4.h"


vector<pair<int,int>> getConGraph4() {
    ifstream myText("../INPCONGRAPH.txt");
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



void exercice4(){
    vector<pair<int,int>> graph = getConGraph4();
    displayGraph(graph);  // défini dans exercice3.h
    vector<deque<int>> adjacenteList = adjacenceList(graph);
    displayAdjacenceList(adjacenteList);

}