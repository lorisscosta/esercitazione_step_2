/*! @file CPower.cpp
    @brief Implementetion of class power
    @author Federico Maria Biasioli Loris Costanzo
*/

#include "CPower.h"

/// @brief defaul constructor
Power::Power(){
    e_coeff=-0.00001;
    k_coeff=0;
}

/// @brief constructor
/// @param e_coeff exponent
/// @param k_coeff coefficient of the power
Power::Power(double e_coefficient, double k_coefficient){
    e_coeff=0;
    k_coeff=0;
    SetPower(e_coefficient,k_coefficient);
}

/** 
* @brief copy constructor
* @param p object to copy
*/
Power::Power(const Power& p){
    e_coeff = p.e_coeff;
    k_coeff = p.k_coeff;
}

/// @brief destructor
Power::~Power(){
    Reset();
}

/** 
* @brief overload operator =
* @param p object to copy
* @return copy of the object
*/
Power& Power::operator=(const Power& p){
    e_coeff = p.e_coeff;
    k_coeff = p.k_coeff;
    return *this;
}

/** 
* @brief overload operator ==
* @param p object to check
* @return true o false
*/
bool Power::operator==(const Power& p){
    if(e_coeff!=p.e_coeff)
    {
        return false;
    }
    if(k_coeff!=p.k_coeff)
    {
        return false;
    }
    return true;
}

/** 
* @brief set the value of the power
* @param e_coeff exponent
* @param k_coeff coefficient of the power
*/
void Power::SetPower(double new_k_coeff, double new_e_coeff)
{
    if(e_coeff!=-0.00001)
    {
        Reset();
    }
    e_coeff=new_e_coeff;
    k_coeff=new_k_coeff;
}

/**
 * @brief reset the power
 */
void Power::Reset(){
    e_coeff=-0.00001;
    k_coeff=0;
}

/**
 * @brief return the state of the object
 */ 
void Power::Dump() {

    if (e_coeff == -0.00001) {
		cout << "Uninitialized Power" << endl;
		return;
	}

	cout << "Potenza: " << e_coeff << endl;
    cout << "Coefficiente della potenza: " << k_coeff <<endl;
	cout << endl;
}

/**
 * @brief return the result
 * @param in base of the power
 * @return result of the power
 */ 
double Power::GetValue(double in){
    double result;
    double x=in;
    if(x==0&&e_coeff==0)
    {
        cout<<" Zero to the zero is an indeterminate form "<<endl;
        exit(-1);
    }
    int i;
    for(i=1;i<e_coeff;i++)
    {
        x=x*in;
    }
    result=x*k_coeff;
	return result;
}