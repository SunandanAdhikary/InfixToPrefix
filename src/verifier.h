/*
 * verifier.h
 *
 *  Created on: 06-June-2018
 *      Author: sunandan
 */

#ifndef UTILITIES_VERIFIER_H_
#define UTILITIES_VERIFIER_H_

#include <iostream>
#include "./InToPre.h"
#include <boost/algorithm/string.hpp> //string comparison
#include "node.h"
#include <boost/tokenizer.hpp>

/* Module to populate details of the plant model from HASLAC into hybrid_automata class
 * control_vars: is the control variables of the plant
 * uncontrol_vars: is the uncontrol or the input variables of the plant which is modified by the Controller-Program
 *
 * */

std::string InfixToPrefix(std::string i);
#endif /* UTILITIES_VERIFIER_H_ */
