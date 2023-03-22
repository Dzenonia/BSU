#include <compare>

class String {
public:
    String();
    String(const char* ptr);
    String(int count, char sym);
    String(const String& another);
    String(String&& another);
    ~String();

    String& operator=(const String& another);
    String& operator=(String&& another);

    int length() const;
    bool empty() const;
    const char* cStr() const;

    char& front();
    char& back();
    const char& front() const;
    const char& back() const;

    void reserve(int capacity);
    void push_back(char sym);
    void pop_back();
    void clear();
    void insert(int index, const String& str);
    void erase(int index, int count = 1);


    char& operator[](int index);
    const char& operator[](int index) const;
    String& operator+=(const String& rhs);

    int compare(const String& other) const;
    std::strong_ordering operator<=>(const String& other) const;
    bool operator==(const String& rhs) const;

private:
    int length_;
    int capacity_;
    char* data_;
};