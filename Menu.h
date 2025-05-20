/*! @file Menu.h
    @brief File .h for class Menu
    @author Federico Maria Biasioli Loris Costanzo
*/

#ifndef MENU_H
#define MENU_H

#include <vector>
#include "CFunction.h"
#include "CLogarithmic.h"
#include "CPower.h"
#include "CPolinomial.h"

/// @class Menu
/// @brief Class Menu
class Menu
{
private:
    std::vector<Function *> functions;

public:
    /// @name Constructors and Destructor
    /// @{
    Menu();
    ~Menu();
    /// @}


    /// @brief Show list of all stored functions
    void VisualizzaFunzioni() const;

    /// @brief Inserts a new user's input function
    void InserisciFunzione();

    /// @brief Delete a function by ID
    /// @param id input
    void EliminaFunzione(int id);

    /// @brief Delete all stored functions
    void EliminaTutte();
    
    /// @brief Select a function and calculate the result
    void SelezionaFunzione();
    ///@}

    /// @name Basic function
    /// @{
    /// @brief Launch the interactive main menu
    void MenuPrincipale();
    ///@}
};

#endif
