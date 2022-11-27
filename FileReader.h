#pragma once
#include "Airline.h"
#include "Airport.h"
#include "Route.h"
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


/**
 * @author Adelle Hasford
 * This class reads information from an input file, an airport file, a route file and an airline
 * file.
*/

class FileReader{
    private:
        // files to be read
        string inputFile;
        // string airportFile;
        // string airlineFile;
        // string routeFile;

        //readfile
        void readRoutes();
        void readAirports();
        void readAirlines();
        void readInputFile();


    public:
        unordered_map<string, vector<Airline> > airlineMap;
        unordered_map<string, vector<Airport> > airportMap;
        unordered_map<string, vector<Route> > routeMap;

        unordered_map<string, string> airportsToCountries;
        unordered_map<string, Airport> iataToAirports;

        
        string sourceInfo;
        string destinationInfo;
        FileReader();
        FileReader(string);
        void readAllFiles();
        

};


FileReader::FileReader(){};


FileReader::FileReader(string input){
    this -> inputFile = input;
    // this -> airportFile = airport;
    // this -> airlineFile = airline;
    // this -> routeFile = route;
}


/**
 * This function reads the route file and creates a map of routes with the key being the source Airport code
*/
void FileReader::readRoutes(){
    string line;
    ifstream routeFile; 

    routeFile.open("routes.csv");
    getline(routeFile, line); // skip the first line

    while(getline(routeFile, line)){
        vector<string> routeStr;
        stringstream ss(line);

        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            routeStr.push_back(substr);
        }
        if(routeStr.size() == 9){
            Route route = Route(routeStr[0], routeStr[1], routeStr[2], routeStr[3], routeStr[4], routeStr[5], 
            routeStr[6], routeStr[7], routeStr[8]);
            string routeKey = routeStr[2];

            //matching all routes to their source airport codes
            if(routeMap.find(routeKey) == routeMap.end()){
                vector<Route> routes;
                routes.push_back(route);
                routeMap.insert(make_pair(routeKey, routes));
            }
            else{
                routeMap.at(routeKey).push_back(route);
            }
        }    
    }

    routeFile.close();

}

/**
 * This function reads the airline file and creares a map of airline objects where the key is the country and 
 * the values is a vector of airline objects
*/
void FileReader::readAirlines(){
    string line;
    ifstream airlineFile;

    airlineFile.open("airlines.csv");
    getline(airlineFile, line); // skips the first line

    while(getline(airlineFile, line)){
        vector<string> airlineStr;
        stringstream ss(line);

        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            airlineStr.push_back(substr);
        }
        if(airlineStr.size() == 8){
            Airline airline = Airline(airlineStr[0], airlineStr[1], airlineStr[2], airlineStr[3],
            airlineStr[4], airlineStr[5], airlineStr[6], airlineStr[7]);
            string airlineKey = airlineStr[6];

            if(airlineMap.find(airlineKey) == airlineMap.end()){
                vector<Airline> airlines;
                airlines.push_back(airline);
                airlineMap.insert(make_pair(airlineKey, airlines));
            }
            else{
                airlineMap.at(airlineKey).push_back(airline);
            }
        }
    }
    airlineFile.close();
}

/**
 * This function reads the airport file and creates a map of airport objects with the key 
 * being the airpot country and city name, with the value being a vector of airport objects
 * Also creates a mapping or airport IATA codes to airport objects and IATA codes to city and country name
*/
void FileReader::readAirports(){
    string line;
    ifstream airportFile; 

    airportFile.open("airports.csv");
    getline(airportFile, line); // skip the first line

    while(getline(airportFile, line)){
        vector<string> airportStr;
        stringstream ss(line);

        while(ss.good()){
            string substr;
            getline(ss, substr, ',');
            airportStr.push_back(substr);
        }
        if(airportStr.size() == 14){
            Airport airport = Airport(airportStr[0], airportStr[1], airportStr[2], airportStr[3], airportStr[4], airportStr[5], 
            airportStr[6], airportStr[7], airportStr[8], airportStr[9], airportStr[10], airportStr[11], airportStr[12], airportStr[13]);
            string airportKey = airportStr[2] + ", " + airportStr[3];
            string acdKey = airportStr[4];

            if(acdKey != "\\N"){
                airportsToCountries.insert(make_pair(acdKey,airportKey));
                iataToAirports.insert(make_pair(acdKey,airport));
            }

            //matching all routes to their source airport codes
            if(airportMap.find(airportKey) == airportMap.end()){
                vector<Airport> airports;
                airports.push_back(airport);
                airportMap.insert(make_pair(airportKey, airports));
            }
            else{
                airportMap.at(airportKey).push_back(airport);
            }
        }    
    }

    airportFile.close();

}

/**
 * This function reads the input file and stores the source and destination information in the sourceInfo and destinationInfo variables
*/
void FileReader::readInputFile(){
    string line;
    ifstream file;

    file.open(inputFile);

    getline(file, sourceInfo);
    getline(file, destinationInfo);

    file.close();
}


void FileReader::readAllFiles(){
    readRoutes();
    readAirlines();
    readAirports();
    readInputFile(); 

}
