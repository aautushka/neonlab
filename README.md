# console-app-android

This is a very basic example which allows you to build and run a console application on Android, no IDE is required.

1. Export Android NDK path
```
export ANDROID_NDK=~/Library/Android/sdk/ndk-bundle
```
2. Configure the project with API 21 and armv7 architecture 
```
mkdir build && cd build

cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_PLATFORM="android-21" -DANDROID_ABI="armeabi-v7a with NEON" -DANDROID_STL=c++_static -D CMAKE_BUILD_TYPE=Release -DNEON=ON ..

```
3. Build
```
make
```
4. Copy to Android and run (does not require a rooted device)
```
adb push console-app-android /data/local/tmp
adb shell "chmod +x /data/local/tmp; /data/local/tmp/console-app-android"
```



