#include <string>
using std::string;

class Answer{
    private:
        double result;
        int iterations;
        double time;
        bool errorFlag;
        string errorMessage;
    
    public:
        Answer();
        Answer(double results, int iterations, double time);
        Answer(string getErrorMessage);
        double getResult();
        int getIterations();
        double getTime();
        bool getErrorFlag();
        string getErrorMessage();
        
};

Answer::Answer(){
    this->result = -1;
    this->iterations = 0;
    this->time = 0;
    this->errorFlag = true;
    this->errorMessage = "Resposta padrão de erro.";
}

Answer::Answer(double result, int iterations, double time){
    this->result = result;
    this->iterations = iterations;
    this->time = time;
    this->errorFlag = false;
    this->errorMessage = "Nenhum erro ocorreu.";
}

Answer::Answer(string errorMessage){
    this->result = -1;
    this->iterations = 0;
    this->time = 0;
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

bool Answer:: getErrorFlag(){
    return errorFlag;
}

string Answer:: getErrorMessage(){
    return errorMessage;
}
