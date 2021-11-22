#include "2048.hpp"

int main(void) {

   srand((unsigned) time(NULL));

   test_all();


   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;

   Plateau tab = init_plateau(genere_nombre());
   affiche_plateau(plateau_to_string(tab));

   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;

   Plateau tab3 = {{16,2,16,16},{16,16,16,16},{4,2,2,4},{2,2,4,8}};
   affiche_plateau(plateau_to_string(tab3));
   cout << "------------------------------------------" << endl;
   tab3 = deplacement(string_to_direction("h"), tab3);
   affiche_plateau(plateau_to_string(tab3));

   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;

   Plateau tab4 = {{2,0,2,0},{4,0,0,4},{4,4,4,4},{2,0,2,2}};
   affiche_plateau(plateau_to_string(tab4));
   cout << "------------------------------------------" << endl;
   tab4 = deplacement(string_to_direction("h"), tab4);
   affiche_plateau(plateau_to_string(tab4));

   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;

   Plateau tab5 = {{0,2,0,2},{0,4,4,0},{0,4,4,4},{2,2,0,2}};
   affiche_plateau(plateau_to_string(tab5));
   cout << "------------------------------------------" << endl;
   tab5 = deplacement(string_to_direction("h"), tab5);
   affiche_plateau(plateau_to_string(tab5));

   cout << "------------------------------------------" << endl;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "------------------------------------------" << endl;


   return 0;
}
