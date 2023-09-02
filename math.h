#include <gmpxx.h>

class Point
{
private:
    
    bool identity;
    mpf_class x,y;
    mpf_class a, b;
public:
    Point() : identity(true) {}
    Point(bool b);
    Point(int x, int y);
    mpf_class getX() const{
        return this->x;
    };
    void setX(mpf_class _x){
        this->x = _x;
    }
    mpf_class getY() const{
        return this->y;
    };

    void setY(mpf_class _y) {
        this->y = _y;
    };
    mpf_class geta() const{
        return this->x;
    };
    void seta(double _x){
        this->x = _x;
    }
    mpf_class getb() const{
        return this->y;
    };

    void setb(double _y) {
        this->y = _y;
    };


    bool isIdentity() const{
        return this->identity;
    };

    void setIdentity(bool _identity){
        this->identity = _identity;
    };

    Point operator=(const Point& P);
    //bool operator==(const Point& P) const;
    //void print();
};


class Line{
    private:
        int A, B;
    public:
        Line();
        Line(int A, int B);
        ~Line();
        bool isZeroDiscriminant();
        int getA(){
            return this->A;
        };
        int getB(){
            return this->B;
        };
};

class Curve:public Line{
    private:
        int C;
    public:
        Curve();
        Curve(int A, int B, int C);
        ~Curve();
        //bool isZeroDiscriminant();
        //int getA(){
        //    return this->A;
        //};
        //int getB(){
        //    return this->B;
        //};
	int getC(){
	    return this->C;
	};

};

class EllipticCurve:public Curve{
	private:
	int D;
	Point identity;
	public:
    EllipticCurve();
    EllipticCurve(int A, int B, int C, int D);
    ~EllipticCurve();
       int getD(){
            return this->D;
        };
        const Point& _inv(Point& Q, const Point& P);
	    bool verifyPoint(const Point& P) const;
       Point& _double(Point& R, const Point& P);




};


