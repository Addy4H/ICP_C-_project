#pragma once
#include "FileReader.h"
#include "Route.h"
#include <unordered_map>
#include <vector>
#include <iostream>


/***
 * @author Adelle Hasford
 * This class is responsible for finding the route from the source to a destination using the breadth first search
 * algorithm
*/
class FindRoute{
    private:
        string inputFile;
        FileReader reader;
        bool isGoal(string);
        vector<Route> actions(string);

    public:
        FindRoute(string);
        

};

FindRoute::FindRoute(string input){
    this -> inputFile = input;
    this -> reader = FileReader(input);
    reader.readAllFiles();
}

/**
 * If the airport code of the current state is in the dictionary, then return true if the country and city of the current state
 * is the same as the destination country and city. Else, return false
 *
 * @param state current state of the search
*/
bool FindRoute::isGoal(string iataCode){
    if(reader.airportsToCountries.find(iataCode) == (reader.airportsToCountries).end()){
        return false;
    }
    return (reader.airportsToCountries.at(iataCode) == reader.destinationInfo);
}

/**
 * Given an airport, return all the routes that originate from that airport
 * 
 * @param state current state of the search
*/
vector<Route> FindRoute::actions(string iataCode){
    vector<Route> possibleActions;
    if(reader.routeMap.find(iataCode) != reader.routeMap.end()){
        possibleActions = reader.routeMap.at(iataCode);
    }

    return possibleActions;
}

