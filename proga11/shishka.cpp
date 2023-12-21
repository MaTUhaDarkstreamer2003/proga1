#include <iostream>
#include "shishka.h"
#include <math.h>

    vector <long long int> CRational::oreh(double j) {
        vector <long long int> pompa;
        pompa.clear();
        pompa.push_back(0); 
        long long int denumerator = 1000000000;
        long long int numerator = (double(j)*denumerator);
        if (j == 0) {
            pompa.push_back(0);
            pompa.push_back(0);
        }
        if (j != 0) {
            pompa.push_back(numerator);
            pompa.push_back(denumerator); 
        }
        pompa = cut (pompa);
        return pompa;
    };

    CRational::CRational (long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl;
            this->bobka.clear();
            this->bobka.push_back(0);
            this->bobka.push_back(0);
            this->bobka.push_back(0);
        } else {
            this->bobka.clear();
            this->bobka.push_back(0);
            this->bobka.push_back(ch);
            this->bobka.push_back(zn);
            this->bobka = cut(this->bobka);
        }
    };

    CRational::CRational (long long int ts, long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl;
            this->bobka.clear();
            this->bobka.push_back(0);
            this->bobka.push_back(0);
            this->bobka.push_back(0);
        } else {
            this->bobka.clear();
            this->bobka.push_back(ts);
            this->bobka.push_back(ch);
            this->bobka.push_back(zn);
            this->bobka = cut(this->bobka);
        }
    };

    CRational::CRational (double j) {
        this->bobka.clear();
        this->bobka = oreh (j);
        this->bobka = cut(this->bobka);
    };

    /*CRational CRational::CRational operator + (long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(0);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        trueplus (yagodka);
        return CRational(this->bobka);
        }
    };

    CRational CRational::CRational operator + (long long int ts, long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl ;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(ts);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        trueplus (yagodka);
        return CRational(this->bobka);
        }
    };

    CRational CRational::CRational operator + (double j) {
        vector <long long int> yagodka = oreh (j);
        cut(yagodka);
        trueplus (yagodka);
        return CRational(this->bobka);
    };

    void CRational::trueplus (vector <long long int> yagodka) {
        this->bobka[0] += yagodka[0];
        long long int a1 = this->bobka [1] * yagodka[2];
        long long int a2 = this->bobka [2] * yagodka[1];
        long long int b = bobka[2] * yagodka[1];
        this->bobka [1] = a1 + a2;
        this->bobka[2] = b;
        cut(this->bobka);
    };

    CRational CRational::CRational operator - (long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl ;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(0);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        trueminus (yagodka);
        return CRational(this->bobka);
        }
    };

    CRational CRational::CRational operator - (long long int ts, long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl ;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(ts);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        trueminus (yagodka);
        return CRational(this->bobka);
        }
    };

    CRational CRational::CRational operator - (double j) {
        vector <long long int> yagodka = oreh (j);
        cut(yagodka);
        trueminus (yagodka);
        return CRational(this->bobka);
    };

    void CRational::trueminus (vector <long long int> yagodka) {
        this->bobka[0] += yagodka[0];
        long long int a1 = this->bobka [1] * yagodka[2];
        long long int a2 = this->bobka [2] * yagodka[1];
        long long int b = bobka[2] * yagodka[1];
        this->bobka [1] = a1 - a2;
        this->bobka[2] = b;
        cut(this->bobka);
    };

    CRational CRational::CRational operator * (long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl ;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(0);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        truemultiple (yagodka);
        return CRational(this->bobka);
        }
    };

    CRational CRational::CRational operator * (long long int ts, long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl ;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(ts);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        truemultiple (yagodka);
        return CRational(this->bobka);
        }
    };

    CRational CRational::CRational operator * (double j) {
        vector <long long int> yagodka = oreh (j);
        cut(yagodka);
        truemultiple (yagodka);       
        return CRational(this->bobka);
    };

    void CRational::truemultiple (vector <long long int> yagodka) {
        long long int a = this->bobka[0]*this->bobka[2] + this->bobka [1];
        long long int b = yagodka[0]*yagodka[2] + yagodka[1];
        long long int c = this->bobka [2] * yagodka[2];
        this->bobka.clear();
        this->bobka.push_back(0);
        this->bobka.push_back(a*b);
        this->bobka.push_back(c);
        cut(this->bobka);
    };

    CRational CRational::CRational operator / (long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl ;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(0);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        truedevide (yagodka);
        }
    };

    CRational CRational::CRational operator / (long long int ts, long long int ch, long long int zn) {
        if (zn == 0) {
            cout << "imposible denumerator value" << endl ;
            return CRational(this->bobka);
        } else {
        vector <long long int> yagodka;
        yagodka.push_back(ts);
        yagodka.push_back(ch);
        yagodka.push_back(zn);
        cut(yagodka);
        truedevide (yagodka);
        }
    };

    CRational CRational::CRational operator / (double j) {
        vector <long long int> yagodka = oreh (j);
        cut(yagodka);
        truedevide (yagodka); 
        return CRational(this->bobka);
    };

    void CRational::truedevide (vector <long long int> yagodka) {
        long long int a = this->bobka[0]*this->bobka[2] + this->bobka [1];
        long long int b = yagodka[2];
        long long int c = this->bobka [2] * (yagodka[0]*yagodka[2] + yagodka[1]);
        this->bobka.clear();
        this->bobka.push_back(0);
        this->bobka.push_back(a*b);
        this->bobka.push_back(c);
        cut(this->bobka);
    };

    */

    CRational CRational::operator + (CRational drob) {
        vector <long long int> temp = this->bobka;
        vector <long long int> temp2 = drob.bobka;
        if (temp[2] == 1) {
            return (CRational (temp[0] + temp2[0], temp2[1], temp2[2]));
        } else if (temp2[2] == 1) {
            return (CRational (temp2[0] + temp[0], temp[1], temp[2]));
        } else { 
        temp[0] += temp2[0];
        long long int a1 = temp [1] * temp2[2];
        long long int a2 = temp [2] * temp2[1];
        long long int b = temp[2] * temp2[2];
        temp [1] = a1 + a2;
        temp[2] = b;
        temp = cut(temp);
        return (CRational (temp[0], temp[1], temp[2]));
        }
   };

    CRational CRational::operator - (CRational drob) {
        vector <long long int> temp = this->bobka;
        vector <long long int> temp2 = drob.bobka;
        return (CRational (temp[0], temp[1], temp[2])+(CRational (-temp2[0], -temp2[1], temp[2])));
    };

    CRational CRational::operator * (CRational drob) {
        vector <long long int> temp = this->bobka;
        vector <long long int> temp2 = drob.bobka;
        if (temp2[2] == 1 && temp[2] == 1) {
            return (CRational (temp[0]*temp2[0], 1, 1));
        } else if (temp[2] == 1 && temp2[2] != 1) {
            return (CRational (temp2[0]*temp[0], temp2[1]*temp[0], temp2[2]));
        } else if (temp2[2]==1 && temp[2]!=1) {
            return (CRational (temp[0]*temp2[0], temp[1]*temp2[0], temp[2]));
        } else {
        return (CRational ((long long int) 0, (temp[0]*temp[2]+temp[1])*(temp2[0]*temp2[2]+temp2[1]), temp[2]*temp2[2]));
        }
    };

    CRational CRational::operator / (CRational drob) {
        vector <long long int> temp = this->bobka;
        vector <long long int> temp2 = drob.bobka;
        if (temp[2] == 1 && temp2[2] == 1) {
            return (CRational(double(double(temp[0])/(double(temp2[0]))))); 
        } else if (temp[2] != 1 && temp2[2] == 1) {
            return (CRational(temp[0], temp[1], temp[2]*temp2[0])); 
        } else if (temp2[2] != 1 && temp[2] == 1) {
            return (CRational((0), temp[0]*temp2[2], temp2[2]*temp2[0]+temp2[1])); 
        } else {
        long long int a = temp2[2];
        long long int b = temp2[0]*temp2[2] + temp2[1];
        return (CRational(temp[0], temp[1], temp[2]) * CRational((0), a, b)); 
        }
    };

    CRational CRational::operator + (long long int a) {
        return(CRational(this->bobka[0]+a, this->bobka[1], this->bobka[2]));
    };

    CRational CRational::operator - (long long int a) {
        return(CRational(this->bobka[0]-a, this->bobka[1], this->bobka[2]));
    };

    CRational CRational::operator * (long long int a) {
        return(CRational(this->bobka[0]*a, this->bobka[1]*a, this->bobka[2]));
    };

    CRational CRational::operator / (long long int a) {
        return(CRational((0), this->bobka[0]*this->bobka[2] + this->bobka[1], this->bobka[2]*a));
    };

    CRational CRational::operator + (double a) {
        vector <long long int> duplo = oreh(a);
        return(CRational(this->bobka[0], this->bobka[1], this->bobka[2]) + CRational(duplo[0], duplo[1], duplo[2]));
    };

    CRational CRational::operator - (double a) {
        vector <long long int> duplo = oreh(a);
        return(CRational(this->bobka[0], this->bobka[1], this->bobka[2]) - CRational(duplo[0], duplo[1], duplo[2]));
    };

    CRational CRational::operator * (double a) {
        vector <long long int> duplo = oreh(a);
        return(CRational(this->bobka[0], this->bobka[1], this->bobka[2]) * CRational(duplo[0], duplo[1], duplo[2]));
    };

    CRational CRational::operator / (double a) {
        vector <long long int> duplo = oreh(a);
        return(CRational(this->bobka[0], this->bobka[1], this->bobka[2]) / CRational(duplo[0], duplo[1], duplo[2]));
    };

    vector <long long int> CRational::cut (vector <long long int> babochka) {

        if (babochka[2] < 0) {
            babochka[0] *= -1;
            babochka[1] *= -1;
            babochka[2] *= -1;
        }

        while (babochka[1] > babochka[2]) {
            babochka[1] -= babochka[2];
            babochka[0] +=1;
        }

        if (babochka[1] == babochka[2] && babochka[2]!=1) {
            babochka[1] = 0;
            babochka[2] = 1;
            babochka[0] ++;
        }

        if (babochka[1] > 1 && babochka[2] > 1) {
            for (long long int i = 2; i <= babochka[1]; i++) {
                while ((babochka [1] % i == 0) && (babochka [2] % i == 0)) {
                    babochka[1] = babochka[1] / i;
                    babochka[2] = babochka[2] / i;
                }
            }
        }

        while (babochka[1] < 0) {
            babochka[1] += babochka[2];
            babochka[0] --;
        }

        if (babochka[1] == 0) {
            babochka[2] = 1;
        }

        if (babochka[0] < 0 && babochka[2]!=1) {
            babochka[0] ++;
            babochka[1] -= babochka [2];
        }

        return  babochka;
    }

    void CRational::show () {
        if (this->bobka [2] == 1) {
            cout << "There is only whole part: " << this->bobka[0] ;
        } else if (this->bobka [0] == 0) {
            cout << "There is only fractional part: " << this->bobka[1] << "/" << bobka[2] << endl;
        } else if (this->bobka [0] == 0 && this->bobka [2] == 1) {
            cout << "There is only whole part: " << this->bobka[0] << endl;
        } else {
            cout << "Whole part: " << this->bobka[0] << " fractional part: " << this->bobka[1] << "/" << this->bobka[2] << endl;
        }
    };

    double CRational::value() {
        return double (double (this->bobka[0]*this->bobka[2] + this->bobka[1])/double (this->bobka[2]));
    };