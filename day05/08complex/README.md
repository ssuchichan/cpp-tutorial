## 赋值类双目操作符：=、+=、-=、*=、/=等

* 右操作数为左值或右值，但左操作数必须是左值
* 表达式的值是左值，且为做操作数本身（而非副本）
* 成员函数形式
  ```
  class LEFT {
  	LEFT& operator#(const RIGHT& right) { ... }
  };
  ```
* 全局函数形式
  ```
  LEFT& operator#(LEFT& left, const RIGHT& right) { ... }
  ```

  