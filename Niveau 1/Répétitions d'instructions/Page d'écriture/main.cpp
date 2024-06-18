#include <iostream>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int main(){
repeat(30){
std::cout<<"a_";
}
std::cout<<std::endl;
repeat(30){
std::cout<<"b_";
}
std::cout<<std::endl;
repeat(30){
std::cout<<"c_";
}
}
