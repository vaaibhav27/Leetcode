class MyHashSet {
public:
    vector<bool> arr;

    MyHashSet() {
        arr.resize(1000001, false);
    }

    void add(int key) {
        arr[key] = true;
    }

    void remove(int key) {
        arr[key] = false;
    }

    bool contains(int key) {
        return arr[key];
    }
};