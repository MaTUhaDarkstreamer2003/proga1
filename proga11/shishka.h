#ifndef shishka_h
#define shishka_h

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class CRational {
    public:
        CRational (long long int ch, long long int zn);
        CRational (long long int ts, long long int ch, long long int zn);
        CRational (double j);
        /*CRational operator + (long long int ch, long long int zn);
        CRational operator + (long long int ts, long long int ch, long long int zn);
        CRational operator + (double j);
        CRational operator - (long long int ch, long long int zn);
        CRational operator - (long long int ts, long long int ch, long long int zn);
        CRational operator - (double j);
        CRational operator *  (long long int ch, long long int zn);
        CRational operator * (long long int ts, long long int ch, long long int zn);
        CRational operator * (double j);
        CRational operator / (long long int ch, long long int zn);
        CRational operator / (long long int ts, long long int ch, long long int zn);
        CRational operator / (double j); */
        CRational operator + (CRational drob);
        CRational operator - (CRational drob);
        CRational operator * (CRational drob);
        CRational operator / (CRational drob);
        CRational operator + (long long int a);
        CRational operator - (long long int a);
        CRational operator * (long long int a);
        CRational operator / (long long int a);
        CRational operator + (double a);
        CRational operator - (double a);
        CRational operator * (double a);
        CRational operator / (double a);
        void show ();
        double value();
    //protected:
        /*void trueplus (vector <long long int> yagodka);
        void trueminus (vector <long long int> yagodka);
        void truedevide (vector <long long int> yagodka);
        void truemultiple (vector <long long int> yagodka);
        */
        vector <long long int> cut (vector <long long int> babochka);
        vector <long long int> oreh (double j);
        vector <long long int> bobka;
};


#endif