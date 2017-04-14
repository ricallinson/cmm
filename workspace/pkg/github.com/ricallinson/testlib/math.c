// Module Math.

// Private attribute.
int current = 0;

// Private function.
int getCurrent() {
    return current++;
}

// Public function.
int MathIncrement(int x) {
    return x + getCurrent();
}

int MathNext() {
    return MathIncrement(0);
}
