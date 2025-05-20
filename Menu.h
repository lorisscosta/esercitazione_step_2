/*! @file FunctionManager.h
    @brief Gestore delle funzioni matematiche
    @author Federico Maria Biasioli Loris Costanzo
*/

#ifndef MENU_H
#define MENU_H

#include <vector>
#include "CFunction.h"
#include "CLogarithmic.h"
#include "CPower.h"

/// @class FunctionManager
/// @brief Gestisce una lista dinamica di funzioni matematiche
class FunctionManager
{
private:
    std::vector<Function *> functions;

public:
    /// @name Constructors and Destructor
    /// @{
    FunctionManager();
    ~FunctionManager();
    /// @}

    /// @name Functions
    /// @{
    /// @brief Mostra la lista di tutte le funzioni registrate
    void VisualizzaFunzioni() const;

    /// @brief Inserisce una nuova funzione dall'input utente
    void InserisciFunzione();

    /// @brief Elimina una funzione tramite ID
    /// @param id Indice della funzione da eliminare
    void EliminaFunzione(int id);

    /// @brief Elimina tutte le funzioni registrate
    void EliminaTutte();
    
    /// @brief Seleziona una funzione ed esegue il calcolo per un dato x
    void SelezionaFunzione();
    ///@}

    /// @name Basic function
    /// @{
    /// @brief Avvia il menu principale interattivo
    void MenuPrincipale();
    ///@}
};

#endif
