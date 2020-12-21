// Module Math.

// Private attribute.
unsigned long current = 0;

// Private function.
int getCurrent() {
    return current++;
}

// Public function.
int MathIncrement(int x) {
    return x + getCurrent();
}

// Public function.
int MathNext() {
    return MathIncrement(0);
}
