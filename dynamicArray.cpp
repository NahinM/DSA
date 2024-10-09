#include <iostream>
using namespace std;

#define br cout << '\n'
#define repti(a,b) for(int i=a;i<b;i++)

template <class T = int>
class Array
{
private:
    T *arr;
    int arraySize;
    int capacity;
public:
    Array(int cap = 1){
        capacity = cap;
        arraySize = 0;
        arr = new T[capacity];
    }
    void push(T d);
    int size();
    T operator[](int at);
    T* at(int n);
    void insertAt(T data,int at);
};

template <class T>
T* Array<T>::at(int n){
    return (n < 0 || n >= arraySize) ? nullptr : &arr[n];
}

template <class T>
void Array<T>::insertAt(T data,int at){
    if(at <= 0 && at < arraySize) arr[at] = data;
}

template <class T>
void Array<T>::push(T d){
    if(arraySize == capacity){
        T *tem = new T[capacity*2];
        repti(0,capacity) tem[i] = arr[i];
        delete[] arr;
        arr = tem;
        capacity *= 2;
    }
    arr[arraySize++] = d;
}

template <class T>
T Array<T>::operator[](int at){
    return arr[at];
}

template <class T>
int Array<T>::size(){
    return arraySize;
}

int main(){
    freopen("arrData.txt","r",stdin);
    Array<int> arr = Array<int>();
    int a;
    while(cin >> a) arr.push(a);
    cout << "The array arraySize is: " << arr.size() << '\n';
    cout << "the array is: ";
    repti(0,arr.size()) cout << arr[i] << ' ';br;
    arr.insertAt(3,0);
    repti(0,arr.size()) cout << arr[i] << ' ';br;

}