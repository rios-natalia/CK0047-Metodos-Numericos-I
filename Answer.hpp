#include <string>
using std::string;

class Answer{
    private:
        double result;
        int iterations;
        double time;
        double absoluteError;
        bool errorFlag;
        string errorMessage;
    
    public:
        Answer();
        Answer(double result, int iterations, double time);
        Answer(double result, int iterations, double time,double absoluteError);
        Answer(string getErrorMessage);
        double getResult();
        int getIterations();
        double getTime();
        double getAbsoluteError();
        bool getErrorFlag();
        string getErrorMessage();
        
};

Answer::Answer(){
    this->result = -1;
    this->iterations = 0;
    this->time = 0;
    this->absoluteError = 0;
    this->errorFlag = true;
    this->errorMessage = "Resposta padrão de erro.";
}

// Apenas para testes. Será deletado
Answer::Answer(double result, int iterations, double time){
    this->result = result;
    this->iterations = iterations;
    this->time = time;
    this->absoluteError = 0;
    this->errorFlag = false;
    this->errorMessage = "Nenhum erro ocorreu.";
}

Answer::Answer(double result, int iterations, double time, double absoluteError){
    this->result = result;
    this->iterations = iterations;
    this->time = time;
    this->absoluteError = absoluteError;
    this->errorFlag = false;
    this->errorMessage = "Nenhum erro ocorreu.";
}

Answer::Answer(string errorMessage){
    this->result = -1;
    this->iterations = 0;
    this->time = 0;
    this-> absoluteError = 0;
    this->errorFlag = true;
    this->errorMessage = errorMessage;
}

double Answer:: getResult(){
    return result;
}

int Answer:: getIterations(){
    return iterations;
}

double Answer:: getTime(){
    return time;
}

double Answer:: getAbsoluteError(){
    return absoluteError;
}


bool Answer:: getErrorFlag(){
    return errorFlag;
}

string Answer:: getErrorMessage(){
    return errorMessage;
}
