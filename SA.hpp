#pragma once
#include "Node.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>
class SA{ //simulated annealing solver
public:
SA(Node* nodelist, int numNodes,double temper, double tval);


double distance(Node n1, Node n2);//gets distance between two nodes
double getListDist(Node* list);//given either bestTour/currentTour, finds total distance of consecutive nodes in that list

void swapCities(Node *n ,int n1, int n2);
//swaps cities in position n1 and n2 in list n

void simulatedAnnealing();//runs the algorithm
void printDist(); //prints the distance of the best tour
void printCities();//prints the list of cities


Node* bestTour;
Node* currentTour;
Node* citiesList;
double temperature,schedule,  bestDist; 
int numCities,updateNum,numIters,totalTours;
//int * c1,c2;
};
