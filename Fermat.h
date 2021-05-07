#ifndef FERMAT_H
#define FERMAT_H

#include <gmp.h>

// Effectue le test de Fermat sur un entier n avec un nombre de répétitions k et stocke le résultat dans y 
void fermat(mpz_t n, mpz_t k,mpz_t* y);

#endif