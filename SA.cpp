#include "SA.hpp"
#include <ctime>
using namespace std;


void SA::simulatedAnnealing(){
srand(time(0));

while(temperature > 0.000001){//loop start
numIters++;//NUMBER OF REJECTED TOURS +1
totalTours++;
for(int i = 0; i < numCities; i++){
currentTour[i] = bestTour[i];
}//SET UP Si


int c1= rand()%numCities;
int c2 = rand()%numCities;
while(c2<=c1 || c2 == 0 ||c1 == 0){	//GENERATE SOME RANDOM NUMBERS
c2 = rand()%numCities;
c1 = rand()%numCities;
}
int lim = c2-c1;
for(int i = 0; i < lim; i++){ //SWAP Si AROUND
swapCities(currentTour,c1+i,c2-i); 
}


double curLen = getListDist(currentTour); //GET THE LENGTH OF NEW TOUR

if( bestDist > curLen ||  (exp(-1*((curLen-bestDist)/temperature)) >(double)(rand()/(double) RAND_MAX))){
for(int i = 0;i<numCities; i++){ //IF THE NEW TOUR IS BETTER 
bestTour[i] = currentTour[i];	// OR THE PROBABILITY IS HIGH ENOUGH 
}				// SET THE BEST TOUR TO THE CURRENT TOUR
bestDist = curLen;
updateNum++;
cout <<"Update: "<<updateNum <<"   " <<"Number of rejected tours " 
<< numIters-1<<"  Temperature: " <<temperature <<endl; //PRINT INFO
numIters= 0;
}

temperature = temperature * schedule;//ADJUST TEMPERATURE
}
}

void SA::printDist(){//PRINT INFO
cout <<"Number of tours generated: " <<totalTours <<endl;
cout <<"Best distance is: "<<bestDist<<endl;
}

void SA::printCities(){//PRINT INFO
for(int i = 0; i < numCities; i++){
cout<< bestTour[i].m_name <<" " <<bestTour[i].m_x <<" " <<bestTour[i].m_y<<endl;
}
}




SA::SA(Node* nodelist, int numNodes,double temper, double tval){
temperature = temper;		//CONSTRUCTOR
schedule = tval;
updateNum = 0;
numIters= 0;
totalTours=0;
numCities = numNodes;
citiesList = new Node[numCities];
bestTour = new Node[numCities];
currentTour = new Node[numCities];
for (int i = 0; i < numNodes; i++){
citiesList[i] = nodelist[i];
bestTour[i] = nodelist[i];
}

schedule = tval;
bestDist = getListDist(bestTour);
}


void SA::swapCities(Node* n, int n1, int n2){
Node temp = n[n1];//SWAP FUNCTION, ASSUMES n IS A LIST
n[n1] = n[n2];
n[n2] = temp;
}



double SA::distance(Node n1, Node n2){//GET DISTNACE BETWEEN 2 NODES
double xDist = n1.m_x - n2.m_x;
xDist = xDist*xDist;
double yDist = n1.m_y - n2.m_y;
yDist = yDist*yDist;
return sqrt(xDist+yDist); 
}

double SA::getListDist(Node * list){// GET DISTANCE IN A LIST
double dist = 0;
for(int i = 0; i < numCities -1; i++){
dist = dist + distance( *(list+i), *(list+i+1));
}
return dist;
}




