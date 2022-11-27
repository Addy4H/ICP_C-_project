#include "Airline.h"
#include "Route.h"
#include "Airport.h"
#include "FileReader.h"
#include "FindRoute.h"
#include <iostream>
#include <fstream>
int main(){
    // Airline a1 = Airline("324","All Nippon Airways","ANA All Nippon Airways","NH","ANA","ALL NIPPON","Japan","Y");
    // Route r1 = Route("BA","1355","SIN","3316","MEL","3339","Y","0","744");
    // Airport air1 = Airport("507","London Heathrow Airport","London","United Kingdom","LHR","EGLL","51.4706","-0.461941","83","0","E","Europe/London","airport","OurAirports");

    // //  cout << air1.toString() << endl << endl;

    // // cout << r1.toString() << endl << endl;

    // // cout << air1.toString() << endl;
    // FileReader reader = FileReader("accra-winnipeg.txt");
    // reader.readAllFiles();
    FindRoute routePath = FindRoute("accra-winnipeg.txt");
    // routePath.actions("YWG");
    // cout << routePath.isGoal("YWG");
    // u

    return 0;
}