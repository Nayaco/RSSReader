# RSSRaader

## 项目介绍

+ 本项目实现RSS订阅源的管理和阅读，实现了网络抓取RSS推送的功能

+ 项目详细报告见[Doc/MiniGrapher总体报告]()
+ 项目详细需求文档见[doc/ReuqestAnalisis]()

## 项目概况

+ 项目采用`C++17`标准开发，使用`Qt5`库，采用MVVM框架搭建
+ 支持跨平台编译，需`Qt5.13.0`及以上Qt版本以及`gcc-8.3.0`及以上GCC编译工具链
+ 采用TravisCI搭建持续集成环境 

## 功能实现

- [x] 添加RSS源，实现RSS订阅
- [x] 实现从RSS源抓取RSS文本
- [x] 实现富文本显示
- [x] 实现多RSS源切换
- [x] 实现sidebar管理源
- [x] 实现卡片效果

## 单元测试

### 测试方式

由于需要较多的网络资源，采用手动测试。编写测试文件，并在本地计算机上运行测试程序。

### 测试截图

![test_result](img/model1.png)

### 运行截图

+ 添加订阅源
![test_result](img/add.gif)

+ 订阅源摘要
![test_result](img/read1.gif)

+ 文章详情页面
![test_result](img/read2.gif)

## 项目目录
```
```

## 开发成员

+ 组长
    + [张文捷](https://github.com/Nayaco)
        + 分工协调，整体MVVM框架搭建、TravisCI持续集成环境配置
        + 负责Model层及网络请求RSS和RSS解析的实现
        + Model层数据持续化实现
        + App层组装、单元测试代码编写、二进制文件发布
+ 组员
    + [黄山](https://github.com/dydxh)


    + [郑泽晖]()
        + viewmodel基本功能实现