#include "test.hpp"

void test_couleur_nombre(void)
{
	assert(couleur_nombre(4) == GREEN);
	assert(couleur_nombre(16) == PURPLE);
	assert(couleur_nombre(64) == BLUE);
	assert(couleur_nombre(512) == RED);
	assert(couleur_nombre(2048) == YELLOW);
	assert(couleur_nombre(8192) == CYAN);
}

void test_string_equal(string got, string expected)
{

	if(got != expected)
	{
		cout << "got:" << endl
			 << "`" << endl
			 << got << "`" << endl
			 << "but expected:" << endl
			 << "`" << endl
			 << expected << "`" << endl;
	}

	assert(got == expected);
}

void test_plateau_to_string(void)
{

	string got = plateau_to_string(
		{{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 2048, 4096}, {0, 0, 0, 0}});
	string expected =
		"*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * "
		"64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 "
		"*\n*************************\n*     *     *     *     *\n*************************\n";
	test_string_equal(got, expected);

	string got2 = plateau_to_string({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}});
	string expected2 =
		"*************************\n*     *     *     *     *\n*************************\n*     *  "
		"   *     *     *\n*************************\n*     *     *     *     "
		"*\n*************************\n*     *     *     *     *\n*************************\n";

	test_string_equal(got2, expected2);

	string got3 = plateau_to_string(
		{{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 2048, 4096}, {8192, 4096, 2048, 1024}});
	string expected3 =
		"*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * "
		"64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 "
		"*\n*************************\n*8192 *4096 *2048 *1024 *\n*************************\n";

	test_string_equal(got3, expected3);
}

void test_genere_nombre(void)
{
	int nombre = genere_nombre();
	assert(nombre == 2 or nombre == 4);
}

void test_init_plateau(void)
{
	Plateau tab = init_plateau(2);
	int nb_deux = 0;
	for(vector<int> ligne : tab)
	{
		for(int nombre : ligne)
		{
			if(nombre == 2)
			{
				nb_deux++;
			}
			else
			{
				assert(nombre == 0);
			}
		}
	}
	assert(nb_deux == 1);
}

void test_ajoute_nombre_plateau(void)
{
	Plateau tab = {{0, 2, 0, 2}, {2, 0, 2, 0}, {2, 2, 0, 0}, {0, 0, 2, 2}};
	int nombre_deux_ou_quatre = 0;
	tab = ajoute_nombre_plateau(tab, genere_nombre());
	for(vector<int> ligne : tab)
	{
		for(int nombre : ligne)
		{
			if(nombre == 2 or nombre == 4)
			{
				nombre_deux_ou_quatre++;
			}
		}
	}
	assert(nombre_deux_ou_quatre == 9);
}

void test_score_nombre(void)
{
	assert(score_nombre(0) == 0);
	assert(score_nombre(2) == 0);
	assert(score_nombre(4) == 4);
	assert(score_nombre(64) == 320);
	assert(score_nombre(1024) == 9216);
	assert(score_nombre(2048) == 20480);
}

void test_score_plateau(void)
{
	assert(score_plateau({{4, 0, 0, 2}, {8, 0, 0, 0}, {4, 2, 0, 0}, {64, 16, 4, 0}}, 7) == 368);
	assert(score_plateau({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}, {8, 0, 2, 0}}, 0) == 16);
	assert(score_plateau({{0, 0, 4, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}, {16, 4, 2, 0}}, 3) == 44);
	assert(score_plateau({{0, 0, 0, 0}, {0, 0, 2, 0}, {2, 0, 0, 0}, {4, 8, 8, 2}}, 3) == 24);
}

void test_plateau_est_plein(void)
{
	assert(not plateau_est_plein({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}));
	assert(not plateau_est_plein(
		{{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 2048, 4096}, {2, 4, 8, 0}}));
	assert(plateau_est_plein(
		{{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 2048, 4096}, {2048, 1024, 512, 256}}));
}

void test_fin_de_partie(void)
{
	assert(
		fin_de_partie({{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 2048, 4096}, {2, 4, 8, 16}}));
	assert(fin_de_partie({{2, 4, 2, 4}, {4, 2, 4, 2}, {2, 4, 2, 4}, {4, 2, 4, 2}}));
	assert(not fin_de_partie(
		{{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 0, 4096}, {2, 4, 8, 16}}));
	assert(not fin_de_partie(
		{{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 2048, 4096}, {2, 4, 16, 16}}));
	assert(not fin_de_partie(
		{{2, 4, 8, 16}, {32, 64, 128, 256}, {512, 1024, 2048, 16}, {2, 4, 8, 16}}));
	assert(not fin_de_partie({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}}));
}

void test_char_to_direction(void)
{
	assert(char_to_direction('d') == Right);
	assert(char_to_direction('g') == Left);
	assert(char_to_direction('b') == Bottom);
	assert(char_to_direction('h') == Top);
}

void test_decalage_nombre(void)
{
	Plateau tab_expected_d1 = {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}};
	Plateau tab_expected_g1 = {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}};
	Plateau tab_expected_b1 = {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}};
	Plateau tab_expected_h1 = {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}};
	assert(
		decalage_nombre(Right, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		tab_expected_d1);
	assert(decalage_nombre(Left, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		   tab_expected_g1);
	assert(
		decalage_nombre(Bottom, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		tab_expected_b1);
	assert(decalage_nombre(Top, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		   tab_expected_h1);

	Plateau tab_expected_d2 = {{0, 0, 2, 2}, {0, 0, 4, 4}, {4, 4, 4, 4}, {0, 2, 2, 2}};
	Plateau tab_expected_g2 = {{2, 2, 0, 0}, {4, 4, 0, 0}, {4, 4, 4, 4}, {2, 2, 2, 0}};
	Plateau tab_expected_b2 = {{2, 0, 0, 0}, {4, 0, 2, 4}, {4, 0, 4, 4}, {2, 4, 2, 2}};
	Plateau tab_expected_h2 = {{2, 4, 2, 4}, {4, 0, 4, 4}, {4, 0, 2, 2}, {2, 0, 0, 0}};
	assert(decalage_nombre(Right, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_d2);
	assert(decalage_nombre(Left, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_g2);
	assert(decalage_nombre(Bottom, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_b2);
	assert(decalage_nombre(Top, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_h2);

	Plateau tab_expected_d3 = {{0, 0, 2, 2}, {0, 0, 4, 4}, {0, 4, 4, 4}, {0, 2, 2, 2}};
	Plateau tab_expected_g3 = {{2, 2, 0, 0}, {4, 4, 0, 0}, {4, 4, 4, 0}, {2, 2, 2, 0}};
	Plateau tab_expected_b3 = {{0, 2, 0, 0}, {0, 4, 0, 2}, {0, 4, 4, 4}, {2, 2, 4, 2}};
	Plateau tab_expected_h3 = {{2, 2, 4, 2}, {0, 4, 4, 4}, {0, 4, 0, 2}, {0, 2, 0, 0}};
	assert(decalage_nombre(Right, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_d3);
	assert(decalage_nombre(Left, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_g3);
	assert(decalage_nombre(Bottom, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_b3);
	assert(decalage_nombre(Top, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_h3);
}

void test_deplacement(void)
{
	Plateau tab_expected_d1 = {{0, 16, 2, 32}, {0, 0, 32, 32}, {0, 4, 4, 4}, {0, 4, 4, 8}};
	Plateau tab_expected_g1 = {{16, 2, 32, 0}, {32, 32, 0, 0}, {4, 4, 4, 0}, {4, 4, 8, 0}};
	Plateau tab_expected_b1 = {{0, 0, 0, 0}, {32, 2, 32, 32}, {4, 16, 2, 4}, {2, 4, 4, 8}};
	Plateau tab_expected_h1 = {{32, 2, 32, 32}, {4, 16, 2, 4}, {2, 4, 4, 8}, {0, 0, 0, 0}};
	assert(deplacement(Right, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		   tab_expected_d1);
	assert(deplacement(Left, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		   tab_expected_g1);
	assert(deplacement(Bottom, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		   tab_expected_b1);
	assert(deplacement(Top, {{16, 2, 16, 16}, {16, 16, 16, 16}, {4, 2, 2, 4}, {2, 2, 4, 8}}) ==
		   tab_expected_h1);

	Plateau tab_expected_d2 = {{0, 0, 0, 4}, {0, 0, 0, 8}, {0, 0, 8, 8}, {0, 0, 2, 4}};
	Plateau tab_expected_g2 = {{4, 0, 0, 0}, {8, 0, 0, 0}, {8, 8, 0, 0}, {4, 2, 0, 0}};
	Plateau tab_expected_b2 = {{0, 0, 0, 0}, {2, 0, 2, 0}, {8, 0, 4, 8}, {2, 4, 2, 2}};
	Plateau tab_expected_h2 = {{2, 4, 2, 8}, {8, 0, 4, 2}, {2, 0, 2, 0}, {0, 0, 0, 0}};
	assert(deplacement(Right, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_d2);
	assert(deplacement(Left, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_g2);
	assert(deplacement(Bottom, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_b2);
	assert(deplacement(Top, {{2, 0, 2, 0}, {4, 0, 0, 4}, {4, 4, 4, 4}, {2, 0, 2, 2}}) ==
		   tab_expected_h2);

	Plateau tab_expected_d3 = {{0, 0, 0, 4}, {0, 0, 0, 8}, {0, 0, 4, 8}, {0, 0, 2, 4}};
	Plateau tab_expected_g3 = {{4, 0, 0, 0}, {8, 0, 0, 0}, {8, 4, 0, 0}, {4, 2, 0, 0}};
	Plateau tab_expected_b3 = {{0, 0, 0, 0}, {0, 2, 0, 2}, {0, 8, 0, 4}, {2, 2, 8, 2}};
	Plateau tab_expected_h3 = {{2, 2, 8, 2}, {0, 8, 0, 4}, {0, 2, 0, 2}, {0, 0, 0, 0}};
	assert(deplacement(Right, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_d3);
	assert(deplacement(Left, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_g3);
	assert(deplacement(Bottom, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_b3);
	assert(deplacement(Top, {{0, 2, 0, 2}, {0, 4, 4, 0}, {0, 4, 4, 4}, {2, 2, 0, 2}}) ==
		   tab_expected_h3);
}

void test_calcul_nombre_quatre(void)
{
	assert(calcul_nombre_quatre(0, 2) == 0);
	assert(calcul_nombre_quatre(0, 4) == 1);
	assert(calcul_nombre_quatre(10, 2) == 10);
	assert(calcul_nombre_quatre(10, 4) == 11);
}

void test_deplacement_possible(void)
{
	Plateau tab = {{0, 0, 0, 4}, {2, 4, 8, 16}, {64, 32, 16, 0}, {0, 0, 0, 0}};
	assert(deplacement_possible(Right, tab));
	assert(deplacement_possible(Left, tab));
	assert(deplacement_possible(Bottom, tab));
	assert(deplacement_possible(Top, tab));

	Plateau tab2 = {{2, 4, 8, 16}, {4, 8, 16, 32}, {8, 16, 32, 64}, {16, 32, 64, 128}};
	assert(not deplacement_possible(Right, tab2));
	assert(not deplacement_possible(Left, tab2));
	assert(not deplacement_possible(Bottom, tab2));
	assert(not deplacement_possible(Top, tab2));

	Plateau tab3 = {{0, 0, 2, 4}, {0, 0, 4, 2}, {0, 0, 0, 0}, {0, 0, 0, 0}};
	assert(not deplacement_possible(Right, tab3));
	assert(deplacement_possible(Left, tab3));
	assert(deplacement_possible(Bottom, tab3));
	assert(not deplacement_possible(Top, tab3));

	Plateau tab4 = {{0, 0, 0, 0}, {0, 0, 0, 0}, {2, 4, 0, 0}, {4, 2, 0, 0}};
	assert(deplacement_possible(Right, tab4));
	assert(not deplacement_possible(Left, tab4));
	assert(not deplacement_possible(Bottom, tab4));
	assert(deplacement_possible(Top, tab4));
}

void test_all(void)
{
	test_couleur_nombre();
	test_plateau_to_string();
	test_genere_nombre();
	test_init_plateau();
	test_ajoute_nombre_plateau();
	test_score_nombre();
	test_score_plateau();
	test_plateau_est_plein();
	test_fin_de_partie();
	test_char_to_direction();
	test_decalage_nombre();
	test_deplacement();
	test_calcul_nombre_quatre();
	test_deplacement_possible();
}
