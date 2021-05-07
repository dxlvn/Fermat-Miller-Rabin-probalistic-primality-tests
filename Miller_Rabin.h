#ifndef MILLER_RABIN_H
#define MILLER_RABIN_H

#include <gmp.h>

// Effectue le test de Miller-Rabin sur un entier n avec un nombre de répétitions k et stocke le résultat dans y
void miller_rabin(mpz_t n, mpz_t k,mpz_t* y);

#endif