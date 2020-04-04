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
    return  sigmoid(x)*(1-sigmoid(x));
}
double mse_loss(int y[],int ypred[])
{
    int avg;
    for(int i=0;i<(sizeof(y)/sizeof(*y));i++)
    {
        avg+=(y[i]-ypred[i])^2;
    }
    return avg/(sizeof(y)/sizeof(*y));
}

int main()
{

    srand(time(NULL));


}
