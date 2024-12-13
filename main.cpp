#include "TrainScheduler.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    queue<string> trainQueue;
    stack<string> completedRoutes;

    // Load state from files
    loadState(trainQueue, completedRoutes);

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline after integer input
        switch (choice) {
            case 1:
                addTrain(trainQueue);
                break;
            case 2:
                viewNextTrain(trainQueue);
                break;
            case 3:
                completeTrain(trainQueue, completedRoutes);
                break;
            case 4:
                saveState(trainQueue, completedRoutes);
                cout << "State saved. Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
