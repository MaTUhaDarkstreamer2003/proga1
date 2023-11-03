#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

double Chebyshev(double a, double b, int i, int n) {
    return ((a+b)/2+(b-a)/2*cos((2.0*i+1.0)*3.141592653589793/(2.0*double(n))));
}

double lagrange(double x, vector<double> X, vector<double> Y, int n) {
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        double l = Y[i];
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                l *= (x - X[j]) / (X[i] - X[j]);
            }
        }
        result += l;
    }
    return result;
}

double newton(double x, vector<double> X, vector<double> Y, int n) {   
    vector<vector<double>> f(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        f[i][0] = Y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (X[i+j] - X[i]);
        }
    }
    double y = f[0][0];
    double w = 1.0;
    for (int j = 1; j < n; j++) {
        w *= (x - X[j-1]);
        y += f[0][j] * w;
    }
    return y;
}

double lin(double x, vector<double> X, vector<double> Y, int n) {   
    vector<vector<double>> f(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        f[i][0] = Y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n-j; i++) {
            f[i][j] = (f[i+1][j-1] - f[i][j-1]) / (X[i+j] - X[i]);
        }
    }
    double y = f[0][0];
    double w = 1.0;
    for (int j = 1; j < n; j++) {
        w *= (x - X[j-1]);
        y += f[0][j] * w;
    }
    return y;
}


int main()
{
    int n = 8;
    int inter = 10;
    double N = n;
    double nach, kon;
    nach = 0;
    kon = 10;
    vector<double> X {0};

    for (int i=1; i<n; i++)
    {
        X.push_back(0);
    }

    X.at(0) = nach;
    X.at(n-1)= kon;

    for (int i=1; i<n; i++)
    {   
        double h = i;
        X.at(i)= nach + ((kon-nach)/(n-1.0))*i;
    }


    const char csv_file_name1[64] = "data_fixed.csv";
    ofstream csv_file;
    csv_file.open(csv_file_name1);
    csv_file << "x,f,Lagrange,Newton\n";

    vector<double> Y (X);
    vector<double> Xch (X);
    vector<double> Ych (X);


    int deb = inter*n;

    for (int i = 0; i < n; i++)
    {
        Y[i] = exp(X[i]/3.0)/(1+X[i]*X[i]);
        Xch[i] = Chebyshev(nach, kon, i, n);
        Ych[i] = exp(Xch[i]/3.0)/(1+Xch[i]*Xch[i]);
        //cout << Xch[i] << " " << Ych[i] << endl;
    }

    double x [deb+1];
    double y1 [deb+1];
    double y2 [deb+1];
    double beb = deb;

    x[0]=0;

    for (int i = 0; i<=deb; i++)
    {
        double h=i;
        x[i]= nach + (h*(kon-nach)/beb);
        //y1[i] = lagrange(x[i], X, Y, n);
        //y2[i] = newton(x[i], X, Y, n);
        //cout << "f(" << x[i] << ") = " << y1[i] << " " << y2[i] << " ravn" <<endl;
    }

    double f_new[deb+1];

    for(int i=0; i<=deb; i++) 
    {
        f_new[i] = exp(x[i]/3.0)/(1.0+x[i]*x[i]);
    }

    double L_new[deb+1];
    double N_new[deb+1];
    
    for(int i=0; i<deb+1; i++)
    {
        L_new[i]=lagrange(x[i], X, Y, n);
        N_new[i]=newton(x[i], X, Y, n);
        csv_file << x[i] << "," << f_new[i] << "," << L_new[i] << "," << N_new[i] <<"\n";
        // cout << [i] << " " << f_new[i] << " " << L_new[i] << " " << N_new[i] <<"\n";
    }

    csv_file.close();

    double L_ch_new[deb+1];
    double N_ch_new[deb+1];
    double f_new2[deb+1];

    const char csv_file_name2[64] = "data_Chebyshev.csv";
    csv_file.open(csv_file_name2);
    csv_file << "x,f,Lagrange,Newton\n";


    for(int i=0; i<=deb; i++){
        L_ch_new[i]=lagrange(x[i], Xch, Ych, n);
        N_ch_new[i]=newton(x[i], Xch, Ych, n);
        csv_file << x[i] << "," << f_new[i] << "," << L_ch_new[i] << "," << N_ch_new[i] <<"\n";
        // cout << x[i] << " " << f_new2[i] << " " << L_ch_new[i] << " " << N_ch_new[i] <<"\n";
    }

    csv_file.close();

    cout << "gotovo";

    return 0;
}