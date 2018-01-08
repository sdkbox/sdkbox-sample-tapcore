
# How to run sdkbox samples

Steps:

~~~bash
mkdir samples
cd samples

# must clone this repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-cocos2d-x-binary.git

# clone sample repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-sample-tapcore.git

# run sample with specified language and platform
# eg: cpp and ios
./sdkbox-cocos2d-x-binary/run_sample.sh tapcore cpp ios
# javascript and android
./sdkbox-cocos2d-x-binary/run_sample.sh tapcore js android

# <optional> if exists "download-depends.sh" in sample repo, execute it
# ./sdkbox-sample-tapcore/download-depends.sh

~~~

Memo:

1.  Sample repo and cocos2dx repo must be in same level directory

~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-tapcore
| +-- cpp
| +-- lua
| \-- js
~~~


## CRASH

Tapcore support lots of `APP_ABI`:

```
     0  01-04-2018 08:38   lib/x86_64/
     9880  01-04-2018 08:38   lib/x86_64/libdVexZld.so
        0  01-04-2018 08:38   lib/mips64/
    14472  01-04-2018 08:38   lib/mips64/libdVexZld.so
        0  01-04-2018 08:38   lib/mips/
    71228  01-04-2018 08:38   lib/mips/libdVexZld.so
        0  01-04-2018 08:38   lib/arm64-v8a/
     9616  01-04-2018 08:38   lib/arm64-v8a/libdVexZld.so
        0  01-04-2018 08:38   lib/armeabi-v7a/
    13564  01-04-2018 08:38   lib/armeabi-v7a/libdVexZld.so
        0  01-04-2018 08:38   lib/x86/
     9360  01-04-2018 08:38   lib/x86/libdVexZld.so
        0  01-04-2018 08:38   lib/armeabi/
    13552  01-04-2018 08:38   lib/armeabi/libdVexZld.so
```

plz remove those `ABI` that your game do not support. How to check your game abi:

1. unzip your.apk
2. check folder name in `libs`

## 中文

由于 tapcore 的 sdk 支持很多架构，armeabi, armeabi-v7a, arm64, x86, mips。所以：

当游戏启动时发现奔溃的话，需要检查游戏所支持的架构。把 tapcore-xxx.jar 里不支持的架构，动态库，删除。
并重新打包 jar 。


解压 jar
```
jar xf tapcore-*.jar
```

重新打包 jar
```
jar cf tapcore-*.jar .
```
