class MyClass {
public:
    explicit MyClass(int x) { /* constructor code */ }
};

void someFunction(MyClass obj) { /* function code */ }

int main() {
    MyClass obj1(10); // Constructor llamado de manera explícita
    MyClass obj2 = 20; // Error: no se puede realizar una conversión implícita
    someFunction(30); // Error: no se puede realizar una conversión implícita
    return 0;
}
