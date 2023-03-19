#include "string_view.h"
#include <algorithm>
#include <cstring>
#include <stdexcept>

const int StringView::N_POS = std::numeric_limits<int>::max();

StringView::StringView() : data_(nullptr), length_(0) { }

StringView::StringView(const char* ptr, int count)
    : data_(ptr), length_(std::min(count, static_cast<int>(std::strlen(ptr)))) { }

int StringView::length() const {
    return length_;
}

bool StringView::empty() const {
    return length_ == 0;
}

const char* StringView::data() const {
    return data_;
}

const char& StringView::operator[](int index) const {
    return data_[index];
}

const char& StringView::at(int index) const {
    if (index < 0 || index >= length_) {
        throw std::out_of_range("Invalid index: " + std::to_string(index));
    }
    return data_[index];
}

bool StringView::startsWith(const StringView& str) const {
    if (str.length_ > length_) {
        return false;
    }
    int minSize = std::min(str.length_, length_);
    for (int i = 0; i < minSize; ++i) {
        if (str[i] != data_[i]) {
            return false;
        }
    }
    return true;
}

bool StringView::endsWith(const StringView& str) const {
    if (str.length_ > length_) {
        return false;
    }
    for (int i = length_ - str.length_; i < length_; ++i) {
        if (data_[i] != str[i - (length_ - str.length_)]) {
            return false;
        }
    }
    return true;
}

void StringView::removePrefix(int count) {
    length_ -= count;
    data_ += count;
}

void StringView::removeSuffix(int count) {
    length_ -= count;
}

StringView StringView::substr(int pos, int count) {
    return StringView(data_ + pos, std::min(count, length_ - pos));
}

int StringView::find(StringView substr, int pos) {

}
