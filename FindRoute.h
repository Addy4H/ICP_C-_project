#pragma once
#include "FileReader.h"
#include "Route.h"
#include "Airport.h"
#include "Node.h"
#include "helper.h"
#include <unordered_map>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>



/***
 * @author Adelle Hasford
 * This class is responsible for finding the route from the source to a destination using the breadth first search
 * algorithm
*/
class FindRoute{
    private:
        string inputFile;
        
        vector<Node> exploredNodes;
        FileReader reader;

        bool isGoal(string);
        vector<Route> getRoutes(string);
        deque<Node> solutionPath(Node);
        deque<Node> breadthFirstSearch();
        void writeOutputToFile();
        

    public:
        FindRoute(string);
        void findRoute();
        

};

FindRoute::FindRoute(string input){
    this -> inputFile = input;
    this -> reader = FileReader(input);
    reader.readAllFiles();
}

/**
 * If the airport code of the current state is in the dictionary, then return true if the country and city of 
 * the current state is the same as the destination country and city. Else, return false
 *
 * @param iataCode current state of the search
*/
bool FindRoute::isGoal(string state){
    if(reader.airportsToCountries.find(state) == (reader.airportsToCountries).end()){
        return false;
    }
    return (reader.airportsToCountries.at(state) == reader.destinationInfo);
}

/**
 * Given an airport, return all the routes that originate from that airport
 * 
 * @param state current state of the search
*/
vector<Route> FindRoute::getRoutes(string state){
    vector<Route> availableRoutes;
    if(reader.routeMap.find(state) != reader.routeMap.end()){
        availableRoutes = reader.routeMap.at(state);
    }

    return availableRoutes;
}

/**
 * This function returns the solution path as a sequence of nodes (route sequence)
 * @param currentNode node being considered
*/
deque<Node> FindRoute::solutionPath(Node currentNode){
    deque<Node> routeSeqeunce;
    routeSeqeunce.push_front(currentNode);

    while(currentNode.getParent() != ""){
        for(Node node: exploredNodes){
            if(node.getState() == currentNode.getParent()){
                routeSeqeunce.push_front(node);
                currentNode = node;
            } 
        }
    }

    routeSeqeunce.pop_front(); //getting rid of the last node

    return routeSeqeunce;

}

/**
 * This function takes in a source location and a destination. Uses the breadth first search algorithm to find the 
 * shortest path between two airports
*/
deque<Node> FindRoute::breadthFirstSearch(){
    string source = reader.sourceInfo;
    deque<Node> frontier;

    // ensure that a route exists in the route file
    if(containsValue(reader.airportsToCountries, source)){
        vector<Airport> airports = reader.airportMap.at(source);

    // for all available airports in the source city and country, create a root node (source airport)
        for(Airport airport: airports){
            frontier.push_back(Node(airport.getIataCode()));
        }
    }

    while(!frontier.empty()){
        Node currNode= frontier.front(); //returns the first node 
        frontier.pop_front(); // deleting the first node from the frontier
        exploredNodes.push_back(currNode); //explored states stored here

        vector<Route> availableRoutes = getRoutes(currNode.getState()); // possible routes from this airport

        for(Route route: availableRoutes){
            if(reader.iataToAirports.find(route.getDestinationAirportCode()) == reader.iataToAirports.end()){
                continue;
            }
            // creating childNodes (destination airports) if they exist
            Airport newAirport = reader.iataToAirports.at(route.getDestinationAirportCode());
            Node childNode = Node(newAirport.getIataCode(), currNode.getState(), route.getAirlineCode(), route.getStops());

            if(!exploredContains(exploredNodes, childNode) && !frontierContains(frontier, childNode)){
                // check for a goal once child node is generated
                if(isGoal(childNode.getState())){
                    return solutionPath(childNode);
                }

                // add child node to the frontier to generate destination nodes
                frontier.push_back(childNode);
            }
        }
    }
    deque<Node> nothing;  //empty deque if there is no solution
   return nothing;

}

/**
 * This function takes the route path returned by the breadth first search algorithm and write it to a file 
*/
void FindRoute::writeOutputToFile(){
    cout << "Finding route..." << endl;
    deque<Node> routePath = breadthFirstSearch();

    stringstream ss(inputFile);
    string filename;
    getline(ss, filename, '.');
    string outputFileName = filename + "_output.txt";

    ofstream outputFile(outputFileName);
    if(!routePath.empty()){
        cout << "Found a solution! Check '" << outputFileName << "' for the route" << endl;
        int totalStops = 0;
        int numList = 0;

        for(Node node: routePath){
            totalStops += stoi(node.getNumOfStops());
            string message = node.getAirlineCode() + " from " + node.getParent() + " to " + node.getState() + " " + node.getNumOfStops() + " stops";
            numList += 1;
            outputFile << numList << ". " << message << "\n";
            
        }
        outputFile << "Total flights: " << numList << "\n";
        outputFile << "Total additional stops: " << totalStops << "\n";
        outputFile << "Optimality criteria: flights" << "\n";
    }
    else{
        cout << "No such route exists" << endl;
    }
    outputFile.close();
}

/**
 * This function drives the route finding class
*/
void FindRoute::findRoute(){
    writeOutputToFile();
}
