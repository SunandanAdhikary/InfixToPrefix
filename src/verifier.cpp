/*
 * verifier.cpp
 *
 *  Created on: 06-june-2018
 *      Author: sunandan
 */
#include "node.h"
#include "verifier.h"
#include <iostream>
#include <stdio.h>
#include <boost/algorithm/string.hpp>
#include <string>
#include <iterator>
#include "InToPre.h"
#include <boost/tokenizer.hpp>



//#define MAIN_DEBUG_ON

using namespace std;

std::string InfixToPrefix(std::string s){
	std::string st;
	std::string s1 = s.substr(s.find("==")+2);							//RHS i.e. equation part (infix format)
	std::string s2 = "(= d/dt[" + s.substr(0,s.find("\'")) + "] ";		//LHS i.e. Variable,which has flow (infix format)
	vector<string> infix, prefix;
	typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
	boost::char_separator<char> sep{" ","+-/^$*)("};
	tokenizer tok{s1, sep};
	for (tokenizer::iterator t = tok.begin(); t != tok.end(); t++){
		 infix.push_back(string(*t));
//		 std::cout<<*t<<endl;
	}
	prefix.resize(infix.size());
	infixtoprefix(infix, prefix);										//converting RHS in postfix format
//	std::reverse(begin(prefix),end(prefix));
	for(string c:prefix){
		cout<<"after unary: "<<c<<endl;
		st +=c;
	}
	st = parenthesize(prefix);
//	std::cout<<"After parenthesis = " <<st<<std::endl;
	return s2+st+")";														//Returning LHS and RHS in prefix format

}

int main(){
	std::string s="p_throttle_flow' == (2 * ((2.821 + ((-0.05231)*p_throttle_angle) + ((0.10299)*p_throttle_angle*p_throttle_angle)) + ((-0.00063)*p_throttle_angle*p_throttle_angle*p_throttle_angle)) * ( ((-2.3421)*p_manifold_pressure*p_manifold_pressure)+(2.7799*p_manifold_pressure)+(-0.3273)))" ;
//	std::string s="p_throttle_flow' == (2*(((-2.3421)*p*p)+(2.7799*p)+(-3)))";
	std::cout<<"\t prefix of "<<s<<" :"<<endl<<InfixToPrefix(s)<<std::endl;
//"a' == a+2/(0.5*b)-2*b"  ||  i' == ( -K / L ) * angVal - ( R / L ) * i + ( voltage / L ) ||
//p'= c1 * ((2 * (c6 + c7*theta + c8*theta*theta + c9*theta*theta*theta) * (c20*p*p+c21*p+c22)) - (c12 * (c2 + c3*w*p + c4*w*p*p + c5*w*w*p))
//ddt p_throttle_flow = (2 * ((2.821 + ((-0.05231)*p_throttle_angle) + ((0.10299)*p_throttle_angle*p_throttle_angle)) + ((-0.00063)*p_throttle_angle*p_throttle_angle*p_throttle_angle)) * ( ((-2.3421)*p_manifold_pressure*p_manifold_pressure)+(2.7799*p_manifold_pressure)+(-0.3273))) ;
//
	return 0;
}

