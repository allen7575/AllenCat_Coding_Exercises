template <class T>
class Queue{
    public:
        Queue();
        ~Queue();
        void push(T);
        T pop();
        bool isEmpty();
        bool isFull();
        T front();
    private:    
};
