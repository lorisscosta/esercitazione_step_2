/*! @file CLogarithmic.h
	@brief file h for class logarithmic
	@author Federico Maria Biasioli Loris Costanzo
*/

#ifndef LOGARITHMIC_H
#define LOGARITHMIC_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"
/// @class Logarithmic
/// @brief Class logarithmic
class Logarithmic : public Function
{
private:
	double b_coeff;
	double k_coeff;

public:
	/// @name Operator
	/// @{
	Logarithmic &operator=(const Logarithmic &l);
	bool operator==(const Logarithmic &l);
	///@}

	/// @name Constructors and Destructor 
	/// @{
	Logarithmic();
	Logarithmic(double b_coefficient, double k_coefficient);
	Logarithmic(const Logarithmic &l);
	~Logarithmic();
	///@}

	///@name Setter
	///@{
	void SetLogarithmic(double b_coefficient, double k_coefficient);
	///@}

	///@name Basic fuction
	///@{
	void Reset();
	///@}

	///@name Getter
	///@{
	double GetValue(double in);
	///@}

	///@name Debug e serialization
	///@{
	void ErrorMessage(const char *string);
	void WarningMessage(const char *string);
	void Dump();
	///@}
};

#endif