/*! @file CPower.h
    @brief File h for class power
    @author Federico Maria Biasioli Loris Costanzo
*/

#ifndef POWER_H
#define POWER_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"
/// @class Power
/// @brief Class for power
class Power : public Function
{
private:
    double k_coeff;
    double e_coeff;

public:
    /// @name Constructors and Destructor 
    /// @{
    Power();
    Power(double k_coeff, double e_coeff);
    Power(const Power &p);
    ~Power();
    /// @}

    /// @name Operators
    /// @{
    Power &operator=(const Power &p);
    bool operator==(const Power &p);
    /// @}

    /// @name Debug e serialization
    /// @{
    void Dump();
    /// @}

    ///@name Setter
    ///@{
    void SetPower(double k_coef, double e_coeff);
    ///@}

    ///@name Getter
    ///@{
    double GetValue(double in);
    ///@}

    /// @name Basic function
    /// @{
    void Reset();
    /// @}
};
#endif