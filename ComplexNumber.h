#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include<iostream>

class ComplexNumber
{
    int Real{0};
    int Imaginary{0};

public:
    ComplexNumber() = default ;
    ComplexNumber(const int& real, const int& imaginary): Real{real}, Imaginary{imaginary}{}


    ComplexNumber& operator+= (const ComplexNumber& other)
    {
        this->Real += other.Real;
        this->Imaginary += other.Imaginary;
        return *this;
    }

    friend ComplexNumber operator+(const ComplexNumber& a,  const ComplexNumber& b)
    {
        return {a.Real + b.Real, a.Imaginary+ b.Imaginary};
    }

    friend ComplexNumber operator-(const ComplexNumber& a,  const ComplexNumber& b)
    {
        return {a.Real - b.Real, a.Imaginary - b.Imaginary};
    }

    friend ComplexNumber operator*(const ComplexNumber& a,  const ComplexNumber& b)
    {
        return {(a.Real*b.Real) - (a.Imaginary*b.Imaginary),
                    (a.Real*b.Imaginary) + (b.Real*a.Imaginary)};
    }

    friend bool operator==(const ComplexNumber& a,  const ComplexNumber& b)
    {
        return a.Real==b.Real && a.Imaginary == b.Imaginary;
    }

    friend std::ostream& operator<<(std::ostream& output, const ComplexNumber& cn)
    {

      /*  output<<cn.Real ; Kelvin
        output<<(cn.Imaginary !=0?
                       (cn.Imaginary >0?
                            (cn.Imaginary ==1?"+i":"+"+std::to_string(cn.Imaginary )+"i")
                            :
                            (cn.Imaginary ==-1?"-i":"-"+std::to_string(cn.Imaginary )+"i")
                       ):"");

        return output;
*/

/*
        if (cn.Real != 0)
                   output << cn.Real;
        if (cn.Imaginary != 0)
        {
                   if (cn.Imaginary > 0)
                          output << '+';
                    output << cn.Imaginary << "i";
        }
        if (cn.Real == 0 & cn.Imaginary == 0)
                    output << 0;

  */


        //return output;




        if(cn.Real== 0 && cn.Imaginary == 0)
        {
            output<<0;
        }
        else if(cn.Real == 0 && cn.Imaginary != 0)
        {
            if( cn.Imaginary < 0)
            {
                output<<" - "<<std::abs(cn.Imaginary)<<"i";
            }
            else
            {
                output<<" + "<<std::abs(cn.Imaginary)<<"i";
            }
        }
        else
        {
            if( cn.Imaginary < 0)
            {
                output<<cn.Real<<" - "<<std::abs(cn.Imaginary)<<"i";
            }
            else if ( cn.Imaginary > 0)
            {
                output<<cn.Real<<" + "<<std::abs(cn.Imaginary)<<"i";
            }
            else
            {
                output<<cn.Real;
            }
        }

        return output;

    }






};





#endif // COMPLEXNUMBER_H
