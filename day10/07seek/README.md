# 读写指针随机访问
* 设置读写还真位置
  * `istream& istream::seekg(off_type offset, ios::seekdir origin);`
  * `ostream& ostream::seekp(off_type offset, ios::seekdir origin);`
  * origin表示偏移量offset的起点
    * `ios::beg`：从文件的第一个字节
    * `ios::cur`：从文件的当前位置
    * `ios::end`：从文件最后一个字节的下一个位置
  * offset为负/正表示向文件头/尾的方向偏移
  * 读写指针被移到文件头之前或文件尾之后，则失败

* 获取读/写指针位置
    * `pos_type istream::tellg()`;
    * `pos_type ostream::tellp()`;
    * 返回读/写指针当前位置相对于文件头的字节偏移量
* iostream的子类，如fstream
    * 同时拥有针对读/写指针位置的两套设置/获取函数
    * 理论上应该拥有两个相互肚子里的读/写指针
    * 多数编译器仍然使用一个指针记录文件的当前位置
    * 建议读取时用`seekg/tellg`，写入时用`seekp/tellp`


