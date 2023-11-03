#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int main () {

    //pervaya proizvodnaya
    double h = 0.01;
    double nach, kon;
    nach = -1.5;
    kon = 1.5;
    int n = (kon-nach)/h+1;
    int N = n-1;
    vector<long double> X(n, 0);
    X [0] = nach;
    for (int i = 0; i < n; i++) {
        X.at(i)= nach + ((kon-nach)/(n-1.0))*i;
    }
    // zadali funkciu
    vector<long double> F(X);
    for (int i = 0; i < n; i++) {
        F.at(i)= log(sin(X[i])*sin(X[i])+1);
        //F.at(i) = X[i]*X[i]*X[i];
    }
    // proizvodnaya pravaya
    vector<long double> Fpp (X);
    for (int i = 0; i < n-1; i++) {
        Fpp[i] = (F[i+1]-F[i])/h;
    }

    //Fpp.at(0) = (4*F[1]-3*F[0]-F[2])/(2*h);
    Fpp.at(N) = (F[N]-F[N-1]) / (h);

    // proizvodnaya srednyaya
    vector<long double> Fps (X);
    for (int i = 1; i < n-1; i++) {
        Fps[i] = (F[i+1]-F[i-1])/(2*h);
    }

    Fps.at(0) = (4*F[1]-3*F[0]-F[2])/(2*h);
    Fps.at(N) = -(4*F[N-1]-3*F[N]-F[N-2])/(2*h);

    const char csv_file_name1[64] = "pp.csv";
    ofstream csv_file;
    csv_file.open(csv_file_name1);
    csv_file << "X,F,Fpp,Fps\n";

    for (int i = 0; i < n; i++) {
        csv_file << X[i] << "," << F[i] << "," << Fpp[i] << "," << Fps[i] <<"\n";
    }

    csv_file.close();

    //vtoraya proizvodnaya

    vector<long double> Fvs (X);
    vector<long double> Fv4 (X);
    for (int i=1; i<n-1; i++) {
        Fvs[i] = (F[i-1]+F[i+1]-2*F[i])/(h*h);
    }

    Fvs.at(0) = (2*F[0]-5*F[1]+4*F[2]-F[3])/(h*h);
    Fvs.at(N) = (2*F[N]-5*F[N-1]+4*F[N-2]-F[N-3])/(h*h);

    for (int i=2; i<=n-2; i++) {
        Fv4[i] = (-F[i-2]+16*F[i-1]-30*F[i]+16*F[i+1]-F[i+2])/(12*h*h);
    }

    for (int i = 0; i<=1; i++) {
        Fv4.at(i) = (-154*F[i+1]+214*F[i+2]-156*F[i+3]+61*F[i+4]-10*F[i+5]+45*F[i])/(12*h*h);
        Fv4.at(N-i) = (-154*F[N-(i+1)]+214*F[N-(i+2)]-156*F[N-(i+3)]+61*F[N-(i+4)]-10*F[N-(i+5)]+45*F[N-i])/(12*h*h);
    }
    
    cout << Fv4.at(1) << endl;

    double opa = Fv4.at(1);

    Fv4.at(1) = (10*F[0]-4*F[2]+14*F[3]-6*F[4]+1*F[5]-15*F[1])/(12*h*h);
    Fv4.at(N-1) = (10*F[N]-4*F[N-2]+14*F[N-3]-6*F[N-4]+1*F[N-5]-15*F[N-1])/(12*h*h);


    const char csv_file_name2[64] = "vp.csv";
    csv_file.open(csv_file_name2);
    csv_file << "X,F,Fvs,Fv4\n";

    for (int i = 0; i < n; i++) {
        csv_file << X[i] << "," << F[i] << "," << Fvs[i] << "," << Fv4[i] <<"\n";
    }

    csv_file.close();

    opa -= Fv4.at(1);

    cout << Fv4.at(1) << endl;

    cout << opa << endl;
    cout << "gotovo";

    return 0;
}