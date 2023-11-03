#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;



int main () {
    ofstream csv_file;
    int y = 25;
    vector<float> H (y, 0);
    vector<float> O (y, 0);
    for (int u=0; u<y; u++) {
        float const h = 1/(pow(2, u+1));
        H[u] = h;
        float nach = 0;
        float kon = 3.14159;
        int const n = (kon-nach)/h+1;
        int N = n-1;
        float *X {new float[n]};
        //float X [n];
        float *Xs {new float[n-1]};
        //float Xs [n-1];
        X [0] = nach;
        for (int i = 1; i < n; i++) {
            X[i]= nach + h*i;
        }
        for (int i = 0; i < n-1; i++) {
            Xs[i]= nach + h*i+h/2;
        }
    
    // zadali funkciu
        float *F{new float[n]};
        //float F [n];
        for (int i = 0; i < n; i++) {
            F[i]= sin(X[i]);
        //F.at(i) = 4*X[i]*X[i]*X[i];
        }
        /*float Fs [n-1];
        for (int i = 0; i < n-1; i++) {
            Fs[i]= Xs[i] * exp(X[i]);
        //F.at(i) = 4*X[i]*X[i]*X[i];
        }
        */
        float I = 2;

    /*// levie p
        vector<float> Ilp (n-1, 0);
        Ilp[0] = h * F[0];
        for (int i = 1; i < n-1; i++) {
            Ilp[i] = Ilp[i-1]+h*F[i];
        }
        cout << "lev " << Ilp[n-2]  << " " << I - Ilp[n-2] << endl;
    */
 /*  // pravie p
    vector<long double> Ipp (n-1, 0);
    Ipp[0] = h * F[1];
    for (int i = 1; i < n-1; i++) {
        Ipp[i] = Ipp[i-1]+h*F[i+1];
    }
    cout<< "prav " << Ipp[n-2] << endl;

    // srednie p
    vector<long double> Isp (n-1, 0);
    Isp[0] = h * Fs[0];
    for (int i = 1; i < n-1; i++) {
        Isp[i] = Isp[i-1]+h*Fs[i];
    }
    cout<< "sred " << Isp[n-2] << endl;

    // trap
    vector<long double> It (n-1, 0);
    It[0] = (h/2)*(F[0]+F[1]);
    for (int i = 1; i < n-1; i++) {
        It[i] = It[i-1]+(h/2)*(F[i]+F[i+1]);
    }
    cout<< "trap " << It[n-2] << endl;
*/
    // simpson
    float *Isi {new float[n/2]};
    //float Isi [n];
    Isi[0] = (h/3) * (F[0] + 4*F[1] + F[2]);
    if (n%2 == 0) {
        for (int i = 1; i < (int (n/2)); i++) {
            Isi[i] = Isi[i-1] + (h/3)*(F[2*i] + 4*F[2*i+1] + F[2*i+2]);
        }
    }
    else {
        for (int i = 1; i < (int (n/2))-1; i++) {
            Isi[i] = Isi[i-1] + (h/3)*(F[2*i] + 4*F[2*i+1] + F[2*i+2]);
        }
        Isi[int (n/2)-1] = Isi[int (n/2)-2] + h*F[n-1];
    }
    cout<< "sim " << Isi[n/2-2] << " " << I - Isi[n/2-2] << endl;
    O[u] = abs(I - Isi[int (n/2)-1]); 
/*
    // sim1
    vector<long double> Isi1 (n-1, 0);
    Isi1[0] = (h/3) * (F[0] + 4*F[1] + F[2]);
    for (int i = 1; i < n-1; i++) {
        Isi1[i] = Isi1[i-1] + (h/6)*(F[i-1] + 4*F[i] + F[i+1]);
    }
    cout<< "sim1 " << Isi1[n-2] << endl;

    const char csv_file_name1[64] = "int1.csv";
    csv_file.open(csv_file_name1);
    csv_file << "X,Xs,F,Fs\n";
    for (int i = 0; i < n; i++) {
        csv_file << X[i] << "," << Xs[i] << "," << F[i] << "," << Fs[i] << "\n";
    }
    csv_file.close();
    const char csv_file_name2[64] = "int2.csv";
    csv_file.open(csv_file_name2);
    csv_file << "I,Ilp,Ipp,Isp,It,Isi,Isi1\n";
    csv_file << I << "," << Ilp[n-3] << "," << Ipp[n-3] << "," << Isp[n-3] << "," << It[n-3] << "," << Isi[n/2-1] << "," << Isi1[n-2] << "\n";
    csv_file.close();
*/ 
    }

    const char csv_file_name1[64] = "int1.csv";
    csv_file.open(csv_file_name1);
    csv_file << "H,O\n";
    for (int i = 0; i < y; i++) {
        csv_file << H[i] << "," << O[i] <<"\n";
    }
    cout << "gotovo\n";
    return 0;
}