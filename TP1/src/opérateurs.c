#include <stdio.h>
int main(void) {
  int a = 16;
  int b = 3;
  int somme = a + b; 
  printf("somme : %d\n", somme);
  int soustraction = b-a;
  printf("soustraction : %d\n", soustraction);
  int produit = a*b;
  printf("produit : %d\n", produit);
  int div = a/b;
  printf("div : %d\n", div);
  int modulo = a%b;
  printf("modulo : %d\n", modulo);
  int resultat = (a == b);
  printf("a est-il égal à b ? %d\n", resultat);
  
}
