// ConsoleApplication5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Car 
{
    string Frame;
    int Engine; 
    int Wheels; 
    string k_p_p;   
public:

    void SetFrame(string frame) 
    {
        this->Frame = frame;    
    }
    string GetFraem() 
    {
        return this->Frame;
    }
    void SetEngine(int engine)  
    {
        this->Engine = engine;  
    }
    int GetEngine() 
    {
        return this->Engine;    
    }
    void SetWheels(int wheels)
    {
        this->Wheels = wheels;
    }
    int GetWheels()
    {
        return this->Wheels;    
    }
    void SetK_p_p(string kpp)   
    {
        this->k_p_p = kpp;
    }
    string GetK_p_p()
    {
        return this->k_p_p; 
    }
    void ShowCar() 
    {
        cout << "Frame: " << Frame << endl; 
        cout << "Engine: " << Engine << endl;
        cout << "Wheels: " << Wheels << endl;   
        cout << "k.p.p: " << k_p_p << endl; 
    }
};  

class CarBuilder abstract
{
protected:
    Car car;
public:
    Car GetCar() 
    {
        return car;
    }   
    virtual void BuildFrame() abstract; 
    virtual void BuildEngine() abstract;
    virtual void BuildWheels() abstract;    
    virtual void Buildk_p_p() abstract;
};

class DaewooLanosBuilder : public CarBuilder 
{
public:
    void BuildFrame() override 
    {
        car.SetFrame("sedan");
    }
    void BuildEngine() override
    {
        car.SetEngine(98);  
    }
    void BuildWheels() override 
    {
        car.SetWheels(13);
    }
    void Buildk_p_p() 
    {
        car.SetK_p_p("5 Manual");
    }
};   

class FordProbeBuilder : public CarBuilder  
{
public:
    void BuildFrame() override
    {
        car.SetFrame("coupe");
    }
    void BuildEngine() override
    {
        car.SetEngine(160);
    }
    void BuildWheels() override
    {
        car.SetWheels(14);
    }
    void Buildk_p_p()
    {
        car.SetK_p_p("5 Auto");
    }
};

class UAZPatriot : public CarBuilder
{
public:
    void BuildFrame() override
    {
        car.SetFrame("station wagon");
    }
    void BuildEngine() override
    {
        car.SetEngine(120);
    }
    void BuildWheels() override
    {
        car.SetWheels(16);
    }
    void Buildk_p_p()
    {
        car.SetK_p_p("4 Manual");
    }
};

class HyundaiGetz : public CarBuilder
{
public:
    void BuildFrame() override
    {
        car.SetFrame("Hatchback");
    }
    void BuildEngine() override
    {
        car.SetEngine(66);
    }
    void BuildWheels() override
    {
        car.SetWheels(13);
    }
    void Buildk_p_p()
    {
        car.SetK_p_p("4 Auto"); 
    }
};

class Shop 
{
    CarBuilder *carBuilder; 
public:
    void SetCArBuilder(CarBuilder* cb) 
    {
        carBuilder = cb;    
    }
    Car GetBuilder() 
    {
        return carBuilder->GetCar();    
    }
    void ConstructCar() 
    {
        carBuilder->BuildFrame();
        carBuilder->BuildEngine();
        carBuilder->BuildWheels();  
        carBuilder->Buildk_p_p();     
    }
};

void Client(CarBuilder* builder) 
{
    Shop director;  
    director.SetCArBuilder(builder);    
    director.ConstructCar();
    Car car = director.GetBuilder();    
    car.ShowCar();  
}

int main()
{
    CarBuilder* builder = new DaewooLanosBuilder(); 
    Client(builder);    
    delete builder; 

    builder = new FordProbeBuilder();   
    Client(builder);
    delete builder;

    builder = new UAZPatriot(); 
    Client(builder);    
    delete builder; 

    builder = new HyundaiGetz();    
    Client(builder);    
    delete builder;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
