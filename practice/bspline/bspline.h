#pragma once
#include "../abstract_spline/abstract_spline.h"

class BSpline : public AbstractSpline
{
    public:
        BSpline(vector<pair<double, double> > points, double t_size);
        BSpline(vector<pair<double,double> > points, double t_size, vector<double> v);
    protected:
        void getH();
};