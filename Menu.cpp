/*! @file Menu.cpp
    @brief Implementazione del gestore di funzioni
    @author Federico Maria Biasioli Loris Costanzo
*/

#include "Menu.h"
#include <iostream>
using namespace std;

/**
 * @brief default constructor
 */
Menu::Menu() {}

/**
 * @brief destructor
 */
Menu::~Menu()
{
    EliminaTutte();
}

/**
 * @brief show all the functions
 * @param coefficients array with coefficients (format: c0+c1*x+ ...)
 * @param size size of the array
 */
void Menu::VisualizzaFunzioni() const
{
    if (functions.empty())
    {
        cout << "Nessuna funzione presente.\n"
             << endl;
        return;
    }

    for (int i = 0; i < functions.size(); i++)
    {
        cout << "Funzioni disponibili:" << endl;
        cout << "Function numero [" << i + 1 << "]: " << endl;
        functions[i]->Dump();
    }
}

void Menu::InserisciFunzione()
{
    int scelta = -1;
    int conferma;
    Function *nuova = nullptr;
    do
    {
        cout << "Che tipo di funzione vuoi inserire?" << endl;
        cout << "0 - Uscita dall'inserimento" << endl;
        cout << "1 - Polinomiale" << endl;
        cout << "2 - Potenza" << endl;
        cout << "3 - Logaritmica" << endl;
        cout << "Scelta: " << endl;
        cin >> scelta;
        switch (scelta)
        {
        case 0:
            cout << "Uscita dall'inserimento." << endl;
            break;
            break;
        case 1:
            int grado;
            cout << "Grado del polinomio: " << endl;
            cin >> grado;
            double *pol_coeff = new double[grado + 1];
            for (int i = 0; i <= grado; i++)
            {
                cout << "Coefficiente di x^" << i << ": " << endl;
                cin >> pol_coeff[i];
            }
            nuova = new Polinomial(pol_coeff, grado + 1);
            cout << "Hai inserito:" << endl;
            nuova->Dump();
            cout << "Confermi?(1=Sì / 0=No):" << endl;
            cin >> conferma;
            if (conferma)
            {
                functions.push_back(nuova);
                cout << "Funzione registrata." << endl;
                delete nuova;
            }
            else
            {
                delete nuova;
                cout << "Funzione scartata." << endl;
            }
            delete pol_coeff;
            break;
        case 2:
            double pow_coeff, exp;
            cout << "Inserisci coefficiente: ";
            cin >> pow_coeff;
            cout << "Inserisci esponente: ";
            cin >> exp;
            nuova = new Power(pow_coeff, exp);
            cout << "Hai inserito:" << endl;
            nuova->Dump();
            cout << "Confermi?(1=Sì / 0=No):" << endl;
            cin >> conferma;
            if (conferma)
            {
                functions.push_back(nuova);
                cout << "Funzione registrata." << endl;
                delete nuova;
            }
            else
            {
                delete nuova;
                cout << "Funzione scartata." << endl;
            }
            break;
        case 3:
        {
            double base, log_coeff;
            cout << "Inserisci la base del logaritmo (diversa da 1 e > 0): ";
            cin >> base;
            cout << "Inserisci il coefficiente: ";
            cin >> log_coeff;
            nuova = new Logarithmic(base, log_coeff);
            cout << "Hai inserito:" << endl;
            nuova->Dump();
            cout << "Confermi?(1=Sì / 0=No):" << endl;
            cin >> conferma;
            if (conferma)
            {
                functions.push_back(nuova);
                cout << "Funzione registrata." << endl;
                delete nuova;
            }
            else
            {
                delete nuova;
                cout << "Funzione scartata." << endl;
            }
            break;
        }
        default:
            cout << "Scelta non valida." << endl;
        }
    } while (scelta != 0);
}

void Menu::EliminaFunzione(int id)
{
    VisualizzaFunzioni();
    int controllo = 0;
    int conferma;
    do
    {
        if (id < 0 || id >= (int)functions.size())
        {
            cout << "ID non valido." << endl;
            cout << "Inserire un nuovo ID:" << endl;
            cin >> id;
        }
        else
            controllo = 1;
    } while (controllo == 0);
    cout << "Funzione selezionata:" << endl;
    functions[id]->Dump();
    cout << "Confermi l'eliminazione? (1=Sì / 0=No): " << endl;
    cin >> conferma;

    if (conferma == 1)
    {
        delete functions[id];
        functions.erase(functions.begin() + id - 1);
        cout << "Funzione eliminata." << endl;
    }
    else
    {
        cout << "Eliminazione annullata." << endl;
    }
}

void Menu::EliminaTutte()
{
    for (Function *f : functions)
    {
        delete f;
    }
    functions.clear();
    cout << "Tutte le funzioni sono state eliminate." << endl;
}

void Menu::SelezionaFunzione()
{
    int id;
    int controllo;
    cout << "Inserisci ID della funzione: " << endl;
    cin >> id;
    do
    {
        if (id < 0 || id >= (int)functions.size())
        {
            cout << "ID non valido." << endl;
            cout << "Inserire un nuovo ID:" << endl;
            cin >> id;
        }
        else
            controllo = 1;
    } while (controllo == 0);
    functions[id]->Dump();
    double x;
    cout << "Inserisci valore di x: " << endl;
    cin >> x;
    double risultato = functions[id]->GetValue(x);
    cout << "Risultato: " << risultato << endl;
}

void Menu::MenuPrincipale()
{
    int scelta = -1;
    do
    {
        cout << "\n========== MENU PRINCIPALE ==========\n"
             << "0 – Esci dal menù\n"
             << "1 – Visualizza la lista delle funzioni\n"
             << "2 – Inserisci una funzione\n"
             << "3 – Elimina una funzione\n"
             << "4 – Elimina tutte le funzioni\n"
             << "5 – Seleziona una funzione\n"
             << "Scelta: ";
        cin >> scelta;

        switch (scelta)
        {
        case 0:
            cout << "Uscita...\n";
            break;
        case 1:
            VisualizzaFunzioni();
            break;
        case 2:
            InserisciFunzione();
            break;
        case 3:
        {
            int id;
            cout << "Inserire l'id della funzione da eliminare: ";
            cin >> id;
            EliminaFunzione(id);
            break;
        }
        case 4:
            EliminaTutte();
            break;
        case 5:
            SelezionaFunzione();
            break;
        default:
            cout << "Scelta non valida.\n";
        }
    } while (scelta != 0);
    EliminaTutte();
}