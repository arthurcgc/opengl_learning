#pragma once
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>
#include "../includes/matriz.h"
#include "../includes/thomas.h"

using namespace std;

class AbstractSpline
{
    public:
        void DeCasteljau(double b0x,double b0y,
                       double b1x,double b1y,
                       double b2x,double b2y,
                       double b3x,double b3y, double t_size);
        void CalculateSplinePoints(double t_size);
        void InitializeVectors(double t_size);
        void InitializeVectors(double t_size, vector<double> v);

        void CopyRVectors(vector<double> &Rx, vector<double> &Ry);
        void CopyDVectors(vector<double> &Dx, vector<double> &Dy);
        void CopyLVectors(vector <double> &Lx, vector<double> &Ly);
        void CopyPVectors(vector<double> &Px, vector<double> &Py);
        void CopyPoints(vector<double> &points_x, vector<double> &y);
        void CopyH(vector<double> &h);
        void CopyGamma(vector<double> &gamma);
        void CopyLambda(vector<double> &lambda);
        void CopyDelta(vector<double> &delta);
        void CopyMi(vector<double> &mi);
        void CopyA(vector<double> &a);
        void CopyB(vector<double> &b);
        void CopyC(vector<double> &c);
        void CopyV(vector<double> &v);
        double **GetMCopy();

        static void PrintAll(AbstractSpline *spline);


    protected:
        virtual void setGamma();
        virtual void setA_B_C();
        virtual void setLambda();
        virtual void setLambda(vector<double> Gamma);
        virtual void setMi();
        virtual void setMi(vector<double> Gamma);
        virtual void setM();
        virtual void setD();
        virtual void setR_L();
        virtual void setDelta();
        // virtual void setAll();
        vector<double> h, gamma, lambda, delta, mi, a, b, c, v;
        vector<double> Rx, Ry, Dx, Dy, Lx, Ly, Px, Py, points_x, points_y;
        double **M;
};