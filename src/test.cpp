#include "test.hpp"


/** Fonction qui effectue un test sur plateau_to_string
 * @param got la chaine de caractere renvoyee par plateau_to_string
 * @param expected la chaine de caractere que l'on attend
 **/
void assert_string_equal(string got, string expected) {

  if (got != expected) {
    cout << "got:" << endl << "`" << endl << got << "`" << endl << "but expected:" << endl << "`" << endl << expected << "`" << endl;
  }

  assert (got == expected);

}


/** Lance une serie de test sur la fonction plateau_to_string **/
void test_plateau_to_string() {

  string got = plateau_to_string ({{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {0,0,0,0}});
  string expected = "*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * 64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 *\n*************************\n*     *     *     *     *\n*************************\n";

  assert_string_equal(got, expected);

  string got2 = plateau_to_string ({{0,0,0,0}, {0,0,0,0}, {0,0,0,0}, {0,0,0,0}});
  string expected2 = "*************************\n*     *     *     *     *\n*************************\n*     *     *     *     *\n*************************\n*     *     *     *     *\n*************************\n*     *     *     *     *\n*************************\n";

  assert_string_equal(got2, expected2);

  string got3 = plateau_to_string ({{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {8192,4096,2048,1024}});
  string expected3 = "*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * 64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 *\n*************************\n*8192 *4096 *2048 *1024 *\n*************************\n";

  assert_string_equal(got3, expected3);

}


/** Teste la fonction genere_nombre **/
void test_genere_nombre() {
  int nombre = genere_nombre();
  assert(nombre == 2 or nombre == 4);
}


/** Teste la fonction init_plateau **/
void test_init_plateau() {
  Plateau tab = init_plateau(2);
  int nb_deux = 0;
  for(vector<int> ligne : tab) {
    for(int nombre : ligne) {
      if(nombre == 2) {
        nb_deux++;
      } else {
        assert(nombre == 0);
      }
    }
  }
  assert(nb_deux == 1);
}


/** Teste la fonction ajoute_nombre_plateau **/
void test_ajoute_nombre_plateau() {
  Plateau tab = {{0,2,0,2}, {2,0,2,0}, {2,2,0,0}, {0,0,2,2}};
  int nombre_deux_ou_quatre = 0;
  tab = ajoute_nombre_plateau(tab, genere_nombre());
  for(vector<int> ligne : tab) {
    for(int nombre : ligne) {
      if(nombre == 2 or nombre == 4) {
        nombre_deux_ou_quatre++;
      }
    }
  }
  assert(nombre_deux_ou_quatre == 9);
}


/** Lance une serie de test pour la fonction score_nombre **/
void test_score_nombre() {
  assert(score_nombre(0) == 0);
  assert(score_nombre(2) == 0);
  assert(score_nombre(4) == 4);
  assert(score_nombre(64) == 320);
  assert(score_nombre(1024) == 9216);
  assert(score_nombre(2048) == 20480);
}


/** Lance une serie de test pour la fonction score_plateau **/
void test_score_plateau() {
  assert(score_plateau({{4,0,0,2},{8,0,0,0},{4,2,0,0},{64,16,4,0}}, 7) == 368);
  assert(score_plateau({{0,0,0,0},{0,0,0,0},{0,0,0,2},{8,0,2,0}}, 0) == 16);
  assert(score_plateau({{0,0,4,0},{0,0,0,0},{2,0,0,0},{16,4,2,0}}, 3) == 44);
  assert(score_plateau({{0,0,0,0},{0,0,2,0},{2,0,0,0},{4,8,8,2}}, 3) == 24);
}


/** Lance une serie de test pour la fonction fin_de_partie **/
void test_fin_de_partie() {
  assert(fin_de_partie({{2,4,8,16},{32,64,128,256},{512,1024,2048,4096},{2,4,8,16}}));
  assert(fin_de_partie({{2,4,2,4},{4,2,4,2},{2,4,2,4},{4,2,4,2}}));
  assert(not fin_de_partie({{2,4,8,16},{32,64,128,256},{512,1024,0,4096},{2,4,8,16}}));
  assert(not fin_de_partie({{2,4,8,16},{32,64,128,256},{512,1024,2048,4096},{2,4,16,16}}));
  assert(not fin_de_partie({{2,4,8,16},{32,64,128,256},{512,1024,2048,16},{2,4,8,16}}));
  assert(not fin_de_partie({{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}}));
}


/** Lance une serie de test pour la fonction valide_direction **/
void test_valide_direction() {
  assert(valide_direction("d"));
  assert(valide_direction("g"));
  assert(valide_direction("b"));
  assert(valide_direction("h"));
  assert(not valide_direction("z"));
  assert(not valide_direction("a"));
}


/** Lance une serie de test pour la fonction string_to_direction **/
void test_string_to_direction() {
  assert(string_to_direction("d") == Right);
  assert(string_to_direction("g") == Left);
  assert(string_to_direction("b") == Bottom);
  assert(string_to_direction("h") == Top);
}


/** Fonction qui lance le test de toutes les fonctions **/
void test_all() {
  test_plateau_to_string();
  test_genere_nombre();
  test_init_plateau();
  test_ajoute_nombre_plateau();
  test_score_nombre();
  test_score_plateau();
  test_fin_de_partie();
  test_string_to_direction();
  test_valide_direction();
}
