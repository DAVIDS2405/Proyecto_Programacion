#include <string>
using namespace std;
const int MAX_DOCS = 100;

typedef struct{
    string nombreMED;
    string apellidoMED;
    string edadMED;
    string especialidad;
    double sueldo;
}tDoctores;

typedef struct{
    tDoctores elementos[MAX] = {};
    int contador = 0;
}tLista;
