# 前自增减单目操作符：前++、前--

* 操作数为左值
* 表达式的值为左值，且为操作数本身（而非副本）
* 成员函数形式

  ```
  class OPERAND {
  	OPERAND& operator#() { ... }
  };
  ```
* 全局函数形式
  ```
  OPERAND& operator#(OPERAND& operand) { ... }
  ```

  