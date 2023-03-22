#include "string_view.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>
#include <string>
#include <iostream>

const int StringView::N_POS = std::numeric_limits<int>::max();

StringView::StringView() : data_(nullptr), length_(0) {}

StringView::StringView(const char *ptr, int count)
        : data_(ptr), length_(std::min(count, static_cast<int>(std::strlen(ptr)))) {}

int StringView::length() const {
    return length_;
}

bool StringView::empty() const {
    return length_ == 0;
}

const char *StringView::data() const {
    return data_;
}

const char &StringView::operator[](int index) const {
    return data_[index];
}

const char &StringView::at(int index) const {
    if (index < 0 || index >= length_) {
        throw std::out_of_range("Invalid index: " + std::to_string(index));
    }
    return data_[index];
}

bool StringView::startsWith(const StringView &str) const {
    if (str.length_ > length_) {
        return false;
    }
    return substr(0, str.length_) == str;
}

bool StringView::endsWith(const StringView &str) const {
    if (str.length_ > length_) {
        return false;
    }
    return substr(length_ - str.length_, str.length_) == str;
}

void StringView::removePrefix(int count) {
    length_ -= count;
    data_ += count;
}

void StringView::removeSuffix(int count) {
    length_ -= count;
}

StringView StringView::substr(int pos, int count) const {
    return StringView(data_ + pos, std::min(count, length_ - pos));
}

int StringView::find(StringView substr, int pos) const {
    for (int i = pos; i < length_; ++i) {
        if (StringView::substr(i, substr.length_) == substr) {
            return i;
        }
    }
    return N_POS;
}

std::strong_ordering StringView::operator<=>(const StringView &other) const {
    int cmp = compare(other);
    if (cmp < 0) {
        return std::strong_ordering::less;
    }
    if (cmp > 0) {
        return std::strong_ordering::greater;
    }
    return std::strong_ordering::equal;
}

int StringView::compare(const StringView &other) const {
    int len = std::min(length_, other.length_);
    int cmp = std::memcmp(data_, other.data_, len);
    if (other.length_ == length_ || cmp != 0) {
        return cmp;
    } else {
        return length_ - other.length_;
    }
}

bool StringView::operator==(const StringView &other) const {
    return compare(other) == 0;
}

int StringView::find(char ch, int pos) const {
    for (int i = pos; i < length_; ++i) {
        if (data_[i] == ch) {
            return i;
        }
    }
    return N_POS;
}
