#include <string>
using namespace std;
const int MAX_DOCS = 25;

typedef struct{
    string nombreMED;
    string apellidoMED;
    string edadMED;
    string especialidad;
    double sueldo;
}tDoctores;

typedef struct{
    tDoctores elementos[MAX_DOCS];
    int contador = 0;
}tLista;
