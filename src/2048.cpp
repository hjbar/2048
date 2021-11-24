#include "2048.hpp"


int main(void) {

   srand((unsigned) time(NULL));

   test_all();

   string decision;
   bool arret_partie = false;
   while(not arret_partie) {
      jeu();
      decision = "_";
      while(not commande_est_valide(decision)) {
         cout << endl << "Entrer 'game' pour rejouer, entrer 'quit' pour quitter le jeu" << endl;
         decision = "";
         cin >> decision;
      }
      if(decision == "quit") {
         arret_partie = true;
      }
   }
   cout << endl << "Merci d'avoir joué ! A bientot :)" << endl;

   return 0;
}
