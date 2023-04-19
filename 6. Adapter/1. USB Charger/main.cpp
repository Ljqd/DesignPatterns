#include <jni.h>
#include <iostream>
#include <string>

#include <windows.h>

#define CLEAR(x) memset(&x, 0, sizeof(x))

// Useful links:
// // About VS dependincies
// https://stackoverflow.com/questions/52969159/vs-2017-unable-to-open-include-file-jni-h (you need also set Link:Input)
// - "Tutorials"
// https://docs.oracle.com/javase/1.5.0/docs/guide/jni/spec/jniTOC.html
// https://download.java.net/java/early_access/loom/docs/specs/jni/invocation.html
// - Useful example
// https://www.codeproject.com/Questions/5302165/Need-a-clarification-using-jni
// - Windows VS2022, fix access violation
// https://stackoverflow.com/questions/36250235/exception-0xc0000005-from-jni-createjavavm-jvm-dll/53654317#53654317
// - Another tutorial (not really needed, but let it be)
// https://www3.ntu.edu.sg/home/ehchua/programming/java/javanativeinterface.html

JNIEnv* create_vm(JavaVM** jvm)
{
    JNIEnv* env;
    JavaVMInitArgs vm_args;
    CLEAR(vm_args);
    JavaVMOption* options = new JavaVMOption[1];
    CLEAR(*options);
    HMODULE jvm_dll = NULL;

    char path[] = "-Djava.class.path=libs/MicroUsb.jar";
    options[0].optionString = path; //Path to the java source code
    options[0].extraInfo = 0;
    vm_args.version = JNI_VERSION_10;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = false;

    // Load Dll
    const size_t size = 400;
    size_t store[size];
    wchar_t t[size];
    mbstowcs_s(store, t, "C:\\Program Files\\Java\\jdk-20\\bin\\server\\jvm.dll", 400);
    jvm_dll = LoadLibrary(t); 

    /// You might check the GetLastError() here after the LoadLibrary()
    if (jvm_dll == NULL) {
        printf("can't load dll\n");
        printf("error code %d", GetLastError());
    }

    JNI_CreateJavaVM(jvm, (void**)&env, &vm_args);

    return env;
}
int main()
{
    JNIEnv* env;
    JavaVM* jvm;
    env = create_vm(&jvm);
    if (env == NULL)
    {
        printf("Error");
    }
    return 0;
}