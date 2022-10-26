template <class T>
class Tree {

    public:
        Tree();
        ~Tree();

        bool insert(T);
        bool find(T);
        int size() const = 0;
        T* getAllAscending();
        void clear();

    private:

};