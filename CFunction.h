/*! @file CFunction.h
	@brief A virtual base class for functions of a single variable
	@author Federico Maria Biasioli Costanzo Lorenzo
*/ 

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Function {
	
		
public:
    
	/// @name Costruttori/Distruttore
	/// @{
    Function(){};
    virtual ~Function(){};
	/// @}

	/// @name Getter
	/// @{
	virtual double GetValue(double in)=0;
	/// @}

	/// @name Debug 
	/// @{
	virtual void Dump()=0;
	/// @}

    
};

#endif