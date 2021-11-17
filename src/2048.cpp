#include "2048.hpp"

int main(void) {
   //cout << "Hello World!" << endl;
   //Plateau tab = {{2,4,8,16},{32,64,128,256},{512,1024,2048,0},{4096,2,2,2}};
   //affiche_plateau(plateau_to_string(tab));
   //test_plateau_to_string();
   //cout << "-----------------------------------------" << endl;
   //tab = ajoute_nombre_plateau(tab, genere_nombre());
   //affiche_plateau(plateau_to_string(tab));
   //cout << "-------------------------------------------" << endl;
   //Plateau tab2 = init_plateau(genere_nombre());
   //affiche_plateau(plateau_to_string(tab2));
   //cout << "---------------------------------------" << endl;
   Plateau tab3 = {{16,2,16,16},{16,16,16,16},{4,2,2,4},{2,2,4,8}};
   affiche_plateau(plateau_to_string(tab3));
   cout << "------------------------------------------" << endl;
   tab3 = deplacement("d", tab3);
   affiche_plateau(plateau_to_string(tab3));
   return 0;
}
