//
// Created by cassandre on 11/10/24.
//

#include "exercice1.h"


vector<int> getSeq1() {
    ifstream myText("../INPMONOSEQ.txt");
    int size;
    vector<int> tab;
    if (myText) {
        string line;
        getline(myText, line);
        size = stoi(line);
        getline(myText, line);
        string numberStr = strtok(line.data(), " ");
        int number = stoi(numberStr);
        //cout << number << endl;
        tab.push_back(number);
        for (int i = 0; i < size - 1; i++) {
            numberStr = strtok(NULL, " ");
            number = stoi(numberStr);
            //cout << number << endl;
            tab.push_back(number);
        }
        return tab;
    }
    else {
        cout << "Error opening file" << endl;
    }
}

vector<int> getSubSeq(const vector<int>& inputSequence) {
    vector<vector<int>> subSequences;
    vector<int> startingSequence;
    startingSequence.push_back(inputSequence.front());
    subSequences.push_back(startingSequence);
    for (int i = 1; i < inputSequence.size(); i++) {
        if(inputSequence.at(i) >= inputSequence.at(i-1)) {
            for(vector<int>& list: subSequences){
                if (list.back() <= inputSequence.at(i)) {
                    list.push_back(inputSequence.at(i));
                }
            }
        }
        else {
            int newElement = inputSequence.at(i);
            int maxIndex = 0;
            int maxIndexList = 0;
            for(int listIndex = 0; listIndex < subSequences.size(); listIndex++) {
                auto currentList = subSequences.at(listIndex);
                int elementIndex = findNewIndex(currentList, newElement);
                if(elementIndex > maxIndex){
                    maxIndex = elementIndex;
                    maxIndexList = listIndex;
                }
            }
            auto copiedList = subSequences.at(maxIndexList);
            vector<int> newList;
            for(int j = 0; j < maxIndex; j++) {
                newList.push_back(copiedList.at(j));
            }
            newList.push_back(newElement);
            subSequences.push_back(newList);
        }
    }
    int maxListSize = 0;
    int biggestListIndex = 0;
    for(int listIndex = 0; listIndex < subSequences.size(); listIndex++) {
        if(subSequences.at(listIndex).size() > maxListSize) {
            maxListSize = subSequences.at(listIndex).size();
            biggestListIndex = listIndex;
        }
    }
    return subSequences.at(biggestListIndex);
}


void output1(const vector<int>& tab) {
    ofstream myFile("../OUTMONOSEQ.txt");
    myFile << tab.size() << endl;
    for (int i = 0; i < tab.size(); i++) {
        myFile << "a[" << i+1 << "] = " << tab.at(i) << endl;
    }
    myFile.close();
}

void exercice1() {
    vector<int> tab = getSeq1();
    int size = tab.size();
    vector<int> subSeq = getSubSeq(tab);
    int subSize = subSeq.size();
    output1(subSeq);
}

int findNewIndex(const vector<int>& list, int newElement) {
    for(int i = 0; i < list.size(); i++) {
        if(newElement < list.at(i)) {
            return i;
        }
    }
    return list.size();
}
