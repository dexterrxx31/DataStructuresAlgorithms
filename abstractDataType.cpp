#include <iostream>
using namespace std;

class myArray
{
    int used_size;
    int total_size;
    int *ptr;

public:
    void creatArray(int usize, int tsize)
    {   
        this->total_size = tsize;
        this->used_size = usize;
        this->ptr = new int[20];
    }
    void show(){
        for(int i =0;i<this->used_size;i++){
            cout<<this->ptr[i];
        }
    }
    void setValue(){
        int n;
        for(int i =0 ; i<this->used_size; i++){
            cout<<"Please enter an element in array . "<<endl;
            cin>>n;
            this->ptr[i]=n;
        }

    }
};
int main()
{
    class myArray arr;
    arr.creatArray(2,10);
    arr.setValue();
    arr.show();
    return 0;
}