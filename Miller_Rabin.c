#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h>
#include "func.h"


void miller_rabin(mpz_t n, mpz_t k,mpz_t* y){
	if(mpz_divisible_ui_p(n,2)){
		gmp_printf("COMPOSÉ, vous devez entrer un nombre impair\n");
		return;
	}
	if(mpz_cmp_ui(n,1)==0){
		gmp_printf("Attention, 1 n'est pas un nombre premier\n");
		return;
	}
	//Décomposition de n-1 en 2^s*t
	mpz_t n_1;
	mpz_init(n_1);
	mpz_sub_ui(n_1,n,1);
	mpz_t s,t;
	mpz_init(s);
	mpz_init(t);
	while(mpz_divisible_ui_p(n_1,2)){
		mpz_add_ui(s,s,1);
		mpz_tdiv_q_ui(n_1,n_1,2);
	}
	mpz_set(t,n_1);
	unsigned long int s_1 = mpz_get_ui(s);
	//Fin Décomposition de n-1 en 2^s*t

	//Initialisation de variables
	mpz_t deux;
	mpz_init_set_str(deux,"2",10);
	unsigned long  v = mpz_get_ui(k);
	int i=0;
	gmp_randstate_t alea;
	gmp_randinit(alea,0,128);
	mpz_t a;
	mpz_init(a);
	unsigned long graine,res;
	time (&graine);    
	gmp_randseed_ui(alea,graine);
	mpz_init(a);
	for(i=0;i<v;i++){  // Boucle pour i de 1 à k
		mpz_urandomm(a,alea,n);
		if(mpz_get_ui(a)==0) i--;
		square_and_multiply(a,n,t,y);	//y <-- a^t mod n	
		if((mpz_get_ui(*y) != 1) && ((mpz_get_ui(*y)!=(-1)))){
			for(int j=1;j<s_1-1; ++j){ // Boucle pour j de 1 à s-1
				square_and_multiply(*y,n,deux,y); //y <-- y^2 mod n
				if((mpz_get_ui(*y)) == 1){ 
					gmp_printf("COMPOSÉ\n");
					gmp_randclear(alea);
					return;
				}
				if((mpz_get_ui(*y)) == -1){
					break;
				}
			} // Fin Boucle pour j de 1 à s-1
			if(mpz_get_ui(*y)==0 || mpz_get_ui(*y) == (mpz_get_ui(n)-1));
			else{
				gmp_printf("COMPOSÉ\n");
				gmp_randclear(alea);
				return;
			}		
		}
	} // Fin Boucle pour i de 1 à k
	gmp_printf("PREMIER\n");
	gmp_randclear(alea);
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
			miller_rabin(n,k,&y);
		}else
		{
			printf("arguments données invalides (seules des nombres/chiffres sont accepté)\n");
			return 1;
		}
		
	}else
	{
		printf("nombre d'argument invalide\n");
		return 2;
	}
 	return 0;
}