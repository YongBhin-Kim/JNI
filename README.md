# JNI
<h3>Starting JNI in Mac vscode environment.<h3>

    
1. Java 소스코드 작성<br>
    Decline native, load library (helloJNI.java 소스코드 참조)<br>
<br>
    
2. 클래스 파일 생성<br>
    
      `$ javac [helloJNI].java` <br>
    
      * create [helloJNI].class
<br>
    
3. 헤더 생성<br>
    
      `$ javah -JNI [helloJNI]         (구 버전)` <br>
      `$ javac [helloJNI].java -h .    (신 버전)` <br>
<br>
    
* 헤더 includepath 오류가 뜬다면 C/C++ Configurations 경로를 다음과 같이 수정해준다.<br>
    
     `/Applications/**` <br>
     `/Users/[사용자 이름]/Desktop/**`<br>
<br>
    
4. C or C++ 소스코드 작성(helloJNI.cpp 소스코드 참조)
<br>
    
5. 라이브러리 컴파일
* [Java <=> C]
   
      $ gcc -I”/[JDK 경로]/Contents/Home/include" -I”/[JDK 경로]/Contents/Home/include/darwin" -o lib[라이브러리명].jnilib -shared [패키지명].c

* [Java <=> C++]

      $ g++ -I"/[JDK 경로]/Contents/Home/include" -I"/[JDK 경로]/Contents/Home/include/darwin" -o lib[라이브러리명].jnilib -shared [패키지명].cpp

     * lib[라이브러리명].jnilib 생성

* 세팅 완료 및 컴파일<br>
   * 라이브러리 참조 가져오기
        
         $ java -Djava.library.path=. [helloJNI]

   * java 직접 컴파일

         $ java [helloJNI].java 
