// Module Math.

// Private attribute.
int current = 0;

// Private function.
int getCurrent() {
    return current++;
}

// Public function.
int TestlibIncrement(int x) {
    return x + getCurrent();
}

// Public function.
int TestlibNext() {
    return MathIncrement(0);
}
