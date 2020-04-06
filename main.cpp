#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<math.h>
using namespace std;
int training_input[4][2] = {{0,0},
                            {0,1},
                            {1,0},
                            {1,1}};
double training_output[4] = {0,0,0,1};
int epochs = 1000;
double learning_rate = 0.1;
class Neuron{
public:
    double w0,w1;
    double b;
Neuron()
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
    double mse_loss(double y[],double ypred[],int size)
    {
        double avg;
        for(int i=0;i<size;i++)
        {
            avg+=(y[i]-ypred[i])*(y[i]-ypred[i]);
        }
        return avg/size;

    }
    double derivative(double y,double ypred)
    {
        return -2*(1- ypred);
    }
double Forward(int X0,int X1)
{
    double VH0,VH1,VO0;
    VH0 = sigmoid(H0.w0*X0+H0.w1*X1+H0.b);
    VH1 = sigmoid(H1.w0*X0+H1.w1*X1*H0.b);
    VO0 = sigmoid(O0.w0*VH0+O0.w0*VH1+O0.b);
    return VO0;
}
double delta_H0(int X0,int X1)
{
    return sigmoid(H0.w0*X0+H0.w1*X1+H0.b);
}
double delta_H1(int X0,int X1)
{
    return sigmoid(H1.w0*X0+H1.w1*X1*H0.b);
}
double delta_O0(int X0,int X1)
{
    return Forward(X0,X1);
}
void Train(int X[4][2],double Y[],double learning_rate,int epochs,int size)
{
    double ypred[size],y_pred;
    double VH0,VH1;
    double derivative_mse;
    double dW0,dW1,dW2,dW3,dW4,dW5,dH0,dH1,dO0;
    for (int i = 1;i<=epochs;i++)
    {
        for (int j=0;j<size;j++)
        {
            VH0 = sigmoid(H0.w0*X[j][0]+H0.w1*X[j][1]+H0.b);
            VH1 = sigmoid(H1.w0*X[j][0]+H1.w1*X[j][1]+H1.b);
            ypred[j]= sigmoid(O0.w0*VH0+O0.w0*VH1+O0.b);
            derivative_mse = derivative(Y[j],ypred[j]);

            dW5=delta_H1(X[j][0],X[j][1])*derivative_mse;
            dW4=delta_H0(X[j][0],X[j][1])*derivative_mse;
            O0.b=derivative_mse;

            dH0= O0.w0*derivative_mse;
            dH1= O0.w1*derivative_mse;

            dW0=X[j][0]*derivative_mse;
            dW1=X[j][1]*derivative_mse;
            H0.b=derivative_mse;

            dW2=X[j][0]*derivative_mse;
            dW3=X[j][1]*derivative_mse;
            H1.b=derivative_mse;

            H0.w0=H0.w0-(learning_rate*dW0*dH0*derivative_mse);
            H0.w1=H0.w1-(learning_rate*dW1*dH0*derivative_mse);
            H1.w0=H1.w0-(learning_rate*dW2*dH1*derivative_mse);
            H1.w1=H1.w1-(learning_rate*dW3*dH1*derivative_mse);
            O0.w0=O0.w0-(learning_rate*dW4*derivative_mse);
            O0.w1=O0.w1-(learning_rate*dW5*derivative_mse);
        }
        if(epochs%10==0)
        {
            for (int j=0;j<size;j++)
            {

            }
        }

    }
}
};

int main()
{
    srand(time(NULL));
    Network Network;
    Network.Train(training_input,training_output,learning_rate,epochs,4);

}
