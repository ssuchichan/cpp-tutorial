# 非格式化IO

* 读取字符
  * `int istream::get();`
    * 成功返回读到的字符，失败或遇到文件尾返回`EOF`
  * `istream& istream::get(char& ch);`
    * 返回输入流本省，其在buffer上下文中的值，成功为rue，失败或遇到文件尾为false
  * `istream& istream::get(char* buff, streamsize num, char delin='\n');`
    * 读取字符到buffer中，直到读满num-1个字符，或遇到文件尾，或遇到定界符`delim`（缺省为换行符），追加结尾空字符，返回流本身
    * 如果因为遇到定界符返回，定界符并不被读取，读指针停在该定界符处
* 读取行
  * `istream& istream::getline(char* buffer, streamsize num, char delim='\n');`
    * 读取字符到buffer中，直到读满num-1个字符，或遇到文件尾，或遇到定界符delim（缺省为换行符），追加结尾空字符，返回流本身
    * 如果因为遇到定界符返回，定界符被读取并丢弃，读指针停在该定界符的下一个位置
* 放回字符
  * `istream& istream::putback(char ch);`
    * 将字符ch放回输入流，返回流本
* 窥视字符
  * `int istream::peek();`
    * 返回但不读取读指针当前位置处的字符，失败或遇到文件尾返回`EOF`
* 忽略字符
  * `istream& istream::ignore(streamsize num=1, int delim=EOF);`
    * 忽略输入流中的num（缺省为1）个字符，或遇到定界符delim（缺省到文件尾），返回流本省
    * 如果因为遇到定界符返回，定界符并不被忽略，读指针停在该定界符处
* 获取读长度
  * `streamsize istream::gcount();`
    * 返回最后一次从输入流中读取的字节数
* 写入字符
  * `ostream& ostream::put(char ch);`
    * 一次向输出流写入一个字符，返回流本身
* 刷输出流
  * `ostream& ostream::flush();`
    * 将输出流缓冲区中的数据刷到设备上，返回流本身






