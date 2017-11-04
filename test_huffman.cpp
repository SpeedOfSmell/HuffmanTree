// test_huffman.cpp
// c. 2015 A. Deeter

#include <iostream>
#include "Huffman.hpp"

int main() {
    Heap h = Heap();
    h.enqueue(new HNode('a', 0));
    h.enqueue(new HNode('c', 0));
    h.enqueue(new HNode('f', 0));
    h.enqueue(new HNode('h', 0));
    h.enqueue(new HNode('j', 0));
    h.enqueue(new HNode('p', 0));
    h.print();

    std::cout << std::endl;
    h.dequeue();
    h.print();

    std::cout << std::endl;
    h.dequeue();
    h.print();

    h.dequeue();
    h.dequeue();
    h.dequeue();

    std::cout << std::endl;
    h.dequeue();
    h.print();

  /*Huffman h;
  Encoded e = h.encode("MISSISSIPPI");

  std::cout << "Input: MISSISSIPPI" << std::endl;
  std::cout << e.encoded_string << std::endl;
  std::cout << e.serialized_tree << std::endl;

  std::cout << "Input: A man a plan, a canal, Panama!" << std::endl;
  Encoded a = h.encode("A man a plan, a canal, Panama!");
  std::cout << a.encoded_string << std::endl;
  std::cout << a.serialized_tree << std::endl;*/

}
