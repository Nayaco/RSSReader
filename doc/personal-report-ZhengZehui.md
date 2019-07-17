## Viewmodel 设计报告

### 设计思路

Viewmodel属于中间层，负责View层和Model层之间的通信。

与MVC中的Control层类似都是为了使界面与模型分离，从而更好的分工协作。

Viewmodel的核心内容就是为model层和view层提供数据支持，将model层的数据进行处理输送到view层。主要的逻辑是在View和Model层中实现的。

### 实现方案

本次设计才用的是QT5 Community作为开发环境。QT可以方便地开发图形界面程序。

核心函数是UpStreamReciever和DownStreamReciever。

使用QT槽响应机制，信号由三个字符串构成。代表数据、操作类型、状态。

这两个函数处理信号的分支选择以及转换。

### 心得体会

- 这次课程接触到了工程中的协作模式以及配合方法。
- 学到了git的基本操作
- 装好了ubuntu系统
- 学习到了MVC、MVVM、MVP模式的概念以及优缺点。
- 初步了解了Travis-CI在线持续集成工具。
- 进一步对Qt环境熟悉
- 学会了cmake的使用


### 课程改进意见

- 希望可以能推荐几个典型的使用MVC、MVVM开发框架的开源项目参考，我们可以更好的理解MVVM这两种架构各自的优越性。