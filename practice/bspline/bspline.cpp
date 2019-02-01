#include "bspline.h"

BSpline::BSpline(vector<pair<double,double> > points, double t_size)
{
    //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size);
}

BSpline::BSpline(vector<pair<double,double> > points, double t_size, vector<double> v)
{
    //definindo os pontos da spline
     for(size_t i = 0; i < points.size(); i++)
    {
        Px.push_back( points[i].first );
        Py.push_back( points[i].second );
    }

    getH();
    InitializeVectors(t_size, v);
}

void BSpline::getH()
{
    h.push_back(0);

    for(int i = 1; i < Px.size(); i++)
        h.push_back(1);

    h.push_back(0);
}