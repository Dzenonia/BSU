#include <limits>
#include <compare>

class StringView {
public:
    static const int N_POS;

    StringView();
    StringView(const char *ptr, int count = N_POS);
    ~StringView() = default;

    int length() const;
    bool empty() const;
    const char *data() const;

    bool startsWith(const StringView &str) const;
    bool endsWith(const StringView &str) const;
    void removePrefix(int count);
    void removeSuffix(int count);
    StringView substr(int pos, int count = N_POS) const;
    int find(StringView substr, int pos = 0) const;
    int find(char ch, int pos = 0) const;

    const char &operator[](int index) const;
    const char &at(int index) const;
    int compare(const StringView &other) const;
    std::strong_ordering operator<=>(const StringView &other) const;
    bool operator==(const StringView& other) const;


private:
    const char *data_;
    int length_;
};