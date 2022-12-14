#pragma once
#include <iostream>
using namespace std;

/**
 * @author Adelle Hasford
 * This class is representation of an airline
*/

class Airline{
    private:
        string airlineId;
        string name;
        string alias;
        string iataCode;
        string icaoCode;
        string callsign;
        string country;
        string active;

    public:
        Airline(string, string, string, string, string, string, string, string);
        string getAirlineId();
        string getIataCode();
        string getCountry();
        string toString();
};

Airline::Airline(string airlineID, string airline, string airlineAlias, string airlineIATA,
string airlineICAO, string airlineCallsign, string airlineCountry, string status){
    this -> airlineId = airlineID;
    this -> name = airline;
    this -> alias = airlineAlias;
    this -> iataCode = airlineIATA;
    this -> icaoCode = airlineICAO;
    this -> callsign = airlineCallsign;
    this -> country = airlineCountry;
    this -> active = status;
}

/**
 * This function returns the airlineId of the airline
*/
string Airline::getAirlineId(){return airlineId;}

/**
 * This function returns the IATA code of the airline
*/
string Airline::getIataCode(){return iataCode;}

/**
 * This function returns the territory (country) of the airport
*/
string Airline::getCountry(){return country;}


/**
 * This function returns the string representation of an airline object
*/
string Airline::toString(){
    return "Airline{airlineId=' " + airlineId + '\'' +
                ", name='" + name + '\'' +
                ", alias='" + alias + '\'' +
                ", iataCode='" + iataCode + '\'' +
                ", icaoCode='" + icaoCode + '\'' +
                ", callsign='" + callsign + '\'' +
                ", country='" + country + '\'' +
                ", active='" + active + '\''
                + "}";
}