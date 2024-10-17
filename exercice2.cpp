//
// Created by cassandre on 11/10/24.
//

#include "exercice2.h"

pair<vector<int>,int> getSeq2() {
    ifstream myText("../INPDIVSEQ.txt");
    int size;
    int divisor;
    vector<int> tab;
    if (myText) {
        string line;
        getline(myText, line);
        string sizeStr = strtok(line.data(), " ");
        size = stoi(sizeStr);
        string divisorStr = strtok(NULL, " ");
        divisor = stoi(divisorStr);
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
        return make_pair(tab, divisor);
    }
    else {
        cout << "Error opening file" << endl;
    }
}

vector<int> getSubSeq2(vector<int> inputSequence, int divisor) {
    int sum = 0;
    for(const int number: inputSequence) {
        sum+= number;
    }
    int sequenceRemainder = sum % divisor;
    if (sequenceRemainder == 0) {
        return inputSequence;
    }
    vector<int> remainderList;
    int remainderCounts[divisor - 1] = {0};
    for (int i : inputSequence) {
        const int remainder = i % divisor;
        remainderList.push_back(remainder);
        if(remainder != 0) {
            remainderCounts[remainder - 1]++;
        }
    }
    cout << "remainders in the sequence: ";
    for(int i = 0; i < divisor - 1; i++) {
        cout << remainderCounts[i] << ", ";
    }
    cout << endl;
    int toExclude = 1;
    vector<int> remaindersToExclude;
    while(remaindersToExclude.empty() && toExclude < divisor + 1) {
        remaindersToExclude = tryToSum(divisor, sequenceRemainder, toExclude, remainderCounts);
        toExclude++;
    }
    if(remaindersToExclude.empty()) {
        vector<int> subSeq;
        return subSeq;
    }
    for(int remainderIndex = 0; remainderIndex < remaindersToExclude.size(); remainderIndex++) {
        const int count = remaindersToExclude.at(remainderIndex);
        for (int j = 0; j < count; j++) {
            int erasedIndex = 0;
            while(remainderList.at(erasedIndex) != remainderIndex + 1) {
                erasedIndex++;
            }
            inputSequence.erase(inputSequence.begin() + erasedIndex);
            remainderList.erase(remainderList.begin() + erasedIndex);
        }
    }
    return inputSequence;
}

void exercice2() {
    auto sequenceInfo = getSeq2();
    auto seq2 = sequenceInfo.first;
    int divisor = sequenceInfo.second;
    auto subSeq = getSubSeq2(seq2, divisor);
    int sum = 0;
    //cout << "subsequence size: " << subSeq.size() << endl;
    //cout << "subsequence: " << endl;
    for (int i:subSeq) {
        sum += i;
        cout << i << endl;
    }
    //cout << "sum: " << sum << endl;
    output2(subSeq);
}


void output2(const vector<int>& tab) {
    ofstream myFile("../OUTDIVSEQ.txt");
    myFile << tab.size() << endl;
    int sum = 0;
    for (int i = 0; i < tab.size(); i++) {
        myFile << "a[" << i+1 << "] = " << tab.at(i) << endl;
        sum += tab.at(i);
    }
    myFile << "sum: " << sum << endl;
    myFile.close();
}

vector<int> tryToSumRec(const int divisor, const int targetRemainder, const int numberOfTerms, int startingRemainder, int remainderCounts[]) {
    static const vector<int> emptyList;
    if(numberOfTerms == 1) {
        if(remainderCounts[targetRemainder - 1] > 0) {
            vector<int> outputList(divisor - 1, 0);
            outputList.at(targetRemainder - 1)++;
            return outputList;
        }
        return emptyList;
    }
    int chosenRemainder = startingRemainder;
    while( chosenRemainder < divisor) {
        if(remainderCounts[chosenRemainder - 1] != 0) {
            remainderCounts[chosenRemainder - 1]--;
            int newTargetRemainder = positiveModulo(targetRemainder - chosenRemainder, divisor);
            vector<int> intermediateList = tryToSumRec(divisor, newTargetRemainder, numberOfTerms - 1, startingRemainder, remainderCounts);
            if(!intermediateList.empty()) {
                intermediateList.at(chosenRemainder - 1)++;
                return intermediateList;
            }
            remainderCounts[chosenRemainder - 1]++;
        }
        chosenRemainder++;
    }
    return emptyList;
}

vector<int> tryToSum(int divisor, int targetRemainder, int numberOfTerms, int remainderCounts[]) {
    return tryToSumRec(divisor, targetRemainder, numberOfTerms, 1, remainderCounts);
}

int positiveModulo(int value, int divisor) {
    int mod = value % divisor;
    if(mod < 0) {
        mod += divisor;
    }
    return mod;
}
