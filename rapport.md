# Rapport de projet

## Auteurs

- Barreiro Hugo hugo.barreiro@universite-paris-saclay.fr MI1 
- Ayora Duarte Francisco francisco.ayora-duarte@universite-paris-saclay.fr MI1

## Résumé du travail effectué

Niveau 0 : 

Toutes les étapes sont réalisées et documentées ; les fonctions gérant l’aléatoire 
ne sont pas testées. Certaines fonctions d’affichage sont testées. Les fonctions 
gérant les tests ne sont pas testées. Le reste des fonctions est testé.

Pour l’affichage, on a fait appel à une bibliothèque externe : libfmt (téléchargée
grâce à la commande sudo apt install libfmt-dev (cf 
https://github.com/fmtlib/fmt pour plus de détails). On a dû ajouter le linker –
lfmt dans le Makefile). 


Niveau 1 : 

L’étape des couleurs dans la console est réalisée et documentée  mais  est 
partiellement testée. Pour ce faire, on envoie un code système à l’aide de cout 
pour changer la couleur du texte.

L’étape  de  la  saisie  automatique  et  de  l’utilisation  des  flèches  a  été 
partiellement réalisée et non testée mais documentée. Après quelques 
expérimentations et recherches, on s’est rendu compte que les flèches étaient 
composées  de  trois  caractères  :  le  caractère d’échappement ‘^[', ‘[‘ et une 
lettre majuscule ‘A’, ‘B’, ‘C’ ou ‘D’.  Une  solution  était  donc  de  récupérer  un 
premier caractère, si celui-ci était une lettre du clavier alors on la renvoie sinon si 
ce caractère était celui d’échappement alors on récupère les deux suivants et on 
renvoie la direction associée. Néanmoins, pour réaliser cela, nous devions avoir 
en notre possession  une fonction permettant de récupérer un caractère sans 
appuyer  sur  entrée.  Ne  sachant  pas  implémenter  cela,  on  a  récupéré  une 
fonction getch (cf https://qastack.fr/programming/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed) sur internet afin 
de tester notre  méthode. Ainsi cette méthode fonctionne, mais cette dernière 
ne dépendant pas entièrement de notre travail, on a préféré la commenter dans 
notre code et ne pas s’en servir.

L’étape du rafraichissement de l’écran est réalisée et documentée mais non 
testée. Pour la réaliser, un tuto sur comment créer un éditeur de texte a été suivi 
(cf https://viewsourcecode.org/snaptoken/kilo/). A chaque coup, la console est 
nettoyée  en  envoyant  un code système à l’aide de cout ;  cependant,  si  on 
“remonte” on peut observer les coups précédents.  Une  solution  aurait  été 
de faire passer le terminal en "row mode" afin de lui envoyer les bonnes commandes afin qu'il s'efface proprement. Néanmoins, cela n'a pas été réussi.

L’étape de la non-utilisation de variables globales et du calcul du score  a  été 
réalisée,  documentée  et  testée.  Remarque :  on  aurait  pu  implémenter  une 
fonction récursive pour calculer le score. 


Niveau 2 : 

L’étape de la compilation automatique et donc du Makefile a été réalisée mais 
non documentée et testée.

L’étape  du  git  a  été  réalisée.  On  a  décidé  d’utiliser  Github  (cf 
https://github.com/hjbar/2048). 


Niveau 3 : 

L’étape de l’interface graphique a été envisagée. Après quelques recherches sur 
les différentes interfaces graphiques, on a décidé de se pencher sur SDL car celle-ci nous paraissait plus intéressante dans notre cas, au niveau de son utilisation et de ses fonctionnalités notamment. Un tutoriel a été 
suivi sur un site internet jusqu’à  son  étape  16 (cf 
https://lazyfoo.net/tutorials/SDL/index.php#Color%20Keying). Néanmoins, 
même si on a réussi à créer des fenêtres de notre côté, nous n’avons pas réussi 
à implémenter quelque chose d’intéressant pour notre projet 2048 par faute de 
temps. 


Remarque : On utilise .clang-format pour indenter correctement le code.

## Démonstration

Par exemple, pour les fonctions gérant l’affichage,

les commandes suivantes :


```
Plateau tab = {{0, 2, 4, 8}, {16, 32, 64, 128}, {256, 512, 1024, 2048}, {4096, 8192, 0, 0}};
affiche_plateau(plateau_to_string_avec_couleur(tab));
```

donnent le résultat suivant :

(cf le fichier exemple_affichage.png)

Pour ce faire, on a implémenté les fonctions suivantes qui génèrent une chaine 
de caractères à partir d’un tableau et la valeur de ses nombres pour la couleur 
et une autre qui affiche cette chaîne générée :


```
string plateau_to_string_avec_couleur(Plateau t)
{
  ostringstream os;
  os << WHITE << "*************************" << RESET_COLOR << endl;
  for(vector<int> ligne : t)
  {
    os << WHITE << "*" << RESET_COLOR;
    for(int nombre : ligne)
    {
      // On utilise une biblioteque externe fmt/core.h qui permet d'implementer la biblioteque stdlib::fmt qui est presente dans le standard de c++ 2020 (mais non implementer dans le compilateur g++) qui permet d'aligne les nombres correctement sur un format de 5 characteres
      string s = nombre != 0 ? fmt::format("{:^5}", nombre) : "     ";
      os << couleur_nombre(nombre);
      os << s << WHITE << "*" << RESET_COLOR;
    }
    os << endl << WHITE << "*************************" << RESET_COLOR << endl;
  }
  return os.str();
}
```

Cette  fonction  permet  de  créer  une  chaine  de  caractères  en  fonction  de  la 
valeur des nombres grâce à la fonction couleur_nombre(nombre) :


```
string couleur_nombre(int nombre)
{
  if(nombre <= 4)
  {
    return GREEN;
  }
  else if(nombre <= 16)
  {
    return PURPLE;
  }
  else if(nombre <= 64)
  {
    return BLUE;
  }
  else if(nombre <= 512)
  {
    return RED;
  }
  else if(nombre <= 2048)
  {
    return YELLOW;
  }
  else
  {
    return CYAN;
  }
}
```

Cette  fonction  permet  de  renvoyer  la  couleur  correspondante  à  la  valeur  des 
nombres. Pour ce faire on a dû définir les couleurs :


```
#define WHITE "\033[0;97m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET_COLOR "\033[0m"
```

Les #define ont pour rôle de remplacer dans le code un mot clef par ce qu'on lui donne comme valeur avant la compilation. Par exemple, dans notre cas, à chaque fois qu'on écrit WHITE dans notre code, cela est remplacé par "\033[0;97m"


```
void affiche_plateau(string plateau)
{
  cout << plateau;
}
```

Cette fonction permet d’afficher la chaîne de caractères créée au préalable.

Pour s’assurer qu’on affiche correctement le plateau de jeu, on vérifie que la 
chaîne de caractères générée est bien celle qu’on attend :


```
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
```


```
void test_string_equal(string got, string expected)
{

  if(got != expected)
  {
    cout << "got:" << endl
      │<< "`" << endl
      │<< got << "`" << endl
      │<< "but expected:" << endl
      │<< "`" << endl
      │<< expected << "`" << endl;
  }

  assert(got == expected);
}
```

On a aussi créé le Makefile suivant afin d’avoir une compilation automatique :


```
NAME := 2048

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := _build

CXX ?= c++
CPPFLAGS ?= -std=c++20 -W -Wall -Wextra -Wdouble-promotion -Wformat -Winit-self  -Wmissing-include-dirs -Wswitch-default  -Wswitch-enum -Wunused -Wunused-parameter -Wuninitialized -Wunknown-pragmas -fstrict-overflow -Wstrict-overflow=2 -Wmissing-format-attribute -Wstrict-aliasing -Wfloat-equal -Wundef -Wpointer-arith -Wcast-qual -Wcast-align -Wconversion -Wmissing-declarations -Wredundant-decls -Wpacked -Wpadded -Winline -Wvla -Wdisabled-optimization -Wstack-protector -Winvalid-pch -Wshadow -pedantic-errors --pedantic -g -Werror -O3 -pipe -funsigned-char -fsigned-bitfields -fPIC -fdiagnostics-color=auto

INCLUDE := -I$(INCLUDE_DIR)

LDFLAGS := -lfmt -fPIE

TARGET := $(NAME).exe
HPP_FILES := $(wildcard $(INCLUDE_DIR)/*.hpp)
CPP_FILES := $(HPP_FILES:$(INCLUDE_DIR)/%.hpp=$(SRC_DIR)/%.cpp)
O_FILES := $(CPP_FILES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

.PHONY: clean mrproper

default: build

all: build clean

build: $(TARGET)

$(BUILD_DIR):
  mkdir -p $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
  $(CXX) -o $@ -c $< $(CPPFLAGS) $(INCLUDE)

$(TARGET): $(BUILD_DIR) $(O_FILES)
  $(CXX) -o $@ $(O_FILES) $(LDFLAGS)

clean:
  rm -rf $(BUILD_DIR)

mrproper: clean
  rm -f $(TARGET)

fmt:
  find src/ -iname \*.cpp | xargs clang-format -style=file -i
  find include/ -iname \*.hpp | xargs clang-format -style=file -i
```

Ce Makefile compile avec le compilateur g++ et la version c++20. Le Makefile va 
chercher les fichiers .hpp dans le répertoire include et ses fichiers .cpp associés 
dans le répertoire src. Les fichiers .o servant à la création de l’exécutable sont 
stockés dans le répertoire créé _build. 

La compilation prend en compte plein de paramètres assurant au maximum la 
fiabilité du programme. Des linkers sont aussi utilisés car ceux-ci participent à la dernière étape de la compilation et permettent d'avoir un exécutable.

Seuls les fichiers modifiés sont re-compilés ; pour les autres, les fichiers .o sont 
ré-utilisés.  Ceci  permet  une  compilation  plus  rapide  surtout  pour  les  grands 
projets.

Pour calculer le score, on utilise la fonction suivante :


```
int score_plateau(Plateau tab, int nombre_de_quatre)
{
  int score = 0;
  for(vector<int> ligne : tab)
  {
    for(int nombre : ligne)
    {
      score = score + score_nombre(nombre);
    }
  }
  // Les nombres 4 generes par le jeu ne rapporte pas de points, il faut donc les retirer de score
  return score - (4 * nombre_de_quatre);
}
```

Cette  fonction  calcule  le  nombre  de  points  donnés  par  chaque nombre  du 
plateau. A la fin, il faut renvoyer la somme calculée  - le nombre de quatre qui 
sont générés aléatoirement, car il ne rapporte pas de points.

Pour ce faire, on utilise une fonction qui calcule le nombre de points donné par 
un nombre :


```
int score_nombre(int nombre)
{
  int score = 0;
  // Si nombre vaut 32, pour creer ce nombre on a obtenu les points de 32*1 + 16*2 + 8*4 + 4*8, d'ou la creation de la variable coefficient
  int coefficient = 1;
  // Le nombre 2 etant obligatoirement generer par le jeu, on ne peut pas en obtenir de points
  while(nombre > 2)
  {
    score = score + (nombre * coefficient);
    nombre = (nombre / 2);
    coefficient = (coefficient * 2);
  }
  return score;
}
```

Chaque  nombre  donne  sa  propre  valeur  en  points  +  deux  fois  son  nombre 
précédent, qui eux-mêmes donnent deux fois leurs nombres précédents et ainsi 
de suite jusqu’à arriver au nombre 2 qui ne donne pas de points. Par exemple, 
le nombre 16 donne 16 + 8 + 8 + 4 + 4 + 4 + 4 points.

On a aussi effectué les tests suivants afin de s’assurer du bon fonctionnement de 
ces fonctions :


```
void test_score_plateau(void)
{
  assert(score_plateau({{4, 0, 0, 2}, {8, 0, 0, 0}, {4, 2, 0, 0}, {64, 16, 4, 0}}, 7) == 368);
  assert(score_plateau({{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}, {8, 0, 2, 0}}, 0) == 16);
  assert(score_plateau({{0, 0, 4, 0}, {0, 0, 0, 0}, {2, 0, 0, 0}, {16, 4, 2, 0}}, 3) == 44);
  assert(score_plateau({{0, 0, 0, 0}, {0, 0, 2, 0}, {2, 0, 0, 0}, {4, 8, 8, 2}}, 3) == 24);
}
```


```
void test_score_nombre(void)
{
  assert(score_nombre(0) == 0);
  assert(score_nombre(2) == 0);
  assert(score_nombre(4) == 4);
  assert(score_nombre(64) == 320);
  assert(score_nombre(1024) == 9216);
  assert(score_nombre(2048) == 20480);
}
```

## Organisation du travail

Nous avons passé  environ  80  heures sur  le  projet.

Afin de communiquer et mettre en commun nos travaux, nous avons décidé de 
communiquer via Discord et via messages téléphoniques. Pour mettre en ligne 
notre code, nous avons également décidé d’utiliser Github. 

Pour  réaliser  les  étapes  du  niveau  0,  nous  avions  décidé,  chacun  de  notre  côté, 
d’implémenter les fonctions nécessaires. Ensuite, nous avions décidé de mettre 
en  commun  nos  fonctions  afin,  soit  de  les  améliorer  avec  les  remarques  de l'autre, soit simplement de garder la meilleure si aucune amélioration n’avait été 
trouvée.  
 
Ensuite,  pour  les  niveaux  suivants,  la  démarche  reste  relativement  semblable. 
C’est-à-dire qu'avant d’implémenter nos fonctions chacun de notre côté, nous 
avons  dû  faire  des  recherches  et  des  expérimentations  afin  de  réaliser  les 
différentes étapes. De plus, pour l’étape de la saisie automatique et des flèches, 
nous  avons  collaboré,  côte-à-côte,  dans  une  même  salle.  Ainsi,  nous  pouvions 
mieux expliquer nos  recherches  et  conseils  dans  le  but  d’améliorer  nos 
implémentations.

## Prise de recul

Plusieurs difficultés ont été rencontrées.

Tout d’abord, Francisco a eu des soucis avec son ordinateur durant le projet, c’est-à-dire,  que  le  code n’arrivait pas à compiler alors  que  celui-ci  était 
correct. Résoudre ce problème a été couteux en énergie et surtout en temps. 
En effet, la non-totale compatibilité des environnements nous a ralenti. 
Francisco étant sur Windows et Hugo sur Linux, certains programmes 
fonctionnant sous Linux ne fonctionnaient pas sur Windows. Certaines 
bibliothèques  ne  se  trouvent  que sous Windows et d’autres uniquement sous 
Linux.  Remarque : certains  programmes  fonctionnaient  sous  Linux  et  non  sur 
JupyterHub.

Ensuite, les étapes demandant des connaissances supplémentaires par rapport 
à celles apportées en cours ont été particulièrement compliquées. En effet, pour 
les réaliser, on devait effectuer des recherches sur internet, comprendre  des 
concepts nouveaux et faire des expérimentations.

Ce projet a permis d’apprendre de nouvelles choses.

Notamment sur la conception d’un jeu vidéo, d’un projet plus conséquent, 
demandant d’utiliser la  compilation  séparée  avec  la  répartition  des  fonctions 
dans divers fichiers. Cela a permis aussi de se rendre compte que chaque langage 
est  large  et  dispose  de  plus  de  fonctionnalités  que  celles  vues  en  cours.  On  a  pu 
aussi apprendre à davantage se débrouiller par soi-même car certains niveaux 
n’étaient pas guidés et demandaient une réelle réflexion.  
 
Si  ce  projet  était  à  refaire,  on  aurait  plus  mis  l’accent sur le travail en groupe 
dans la même salle. Car la possibilité de faire des commentaires en direct à son 
camarade  permet de mieux saisir ses idées et d’avancer plus rapidement.  De 
plus, on aurait dû adopter une répartition du travail plus stricte, plus structurée 
et  plus  précise  afin  que  chacun  se  mette  au  travail  rapidement, au même rythme  et  à  la  même 
intensité.
