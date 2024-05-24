# 格式化IO

* 流函数
    * IO流类定义了一组用于控制输入输出格式的公有成员函数，调用这些函数可以改变IO流对象内部的格式状态，进而影响后续输入输出的格式化方式
* 流控制符（Stream Manipulator）
    * 标准库定义了一组特殊的全局函数，它们有的带有参数（在iomanip头文件中声明），有的不带参数（在iostream头文件中声明），可被直接嵌入到输入
      输出表达式中，影响后续输入输出格式，称为流控制符

# IO流格式化函数

![iofmtfunc](../../docs/pics/iofmtfunc.png)

* 一般而言，对IO流格式的改变都是持久的，即只要不再设置新格式，当前格式将始终保持下去
* 显式域宽是个例外，通过`ios::width(int)`所设置的显示域宽，只影响紧随其后的第一次输出，再往后的输出又恢复到默认状态

# I/O流格式标志

![fmtflag](../../docs/pics/fmtflag.png)

# I/O流格式化控制符

![fmtcontrol](../../docs/pics/fmtcontrol.png)








