template <typename T>
class Stack {
private:
    int N;
    int capacity;
    T* a;
public:
    Stack() : N(0), capacity(1) {
        a = new T[capacity];
    }

		~Stack() {
        delete[] a;
    }
    
    bool empty() const {
        return N == 0; 
    }
    
    int size() const {
        return N;
    }

    void push(const T& item) {
        if (N == capacity) resize(2 * capacity);
        a[N++] = item;
    }

    T pop() {
        assert(!empty());
        T value = a[--N];
        if (N > 0 && N == capacity / 4) resize(capacity / 2);
        return value;
    }
private:
    void resize(int max) {
        T* temp = new T[max];
        for (int i = 0; i < N; i++) {
            temp[i] = a[i];
        }
        delete[] a;
        a = temp;
        capacity = max;
    }
};