#include "TrainScheduler.h"
#include <iostream>
#include <fstream>

using namespace std;

// Function Definitions
void loadState(queue<string>& trainQueue, stack<string>& completedRoutes) {
    ifstream queueFile("queue.txt"), stackFile("stack.txt");
    string line;

    // Load queue
    if (queueFile.is_open()) {
        while (getline(queueFile, line)) {
            trainQueue.push(line);
        }
        queueFile.close();
    }

    // Load stack
    if (stackFile.is_open()) {
        stack<string> tempStack;
        while (getline(stackFile, line)) {
            tempStack.push(line);
        }
        stackFile.close();

        // Reverse to restore order
        while (!tempStack.empty()) {
            completedRoutes.push(tempStack.top());
            tempStack.pop();
        }
    }
}

void saveState(const queue<string>& trainQueue, const stack<string>& completedRoutes) {
    ofstream queueFile("queue.txt"), stackFile("stack.txt");

    // Save queue
    queue<string> tempQueue = trainQueue;
    while (!tempQueue.empty()) {
        queueFile << tempQueue.front() << "\n";
        tempQueue.pop();
    }
    queueFile.close();

    // Save stack
    stack<string> tempStack = completedRoutes;
    while (!tempStack.empty()) {
        stackFile << tempStack.top() << "\n";
        tempStack.pop();
    }
    stackFile.close();
}

void displayMenu() {
    cout << "\nTrain Scheduling System\n";
    cout << "1. Add a train to the schedule\n";
    cout << "2. View next train to depart\n";
    cout << "3. Complete a train route\n";
    cout << "4. Save and Exit\n";
    cout << "Enter your choice: ";
}

void addTrain(queue<string>& trainQueue) {
    string train;
    cout << "Enter train details (e.g., Train 101 at 10:00 AM): ";
    getline(cin, train);
    trainQueue.push(train);
    cout << "Train added to schedule.\n";
}

void viewNextTrain(const queue<string>& trainQueue) {
    if (!trainQueue.empty()) {
        cout << "Next train: " << trainQueue.front() << "\n";
    } else {
        cout << "No trains scheduled.\n";
    }
}

void completeTrain(queue<string>& trainQueue, stack<string>& completedRoutes) {
    if (!trainQueue.empty()) {
        string completedTrain = trainQueue.front();
        trainQueue.pop();
        completedRoutes.push(completedTrain);
        cout << "Train completed: " << completedTrain << "\n";
    } else {
        cout << "No trains to complete.\n";
    }
}
