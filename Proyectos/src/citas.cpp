#include "citas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int Menucitas(){

  int op = 0;
  while ((op < 1) || (op > 7))
  {
      cout << setw(41) << " --------------------------------------------" << endl;
      cout << "|" << setw(30) << "Menu Citas" << setw(15) << "|" << endl;
      cout << "|" << setw(41) << "1 - Agregar un nuevo doctor" << setw(4) << "|" << endl;
      cout << "|" << setw(36) << "2 - Eliminar un doctor" << setw(9) << "|" << endl;
      cout << "|" << setw(38) << "3 - Ordenar los doctores" << setw(7) << "|" << endl;
      cout << "|" << setw(36) << "4 - Consultar doctores" << setw(9) << "|" << endl;
      cout << "|" << setw(34) << "5 - Modificar doctor" << setw(11) << "|" << endl;
      cout << "|" << setw(32) << "6 - Mostrar doctor" << setw(13) << "|" << endl;
      cout << "|" << setw(42) << "7 - Salir del menu pacientes" << setw(3) << "|" << endl;
      cout << setw(41) << " --------------------------------------------" << endl;
      cout << setw(10) << " Ingrese la opcion deseada: ";
      cin >> op;
      cin.ignore();
      cout <<endl;
      if ((op < 1) || (op > 7))
      {
          cout << "Opcion no valida ingresar un numero valido" << endl;
      }
  }
  return op;

}


void Cargar_docs_aux(tListaDocAUX &listaAux, bool& funca){

  tDoctoresAUX doctor;
  ifstream archivo_lec;
  char aux = ' ';
  listaAux.contadorDoc = 0;
  archivo_lec.open("Medicos.txt",ios::in);

  if( !archivo_lec.is_open() ){
      okdoc = false;

  }else{
      okdoc = true;

      getline(archivo_lec, doctor.cedula);
      doctor.cedula = doctor.cedula.substr(0,10);

        while( (doctor.cedula != "XXX")&&(listaAux.contadorDoc < MAX_DOCS)  ){

            getline(archivo_lec, doctor.nombreMED);
            getline(archivo_lec, doctor.apellidoMED);
            archivo_lec >> doctor.edadMED;
            archivo_lec.get(aux);
            getline(archivo_lec, doctor.especialidad);
            listaAux.elementosDoc[listaAux.contadorDoc] = doctor;
            listaAux.contadorDoc++;
            getline(archivo_lec, doctor.cedula);
            doctor.cedula = doctor.cedula.substr(0,10);

        }


        archivo_lec.close();
  }//fin del else principal


}


void Cargar_pacs_aux(tListaPacienteAUX &listaAux, bool& funca){

  tPacientesaux pacientes;
  ifstream archivo;
  char aux;

  listaAux.contador = 0;
  archivo.open("pacientes.txt");
  if (!archivo.is_open())
  {
      ok = false;
  }
  else
  {
      ok = true;

      getline(archivo, pacientes.cedulaPAC);
      while ((pacientes.cedulaPAC != "XXX") && (listaAux.contador < MAX_PACIE))
      {
          getline(archivo, pacientes.nombrePAC);
          getline(archivo, pacientes.apellidoPAC);
          archivo >> pacientes.edadPAC;
          archivo.get(aux);
          listaAux.elementos[listaAux.contador] = pacientes;
          listaAux.contador++;
          getline(archivo, pacientes.cedulaPAC);
      }
      archivo.close();
  }



}


void Cargar_citas(tListaC &listacita, bool& funca){

  tCita cita;
  ifstream  leer_archivo;
  char aux = ' ';
  listacita.contadorCit = 0;

  leer_archivo.open("Citas.txt",ios::in);

  if( !leer_archivo.is_open()  ){
      cout <<"No se pudo abrir el archivo"<<endl;

  }else{
        leer_archivo >> cita.codigo_cita;
        while( cita.codigo_cita != -1 && listacita.contadorCit < MAX_CITAS ){
              leer_archivo.get(aux);
              getline(leer_archivo, cita.elementosDoc[listacita.contadorCit].cedula);
              getline(leer_archivo, cita.elementosDoc[listacita.contadorCit].nombreMED);
              getline(leer_archivo, cita.elementosDoc[listacita.contadorCit].apellidoMED);
              getline(leer_archivo, cita.elementosDoc[listacita.contadorCit].especialidad);

              getline(leer_archivo, cita.elementos[listacita.contadorCit].cedulaPAC);
              getline(leer_archivo, cita.elementos[listacita.contadorCit].nombrePAC);
              getline(leer_archivo, cita.elementos[listacita.contadorCit].apellidoPAC);

              leer_archivo >> cita.dia;
              leer_archivo >> cita.mes;
              leer_archivo >> cita.anio;

              listacita.elementosCitas[listacita.contadorCit] = cita;
              listacita.contadorCit++;
              leer_archivo >> cita.codigo_cita;
        }

        leer_archivo.close();

  }













}


void Guardar_citas(const tListaC &listacita){
    ofstream archivo_pac("Citas.txt",ios::out);

    for(int i = 0; i < listacita.contadorCit; i++){
        archivo_pac << listacita.elementosCitas[i].elementosDoc[i].codigo_cita<<endl;
        archivo_pac << listacita.elementosCitas[i].elementosDoc[i].cedula<<endl;
        archivo_pac << listacita.elementosCitas[i].elementosDoc[i].nombreMED<<endl;
        archivo_pac << listacita.elementosCitas[i].elementosDoc[i].apellidoMED<<endl;
        archivo_pac << listacita.elementosCitas[i].elementosDoc[i].especialidad<<endl;

        archivo_pac << listacita.elementosCitas[i].elementos[i].cedulaPAC<<endl;
        archivo_pac << listacita.elementosCitas[i].elementos[i].nombrePAC<<endl;
        archivo_pac << listacita.elementosCitas[i].elementos[i].apellidoPAC<<endl;

        archivo_pac << listacita.elementosCitas[i].dia<<endl;
        archivo_pac << listacita.elementosCitas[i].mes<<endl;
        archivo_pac << listacita.elementosCitas[i].anio<<endl;
    }
    archivo_pac << -1<<endl;
    archivo_pac.close();
}


void Leer_citas(){
cin.sync();
cout <<"Ingrese el codigo de la cita: ";
cin >> cita.codigo_cita;

cin.sync();


cout <<"Ingrese la cedula del doctor: ";
cin >> cita.elementosDoc.cedula;
}
