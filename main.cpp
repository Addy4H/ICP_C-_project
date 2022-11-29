#include "FindRoute.h"
#include <iostream>
#include <fstream>
int main(){
    string file;
    cout << "Provide file name (eg: accra-winnipeg.txt): ";
    cin >> file;
    FindRoute routePath = FindRoute(file);
    routePath.findRoute();
    
    return 0;
}