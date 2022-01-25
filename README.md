# JNI
Starting jni in Mac vcode environment.

본 소스코드 경로는 [profectname]/src/* 이다.

1. [helloJNI].java 아래에 native를 선언하고 library를 load해준다.

2. Terminal에서 $ javac [helloJNI].java 명령을 수행한다.
- [helloJNI].class 파일 생성

3. 헤더 생성 : $ javah -JNI [helloJNI]
    (안 되면 다음 명령어 수행) $ javac [helloJNI].java -h .
    - 헤더 includepath 오류가 뜬다면 C/C++ Configurations 경로를 다음과 같이 수정해준다.
    /Applications/**
    /Users/[사용자 이름]/Desktop/**

4. C or C++ 소스코드 작성(첨부 소스코드)

5. 라이브러리 컴파일
[Java <=> C]
gcc -I”/[JDK 경로]/Contents/Home/include" -I”/[JDK 경로]/Contents/Home/include/darwin" -o lib[라이브러리명].jnilib -shared [패키지명].c

[Java <=> C++]
g++ -I"/[JDK 경로]/Contents/Home/include" -I"/[JDK 경로]/Contents/Home/include/darwin" -o lib[라이브러리명].jnilib -shared [패키지명].cpp

--> lib[라이브러리명 : helloJNI].jnilib 생성

* 세팅 완료 *

컴파일 : 라이브러리 참조 가져오기
java -Djava.library.path=. [helloJNI]

java 직접 컴파일
java [helloJNI].java 
