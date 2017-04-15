// Module Math.

// Private attribute.
int current = 0;

// Private function.
int getCurrent() {
    return current++;
}

// Public function.
int _Increment(int x) {
    return x + getCurrent();
}

// Public function.
int _Next() {
    return _Increment(0);
}
