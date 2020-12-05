#ifndef TAXIAB_H
#define TAXIAB_H

#include<vector>

struct Taxiab
{


    int operator()(const std::vector<int>& a,  const std::vector<int>& b)
    {
        int sum=0;
        for(unsigned i =0; i < a.size(); ++i)
        {
            sum += std::abs(a[i]-b[i]);
        }

        return sum;
    }
};





#endif // TAXIAB_H
