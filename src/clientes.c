#include "../include/clientes.h"

int Altura(Node *N) {
    if (N == NULL)
        return 0;
    return N->Altura;
}