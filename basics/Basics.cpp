#include <iostream>
using namespace std;

int addNumbers(int a, int b){
    return a+b;
}

void fruitLoops(){
    int iterations = 5;
    for (int i = 1; i < iterations + 1; i++){
        cout<<i<<endl;
    }
    cout<<"Fruit loops done"<<endl;
}

bool conditionalTesting(){
    bool a = true;
    bool b = false;
    bool c = true;

    bool result = true;

    if(a==true){
        cout<<"a is true!"<<endl;
    }

    if(a && b){
        result = !result;
    }

    if(a || b){
        result = !result;
    }


    return a;
}

int main() {
    cout << "Hello, World!" << endl;

    int result = addNumbers(1,24);
    cout<<result<<endl;

    fruitLoops();

    bool conditionResult = conditionalTesting();
    cout<<"Result: "<<conditionResult<<endl;

    return 0;
}