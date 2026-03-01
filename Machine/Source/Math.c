#include "Math.h"


unsigned char xOR(unsigned char numA,unsigned char numB) {

    return (numA & ~numB) | ((numB) & ~numA);
}






