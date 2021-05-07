#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>
#include "func.h"


void fermat(mpz_t n, mpz_t k,mpz_t* y){
	if(mpz_divisible_ui_p(n,2)){
		gmp_printf("COMPOSÉ, vous devez entrer un nombre impair\n");
		return;
	}
	if(mpz_cmp_ui(n,1)==0){
		gmp_printf("Attention, 1 n'est pas un nombre premier\n");
		return;
	}
	// Initialisations
   	int i=0;
  	gmp_randstate_t alea;
	gmp_randinit(alea,0,128);
	mpz_t a;
	mpz_init(a);
	unsigned long graine,res;
	time (&graine);    
	gmp_randseed_ui(alea,graine);
	mpz_t n_1; 
	mpz_init(a);
	mpz_sub_ui(n_1,n,1);
	unsigned long  v = mpz_get_ui(k);

	//Coeur de l'algorithme
	for(i=0;i<v;i++){ // Boucle pour i de 1 à k
		mpz_urandomm (a,alea, n);
	    if(mpz_get_ui(a)==1 ||  mpz_get_ui(a)==0 ) i--;
	    else{
	      	square_and_multiply(a,n,n_1,y); // y <-- a^n_1 mod n
	      	if(mpz_get_ui(*y) != 1){
	      	printf("COMPOSÉ\n");
	      	gmp_randclear(alea);
	      	mpz_clear(a);
	      	return;
	      	}
	      }
	   } // Fin Boucle pour i de 1 à k
	  printf("PREMIER\n");
	  gmp_randclear(alea);
	  mpz_clear(a);
}

int main(int argc,char **argv){ 

	if(argc == 3)
	{
		if( check_arg(argv[1]) && check_arg(argv[2]) )
		{
			mpz_t k,n;
			mpz_init_set_str(k,argv[1],10);
			mpz_init_set_str(n,argv[2],10);
			mpz_t y;
			mpz_init(y);
			fermat(n,k,&y);
		}else
		{
			printf("arguments données invalides (seules des nombres/chiffres sont accepté)");
			return 1;
		}
		
	}else
	{
		printf("nombre d'argument invalide\n");
		return 2;
	}
	return 0;
}
