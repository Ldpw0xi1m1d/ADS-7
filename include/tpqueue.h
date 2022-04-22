// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

#include <string>

template <typename T>
      class TPQueue {
 private:
           
       struct Item {
                        T value;
                        Item* next;
                };
                Item* head = nullptr;
                TPQueue::Item* create(const T& value);
 public:
            
      TPQueue();
                TPQueue(const T&);
                void addHead(const T&);
                void push(const T& value);
                T pop();
       };
        template <typename T>
        typename TPQueue <T>::Item* TPQueue<T>::create(const T& value) {
                Item* item = new Item;
                item->value = value;
                item->next = nullptr;
                return item;
        }
       template <typename T>
        TPQueue <T>::TPQueue() {
               head = nullptr;
        }
       template <typename T>
        TPQueue <T>::TPQueue(const T& value) {
                 head = create(value);
        }
        template <typename T>
        void TPQueue<T>::addHead(const T& value) {
                 if (head) {
                      Item* temp = create(value);
                      temp->next = head;
                      head = temp;
                  } else {
                      head = create(value);
               }
        }
       template <typename T>
        void TPQueue <T>::push(const T& value) {
                Item* current = nullptr;
                if (head == nullptr) {
                      head = create(value);
                 } else {
                       Item* first = head;
                         while (first != nullptr) {
                              if (first->value.prior > value.prior) {
                                       Item* temp = new Item;
                                       temp->value = first->value;
                                       temp->next = create(value);
                                } else if (first->value.prior < value.prior) {
                                        Item* temp = new Item;
                                        temp->value = first->value;
                                        temp->next = first->next;
                                        first->value = value;
                                        first->next = temp;
                                       return;
                                  }
                                current = first;
                                first = first->next;
                       }
                        current->next = create(value);
               }
       }
        template <typename T>
        T TPQueue <T>::pop() {
                if (head == nullptr) {
                      throw std::string("Empty!");
                 } else {
                       Item* first = head;
                       if (first != nullptr) {
                                T temp = first->value;
                                head = first->next;
                                return temp;
                        }
} }

struct SYM {
        char ch;
        int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
