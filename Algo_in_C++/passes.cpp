#include <iostream>
#include<cmath>

struct Unit{
float w;
float b;
    Unit(){
        w=0;
        b=0;
    }

};
#define Sigmoid(x) (1/(1+std::exp(-x)))
#define MeanSquareLoss(y_true,y_pred) (0.5*std::pow((y_true-y_pred),2))
int main(){
    Unit u;
    std::cin>>u.w>>u.b;

    float x;
    std::cout<<"enter input value"<<std::endl;
    std::cin>>x;
    float y_pred=x*u.w+u.b;
    y_pred=Sigmoid(y_pred);
    std::cout<<"enter the true value"<<std::endl;
    float y_true;
    std::cin>>y_true;
    float loss=MeanSquareLoss(y_true,y_pred);
    std::cout<<"the loss is"<<loss<<std::endl;
    std::cout<<"the y_pred is"<<y_pred<<std::endl;
    float learning_rate;
    std::cin>>learning_rate;

    //backpropgation bruh
    u.b=u.b-learning_rate*(y_pred*(y_pred-y_true)*(1-y_pred));
    u.w=u.w-learning_rate*(y_pred*(y_pred-y_true)*(1-y_pred)*x);
    std::cout<<"updated weight is"<<u.w<<std::endl;
    y_pred=x*u.w+u.b;
    y_pred=Sigmoid(y_pred);
    loss=MeanSquareLoss(y_true,y_pred);
    std::cout<<"the loss after backpropagation is"<<loss<<std::endl;
    std::cout<<"the y_pred after backpropagation is"<<y_pred<<std::endl;
    
    
    
}