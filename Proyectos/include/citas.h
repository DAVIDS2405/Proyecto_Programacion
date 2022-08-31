#include <string>
using namespace std;
const int MAX_DOCS_AUX = 30;
const int MAX_PACIE_AUX = 30;
const int MAX_CITAS = 30;



//ESTRUCTURAS PARA CITAS MÉDICAS
typedef struct{
      int codigo_cita;
      int dia, mes, anio;
      string cedula;
      string cedulaPAC;
}tCita;

typedef struct{
      tCita elementosCitas[MAX_CITAS];
      int contadorCit = 0;
}tListaC;

int Menucitas();
void Cargar_citas(tListaC &listacita);
void Guardar_citas(const tListaC &listacita);
void Leer_citas(tCita &cita);
void Insertar_cita(tListaC &listacita, tCita cita, bool &funca);
void Eliminar_cita(tListaC &listacita, int codigo_buscar, bool &funca);
void Ordenar_cita(tListaC &listacita);
void Buscar_cita(tListaC &listacita, int codigo_buscar, bool &funca);
void Modificar_cita(tListaC &listacita, int codigo_buscar);
void MostrarCita(tCita cita);
void ListadoCitas(tListaC listacita);


