#include <string>
using namespace std;
const int MAX_DOCS_AUX = 30;
const int MAX_PACIE_AUX = 30;
const int MAX_CITAS = 30;

//ESTRUCTURAS PARA DOCTORES
typedef struct{
    string nombre_MED;
    string apellido_MED;
    int edad_MED;
    string especialidad_MED;
    string cedula_MED;
}tDoctoresAUX;

typedef struct{
    tDoctoresAUX Doc_aux[MAX_DOCS_AUX];
    int contadorDoc_aux = 0;
}tListaDocAUX;

//ESTRUCTURAS PARA PACIENTES
typedef struct
{
    string nombre_PAC;
    string apellido_PAC;
    string edad_PAC;
    string cedula_PAC;
} tPacientesaux;

typedef struct
{
    tPacientesaux Pac_aux[MAX_PACIE_AUX];
    int contadorPac_aux = 0;
} tListaPacienteAUX;


//ESTRUCTURAS PARA CITAS MÉDICAS
typedef struct{
      int codigo_cita;
      int dia, mes, anio;
      string cedDoc,nomDoc, apelDoc, especialidadDoc;
      string cedPax,nomPax, apelPax;
      //tDoctoresAUX elementosDoc[MAX_DOCS_AUX];
      //tPacientesaux elementos[MAX_PACIE_AUX];
      //tDoctoresAUX doctor;
      //tPacientesaux paciente;
}tCita;

typedef struct{
      tCita elementosCitas[MAX_CITAS] = {};
      int contadorCit = 0;
}tListaC;


int Menucitas();
void Cargar_docs_aux(tListaDocAUX &listaAux, bool& funca);
void Cargar_pacs_aux(tListaPacienteAUX &listaAux, bool& funca);
void Cargar_citas(tListaC &listacita, bool& funca);
void Guardar_citas(const tListaC &listacita);
void Leer_citas(tCita &cita, tListaDocAUX &listaAux, tListaPacienteAUX &listaAux);
void Insertar_cita(tListaC &listacita, tCita cita, bool &funca);
void Eliminar_cita(tListaC &listacita, int pos, bool &funca);
void Ordenar_cita(tListaC &listacita);
void Buscar_cita(tListaC &listacita, int codigo_buscar, bool &funca);
void Modificar_cita(tListaC &listacita, int codigo_buscar);
