#include <memory>

using namespace std;

template <class T>
class Node{

    public:
        Node(T item);
        ~Node();
        T getValue();
        void setValue(T);

        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

    private:
        T value;
};


template <class T>
Node<T>::Node(T item){
    value = item;

    left = nullptr;
    right = nullptr;
}

template <class T>
Node<T>::~Node(){
    left = nullptr;
    right = nullptr;
}

template <class T>
T Node<T>::getValue(){
    return value;
}

template <class T>
void Node<T>::setValue(T item){
    value = item;
}