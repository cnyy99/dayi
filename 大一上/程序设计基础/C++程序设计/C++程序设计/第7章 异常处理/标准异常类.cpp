#include<iostream> 
#include<stdexcept> 
using namespace std; 

int main() 
{ 
    try 
    { 
        throw out_of_range("out of range"); 
    } 
    catch(out_of_range & exc) 
    { 
        cout<<exc.what()<<endl; 
    } 
    cout<< "Done!"<<endl;
    return 0; 
}
    