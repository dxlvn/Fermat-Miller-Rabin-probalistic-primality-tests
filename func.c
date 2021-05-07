#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <gmp.h>

int check_arg(char *argv){	
	for(int i = 0; i < strlen(argv);i++){	
		if(argv[i] < '0' || argv[i] > '9'){
			return 0;	
		}
	}
	return 1;
}

unsigned long int nb(mpz_t n){
	mpz_t tmp;
	mpz_init(tmp);
	mpz_set(tmp,n);
	int t;
	if(mpz_divisible_ui_p(tmp,2)) t=2;
	if(mpz_divisible_ui_p(tmp,6)) t=1;
	if(mpz_divisible_ui_p(tmp,10)) t=1;

	else t=1;
	mpz_t un;
	mpz_init_set_str(un,"1",10);
	mpz_t deux;
	mpz_init_set_str(deux,"2",10);
	
	if( (mpz_cmp_ui(n,0)==0) || (mpz_cmp_ui(n,1)==0)){
		return 1;
	}  
	while(mpz_cmp_ui(tmp,2)){  
		mpz_cdiv_q_ui(tmp,tmp,2);
		t++;
	}
	return t;
}

void square_and_multiply(mpz_t a, mpz_t n,mpz_t H,mpz_t* nbb){
	//Calcul de la taille en bits du module H
	unsigned long int taille = nb(H);

	//Initialisations
	mpz_t var;
	mpz_init(var);
	mpz_set(var,H);
	unsigned long int tab[taille];
	unsigned long int x = 0;
	mpz_t deux;
	mpz_init_set_str(deux,"2",10);
	mpz_t q;
	mpz_init(q);
	mpz_tdiv_q(q,H,deux);
	unsigned long int v = mpz_get_ui(var);
	mpz_t hi;
	mpz_init(hi);
	unsigned long int i=0;
	unsigned long int it=taille;

	//Décomposition binaire du module
	if(mpz_cmp_ui(var,0)==0){
		tab[0] = v; 
	}
	else{
		while(i<taille){  
			mpz_mod(hi,var,deux);
			v = mpz_get_ui(hi);
			tab[x] = v;
			mpz_tdiv_q(var,var,deux);
			it--;
			x++;
			i++;
		}		
		tab[taille-1] = 1;
	}
	// Coeur de l'algorithme
	if(mpz_cmp_ui(H,0)==0){
		mpz_t UN;
		mpz_init_set_str(UN,"1",10);
		mpz_mod(*nbb,UN,n);
	}
	if(mpz_cmp_ui(H,1)==0){
		mpz_mod(*nbb,a,n);
	}
	mpz_set(*nbb,a);
	for (int i=taille-2;i>(-1);i--){
		mpz_mul(*nbb,*nbb,*nbb);
		mpz_mod(*nbb,*nbb,n);

		if(tab[i]==1){
			mpz_mul(*nbb,*nbb,a);
			mpz_mod(*nbb,*nbb,n);
		}
	}
}