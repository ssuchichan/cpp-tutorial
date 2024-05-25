# 二进制I/O

* 读取二进制数据
  * `istream& istream::read(char* buffer, streamsize num);`
  * 从输入流中读取num个字节到缓冲区buffer中
  * 返回流本身，其在buer上下文中的值，成功（读满）为true，失败（没读满）为false
  * 如果没读满num个字节，函数就返回了，比如遇到文件尾，最后一次读到缓冲区buffer中的字节数，可以通过`istream::gcount()`函数获得

* 写入二进制数据
  * `ostream& ostream::write(const char* buffer, streamsize num);`
  * 将缓冲区buffer中num个字节写入到输出流中
  * 返回流本身，其在布尔上下文中的值，成功（写满）为true，失败（没写满）为false


