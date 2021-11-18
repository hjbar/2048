#include "2048.hpp"

int main(void) {

   Plateau tab3 = {{16,2,16,16},{16,16,16,16},{4,2,2,4},{2,2,4,8}};
   affiche_plateau(plateau_to_string(tab3));
   cout << "------------------------------------------" << endl;
   tab3 = deplacement("d", tab3);
   affiche_plateau(plateau_to_string(tab3));

   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;

   Plateau tab4 = {{2,0,2,0},{4,0,0,4},{4,4,4,4},{2,0,2,2}};
   affiche_plateau(plateau_to_string(tab4));
   cout << "------------------------------------------" << endl;
   tab4 = deplacement("d", tab4);
   affiche_plateau(plateau_to_string(tab4));

   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;

   Plateau tab5 = {{0,2,0,2},{0,4,4,0},{0,4,4,4},{2,2,0,2}};
   affiche_plateau(plateau_to_string(tab5));
   cout << "------------------------------------------" << endl;
   tab5 = deplacement("d", tab5);
   affiche_plateau(plateau_to_string(tab5));

   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;

   test_all();

   return 0;
}
