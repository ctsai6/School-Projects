template <typename E> // Array-based list implementation
class AList : public List<E>
{
private:
    int maxSize; // Maximum size of list
    int listSize; // Number of list items now
    int curr; // Position of current element
    E* listArray; // Array holding list elements
public:
    AList(int size = defaultSize) { // Constructor
        maxSize = size;
        listSize = curr = 0;
        listArray = new E[maxSize];
    }
    AList() { delete[] listArray; } // Destructor
    void clear() { // Reinitialize the list
        delete[] listArray; // Remove the array
        listSize = curr = 0; // Reset the size
        listArray = new E[maxSize]; // Recreate array
    }
    // Insert "it" at current position
    void insert(const E& it) {

        if (listSize == maxSize - 1) {

            E* temp = new E[2 * maxSize];

            for (int i = 0; i < listSize; i++)

                temp[i] = listArray[i];

            delete[] listArray;

            listArray = temp;

            maxSize = 2 * maxSize;

        }

        for (int i = listSize; i > curr; i--)

            listArray[i] = listArray[i - 1];

        listArray[curr] = it;

        listSize++;

    }
    // Remove and return the current element.
    E remove() {
        Assert((curr >= 0) && (curr < listSize), "No element");
        E it = listArray[curr]; // Copy the element
        for (int i = curr; i < listSize - 1; i++) // Shift them down
            listArray[i] = listArray[i + 1];
        listSize--; // Decrement size
        return it;
    }

    void moveToStart() { curr = 0; } // Reset position
    void moveToEnd() { curr = listSize; } // Set at end
    void prev() { if (curr != 0) curr--; } // Back up
    void next() { if (curr < listSize) curr++; } // Next
    // Return list size
    int length() const { return listSize; }
    // Return current position
    int currPos() const { return curr; }
    // Set current list position to "pos"
    void moveToPos(int pos) {
        Assert((pos >= 0) && (pos <= listSize), "Pos out of range");
        curr = pos;
    }
    const E& getValue() const { // Return current element
        Assert((curr >= 0) && (curr < listSize), "No current element");
        return listArray[curr];
    }
};