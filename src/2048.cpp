#include "2048.hpp"

int main(void) {
   cout << "Hello World!" << endl;
   string os = affiche_plateau({{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {2,2,2,2}});
   return 0;
}
