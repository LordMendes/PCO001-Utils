#include<iostream>
using namespace std;

#define SIZE 10

struct Knot{

    char Key;
    int Value;

};

class StaticList{

    private:
        Knot Data[SIZE];
        int End;

    public:

        StaticList(){
            this->End = -1;
        }

        void print(){
            cout<<endl;
            if(this->End == -1){
                cout<<"Empty List";
            }

            for(int i = 0; i <= this->End; i++){


                cout<<this->Data[i].Key<<" ";
            }
        };

        bool insertKnot(Knot newKnot){

            if (this->End == SIZE - 1) //Lista cheia
                return false;
            else {
                int i = 0, position;
                while ((i <= this->End) && (this->Data[i].Key < newKnot.Key))
                    i++;
                    position = i;
                    i = this->End;
                while (i > position-1) {
                    this->Data[i+1] = this->Data[i];
                    i--;
                }
                this->Data[position] = newKnot;
                this->End++;
                return true;
            }

        }

        bool removeKnot (Knot& N){
            int i = 0;
            while ((i <= this->End) && (this->Data[i].Key != N.Key)){
                i++;
                if (i > this->End) // nó não encontrado
                    return false;
            }
            N = this->Data[i];
            while (i < this->End) {
                this->Data[i] = this->Data[i+1];
                i++;
            }
            this->End--;
            return true;
        }

        Knot searchKnot (Knot& N){
            int i = 0;
            while ((i <= this->End) && (this->Data[i].Key != N.Key)){
                i++;
                if (i > this->End){ // nó não encontrado
                    return N;
                }
            }
            return this->Data[i];
        }
};
