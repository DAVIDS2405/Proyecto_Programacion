#include <iostream>
#include <iomanip>
#include <string>
#include "pacientes.h"
#include "medicos.h"
#include "citas.h"
using namespace std;
int MenuPrincipal();



int main(){
    tLista lista;
    tPacientes pacientes;
    tListaDoc listaDoc;
    tDoctores doctores;
    string CedulaBuscar;
    tCita cita;
    tListaC listacitas;
    bool ok;
    int pos;
    int codigo_buscar = 0;
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
                                ListadoDoctores(listaDoc);
                                //modificar
                                string cedula_aux;
                                cout <<"cededula del medico a modificar: ";
                                cin >> cedula_aux;
                                cout <<endl;
                                ModificarDoctores(listaDoc, cedula_aux);
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

                            {
                                cout <<"Que paciente desea eliminar: ";
                                cin >> pos;
                                Eliminar_Pac(lista, pos-1, ok);
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
                                //modificar
                                Listado_Pac(lista);
                                string cedula_aux;
                                cout <<"cedula del paciente a modificar: ";
                                cin >> cedula_aux;
                                cout <<endl;
                                ModificarPac(lista, cedula_aux);
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

                Cargar_citas(listacitas);
                CargarDoctores(listaDoc, ok);
                Cargar_Pac(lista, ok);

                int opmenucitas = Menucitas();
                while (opmenucitas != 7)
                {
                    switch (opmenucitas)
                    {
                        case 1:
                        {
                            Listado_Pac(lista);
                            ListadoDoctores(listaDoc);

                            Leer_citas(cita);
                            Insertar_cita(listacitas,cita,ok);
                        }
                        break;
                        case 2:
                        {
                            ListadoCitas(listacitas);
                            cout << "Ingrese la posicion a elimar de la cita ";
                            cin >> codigo_buscar;
                            Eliminar_cita(listacitas,codigo_buscar,ok);
                            if (!ok)
                            {
                                cout << "El paciente no existe!" << endl;
                            }
                        }
                        break;
                        case 3:
                        {
                            Ordenar_cita(listacitas);
                        }
                        break;
                        case 4:
                        {
                            
                            cout <<"Ingrese el codigo a buscar de la cita: ";
                            cin >> codigo_buscar;
                            Buscar_cita(listacitas,codigo_buscar,ok);
            
                        }
                        break;
                        case 5:
                        {
                            ListadoCitas(listacitas);
                            cout << "ingrese el codigo de la cita a modificar ";
                            cin >> codigo_buscar;
                            Modificar_cita(listacitas,codigo_buscar);
                        }
                        break;
                        case 6:
                        {
                            ListadoCitas(listacitas);
                        }
                    }
                    opmenucitas = Menucitas();
                    }

                Guardar_citas(listacitas);
            }   

        }   
        opcionMenuPrincipal = MenuPrincipal();   
   }
   return 0;
}

int MenuPrincipal(){
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