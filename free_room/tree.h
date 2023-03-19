class Tree {

public:
    Tree(const std::vector<int>& array)
        : upNode(new Node(0, static_cast<int>(array.size()), array)) { }

    ~Tree() { delete upNode; }

    ll getMaxOnSegment(int left, int right) {
        if (left >= right || left < 0 || right > upNode->right) {
            //            throw std::invalid_argument("Wrong bond!");
            return -1;
        }
        return upNode->getMax(left, right);
    }

    ll getValue(int position) { return getMaxOnSegment(position, position + 1); }

    void update(int left, int right, ll value) {
        if (left >= right || left < 0 || right > upNode->right) {
            return;
        }
        upNode->update(left, right, value);
    }


private:
    class Node {
    public:
        Node(int left, int right, const std::vector<int>& array)
            : left(left),
              right(right),
              needPush(0),
              valueToPush(-1),
              leftNode(nullptr),
              rightNode(nullptr) {
            if (left + 1 == right) {
                value = array[left];
                return;
            }
            int mid = (left + right) >> 1;
            leftNode = new Node(left, mid, array);
            rightNode = new Node(mid, right, array);
            value = std::max(leftNode->value, rightNode->value);
        }

        ~Node() {
            delete leftNode;
            delete rightNode;
        }

        ll getMax(int leftBound, int rightBound) {
            push();
            if (leftBound >= right || rightBound <= left) {
                return 0;
            }
            if (left >= leftBound && right <= rightBound) {
                return value;
            }
            return std::max(
                leftNode->getMax(leftBound, rightBound), rightNode->getMax(leftBound, rightBound)
            );
        }

        void update(int leftBound, int rightBound, ll updateValue) {
            push();
            if (leftBound >= right || rightBound <= left) {
                return;
            }
            if (left >= leftBound && right <= rightBound) {
                setPush(updateValue);
                return;
            }
            leftNode->update(leftBound, rightBound, updateValue);
            rightNode->update(leftBound, rightBound, updateValue);
        }

        void setPush(ll pushValue) {
            needPush = 1;
            valueToPush = std::max(valueToPush, pushValue);
        }

        void push() {
            if (!needPush) {
                return;
            }
            value = std::max(value, valueToPush);
            needPush = 0;
            if (left + 1 == right) {
                return;
            }
            leftNode->setPush(valueToPush);
            rightNode->setPush(valueToPush);
        }

        int left;
        int right;
        bool needPush;
        ll valueToPush;
        ll value;
        Node* leftNode;
        Node* rightNode;
    };

    Node* upNode;
};