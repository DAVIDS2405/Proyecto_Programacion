#include <iostream>
#include <iomanip>
#include <string>
#include "pacientes.h"
#include "medicos.h"
using namespace std;
int MenuPrincipal();



int main(){
    tLista lista;
    tPacientes pacientes;
    tListaDoc listaDoc;
    tDoctores doctores;
    string CedulaBuscar;
    bool ok;
    int pos;
    int opcionMenuPrincipal = MenuPrincipal();
    while(opcionMenuPrincipal != 4){
        switch(opcionMenuPrincipal){
            case 1:{
                CargarDoctores(listaDoc,ok);
                if (!ok)
                {
                    cout <<"no se pudo cargar el archivo"<<endl;
                }
                else{
                    int opcionDoctores = MenuDoctores();
                    while(opcionDoctores != 7){
                        switch(opcionDoctores){
                            case 1:{
                                LeerDoctor(doctores);
                                InsertarDoctor(listaDoc, doctores,ok);
                            }
                            break;
                            case 2:
                            {    
                                ListadoDoctores(listaDoc);
                                cout <<endl;
                                cout <<"Que doctor desea eliminar"<<endl;
                                cin >> pos;
                                EliminarDoctor(listaDoc, pos-1,ok);
                            }
                            break;
                            case 3:
                            {
                                Ordenamiento_Doctores(listaDoc);
                            }
                            break;
                            case 4:
                            {
                                cout << "ingrese la cedula a buscar: ";
                                getline(cin, CedulaBuscar);
                                Buscar_Doctores(listaDoc, CedulaBuscar, ok);
                            }
                            break;
                            case 5:
                            {
                            }
                            break;
                            case 6:
                            {
                                ListadoDoctores(listaDoc);
                            }
                        }
                        opcionDoctores = MenuDoctores();
                    }
                }
                GuardarDoctores(listaDoc);
            }
            break;
            case 2:{
                Cargar_Pac(lista, ok);
                if (!ok){
                    cout << "no se pudo cargar el archivo" << endl;
                }
                else{

                    int opcionPacientes = Menu_Pac();
                    while (opcionPacientes != 7)
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
                            break;
                        }
                        opcionPacientes = Menu_Pac();
                    }
                    
                }
                Guardar_Pac(lista);
                
            }
            break;
            case 3:{

            }
            break;
        }
        opcionMenuPrincipal = MenuPrincipal();
    }

    return 0;
}

int MenuPrincipal()
{
    int op = 0;
    while ((op < 1) || (op > 4))
    {
        cout << setw(41) << " --------------------------------------------" << endl;
        cout << "|" << setw(30) << "CITAS MEDICAS" << setw(15) << "|" << endl;
        cout << "|" << setw(36) << "1 - Ingresar a Medicos" << setw(9) << "|" << endl;
        cout << "|" << setw(38) << "2 - Ingresar a Pacientes" << setw(7) << "|" << endl;
        cout << "|" << setw(34) << "3 - Ingresar a Citas" << setw(11) << "|" << endl;
        cout << "|" << setw(23) << "4 - Salir" << setw(22) << "|" << endl;
        cout << setw(41) << " --------------------------------------------" << endl;
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