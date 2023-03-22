#include "string.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <iostream>

String::String() : length_(0), capacity_(1), data_(new char[capacity_]) {
    data_[0] = '\0';
}

String::String(int count, char sym)
        : length_(count), capacity_(count + 1), data_(new char[capacity_]) {
    std::fill_n(data_, length_, sym);
    data_[length_] = '\0';
}

String::String(const char *ptr)
        : length_(std::strlen(ptr)), capacity_(length_ + 1), data_(new char[capacity_]) {
    std::strcpy(data_, ptr);
}

String::String(const String &another)
        : length_(another.length_), capacity_(another.capacity_), data_(new char[capacity_]) {
    std::strcpy(data_, another.data_);
}

String::String(String &&another)
        : length_(another.length_), capacity_(another.capacity_), data_(another.data_) {
    another.length_ = 0;
    another.capacity_ = 1;
    another.data_ = new char[capacity_];
    another.data_[0] = '\0';
}

String::~String() {
    delete[] data_;
}

String &String::operator=(const String &another) {
    if (this != &another) {
        delete[] data_;
        length_ = another.length_;
        capacity_ = another.capacity_;
        data_ = new char[capacity_];
        std::strcpy(data_, another.data_);
    }
    return *this;
}

String &String::operator=(String &&another) {
    if (this != &another) {
        delete[] data_;
        length_ = another.length_;
        capacity_ = another.capacity_;
        data_ = another.data_;
        another.length_ = 0;
        another.capacity_ = 1;
        another.data_ = new char[capacity_];
        another.data_[0] = '\0';
    }
    return *this;
}

int String::length() const {
    return length_;
}

bool String::empty() const {
    return length_ == 0;
}

const char *String::cStr() const {
    return data_;
}

char &String::front() {
    if (length_ == 0) {
        throw std::out_of_range("String is empty!");
    }
    return data_[0];
}

char &String::back() {
    if (length_ == 0) {
        throw std::out_of_range("String is empty!");
    }
    return data_[length_ - 1];
}

const char &String::front() const {
    if (length_ == 0) {
        throw std::out_of_range("String is empty!");
    }
    return data_[0];
}

const char &String::back() const {
    if (empty()) {
        throw std::out_of_range("String is empty!");
    }
    return data_[length_ - 1];
}

char &String::operator[](int index) {
    if (index < 0 || index >= length_) {
        throw std::out_of_range("Out of range error: index should be between 0 and length - 1");
    }
    return data_[index];
}

const char &String::operator[](int index) const {
    if (index < 0 || index >= length_) {
        throw std::out_of_range("Out of range error: index should be between 0 and length - 1");
    }
    return data_[index];
}

void String::reserve(int capacity) {
    if (capacity_ >= capacity) {
        return;
    }
    char *newData = new char[capacity];
    std::memcpy(newData, data_, length_ + 1);
    delete[] data_;
    data_ = newData;
    capacity_ = capacity;
}

void String::push_back(char sym) {
    if (length_ + 1 >= capacity_) {
        reserve(2 * capacity_);
    }
    data_[length_++] = sym;
    data_[length_] = '\0';
}

void String::pop_back() {
    if (empty()) {
        throw std::out_of_range("String is empty!");
    }
    data_[--length_] = '\0';
}

void String::clear() {
    length_ = 0;
    data_[0] = '\0';
}

String &String::operator+=(const String &rhs) {
    String add = rhs;
    reserve(length_ + rhs.length_);
    std::strcat(data_, rhs.data_);
    length_ += rhs.length_;

    return *this;
}

bool String::operator==(const String &rhs) const {
    if (rhs.length_ != length_) {
        return false;
    }
    return strcmp(data_, rhs.data_) == 0;
}

int String::compare(const String &other) const {
    return std::strcmp(data_, other.data_);
}

std::strong_ordering String::operator<=>(const String &other) const {
    int cmp = compare(other);
    if (cmp < 0) {
        return std::strong_ordering::less;
    }
    if (cmp > 0) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}

void String::insert(int index, const String &str) {
    if (str.empty()) {
        return;
    }
    reserve(str.length_ + length_ + 1);
    for (int i = length_; i >= index; --i) {
        data_[i + str.length_] = data_[i];
    }
    memcpy(data_ + index, str.data_, str.length_);
    length_ += str.length_;
}

void String::erase(int index, int count) {
    for (int i = index + count; i <= length_; ++i) {
        data_[i - count] = data_[i];
    }
    length_ -= count;
}
