#include <jni.h>
#include <iostream>
#include "helloJNI.h"

JNIEXPORT void JNICALL Java_helloJNI_print
(
    JNIEnv  *env, 
    jobject  thiz
)
{
    std::cout << "여기는 C++ 내부 입니다!" << std::endl;
}
