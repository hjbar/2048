#include "test.hpp"


void assert_string_equal(string got, string expected) {

  if (got != expected) {
    cout << "got:" << endl << "`" << endl << got << "`" << endl << "but expected:" << endl << "`" << endl << expected << "`" << endl;
  }

  assert (got == expected);

}


/** Effectue une serie de test sur la fonction affiche_plateau **/
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


void test_all() {
  test_plateau_to_string();
}
