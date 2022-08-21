#include <iostream>
#include <iomanip>
#include <string>
#include "pacientes.h"
using namespace std;
int MenuPrincipal();
int main(){
    int opcionMenuPrincipal = MenuPrincipal();
    while(opcionMenuPrincipal != 4){
        switch(opcionMenuPrincipal){
            case 1:{

            }
            break;
            case 2:{
                Menu_Pac();
            }
            break;
            case 3:{

            }
            break;
        }
    }

    return 0;
}

int MenuPrincipal(){
    int op = 0;
    while ((op < 1) || (op > 4))
    {
        cout << setw(41) << " --------------------------------------------" << endl;
        cout << "|" << setw(30) << "Menu Pacientes" << setw(15) << "|" << endl;
        cout << "|" << setw(24) << "1 - Ingresar a Medicos" << setw(21) << "|" << endl;
        cout << "|" << setw(25) << "2 - Ingresar a Pacientes" << setw(20) << "|" << endl;
        cout << "|" << setw(25) << "3 - Ingresar a Citas" << setw(20) << "|" << endl;
        cout << "|" << setw(23) << "4 - Salir" << setw(22) << "|" << endl;
        cout << setw(10) << " Ingrese la opcion deseada: ";
        cin >> op;
        cin.ignore();
        if ((op < 1) || (op > 4))
        {
            cout << "Opcion no valida ingresar un numero valido" << endl;
        }
    }
    return op;
}