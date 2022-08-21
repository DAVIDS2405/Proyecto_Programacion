#include <iostream>
#include <iomanip>
#include <string>
#include "pacientes.h"
using namespace std;
int MenuPrincipal();



int main(){
    tLista lista;
    tPacientes pacientes;
    string CedulaBuscar;
    bool ok;
    int pos;
    int opcionMenuPrincipal = MenuPrincipal();
    while(opcionMenuPrincipal != 4){
        switch(opcionMenuPrincipal){
            case 1:{

            }
            break;
            case 2:{
                Cargar_Pac(lista, ok);
                if (!ok){

                }
                else{

                    int opcionPacientes = Menu_Pac();
                    while (opcionPacientes != 6)
                    {
                        switch (opcionPacientes)
                        {
                            case 1:
                            {
                                Leer_Pac(pacientes);
                                Insertar_Pac(lista, pacientes,ok);
                                if (!ok)
                                {
                                    cout << "Lista llena: imposible insertar" << endl;
                                }
                            }
                            break;
                            case 2:
                            {   cout <<"Que paciente desea eliminar: ";
                                cin >> pos;
                                Eliminar_Pac(lista, pos, ok);
                                if (!ok)
                                {
                                    cout << "El paciente no existe!" << endl;
                                }
                            }
                            break;
                            case 3:
                            {
                                Ordenamiento_Pac(lista);
                            }
                            break;
                            case 4:
                            {
                                cout <<"ingrese la cedula a buscar: ";
                                getline(cin,CedulaBuscar);
                                Buscar_Pac(lista,CedulaBuscar, ok);
                            }
                            break;
                            case 5:
                            {
                            }
                            break;
                            case 6:
                            {
                                Listado_Pac(lista);
                            }
                        }
                    }
                }
                Guardar_Pac(lista);
                
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