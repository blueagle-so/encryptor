#include <gmp.h>
#include <math.h>
#include <gmpxx.h>
#include <iostream>
#include <string>
//#include <int128.h>
class Point{
        public:
	Point(std::string x_, std::string y_):x(x_), y(y_){}
        std::string x;
        std::string y;

};

class Curve{
    public:
        //# curve parameters for NIST P-256 (ANSI prime256v1, SECG secp256r1)
        //# https://www.nsa.gov/ia/_files/nist-routines.pdf
        //# http://perso.univ-renes1.fr/sylvain.duquesne/master/standards/sec2_final.pdf
        //double p=pow(2,256)-pow(2,224)+pow(2,192)+pow(2,96)-1;
        std::string p="115792089210356248762697446949407573530086143415290314195533631308867097853951";
	//double a = p-3;
	std::string b = "41058363725152142129326129780047268409114441015993725554835256314039467401291";
        //gx = bi("6b17d1f2 e12c4247 f8bce6e5 63a440f2 77037d81 2deb33a0 f4a13945 d898c296".replace(" ", "").encode().hex())
        //gy = bi("4fe342e2 fe1a7f9b 8ee7eb4a 7c0f9e16 2bce3357 6b315ece cbb64068 37bf51f5".replace(" ", "").encode().hex())
        //g = [gx,gy]
	std::string n = "115792089210356248762697446949407573529996955224135760342422259061068512044369";

bool valid(Point point){
//        mpz_class xP = point.x
//        if xP == NULL:
//            return false;
//        mpz_class yP=point.y;
//        return yP^2 % p == (pow(xP, 3, p)+a*xP+b) % p;


mpz_class xP(point.x);
mpz_class yP(point.y);
return ((yP*yP) % mpz_class(p))==((((xP*xP*xP)% mpz_class(p))+(mpz_class(p)-3)*xP+mpz_class(b)) % mpz_class(p));



}




};



int main(void)
{
Curve curve;   

//mpz_class f(0);
//f+curve.n;
//mpz_class j(curve.n);
//gmp_printf("%Zd",curve.p);
//mpz_class i(curve.n);
//mpz_t x;
//mpz_class p(curve.p);
//mpz_class p2(curve.p2);
//mpz_class p3(curve.p3);
//mpz_class p4(curve.p4);
//mpz_class p5(curve.p5);
Point point("48439561293906451759052585252797914202762949526041747995844080717082404635286", "36134250956749795798585127919587881956611106672985015071877198253568414405109");


if(curve.valid(point))std::cout<<"true"<<std::endl;

   return EXIT_SUCCESS;
}
