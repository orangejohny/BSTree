#include <node.hpp>
#include <iterator>

namespace BSTree {
template<typename type>
class bIt : public std::iterator<std::bidirectional_iterator_tag, Node<type>> {
private:
    Node<type>* ptr;
public:
    bIt(Node<type>* p) : ptr{p} {};
    bIt(const bIt<type>& other) : ptr{other.ptr} {};
    bIt<type>& operator=(const bIt<type>& other);
};

template<typename type>
bIt<type>& bIt<type>::operator=(const bIt<type>& other) {
    ptr = other.ptr;
}
}




