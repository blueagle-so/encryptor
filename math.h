class Curve{
    private:
        int A, B, C, D;
    public:
        Curve();
        Curve(int A, int B, int C, int D);
        ~Curve();
        bool isZeroDiscriminant();
        int getA(){
            return this->A;
        };
        int getB(){
            return this->B;
        };
	int getC(){
	    return this->C;
	};
	int getD(){
	    return this->D;
	};


};

class EllipticCurve:public Curve{
public:
    EllipticCurve();
    EllipticCurve(int A, int B, int C, int D);
    ~EllipticCurve();





};


