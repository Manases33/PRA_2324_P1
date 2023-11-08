#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        // miembros privados
	
	    T* arr;
	    int max;
	    int n;
	    static const int MINSIZE = 2;
	    void resize(int newSize){
		    T *a = new T[newSize];
		    for(int i = 0; i < n; i++){
			    a[i] = arr[i];
		    }
		    delete[] arr;
		    arr = a;
		    max = newSize;
	    }
    public:
        // miembros p煤blicos, incluidos los heredados de List<T>
    
	    ListArray(){
		    arr = new T[MINSIZE];
		    n = 0;
		    max = MINSIZE;
	    }
	    ~ListArray(){
		    delete[] arr;
		    arr = nullptr;
	    }

	    T operator[](int pos){
		    if(pos >= 0 && pos < n){
			    return get(pos);
		    }else
			    throw std::out_of_range("La posici贸n no es v胠ida.\n");

	    }

	    friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		    out<<"La lista contiene: "<<std::endl;
			for (int i = 0; i < list.n; i++){
				out<<list.arr[i]<<std::endl;
			}
			out<<std::endl;
			return out;
		}

	    void insert(int pos, T e) override{
			if (pos < 0 || pos > size()){
				throw std::out_of_range("Posici贸n inv谩lida.");
			}
			if (n == max){
				resize(max + 1);
			}
			for (int i = n; i > pos; i--){
				arr[i] = arr[i - 1];
			}
			arr[pos] = e;
			n++;
		}

	    void append(T e) override{
			if (n == max){
				resize(max + 1);
			}
			arr[n] = e;
			n++;
		}

	    void prepend(T e) override{
			if (n == max){
				resize(max + 1);
			}
			for (int i = n; i != 0; i--){
				arr[i] = arr[i - 1];
			}
			arr[0] = e;
			n++;
		}

	    T remove(int pos) override{
			if (pos < 0 || pos > size() - 1){
				throw std::out_of_range("Posici贸n inv谩lida.");
			}

			T del = arr[pos];

			for (int i = pos; i < n - 1; i++){
				arr[i] = arr[i + 1];
			}
			n--;
			resize(max - 1);

			return del;
		}

	    T get(int pos) override{
			if (pos < 0 || pos > size()-1){
				throw std::out_of_range("Posici贸n inv谩lida.");
			}
			return arr[pos];
		}

	    int search(T e) override{
			for (int i = 0; i < n; i++){
				if (arr[i] == e){
					return i;
				}
			}
			return -1;
		}

	    bool empty() override{
		if(n == 0){
			return true;
		}
		else{
			return false;
		}
	}

	    int size() override{
		return n;
	}
};
