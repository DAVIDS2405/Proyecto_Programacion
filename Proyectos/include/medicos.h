#include <string>
using namespace std;
const int MAX_DOCS = 30;

typedef struct{
    string nombreMED;
    string apellidoMED;
    string edadMED;
    string especialidad;
    string cedula;
}tDoctores;

typedef struct{
    tDoctores elementosDoc[MAX_DOCS];
    int contadorDoc = 0;
}tListaDoc;

//PROTOTIPOS DE LAS FUNCIONES PARA LOS MÉDICOS
int MenuDoctores();
void CargarDoctores(tListaDoc &listadoc, bool& okdoc);
void GuardarDoctores(const tListaDoc &listadoc);
void LeerDoctor(tDoctores &doctores);
void InsertarDoctor(tListaDoc &listadoc, tDoctores doctor, bool &okdoc);
void EliminarDoctor(tListaDoc &listadoc, int pos, bool &okdoc);
string NombreCompleto(tDoctores doctor);
void MostrarDoctor(tDoctores doctor);
void ListadoDoctores(const tListaDoc &listadoc);
void OrdenarDoctores(tListaDoc &listadoc);
void Buscar_Doctores(tLista &lista, string CedulaBuscar, bool &ok);
