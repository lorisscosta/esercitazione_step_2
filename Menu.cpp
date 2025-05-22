/*! @file Menu.cpp
    @brief Implementation of class Menu
    @author Federico Maria Biasioli Loris Costanzo
*/

#include "Menu.h"
#include "CLogarithmic.h"
#include "CPower.h"
#include "CPolinomial.h"
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
 * @brief shows all functions with index
 * @return void
 */
void Menu::VisualizzaFunzioni() const
{
    if (functions.empty())
    {
        cout << "Nessuna funzione presente." << endl;
        return;
    }
    cout << "Funzioni disponibili:" << endl;
    for (int i = 0; i < (int)functions.size(); i++)
    {
        cout << "Function numero [" << i << "]: " << endl;
        functions[i]->Dump();
    }
}

/**
 * @brief store a new function
 * @param scelta input
 * @return void
 */
void Menu::InserisciFunzione()
{
    string stdgrado; // Inizio variabili controllo dell'input
    string stdconferma;
    string stdpol_coeff;
    string stdexp;
    string stdpow_coeff;
    string stdbase;
    string stdlog_coeff;
    string stdscelta;
    const char *stdscelta2;
    const char *stdconferma2; // Fine variabili controllo dell'input
    int scelta = 1;
    int result = -1;
    int conferma = -1;
    // oggetto per creare una copia iniziale della funzione
    Function *nuova = nullptr;
    do
    {
        do // Scelta della funzione con controllo input
        {
            cout << "Che tipo di funzione vuoi inserire?" << endl;
            cout << "0 - Uscita dall'inserimento" << endl;
            cout << "1 - Polinomiale" << endl;
            cout << "2 - Potenza" << endl;
            cout << "3 - Logaritmica" << endl;
            cout << "Scelta: " << endl;
            getline(cin, stdscelta);
            stdscelta2 = stdscelta.c_str();
            result = CheckValueInt(stdscelta);
        } while (result == -1);
        scelta = atoi(stdscelta2);
        switch (scelta)
        {
        case 0:
        {
            cout << "Uscita dall'inserimento.\n" << endl;
            break;
        }
        case 1:
        {
            const char *stdgrado2;     // Variabile di controllo input
            const char *stdpol_coeff2; // Variabile di controllo input
            int grado;
            do // Inserimento e controllo del grado di polinomio
            {
                cout << "Grado del polinomio: " << endl;
                getline(cin, stdgrado);
                stdgrado2 = stdgrado.c_str();
                result = CheckValueInt(stdgrado);
                if(atof(stdgrado2)<0)
                        result=-1;
            } while (result == -1);
            grado = atoi(stdgrado2);
            double *pol_coeff = new double[grado + 1];
            for (int i = 0; i <= grado; i++)
            {
                do // Inserimento coefficienti con controllo dell'input
                {
                    cout << "Coefficiente di x^" << i << ": " << endl;
                    getline(cin, stdpol_coeff);
                    stdpol_coeff2 = stdpol_coeff.c_str();
                    result = CheckValueDouble(stdpol_coeff);
                } while (result == -1);
                pol_coeff[i] = atof(stdpol_coeff2);
            }
            // Creazione del polinomio
            nuova = new Polinomial(pol_coeff, grado + 1);
            cout << "Hai inserito:" << endl;
            nuova->Dump();
            do // Conferma di creazione più controllo input
            {
                conferma = -1;
                cout << "Confermi?(1=Si / 0=No):" << endl;
                getline(cin, stdconferma);
                stdconferma2 = stdconferma.c_str();
                if (CheckValueInt(stdconferma) == 1)
                    conferma = atoi(stdconferma2);
            } while (conferma != 1 && conferma != 0);
            if (conferma) // aggiunta della nuova funzione nella lista
            {
                functions.push_back(nuova);
                cout << "Funzione registrata.\n" << endl;
            }
            else
            {
                delete nuova;
                cout << "Funzione scartata.\n" << endl;
            }
            break;
        }
        case 2:
        {
            const char *stdpow_coeff2; // Variabile per il controllo dell'input
            const char *stdexp2;       // Variabile per il controllo dell'inputs
            double pow_coeff, exp;
            do // Inserimento coefficiente con controllo dell'input
            {
                cout << "Inserisci coefficiente: " << endl;
                getline(cin, stdpow_coeff);
                stdpow_coeff2 = stdpow_coeff.c_str();
                result = CheckValueDouble(stdpow_coeff);
            } while (result == -1);
            pow_coeff = atof(stdpow_coeff2);
            do // Inserimento esponente con controllo dell'input
            {
                cout << "Inserisci esponente: " << endl;
                getline(cin, stdexp);
                stdexp2 = stdexp.c_str();
                result = CheckValueDouble(stdexp);
            } while (result == -1);
            exp = atof(stdexp2);
            // Creazione della potenza
            nuova = new Power(pow_coeff, exp);
            cout << "Hai inserito:" << endl;
            nuova->Dump();
            do // Conferma della creazione con controllo su input
            {
                conferma = -1;
                cout << "Confermi?(1=Si / 0=No):" << endl;
                getline(cin, stdconferma);
                stdconferma2 = stdconferma.c_str();
                if (CheckValueInt(stdconferma) == 1)
                    conferma = atoi(stdconferma2);
            } while (conferma != 1 && conferma != 0);
            if (conferma)
            { // Inserimento nella lista della nuova funzione
                functions.push_back(nuova);
                cout << "Funzione registrata.\n" << endl;
            }
            else
            {
                delete nuova;
                cout << "Funzione scartata.\n" << endl;
            }
            break;
        }
        case 3:
        {
            double base, log_coeff;
            const char *stdbase2;      // Variabile per il controllo dell'input
            const char *stdlog_coeff2; // Variabile per il controllo dell'input
            do                         // Inserimento della base con controllo dell'input
            {
                cout << "Inserisci la base del logaritmo (diversa da 1 e > 0): " << endl;
                getline(cin, stdbase);
                stdbase2 = stdbase.c_str();
                result = CheckValueDouble(stdbase);
            } while (result == -1);
            base = atof(stdbase2);
            do // Inserimento coefficiente con controllo dell'input
            {
                cout << "Inserisci coefficiente: ";
                getline(cin, stdlog_coeff);
                stdlog_coeff2 = stdlog_coeff.c_str();
                result = CheckValueDouble(stdlog_coeff);
            } while (result == -1);
            log_coeff = atof(stdlog_coeff2);
            // Creazione del nuovo logaritmo
            nuova = new Logarithmic(base, log_coeff);
            cout << "Hai inserito:" << endl;
            nuova->Dump();
            do // Salvataggio della nuova funzione con controllo
            {
                conferma = -1;
                cout << "Confermi?(1=Si / 0=No):" << endl;
                getline(cin, stdconferma);
                stdconferma2 = stdconferma.c_str();
                if (CheckValueInt(stdconferma) == 1)
                    conferma = atoi(stdconferma2);
            } while (conferma != 1 && conferma != 0);
            if (conferma)
            { // Copia della nuova funzione.
                functions.push_back(nuova);
                cout << "Funzione registrata.\n" << endl;
            }
            else
            {
                delete nuova;
                cout << "Funzione scartata.\n" << endl;
            }
            break;
        }
        default:
            cout << "Scelta non valida." << endl;
        }
    } while (scelta != 0);
}

/**
 * @brief delete a function
 * @param id input
 * @return void
 */
void Menu::EliminaFunzione(int id)
{
    string stdid; // Inizio variabili di controllo dell'input
    string stdconferma;
    const char *stdconferma2;
    const char *stdid2; // Fine variabili di controllo dell'input
    int controllo = 0;
    int conferma;
    do // Controllo di id
    {
        if (id < 0 || id >= (int)functions.size())
        {
            cout << "ID non valido." << endl;
            controllo = 0;
            cout << "Inserisci ID della funzione: " << endl;
            getline(cin, stdid);
            stdid2 = stdid.c_str();
            if (CheckValueInt(stdid) == 1)
                id = atoi(stdid2);
            else
                id = -1;
        }
        else
            controllo = -1;
    } while (controllo == 0);
    cout << "Funzione selezionata:" << endl;
    functions[id]->Dump();
    do // Controllo di conferma
    {
        conferma = -1;
        cout << "Confermi?(1=Si / 0=No):" << endl;
        getline(cin, stdconferma);
        stdconferma2 = stdconferma.c_str();
        if (CheckValueInt(stdconferma) == 1)
            conferma = atoi(stdconferma2);
    } while (conferma != 1 && conferma != 0);

    if (conferma == 1)
    {
        delete functions[id];
        functions.erase(functions.begin() + id);
        cout << "Funzione eliminata." << endl;
    }
    else
    {
        cout << "Eliminazione annullata." << endl;
    }
}

/**
 * @brief delete all functions
 * @return void
 */
void Menu::EliminaTutte()
{
    for (Function *f : functions)
    {
        delete f;
    }
    functions.clear();
    cout << "Tutte le funzioni sono state eliminate." << endl;
}

/**
 * @brief Check the value passed by the user (for int type)
 * @param cstring string to check
 * @return 1 if the string is a int, -1 if it's not
 */
int Menu::CheckValueInt(string cstring)
{
    int counter = 0;
    if (cstring == "")
    {
        cout << "Valore inserito errato" << endl;
        return -1;
    }
    for (char c : cstring)
    {
        if (counter != 0 && !isdigit(c))
        {
            cout << "Valore inserito errato" << endl;
            return -1;
        }
        if (!isdigit(c)&&counter==0&&c!='-')
        {
            cout << "Valore inserito errato" << endl;
            return -1;
        }
        counter++;
    }
    return 1;
}

/**
 * @brief Check the value passed by the user (for double type)
 * @param cstring string to check
 * @return 1 if the string is a double, -1 if it's not
 */
double Menu::CheckValueDouble(string cstring)
{
    int counter = 0;
    if (cstring == "")
    {
        cout << "Valore inserito errato" << endl;
        return -1;
    }
    for (char c : cstring)
    {
        if (counter != 0 && !isdigit(c)&&c!='.')
        {
            cout << "Valore inserito errato" << endl;
            return -1;
        }
        if (!isdigit(c)&&counter==0&&c!='-')
        {
            cout << "Valore inserito errato" << endl;
            return -1;
        }
        counter++;
    }
    return 1;
}

/**
 * @brief execute a function
 * @param id input
 * @param x input
 * @return void
 */
void Menu::SelezionaFunzione()
{
    VisualizzaFunzioni();
    int id; // Inizio variabili per i controlli sulle stringhe
    double x;
    string stdid;
    const char *stdid2;
    string stdx;
    const char *stdx2; // Fine variabili per i controlli sulle stringhe
    int controllo;
    int result = -1;
    do // Controllo ID
    {
        cout << "Inserisci ID della funzione: " << endl;
        getline(cin, stdid);
        stdid2 = stdid.c_str();
        if (CheckValueInt(stdid) == 1)
            id = atoi(stdid2);
        else
            id = -1;
        if (id < 0 || id >= (int)functions.size())
        {
            cout << "ID non valido." << endl;
            controllo = 0;
        }
        else
            controllo = -1;
    } while (controllo == 0);
    // Stampa della funzione scelta
    functions[id]->Dump();
    do // Controllo valore inserito
    {
        cout << "Inserisci valore di x: " << endl;
        getline(cin, stdx);
        stdx2 = stdx.c_str();
        result = CheckValueDouble(stdx);
    } while (result == -1);
    x = atof(stdx2);
    double risultato = functions[id]->GetValue(x);
    cout << "Risultato: " << risultato << endl;
}

/**
 * @brief shows the main menu
 * @param scelta input
 * @return void
 */
void Menu::MenuPrincipale()
{
    cout<<"N.B. Per separare la parte decimale usare il punto e non la virgola."<<endl;
    cout<<"N.B. Per usare il numero di nepero inserire: 2.718"<<endl;
    cout<<"N.B. Per usare il pgreco inserire: 3.141"<<endl;
    string stdscelta; // Inizio variabili di controllo stringhe
    const char *stdscelta2;
    string stdid;
    const char *stdid2; // Fine variabili di controllo stringhe
    int scelta = -1;
    int result = -1;
    do
    {
        do // Scelta iniziale con controllo su input
        {
            cout << "========== MENU PRINCIPALE ==========" << endl;
            cout << "0  Esci dal menu" << endl;
            cout << "1  Visualizza la lista delle funzioni" << endl;
            cout << "2  Inserisci una funzione" << endl;
            cout << "3  Elimina una funzione" << endl;
            cout << "4  Elimina tutte le funzioni" << endl;
            cout << "5  Seleziona una funzione" << endl;
            cout << "Scelta: " << endl;
            getline(cin, stdscelta);
            stdscelta2 = stdscelta.c_str();
            result = CheckValueInt(stdscelta);
        } while (result == -1);
        scelta = atoi(stdscelta2);
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
            int controllo;
            if (functions.empty())
            {
                cout << "Nessuna funzione presente" << endl;
            }
            else
            {
                VisualizzaFunzioni();
                do // Inserimento primo id con controllo dell'input
                {
                    cout << "Inserisci ID della funzione: " << endl;
                    getline(cin, stdid);
                    stdid2 = stdid.c_str();
                    if (CheckValueInt(stdid) == 1)
                        id = atoi(stdid2);
                    else
                        id = -1;
                    if (id < 0 || id >= (int)functions.size())
                    {
                        cout << "ID non valido." << endl;
                        controllo = 0;
                    }
                    else
                        controllo = -1;
                } while (controllo == 0);
                EliminaFunzione(id);
            }
            break;
        }
        case 4:
            EliminaTutte();
            break;
        case 5:
            if (functions.empty())
            {
                cout << "Nessuna funzione presente" << endl;
            }
            else
                SelezionaFunzione();
            break;
        default:
            cout << "Scelta non valida.\n";
        }
    } while (scelta != 0);
}