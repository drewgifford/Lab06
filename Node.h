using namespace std;

template <class T>
class Node{

    public:
        Node(T item);
        ~Node();

        shared_ptr<Node> getNext();
        setNext(shared_ptr<Node> next);




    private:
        T value;
        shared_ptr<Node> next;

};