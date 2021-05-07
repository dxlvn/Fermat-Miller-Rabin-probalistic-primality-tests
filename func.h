#ifndef FUNC_H
#define FUNC_H

#include <gmp.h>

// Fonction auxiliaire calculant la taille en bits du module n
// Utile pour effectuer la décomposition binaire 
unsigned long int nb(mpz_t n);

// Calcule et stocke dans y le résultat de a exposant H modulo n
void square_and_multiply(mpz_t a, mpz_t n,mpz_t H,mpz_t* y);

//Vérifie la validité des arguments pour sécuriser les entrées
int check_arg(char *argv);


#endif