/*! @file CPolinomial.cpp
 	@brief Implementation of class CPolinomial.h
	@author Federico Maria Biasioli Loris Costanzo
*/ 
#include "CPolinomial.h"

/**
 * @brief default constructor
 */
Polinomial::Polinomial() {
	degree=-1;
	coeff = NULL;
}


/**
 * @brief constructor
 * @param coefficients array with coefficients
 * @param size array size
 */
Polinomial::Polinomial(const double* coefficients, int size) {
	degree = -1;
	coeff = NULL;
	SetPolinomial(coefficients,size);
}

/**
 * @brief destructor
 */
Polinomial::~Polinomial() {
    
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/**
 * @brief copy constructor
 */
Polinomial::Polinomial(const Polinomial& p) {
	
	int i;
	
	if (p.coeff == NULL) {
		ErrorMessage("Copy constructor: the object to be copied has no coefficients");
		exit(-1);
	}
	degree = p.degree;
	coeff = new double[degree + 1];
	if (coeff == NULL) {
		ErrorMessage("Copy constructor: cannot allocate memory");
		exit(-1);
	}
	
    for (i=0;i<=degree;i++)
		coeff[i]= p.coeff[i];
}

/**
 * @brief overload operator =
 * @param p object to copy
 * @return copy of the object
 */
Polinomial& Polinomial::operator=(const Polinomial& p) {
    
	int i; 
	
	if (this != &p) {
		if (coeff != NULL)
			delete coeff;
        degree = p.degree;
        coeff = new double[degree + 1];
		if (coeff == NULL) {
			ErrorMessage("Operator =: cannot allocate memory");
			exit(-1);
		}
        for (i=0;i<=degree;i++)
			coeff[i]= p.coeff[i];
    }
    return *this;
}

/// @brief overload operator ==
bool Polinomial::operator==(const Polinomial& p) {
	
	int i;
	
	if (degree != p.degree)
		return false;
	
	for (i=0; i<=degree; i++) {
		if (coeff[i] != p.coeff[i])
			return false;
	}
	
	return true;
	
}

/**
 * @brief set the coefficients of the polinomial
 * @param coefficients array with coefficients (format: c0+c1*x+ ...)
 * @param size size of the array
 */
void Polinomial::SetPolinomial(const double* coefficients, int size) {
	
	int i=0;
	
	if (size < 1) {
		ErrorMessage("SetPolinomial: the degree of the Polinomial cannot be negative");
		exit(-1);
	}
	
	if (coeff != NULL)
		Reset();
	
	degree = size - 1;
    coeff = new double[size]; // restituisce double* dove 
	if (coeff == NULL) {
		ErrorMessage("SetPolinomial: cannot allocate memory");
		exit(-1);
	}
	
	for (i=0; i<=degree; i++)
		coeff[i] = coefficients[i];
	
}

/**
 * @brief return the result of the polinomial
 * @param in input
 * @return value of the polinomial
 */
double Polinomial::GetValue(double in) {
    int i;
	double x = in;
	double result = 0.0;
        
	result = coeff[0];
	for (i=1; i<=degree; i++) {
		result += coeff[i]*x;
		x *= in;			/* x^i */
	}
        
	return result;
}

/**
 * @brief reset the polinomial
 */ 
void Polinomial::Reset() {
	
	degree = -1; 
	if (coeff != NULL) {
		delete coeff;
		coeff = NULL;
	}
}

/**
 * @brief write an error message 
 * @param string message to print
 */
void Polinomial::ErrorMessage(const char *string) {
	
	cout << endl << "ERROR -- Polinomial --";
	cout << string << endl;

}

/**
 * @brief write an warning message
 * @param string message to print
 */ 
void Polinomial::WarningMessage(const char *string) {
	
	cout << endl << "WARNING -- Polinomial --";
	cout << string << endl;

}

/**
 * @brief print the object
 */ 
void Polinomial::Dump() {

	int i;
	
	if (degree == -1) {
		cout << "Uninitialized Polinomial" << endl;
		return;
	}
	
	if (coeff == NULL) {
		cout << "Degree: " << degree << endl;
		cout << "No coefficients available" << endl;
		return;
	}
	
    for (i = 0; i <= degree; ++i) {
		if (coeff[i] != 0.) {
			cout << (coeff[i] > 0 && i > 0 ? " +" : " ") << coeff[i];
            if (i > 0) {
                cout << "x";
                if (i > 1) 
                    cout << "^" << i;
            }
        }
    }
	cout << endl;
}