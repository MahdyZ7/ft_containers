/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterators.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:32:24 by ayassin           #+#    #+#             */
/*   Updated: 2023/03/28 13:35:47 by ayassin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITRATORS_HPP
#define ITRATORS_HPP

#include <iterator>
#include "vector.hpp"
template <class T>
class iterator :public std::iterator<std::random_access_iterator_tag, ValueType> {

   private:
      const Vector *vp;
      int index;

   public:

      iterator() {
         this->vp = NULL;
      }

      iterator(const iterator & it) {
         this->vp = it.vp;
         this->index = it.index;
      }

      iterator(const Vector *vp, int index) {
         this->vp = vp;
         this->index = index;
      }

      iterator & operator++() {
         index++;
         return *this;
      }

      iterator operator++(int) {
         iterator copy(*this);
         operator++();
         return copy;
      }

      iterator & operator--() {
         index--;
         return *this;
      }

      iterator operator--(int) {
         iterator copy(*this);
         operator--();
         return copy;
      }

      bool operator==(const iterator & rhs) {
         return vp == rhs.vp && index == rhs.index;
      }

      bool operator!=(const iterator & rhs) {
         return !(*this == rhs);
      }

      bool operator<(const iterator & rhs) {
         extern void error(std::string msg);
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index < rhs.index;
      }

      bool operator<=(const iterator & rhs) {
         extern void error(std::string msg);
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index <= rhs.index;
      }

      bool operator>(const iterator & rhs) {
         extern void error(std::string msg);
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index > rhs.index;
      }

      bool operator>=(const iterator & rhs) {
         extern void error(std::string msg);
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index >= rhs.index;
      }

      iterator operator+(const int & rhs) {
         return iterator(vp, index + rhs);
      }

      iterator operator+=(const int & rhs) {
         index += rhs;
         return *this;
      }

      iterator operator-(const int & rhs) {
         return iterator(vp, index - rhs);
      }

      iterator operator-=(const int & rhs) {
         index -= rhs;
         return *this;
      }

      int operator-(const iterator & rhs) {
         extern void error(std::string msg);
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index - rhs.index;
      }

      ValueType & operator*() {
         return vp->elements[index];
      }

      ValueType *operator->() {
         return &vp->elements[index];
      }

      ValueType & operator[](int k) {
         return vp->elements[index + k];
      }

   };

   iterator begin() const {
      return iterator(this, 0);
   }

   iterator end() const {
      return iterator(this, count);
   }

};
#endif