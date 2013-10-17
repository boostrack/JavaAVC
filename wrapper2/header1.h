enum Enum1 {
    value1, 
    value2 = 123, 
    value3, 
    value4
};

struct Struct1;

struct Struct1 {
    int a;
    double b;
};

typedef struct Struct3 {
    int c;
    double d;
} MyStruct3;

void f1(int a, double b, MyStruct3 c);

const char *f2(void);

const char* f3(const char* a, int b);

