/*! @file CLogarithmic.cpp
	@brief Implementetion of class logarithmic
	@author Federico Maria Biasioli Loris Costanzo
*/
#include "CLogarithmic.h"

/// @brief defaul constructor
Logarithmic::Logarithmic()
{
	b_coeff=-1;
	k_coeff=0;
}

/// @brief constructor
/// @param b_coefficient Base of the logarithmic
/// @param k_coefficient Coefficient of the logarithmic
Logarithmic::Logarithmic(double b_coefficient, double k_coefficient)
{
	if(b_coefficient <= 0 || b_coefficient==1)
	{	
		ErrorMessage("Error with b_coefficient (b_coefficient can't be <=0)");
		Reset();
		exit(-1);
	}
	SetLogarithmic(b_coefficient, k_coefficient);
}

/** 
* @brief copy constructor
* @param l object to copy
*/
Logarithmic::Logarithmic(const Logarithmic& l)
{
	k_coeff = l.k_coeff;
    b_coeff = l.b_coeff;
}

/// @brief destructor
Logarithmic::~Logarithmic()
{
	Reset();
}

/** 
* @brief overload operator =
* @param l object to copy
* @return copy of the object
*/
Logarithmic& Logarithmic::operator=(const Logarithmic& l)
{
	k_coeff = l.k_coeff;
    b_coeff = l.b_coeff;
    return *this;
}

/** 
* @brief overload operator ==
* @param l object to check
* @return true o false
*/
bool Logarithmic::operator==(const Logarithmic& l)
{
	if(b_coeff!=l.b_coeff)
    {
        return false;
    }
    if(k_coeff!=l.k_coeff)
    {
        return false;
    }
    return true;
}

/** 
* @brief set the coefficient of the logarithmic
* @param b_coefficient base of the logarithmic
* @param k_coefficient coefficient of the logarithmic
*/
void Logarithmic::SetLogarithmic(double b_coefficient, double k_coefficient)
{
	k_coeff = k_coefficient;
	b_coeff = b_coefficient;
}

/**
 * @brief return the result of the logarithmic
 * @param in argument of the logarithmic
 * @return result of the logarithmic
 */ 
double Logarithmic::GetValue(double in)
{
	double result;
	if( in <= 0)
	{
		ErrorMessage("Argument can't be (<= 0)");
		return 0;
	}
	result= k_coeff*(log(in) / log(b_coeff));
	return result;
}

/**
 * @brief reset the logarithmic
 */
void Logarithmic::Reset()
{
	b_coeff = -1;
	k_coeff = 0;
}

/**
 * @brief write an error message 
 * @param string message to print
 */
void Logarithmic::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Logarithmic --";
	cout << string << endl;

}

/**
 * @brief write a warning message
 * @param string message to print
 */ 
void Logarithmic::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Logarithmic --";
	cout << string << endl;

}

/**
 * @brief return the state of the object
 */ 
void Logarithmic::Dump() {
	if (b_coeff == -1) {
		cout << "Uninitialized Power" << endl;
		return;
	}
	cout << "Base del logaritmo: " << b_coeff << endl;
    cout << "Coefficiente del logaritmo: " << k_coeff <<endl;
	cout << endl;
}