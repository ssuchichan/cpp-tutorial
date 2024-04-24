# 单目操作运算符重载

## 运算类单目操作符：-、~、!等

* 操作数为左值或右值
* 表达式的值为右值
* 成员函数形式
  ```
  class OPERAND {
  	const RESULT operator#() const { ... }
  };
  ```
* 全局函数形式
  ```
  const RESULT operator#(const OPERAND& operand) { ... }
  ```





