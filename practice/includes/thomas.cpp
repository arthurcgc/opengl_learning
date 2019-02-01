#include "thomas.h"
#include "matriz.h"


using namespace std;

vector <double> Thomas(double **A, vector <double> P)
{
    vector <double> D;
    vector <double> c_p;
    vector <double> d_p;
    
    c_p.push_back(A[0][1] / A[0][0]);
    d_p.push_back(P[0] / A[0][0]);

    int n = P.size();
    for(int i = 1; i < n; i++)
    {
        if( i < n - 1 )
            c_p.push_back( A[i][i+1] / (A[i][i] - (A[i][i-1]*c_p[i-1]) ));
        d_p.push_back( (P[i] - (A[i][i-1]*d_p[i-1])) / (A[i][i] - (A[i][i-1]*c_p[i-1]) )  );
    }
    
    D.push_back(d_p[n-1]);
    
    int j = 0;
    for(int i = n-2; i >= 0; i--)
    {
        D.push_back( d_p[i] - (c_p[i]*D[j]) );
        j++;
    }
    
    reverse(D.begin(), D.end());
    return D;
}


