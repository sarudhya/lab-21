#include<iostream>
using namespace std;

int main(int argc, char *argv[]){
    float sum;
    int i = 1;
    if(argc == 1){
        cout << "Please input numbers to find average.";
    }else{
        cout << "---------------------------------" << endl;
        cout << "Average of " << argc - 1 <<" numbers = ";
        while(i < argc){
            sum += atof(argv[i]);
            i++;
            
        }   
        cout << sum/(i-1) << endl;
        cout << "---------------------------------";
    }
}
