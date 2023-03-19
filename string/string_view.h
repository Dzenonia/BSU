#include <limits>

class StringView {
public:
    static const int N_POS;
    StringView();
    StringView(const char* ptr, int count = N_POS);
    ~StringView() = default;

    int length() const;
    bool empty() const;
    const char* data() const;

    bool startsWith(const StringView& str) const;
    bool endsWith(const StringView& str) const;
    void removePrefix(int count);
    void removeSuffix(int count);

    StringView substr(int pos, int count = N_POS);
    int find(StringView substr, int pos = 0);

    const char& operator[](int index) const;
    const char& at(int index) const;


private:
    const char* data_;
    int length_;
};