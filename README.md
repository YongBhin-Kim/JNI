<h2>Starting JNI(Java Native Interface)</h2>

    
**[Environment]** <br>
- Mac OS
- Visual Studio Code 2
- G++ version 4.2.1
- Java version 17.0.1
<br><br><br>

**[1. 자바 소스코드 작성]** : `helloJNI.java` <br>

- Decline native <br> 
<img width="366" height = "100" alt="image" src="https://user-images.githubusercontent.com/98372474/158514125-7a9a072c-6d55-4ee0-871b-103dc3a73fe4.png">
    
- Load library <br>
<img width="343" alt="image" src="https://user-images.githubusercontent.com/98372474/158514175-ca310415-9bdb-43fb-9adb-1278da999370.png">
<br><br><br>

    
**[2. 클래스파일 생성]** <br>

- 터미널에서 `$ javac [helloJNI].java` 명령 <br>
: `[helloJNI].class` 파일이 생성된다. <br>
<br><br><br>


**[3. 헤더 생성]** <br>

- 자바의 버전에 따라 명령어가 달라진다.
- `$ javah -JNI [helloJNI]         `(구 버전) <br>
- `$ javac [helloJNI].java -h .    `(신 버전) <br>
: `[helloJNI].h` 파일이 생성된다. <br>
<br><br>
    
- 헤더 includepath 오류가 뜬다면 C/C++ Configurations 경로를 다음과 같이 수정해준다.<br>
    
```
/Applications/**
/Users/[사용자 이름]/Desktop/**
```
<br>

[오류] <br>
<img width ="400" height="250" alt = "image" src="https://user-images.githubusercontent.com/98372474/158515058-35238761-2a13-47d3-8344-e09144127345.png">

[c_cpp_properties.json 파일] : "includePath" 수정 <br>
<img width = "450" height = "200" src = "https://user-images.githubusercontent.com/98372474/158515078-fc9d7449-1fb1-46bd-9a4c-ad26238eeb84.png">
<br><br><br>
    
    
**[4. C or C++ 소스코드 작성]** <br>
<img width="450" height = "200" alt = "image" src = "https://user-images.githubusercontent.com/98372474/158515765-3ea0b62f-0fcc-41b0-84dd-cd581fabcad0.png">
<br><br><br>
    

**[5. 라이브러리 컴파일]** <br>
    
- [Java <=> C] <br>

`$ gcc -I”/[JDK 경로]/Contents/Home/include" -I”/[JDK 경로]/Contents/Home/include/darwin" -o lib[라이브러리명].jnilib -shared [패키지명].c` <br>
<br>

- [Java <=> C++] <br>
    
`$ g++ -I"/[JDK 경로]/Contents/Home/include" -I"/[JDK 경로]/Contents/Home/include/darwin" -o lib[라이브러리명].jnilib -shared [패키지명].cpp` <br>
<br>

: `lib[라이브러리명].jnilib` 생성
<br><br><br>
    
**[세팅 완료 및 컴파일]** <br>
    
[라이브러리 참조 가져오기] <br>
    
- `$ java -Djava.library.path=. [helloJNI]` <br>
<br>

[java 직접 컴파일] <br>
    
- `$ java [helloJNI].java` <br>
<br><br><br>
    
    
**[컴파일 결과]** <br>

![image](https://user-images.githubusercontent.com/98372474/158517275-2b799358-4341-474d-af48-38303c0a856c.png)

