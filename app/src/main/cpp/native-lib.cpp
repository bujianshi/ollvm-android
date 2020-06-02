#include <jni.h>
#include <string>


int add(int a, int b) __attribute((__annotate__(("fla sub"))));

int add(int a, int b) {
    if (a >= 1)
        a += 1;
    int c = a + b;
    int d = c * c;
    return d;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    int a = 1, b = 2;
    int c = add(a, b);
    hello.append(c ? "!" : "?");
    return env->NewStringUTF(hello.c_str());
}
