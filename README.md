# ICP_C-_project
Applies the use of C++ to map out the route between one city and another. 

C++ version: 11

Compiled with: Apple Clang version 14.0.0



## Description
The project makes use of the following data files airports.csv, airlines.csv and routes.csv. Information about these datasets can be retrieved from https://openflights.org/data.html



## Usage
To run this code, you may decide to use either one of the test files in the folder or you may create your own.

To create your input file you put in the name of the city and country you are travelling from and that of where you are headed. The content of the file would look something like this:

```txt
SourceCity, SourceCountry

DestinationCity, DestinationCountry
```

Be sure to place the empty space after the comma as seen above. The cities and countries should be written in title case. Save the file in the same file directory being used

To find the path, pass in the name of your text file (or one of the tests text files) as a string with no spaces after and an output file will be generated if there is indeed a route.

```c++
int main(){
    string file;
    cout << "Provide file name (eg: accra-winnipeg.txt): ";
    cin >> file;
    FindRoute routePath = FindRoute(file);
    routePath.findRoute();
    
    return 0;
}
```

```txt
// output if route is found
Finding route...
Found a solution! Check 'accra-winnipeg_output.txt' for the route

//output if there is no route
Finding route...
No such route exists

```

## Run
run ```main.exe```


All the best!!
