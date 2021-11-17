#include "2048.hpp"

int main(void) {
   cout << "Hello World!" << endl;
   //affiche_plateau("affiche", {{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {0,0,0,0}});
   //test_affiche_plateau();
   //Plateau tab = init_plateau(genere_nombre());
   //affiche_plateau("affiche", tab);
   //tab = ajoute_nombre_plateau(tab, genere_nombre());
   //affiche_plateau("affiche", tab);
   Plateau tab = {{2,2,2,2},{2,2,2,2},{2,2,0,2},{2,2,2,2}};
   affiche_plateau("affiche", tab);
   cout << "--------------------------------------------" << endl;
   tab = ajoute_nombre_plateau(tab, genere_nombre());
   affiche_plateau("affiche", tab);
   return 0;
}
