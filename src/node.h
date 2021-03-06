//
// Created by fedor on 02/02/17.
//

#ifndef PROBREACH_NODE_H
#define PROBREACH_NODE_H

#include <iostream>
#include <vector>

using namespace std;

class node {

protected:

    // either a name of operation or a value of the operand (const or identifier)
    string value;

    // vector is empty if the node is terminal and non-empty if the node is operation node
    vector<node> operands;

public:

    // default constructor
    node();

    // constructor creates a terminal node
    node(char);

    // constructor creates a terminal node
    node(string);

    // constructor creates an operation node
    node(char, vector<node>);

    // constructor creates an operation node
    node(string, vector<node>);

    //adds value to value variable
    void addVal(string);

    // appends node to the list of operands in the current node
    void append(node);

    // appends a list of nodes to the list of operands in the current node
    void append(vector<node>);

    // returns true if the node does not have operands and false otherwise
    bool is_terminal();

    // returns true if the the first character in the string representing
    // the node value is a digit
    bool is_number();

    // returns true if the node does not have operands and its value is an empty string
    // and false otherwise
    bool is_empty();

    // returns a string representation of the node in infix notation
    string to_infix();

    // returns a string representation of the node in infix notation
    // where each variable is appended with the specified string
    string to_infix(string);

    // returns a string representation of the node in prefix notation
    string to_prefix();

    // returns a string representation of the node in prefix notation
    // where each variable is appended with the specified string
    string to_prefix(string);

    friend std::ostream& operator<<(std::ostream&, const node&);
    friend bool operator==(const node&, const node&);

    // returns the node's value
    string get_value() const;

    // returns list of node's operands
    vector<node> get_operands() const;

};


#endif //PROBREACH_NODE_H
