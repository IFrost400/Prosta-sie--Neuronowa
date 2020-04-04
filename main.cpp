#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int w0,w1,w2,w3,w4,w5;
int b1,b2,b3;
int training_input[4][2] = {{0,0},
                            {0,1},
                            {1,0},
                            {1,1}};
int training_output[4] = {0,0,0,1};

double sigmoid(double x)
{
    return 1/(1+exp(x));
}
double derivsigmoid(double x)
{
    this->w0=(rand()*1.0)/RAND_MAX;
    this->w1=(rand()*1.0)/RAND_MAX;
    this->b=(rand()*1.0)/RAND_MAX;
}
};
class Network{
public:
    Neuron H0,H1,O0;
    double sigmoid(double x)
    {
        return 1/(1+exp(x));
    }
    double derivsigmoid(double x)
    {
        return  sigmoid(x)*(1-sigmoid(x));
    }
    double mse_loss(int y[],int ypred[],int size)
    {
        int avg;
        for(int i=0;i<size;i++)
        {
            avg+=(y[i]-ypred[i])^2;
        }
        return avg/size;
    }
double Forward(Neuron N, int X0,int X1)
{
    double VH0,VH1,VO0;
    VH0 = sigmoid(H0.w0*X0+H0.w1*X1);
    VH1 = sigmoid(H1.w0*X0+H1.w1*X1);
    VO0 = sigmoid(O0.w0*VH0+O0.w0*VH1);
    return VO0;
}
};
int main()
{

    srand(time(NULL));


}
