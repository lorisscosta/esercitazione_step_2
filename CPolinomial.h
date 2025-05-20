/*! @file CPolinomial.h
	@brief file h for class polinomial
	@author Federico Maria Biasioli Loris Costanzo
*/ 

#ifndef POLINOMIAL_H
#define POLINOMIAL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;
/// @class Polinomial
/// @brief class polinomial
class Polinomial:public Function {
private:
    double* coeff;  											
    int degree; 												

public:
	/// @name Constructors and Destructor 
	/// @{
    Polinomial();  
	Polinomial(const double* coefficients, int size); 			
    Polinomial(const Polinomial& p); 							
    ~Polinomial();												
	/// @}

	/// @name Operators
	/// @{
    Polinomial& operator=(const Polinomial& p); 				
	Polinomial operator+(const Polinomial& p); 					
	bool operator==(const Polinomial& p); 						
	/// @}

	///@name Setter
	///@{
	void SetPolinomial(const double* coefficients, int size);	
	/// @}

	///@name Getter
	///@{
    double GetValue(double in);							
	/// @}
	
	/// @name Basic function
    /// @{
	void Reset();												
	/// @}

	/// @name Debug e serialization
	/// @{
	void ErrorMessage(const char *string); 						
	void WarningMessage(const char *string);					
	void Dump();												
	/// @}
};

#endif