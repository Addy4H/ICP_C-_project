#pragma once
#include <vector>
#include <iostream>


/**
 * @author Adelle Hasford
 * This class represents information about a route. Used in the search tree algorithm
*/
class Node{
    private:
        string state;
        string parent;
        string airlineCode;
        string numOfStops;

    public:
    Node(string);
    Node(string, string, string, string);
    string getState();
    string getParent();
    string getAirlineCode();
    string getNumOfStops();
    bool operator==(Node);

};

/**
 * Creating instances of root nodes for the search tree
 * @param current passes in the state of the node
*/
Node::Node(string current){
    this -> state = current;
    this -> parent = "";
    this -> airlineCode = "";
    this -> numOfStops = "0";
};

Node::Node(string current, string predecessor, string code, string stops){
    this -> state = current;
    this -> parent = predecessor;
    this -> airlineCode = code;
    this -> numOfStops = stops;
}

/**
 * This function returns the state of the node
*/
string Node::getState(){
    return state;
}

/**
 * This function returns the parent of the node
*/
string Node::getParent(){
    return parent;
}

/**
 * This function returns the airline code of the node
*/
string Node::getAirlineCode(){
    return airlineCode;
}

/**
 * This function returns the number of stops for the node
*/
string Node::getNumOfStops(){
    return numOfStops;
}

/**
 * This function defines the equality operation for the node
*/
bool Node::operator==(Node other){
    return state == other.state;
}
