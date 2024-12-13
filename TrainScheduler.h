#ifndef TRAINSCHEDULER_H
#define TRAINSCHEDULER_H

#include <queue>
#include <stack>
#include <string>

void loadState(std::queue<std::string>& trainQueue, std::stack<std::string>& completedRoutes);
void saveState(const std::queue<std::string>& trainQueue, const std::stack<std::string>& completedRoutes);
void displayMenu();
void addTrain(std::queue<std::string>& trainQueue);
void viewNextTrain(const std::queue<std::string>& trainQueue);
void completeTrain(std::queue<std::string>& trainQueue, std::stack<std::string>& completedRoutes);

#endif // TRAINSCHEDULER_H
