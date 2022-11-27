#pragma once
#include <iostream>
using namespace std;

/**
 * @author Adelle Hasford
 * This class represents an airport
*/

class Airport{
    private:
        string airportId;
        string name;
        string city;
        string country;
        string iataCode;
        string icaoCode;
        string latitude;
        string longitude;
        string altitude;
        string timezone;
        string daylightSavingsTime;
        string databaseTimeZone;
        string type;
        string sourceData;

    public:
        Airport(string, string, string, string, string, string, string, string, 
        string, string, string, string, string, string);
        string getCity();
        string getCountry();
        string getIataCode();
        string toString();

};

Airport::Airport(string id, string airportName, string airportCity, string airportCountry, string airportIATA, string airportICAO, 
string lat, string log, string alt, string tz, string daylight, string dbTz, string airportType, string source){
    this -> airportId = id;
    this -> name = airportName;
    this -> city = airportCity;
    this -> country = airportCountry;
    this -> iataCode = airportIATA;
    this -> icaoCode = airportICAO;
    this -> latitude = lat;
    this -> longitude = log;
    this -> altitude = alt;
    this -> timezone = tz;
    this -> daylightSavingsTime = daylight;
    this -> databaseTimeZone = dbTz;
    this -> type = airportType;
    this -> sourceData = source;
}

/**
 * This function returns the main Airport city
*/
string Airport::getCity(){return city;}

/**
 * This function returns the territory(country) of the airport
*/
string Airport::getCountry(){return country;}

/**
 * This function returns the IATA code of the airport
*/
string Airport::getIataCode(){return iataCode;}

/**
 * This function returns a string representation of a route object
*/
string Airport::toString(){
    return "Airport{airportId='" + airportId + '\'' +
                ", name='" + name + '\'' +
                ", city='" + city + '\'' +
                ", country='" + country + '\'' +
                ", iataCode='" + iataCode + '\'' +
                ", icaoCode='" + icaoCode + '\'' +
                ", latitude=" + latitude +
                ", longitude=" + longitude +
                ", altitude=" + altitude +
                ", timezone=" + timezone +
                ", daylightSavingsTime='" + daylightSavingsTime + '\'' +
                ", databaseTimeZone='" + databaseTimeZone + '\'' +
                ", type='" + type + '\'' +
                ", sourceData='" + sourceData + '\'' +
                '}';
}