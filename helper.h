#pragma once
#include <vector>
#include <unordered_map>
#include <iostream>
#include <deque>
#include "Node.h"

/**
 * This function checks if a value is in an unordered map
 * @param umap unordered map of key and value type string respectively
 * @param value value being searched for
*/
bool containsValue(unordered_map<string, string> umap, string value){
    for(auto x: umap){
        if(x.second == value){return true;}
    }
    return false;
}

/**
 * This function checks if a node is present in the frontier
 * @param front deque of nodes (frontier)
 * @param currNode node being searched for
*/
bool frontierContains(deque<Node> front, Node currNode){
    for(Node node: front){
        if(node == currNode){return true;}
    }
    return false;
}

/**
 * This function checks if a node is present in the explored list
 * @param explored list of nodes (explored list)
 * @param currNode node being searched for
*/
bool exploredContains(vector<Node> explored, Node currNode){
    for(Node node: explored){
        if(node == currNode){return true;}
    }
    return false;
}

