#pragma once
#include <iostream>
using namespace std;

/**
 * @author Adelle Haford
 * This class represents a route between two airports
*/

class Route{
    private:
        string airlineCode;
        string airlineId;
        string sourceAirportCode;
        string sourceAirportId;
        string destinationAirportCode;
        string destinationAirportId;
        string codeshare;
        string stops;
        string equipment;
    public:
        Route(string, string, string, string, string, string, string, string, string);
        string getAirlineCode();
        string getSourceAirportCode();
        string getDestinationAirportCode();
        string getStops();
        string toString();
};

Route::Route(string code, string id, string sourcePortCode, string sourcePortId,
string destinationPortCode, string destinationPortID, string operated, string numOfStops, string equip){
    this -> airlineCode = code;
    this -> airlineId = id;
    this -> sourceAirportCode = sourcePortCode;
    this -> sourceAirportId = sourcePortId;
    this -> destinationAirportCode = destinationPortCode;
    this -> destinationAirportId = destinationPortID;
    this -> codeshare = operated;
    this -> stops = numOfStops;
    this -> equipment = equip;
}

/**
 * This function returns the airline code of the flight
*/
string Route::getAirlineCode(){return airlineCode;}

/**
 * This function returns the code for the source airport
*/
string Route::getSourceAirportCode(){return sourceAirportCode;}

/**
 * This function returns the code for the destination airport
*/
string Route::getDestinationAirportCode(){return destinationAirportCode;}

/**
 * This function returns the number of stops on the route
*/
string Route::getStops(){return stops;}

/**
 * This function returns a string representation of a route object
*/
string Route::toString(){
    return "Route{airlineCode='" + airlineCode + '\'' +
                ", airlineId='" + airlineId + '\'' +
                ", sourceAirportCode='" + sourceAirportCode + '\'' +
                ", sourceAirportId='" + sourceAirportId + '\'' +
                ", destinationAirportCode='" + destinationAirportCode + '\'' +
                ", destinationAirportId='" + destinationAirportId + '\'' +
                ", codeshare='" + codeshare + '\'' +
                ", stops='" + stops + '\'' +
                ", equipment='" + equipment + '\'' +
                '}';
}