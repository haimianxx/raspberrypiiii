# 基于opencv(c++版)的人脸识别打卡机
（Face recognition punch card machine based on opencv）

**配置树莓派环境**

1.打开命令行更新树莓派
 `sudo apt-get update` or `sudo apt-get upgrate`

2.下载opencv的package 
`sudo apt-get install libopencv-dev`

3.下载百度AI的c++sdk包
网址：https://ai.baidu.com/sdk#bfr

4.下载百度AI文档中说明的支持包(包名称可能会有差异，若出现没有包的情况，百度搜一下包名称可马上解决)
(**这里还需下载ssl包**)

5.主程序代码为face_detect的main.cpp（具体代码可能随着opencv的版本和百度AI的sdk包略有差异）

6.命令行切换到face_detect文件下，编译时链接opencv的库文件和其他库文件
我的编译指令为```g++ New.cpp -o main -std=c++11 -I/usr/include/opencv4/
-lopencv_core -lopencv_videoio -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_imgcodecs  -lcurl -lcrypto -ljsoncpp``` 
  1. (-I ( i 的大写)  ：指定头文件路径（相对路径或觉得路径，建议相对路径）
  2. -i              ：指定头文件名字 (一般不使用，而是直接放在**.c 文件中通过#include<***.h> 添加)
  3. -L              ：指定连接的动态库或者静态库路径（相对路径或觉得路径，建议相对路径）
  4. -l (L的小写)：指定需要链接的库的名字（链接 libc.a :-lc 链接动态库：libc.so : -lc 注意：-l后面直接添加库名省去“lib”和“.so”或“.a”  ）


