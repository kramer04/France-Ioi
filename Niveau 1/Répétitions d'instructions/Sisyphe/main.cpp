#include "robot.h"
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main(){
repeat(21){
haut();
droite();
}
repeat(21){
gauche();
bas();
}
}
