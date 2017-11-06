#include "SA.hpp"
#include "Node.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

//TO MAKE THIS PROGRAM TYPE MAKE, IT WILL COMPILE IT INTO A PROGRAM NAMED prog

//TO USE THIS PROGRAM GIVE IT 0 OR 2 ARGUMENTS.
//0 ARGUMENTS RUNS THE PROGRAM WITH DEFAULT TEMPERATURE AND COOLING RATE
//2 ARGUMENTS SPECIFY THE TEMPERATURE AND COOLING RATE MULTIPLER RESPECTIVELY
//WHEN INPUTTING THE COOLING RATE, TYPE IN THE NUMBER WITHOUT THE LEADING ZERO AND DECIMAL, IE
//TO SET THE COOLING RATE MULTIPLER TO 0.999, THE INPUT WOULD BE 999
//note the custom temperature has an upper bound because it is turned into an int before a double

//THE PROGRAM WILL CONSTANTLY OUTPUT THE NUMBER OF TIMES S <- Si, the number of times it updated the best tour list
//IT WILL ALSO INPUT THE NUMBER OF REJECTED TOURS BEFORE UPDATING THE TOUR LIST
//IT WILL ALSO OUTPUT THE CURRENT TEMPERATURE
//THE PROGRAM STOPS LOOPING WHEN TEMPERATURE < 0.000001

// AFTER THE LOOP IS FINISHED, THE PROGRAM OUTPUTS TOTAL NUMBER OF GENERATED TOURS AND THE CURRENT BEST DISTANCE
// FOLLOWED BY THE CITIES IN THE ORDER THEY ARE VISITED, 1 CITY ON EACH LINE

int main(int argc, const char* argv[]){
ifstream input;
int numCities;
input.open("randTSP/problem36");
input>>numCities;
Node *n = new Node[numCities];


for(int i = 0; i < numCities; i++){ //MAKING NODES FROM THE INPUT FILE
string name;			//DEFAULT FILE IS THE 36 CITIES FILE
int x,y;
input >> name;
input >> x;
input >> y;
n[i]=Node(x,y,name);
}
if(argc ==1){ //DEFAULT ARGS
SA annealer(n,numCities,99999999999999999999999999.0,0.9999);
annealer.simulatedAnnealing();
annealer.printDist();
annealer.printCities();}

else if(argc == 3){//CUSTOM TEMP AND COOLING RATE
int tempt = atoi(argv[1]);
int temps = atoi(argv[2]);
double tempe = tempt;
double sched = temps;
int count = 0;

while(temps>0){ //SINCE CANT READ DOUBLES 
temps = temps/10;
count++;
}
for (int i = 0; i < count; i++){
sched = sched*0.1;
}


SA annealer(n,numCities,tempe,sched);
annealer.simulatedAnnealing();
annealer.printDist();
annealer.printCities();


}





};
